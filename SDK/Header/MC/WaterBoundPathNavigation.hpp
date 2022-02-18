// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "PathNavigation.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class WaterBoundPathNavigation : public PathNavigation {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_WATERBOUNDPATHNAVIGATION
public:
    class WaterBoundPathNavigation& operator=(class WaterBoundPathNavigation const&) = delete;
    WaterBoundPathNavigation(class WaterBoundPathNavigation const&) = delete;
    WaterBoundPathNavigation() = delete;
#endif

public:
    /*0*/ virtual ~WaterBoundPathNavigation();
    /*1*/ virtual void initializeInternal(class Mob&, struct NavigationDescription*);
    /*2*/ virtual void tick(class NavigationComponent&, class Mob&);
    /*3*/ virtual class Vec3 getTempMobPos(class Mob const&) const;
    /*10*/ virtual bool travel(class NavigationComponent&, class Mob&, float&, float&, float&);
    /*11*/ virtual bool canUpdatePath(class Mob const&) const;
    /*12*/ virtual void updatePath(class NavigationComponent&, class Mob&);

protected:

private:

};