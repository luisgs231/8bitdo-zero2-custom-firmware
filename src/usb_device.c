/* usb_device.c: guessed: the USB descriptors and the device stack */

#include "zero2.h"

/* 01020dc8 */
#ifdef NONMATCHING
void FUN_01020dc8(void)
{
  FUN_01022998();
  FUN_010240ac(0x21a54,100);
  FUN_01023d5c(0x21a54);
  return;
}
#endif

/* 01020de4 */
#ifdef NONMATCHING
void FUN_01020de4(void)
{
  FUN_010240c8(0x21a54,0x1020dc9);
  FUN_010240ac(0x21a54,100);
  FUN_01023d5c(0x21a54);
  return;
}
#endif

/* 01020edc */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01020edc(void)
{
  core_bringup();
  _DAT_000f8560 = _DAT_000f8560 | 0x1000;
  return;
}
#endif

/* 01020ef8 */
#ifdef NONMATCHING
undefined4 FUN_01020ef8(int param_1,undefined4 param_2)
{
  (**(code **)(*(int *)(param_1 + 0x494) + 4))(param_1,param_2);
  return 0;
}
#endif

/* 01020f16 */
#ifdef NONMATCHING
void FUN_01020f16(int param_1,int param_2)
{
  if ((*(char *)(param_1 + 0x3a) == '\x02') || (*(char *)(param_1 + 0x3a) == '\x03')) {
    if (*(short *)(param_2 + 2) == 1) {
      *(undefined4 *)(param_1 + 0x40) = 0;
      (**(code **)(*(int *)(param_1 + 0x494) + 8))(param_1,param_2);
      FUN_01020fae(param_1);
    }
  }
  else {
    FUN_01020f7a(param_1,param_2);
  }
  return;
}
#endif

/* 01020f60 */
#ifdef NONMATCHING
undefined4 FUN_01020f60(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  FUN_0101ad98(param_1,0,param_2,param_3,param_4);
  return 0;
}
#endif

/* 01020f7a */
#ifdef NONMATCHING
void FUN_01020f7a(undefined4 param_1)
{
  FUN_0101ae58(param_1,0);
  return;
}
#endif

/* 01020f8a */
#ifdef NONMATCHING
undefined4 FUN_01020f8a(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  *(undefined4 *)(param_1 + 0x60) = param_3;
  *(undefined4 *)(param_1 + 0x5c) = param_3;
  *(undefined1 *)(param_1 + 0x39) = 2;
  FUN_0101aea4(param_1,0,param_2,param_3,param_4);
  return 0;
}
#endif

/* 01020fae */
#ifdef NONMATCHING
undefined4 FUN_01020fae(int param_1)
{
  *(undefined1 *)(param_1 + 0x39) = 4;
  FUN_01022488(param_1,0);
  return 0;
}
#endif

/* 01020fc6 */
#ifdef NONMATCHING
undefined4 FUN_01020fc6(int param_1,int param_2)
{
  if (((param_2 != 0) && (*(int *)(*(int *)(param_1 + 0x494) + 0x14) != 0)) &&
     (*(char *)(param_1 + 0x3a) == '\x03')) {
    (**(code **)(*(int *)(param_1 + 0x494) + 0x14))(param_1,param_2);
  }
  return 0;
}
#endif

/* 01020ffe */
#ifdef NONMATCHING
undefined4 FUN_01020ffe(int param_1,int param_2)
{
  ushort uVar1;
  
  if (param_2 == 0) {
    if (*(char *)(param_1 + 0x39) == '\x03') {
      if ((uint)*(byte *)(param_1 + 0x267) < *(uint *)(param_1 + 0x278)) {
        *(uint *)(param_1 + 0x278) = *(int *)(param_1 + 0x278) - (uint)*(byte *)(param_1 + 0x267);
        if (*(char *)(param_1 + 3) == '\x01') {
          *(uint *)(param_1 + 0x268) = *(int *)(param_1 + 0x268) + (uint)*(byte *)(param_1 + 0x267);
        }
        if (*(uint *)(param_1 + 0x278) < (uint)*(byte *)(param_1 + 0x267)) {
          uVar1 = (ushort)*(undefined4 *)(param_1 + 0x278);
        }
        else {
          uVar1 = (ushort)*(byte *)(param_1 + 0x267);
        }
        FUN_01020f60(param_1,*(undefined4 *)(param_1 + 0x268),uVar1);
      }
      else {
        if ((*(int *)(*(int *)(param_1 + 0x494) + 0x10) != 0) &&
           (*(char *)(param_1 + 0x3a) == '\x03')) {
          (**(code **)(*(int *)(param_1 + 0x494) + 0x10))(param_1);
        }
        FUN_01020fae(param_1);
      }
    }
  }
  else if ((*(int *)(*(int *)(param_1 + 0x494) + 0x18) != 0) &&
          (*(char *)(param_1 + 0x3a) == '\x03')) {
    (**(code **)(*(int *)(param_1 + 0x494) + 0x18))(param_1,param_2);
  }
  return 0;
}
#endif

/* 010210b2 */
#ifdef NONMATCHING
longlong FUN_010210b2(uint param_1)
{
  return (ulonglong)param_1 << 0x20;
}
#endif

/* 010210b8 */
#ifdef NONMATCHING
undefined4 FUN_010210b8(int param_1)
{
  (**(code **)(*(int *)(param_1 + 0x498) + 0x14))();
  *(undefined1 *)(param_1 + 0x3e) = 1;
  return 0;
}
#endif

/* 010210d6 */
#ifdef NONMATCHING
undefined4 FUN_010210d6(int param_1)
{
  (**(code **)(*(int *)(param_1 + 0x498) + 0x18))();
  (**(code **)(*(int *)(param_1 + 0x494) + 4))(param_1,0);
  *(undefined1 *)(param_1 + 0x3e) = 0;
  return 0;
}
#endif

/* 01021108 */
#ifdef NONMATCHING
void FUN_01021108(int param_1,int param_2)
{
  if (*(short *)(param_2 + 6) == 1) {
    if (*(char *)(param_1 + 0x3a) == '\x02') {
      FUN_01020f8a(param_1,0x200e8,1);
    }
    else if (*(char *)(param_1 + 0x3a) == '\x03') {
      FUN_01020f8a(param_1,param_1 + 0x38,1);
    }
    else {
      FUN_01020f7a(param_1,param_2);
    }
  }
  else {
    FUN_01020f7a(param_1,param_2);
  }
  return;
}
#endif

/* 01021158 */
#ifdef NONMATCHING
void FUN_01021158(void)
{
                    /* WARNING: Subroutine does not return */
  yc_switch8();
}
#endif

/* 01021172 */
#ifdef NONMATCHING
void FUN_01021172(void)
{
  int unaff_r4;
  int unaff_r6;
  short in_stack_00000000;
  
  (*(code *)**(undefined4 **)(unaff_r4 + 0x49c))(*(undefined1 *)(unaff_r4 + 2));
  if ((in_stack_00000000 != 0) && (*(short *)(unaff_r6 + 6) != 0)) {
    FUN_01020f8a();
  }
  return;
}
#endif

/* 0102118a */
#ifdef NONMATCHING
void FUN_0102118a(void)
{
  int iVar1;
  int unaff_r4;
  int unaff_r6;
  short in_stack_00000000;
  
  iVar1 = (**(code **)(*(int *)(unaff_r4 + 0x494) + 0x28))(*(undefined1 *)(unaff_r4 + 2));
  *(undefined1 *)(iVar1 + 1) = 2;
  *(int *)(unaff_r4 + 0x4a0) = iVar1;
  if ((in_stack_00000000 != 0) && (*(short *)(unaff_r6 + 6) != 0)) {
    FUN_01020f8a();
  }
  return;
}
#endif

