/* yc_flash.c: guessed: flash read, erase, write and the chip UID */

#include "zero2.h"

/* 010180e4 */
void FUN_010180e4(void)
{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

/* 010180e6 */
void FUN_010180e6(void)
{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

/* 010180e8 */
void FUN_010180e8(void)
{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

/* 010198e8 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_010198e8(void)
{
  int iVar1;
  undefined4 uStack0000001c;
  
  memzero(&uStack0000001c,0x100);
  iVar1 = FUN_01019c7c((int)&uStack0000001c + 2);
  if (0 < iVar1) {
    if (uStack0000001c._2_2_ == _DAT_00020648) {
      timer_remove();
      FUN_010232b0();
    }
  }
  return;
}
#endif

/* 01019e48 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Enable_WakeupNs(undefined4 param_1,undefined2 param_2,undefined1 param_3)
{
  int iVar1;
  undefined1 uStack_18;
  undefined1 local_17;
  undefined2 local_16;
  undefined4 local_14;
  
  _uStack_18 = CONCAT22(param_2,CONCAT11(0x70,param_3));
  local_14 = param_1;
  log_empty(STR_01019e9c);
  FUN_01018a54(&DAT_00020010,0x35);
  ipc_send(&uStack_18);
  _DAT_0002000c = now();
  do {
    iVar1 = FUN_01018a76(&DAT_00020010,0x35);
    if (iVar1 != 0) {
      return 1;
    }
    iVar1 = elapsed(_DAT_0002000c,500);
  } while (iVar1 == 0);
  return 0;
}
#endif

/* 0101e008 */
undefined4 FUN_0101e008(void)
{
  FUN_010232b0();
  FUN_01022a00();
  FUN_01022754();
  return 1;
}

/* 0101e050 */
#ifdef NONMATCHING
void FUN_0101e050(void)
{
  if ((DAT_00020181 != '\x03') && (DAT_000201b4 != '\0')) {
    FUN_0101ded0();
  }
  if (DAT_000201b4 == '\0') {
    FUN_010203f0(0x4000);
  }
  return;
}
#endif

/* 0101e080 */
#ifdef NONMATCHING
void report3_build(uint param_1,uint param_2,undefined4 param_3,undefined1 *param_4)
{
  undefined2 uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint local_20;
  
  memzero(param_4,0xb);
  *param_4 = 0xa1;
  param_4[1] = 3;
  local_20 = param_2;
  if (((param_1 & 8) == 8) &&
     ((((param_2 & 0xff00) == 0xff00 || ((param_2 & 0xff000000) == 0xff000000)) ||
      ((param_1 & 0x100) == 0x100)))) {
    local_20 = 0x7f7f7f7f;
    param_1 = param_1 & 0xfffffef7 | 0x20000;
  }
  uVar3 = param_1 & 0x3c0;
  if ((param_1 & 0x2000) != 0) {
    param_4[2] = (param_4[2] & 0xfe) + 1;
  }
  if ((param_1 & 0x1000) != 0) {
    param_4[2] = (param_4[2] & 0xfd) + 2;
  }
  if ((param_1 & 0x10) != 0) {
    param_4[2] = (param_4[2] & 0xf7) + 8;
  }
  if ((param_1 & 0x20) != 0) {
    param_4[2] = (param_4[2] & 0xef) + 0x10;
  }
  if ((param_1 & 0x400) != 0) {
    param_4[2] = (param_4[2] & 0xbf) + 0x40;
  }
  if ((param_1 & 0x800) != 0) {
    param_4[2] = (param_4[2] & 0x7f) + 0x80;
  }
  if ((param_1 & 0x4000) != 0) {
    param_4[3] = (param_4[3] & 0xfe) + 1;
  }
  if ((param_1 & 0x8000) != 0) {
    param_4[3] = (param_4[3] & 0xfd) + 2;
  }
  if ((param_1 & 2) != 0) {
    param_4[3] = (param_4[3] & 0xdf) + 0x20;
  }
  if ((param_1 & 4) != 0) {
    param_4[3] = (param_4[3] & 0xbf) + 0x40;
  }
  if ((param_1 & 8) != 0) {
    param_4[3] = (param_4[3] & 0xfb) + 4;
  }
  if ((param_1 & 1) != 0) {
    param_4[3] = (param_4[3] & 0xf7) + 8;
  }
  if ((param_1 & 0x20000) != 0) {
    param_4[3] = (param_4[3] & 0xef) + 0x10;
  }
  if (uVar3 == 0) {
    param_4[4] = (param_4[4] & 0xf0) + 0xf;
  }
  else if (uVar3 == 0x200) {
    param_4[4] = param_4[4] & 0xf0;
  }
  else if (uVar3 == 0x40) {
    param_4[4] = (param_4[4] & 0xf0) + 2;
  }
  else if (uVar3 == 0x100) {
    param_4[4] = (param_4[4] & 0xf0) + 4;
  }
  else if (uVar3 == 0x80) {
    param_4[4] = (param_4[4] & 0xf0) + 6;
  }
  else if (uVar3 == 0x240) {
    param_4[4] = (param_4[4] & 0xf0) + 1;
  }
  else if (uVar3 == 0x140) {
    param_4[4] = (param_4[4] & 0xf0) + 3;
  }
  else if (uVar3 == 0x180) {
    param_4[4] = (param_4[4] & 0xf0) + 5;
  }
  else if (uVar3 == 0x280) {
    param_4[4] = (param_4[4] & 0xf0) + 7;
  }
  uVar2 = FUN_0101c254();
  uVar1 = FUN_01018240(uVar2,10);
  FUN_010182f0(local_20,param_4 + 5);
  param_4[9] = (char)uVar1;
  param_4[10] = param_4[10] & 0xf0 | (byte)((ushort)uVar1 >> 8) & 0xf;
  param_4[10] = param_4[10] & 0xef | (DAT_000206b1 & 1) << 4;
  param_4[10] = param_4[10] & 0xdf | (DAT_000206b2 & 1) << 5;
  param_4[10] = param_4[10] & 0xbf | (DAT_000206b3 & 1) << 6;
  return;
}
#endif

/* 01020e08 */
#ifdef NONMATCHING
void FUN_01020e08(void)
{
  int iVar1;
  int iVar2;
  undefined1 auStack_ac [8];
  undefined1 auStack_a4 [16];
  undefined1 auStack_94 [6];
  undefined1 auStack_8e [6];
  undefined1 auStack_88 [128];
  
  flash_read(0x107e000,auStack_94,0x8c);
  iVar1 = (uint)DAT_000201b4 * 0x1c;
  iVar2 = FUN_010182b0(auStack_8e + iVar1,&DAT_0102823e,6);
  if (iVar2 != 0) {
    memcpy(auStack_ac,auStack_8e + iVar1,6);
    memcpy(auStack_a4,auStack_88 + iVar1,0x10);
    set_vis(0,0);
    switch_link_key(auStack_ac,auStack_a4);
    DAT_0002067f = 1;
  }
  return;
}
#endif

/* 01020e74 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01020e74(void)
{
  byte bVar1;
  byte bVar2;
  
  if ((DAT_00021864 != '\0') && (_DAT_0002186c != 0)) {
    _DAT_00021874 = _DAT_00021874 + 1;
    _DAT_00021876 = _DAT_00021876 + 1;
    bVar1 = FUN_01023fb8(0x1e);
    bVar2 = FUN_01023fb8(0x1e);
    if (bVar2 < _DAT_00021876) {
      _DAT_00021876 = 0;
      FUN_01020352(1);
    }
    if (bVar1 <= _DAT_00021874) {
      _DAT_00021874 = 0;
      _DAT_00021870 = _DAT_0002186c & ~_DAT_00021870;
    }
  }
  return;
}
#endif

/* 010215e8 */
#ifdef NONMATCHING
longlong FUN_010215e8(void)
{
  uint in_stack_00000000;
  
  FUN_01020f8a();
  return (ulonglong)in_stack_00000000 << 0x20;
}
#endif

/* 01022e14 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01022e14(void)
{
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  local_3c = 0x241900;
  local_38 = _DAT_0002016c;
  local_34 = _DAT_00020170;
  local_30 = _DAT_00020174;
  local_2c = _DAT_0800001c;
  local_28 = _DAT_08000020;
  local_24 = _DAT_08000024;
  local_20 = _DAT_0800341c;
  local_1c = _DAT_08003420;
  local_18 = _DAT_08003424;
  local_14 = 0x40002;
  FUN_0101c034(&local_3c,0x2c);
  return;
}
#endif

/* 01023e64 */
#ifdef NONMATCHING
void FUN_01023e64(int param_1,ushort param_2)
{
  *(ushort *)(param_1 + 0xc) = *(ushort *)(param_1 + 0xc) & ~param_2;
  return;
}
#endif

/* 01023e76 */
#ifdef NONMATCHING
void execute(void)
{
  do {
    FUN_01023e80();
  } while( true );
}
#endif

/* 01023e80 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01023e80(void)
{
  uint uVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = (int *)_DAT_00020638;
  while (uVar1 = _DAT_00020640, piVar2 != (int *)0x0) {
    iVar3 = *piVar2;
    if ((*(byte *)(piVar2 + 3) & 1) != 0) {
      (*(code *)piVar2[2])(piVar2,1);
    }
    piVar2 = (int *)iVar3;
  }
  while ((iVar3 = _DAT_0002063c, _DAT_0002063c != 0 && (*(uint *)(_DAT_0002063c + 4) <= uVar1))) {
    FUN_01024090(_DAT_0002063c);
    (**(code **)(iVar3 + 8))(iVar3);
  }
  FUN_01024bb8();
  if (_DAT_00020644 == 0) {
    FUN_01024bbc();
  }
  else {
    _DAT_00020644 = 0;
    FUN_01024bba();
  }
  return;
}
#endif

/* 010242e4 */
void FUN_010242e4(void)
{
  led_set(7,0);
  return;
}

/* 010247e8 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_010247e8(void)
{
  if (DAT_00022030 == '\0') {
    FUN_01024900();
    led_set(7,0);
    DAT_000206d0 = 4;
    _DAT_00022024 = 0x102492d;
    if (DAT_00020182 == '\x02') {
      FUN_010249ce(0x2201c,9);
    }
    else {
      FUN_010249ce(0x2201c,499);
    }
  }
  return;
}
#endif

/* 010249e6 */
#ifdef NONMATCHING
void FUN_010249e6(void)
{
  bt_disconnect();
  return;
}
#endif

/* 01024e24 */
#ifdef NONMATCHING
void FUN_01024e24(void)
{
  DAT_00020773 = 0;
  DAT_00020774 = 0;
  DAT_00020775 = 0;
  DAT_00020777 = 0x3f;
  DAT_00020779 = 0;
  DAT_00021798 = 0xa1;
  DAT_00021799 = 0x30;
  DAT_0002179a = 0;
  DAT_0002179b = 0;
  DAT_0002179c = 0x80;
  DAT_0002179d = 0x80;
  DAT_0002179e = 0x9e;
  memzero(0x22aa8,0x1a);
  return;
}
#endif

/* 01024e80 */
#ifdef NONMATCHING
void FUN_01024e80(void)
{
  FUN_0000442c();
  return;
}
#endif

/* 01025018 */
#ifdef NONMATCHING
undefined4 flash_read(undefined4 param_1,undefined4 param_2,undefined4 param_3)
{
  undefined4 uVar1;
  undefined4 uVar2;
  
  FUN_01024a7c();
  disableIRQinterrupts();
  uVar1 = FUN_01024fbc();
  thunk_FUN_00004404(0x102393d,0x1023a3d);
  uVar2 = FUN_0102393c(param_1,param_3,param_2);
  FUN_01024264(uVar1);
  enableIRQinterrupts();
  return uVar2;
}
#endif

/* 01025054 */
#ifdef NONMATCHING
undefined4 flash_erase(undefined4 param_1)
{
  undefined4 uVar1;
  undefined4 uVar2;
  
  FUN_01024a7c();
  disableIRQinterrupts();
  uVar1 = FUN_01024fbc();
  uVar2 = FUN_000048b4(param_1);
  FUN_01024264(uVar1);
  enableIRQinterrupts();
  return uVar2;
}
#endif

/* 0102507c */
#ifdef NONMATCHING
undefined4 flash_write(undefined4 param_1,undefined4 param_2,undefined4 param_3)
{
  undefined4 uVar1;
  undefined4 uVar2;
  
  FUN_01024a7c();
  disableIRQinterrupts();
  uVar1 = FUN_01024fbc();
  uVar2 = FUN_010239cc(param_1,param_3,param_2);
  FUN_01024264(uVar1);
  enableIRQinterrupts();
  return uVar2;
}
#endif

/* 010250a8 */
#ifdef NONMATCHING
void FUN_010250a8(undefined4 param_1)
{
  FUN_01024e80();
  FUN_000045d8(param_1);
  FUN_01024150();
  return;
}
#endif

/* 010250c0 */
#ifdef NONMATCHING
undefined4 read_uid(undefined4 param_1,undefined4 param_2,undefined4 param_3)
{
  FUN_01024e80();
  FUN_0000449c(param_1,param_2,param_3);
  FUN_01024150();
  return 1;
}
#endif

/* 010250e4 */
#ifdef NONMATCHING
void FUN_010250e4(undefined4 param_1,undefined4 param_2)
{
  FUN_010250f6(param_1,param_2,6);
  return;
}
#endif

/* 010250f6 */
#ifdef NONMATCHING
void FUN_010250f6(int param_1,int param_2,int param_3)
{
  int iVar1;
  
  for (iVar1 = 0; iVar1 < param_3; iVar1 = iVar1 + 1) {
    *(undefined1 *)(param_2 + ((param_3 + -1) - iVar1)) = *(undefined1 *)(param_1 + iVar1);
  }
  return;
}
#endif

/* 01025110 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01025110(int param_1,uint param_2)
{
  if (param_1 == 0) {
    _DAT_000f881c = _DAT_000f881c & 0xffffff7f;
  }
  else {
    _DAT_000f881c = _DAT_000f881c | 0x80;
  }
  _DAT_000f8560 = _DAT_000f8560 & 0xfffffff0 | param_2 & 0xf;
  return;
}
#endif

/* 0102513c */
#ifdef NONMATCHING
void FUN_0102513c(void)
{
  *(uint *)(_FUN_01025150 + 0x34) = *(uint *)(_FUN_01025150 + 0x34) | 1;
  *(undefined4 *)(_FUN_01025150 + 0x3c) = 0x55;
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}
#endif

/* 01025150 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01025150(int param_1)
{
  *(short *)(param_1 + 0x2a) = (short)param_1;
  if (DAT_00020181 != '\0') {
    FUN_01024ad0();
  }
  FUN_0101f98c(0xffffffff);
  FUN_0101f98c(0xd);
  FUN_0101f98c(0);
  FUN_0101f98c(5);
  FUN_0101f98c(6);
  FUN_0101f98c(0xc);
  FUN_0101f98c(0xb);
  FUN_01020bf8();
  FUN_01020364();
  _DAT_0002fff0 = 0x11223344;
  FUN_010180d4();
  return;
}
#endif

/* 01025154 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01025154(void)
{
  if (DAT_00020181 != '\0') {
    FUN_01024ad0();
  }
  FUN_0101f98c(0xffffffff);
  FUN_0101f98c(0xd);
  FUN_0101f98c(0);
  FUN_0101f98c(5);
  FUN_0101f98c(6);
  FUN_0101f98c(0xc);
  FUN_0101f98c(0xb);
  FUN_01020bf8();
  FUN_01020364();
  _DAT_0002fff0 = 0x11223344;
  FUN_010180d4();
  return;
}
#endif
