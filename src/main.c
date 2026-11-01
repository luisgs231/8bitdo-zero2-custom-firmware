/* main.c: main */

#include "zero2.h"

/* 01024f48 */
#ifdef NONMATCHING
void main(void)
{
  int iVar1;
  undefined4 extraout_r2;
  undefined4 extraout_r3;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined *puVar5;
  undefined4 uVar6;
  undefined *puVar7;
  
  puVar7 = &DAT_00001022;
  uVar6 = 0x33000000;
  puVar5 = &DAT_0000e417;
  uVar4 = 0xd8000000;
  uVar2 = 0;
  uVar3 = 0;
  iVar1 = FUN_0101c424();
  if (iVar1 == 0x20210624) {
    DAT_00020039 = 1;
  }
  SYSCTRL_HCLKConfig(6);
  SYSCTRL_AHBPeriphClockCmd
            (&DAT_00004248,0,extraout_r2,extraout_r3,uVar2,uVar3,uVar4,puVar5,uVar6,puVar7);
  FUN_0101b4c0();
  FUN_010250a8(0x20000);
  FUN_01020edc();
  FUN_01022b18();
  do {
    loop_once();
  } while( true );
}
#endif

/* 01024fbc */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_01024fbc(void)
{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  uVar1 = _DAT_000f8560 & 0xf;
  if ((_DAT_000f881c & 0x80) != 0) {
    uVar2 = 0x80;
  }
  uVar2 = uVar2 | uVar1;
  thunk_FUN_00004404(0x1025111,0x1025151);
  if (uVar1 == 0) {
    uVar1 = 2;
  }
  FUN_01025110(0,uVar1);
  return uVar2;
}
#endif

/* 01025000 */
#ifdef NONMATCHING
void thunk_FUN_00004404(void)
{
  FUN_00004404();
  return;
}
#endif

/* 01025008 */
#ifdef NONMATCHING
void FUN_01025008(void)
{
  int iVar1;
  
  for (iVar1 = 0; iVar1 < 5; iVar1 = iVar1 + 1) {
  }
  return;
}
#endif