/* 010211b2 */
#ifdef NONMATCHING
void FUN_010211b2(void)
{
                    /* WARNING: Subroutine does not return */
  yc_switch8();
}
#endif

/* 010211c2 */
#ifdef NONMATCHING
void FUN_010211c2(void)
{
  int unaff_r4;
  int unaff_r6;
  short in_stack_00000000;
  
  (**(code **)(*(int *)(unaff_r4 + 0x49c) + 4))(*(undefined1 *)(unaff_r4 + 2));
  if ((in_stack_00000000 != 0) && (*(short *)(unaff_r6 + 6) != 0)) {
    FUN_01020f8a();
  }
  return;
}
#endif

/* 010211da */
#ifdef NONMATCHING
void FUN_010211da(void)
{
  int unaff_r4;
  int unaff_r6;
  short in_stack_00000000;
  
  (**(code **)(*(int *)(unaff_r4 + 0x49c) + 8))(*(undefined1 *)(unaff_r4 + 2));
  if ((in_stack_00000000 != 0) && (*(short *)(unaff_r6 + 6) != 0)) {
    FUN_01020f8a();
  }
  return;
}
#endif

/* 010211f2 */
#ifdef NONMATCHING
void FUN_010211f2(void)
{
  int unaff_r4;
  int unaff_r6;
  short in_stack_00000000;
  
  (**(code **)(*(int *)(unaff_r4 + 0x49c) + 0xc))(*(undefined1 *)(unaff_r4 + 2));
  if ((in_stack_00000000 != 0) && (*(short *)(unaff_r6 + 6) != 0)) {
    FUN_01020f8a();
  }
  return;
}
#endif

/* 0102120a */
#ifdef NONMATCHING
void FUN_0102120a(void)
{
  int unaff_r4;
  int unaff_r6;
  short in_stack_00000000;
  
  (**(code **)(*(int *)(unaff_r4 + 0x49c) + 0x10))(*(undefined1 *)(unaff_r4 + 2));
  if (*(char *)(unaff_r4 + 0x3a) == '\x03') {
    *(undefined1 *)(unaff_r4 + 0x3b) = 5;
  }
  if ((in_stack_00000000 != 0) && (*(short *)(unaff_r6 + 6) != 0)) {
    FUN_01020f8a();
  }
  return;
}
#endif

/* 01021230 */
#ifdef NONMATCHING
void FUN_01021230(void)
{
  int unaff_r4;
  int unaff_r6;
  short in_stack_00000000;
  
  (**(code **)(*(int *)(unaff_r4 + 0x49c) + 0x14))(*(undefined1 *)(unaff_r4 + 2));
  if ((in_stack_00000000 != 0) && (*(short *)(unaff_r6 + 6) != 0)) {
    FUN_01020f8a();
  }
  return;
}
#endif

/* 01021248 */
#ifdef NONMATCHING
void FUN_01021248(void)
{
  int unaff_r4;
  int unaff_r6;
  short in_stack_00000000;
  
  (**(code **)(*(int *)(unaff_r4 + 0x49c) + 0x18))(*(undefined1 *)(unaff_r4 + 2));
  if ((in_stack_00000000 != 0) && (*(short *)(unaff_r6 + 6) != 0)) {
    FUN_01020f8a();
  }
  return;
}
#endif

/* 01021260 */
#ifdef NONMATCHING
void FUN_01021260(void)
{
  FUN_01020f7a();
  return;
}
#endif

/* 0102126e */
#ifdef NONMATCHING
void FUN_0102126e(void)
{
  FUN_01020f7a();
  return;
}
#endif

/* 01021278 */
#ifdef NONMATCHING
void FUN_01021278(void)
{
  FUN_01020f7a();
  return;
}
#endif

/* 01021282 */
#ifdef NONMATCHING
void FUN_01021282(void)
{
  FUN_01020f7a();
  return;
}
#endif

/* 010212c0 */
#ifdef NONMATCHING
char FUN_010212c0(char *param_1)
{
  char cVar1;
  
  cVar1 = '\0';
  for (; *param_1 != '\0'; param_1 = param_1 + 1) {
    cVar1 = cVar1 + '\x01';
  }
  return cVar1;
}
#endif

/* 010212d4 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_010212d4(int param_1,undefined4 param_2)
{
  if ((*(char *)(param_1 + 0x3a) == '\x02') || (*(char *)(param_1 + 0x3a) == '\x03')) {
    _DAT_000200ec = 1;
    if (*(int *)(param_1 + 0x40) != 0) {
      _DAT_000200ec = 3;
    }
    FUN_01020f8a(param_1,&DAT_000200ec,2);
  }
  else {
    FUN_01020f7a(param_1,param_2);
  }
  return;
}
#endif

/* 01021320 */
#ifdef NONMATCHING
void FUN_01021320(char *param_1,undefined1 *param_2,short *param_3)
{
  short sVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_1 != (char *)0x0) {
    sVar1 = FUN_010212c0(param_1);
    *param_3 = sVar1 * 2 + 2;
    *param_2 = (char)*param_3;
    uVar2 = 2;
    param_2[1] = 3;
    for (; *param_1 != '\0'; param_1 = param_1 + 1) {
      uVar3 = uVar2 + 1 & 0xff;
      param_2[uVar2] = *param_1;
      uVar2 = uVar3 + 1 & 0xff;
      param_2[uVar3] = 0;
    }
  }
  return;
}
#endif

/* 0102136e */
#ifdef NONMATCHING
undefined4 FUN_0102136e(void)
{
  return 0;
}
#endif

/* 01021374 */
#ifdef NONMATCHING
undefined4 FUN_01021374(undefined4 param_1)
{
  FUN_0101ad98(param_1,2,0x21618,0x40);
  DAT_00020130 = 1;
  return 0;
}
#endif

/* 01021398 */
#ifdef NONMATCHING
undefined4 FUN_01021398(undefined4 param_1)
{
  FUN_0101ace4(param_1,0x81);
  if (DAT_00020060 == '\x01') {
    FUN_0101ace4(param_1,2);
  }
  else {
    FUN_0101ace4(param_1,2);
  }
  return 0;
}
#endif

/* 010213c8 */
#ifdef NONMATCHING
undefined * FUN_010213c8(undefined4 param_1,undefined2 *param_2)
{
  undefined *puVar1;
  
  if (*FUN_01021422 == '\x03') {
    *param_2 = 0x29;
    puVar1 = &DAT_01027a12;
  }
  else if (*FUN_01021422 == '\x01') {
    *param_2 = 0x8b;
    puVar1 = &DAT_01027aad;
  }
  else if (*FUN_01021422 == '\0') {
    *param_2 = 0x29;
    puVar1 = &DAT_01027bd1;
  }
  else if (*FUN_01021422 == '\x02') {
    *param_2 = 0x29;
    puVar1 = &DAT_01027bfa;
  }
  else if (*FUN_01021422 == '\x04') {
    *param_2 = 0x3b;
    puVar1 = &DAT_01027fd1;
  }
  else {
    *param_2 = 0x29;
    puVar1 = &DAT_01027a12;
  }
  return puVar1;
}
#endif

/* 01021422 */
#ifdef NONMATCHING
undefined4 FUN_01021422(void)
{
  int iVar1;
  int unaff_r4;
  
  iVar1 = unaff_r4 << 1;
  if (DAT_00020060 == '\x04') {
    FUN_0101ad2e(iVar1,0x81,0x40,3);
    FUN_0101ad2e(iVar1,0x82,0x40,3);
  }
  else {
    FUN_0101ad2e(iVar1,0x81,0x40,3);
  }
  if (DAT_00020060 == '\x01') {
    FUN_0101ad2e(iVar1,2,0x40,3);
  }
  else if (DAT_00020060 != '\x04') {
    FUN_0101ad2e(iVar1,2,0x40,3);
  }
  return 0;
}
#endif

