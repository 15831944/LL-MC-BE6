// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "ScriptApi.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class ScriptSpawnActorComponent {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_SCRIPTSPAWNACTORCOMPONENT
public:
    class ScriptSpawnActorComponent& operator=(class ScriptSpawnActorComponent const&) = delete;
    ScriptSpawnActorComponent(class ScriptSpawnActorComponent const&) = delete;
    ScriptSpawnActorComponent() = delete;
#endif

public:
    /*0*/ virtual ~ScriptSpawnActorComponent();
    /*1*/ virtual void __unk_vfn_1();
    /*2*/ virtual void __unk_vfn_2();
    /*3*/ virtual void __unk_vfn_3();
    /*4*/ virtual bool applyComponentTo(class ScriptApi::ScriptVersionInfo const&, class ScriptEngine&, class ScriptServerContext&, class Actor&, class ScriptApi::ScriptObjectHandle const&) const;
    /*5*/ virtual void __unk_vfn_5();
    /*6*/ virtual void __unk_vfn_6();
    /*7*/ virtual void __unk_vfn_7();
    /*8*/ virtual bool retrieveComponentFrom(class ScriptApi::ScriptVersionInfo const&, class ScriptEngine&, class ScriptServerContext&, class Actor&, class ScriptApi::ScriptObjectHandle&) const;
    /*9*/ virtual void __unk_vfn_9();
    /*10*/ virtual void __unk_vfn_10();
    /*11*/ virtual void __unk_vfn_11();
    /*12*/ virtual bool hasComponent(class ScriptApi::ScriptVersionInfo const&, class ScriptEngine&, class ScriptServerContext&, class Actor&, bool&) const;

protected:

private:
    MCAPI static class HashedString const mHash;

};