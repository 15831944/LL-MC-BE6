// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "ContainerValidationBase.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class FurnaceResultContainerValidation : public ContainerValidationBase {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_FURNACERESULTCONTAINERVALIDATION
public:
    class FurnaceResultContainerValidation& operator=(class FurnaceResultContainerValidation const&) = delete;
    FurnaceResultContainerValidation(class FurnaceResultContainerValidation const&) = delete;
    FurnaceResultContainerValidation() = delete;
#endif

public:
    /*0*/ virtual ~FurnaceResultContainerValidation();
    /*2*/ virtual void __unk_vfn_2();
    /*4*/ virtual void __unk_vfn_4();
    /*5*/ virtual void __unk_vfn_5();
    /*8*/ virtual int getContainerOffset(class ContainerScreenContext const&) const;

protected:

private:

};