/* 0102143c */
#ifdef NONMATCHING
undefined4 FUN_0102143c(undefined4 param_1)
{
  if (DAT_00020060 == '\x04') {
    FUN_0101ad2e(param_1,0x81,0x40,3);
    FUN_0101ad2e(param_1,0x82,0x40,3);
  }
  else {
    FUN_0101ad2e(param_1,0x81,0x40,3);
  }
  if (DAT_00020060 == '\x01') {
    FUN_0101ad2e(param_1,2,0x40,3);
  }
  else if (DAT_00020060 != '\x04') {
    FUN_0101ad2e(param_1,2,0x40,3);
  }
  return 0;
}
#endif

/* 010214a4 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_010214a4(undefined4 param_1,byte *param_2,undefined4 param_3,undefined4 param_4)
{
  byte bVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined *puVar4;
  
  uVar2 = 0;
  puVar4 = (undefined *)0x0;
  _DAT_0002012c = _DAT_0002012c + 1;
  bVar1 = *param_2 & 0x60;
  if ((*param_2 & 0x60) == 0) {
    bVar1 = param_2[1];
    if (bVar1 == 1) {
      if ((DAT_00020060 == '\x04') && (*(short *)(param_2 + 2) == 0)) {
        FUN_01024ad0();
      }
    }
    else if (bVar1 == 6) {
      if ((int)(uint)*(ushort *)(param_2 + 2) >> 8 == 0x22) {
        if (DAT_00020060 == '\x03') {
          if (*(ushort *)(param_2 + 6) < 0x88) {
            uVar2 = *(undefined2 *)(param_2 + 6);
          }
          else {
            uVar2 = 0x87;
          }
          puVar4 = &DAT_01027a3b;
        }
        else if (DAT_00020060 == '\x01') {
          if (*(ushort *)(param_2 + 6) < 0x79) {
            uVar2 = *(undefined2 *)(param_2 + 6);
          }
          else {
            uVar2 = 0x78;
          }
          puVar4 = &DAT_01027c23;
        }
        else if (DAT_00020060 == '\0') {
          if (*(ushort *)(param_2 + 6) < 0xcc) {
            uVar2 = *(undefined2 *)(param_2 + 6);
          }
          else {
            uVar2 = 0xcb;
          }
          puVar4 = &DAT_01027c9b;
        }
        else if (DAT_00020060 == '\x02') {
          if (*(ushort *)(param_2 + 6) < 500) {
            uVar2 = *(undefined2 *)(param_2 + 6);
          }
          else {
            uVar2 = 499;
          }
          puVar4 = &DAT_01027d66;
        }
        else if (DAT_00020060 == '\x04') {
          if (*(short *)(param_2 + 4) == 0) {
            if (*(ushort *)(param_2 + 6) < 0x3c) {
              uVar2 = *(undefined2 *)(param_2 + 6);
            }
            else {
              uVar2 = 0x3b;
            }
            puVar4 = &DAT_0102800c;
          }
          else if (*(short *)(param_2 + 4) == 1) {
            if (*(ushort *)(param_2 + 6) < 0xb2) {
              uVar2 = *(undefined2 *)(param_2 + 6);
            }
            else {
              uVar2 = 0xb1;
            }
            puVar4 = &DAT_01028047;
          }
        }
        FUN_0101ded0();
      }
      else if ((int)(uint)*(ushort *)(param_2 + 2) >> 8 == 0x21) {
        if (DAT_00020060 == '\x03') {
          puVar4 = &DAT_01027a24;
          if (*(ushort *)(param_2 + 6) < 10) {
            uVar2 = *(undefined2 *)(param_2 + 6);
          }
          else {
            uVar2 = 9;
          }
        }
        else if (DAT_00020060 == '\x01') {
          puVar4 = (undefined *)0x0;
          uVar2 = 0;
        }
        else if (DAT_00020060 == '\0') {
          puVar4 = &DAT_01027be3;
          if (*(ushort *)(param_2 + 6) < 10) {
            uVar2 = *(undefined2 *)(param_2 + 6);
          }
          else {
            uVar2 = 9;
          }
        }
        else if (DAT_00020060 == '\x02') {
          puVar4 = &DAT_01027c0c;
          if (*(ushort *)(param_2 + 6) < 10) {
            uVar2 = *(undefined2 *)(param_2 + 6);
          }
          else {
            uVar2 = 9;
          }
        }
        else if (DAT_00020060 == '\x04') {
          puVar4 = &DAT_01027fe3;
          if (*(ushort *)(param_2 + 6) < 10) {
            uVar2 = *(undefined2 *)(param_2 + 6);
          }
          else {
            uVar2 = 9;
          }
        }
      }
      FUN_01020f8a(param_1,puVar4,uVar2);
    }
    else if (bVar1 == 10) {
      FUN_01020f8a(param_1,&DAT_00020120,1,param_4,param_2,param_3,param_4);
    }
    else if (bVar1 == 0xb) {
      _DAT_00020120 = (uint)param_2[2];
    }
  }
  else {
    if (bVar1 == 0x20) {
                    /* WARNING: Subroutine does not return */
      yc_switch8();
    }
    if (bVar1 == 0x40) {
      uVar3 = FUN_01021784();
      return uVar3;
    }
  }
  return 0;
}
#endif

/* 010214e2 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong FUN_010214e2(void)
{
  int unaff_r4;
  uint in_stack_00000000;
  
  _DAT_00020124 = (uint)*(byte *)(unaff_r4 + 2);
  return (ulonglong)in_stack_00000000 << 0x20;
}
#endif

/* 010214ea */
#ifdef NONMATCHING
longlong FUN_010214ea(void)
{
  uint in_stack_00000000;
  
  FUN_01020f8a();
  return (ulonglong)in_stack_00000000 << 0x20;
}
#endif

/* 010214f6 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong FUN_010214f6(void)
{
  int unaff_r4;
  uint in_stack_00000000;
  
  _DAT_00020128 = (int)(uint)*(ushort *)(unaff_r4 + 2) >> 8;
  DAT_000210eb = 5;
  return (ulonglong)in_stack_00000000 << 0x20;
}
#endif

/* 01021506 */
#ifdef NONMATCHING
longlong FUN_01021506(void)
{
  uint in_stack_00000000;
  
  FUN_01020f8a();
  return (ulonglong)in_stack_00000000 << 0x20;
}
#endif

/* 01021512 */
#ifdef NONMATCHING
longlong FUN_01021512(void)
{
  int unaff_r4;
  uint in_stack_00000000;
  
  DAT_00020133 = 1;
  DAT_00020134 = (undefined1)((ushort)*(undefined2 *)(unaff_r4 + 2) >> 8);
  DAT_00020135 = *(undefined1 *)(unaff_r4 + 2);
  DAT_00020136 = *(undefined1 *)(unaff_r4 + 6);
  if (DAT_00020060 == '\x04') {
    FUN_01020fae();
  }
  return (ulonglong)in_stack_00000000 << 0x20;
}
#endif

