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
			WriteConfig(ConfigPath, ConfigFile, Config);
		}
	}
}
bool InitConfig() {
	LoadConfig(ChatPath, ChatFile, ChatConfig);
	ChatFilter = ChatConfig["ChatFilter"];
	ChatPrefix = ChatConfig["ChatPrefix"];
	ChatMsg = ChatConfig["ChatMsg"];
	JoinMsg = ChatConfig["JoinMsg"];
	return true;
}