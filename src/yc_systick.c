/* yc_systick.c: ..\Librarier\sdk\yc_systick.c in SysTick_Config's assert */

#include "zero2.h"

/* 01020b14 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SysTick_Config(uint param_1)
{
  if (0xffffff < param_1) {
    assert_failed(STR_01020b58,0x42,STR_010278ec);
  }
  _DAT_e000e014 = param_1 - 1;
  _DAT_e000e018 = 0;
  _DAT_0002003c = 0;
  _DAT_e000e010 = _DAT_e000e010 & 0xfffffffe | 7;
  return;
}
#endif

/* 01020b8c */
void FUN_01020b8c(void)
{
  return;
}

/* 01020b8e */
void FUN_01020b8e(void)
{
  return;
}

/* 01020b90 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 now(void)
{
  return _DAT_0002003c;
}
#endif

/* 01020b9c */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool elapsed(int param_1,uint param_2)
{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  iVar1 = now();
  iVar1 = iVar1 - param_1;
  if (iVar1 < 0) {
    iVar1 = iVar1 + 0x7fffffff;
  }
  uVar2 = FUN_01018240(192000000,(_DAT_000f8560 & 0xf) + 2);
  uVar2 = FUN_01018240(uVar2,1000);
  uVar3 = FUN_01018214(iVar1 * _DAT_e000e014,uVar2);
  return param_2 <= uVar3;
}
#endif

/* 01020bf8 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01020bf8(void)
{
  _DAT_e000e014 = 0;
  _DAT_e000e018 = 0;
  _DAT_0002003c = 0;
  _DAT_e000e010 = 0;
  return;
}
#endif

/* 01020c1c */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01020c1c(void)
{
  FUN_0101fa44();
  FUN_01018544();
  FUN_010241dc();
  FUN_0101b750();
  DAT_000201e9 = FUN_0101c414();
  GPIO_SetBits(2,4);
  _DAT_00020150 = 0;
  FUN_01022314();
  led_set(7,4);
  return;
}
#endif
