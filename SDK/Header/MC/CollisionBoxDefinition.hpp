// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "JsonUtil.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

struct CollisionBoxDefinition {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_COLLISIONBOXDEFINITION
public:
    struct CollisionBoxDefinition& operator=(struct CollisionBoxDefinition const&) = delete;
    CollisionBoxDefinition(struct CollisionBoxDefinition const&) = delete;
    CollisionBoxDefinition() = delete;
#endif

public:
    MCAPI void setHeight(float const&);
    MCAPI void setWidth(float const&);

protected:

private:

};