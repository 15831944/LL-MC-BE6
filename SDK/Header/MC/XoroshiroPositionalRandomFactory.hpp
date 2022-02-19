// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Bedrock.hpp"
#include "Crypto.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class XoroshiroPositionalRandomFactory {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_XOROSHIROPOSITIONALRANDOMFACTORY
public:
    class XoroshiroPositionalRandomFactory& operator=(class XoroshiroPositionalRandomFactory const&) = delete;
    XoroshiroPositionalRandomFactory(class XoroshiroPositionalRandomFactory const&) = delete;
    XoroshiroPositionalRandomFactory() = delete;
#endif

public:
    /*0*/ virtual ~XoroshiroPositionalRandomFactory();
    /*1*/ virtual std::unique_ptr<class IRandom> forBlockPos(class BlockPos const&) const;
    /*2*/ virtual std::unique_ptr<class IRandom> forString(std::string const&) const;
    /*
    inline  ~XoroshiroPositionalRandomFactory(){
         (XoroshiroPositionalRandomFactory::*rv)();
        *((void**)&rv) = dlsym("??1XoroshiroPositionalRandomFactory@@UEAA@XZ");
        return (this->*rv)();
    }
    */
    MCAPI class XoroshiroRandom forStringImpl(std::string const&) const;

protected:

private:
    MCAPI static class Bedrock::Threading::ThreadLocalObject<class Crypto::Hash::md5, class std::allocator<class Crypto::Hash::md5> > mThreadLocalDigest;

};