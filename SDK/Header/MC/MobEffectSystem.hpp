// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class MobEffectSystem {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_MOBEFFECTSYSTEM
public:
    class MobEffectSystem& operator=(class MobEffectSystem const&) = delete;
    MobEffectSystem(class MobEffectSystem const&) = delete;
    MobEffectSystem() = delete;
#endif

public:
    /*0*/ virtual ~MobEffectSystem();
    /*1*/ virtual void __unk_vfn_1();
    /*2*/ virtual void tick(class EntityRegistry&);

protected:

private:
    MCAPI void _tickComponent(class ViewedEntityContextT<class EntityContext, class FlagComponent<struct ActorTickedFlag>, class FlagComponent<struct ActorFlag>, class MobEffectComponent>&);

};