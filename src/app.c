/* app.c: guessed: application helpers before main */

#include "zero2.h"

/* 01024798 */
void FUN_01024798(void)
{
  return;
}

/* 0102479c */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0102479c(int param_1)
{
  if (DAT_00022060 == '\0') {
    FUN_010247c4();
    _DAT_00022054 = 0x10248e1;
    FUN_010249ce(0x2204c,param_1 + -1);
  }
  return;
}
#endif

/* 010247c4 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_010247c4(void)
{
  DAT_000206b0 = 1;
  led_set(7,0);
  _DAT_000206b8 = 0x1024585;
  return;
}
#endif

/* 01024838 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01024838(void)
{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = 10;
  iVar2 = usb_powered();
  if ((((iVar2 != 0) || (DAT_00020182 == '\x02')) || (iVar2 = usb_charging(), iVar2 != 0)) ||
     ((iVar2 = FUN_0101eefc(), iVar2 != 0 || (_DAT_00020620 < 5)))) {
    return;
  }
  while (uVar1 != 0) {
    led_set(7,0);
    uVar3 = FUN_0101fb08();
    if ((uVar3 & 0x20000) != 0) {
      restart();
    }
    iVar2 = FUN_0101f0bc();
    if (iVar2 == 0) {
      if (uVar1 != 0) {
        uVar1 = uVar1 - 1;
      }
    }
    else if (uVar1 < 100) {
      uVar1 = uVar1 + 1;
    }
    rom_delay_a(10);
  }
  do {
    GPIO_ResetBits(2,4);
    led_set(7,0);
    uVar3 = FUN_0101fb08();
    if ((uVar3 & 0x20000) != 0) {
      restart();
    }
    rom_delay_a(10);
  } while( true );
}
#endif

/* 01024900 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01024900(void)
{
  _DAT_000206b8 = 0x1024799;
  return;
}
#endif

/* 01024910 */
#ifdef NONMATCHING
void FUN_01024910(void)
{
  if (DAT_00022030 != '\0') {
    FUN_01024090(0x2201c);
    FUN_010247c4();
  }
  return;
}
#endif

/* 0102492c */
#ifdef NONMATCHING
void FUN_0102492c(undefined4 param_1)
{
  if ((DAT_000206d0 & 1) == 0) {
    led_set(1);
  }
  else {
    led_set(1,0);
  }
  if (DAT_000206d0 != 0) {
    DAT_000206d0 = DAT_000206d0 - 1;
  }
  if (DAT_000206d0 == 0) {
    FUN_010247c4();
    FUN_01024910();
  }
  else {
    FUN_010249ce(param_1,0x95);
  }
  return;
}
#endif

/* 01024980 */
#ifdef NONMATCHING
char FUN_01024980(void)
{
  DAT_00020716 = DAT_00020716 + '\x02';
  return DAT_00020716;
}
#endif

/* 01024994 */
#ifdef NONMATCHING
char FUN_01024994(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  undefined4 local_10;
  undefined4 local_c;
  
  local_10 = param_3;
  local_c = param_4;
  FUN_010206ca(&local_10,0);
  return (char)local_10 + local_10._1_1_ + local_10._2_1_ + local_10._3_1_ + (char)local_c +
         local_c._1_1_;
}
#endif

/* 010249c2 */
void FUN_010249c2(void)
{
  return;
}

/* 010249c4 */
void FUN_010249c4(void)
{
  FUN_0102479c(10);
  return;
}

/* 010249ce */
#ifdef NONMATCHING
void FUN_010249ce(int param_1,undefined4 param_2)
{
  FUN_010240ac(param_1,param_2);
  FUN_01023d5c(param_1);
  *(undefined4 *)(param_1 + 0x10) = param_2;
  return;
}
#endif

/* 010249ee */
#ifdef NONMATCHING
void FUN_010249ee(int param_1)
{
  set_vis(param_1 != 0,param_1 != 0,0);
  return;
}
#endif

/* 01024a08 */
#ifdef NONMATCHING
void FUN_01024a08(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  int iVar1;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  
  iVar1 = (uint)DAT_000201b4 * 0x1c;
  uStack_20 = param_2;
  uStack_1c = param_3;
  uStack_18 = param_4;
  FUN_0101c294(&uStack_20);
  memcpy(iVar1 + 0x21ed4,&uStack_20,6);
  FUN_01023aea(iVar1 + 0x21eda,param_1);
  memcpy(iVar1 + 0x21ee0,param_2,0x10);
  DAT_00020659 = 1;
  return;
}
#endif

