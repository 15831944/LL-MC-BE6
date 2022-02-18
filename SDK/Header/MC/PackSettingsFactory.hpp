// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Json.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class PackSettingsFactory {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_PACKSETTINGSFACTORY
public:
    class PackSettingsFactory& operator=(class PackSettingsFactory const&) = delete;
    PackSettingsFactory(class PackSettingsFactory const&) = delete;
    PackSettingsFactory() = delete;
#endif

public:
    MCAPI class PackSettings* getPackSettings(class PackManifest const&);
    MCAPI class PackSettings* loadPackSettings(struct PackIdVersion const&, class Json::Value const&);

protected:

private:

};