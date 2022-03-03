#include "pch.h"
#include "Tools.h"
#include "res.h"
#include <string>
#include <iostream>
#include <locale>
#include <atlstr.h>
#include <EventAPI.h>
#include <MC/Level.hpp>
#include <MC/BlockInstance.hpp>
#include <MC/Block.hpp>
#include <MC/BlockSource.hpp>
#include <MC/Actor.hpp>
#include <MC/Player.hpp>
#include <MC/ItemStack.hpp>
#include <LLAPI.h>
#include <httplib/httplib.h>
#include <regex>
using namespace std;
string getPlayerDimid(int in) {
	string s[4] = {
		"§4未知§r",
		"§2主世界§r",
		"§5下界§r",
		"§9末地§r"
	};
	return s[in + 1];
}
string getPlayerIP(string ip,int mode) {
	string dz;
	float lag=0,lng=0;
	ip=SplitStrWithPattern(ip, ":")[0];
	if (ip == "127.0.0.1" || SplitStrWithPattern(ip,".")[0] == "192") {
		return "本地";
	}
	string CN_Url = R"(/ws/location/v1/ip?output=json&key=KUQBZ-FYDCU-YMVVN-2DDW5-7WDYE-5JBJR&ip=)";
	httplib::Client CN("apis.map.qq.com");
	httplib::Client NCN("ipchaxun.com");
	auto res = CN.Get((CN_Url + ip).c_str());
	if (res) {
		json date = json::parse(res->body);
		if(date.count("status")){
			//lat = to_string(date.at("result").at("location").at("lat"));
			//lng = to_string(date.at("result").at("location").at("lng"));
			string nation = date.at("result").at("ad_info").at("nation");
			string province=date.at("result").at("ad_info").at("province");
			dz = nation + province;
			if (nation != "中国") {
				auto ncn = NCN.Get(("/" + ip + "/").c_str());
				if (ncn) {
					string data = SplitStrWithPattern(ncn->body, "\n")[64];
					ReplaceStr(data, R"(<span class="name">归属地：</span><span class="value">)", "");
					ReplaceStr(data, R"(</span>)", "");
					dz = data;
				}
			}
		}
	}
	switch (mode) {
		case 0:
			return dz;
		case 1:
			return dz+":"+to_string(lag)+ ":" + to_string(lng);
	}
	
}
string getPlayerMode(GameType in) {
	string s[4] = {
		"§2生存§r",
		"§4创造§r",
		"§b冒险§r",
		"§9观察§r"
	};
	return s[in];
}
void setPlayerMsg(string &msg, Player* pl) {
	/*fmt::format(msg, fmt::arg("NAME", pl->getRealName()),
		fmt::arg("PING", to_string(pl->getAvgPing())),
		fmt::arg("LEVEL", to_string(pl->getPlayerLevel())),
		fmt::arg("MODE", getPlayerMode(pl->getPlayerGameType())),
		fmt::arg("DIMID", getPlayerDimid(pl->getDimensionId())),
		fmt::arg("SYSTEM", pl->getDeviceName()),
		fmt::arg("POS_X", to_string(pl->getPos().x)),
		fmt::arg("POS_Y", to_string(pl->getPos().y)),
		fmt::arg("POS_Z", to_string(pl->getPos().z)),
		fmt::arg("PLAYER_IP", getPlayerIP(pl->getIP())),
		fmt::arg("HEALTH", to_string(pl->getHealth())),
		fmt::arg("HEALTH_MAX", to_string(pl->getMaxHealth()))
	);*/
	if (msg.find("{NAME}") != msg.npos)         ReplaceStr(msg, "{NAME}", pl->getRealName());
	if (msg.find("{PING}") != msg.npos)         ReplaceStr(msg, "{PING}", to_string(pl->getAvgPing()));
	if (msg.find("{LEVEL}") != msg.npos)        ReplaceStr(msg, "{LEVEL}", to_string(pl->getPlayerLevel()));
	if (msg.find("{MODE}") != msg.npos)         ReplaceStr(msg, "{MODE}", getPlayerMode(pl->getPlayerGameType()));
	if (msg.find("{DIMID}") != msg.npos)        ReplaceStr(msg, "{DIMID}", getPlayerDimid(pl->getDimensionId()));
	if (msg.find("{SYSTEM}") != msg.npos)       ReplaceStr(msg, "{SYSTEM}", pl->getDeviceName());
	if (msg.find("{POS_X}") != msg.npos)        ReplaceStr(msg, "{POS_X}", to_string(pl->getPos().x));
	if (msg.find("{POS_Y}") != msg.npos)        ReplaceStr(msg, "{POS_Y}", to_string(pl->getPos().y));
	if (msg.find("{POS_Z}") != msg.npos)        ReplaceStr(msg, "{POS_Z}", to_string(pl->getPos().z));
	if (msg.find("{PLAYER_IP}") != msg.npos)    ReplaceStr(msg, "{PLAYER_IP}", getPlayerIP(pl->getIP()));
	if (msg.find("{HEALTH}") != msg.npos)       ReplaceStr(msg, "{HEALTH}", to_string(pl->getHealth()));
	if (msg.find("{HEALTH_MAX}") != msg.npos)   ReplaceStr(msg, "{HEALTH_MAX}", to_string(pl->getMaxHealth()));
}
string UnicodeToUTF8(string str)
{
	int i = 0;
	int j = 0;
	int len = 0;
	CString cstr;
	len = str.length();
	int nValue = 0;
	WCHAR* pWchar;
	wchar_t* szHex;
	char strchar[6] = { '0','x','\0' };

	for (i = 0; i < len; i++)
	{
		if (str[i] == 'u')
		{
			for (j = 2; j < 6; j++)
			{
				i++;
				strchar[j] = str[i];
			}

			USES_CONVERSION;
			szHex = A2W(strchar);

			StrToIntExW(szHex, STIF_SUPPORT_HEX, &nValue);
			pWchar = (WCHAR*)&nValue;

			cstr = cstr + pWchar;
		}
	}
	cstr.ReleaseBuffer(); 
	wstring _str= cstr.GetString();
	cstr.ReleaseBuffer();
	return wstr2str(_str);
}
string UnicodeStrToUtf8(const string& src) {
	regex Unicode("(\\\\u[0123456789abcdef]{4})+");
	smatch Unicodes;
	regex_search(src, Unicodes, Unicode);
	string _src = regex_replace(src, Unicode, UnicodeToUTF8(Unicodes.str(0)));
	return _src;
}