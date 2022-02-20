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
using nlohmann::json;
Logger logger("BE6-CLOUD");
Trie trie;
json ChatConfig{
	{ "ChatFilter", true},
	{ "ChatMsg", "§l§r[§1{SYSTEM}§r:§6{PING}ms§r]§r[{MODE}]§r[§5H§r:§5{HEALTH}§r]§r[§2L§r:§2{LEVEL}§r]§3{NAME} §r>> {MSG}"},
	{ "ChatPrefix", true}
};
bool ChatFilter;
bool ChatPrefix;
string ChatMsg;
string LoadMsg = "\n"
"+-+-+-+-+-+-+-+-+  ++++++++++++++++++++++++++++++++++++\n"
"|B|E|6|C|L|O|U|D|  |！！！星海湾畔控制系统已加载！！！|\n"
"+-+-+-+-+-+-+-+-+  ++++++++++++++++++++++++++++++++++++\n";
string RootPath = "plugins/BE6CLOUD/";
string ChatPath = RootPath + "Chat/";
string WordPath = ChatPath + "Word.txt";
string ChatFile = "chat.json";
void loadConfig(string ConfigPath,string ConfigFile,json &Config) {
    std::ifstream _ConfigFile;
	json _Config;
	logger.info("加载{0}中...", ConfigPath + ConfigFile);
    _ConfigFile.open(ConfigPath+ConfigFile, std::ios::in);
    if (!_ConfigFile) {
		CreateDirs(ConfigPath);
		std::ofstream of(ConfigPath + ConfigFile);
		if (of) { 
			of << std::setw(4) << Config << std::endl;
			logger.info("创建{0}配置文件成功！！！", ConfigPath + ConfigFile);
			of.close();
		}
		else {
			logger.error("创建{0}配置文件失败！！！", ConfigPath + ConfigFile);
		}
	}
	else {
		_ConfigFile >> _Config;
		Config = _Config;
		logger.info("加载{0}配置文件成功！！！", ConfigPath + ConfigFile);
		_ConfigFile.close();
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
void loadEvent() {
	Event::PlayerChatEvent::subscribe_ref([](Event::PlayerChatEvent& ev) {
		std::string msg = ev.mMessage;
		auto pl = ev.mPlayer;
		if (ChatFilter)
		{
			std::wstring result = trie.replaceSensitive(SBCConvert::s2ws(msg));
			ev.mMessage = SBCConvert::ws2s(result);
		}
		if (ChatPrefix) {
			string _msg = ChatMsg;
			ReplaceStr(_msg, "{NAME}", pl->getRealName());
			ReplaceStr(_msg, "{PING}", std::to_string(pl->getAvgPing()));
			ReplaceStr(_msg, "{LEVEL}", std::to_string(pl->getPlayerLevel()));
			ReplaceStr(_msg, "{MODE}", getPlayerMode(pl->getPlayerGameType()));
			ReplaceStr(_msg, "{SYSTEM}", pl->getDeviceName());
			ReplaceStr(_msg, "{HEALTH}", std::to_string(pl->getHealth()) + "/" + std::to_string(pl->getMaxHealth()));
			ReplaceStr(_msg, "{MSG}", ev.mMessage);
			Level::broadcastText(_msg, TextType::RAW);
			return false;
		}
		return true;
		});
	Event::PlayerCmdEvent::subscribe_ref([](Event::PlayerCmdEvent& ev) {
		std::string cmd = ev.mCommand;
		std::regex tell("tell .*"), msg("msg .*"), me("me .*"), w("w .*"), say("say .*");
		bool flag = std::regex_match(cmd, tell) || std::regex_match(cmd, say) || std::regex_match(cmd, msg) || std::regex_match(cmd, me) || std::regex_match(cmd, w);
		if (flag) {
			std::wstring result = trie.replaceSensitive(SBCConvert::s2ws(cmd));
			ev.mCommand = SBCConvert::ws2s(result);
		}
		return true;
		});
	logger.info("[Event] 事件监听已注册");
}
void PluginInit()
{
	loadConfig(ChatPath, ChatFile, ChatConfig);
	ChatFilter = ChatConfig["ChatFilter"];
	ChatPrefix = ChatConfig["ChatPrefix"];
	ChatMsg = ChatConfig["ChatMsg"];
	//提示信息
	logger.info(LoadMsg);
	logger.info("[Config][Chat]:成功加载了"+ std::to_string(trie.loadFromFile(WordPath))+"个屏蔽词！");
	logger.info("[Config][Chat]:{0}设置为{1}","聊天过滤",ChatFilter);
	logger.info("[Config][Chat]:{0}设置为{1}", "聊天前缀", ChatPrefix);
	loadEvent();
}
