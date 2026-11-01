/* power.c: guessed: power off */

#include "zero2.h"

/* 01020c60 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void power_off(void)
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  if (DAT_00020168 == '\0') {
    DAT_00020168 = '\x01';
    FUN_01022e8c();
    FUN_01020350(10);
    FUN_01020340(6);
    FUN_0101fc30(0xa5,DAT_000201b4);
    FUN_01024d78();
    FUN_01024194();
    thunk_FUN_0101b23c(0x10000);
    if (DAT_000201b8 == '\0') {
      GPIO_ResetBits(2,4);
      FUN_0101a9e0(0x100000);
      FUN_0101b242(100);
      uVar3 = 0;
      do {
        uVar1 = _DAT_00020008;
        if (uVar3 + 2000 <= _DAT_00020008) {
          FUN_0101a468(0);
          uVar3 = uVar1;
        }
        uVar1 = FUN_0101fb08();
        if ((uVar1 & 0x20000) != 0) {
          restart();
        }
        iVar2 = FUN_0101f0bc();
        if (iVar2 == 0) {
          GPIO_ResetBits(2,4);
        }
        else if (DAT_000206b2 == '\0') {
          led_set(7,1);
        }
        else {
          led_set(7,0);
        }
        rom_delay_a(100);
      } while( true );
    }
  }
  return;
}
#endif