/* 01021536 */
#ifdef NONMATCHING
longlong FUN_01021536(void)
{
  int unaff_r4;
  undefined1 uStack00000000;
  undefined1 uStack00000001;
  undefined1 uStack00000002;
  undefined1 uStack00000003;
  undefined1 uStack00000004;
  undefined1 uStack00000005;
  
  if (DAT_00020060 == '\x02') {
    if (*(short *)(unaff_r4 + 2) == 0x312) {
      memcpy(0x215d8,&DAT_01027f59,0x10);
      FUN_0101c294();
      DAT_000215de = uStack00000000;
      DAT_000215dd = uStack00000001;
      DAT_000215dc = uStack00000002;
      DAT_000215db = uStack00000003;
      DAT_000215da = uStack00000004;
      DAT_000215d9 = uStack00000005;
      FUN_01020f8a();
    }
    else if (*(short *)(unaff_r4 + 2) == 0x302) {
      memcpy(0x215d8,&DAT_01027f69,0x25);
      FUN_01020f8a();
    }
    else if (*(short *)(unaff_r4 + 2) == 0x3a3) {
      memcpy(0x215d8,&DAT_01027f8e,0x31);
      FUN_01020f8a();
    }
    else {
      memcpy(0x215d8,&DAT_01027f59,0x10);
      FUN_01020f8a();
    }
  }
  else {
    FUN_01020f8a();
  }
  return (ulonglong)_uStack00000000 << 0x20;
}
#endif

/* 010215ae */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong thunk_FUN_01021604(void)
{
  char cVar1;
  int unaff_r4;
  uint in_stack_00000000;
  
  cVar1 = *(char *)(unaff_r4 + 1);
  if (cVar1 == '\x01') {
    if ((DAT_00020060 == '\x04') && (*(short *)(unaff_r4 + 2) == 0)) {
      FUN_01024ad0();
    }
  }
  else if (cVar1 == '\x06') {
    if ((int)(uint)*(ushort *)(unaff_r4 + 2) >> 8 == 0x22) {
      FUN_0101ded0();
    }
    FUN_01020f8a();
  }
  else if (cVar1 == '\n') {
    FUN_01020f8a();
  }
  else if (cVar1 == '\v') {
    _DAT_00020120 = (uint)*(byte *)(unaff_r4 + 2);
  }
  return (ulonglong)in_stack_00000000 << 0x20;
}
#endif

/* 010215b0 */
#ifdef NONMATCHING
longlong FUN_010215b0(void)
{
  uint in_stack_00000000;
  
  return (ulonglong)in_stack_00000000 << 0x20;
}
#endif

/* 010215b2 */
#ifdef NONMATCHING
longlong FUN_010215b2(void)
{
  int unaff_r4;
  uint in_stack_00000000;
  
  if (*(short *)(unaff_r4 + 2) == 0x3a3) {
    memcpy(0x215d8,&DAT_01027f8e,0x31);
    FUN_01020f8a();
  }
  else {
    memcpy(0x215d8,&DAT_01027f59,0x10);
    FUN_01020f8a();
  }
  return (ulonglong)in_stack_00000000 << 0x20;
}
#endif

/* 010215f4 */
#ifdef NONMATCHING
undefined8 FUN_010215f4(void)
{
  undefined4 in_stack_00000000;
  
  FUN_01020f7a();
  return CONCAT44(in_stack_00000000,2);
}
#endif

/* 01021604 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong FUN_01021604(void)
{
  char cVar1;
  int unaff_r4;
  uint in_stack_00000000;
  
  cVar1 = *(char *)(unaff_r4 + 1);
  if (cVar1 == '\x01') {
    if ((DAT_00020060 == '\x04') && (*(short *)(unaff_r4 + 2) == 0)) {
      FUN_01024ad0();
    }
  }
  else if (cVar1 == '\x06') {
    if ((int)(uint)*(ushort *)(unaff_r4 + 2) >> 8 == 0x22) {
      FUN_0101ded0();
    }
    FUN_01020f8a();
  }
  else if (cVar1 == '\n') {
    FUN_01020f8a();
  }
  else if (cVar1 == '\v') {
    _DAT_00020120 = (uint)*(byte *)(unaff_r4 + 2);
  }
  return (ulonglong)in_stack_00000000 << 0x20;
}
#endif

/* 01021784 */
#ifdef NONMATCHING
longlong FUN_01021784(void)
{
  int unaff_r4;
  uint in_stack_00000000;
  undefined4 uStack00000008;
  
  if (*(char *)(unaff_r4 + 1) == '\x01') {
    uStack00000008 = 0;
    FUN_01020f8a();
  }
  return (ulonglong)in_stack_00000000 << 0x20;
}
#endif

/* 010217fc */
#ifdef NONMATCHING
void FUN_010217fc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)
{
  FUN_010210b2(param_1);
  *(undefined4 *)(param_1 + 0x494) = param_4;
  *(undefined4 *)(param_1 + 0x498) = param_5;
  *(undefined4 *)(param_1 + 0x49c) = param_3;
  FUN_0101b1b0(param_1,param_2);
  return;
}
#endif

/* 01021836 */
#ifdef NONMATCHING
undefined4 FUN_01021836(int param_1)
{
  (**(code **)(*(int *)(param_1 + 0x494) + 0x20))(param_1);
  return 0;
}
#endif

/* 01021850 */
#ifdef NONMATCHING
undefined4 FUN_01021850(int param_1)
{
  (**(code **)(*(int *)(param_1 + 0x494) + 0x24))(param_1);
  return 0;
}
#endif

/* 0102186c */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0102186c(int param_1)
{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  
  bVar1 = *(byte *)(*(int *)(param_1 + 0x34) + 1);
  bVar2 = *(byte *)(*(int *)(param_1 + 0x34) + 2);
  if ((bVar1 != 0) || (uVar3 = 0, bVar2 != 0)) {
    uVar3 = 0;
    if ((char)bVar1 < '\0') {
      uVar3 = (**(code **)(_DAT_000200d8 + 0x10))(param_1);
    }
    *(undefined1 *)(*(int *)(param_1 + 0x34) + 1) = 0xe0;
    if ((bVar1 & 0xe) != 0) {
      *(byte *)(*(int *)(param_1 + 0x34) + 1) = bVar1 & 0xe;
      uVar4 = FUN_0101b174(param_1,bVar1 & 0xe);
      uVar3 = uVar3 | uVar4;
    }
    if ((bVar1 & 1) != 0) {
      if (DAT_00020138 != '\0') {
        *(byte *)(*(int *)(param_1 + 0xc) + 4) = *(byte *)(*(int *)(param_1 + 0xc) + 4) | 0x80;
        DAT_00020138 = '\0';
      }
      if ((bVar1 & 0x1f) >> 4 == 0) {
        *(undefined1 *)(*(int *)(param_1 + 0x34) + 1) = 1;
        FUN_0101b108(param_1);
      }
      else {
        *(undefined1 *)(*(int *)(param_1 + 0x34) + 1) = 0x11;
        (**(code **)(_DAT_000200d8 + 8))(param_1);
      }
    }
    if ((bVar2 & 0xf) != 0) {
      if ((bVar2 & 3) >> 1 != 0) {
        FUN_0101b4e0();
      }
      *(byte *)(*(int *)(param_1 + 0x34) + 2) = bVar2;
      uVar4 = FUN_0101aef0(param_1,bVar2 & 0xf);
      uVar3 = uVar3 | uVar4;
    }
  }
  return uVar3;
}
#endif

/* 01021964 */
#ifdef NONMATCHING
void FUN_01021964(int param_1,undefined1 *param_2)
{
  *param_2 = *(undefined1 *)(param_1 + 0x47c);
  param_2[1] = *(undefined1 *)(param_1 + 0x47d);
  *(undefined2 *)(param_2 + 2) = *(undefined2 *)(param_1 + 0x47e);
  *(undefined2 *)(param_2 + 4) = *(undefined2 *)(param_1 + 0x480);
  *(undefined2 *)(param_2 + 6) = *(undefined2 *)(param_1 + 0x482);
  *(undefined1 *)(param_1 + 100) = param_2[6];
  *(undefined1 *)(param_1 + 0x39) = 1;
  return;
}
#endif

