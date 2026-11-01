/* hid_device.c: guessed: IPC sends, reports and the Switch protocol */

#include "zero2.h"

/* 010202c8 */
#ifdef NONMATCHING
bool ipc_send(undefined1 *param_1)
{
  bool bVar1;
  int iVar2;
  
  iVar2 = FUN_0101ed1c();
  bVar1 = (int)(*(ushort *)(param_1 + 2) + 3) <= iVar2;
  if (bVar1) {
    *param_1 = 1;
    ipc_queue_write(param_1);
  }
  return bVar1;
}
#endif

/* 010202f2 */
#ifdef NONMATCHING
void send_battery_report(undefined1 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4
                        )
{
  undefined4 uVar1;
  undefined2 local_10;
  undefined1 local_e;
  undefined1 uStack_d;
  
  uStack_d = (undefined1)((uint)param_4 >> 0x18);
  _local_10 = CONCAT12(param_1,0x4a1);
  uVar1 = FUN_01024a54(2);
  FUN_01024e8c(uVar1,&local_10,3);
  return;
}
#endif

/* 01020316 */
#ifdef NONMATCHING
bool ipc_send_long(undefined1 *param_1)
{
  bool bVar1;
  ushort uVar2;
  int iVar3;
  
  uVar2 = *(ushort *)(param_1 + 2);
  iVar3 = FUN_0101ed1c();
  bVar1 = (int)(uVar2 + 4) <= iVar3;
  if (bVar1) {
    *param_1 = 1;
    FUN_0101ec38(param_1);
  }
  return bVar1;
}
#endif

/* 01020340 */
void FUN_01020340(void)
{
  return;
}

/* 01020344 */
#ifdef NONMATCHING
void FUN_01020344(undefined1 param_1)
{
  DAT_000201a8 = param_1;
  return;
}
#endif

/* 01020350 */
void FUN_01020350(void)
{
  return;
}

/* 01020352 */
void FUN_01020352(void)
{
  return;
}

/* 01020354 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01020354(uint param_1)
{
  _DAT_000201bc = _DAT_000201bc | param_1;
  return;
}
#endif

/* 01020364 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01020364(void)
{
  _DAT_0002fff4 = 0x20210624;
  return;
}
#endif

/* 01020374 */
#ifdef NONMATCHING
void FUN_01020374(void)
{
  uint uVar1;
  
  FUN_01020354(0x1000000);
  uVar1 = poll_flags();
  if ((uVar1 & 0x40000000) == 0) {
    FUN_01020350(2);
  }
  else {
    FUN_0101a9e0(0x40000000);
  }
  FUN_0102055c();
  if (DAT_000201b4 == '\0') {
    FUN_0102059c();
  }
  return;
}
#endif

/* 010203b0 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_010203b0(void)
{
  _DAT_0002fff0 = 0x87654321;
  return;
}
#endif

/* 010203c0 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_010203c0(void)
{
  _DAT_0002fff0 = 0x12345678;
  return;
}
#endif

/* 010203d0 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_010203d0(uint param_1)
{
  _DAT_00020140 = _DAT_00020140 | param_1;
  return;
}
#endif

/* 010203e0 */
#ifdef NONMATCHING
void FUN_010203e0(undefined4 param_1,undefined4 param_2)
{
  FUN_01018940(param_1,param_2);
  return;
}
#endif

/* 010203f0 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_010203f0(uint param_1)
{
  _DAT_00020708 = _DAT_00020708 | param_1;
  return;
}
#endif

/* 01020400 */
#ifdef NONMATCHING
void FUN_01020400(byte param_1,int param_2)
{
  if (param_2 == 0) {
    DAT_00020784 = 0x41;
  }
  else {
    DAT_00020784 = param_1 | 0x80;
  }
  return;
}
#endif

/* 0102041c */
#ifdef NONMATCHING
void FUN_0102041c(void)
{
  FUN_0101fb08();
  DAT_000201b4 = FUN_0101c3ac();
  DAT_000201b7 = 0;
  DAT_000201b5 = DAT_000201b4;
  idle_limit_set();
  if (DAT_000201b4 == '\0') {
    FUN_0101c830(10);
  }
  else {
    FUN_0101c830(10);
  }
  return;
}
#endif

