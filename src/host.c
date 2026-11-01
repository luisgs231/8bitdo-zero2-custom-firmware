/* host.c: guessed: the host link keys and reconnects, the LED pins */

#include "zero2.h"

/* 01022ea0 */
#ifdef NONMATCHING
void switch_link_key(undefined1 *param_1,undefined4 param_2)
{
  undefined1 auStack_3c [8];
  undefined1 local_34;
  undefined1 local_33;
  undefined1 local_32;
  undefined1 local_31;
  undefined1 local_30;
  undefined1 local_2f;
  undefined1 local_2e;
  undefined1 local_2d;
  undefined1 auStack_2c [12];
  undefined1 auStack_20 [16];
  
  log_empty(STR_01022f14);
  FUN_01025008(param_1);
  log_empty(0x1022f2c);
  memzero(&local_34,0x24);
  local_34 = 0xc0;
  local_33 = 0x12;
  local_32 = *param_1;
  local_31 = param_1[1];
  local_30 = param_1[2];
  local_2f = param_1[3];
  local_2e = param_1[4];
  local_2d = param_1[5];
  FUN_01023aea(auStack_3c,param_1);
  FUN_0101abe0(auStack_2c,auStack_3c);
  memcpy(auStack_20,param_2,0x10);
  Enable_WakeupNs(&local_34,0x24);
  log_empty(STR_01022f34);
  return;
}
#endif

/* 01022f2a */
#ifdef NONMATCHING
void FUN_01022f2a(undefined4 param_1,uint param_2,int param_3,int param_4)
{
  undefined4 unaff_r4;
  int unaff_r6;
  undefined4 unaff_r7;
  
  *(undefined4 *)(param_3 + 0x14) = unaff_r7;
  *(int *)((param_2 >> 8) + 0x54) = param_4;
  *(char *)(param_3 + 1) = (char)(param_2 >> 8);
  *(short *)(param_4 + (param_2 >> 8)) = (short)unaff_r7;
  *(undefined4 *)(unaff_r6 + 0x34) = unaff_r4;
  memcpy(0x219ac,&DAT_0102969d,0x30);
  FUN_010202a0(0x3a,0x24,param_2);
  FUN_01020354(0x10000000);
  return;
}
#endif

/* 01022f48 */
#ifdef NONMATCHING
void FUN_01022f48(undefined4 param_1,undefined4 param_2)
{
  memcpy(0x219ac,&DAT_0102969d,0x30);
  FUN_010202a0(param_1,0x24,param_2);
  FUN_01020354(0x10000000);
  return;
}
#endif

/* 01022f74 */
#ifdef NONMATCHING
undefined4 FUN_01022f74(int param_1)
{
  if ((*(char *)(param_1 + 3) == '\x01') && (*(char *)(param_1 + 4) == '\0')) {
    DAT_00020786 = 1;
  }
  else if ((*(char *)(param_1 + 3) == '\0') && (*(char *)(param_1 + 4) == '\x01')) {
    if (DAT_00020786 == '\x01') {
      DAT_00020786 = 2;
    }
    else {
      DAT_00020786 = 0;
    }
  }
  else if ((*(char *)(param_1 + 3) == '\x01') && (*(char *)(param_1 + 4) == '\x01')) {
    if (DAT_00020786 == '\x02') {
      DAT_00020786 = 3;
    }
    else {
      DAT_00020786 = 0;
    }
  }
  else if (*(char *)(param_1 + 3) == '\x05') {
    if (DAT_00020786 == '\x03') {
      FUN_0101a7b8(*(undefined1 *)(param_1 + 4));
      return 1;
    }
    DAT_00020786 = 0;
  }
  else {
    DAT_00020786 = 0;
  }
  return 0;
}
#endif

