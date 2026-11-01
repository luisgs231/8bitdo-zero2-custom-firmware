/* yc_core.c: guessed: DMA and the core's microcode loader */

#include "zero2.h"

/* 01023398 */
#ifdef NONMATCHING
void dma_copy(undefined4 param_1,undefined4 param_2,undefined4 param_3)
{
  FUN_01023354(6,param_2,param_3,param_1,param_3);
  FUN_01023380(6);
  return;
}
#endif

/* 010233b8 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void core_load_blob(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  ushort uVar1;
  uint uVar2;
  short *psVar3;
  int iVar4;
  undefined4 local_18;
  
  if (*(short *)(param_1 + 2) == 0x55aa) {
    _DAT_000f856c = _DAT_000f856c & 0xffffdfff;
    uVar1 = *(ushort *)(param_1 + 4);
    DAT_000c8024 = 0;
    DAT_000c8022 = 0;
    DAT_000c8023 = 0x80;
    DAT_000f8e0c = 8;
    local_18 = param_4;
    dma_copy(0xc8025,param_1 + 6,(uint)uVar1);
    DAT_000c8023 = 0;
    DAT_000f8e0c = 0;
    for (psVar3 = (short *)(param_1 + 6 + (uint)uVar1); *psVar3 == 0x55aa;
        psVar3 = (short *)((int)(psVar3 + 3) + uVar2)) {
      uVar2 = (uint)(ushort)psVar3[1];
      iVar4 = (ushort)psVar3[2] + 0xc0000;
      if ((iVar4 == 0xc453d) && (uVar2 == 4)) {
        local_18 = CONCAT31(local_18._1_3_,1);
        memcpy((int)&local_18 + 1,(int)psVar3 + 7,3);
        dma_copy(0xc453d,&local_18,4);
      }
      else if ((iVar4 == 0xc4acf) && (uVar2 == 1)) {
        local_18 = 0;
        dma_copy(0xc4acf,&local_18,1);
      }
      else {
        dma_copy(iVar4,psVar3 + 3,uVar2);
      }
    }
  }
  return;
}
#endif