/* 01020464 */
#ifdef NONMATCHING
void FUN_01020464(int param_1)
{
  uint extraout_r1;
  uint uVar1;
  
  if (param_1 < 6) {
    if (param_1 < 1) {
      uVar1 = 3;
    }
    else {
      uVar1 = param_1 - 2U & 0xff;
    }
  }
  else {
    FUN_01018240(param_1,6);
    uVar1 = extraout_r1 & 0xff;
  }
  if (uVar1 == 0) {
    FUN_01020350(2);
  }
  else if (uVar1 == 1) {
    FUN_01020350(3);
  }
  else if (uVar1 == 2) {
    FUN_01020350(4);
  }
  else if (uVar1 == 3) {
    FUN_01020350(5);
  }
  FUN_01020354(0x40000000);
  return;
}
#endif

/* 010204bc */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_010204bc(uint param_1)
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_0101ef48(param_1);
  if (iVar1 != 0) {
    _DAT_00021868 = param_1 & 0x600fc36;
    _DAT_0002186c = _DAT_0002186c ^ _DAT_00021868;
    do {
      uVar2 = FUN_0101fb08();
      FUN_0101b242(1);
      iVar1 = FUN_0101ef48(uVar2);
    } while (iVar1 != 0);
  }
  return;
}
#endif

/* 01020500 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01020500(int param_1)
{
  _DAT_00020f98 = _DAT_00020f98 + param_1;
  if (_DAT_00020f90 <= _DAT_00020f98) {
    _DAT_00020f98 = _DAT_00020f98 - _DAT_00020f90;
  }
  FUN_0101f98c(0xb);
  _DAT_00020f94 = _DAT_00020f94 - param_1;
  FUN_0101f9a0(0xb);
  return;
}
#endif

/* 01020544 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01020544(void)
{
  _DAT_00020334 = 0xffffffff;
  _DAT_00020338 = 0xffffffff;
  return;
}
#endif

/* 0102055c */
void FUN_0102055c(void)
{
  FUN_01024090(0x219f4);
  return;
}

/* 0102056c */
#ifdef NONMATCHING
void FUN_0102056c(int param_1)
{
  if ((DAT_000201f7 == '\0') && (DAT_000201b8 == '\0')) {
    memzero(param_1 + 0xe,0x24);
  }
  protocol_report_byte(param_1 + 3);
  return;
}
#endif

/* 0102059c */
#ifdef NONMATCHING
void FUN_0102059c(void)
{
  DAT_000201f7 = 0;
  DAT_000201f6 = 0;
  DAT_00020777 = 0x3f;
  DAT_0002018c = 0;
  DAT_00020717 = 0;
  DAT_000201ea = 1;
  DAT_00020716 = 0;
  return;
}
#endif

/* 010205e0 */
#ifdef NONMATCHING
void FUN_010205e0(int param_1,int param_2)
{
  undefined1 uVar1;
  undefined4 uVar2;
  
  uVar2 = FUN_01024a54(2);
  if (DAT_00020777 == '0') {
    FUN_0102056c(param_1);
    if (param_2 == 2) {
      uVar1 = FUN_01024980();
      *(undefined1 *)(param_1 + 2) = uVar1;
      FUN_01024e8c(uVar2,param_1,0x32);
    }
    else if (((param_2 == 1) && (DAT_000201ea != '\0')) && (DAT_00020181 == '\x03')) {
      DAT_000201ea = '\0';
      uVar1 = FUN_01024980();
      *(undefined1 *)(param_1 + 2) = uVar1;
      FUN_01024b54(param_1 + 1,0x40);
    }
  }
  else if (DAT_00020777 == '?') {
    if (param_2 == 2) {
      FUN_01024e8c(uVar2,param_1,0xd);
    }
    else if (((param_2 == 1) && (DAT_000201ea != '\0')) && (DAT_00020181 == '\x03')) {
      DAT_000201ea = '\0';
      FUN_01024b54(param_1 + 1,0x40);
    }
  }
  return;
}
#endif