/* 01023004 */
#ifdef NONMATCHING
void xinput_host_data(char *param_1,undefined4 param_2,int param_3)
{
  int iVar1;
  int iVar2;
  
  if (param_3 == 1) {
    if (*param_1 == '\x01') {
      if (param_1[1] == '\x03') {
        FUN_01020464(param_1[2]);
      }
    }
    else if (((*param_1 == '\0') && (param_1[1] == '\b')) &&
            (iVar1 = FUN_01022f74(param_1,param_2), iVar1 == 0)) {
      FUN_010200bc((int)(uint)(byte)param_1[3] >> 1,(int)(uint)(byte)param_1[4] >> 1,0x2d,3);
    }
  }
  else if ((param_3 == 2) && (param_1[1] == '\x03')) {
    if ((uint)(byte)param_1[5] * 4 < 0x100) {
      iVar1 = ((byte)param_1[5] & 0x3f) << 2;
    }
    else {
      iVar1 = 0xff;
    }
    if ((uint)(byte)param_1[6] * 4 < 0x100) {
      iVar2 = ((byte)param_1[6] & 0x3f) << 2;
    }
    else {
      iVar2 = 0xff;
    }
    if ((param_1[5] == '\x01') && (param_1[6] == '\0')) {
      iVar1 = 0;
      iVar2 = 0;
    }
    FUN_010200bc(iVar1,iVar2,0x2d,3);
  }
  return;
}
#endif

/* 010230a4 */
#ifdef NONMATCHING
void FUN_010230a4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  FUN_010234c8(param_1,&uStack_c,0x20788,0x10249c3);
  return;
}
#endif

/* 010230c4 */
#ifdef NONMATCHING
undefined4 FUN_010230c4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  undefined4 uVar1;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_10 = param_1;
  uStack_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  uVar1 = FUN_010234c8(param_2,&uStack_8,&uStack_10,0x1023a51);
  FUN_01023a50(0,&uStack_10);
  return uVar1;
}
#endif

/* 010230c6 */
#ifdef NONMATCHING
undefined4 FUN_010230c6(void)
{
  undefined4 uVar1;
  undefined1 uStack00000000;
  undefined4 in_stack_00000004;
  undefined1 uStack00000008;
  
  uVar1 = FUN_010234c8(in_stack_00000004,&uStack00000008,&uStack00000000,0x1023a51);
  FUN_01023a50(0,&uStack00000000);
  return uVar1;
}
#endif

