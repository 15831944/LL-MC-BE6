// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Actor.hpp"
#include "Mob.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class Agent : public Mob {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_AGENT
public:
    class Agent& operator=(class Agent const&) = delete;
    Agent(class Agent const&) = delete;
    Agent() = delete;
#endif

public:
    /*10*/ virtual void initializeComponents(enum Actor::InitializationMethod, class VariantParameterList const&);
    /*14*/ virtual ~Agent();
    /*20*/ virtual bool isRuntimePredictedMovementEnabled() const;
    /*41*/ virtual void __unk_vfn_41();
    /*43*/ virtual void teleportTo(class Vec3 const&, bool, int, int);
    /*48*/ virtual void normalTick();
    /*59*/ virtual bool isInvisible() const;
    /*60*/ virtual bool canShowNameTag() const;
    /*61*/ virtual void __unk_vfn_61();
    /*65*/ virtual std::string getFormattedNameTag() const;
    /*68*/ virtual void __unk_vfn_68();
    /*78*/ virtual float getCameraOffset() const;
    /*82*/ virtual void __unk_vfn_82();
    /*87*/ virtual void __unk_vfn_87();
    /*88*/ virtual void playerTouch(class Player&);
    /*93*/ virtual bool isPickable();
    /*94*/ virtual void __unk_vfn_94();
    /*97*/ virtual void __unk_vfn_97();
    /*100*/ virtual bool isDamageBlocked(class ActorDamageSource const&) const;
    /*104*/ virtual void __unk_vfn_104();
    /*106*/ virtual void __unk_vfn_106();
    /*107*/ virtual void __unk_vfn_107();
    /*108*/ virtual void __unk_vfn_108();
    /*112*/ virtual class Actor* findAttackTarget();
    /*113*/ virtual bool isValidTarget(class Actor*) const;
    /*116*/ virtual void adjustDamageAmount(int&) const;
    /*120*/ virtual void onTame();
    /*121*/ virtual void onFailedTame();
    /*130*/ virtual void vehicleLanded(class Vec3 const&, class Vec3 const&);
    /*140*/ virtual void onBounceStarted(class BlockPos const&, class Block const&);
    /*142*/ virtual void handleEntityEvent(enum ActorEvent, int);
    /*152*/ virtual void awardKillScore(class Actor&, int);
    /*162*/ virtual void setCarriedItem(class ItemStack const&);
    /*172*/ virtual struct ActorUniqueID getSourceUniqueID() const;
    /*179*/ virtual int getPortalWaitTime() const;
    /*181*/ virtual bool canChangeDimensions() const;
    /*182*/ virtual void __unk_vfn_182();
    /*184*/ virtual struct ActorUniqueID getControllingPlayer() const;
    /*193*/ virtual bool canPickupItem(class ItemStack const&) const;
    /*194*/ virtual bool canBePulledIntoVehicle() const;
    /*196*/ virtual void __unk_vfn_196();
    /*199*/ virtual bool canSynchronizeNewEntity() const;
    /*212*/ virtual bool canBeAffected(class MobEffectInstance const&) const;
    /*221*/ virtual void __unk_vfn_221();
    /*222*/ virtual void __unk_vfn_222();
    /*227*/ virtual bool isWorldBuilder() const;
    /*228*/ virtual bool isCreative() const;
    /*229*/ virtual bool isAdventure() const;
    /*233*/ virtual bool canDestroyBlock(class Block const&) const;
    /*234*/ virtual void setAuxValue(int);
    /*240*/ virtual void stopSpinAttack();
    /*242*/ virtual void __unk_vfn_242();
    /*245*/ virtual void __unk_vfn_245();
    /*246*/ virtual void kill();
    /*255*/ virtual void updateEntitySpecificMolangVariables(class RenderParams&);
    /*257*/ virtual void __unk_vfn_257();
    /*258*/ virtual bool _hurt(class ActorDamageSource const&, int, bool, bool);
    /*265*/ virtual void __unk_vfn_265();
    /*274*/ virtual void __unk_vfn_274();
    /*275*/ virtual void knockback(class Actor*, int, float, float, float, float, float);
    /*276*/ virtual void spawnAnim();
    /*287*/ virtual void travel(float, float, float);
    /*290*/ virtual void aiStep();
    /*298*/ virtual int getItemUseDuration() const;
    /*299*/ virtual float getItemUseStartupProgress() const;
    /*300*/ virtual float getItemUseIntervalProgress() const;
    /*303*/ virtual void __unk_vfn_303();
    /*305*/ virtual bool isAlliedTo(class Mob*);
    /*307*/ virtual void __unk_vfn_307();
    /*316*/ virtual void sendArmorDamage(class std::bitset<4> const&);
    /*330*/ virtual bool createAIGoals();
    /*331*/ virtual void onBorn(class Actor&, class Actor&);
    /*336*/ virtual float _getWalkTargetValue(class BlockPos const&);
    /*337*/ virtual bool canExistWhenDisallowMob() const;
    /*338*/ virtual void __unk_vfn_338();
    /*343*/ virtual std::unique_ptr<class BodyControl> initBodyControl();
    /*348*/ virtual void _serverAiMobStep();
    /*354*/ virtual void __unk_vfn_354();
    /*
    inline bool isTargetable() const{
        bool (Agent::*rv)() const;
        *((void**)&rv) = dlsym("?isTargetable@Agent@@UEBA_NXZ");
        return (this->*rv)();
    }
    inline bool getAlwaysShowNameTag() const{
        bool (Agent::*rv)() const;
        *((void**)&rv) = dlsym("?getAlwaysShowNameTag@Agent@@UEBA_NXZ");
        return (this->*rv)();
    }
    inline bool interactPreventDefault(){
        bool (Agent::*rv)();
        *((void**)&rv) = dlsym("?interactPreventDefault@Agent@@UEAA_NXZ");
        return (this->*rv)();
    }
    inline bool breaksFallingBlocks() const{
        bool (Agent::*rv)() const;
        *((void**)&rv) = dlsym("?breaksFallingBlocks@Agent@@UEBA_NXZ");
        return (this->*rv)();
    }
    */
    MCAPI Agent(class ActorDefinitionGroup*, struct ActorDefinitionIdentifier const&, class EntityContext&);
    MCAPI float getMoveSpeedScalar() const;
    MCAPI int getSelectedSlot() const;
    MCAPI bool isValidSlotNum(int);
    MCAPI void setMoveTarget(class Vec3 const&);
    MCAPI void setNameTagFromOwner(class Player const&);
    MCAPI void startCommandMode();
    MCAPI void stopCommandMode();
    MCAPI bool swingAnimationCompleted();
    MCAPI void swingArm();
    MCAPI void tryFireCreateEvent(class Player&);
    MCAPI static class Vec3 roundTeleportPos(class Vec3 const&);
    MCAPI static class Agent* tryGetFromEntity(class EntityContext&, bool);

protected:

private:

};