/* 010219dc */
#ifdef NONMATCHING
undefined4 FUN_010219dc(int param_1)
{
  FUN_0101ad2e(param_1,0,0x40);
  FUN_0101ad2e(param_1,0x80,0x40,0);
  *(undefined1 *)(param_1 + 0x3a) = 1;
  (**(code **)(*(int *)(param_1 + 0x498) + 4))(*(undefined1 *)(param_1 + 2));
  return 0;
}
#endif

/* 01021a12 */
#ifdef NONMATCHING
undefined4 FUN_01021a12(int param_1)
{
  (**(code **)(*(int *)(param_1 + 0x498) + 0x10))();
  *(undefined1 *)(param_1 + 0x3a) = *(undefined1 *)(param_1 + 0x3c);
  *(undefined1 *)(param_1 + 0x3a) = 3;
  return 0;
}
#endif

/* 01021a36 */
#ifdef NONMATCHING
undefined4 FUN_01021a36(int param_1)
{
  if (*(int *)(*(int *)(param_1 + 0x494) + 0x1c) != 0) {
    (**(code **)(*(int *)(param_1 + 0x494) + 0x1c))(param_1);
  }
  return 0;
}
#endif

/* 01021a60 */
#ifdef NONMATCHING
void FUN_01021a60(int param_1,int param_2)
{
  byte bVar1;
  
  if ((*(short *)(param_2 + 4) == 0) && (*(short *)(param_2 + 6) == 0)) {
    bVar1 = *(byte *)(param_2 + 2);
    if (*(char *)(param_1 + 0x3a) == '\x03') {
      FUN_01020f7a(param_1,param_2);
    }
    else {
      *(byte *)(param_1 + 0x3d) = bVar1 & 0x7f;
      *(undefined1 *)(*(int *)(param_1 + 0xc) + 4) = DAT_00020139;
      FUN_01020fae(param_1);
      if ((bVar1 & 0x7f) == 0) {
        *(undefined1 *)(param_1 + 0x3a) = 1;
      }
      else {
        *(undefined1 *)(param_1 + 0x3a) = 2;
      }
    }
  }
  else {
    FUN_01020f7a(param_1,param_2);
  }
  return;
}
#endif

/* 01021ac0 */
#ifdef NONMATCHING
undefined4 FUN_01021ac0(int param_1,undefined4 param_2)
{
  (*(code *)**(undefined4 **)(param_1 + 0x494))(param_1,param_2);
  (**(code **)(*(int *)(param_1 + 0x498) + 8))();
  return 0;
}
#endif

/* 01021af0 */
#ifdef NONMATCHING
void FUN_01021af0(int param_1,int param_2)
{
  DAT_000200f0 = *(byte *)(param_2 + 2);
  if (DAT_000200f0 < 2) {
    if (*(char *)(param_1 + 0x3a) == '\x02') {
      if (DAT_000200f0 == 0) {
        FUN_01020fae(param_1);
      }
      else {
        *(byte *)(param_1 + 0x38) = DAT_000200f0;
        *(undefined1 *)(param_1 + 0x3a) = 3;
        FUN_01021ac0(param_1,DAT_000200f0);
        FUN_01020fae(param_1);
      }
    }
    else if (*(char *)(param_1 + 0x3a) == '\x03') {
      if (DAT_000200f0 == 0) {
        *(undefined1 *)(param_1 + 0x3a) = 2;
        *(byte *)(param_1 + 0x38) = DAT_000200f0;
        FUN_01020ef8(param_1,DAT_000200f0);
        FUN_01020fae(param_1);
      }
      else if (*(byte *)(param_1 + 0x38) == DAT_000200f0) {
        FUN_01020fae(param_1);
      }
      else {
        FUN_01020ef8(param_1,*(undefined1 *)(param_1 + 0x38));
        *(byte *)(param_1 + 0x38) = DAT_000200f0;
        FUN_01021ac0(param_1,DAT_000200f0);
        FUN_01020fae(param_1);
      }
    }
    else {
      FUN_01020f7a(param_1,param_2);
    }
  }
  else {
    FUN_01020f7a(param_1,param_2);
  }
  return;
}
#endif

/* 01021bc0 */
#ifdef NONMATCHING
/* WARNING: Removing unreachable block (ram,0x01021c36) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_01021bc0(int param_1)
{
  char cVar1;
  undefined1 auStack_58 [64];
  byte local_18 [8];
  
  cVar1 = **(char **)(param_1 + 0x24);
  _DAT_000200dc = _DAT_000200dc + 1;
  DAT_000201b4 = 3;
  if (cVar1 == '\b') {
    FUN_010225f0(param_1,param_1 + 0x47c,0,8);
  }
  else {
    DAT_000f6026 = 0x40;
    memzero(auStack_58);
    FUN_010225f0(param_1,param_1 + 0x47c,0,8);
    FUN_010225f0(param_1,auStack_58,0,cVar1 + -8);
  }
  FUN_01021964(param_1,local_18);
  if ((local_18[0] & 0x1f) == 0) {
    FUN_01021ca8(param_1,local_18);
  }
  else if ((local_18[0] & 0x1f) == 1) {
    FUN_01021ec4(param_1,local_18);
  }
  else if ((local_18[0] & 0x1f) == 2) {
    FUN_01021d54(param_1,local_18);
  }
  else {
    FUN_0101ae58(param_1,local_18[0] & 0x80);
  }
  return 0;
}
#endif

/* 01021ca8 */
#ifdef NONMATCHING
void FUN_01021ca8(void)
{
                    /* WARNING: Subroutine does not return */
  yc_switch8();
}
#endif

/* 01021cc4 */
#ifdef NONMATCHING
void FUN_01021cc4(void)
{
  FUN_01021158();
  FUN_01021d46();
  return;
}
#endif

/* 01021cce */
#ifdef NONMATCHING
void FUN_01021cce(void)
{
  int unaff_r4;
  
  DAT_00020138 = 1;
  DAT_00020139 = *(byte *)(unaff_r4 + 2) & 0x7f;
  FUN_01021a60();
  FUN_01021d46();
  return;
}
#endif

/* 01021ce8 */
#ifdef NONMATCHING
void FUN_01021ce8(void)
{
  FUN_01021af0();
  FUN_01021d46();
  return;
}
#endif

/* 01021cf2 */
#ifdef NONMATCHING
void FUN_01021cf2(void)
{
  FUN_01021108();
  FUN_01021d46();
  return;
}
#endif

/* 01021cfc */
#ifdef NONMATCHING
void FUN_01021cfc(void)
{
  FUN_010212d4();
  FUN_01021d46();
  return;
}
#endif

/* 01021d06 */
#ifdef NONMATCHING
void FUN_01021d06(void)
{
  int unaff_r5;
  undefined1 uStack00000000;
  
  *(undefined4 *)(unaff_r5 + 0x40) = 1;
  _uStack00000000 = (DAT_000f6000 & 0xffffff7f) + 0x80;
  DAT_000f6000 = uStack00000000;
  FUN_01020fae();
  FUN_01021d46();
  return;
}
#endif

/* 01021d30 */
#ifdef NONMATCHING
void FUN_01021d30(void)
{
  FUN_01020f16();
  FUN_01021d46();
  return;
}
#endif

/* 01021d3a */
#ifdef NONMATCHING
void thunk_FUN_01021d46(void)
{
  return;
}
#endif

/* 01021d3c */
#ifdef NONMATCHING
void FUN_01021d3c(void)
{
  FUN_01020f7a();
  return;
}
#endif

/* 01021d46 */
#ifdef NONMATCHING
void FUN_01021d46(void)
{
  return;
}
#endif