/* 010230ec */
#ifdef NONMATCHING
void yc_switch8(void)
{
  uint in_r3;
  uint uVar1;
  int unaff_lr;
  
  uVar1 = (uint)*(byte *)(unaff_lr + -1);
  if (in_r3 < *(byte *)(unaff_lr + -1)) {
    uVar1 = in_r3;
  }
                    /* WARNING: Could not recover jumptable at 0x01023102. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(unaff_lr + (uint)*(byte *)(unaff_lr + uVar1) * 2))();
  return;
}
#endif

/* 01023108 */
#ifdef NONMATCHING
int FUN_01023108(undefined4 param_1,int param_2)
{
  if (param_2 != 9) {
    FUN_010230a4(STR_01023130,param_2);
  }
  FUN_0101aea4(0x210b0,0x81,param_1,param_2);
  DAT_000201ea = 0;
  return param_2;
}
#endif

/* 01023148 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Reconnect_Host(void)
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_2c [6];
  undefined2 local_26;
  undefined1 auStack_24 [16];
  
  if (DAT_000201b8 == '\0') {
    if (DAT_00020650 == '\0') {
      if (_DAT_00020654 == 0) {
        _DAT_00020654 = _DAT_00020008;
      }
      else if (&DAT_0000ea60 < (undefined *)(_DAT_00020008 - _DAT_00020654)) {
        _DAT_00020654 = 0;
        DAT_000201dc = 0;
        iVar2 = link_byte();
        if (iVar2 != 2) {
          FUN_01024d0c(0);
        }
      }
      iVar2 = (uint)DAT_000201b4 * 0x1c;
      iVar3 = FUN_010182b0(iVar2 + 0x21eda,&DAT_0102823e,6);
      if ((iVar3 == 0) || (iVar3 = FUN_010182b0(iVar2 + 0x21eda,&DAT_01028244,6), iVar3 == 0)) {
        uVar1 = 0;
      }
      else {
        memcpy(auStack_2c,iVar2 + 0x21eda,6);
        memcpy(auStack_24,iVar2 + 0x21ee0,0x10);
        local_26 = 0x12c0;
        DAT_00020650 = DAT_00020650 + '\x01';
        FUN_01018bc8(auStack_2c,0x18);
        FUN_0101fb2c();
        if (((*(char *)(iVar2 + 0x21edf) == -0x1c) && (*(char *)(iVar2 + 0x21ede) == '\x17')) &&
           (*(char *)(iVar2 + 0x21edd) == -0x28)) {
          DAT_00020658 = 1;
          memzero(iVar2 + 0x21ed4,0x1c);
          log_empty(STR_01023270);
        }
        else {
          DAT_00020658 = 0;
        }
        uVar1 = 1;
      }
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    set_vis(0,1);
    uVar1 = 0;
  }
  return uVar1;
}
#endif

/* 01023290 */
void restart(void)
{
  FUN_01023b04();
  FUN_0101e01c();
  FUN_0101b4ac();
  FUN_0101b242(5);
  FUN_01020b8c();
  FUN_010180b4();
  return;
}

/* 010232b0 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_010232b0(void)
{
  _DAT_00020198 = 0;
  return;
}
#endif

/* 010232bc */
#ifdef NONMATCHING
void led_set(uint param_1,uint param_2)
{
  if ((param_1 & 1) != 0) {
    if ((param_2 & 1) == 0) {
      GPIO_ResetBits(0,8);
    }
    else {
      GPIO_SetBits(0,8);
    }
  }
  if ((param_1 & 2) != 0) {
    if ((param_2 & 2) == 0) {
      GPIO_ResetBits(0,4);
    }
    else {
      GPIO_SetBits(0,4);
    }
  }
  if ((param_1 & 4) != 0) {
    if ((param_2 & 4) == 0) {
      GPIO_ResetBits(2,8);
    }
    else {
      GPIO_SetBits(2,8);
    }
  }
  return;
}
#endif

/* 0102332a */
void FUN_0102332a(void)
{
  return;
}

/* 0102332c */
void FUN_0102332c(void)
{
  return;
}

/* 0102332e */
void FUN_0102332e(void)
{
  return;
}

/* 01023330 */
void FUN_01023330(void)
{
  return;
}

/* 01023332 */
#ifdef NONMATCHING
void thunk_FUN_0102333a(undefined4 *param_1,undefined4 *param_2,int param_3)
{
  undefined4 uVar1;
  
  for (; param_3 != 0; param_3 = param_3 + -4) {
    uVar1 = *param_1;
    param_1 = param_1 + 1;
    *param_2 = uVar1;
    param_2 = param_2 + 1;
  }
  return;
}
#endif

/* 0102333a */
#ifdef NONMATCHING
void FUN_0102333a(undefined4 *param_1,undefined4 *param_2,int param_3)
{
  undefined4 uVar1;
  
  for (; param_3 != 0; param_3 = param_3 + -4) {
    uVar1 = *param_1;
    param_1 = param_1 + 1;
    *param_2 = uVar1;
    param_2 = param_2 + 1;
  }
  return;
}
#endif

/* 01023340 */
void FUN_01023340(void)
{
  return;
}

/* 01023342 */
#ifdef NONMATCHING
void FUN_01023342(undefined4 param_1,undefined4 *param_2,int param_3)
{
  for (; param_3 != 0; param_3 = param_3 + -4) {
    *param_2 = 0;
    param_2 = param_2 + 1;
  }
  return;
}
#endif

/* 01023350 */
#ifdef NONMATCHING
void assert_failed(void)
{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}
#endif

/* 01023352 */
void sdk_assert(void)
{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

/* 01023354 */
#ifdef NONMATCHING
void FUN_01023354(int param_1,undefined4 param_2,int param_3,undefined4 param_4,uint param_5)
{
  *(undefined4 *)(&DAT_000f8800 + param_1 * 0x100) = param_2;
  *(undefined4 *)(&DAT_000f8804 + param_1 * 0x100) = param_4;
  *(uint *)(&DAT_000f8808 + param_1 * 0x100) = param_3 << 0x10 | param_5;
  (&DAT_000f880f)[param_1 * 0x100] = 0x80;
  return;
}
#endif

/* 01023380 */
#ifdef NONMATCHING
void FUN_01023380(int param_1)
{
  do {
  } while ((*(uint *)(&DAT_000f8810 + param_1 * 0x100) & 1) == 0);
  return;
}
#endif