/* 01024a54 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 FUN_01024a54(int param_1)
{
  undefined2 uVar1;
  
  if (param_1 == 2) {
    uVar1 = _DAT_00020588;
  }
  else if (param_1 == 3) {
    uVar1 = _DAT_0002058a;
  }
  else {
    uVar1 = 0xffff;
  }
  return uVar1;
}
#endif

/* 01024a7c */
#ifdef NONMATCHING
void FUN_01024a7c(void)
{
  bool bVar1;
  
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    isIRQinterruptsEnabled();
  }
  return;
}
#endif

/* 01024a84 */
#ifdef NONMATCHING
void FUN_01024a84(undefined4 param_1,undefined2 param_2,undefined1 param_3,undefined4 param_4)
{
  undefined2 local_18;
  undefined1 local_16;
  undefined1 uStack_15;
  
  uStack_15 = (undefined1)((uint)param_4 >> 0x18);
  _local_18 = CONCAT12(param_3,param_2);
  GPIO_Init(param_1,&local_18);
  return;
}
#endif

/* 01024a9c */
#ifdef NONMATCHING
void FUN_01024a9c(undefined4 param_1,undefined2 param_2)
{
  FUN_01020f8a(0x210b0,param_1,param_2);
  return;
}
#endif

/* 01024ab4 */
#ifdef NONMATCHING
bool FUN_01024ab4(void)
{
  bool bVar1;
  
  bVar1 = DAT_00020130 == '\x01';
  if (bVar1) {
    DAT_00020130 = '\0';
  }
  return bVar1;
}
#endif

/* 01024ad0 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01024ad0(void)
{
  DAT_000f6012 = 0x40;
  DAT_000f6029 = 0;
  DAT_000f602a = 0;
  DAT_000f6000 = 0;
  _DAT_e000e180 = 1;
  _DAT_000f856c = _DAT_000f856c | 0x40;
  return;
}
#endif

/* 01024b14 */
#ifdef NONMATCHING
void FUN_01024b14(int param_1)
{
  if (param_1 == 0) {
    FUN_010259e8();
  }
  return;
}
#endif