/* 01021d54 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_01021d54(int param_1,int param_2,undefined4 param_3,undefined4 param_4)
{
  char cVar1;
  uint uVar2;
  
  uVar2 = (uint)*(byte *)(param_2 + 4);
  cVar1 = *(char *)(param_2 + 1);
  if (cVar1 == '\0') {
    if (*(char *)(param_1 + 0x3a) == '\x02') {
      if ((uVar2 != 0) && (uVar2 != 0x80)) {
        FUN_0101ae58(param_1,uVar2,param_3,param_4,param_4);
      }
    }
    else if (*(char *)(param_1 + 0x3a) == '\x03') {
      if ((uVar2 & 0x80) == 0x80) {
        if (*(char *)((uVar2 & 0x7f) * 0x24 + param_1 + 0x46) == '\0') {
          _DAT_000200e4 = 0;
        }
        else {
          _DAT_000200e4 = 1;
        }
      }
      else if ((*(byte *)(param_2 + 4) & 0x80) == 0) {
        if (*(char *)(uVar2 * 0x24 + param_1 + 0x262) == '\0') {
          _DAT_000200e4 = 0;
        }
        else {
          _DAT_000200e4 = 1;
        }
      }
      FUN_01020f8a(param_1,&DAT_000200e4,2);
    }
    else {
      FUN_01020f7a(param_1,param_2);
    }
  }
  else if (cVar1 == '\x01') {
    if (*(char *)(param_1 + 0x3a) == '\x02') {
      if ((uVar2 != 0) && (uVar2 != 0x80)) {
        FUN_0101ae58(param_1,uVar2,param_3,param_4,param_4);
      }
    }
    else if (*(char *)(param_1 + 0x3a) == '\x03') {
      if (*(short *)(param_2 + 2) == 0) {
        if ((uVar2 != 0) && (uVar2 != 0x80)) {
          (**(code **)(*(int *)(param_1 + 0x494) + 8))(param_1,param_2);
        }
        FUN_01020fae(param_1);
      }
    }
    else {
      FUN_01020f7a(param_1,param_2);
    }
  }
  else if (cVar1 == '\x03') {
    if (*(char *)(param_1 + 0x3a) == '\x02') {
      if ((uVar2 != 0) && (uVar2 != 0x80)) {
        FUN_0101ae58(param_1,uVar2,param_3,param_4,param_4);
      }
    }
    else if (*(char *)(param_1 + 0x3a) == '\x03') {
      if (((*(short *)(param_2 + 2) == 0) && (uVar2 != 0)) && (uVar2 != 0x80)) {
        FUN_0101ae58(param_1,uVar2,param_3,param_4,param_4);
      }
      (**(code **)(*(int *)(param_1 + 0x494) + 8))(param_1,param_2);
      FUN_01020fae(param_1);
    }
    else {
      FUN_01020f7a(param_1,param_2);
    }
  }
  return 0;
}
#endif

/* 01021ec4 */
#ifdef NONMATCHING
undefined4 FUN_01021ec4(int param_1,int param_2)
{
  if (*(char *)(param_1 + 0x3a) == '\x03') {
    if (*(byte *)(param_2 + 4) < 2) {
      (**(code **)(*(int *)(param_1 + 0x494) + 8))(param_1,param_2);
      if (*(short *)(param_2 + 6) == 0) {
        FUN_01020fae(param_1);
      }
    }
    else {
      FUN_01020f7a(param_1,param_2);
    }
  }
  else {
    FUN_01020f7a(param_1,param_2);
  }
  return 0;
}
#endif

/* 01021f1a */
#ifdef NONMATCHING
undefined4 FUN_01021f1a(int param_1)
{
  *(undefined1 *)(param_1 + 0x3c) = *(undefined1 *)(param_1 + 0x3a);
  *(undefined1 *)(param_1 + 0x3a) = 4;
  (**(code **)(*(int *)(param_1 + 0x498) + 0xc))();
  return 0;
}
#endif

/* 01021f40 */
#ifdef NONMATCHING
undefined4 FUN_01021f40(int param_1,undefined4 param_2)
{
  if (param_1 == 0) {
    FUN_01021320(STR_01021f7c,0x21598,param_2);
  }
  else if (DAT_00020060 == '\x04') {
    FUN_01021320(FUN_01021fa0,0x21598,param_2);
  }
  else {
    FUN_01021320(STR_01021f7c,0x21598,param_2);
  }
  return 0x21598;
}
#endif

/* 01021fa0 */
#ifdef NONMATCHING
int FUN_01021fa0(int param_1)
{
  return param_1 + 0x38;
}
#endif

/* 01021faa */
void FUN_01021faa(void)
{
  return;
}

/* 01021fac */
#ifdef NONMATCHING
undefined * FUN_01021fac(undefined4 param_1,undefined2 *param_2)
{
  undefined *puVar1;
  
  if (*FUN_01022002 == '\x03') {
    *param_2 = 0x12;
    puVar1 = &DAT_010279ca;
  }
  else if (*FUN_01022002 == '\x01') {
    *param_2 = 0x12;
    puVar1 = &DAT_010279dc;
  }
  else if (*FUN_01022002 == '\0') {
    *param_2 = 0x12;
    puVar1 = &DAT_010279ee;
  }
  else if (*FUN_01022002 == '\x02') {
    *param_2 = 0x12;
    puVar1 = &DAT_01027a00;
  }
  else if (*FUN_01022002 == '\x04') {
    *param_2 = 0x12;
    puVar1 = &DAT_01027fbf;
  }
  else {
    puVar1 = &DAT_010279ca;
  }
  return puVar1;
}
#endif

/* 01022002 */
#ifdef NONMATCHING
void FUN_01022002(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)
{
  int unaff_r4;
  
  log_empty(STR_01022028,param_2,(uint)*(byte *)(unaff_r4 * 2 + 8) << 4,param_4,
            *(undefined1 *)(param_4 + 7));
  return;
}
#endif

/* 0102201c */
#ifdef NONMATCHING
void FUN_0102201c(void)
{
  log_empty(STR_01022028);
  return;
}
#endif

/* 01022044 */
#ifdef NONMATCHING
void FUN_01022044(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  DAT_00021554 = 0;
  memzero(0x210b0,0x4a8,param_3,param_4,param_4);
  DAT_000210ea = 1;
  FUN_010217fc(0x210b0,1,0x20064,0x200f4,0x20090);
  DAT_000f6012 = 0x40;
  DAT_000f6029 = 0;
  DAT_000f602a = 0;
  DAT_000f6026 = 0xff;
  DAT_000f6027 = 0xff;
  DAT_000f6004 = 0;
  DAT_000f6001 = 0x70;
  DAT_000f6002 = 0xf0;
  DAT_000f6003 = 0xff;
  return;
}
#endif

/* 010220bc */
#ifdef NONMATCHING
undefined4 FUN_010220bc(int param_1,undefined4 param_2)
{
  if (param_1 == 0) {
    FUN_01021320(STR_010220e4,0x21598,param_2);
  }
  else {
    FUN_01021320(STR_010220e4,0x21598,param_2);
  }
  return 0x21598;
}
#endif

/* 01022104 */
#ifdef NONMATCHING
undefined4 FUN_01022104(undefined4 param_1,undefined2 *param_2)
{
  *param_2 = 4;
  return FUN_0102210e;
}
#endif

/* 0102210e */
#ifdef NONMATCHING
undefined4 FUN_0102210e(undefined4 param_1,undefined4 param_2)
{
  if (DAT_00020060 == '\x03') {
    FUN_01021320(STR_01022188,0x21598,param_2);
  }
  else if (DAT_00020060 == '\x01') {
    FUN_01021320(STR_01022188,0x21598,param_2);
  }
  else if (DAT_00020060 == '\0') {
    FUN_01021320(STR_01022190,0x21598,param_2);
  }
  else if (DAT_00020060 == '\x02') {
    FUN_01021320(STR_010221a4,0x21598,param_2);
  }
  else if (DAT_00020060 == '\x04') {
    FUN_01021320(STR_01022188,0x21598,param_2);
  }
  return 0x21598;
}
#endif

