// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "AttributeScriptActorComponent.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class ScriptLavaMovementComponent : public AttributeScriptActorComponent {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_SCRIPTLAVAMOVEMENTCOMPONENT
public:
    class ScriptLavaMovementComponent& operator=(class ScriptLavaMovementComponent const&) = delete;
    ScriptLavaMovementComponent(class ScriptLavaMovementComponent const&) = delete;
    ScriptLavaMovementComponent() = delete;
#endif

public:
    /*0*/ virtual ~ScriptLavaMovementComponent();
    /*
    inline  ~ScriptLavaMovementComponent(){
         (ScriptLavaMovementComponent::*rv)();
        *((void**)&rv) = dlsym("??1ScriptLavaMovementComponent@@UEAA@XZ");
        return (this->*rv)();
    }
    */
    MCAPI static class Scripting::ClassBindingBuilder<class ScriptLavaMovementComponent> bind(struct Scripting::Version);

protected:

private:

};