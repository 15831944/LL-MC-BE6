#include "pch.h"
#include "res.h"
#include "Event.h"
#include "Config.h"
#include "Mqtt.h"
using namespace std;
void PluginInit()
{
	InitConfig();
	//提示信息
	logger.info(LoadMsg);
	logger.info("[Config][Chat]:成功加载了"+ std::to_string(Wordtrie.loadFromFile(WordPath))+"个屏蔽词！");
	logger.info("[Config][Chat]:{0}为 {1}", "聊天配置版本", ChatConfig["Version"]);
	logger.info("[Config][Chat]:{0}设置为 {1}","聊天过滤",ChatFilter);
	logger.info("[Config][Chat]:{0}设置为 {1}", "聊天前缀", ChatPrefix);
	logger.info("[Config][Chat]:{0}设置为 {1}", "聊天格式", ChatMsg);
	logger.info("[Config][Chat]:{0}设置为 {1}", "进服提醒", JoinMsg);
	LoadEvent();
	Mqtt = MqttInit("BE6CLOUD/MQTT-test");
}
