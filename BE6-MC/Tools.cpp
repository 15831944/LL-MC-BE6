#include "pch.h"
#include "Tools.h"
#include "res.h"
#include <string>
#include <iostream>
#include <locale>
#include <atlstr.h>
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
string getPlayerMode(GameType in) {
	string s[4] = {
		"§2生存§r",
		"§4创造§r",
		"§b冒险§r",
		"§9观察§r"
	};
	return s[in];
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