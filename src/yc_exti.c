/* yc_exti.c: ..\Librarier\sdk\yc_exti.c in EXTI_ClearITPendingBit's assert */

#include "zero2.h"

/* 0101b504 */
#ifdef NONMATCHING
void EXTI_ClearITPendingBit(int param_1,uint param_2)
{
  ushort uVar1;
  ushort uVar2;
  
  if (((param_1 != 0) && (param_1 != 1)) && (param_1 != 2)) {
    assert_failed(STR_0101b570,0xe,STR_010279a3);
  }
  if (((param_2 & 0xffff0000) != 0) || (param_2 == 0)) {
    assert_failed(STR_0101b570,0xf,STR_010279a3);
  }
  uVar2 = *(ushort *)(param_1 * 2 + 0xf8736);
  uVar1 = (ushort)param_2;
  if ((uVar2 & param_2) == 0) {
    uVar2 = uVar2 | uVar1;
  }
  else {
    uVar2 = uVar2 & ~uVar1;
  }
  *(ushort *)(param_1 * 2 + 0xf8736) = uVar2;
  *(ushort *)(param_1 * 2 + 0x2005a) = *(ushort *)(param_1 * 2 + 0x2005a) & ~uVar1;
  return;
}
#endif

/* 0101b5a0 */
#ifdef NONMATCHING
void FUN_0101b5a0(void)
{
  set_vis(1,1,0);
  return;
}
#endif

/* 0101b5b0 */
#ifdef NONMATCHING
undefined4 FUN_0101b5b0(undefined4 param_1,undefined4 param_2,undefined4 param_3)
{
  FUN_0101aea4(0x210b0,param_3,param_1,param_2);
  DAT_000201ea = 0;
  return param_2;
}
#endif

/* 0101b5d8 */
#ifdef NONMATCHING
void FUN_0101b5d8(void)
{
  DAT_000201dc = 0x40;
  FUN_0101b5a0(0);
  memcpy(0x20179,&DAT_0102823e,6);
  FUN_0101f7d2();
  FUN_01020350(10);
  FUN_01020344(7);
  FUN_01020350(1);
  FUN_0101c024();
  FUN_01022e8c();
  return;
}
#endif

/* 0101b61c */
#ifdef NONMATCHING
bool FUN_0101b61c(void)
{
  uint uVar1;
  
  uVar1 = FUN_0101fb08();
  return (uVar1 & 0x40000) != 0;
}
#endif

/* 0101b634 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0101b634(void)
{
  if (DAT_00020181 == '\x03') {
    FUN_010240ac(0x218e8,99);
    FUN_01023d5c(0x218e8);
  }
  else {
    _DAT_0002fff0 = 0x55667788;
    restart();
  }
  return;
}
#endif

/* 0101b66c */
#ifdef NONMATCHING
void FUN_0101b66c(void)
{
  FUN_010240c8(0x218e8,0x101b635);
  FUN_010240ac(0x218e8,99);
  FUN_01023d5c(0x218e8);
  return;
}
#endif