/* 01022114 */
#ifdef NONMATCHING
undefined4 FUN_01022114(undefined4 param_1,undefined4 param_2)
{
  if (DAT_00020060 == '\x03') {
    FUN_01021320(STR_01022188,0x21598,param_2);
  }
  else if (DAT_00020060 == '\x01') {
    FUN_01021320(STR_01022188,0x21598,param_2);
  }
  else if (DAT_00020060 == '\0') {
    FUN_01021320(STR_01022190,0x21598,param_2);
  }
  else if (DAT_00020060 == '\x02') {
    FUN_01021320(STR_010221a4,0x21598,param_2);
  }
  else if (DAT_00020060 == '\x04') {
    FUN_01021320(STR_01022188,0x21598,param_2);
  }
  return 0x21598;
}
#endif

/* 010221c0 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_010221c0(int param_1,undefined4 param_2)
{
  if (param_1 == 0) {
    FUN_01021320(_DAT_000206a0,0x21598,param_2);
  }
  else if (DAT_00020060 == '\x03') {
    FUN_01021320(_DAT_000206a0,0x21598,param_2);
  }
  else if (DAT_00020060 == '\x01') {
    FUN_01021320(_DAT_000206a0,0x21598,param_2);
  }
  else if (DAT_00020060 == '\0') {
    FUN_01021320(STR_01022250,0x21598,param_2);
  }
  else if (DAT_00020060 == '\x02') {
    FUN_01021320(STR_01022260,0x21598,param_2);
  }
  else if (DAT_00020060 == '\x04') {
    FUN_01021320(_DAT_000206a0,0x21598,param_2);
  }
  return 0x21598;
}
#endif

/* 01022274 */
#ifdef NONMATCHING
undefined4 FUN_01022274(undefined4 param_1,undefined4 param_2)
{
  undefined4 uVar1;
  undefined1 auStack_1c [12];
  undefined1 local_10;
  
  if (DAT_00020060 == '\0') {
    FUN_01021320(STR_010222e0,0x21598,param_2);
    FUN_0101e050();
    uVar1 = 0x21598;
  }
  else {
    FUN_010230c4(auStack_1c,STR_010222f4,DAT_00020000,DAT_00020001,DAT_00020002,
                 DAT_00020003,DAT_00020004,DAT_00020005);
    local_10 = 0;
    FUN_01021320(auStack_1c,0x21558,param_2);
    FUN_0101e050();
    uVar1 = 0x21558;
  }
  return uVar1;
}
#endif

/* 01022314 */
void FUN_01022314(void)
{
  return;
}

/* 01022318 */
void FUN_01022318(void)
{
  FUN_0102186c(0x210b0);
  return;
}

/* 01022328 */
void FUN_01022328(void)
{
  return;
}

/* 0102232a */
#ifdef NONMATCHING
longlong FUN_0102232a(uint param_1)
{
  return (ulonglong)param_1 << 0x20;
}
#endif

/* 01022330 */
#ifdef NONMATCHING
undefined8 FUN_01022330(int param_1,undefined1 *param_2,undefined4 param_3,undefined4 param_4)
{
  int extraout_r1;
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  uVar1 = 0;
  if (param_2[1] == '\x01') {
    *(int *)(param_2 + 0x18) = *(int *)(param_2 + 0x10) - *(int *)(param_2 + 0x14);
    if (*(int *)(param_2 + 0x18) == 0) {
      if ((*(int *)(param_2 + 0x10) != 0) &&
         (FUN_01018214(*(undefined4 *)(param_2 + 0x10),param_2[7]), extraout_r1 == 0)) {
        FUN_01022488(param_1,param_2);
        *(undefined4 *)(param_2 + 0x10) = 0;
      }
    }
    else if ((uint)(byte)param_2[7] < *(uint *)(param_2 + 0x18)) {
      FUN_01022724(param_1,*(int *)(param_2 + 8) + *(int *)(param_2 + 0x14),0,param_2[7]);
      *(uint *)(param_2 + 0x14) = *(int *)(param_2 + 0x14) + (uint)(byte)param_2[7];
      *(int *)(param_2 + 0x18) = *(int *)(param_2 + 0x10) - *(int *)(param_2 + 0x14);
      FUN_010226dc(param_1,param_2);
    }
    else {
      FUN_01022724(param_1,*(int *)(param_2 + 8) + *(int *)(param_2 + 0x14),0,param_2[0x18]);
      *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(param_2 + 0x10);
      *(undefined4 *)(param_2 + 0x18) = 0;
      FUN_010226dc(param_1,param_2);
    }
  }
  else if (*(int *)(param_2 + 0x10) != 0) {
    FUN_010225f0(param_1,*(int *)(param_2 + 8) + *(int *)(param_2 + 0x14),*param_2,param_2[0x10],0,0
                 ,param_4);
    *(undefined4 *)(param_2 + 0x14) = 0;
    *(int *)(param_2 + 8) = param_1 + 0x47c;
  }
  return CONCAT44(uVar1,uVar2);
}
#endif

/* 0102240c */
#ifdef NONMATCHING
undefined4 FUN_0102240c(int param_1,sbyte *param_2)
{
  byte local_c;
  
  if (param_2[1] == 1) {
    local_c = (byte)(1 << *param_2);
    *(byte *)(*(int *)(param_1 + 0xc) + 1) = *(byte *)(*(int *)(param_1 + 0xc) + 1) & ~local_c;
  }
  else {
    local_c = (byte)(1 << *param_2);
    *(byte *)(*(int *)(param_1 + 0xc) + 1) = *(byte *)(*(int *)(param_1 + 0xc) + 1) & ~local_c;
  }
  return 0;
}
#endif

/* 0102244a */
#ifdef NONMATCHING
undefined4 FUN_0102244a(int param_1,sbyte *param_2)
{
  byte local_10;
  byte local_c;
  
  if (param_2[1] == 1) {
    local_10 = (byte)(1 << *param_2);
    *(byte *)(*(int *)(param_1 + 0xc) + 1) = *(byte *)(*(int *)(param_1 + 0xc) + 1) | local_10;
  }
  else {
    local_c = (byte)(1 << *param_2);
    *(byte *)(*(int *)(param_1 + 0xc) + 1) = *(byte *)(*(int *)(param_1 + 0xc) + 1) | local_c;
  }
  return 0;
}
#endif

/* 01022488 */
#ifdef NONMATCHING
undefined4 FUN_01022488(int param_1,sbyte *param_2)
{
  **(undefined1 **)(param_1 + 0x10) = (char)(0x10 << *param_2);
  return 0;
}
#endif

/* 0102249c */
#ifdef NONMATCHING
undefined4 FUN_0102249c(int param_1,char *param_2)
{
  if (*param_2 == '\0') {
    *(undefined1 *)(*(int *)(param_1 + 0x10) + 1) = 1;
    FUN_01022488(param_1,param_2);
  }
  return 0;
}
#endif

