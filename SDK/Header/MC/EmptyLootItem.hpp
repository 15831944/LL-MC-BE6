// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class EmptyLootItem {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_EMPTYLOOTITEM
public:
    class EmptyLootItem& operator=(class EmptyLootItem const&) = delete;
    EmptyLootItem(class EmptyLootItem const&) = delete;
    EmptyLootItem() = delete;
#endif

public:
    /*0*/ virtual void __unk_vfn_0();
    /*1*/ virtual ~EmptyLootItem();
    /*
    inline bool _createItem(std::vector<class ItemStack>& a0, class Random& a1, class LootTableContext& a2){
        bool (EmptyLootItem::*rv)(std::vector<class ItemStack>&, class Random&, class LootTableContext&);
        *((void**)&rv) = dlsym("?_createItem@EmptyLootItem@@MEAA_NAEAV?$vector@VItemStack@@V?$allocator@VItemStack@@@std@@@std@@AEAVRandom@@AEAVLootTableContext@@@Z");
        return (this->*rv)(std::forward<std::vector<class ItemStack>&>(a0), std::forward<class Random&>(a1), std::forward<class LootTableContext&>(a2));
    }
    */

protected:

private:

};