/* 01020688 */
#ifdef NONMATCHING
void protocol_report_byte(byte *param_1)
{
  byte bVar1;
  int iVar2;
  
  bVar1 = FUN_0101c22c();
  if (bVar1 < 0x33) {
    if (bVar1 < 0xb) {
      iVar2 = FUN_0101efa4();
      if (iVar2 == 0) {
        *param_1 = 0x40;
      }
      else {
        *param_1 = 0x20;
      }
    }
    else {
      *param_1 = 0x40;
    }
  }
  else {
    *param_1 = 0x60;
  }
  iVar2 = FUN_0101f0bc();
  if (iVar2 != 0) {
    *param_1 = *param_1 | 0x10;
  }
  return;
}
#endif

/* 010206ca */
#ifdef NONMATCHING
void FUN_010206ca(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)
{
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_18 = param_3;
  uStack_14 = param_4;
  FUN_0101c294(&uStack_18);
  if (param_2 == 0) {
    memcpy(param_1,&uStack_18,6);
  }
  else {
    FUN_01023aea(param_1,&uStack_18);
  }
  return;
}
#endif

/* 010206f0 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void switch_host_data(byte *param_1,undefined4 param_2,int param_3)
{
  byte bVar1;
  uint unaff_r4;
  byte *unaff_r5;
  uint unaff_r7;
  undefined1 auStack_64 [2];
  ushort local_62;
  ushort local_5e;
  ushort local_4e;
  ushort local_4a;
  undefined4 local_3c;
  uint local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  undefined *local_24;
  byte *pbStack_20;
  undefined4 uStack_1c;
  int local_18;
  
  pbStack_20 = param_1;
  uStack_1c = param_2;
  local_18 = param_3;
  local_3c = FUN_01024a54(2);
  if (local_18 == 1) {
    local_2c = (uint)*param_1;
    unaff_r4 = (uint)param_1[10];
    unaff_r7 = (uint)param_1[0xb];
    unaff_r5 = param_1;
  }
  else if (local_18 == 2) {
    if (*param_1 == 0xa2) {
      local_2c = (uint)param_1[1];
      unaff_r4 = (uint)param_1[0xb];
      unaff_r7 = (uint)param_1[0xc];
      unaff_r5 = param_1 + 1;
    }
  }
  else {
    local_2c = 0;
    unaff_r4 = 0;
    unaff_r7 = 0;
  }
  if (local_2c == 1) {
    if (unaff_r4 == 1) {
      if (unaff_r7 == 1) {
        _DAT_00020708 = _DAT_00020708 | 0x400;
        FUN_010250e4(unaff_r5 + 0xc,0x20179);
      }
      else if (unaff_r7 == 2) {
        _DAT_00020708 = _DAT_00020708 | 0x800;
        if (local_18 == 1) {
          FUN_0101ded0();
        }
      }
      else if (unaff_r7 == 3) {
        _DAT_00020708 = _DAT_00020708 | 0x1000;
      }
      else if (unaff_r7 == 4) {
        _DAT_00020708 = _DAT_00020708 | 0x2000;
        FUN_010250e4(unaff_r5 + 0xc,0x20179);
        if (local_18 == 1) {
          FUN_0101ded0();
        }
      }
    }
    else if (unaff_r4 == 2) {
      _DAT_00020708 = _DAT_00020708 | 1;
    }
    else if (unaff_r4 == 8) {
      _DAT_00020708 = _DAT_00020708 | 2;
    }
    else if (unaff_r4 == 3) {
      _DAT_00020708 = _DAT_00020708 | 4;
      DAT_00020714 = (char)unaff_r7;
    }
    else if (unaff_r4 == 4) {
      _DAT_00020708 = _DAT_00020708 | 8;
    }
    else if (unaff_r4 == 0x10) {
      _DAT_00020708 = _DAT_00020708 | 0x10;
      _DAT_0002070c = (uint)unaff_r5[0xb];
      _DAT_00020710 = (ushort)unaff_r5[0xf];
      DAT_00020712 = unaff_r5[0xc];
    }
    else if (unaff_r4 == 0x48) {
      _DAT_00020708 = _DAT_00020708 | 0x20;
      if (unaff_r7 == 0) {
        DAT_00020717 = DAT_00020717 & 0xbf;
      }
      else {
        DAT_00020717 = DAT_00020717 | 0x40;
      }
    }
    else if (unaff_r4 == 0x40) {
      _DAT_00020708 = _DAT_00020708 | 0x40;
      if (unaff_r7 == 0) {
        DAT_00020717 = DAT_00020717 & 0x7f;
      }
      else {
        DAT_00020717 = DAT_00020717 | 0x80;
        if (DAT_00020777 == '?') {
          DAT_00020777 = '0';
        }
      }
    }
    else if (unaff_r4 == 0x30) {
      _DAT_00020708 = _DAT_00020708 | 0x80;
      DAT_00020715 = (char)unaff_r7;
    }
    else if (unaff_r4 == 0x22) {
      _DAT_00020708 = _DAT_00020708 | 0x100;
    }
    else if (unaff_r4 == 0x21) {
      _DAT_00020708 = _DAT_00020708 | 0x200;
    }
    else if (unaff_r4 == 0x11) {
      _DAT_00020708 = _DAT_00020708 | 0x40000;
      local_24 = (undefined *)(uint)unaff_r5[0xb];
      local_28 = (uint)unaff_r5[0xf];
      if ((&UNK_0000800f < local_24) && (local_24 < &UNK_00008041)) {
        if (_DAT_000219a8 != -0x74f43526) {
          memcpy(0x219ac,&DAT_0102969d,0x30);
        }
        FUN_010202a0(unaff_r5 + 0x10,(uint)(local_24 + -0x8010) & 0xff,local_28);
      }
    }
  }
  else if (local_2c == 0x80) {
    if (local_18 == 1) {
      bVar1 = param_1[1];
      if (bVar1 == 1) {
        _DAT_00020708 = _DAT_00020708 | 0x200000;
      }
      else if (bVar1 == 2) {
        _DAT_00020708 = _DAT_00020708 | 0x400000;
      }
      else if (bVar1 == 3) {
        _DAT_00020708 = _DAT_00020708 | 0x800000;
      }
      else if (bVar1 == 4) {
        _DAT_00020708 = _DAT_00020708 | 0x1000000;
      }
    }
  }
  else if ((local_2c == 0x10) && ((DAT_00020717 & 0x40) != 0)) {
    if (local_18 == 1) {
      FUN_0101c458(param_1,auStack_64,1);
    }
    else if (local_18 == 2) {
      FUN_0101c458(param_1 + 1,auStack_64,2);
    }
    if (local_5e < local_62) {
      bVar1 = FUN_01018240(local_62,9);
    }
    else {
      bVar1 = FUN_01018240(local_5e,9);
    }
    local_30 = (uint)bVar1;
    if (local_4a < local_4e) {
      bVar1 = FUN_01018240(local_4e,9);
    }
    else {
      bVar1 = FUN_01018240(local_4a,9);
    }
    local_34 = (uint)bVar1;
    FUN_010200bc(local_30,local_34,0x2d,3);
  }
  return;
}
#endif

/* 01020a50 */
#ifdef NONMATCHING
short FUN_01020a50(int param_1)
{
  short sVar1;
  
  sVar1 = 0;
  if (param_1 < 0x21d) {
    if ((param_1 < 0x141) || (0x21c < param_1)) {
      if ((param_1 < 0xe6) || (0x140 < param_1)) {
        if ((param_1 < 0xa1) || (0xe5 < param_1)) {
          if ((param_1 < 0x28) || (0xa0 < param_1)) {
            sVar1 = 0;
          }
          else {
            sVar1 = FUN_01018240((0xa0 - param_1) * 100,0x78);
            sVar1 = 100 - sVar1;
          }
        }
        else {
          sVar1 = FUN_01018240((param_1 + -0xa0) * 100,0x45);
          sVar1 = 100 - sVar1;
        }
      }
      else {
        sVar1 = FUN_01018240((0x140 - param_1) * 0x4c,99);
        sVar1 = 0x4c - sVar1;
      }
    }
    else {
      sVar1 = FUN_01018240((param_1 + -0x140) * 0x4c,0xdc);
      sVar1 = 0x4c - sVar1;
    }
  }
  if (((DAT_000201b2 & 7) == 1) && (sVar1 != 0)) {
    sVar1 = 100;
  }
  else if (sVar1 == 0) {
    sVar1 = 1;
  }
  return sVar1;
}
#endif
