#include "pch.h"
#include "Event.h"
#include "Tools.h"
#include "Config.h"
#include <EventAPI.h>
#include <MC/Level.hpp>
#include <MC/BlockInstance.hpp>
#include <MC/Block.hpp>
#include <MC/BlockSource.hpp>
#include <MC/Actor.hpp>
#include <MC/Player.hpp>
#include <MC/ItemStack.hpp>
#include <LLAPI.h>
#include <regex>
using namespace std;

void LoadEvent() {
	Event::PlayerChatEvent::subscribe_ref([](Event::PlayerChatEvent& ev) {
		string msg = ev.mMessage;
		auto pl = ev.mPlayer;
		if (ChatFilter) {
			std::wstring result = Wordtrie.replaceSensitive(SBCConvert::s2ws(msg));
			ev.mMessage = SBCConvert::ws2s(result);
		}
		if (ChatPrefix) {
			string _msg = ChatMsg;
			vector<string> scores;
			regex SCORE("\\{SCOREITEM=([^}]*)\\}");
			sregex_iterator pos(_msg.cbegin(), _msg.cend(), SCORE);
			sregex_iterator end;
			for (; pos != end; pos++) {
				scores.push_back(pos->str(1));
			}
			for (vector<string>::iterator itr = scores.begin(); itr != scores.end(); ++itr) {
				ReplaceStr(_msg, "{SCOREITEM=" + *itr + "}", std::to_string(pl->getScore(*itr)));
			}
			ReplaceStr(_msg, "{NAME}", pl->getRealName());
			ReplaceStr(_msg, "{PING}", to_string(pl->getAvgPing()));
			ReplaceStr(_msg, "{LEVEL}", to_string(pl->getPlayerLevel()));
			ReplaceStr(_msg, "{MODE}", getPlayerMode(pl->getPlayerGameType()));
			ReplaceStr(_msg, "{DIMID}", getPlayerDimid(pl->getDimensionId()));
			ReplaceStr(_msg, "{SYSTEM}", pl->getDeviceName());
			ReplaceStr(_msg, "{POS_X}", to_string(pl->getPos().x));
			ReplaceStr(_msg, "{POS_Y}", to_string(pl->getPos().y));
			ReplaceStr(_msg, "{POS_Z}", to_string(pl->getPos().z));
			ReplaceStr(_msg, "{PLAYER}", pl->getIP());
			ReplaceStr(_msg, "{HEALTH}", to_string(pl->getHealth()));
			ReplaceStr(_msg, "{HEALTH_MAX}", to_string(pl->getMaxHealth()));
			ReplaceStr(_msg, "{MSG}", ev.mMessage);
			Level::broadcastText(_msg, TextType::RAW);
			return false;
		}
		return true;
		});
	Event::PlayerCmdEvent::subscribe_ref([](Event::PlayerCmdEvent& ev) {
		std::string cmd = ev.mCommand;
		std::regex tell("tell .*"), msg("msg .*"), me("me .*"), w("w .*"), say("say .*"), tellraw("tellraw .*");
		bool flag = std::regex_match(cmd, tell) || std::regex_match(cmd, tellraw) || std::regex_match(cmd, say) || std::regex_match(cmd, msg) || std::regex_match(cmd, me) || std::regex_match(cmd, w);
		if (flag) {
			std::wstring result = Wordtrie.replaceSensitive(SBCConvert::s2ws(cmd));
			ev.mCommand = SBCConvert::ws2s(result);
		}
		return true;
		});
	Event::ConsoleCmdEvent::subscribe_ref([](Event::ConsoleCmdEvent& ev) {
		std::string cmd = ev.mCommand;
		std::regex tell("tell .*"), msg("msg .*"), tellraw("tellraw .*"), w("w .*"), say("say .*");
		bool flag = std::regex_match(cmd, tell) || std::regex_match(cmd, say) || std::regex_match(cmd, msg) || std::regex_match(cmd, tellraw) || std::regex_match(cmd, w);
		if (flag) {
			std::wstring result = Wordtrie.replaceSensitive(SBCConvert::s2ws(UnicodeStrToUtf8(cmd)));
			ev.mCommand = SBCConvert::ws2s(result);
		}
		return true;
	});
	logger.info("[Event] 监听已注册{}个！！！",3);
}