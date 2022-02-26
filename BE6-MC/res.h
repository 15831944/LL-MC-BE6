#pragma once
#include <Nlohmann/json.hpp>
#include <LoggerAPI.h>
#include "trie.h"
extern Trie Wordtrie;
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

