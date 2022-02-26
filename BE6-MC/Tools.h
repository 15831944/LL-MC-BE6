#pragma once
#include <LoggerAPI.h>
#include <MC/Level.hpp>
#include <MC/BlockInstance.hpp>
#include <MC/Block.hpp>
#include <MC/BlockSource.hpp>
#include <MC/Actor.hpp>
#include <MC/Player.hpp>
#include <MC/ItemStack.hpp>
#include <LLAPI.h>
string getPlayerDimid(int in);
string getPlayerMode(GameType in);
string UnicodeStrToUtf8(const string& src);
string getPlayerIP(string ip);
void setPlayerMsg(string& _msg, Player* pl);