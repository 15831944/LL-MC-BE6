// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class TransactionalWorldBlockTarget {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_TRANSACTIONALWORLDBLOCKTARGET
public:
    class TransactionalWorldBlockTarget& operator=(class TransactionalWorldBlockTarget const&) = delete;
    TransactionalWorldBlockTarget(class TransactionalWorldBlockTarget const&) = delete;
    TransactionalWorldBlockTarget() = delete;
#endif

public:
    /*0*/ virtual ~TransactionalWorldBlockTarget();
    /*1*/ virtual void __unk_vfn_1();
    /*2*/ virtual void __unk_vfn_2();
    /*3*/ virtual class Block const& getBlock(class BlockPos const&) const;
    /*4*/ virtual void __unk_vfn_4();
    /*5*/ virtual void __unk_vfn_5();
    /*6*/ virtual void __unk_vfn_6();
    /*7*/ virtual bool setBlock(class BlockPos const&, class Block const&, int);
    /*8*/ virtual void __unk_vfn_8();
    /*9*/ virtual bool apply() const;
    /*10*/ virtual bool placeStructure(class BlockPos const&, class StructureTemplate&, class StructureSettings&);
    /*11*/ virtual bool mayPlace(class BlockPos const&, class Block const&) const;
    /*12*/ virtual bool canSurvive(class BlockPos const&, class Block const&) const;
    /*13*/ virtual short getMaxHeight() const;
    /*14*/ virtual void __unk_vfn_14();
    /*15*/ virtual void __unk_vfn_15();
    /*16*/ virtual short getHeightmap(int, int);
    /*17*/ virtual bool isLegacyLevel();
    /*18*/ virtual void __unk_vfn_18();
    /*19*/ virtual void __unk_vfn_19();
    /*20*/ virtual short getLocalWaterLevel(class BlockPos const&) const;
    /*21*/ virtual class LevelData const& getLevelData() const;
    /*
    inline bool shimPlaceForOldFeatures(class Feature const& a0, class BlockPos const& a1, class Random& a2) const{
        bool (TransactionalWorldBlockTarget::*rv)(class Feature const&, class BlockPos const&, class Random&) const;
        *((void**)&rv) = dlsym("?shimPlaceForOldFeatures@TransactionalWorldBlockTarget@@UEBA_NAEBVFeature@@AEBVBlockPos@@AEAVRandom@@@Z");
        return (this->*rv)(std::forward<class Feature const&>(a0), std::forward<class BlockPos const&>(a1), std::forward<class Random&>(a2));
    }
    inline void disableBlockSimple(){
        void (TransactionalWorldBlockTarget::*rv)();
        *((void**)&rv) = dlsym("?disableBlockSimple@TransactionalWorldBlockTarget@@UEAAXXZ");
        return (this->*rv)();
    }
    inline  ~TransactionalWorldBlockTarget(){
         (TransactionalWorldBlockTarget::*rv)();
        *((void**)&rv) = dlsym("??1TransactionalWorldBlockTarget@@UEAA@XZ");
        return (this->*rv)();
    }
    inline class Block const& getExtraBlock(class BlockPos const& a0) const{
        class Block const& (TransactionalWorldBlockTarget::*rv)(class BlockPos const&) const;
        *((void**)&rv) = dlsym("?getExtraBlock@TransactionalWorldBlockTarget@@UEBAAEBVBlock@@AEBVBlockPos@@@Z");
        return (this->*rv)(std::forward<class BlockPos const&>(a0));
    }
    inline class Biome const* getBiome(class BlockPos const& a0) const{
        class Biome const* (TransactionalWorldBlockTarget::*rv)(class BlockPos const&) const;
        *((void**)&rv) = dlsym("?getBiome@TransactionalWorldBlockTarget@@UEBAPEBVBiome@@AEBVBlockPos@@@Z");
        return (this->*rv)(std::forward<class BlockPos const&>(a0));
    }
    inline class Block const& getBlockNoBoundsCheck(class BlockPos const& a0) const{
        class Block const& (TransactionalWorldBlockTarget::*rv)(class BlockPos const&) const;
        *((void**)&rv) = dlsym("?getBlockNoBoundsCheck@TransactionalWorldBlockTarget@@UEBAAEBVBlock@@AEBVBlockPos@@@Z");
        return (this->*rv)(std::forward<class BlockPos const&>(a0));
    }
    inline struct WorldGenContext const& getContext(){
        struct WorldGenContext const& (TransactionalWorldBlockTarget::*rv)();
        *((void**)&rv) = dlsym("?getContext@TransactionalWorldBlockTarget@@UEAAAEBUWorldGenContext@@XZ");
        return (this->*rv)();
    }
    inline short getMinHeight() const{
        short (TransactionalWorldBlockTarget::*rv)() const;
        *((void**)&rv) = dlsym("?getMinHeight@TransactionalWorldBlockTarget@@UEBAFXZ");
        return (this->*rv)();
    }
    inline bool hasBiomeTag(unsigned __int64 a0, class BlockPos const& a1) const{
        bool (TransactionalWorldBlockTarget::*rv)(unsigned __int64, class BlockPos const&) const;
        *((void**)&rv) = dlsym("?hasBiomeTag@TransactionalWorldBlockTarget@@UEBA_N_KAEBVBlockPos@@@Z");
        return (this->*rv)(std::forward<unsigned __int64>(a0), std::forward<class BlockPos const&>(a1));
    }
    inline bool isInBounds(class Pos const& a0) const{
        bool (TransactionalWorldBlockTarget::*rv)(class Pos const&) const;
        *((void**)&rv) = dlsym("?isInBounds@TransactionalWorldBlockTarget@@UEBA_NAEBVPos@@@Z");
        return (this->*rv)(std::forward<class Pos const&>(a0));
    }
    inline bool setBlockSimple(class BlockPos const& a0, class Block const& a1){
        bool (TransactionalWorldBlockTarget::*rv)(class BlockPos const&, class Block const&);
        *((void**)&rv) = dlsym("?setBlockSimple@TransactionalWorldBlockTarget@@UEAA_NAEBVBlockPos@@AEBVBlock@@@Z");
        return (this->*rv)(std::forward<class BlockPos const&>(a0), std::forward<class Block const&>(a1));
    }
    */
    MCAPI TransactionalWorldBlockTarget(class IBlockWorldGenAPI&);

protected:

private:

};