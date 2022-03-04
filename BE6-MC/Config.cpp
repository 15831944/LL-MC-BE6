#include "pch.h"
#include "Config.h"
#include "res.h"
using namespace std;
using nlohmann::json;
void WriteConfig(string ConfigPath, string ConfigFile, json& Config) {
	CreateDirs(ConfigPath);
	ofstream of(ConfigPath + ConfigFile);
	if (of) {
		of << setw(4) << Config << std::endl;
		logger.info("[Config] 创建{0}配置文件成功！！！", ConfigPath + ConfigFile);
		of.close();
	}
	else {
		logger.error("[Config] 创建{0}配置文件失败！！！", ConfigPath + ConfigFile);
	}
}
void LoadConfig(string ConfigPath, string ConfigFile, json& Config) {
	ifstream _ConfigFile;
	json _Config;
	logger.info("加载{0}中...", ConfigPath + ConfigFile);
	_ConfigFile.open(ConfigPath + ConfigFile, std::ios::in);
	if (!_ConfigFile) {
		WriteConfig(ConfigPath, ConfigFile,Config);
	}
	else {
		_ConfigFile >> _Config;
		if (_Config["Version"] == Version)
		{
			Config = _Config;
			logger.info("[Config] 加载{0}配置文件成功！！！", ConfigPath + ConfigFile);
			_ConfigFile.close();
		}
		else {
			logger.info("[Config] 配置文件更新中！！！");
			getConfig(_Config);
			setConfig(Config);
			WriteConfig(ConfigPath, ConfigFile, Config);
		}
	}
}
void getConfig(json& Config) {
	Config.count("ChatFilter") ? ChatFilter = Config.at("ChatFilter") : ChatFilter = ChatConfig.at("ChatFilter");
	Config.count("ChatPrefix") ? ChatPrefix = Config.at("ChatPrefix") : ChatPrefix = ChatConfig.at("ChatPrefix");
	Config.count("WorldChat") ? WorldChat = Config.at("WorldChat") : WorldChat = ChatConfig.at("WorldChat");
	Config.count("ChatMsg") ? ChatMsg = Config.at("ChatMsg") : ChatMsg = ChatConfig.at("ChatMsg");
	Config.count("JoinMsg") ? JoinMsg = Config.at("JoinMsg") : JoinMsg = ChatConfig.at("JoinMsg");
}
void setConfig(json& Config) {
	Config["ChatFilter"] = ChatFilter;
	Config["ChatPrefix"] = ChatPrefix;
	Config["WorldChat"]  = WorldChat;
	Config["ChatMsg"]    = ChatMsg ;
	Config["JoinMsg"]    = JoinMsg;
}
bool InitConfig() {
	LoadConfig(ChatPath, ChatFile, ChatConfig);
	getConfig(ChatConfig);
	return true;
}