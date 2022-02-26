#include "pch.h"
#include "res.h"
Logger logger("BE6-CLOUD");
Trie Wordtrie;
string LoadMsg = "\n"
"+-+-+-+-+-+-+-+-+  ++++++++++++++++++++++++++++++++++++\n"
"|B|E|6|C|L|O|U|D|  |！！！星海湾畔控制系统已加载！！！|\n"
"+-+-+-+-+-+-+-+-+  ++++++++++++++++++++++++++++++++++++\n";
string RootPath = "plugins/BE6CLOUD/";
string ChatPath = RootPath + "Chat/";
string WordPath = ChatPath + "Word.txt";
string ChatFile = "chat.json";
nlohmann::json ChatConfig = {
{ "Version", "1.1.5"},
{ "ChatFilter", true},
{ "ChatPrefix", true},
{ "ChatMsg", "[暴毙数:{SCOREITEM=BE6_die}]§l§r[§1{SYSTEM}§r:§6{PING}ms§r]§r[{MODE}]§r[§5H§r:§5{HEALTH}/{HEALTH_MAX}§r]§r[§2L§r:§2{LEVEL}§r]§3{NAME} §r>> {MSG}"},
{ "JoinMsg", "§l§b欢迎来自地区:§e({PLAYER_IP})§9[{SYSTEM}]§b的玩家:§a{NAME}§b加入服务器"}
};
bool ChatFilter;
bool ChatPrefix;
string ChatMsg;
string JoinMsg;
string Version="1.1.5";