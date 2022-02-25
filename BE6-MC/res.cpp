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
{ "ChatFilter", true},
{ "ChatMsg", "§l§r[§1{SYSTEM}§r:§6{PING}ms§r]§r[{MODE}]§r[§5H§r:§5{HEALTH}§r]§r[§2L§r:§2{LEVEL}§r]§3{NAME} §r>> {MSG}"},
{ "ChatPrefix", true}
};
bool ChatFilter;
bool ChatPrefix;
string ChatMsg;