/* timer.c: guessed: software timers */

#include "zero2.h"

/* 010238f0 */
#ifdef NONMATCHING
int FUN_010238f0(int param_1,int param_2,undefined4 param_3,code *param_4)
{
  int iVar1;
  
  iVar1 = 0;
  if (param_2 << 0x12 < 0) {
    while (param_1 = param_1 + -1, -1 < param_1) {
      (*param_4)(0x20,param_3);
      iVar1 = iVar1 + 1;
    }
  }
  return iVar1;
}
#endif

/* 01023910 */
#ifdef NONMATCHING
int FUN_01023910(int param_1,int param_2,undefined4 param_3,code *param_4)
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = 0;
  if (param_2 << 0xf < 0) {
    uVar2 = 0x30;
  }
  else {
    uVar2 = 0x20;
  }
  if (-1 < param_2 << 0x12) {
    while (param_1 = param_1 + -1, -1 < param_1) {
      (*param_4)(uVar2,param_3);
      iVar1 = iVar1 + 1;
    }
  }
  return iVar1;
}
#endif

/* 0102393c */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_0102393c(undefined4 param_1,uint param_2,undefined4 param_3)
{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 local_20;
  
  uVar3 = 1;
  iVar1 = 5;
  uVar2 = (_DAT_000f881c & 0xffffff) >> 0x10;
  local_20 = CONCAT13((char)param_1,
                      CONCAT12((char)((uint)param_1 >> 8),
                               CONCAT11((char)((uint)param_1 >> 0x10),
                                        (char)((_DAT_000f881c & 0xffffff) >> 0x10))));
  if ((uVar2 != 0xbb) && ((uVar2 < 0xbc || ((uVar2 != 0xe7 && (uVar2 != 0xeb)))))) {
    iVar1 = 4;
  }
  _DAT_000f8800 = &local_20;
  _DAT_000f8804 = param_3;
  _DAT_000f8808 = iVar1 << 0x10 | param_2;
  DAT_000f880c = 0;
  DAT_000f880f = 0x80;
  iVar1 = 0;
  do {
    if ((_DAT_000f8810 & 1) != 0) goto LAB_010239ba;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x10001);
  uVar3 = 0;
LAB_010239ba:
  return CONCAT44(local_20,uVar3);
}
#endif

/* 010239cc */
#ifdef NONMATCHING
undefined4 FUN_010239cc(int param_1,uint param_2,int param_3)
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined1 auStack_124 [4];
  undefined1 local_120 [256];
  int local_20;
  uint uStack_1c;
  int local_18;
  
  local_20 = param_1;
  uStack_1c = param_2;
  local_18 = param_3;
  memzero(auStack_124,0x104);
  uVar1 = param_2 + 0xff;
  uVar5 = 0;
  while( true ) {
    if (uVar1 >> 8 <= uVar5) {
      return 1;
    }
    uVar4 = 0x100;
    if (param_2 < 0x101) {
      uVar4 = param_2;
    }
    FUN_000047e4(auStack_124,2,uVar5 * 0x100 + local_20);
    for (uVar2 = 0; uVar2 < uVar4; uVar2 = uVar2 + 1) {
      local_120[uVar2] = *(undefined1 *)(local_18 + uVar5 * 0x100 + uVar2);
    }
    iVar3 = FUN_000047d0();
    if (iVar3 == 0) {
      return 0;
    }
    iVar3 = FUN_0000468c(auStack_124,uVar4 + 4);
    if (iVar3 == 0) {
      return 0;
    }
    iVar3 = FUN_00004740();
    if (iVar3 == 0) break;
    param_2 = param_2 - uVar4;
    uVar5 = uVar5 + 1;
  }
  return 0;
}
#endif

/* 01023a50 */
#ifdef NONMATCHING
void FUN_01023a50(undefined1 param_1,undefined4 *param_2)
{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)*param_2;
  *param_2 = puVar1 + 1;
  *puVar1 = param_1;
  return;
}
#endif

/* 01023a5c */
#ifdef NONMATCHING
void FUN_01023a5c(void)
{
  if (DAT_00021ed0 != '\0') {
    FUN_01024090(0x21ebc);
  }
  FUN_010240c8(0x21ebc,0x1023a91);
  FUN_010240ac(0x21ebc,&DAT_0000176f);
  FUN_01023d5c(0x21ebc);
  return;
}
#endif

/* 01023a90 */
#ifdef NONMATCHING
void FUN_01023a90(void)
{
  int iVar1;
  
  if (((DAT_00020682 == '\x02') && (DAT_00020181 != '\x03')) && (iVar1 = usb_charging(), iVar1 == 0)
     ) {
    restart();
  }
  FUN_010240ac(0x21ebc,&DAT_0000176f);
  FUN_01023d5c(0x21ebc);
  return;
}
#endif

/* 01023ad0 */
#ifdef NONMATCHING
void timer_remove(void)
{
  if (DAT_00021ed0 != '\0') {
    FUN_01024090(0x21ebc);
  }
  return;
}
#endif

/* 01023ae8 */
void FUN_01023ae8(void)
{
  return;
}

/* 01023aea */
#ifdef NONMATCHING
void FUN_01023aea(undefined1 *param_1,undefined1 *param_2)
{
  *param_1 = param_2[5];
  param_1[1] = param_2[4];
  param_1[2] = param_2[3];
  param_1[3] = param_2[2];
  param_1[4] = param_2[1];
  param_1[5] = *param_2;
  return;
}
#endif

/* 01023b04 */
undefined4 FUN_01023b04(void)
{
  return 0;
}

/* 01023b08 */
#ifdef NONMATCHING
void FUN_01023b08(int *param_1,int *param_2)
{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  while( true ) {
    if (piVar1 == (int *)0x0) {
      *param_2 = *param_1;
      *param_1 = (int)param_2;
      return;
    }
    if (piVar1 == param_2) break;
    piVar1 = (int *)*piVar1;
  }
  return;
}
#endif

/* 01023b22 */
#ifdef NONMATCHING
undefined4 FUN_01023b22(int *param_1,int *param_2)
{
  if (param_2 != (int *)0x0) {
    for (; param_1 != (int *)0x0; param_1 = (int *)*param_1) {
      if ((int *)*param_1 == param_2) {
        *param_1 = *param_2;
        return 0;
      }
    }
  }
  return 0xffffffff;
}
#endif