/* 01024b28 */
#ifdef NONMATCHING
uint FUN_01024b28(undefined4 param_1,int param_2)
{
  uint uVar1;
  
  if (param_2 < 0x41) {
    memcpy(param_1,0x21618,DAT_00020131);
    uVar1 = (uint)DAT_00020131;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}
#endif

/* 01024b54 */
#ifdef NONMATCHING
/* WARNING: Removing unreachable block (ram,0x01024b88) */

uint FUN_01024b54(undefined1 *param_1,uint param_2)
{
  uint uVar1;
  
  for (uVar1 = 0; uVar1 < param_2; uVar1 = uVar1 + 1) {
    DAT_000f6019 = *param_1;
    param_1 = param_1 + 1;
  }
  DAT_000f6026 = 0x40;
  DAT_000f6027 = 2;
  DAT_000f6010 = 2;
  DAT_000201ea = 0;
  return param_2;
}
#endif

/* 01024bb8 */
void FUN_01024bb8(void)
{
  return;
}

/* 01024bba */
void FUN_01024bba(void)
{
  return;
}

/* 01024bbc */
void FUN_01024bbc(void)
{
  return;
}

/* 01024bc0 */
#ifdef NONMATCHING
undefined1 FUN_01024bc0(void)
{
  return DAT_0002058d;
}
#endif

/* 01024bcc */
void FUN_01024bcc(void)
{
  return;
}

/* 01024bd0 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01024bd0(int param_1)
{
  if (param_1 == 0) {
    _DAT_000205f4 = 0x10241c5;
  }
  else {
    _DAT_000205f4 = param_1;
  }
  return;
}
#endif

/* 01024bec */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01024bec(uint param_1)
{
  if (((int)param_1 < (int)(uint)_DAT_00021922) && ((int)param_1 < 5)) {
    if (5 < _DAT_00021922) {
      _DAT_00021922 = 5;
    }
    for (; (int)(param_1 + 1) < (int)(uint)_DAT_00021922; param_1 = param_1 + 1 & 0xff) {
      memcpy(param_1 * 0x18 + 0x21930,(param_1 + 1) * 0x18 + 0x21930,0x18);
    }
    memzero(param_1 * 0x18 + 0x21930,0x18);
    _DAT_00021922 = _DAT_00021922 - 1;
    DAT_000201e8 = 1;
  }
  return;
}
#endif

/* 01024c60 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_01024c60(uint param_1)
{
  uint uVar1;
  int extraout_r3;
  
  uVar1 = 0;
  while( true ) {
    if (_DAT_00021922 <= uVar1) {
      return 0;
    }
    if (*(ushort *)(uVar1 * 0x18 + 0x21946) == param_1) break;
    if (5 < uVar1) {
      return 0;
    }
    uVar1 = uVar1 + 1 & 0xff;
  }
  FUN_01025008(uVar1 * 0x18 + 0x21930);
  return extraout_r3 * 0x18 + 0x21930;
}
#endif

/* 01024cac */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_01024cac(uint param_1)
{
  uint uVar1;
  
  uVar1 = 0;
  while( true ) {
    if (_DAT_00021922 <= uVar1) {
      return 0x7f;
    }
    if (*(ushort *)(uVar1 * 0x18 + 0x21946) == param_1) break;
    if (5 < uVar1) {
      return 0x7f;
    }
    uVar1 = uVar1 + 1 & 0xff;
  }
  return uVar1;
}
#endif

/* 01024ce4 */
#ifdef NONMATCHING
void FUN_01024ce4(void)
{
  int iVar1;
  
  iVar1 = FUN_0101b61c();
  if (iVar1 != 0) {
    thunk_FUN_0101b23c(0x2000);
    iVar1 = FUN_0101b61c();
    if (iVar1 != 0) {
      DAT_000201b9 = 1;
    }
  }
  return;
}
#endif

/* 01024d0c */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01024d0c(int param_1)
{
  int iVar1;
  
  if (param_1 == 0) {
    FUN_0101c8ac();
  }
  else if (param_1 == 1) {
    iVar1 = FUN_0101a910();
    if (iVar1 == 0) {
      if (_DAT_0002fff0 == 0x55667788) {
        _DAT_0002fff0 = 0;
        DAT_000201b8 = 1;
        FUN_0101b5a0(0);
      }
      else if (DAT_00020182 != '\x02') {
        Create_BtConnection();
      }
    }
    else {
      _DAT_0002fff0 = 0;
      FUN_0101b5d8();
    }
  }
  return;
}
#endif

/* 01024d78 */
void FUN_01024d78(void)
{
  return;
}

/* 01024d7c */
#ifdef NONMATCHING
void FUN_01024d7c(void)
{
  int iVar1;
  
  iVar1 = (uint)DAT_000201b4 * 0x1c;
  if ((((*(char *)(iVar1 + 0x21edf) == -0x1c) && (*(char *)(iVar1 + 0x21ede) == '\x17')) &&
      (*(char *)(iVar1 + 0x21edd) == -0x28)) ||
     (iVar1 = FUN_010182b0(iVar1 + 0x21eda,&DAT_0102823e,6), iVar1 == 0)) {
    DAT_00020658 = 1;
    FUN_01024de0();
  }
  return;
}
#endif

/* 01024dc8 */
#ifdef NONMATCHING
void FUN_01024dc8(undefined4 param_1,undefined4 param_2)
{
  undefined4 uVar1;
  
  uVar1 = FUN_01024a54(2);
  FUN_01024e8c(uVar1,param_1,param_2);
  return;
}
#endif

/* 01024de0 */
#ifdef NONMATCHING
void FUN_01024de0(void)
{
  undefined1 uVar1;
  undefined4 in_r3;
  undefined4 local_10;
  undefined1 uStack_c;
  undefined3 uStack_b;
  
  local_10 = 0x3203dda5;
  _uStack_c = CONCAT31((int3)((uint)in_r3 >> 8),0x30);
  uVar1 = FUN_0101aa28();
  _uStack_c = CONCAT11(uVar1,uStack_c);
  FUN_01024dc8(&local_10,6);
  return;
}
#endif

/* 01024e8c */
#ifdef NONMATCHING
undefined4 FUN_01024e8c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  send_b0(param_2,param_3,param_3,param_4,param_4);
  return 0;
}
#endif

/* 01024ea2 */
#ifdef NONMATCHING
void FUN_01024ea2(int param_1,int param_2,undefined4 param_3)
{
  *(char *)(param_1 + param_2) = (char)param_3;
  *(char *)(param_1 + (param_2 + 1U & 0xffff)) = (char)((uint)param_3 >> 8);
  return;
}
#endif

/* 01024eb8 */
#ifdef NONMATCHING
uint FUN_01024eb8(int param_1)
{
  uint uVar1;
  
  if ((param_1 == 2) || (param_1 == 3)) {
    uVar1 = FUN_00004d24(param_1);
    uVar1 = uVar1 >> 2;
  }
  else {
    uVar1 = FUN_00004d24(param_1);
  }
  return uVar1;
}
#endif

/* 01024edc */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01024edc(uint param_1,undefined4 param_2)
{
  _DAT_000f856c = _DAT_000f856c & 0xffffdfff;
  DAT_000c804c = (undefined1)param_2;
  rom_delay_b(1);
  DAT_000c804d = (undefined1)((uint)param_2 >> 8);
  rom_delay_b(1);
  DAT_000c804e = (undefined1)((uint)param_2 >> 0x10);
  rom_delay_b(1);
  DAT_000c804f = (undefined1)((uint)param_2 >> 0x18);
  rom_delay_b(1);
  DAT_000c8005 = (undefined1)(1 << (param_1 & 0xff));
  rom_delay_a(1);
  return;
}
#endif
