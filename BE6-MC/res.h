#pragma once
#include <Nlohmann/json.hpp>
#include <LoggerAPI.h>
#include "trie.h"
#include <MQTTClient.h>
extern Trie Wordtrie;
extern MQTTClient Mqtt;
extern Logger logger;
extern nlohmann::json ChatConfig;
extern bool ChatFilter;
extern bool ChatPrefix;
extern string ChatMsg;
extern string LoadMsg;
extern string RootPath;
extern string ChatPath;
extern string WordPath;
extern string ChatFile;
extern string Version;
extern string JoinMsg;
extern bool WorldChat;
namespace BE6 {
	struct playerAddress
	{
		string nation;
		string province;
		string city;
		string district;
		float lat;
		float lng;
		playerAddress(string _nation="", string _province="", string _city="", string _district="", float _lat=0, float _lng=0)
		{
			nation = _nation;
			province = _province;
			city = _city;
			district = _district;
			lat = _lat;
			lng = _lng;
		}
	};
	struct playerInfo
	{
		string plName;
		string xuid;
		playerAddress address;
		playerInfo(string _name="",string _xuid="")
		{
			plName = _name;
			xuid = _xuid;
			address;
		}
	};
}