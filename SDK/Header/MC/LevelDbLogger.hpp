// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class LevelDbLogger {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_LEVELDBLOGGER
public:
    class LevelDbLogger& operator=(class LevelDbLogger const&) = delete;
    LevelDbLogger(class LevelDbLogger const&) = delete;
    LevelDbLogger() = delete;
#endif

public:
    /*0*/ virtual ~LevelDbLogger();
    /*
    inline void Logv(char const* a0, char* a1){
        void (LevelDbLogger::*rv)(char const*, char*);
        *((void**)&rv) = dlsym("?Logv@LevelDbLogger@@EEAAXPEBDPEAD@Z");
        return (this->*rv)(std::forward<char const*>(a0), std::forward<char*>(a1));
    }
    */

protected:

private:

};