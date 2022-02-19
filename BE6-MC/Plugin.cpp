#include "pch.h"
#include <EventAPI.h>
#include <LoggerAPI.h>
#include <MC/Level.hpp>
#include <MC/BlockInstance.hpp>
#include <MC/Block.hpp>
#include <MC/BlockSource.hpp>
#include <MC/Actor.hpp>
#include <MC/Player.hpp>
#include <MC/ItemStack.hpp>
#include <LLAPI.h>
#include "trie.h"
#include <regex>
Logger logger("BE6-CLOUD");
Trie trie;
void PluginInit()
{
	string LoadMsg = "\n"
		"+-+-+-+-+-+-+-+-+  ++++++++++++++++++++++++++++++++++++\n"
		"|B|E|6|C|L|O|U|D|  |！！！星海湾畔控制系统已加载！！！|\n"
		"+-+-+-+-+-+-+-+-+  ++++++++++++++++++++++++++++++++++++\n";
	string RootPath = "plugins/BE6CLOUD/";
	string ChatPath = RootPath + "Chat/";
	string WordPath = ChatPath + "Word.txt";
	string ChatConfigPath = ChatPath + "config.json";
	logger.info(LoadMsg);
	logger.info("成功加载了"+ std::to_string(trie.loadFromFile(WordPath))+"个屏蔽词！");
	Event::PlayerChatEvent::subscribe_ref([](Event::PlayerChatEvent& ev) {
		std::string str = ev.mMessage;
		std::wstring result = trie.replaceSensitive(SBCConvert::s2ws(str));
		ev.mMessage = SBCConvert::ws2s(result);
      return true;
	});
	Event::PlayerCmdEvent::subscribe_ref([](Event::PlayerCmdEvent& ev) {
		std::string cmd = ev.mCommand;
		std::regex tell("tell .*"),msg("msg .*"), me("me .*"), w("w .*"), say("say .*");
		bool flag= std::regex_match(cmd, tell) || std::regex_match(cmd, say) ||std::regex_match(cmd, msg)||std::regex_match(cmd, me)||std::regex_match(cmd, w);
		if (flag) {
			std::wstring result = trie.replaceSensitive(SBCConvert::s2ws(cmd));
			ev.mCommand = SBCConvert::ws2s(result);
		}
		return true;
	});
}