/* 010224bc */
#ifdef NONMATCHING
undefined4 FUN_010224bc(int param_1,byte *param_2)
{
  byte bVar1;
  
  if (param_2[1] == 1) {
    if ((*(char *)(param_1 + 3) == '\0') || (*param_2 != 1)) {
      *(int *)(param_2 + 0x18) = *(int *)(param_2 + 0x10) - *(int *)(param_2 + 0x14);
      if (*(uint *)(param_2 + 0x18) == (uint)param_2[7]) {
        FUN_01022724(param_1,*(int *)(param_2 + 8) + *(int *)(param_2 + 0x14),*param_2,param_2[7]);
        *(uint *)(param_2 + 0x14) = *(int *)(param_2 + 0x14) + (uint)param_2[7];
        FUN_010226dc(param_1,param_2);
        *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(param_2 + 0x10);
        param_2[0x18] = 0;
        param_2[0x19] = 0;
        param_2[0x1a] = 0;
        param_2[0x1b] = 0;
        *(undefined1 *)(param_1 + 0x4a4) = 1;
      }
      else if (*(int *)(param_2 + 0x18) == 0) {
        FUN_01022724(param_1,*(int *)(param_2 + 8) + *(int *)(param_2 + 0x14),*param_2,0);
        *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(param_2 + 0x10);
        param_2[0x18] = 0;
        param_2[0x19] = 0;
        param_2[0x1a] = 0;
        param_2[0x1b] = 0;
      }
      else if ((uint)param_2[7] < *(uint *)(param_2 + 0x18)) {
        FUN_01022724(param_1,*(int *)(param_2 + 8) + *(int *)(param_2 + 0x14),*param_2,param_2[7]);
        FUN_010226dc(param_1,param_2);
        *(uint *)(param_2 + 0x14) = *(int *)(param_2 + 0x14) + (uint)param_2[7];
        if (*(uint *)(param_2 + 0x10) < *(uint *)(param_2 + 0x14)) {
          param_2[0x18] = 0;
          param_2[0x19] = 0;
          param_2[0x1a] = 0;
          param_2[0x1b] = 0;
          *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(param_2 + 0x10);
        }
        else {
          *(int *)(param_2 + 0x18) = *(int *)(param_2 + 0x10) - *(int *)(param_2 + 0x14);
        }
      }
      else {
        FUN_01022724(param_1,*(int *)(param_2 + 8) + *(int *)(param_2 + 0x14),*param_2,param_2[0x18]
                    );
        FUN_010226dc(param_1,param_2);
        *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(param_2 + 0x10);
        param_2[0x18] = 0;
        param_2[0x19] = 0;
        param_2[0x1a] = 0;
        param_2[0x1b] = 0;
      }
    }
  }
  else {
    bVar1 = **(byte **)(param_1 + 0x24 + (uint)*param_2 * 4);
    FUN_010225f0(param_1,*(int *)(param_2 + 8) + *(int *)(param_2 + 0x14),*param_2,(uint)bVar1);
    *(uint *)(param_2 + 0x14) = *(int *)(param_2 + 0x14) + (uint)bVar1;
    DAT_00020131 = bVar1;
    if (*(uint *)(param_2 + 0x14) < *(uint *)(param_2 + 0x10)) {
      param_2[0x18] = 0;
      param_2[0x19] = 0;
      param_2[0x1a] = 0;
      param_2[0x1b] = 0;
      *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(param_2 + 0x14);
    }
    else {
      *(int *)(param_2 + 0x18) = *(int *)(param_2 + 0x14) - *(int *)(param_2 + 0x10);
    }
  }
  return 0;
}
#endif

/* 010225f0 */
#ifdef NONMATCHING
void FUN_010225f0(undefined4 param_1,undefined1 *param_2,int param_3,int param_4)
{
  uint uVar1;
  
  for (uVar1 = 0; (int)uVar1 < param_4; uVar1 = uVar1 + 1 & 0xff) {
    *param_2 = (&DAT_000f6018)[param_3];
    param_2 = param_2 + 1;
  }
  return;
}
#endif

/* 01022614 */
#ifdef NONMATCHING
undefined4 FUN_01022614(undefined1 *param_1,int param_2)
{
  uint uVar1;
  
  param_1[3] = 0;
  param_1[2] = 1;
  *(undefined2 *)(param_1 + 4) = 0x40;
  if (param_2 == 1) {
    param_1[0xb] = 1;
    param_1[1] = 4;
    *(undefined2 *)(param_1 + 6) = 0x40;
    param_1[8] = 2;
  }
  else if (param_2 == 0) {
    param_1[0xb] = 0;
    *param_1 = 8;
    param_1[1] = 4;
    *(undefined2 *)(param_1 + 6) = 0x200;
  }
  *(undefined1 **)(param_1 + 0xc) = &DAT_000f6000;
  *(undefined1 **)(param_1 + 0x10) = &DAT_000f6010;
  for (uVar1 = 0; uVar1 < 4; uVar1 = uVar1 + 1) {
    *(undefined1 **)(param_1 + uVar1 * 4 + 0x14) = &DAT_000f6018 + uVar1;
  }
  for (uVar1 = 0; uVar1 < 4; uVar1 = uVar1 + 1) {
    *(uint *)(param_1 + uVar1 * 4 + 0x24) = uVar1 + 0xf6020;
  }
  *(undefined4 *)(param_1 + 0x34) = 0xf6025;
  return 0;
}
#endif

/* 010226a4 */
#ifdef NONMATCHING
undefined4 FUN_010226a4(int param_1,int param_2)
{
  if ((param_2 != 1) && (param_2 == 0)) {
    *(int *)(param_1 + 0x268) = param_1 + 0x47c;
    *(undefined4 *)(param_1 + 0x270) = 8;
  }
  rom_delay_b(0x32);
  return 0;
}
#endif

/* 010226dc */
#ifdef NONMATCHING
/* WARNING: Removing unreachable block (ram,0x010226fa) */

undefined4 FUN_010226dc(undefined4 param_1,sbyte *param_2)
{
  DAT_000f6026 = 0x40;
  DAT_000f6027 = (char)(1 << *param_2);
  DAT_000f6010 = (char)(1 << *param_2);
  return 0;
}
#endif

/* 01022724 */
#ifdef NONMATCHING
undefined4 FUN_01022724(int param_1,undefined1 *param_2,int param_3,int param_4)
{
  uint uVar1;
  
  uVar1 = 0;
  if (*(char *)(param_1 + 3) == '\0') {
    for (; (int)uVar1 < param_4; uVar1 = uVar1 + 1 & 0xff) {
      **(undefined1 **)(param_1 + 0x14 + param_3 * 4) = *param_2;
      param_2 = param_2 + 1;
    }
  }
  return 0;
}
#endif

/* 01022754 */
#ifdef NONMATCHING
void FUN_01022754(void)
{
  FUN_01024b14(0);
  DAT_00020181 = 1;
  return;
}
#endif

/* 01022768 */
#ifdef NONMATCHING
/* WARNING: Removing unreachable block (ram,0x010227be) */
/* WARNING: Removing unreachable block (ram,0x010227cc) */
/* WARNING: Removing unreachable block (ram,0x010227c2) */

void FUN_01022768(void)
{
  undefined1 auStack_5c [64];
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined1 local_19;
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined1 local_11;
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_e;
  
  local_14 = 0x20;
  FUN_0101c294(&local_1c);
  local_13 = local_17;
  local_12 = local_18;
  local_11 = local_19;
  local_10 = local_1a;
  local_f = local_1b;
  local_e = local_1c;
  FUN_01024ea2(&local_14,7,&DAT_00009018);
  memzero(auStack_5c,0x40);
  memcpy(auStack_5c,&local_14,9);
  FUN_01024b54(auStack_5c,9);
  return;
}
#endif

/* 010227dc */
#ifdef NONMATCHING
undefined8 FUN_010227dc(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  local_18 = param_1;
  uStack_14 = param_2;
  uStack_10 = param_3;
  uStack_c = param_4;
  FUN_010241fa(0x1017040,&uStack_c,4);
  local_18 = CONCAT31(local_18._1_3_,0x22);
  memcpy((int)&local_18 + 1,&uStack_c,4);
  FUN_01024ea2(&local_18,5,&DAT_00009018);
  FUN_01024ea2(&local_18,7,0x3f);
  FUN_0101c034(&local_18,9);
  return CONCAT44(uStack_14,local_18);
}
#endif

/* 01022820 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_01022820(void)
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_0101ef2c();
  if ((iVar1 == 0) || ((_DAT_00021880 & _DAT_0002186c) == 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}
#endif
