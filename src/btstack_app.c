/* btstack_app.c: btstack_app.c in Reconnect_timer_handler's assert */

#include "zero2.h"

/* 0101fbf0 */
#ifdef NONMATCHING
void Reconnect_timer_handler(void)
{
  Reconnect_Host(STR_0101fc08,STR_01029184,0x3dd);
  return;
}
#endif

/* 0101fc18 */
#ifdef NONMATCHING
void FUN_0101fc18(void)
{
  if (DAT_00021ea0 != '\0') {
    FUN_01024090(0x21e8c);
  }
  return;
}
#endif

/* 0101fc30 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0101fc30(int param_1,byte param_2)
{
  uint uVar1;
  
  uVar1 = param_1 << 8 | (uint)param_2;
  if (_DAT_0002192c != uVar1) {
    _DAT_0002192c = (ushort)uVar1;
    DAT_000201e8 = 1;
  }
  return;
}
#endif

/* 0101fc58 */
#ifdef NONMATCHING
void mode_setup(int param_1)
{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_2c [32];
  
  if (param_1 == 0) {
    memzero(auStack_2c,0x20);
    FUN_010182ca(auStack_2c,STR_01029103);
    iVar1 = BT_SetSDP_SERVICE(0x2035c,0x229);
    if (iVar1 == 0) {
      log_empty(STR_0101fe0c);
    }
    else {
      log_empty(STR_0101fde4);
    }
  }
  else if (param_1 == 3) {
    BT_ResetFeatrues(0x205ec,8);
    memzero(auStack_2c,0x20);
    uVar2 = FUN_0101c340();
    FUN_010182ca(auStack_2c,uVar2);
    iVar1 = BT_SetSDP_SERVICE(&DAT_01028745,0x20e);
    if (iVar1 == 0) {
      log_empty(STR_0101fe64);
    }
    else {
      log_empty(STR_0101fe3c);
    }
    FUN_0101a0f0(1,0x10);
  }
  else if (param_1 == 1) {
    memzero(auStack_2c,0x20);
    uVar2 = FUN_0101c340();
    FUN_010182ca(auStack_2c,uVar2);
    iVar1 = BT_SetSDP_SERVICE(&DAT_01028953,0x2d9);
    if (iVar1 == 0) {
      log_empty(STR_0101fec0);
    }
    else {
      log_empty(STR_0101fe90,0x2d9);
    }
    BT_ResetFeatrues(0x205ec,8);
    FUN_0101a0f0(0);
  }
  else if (param_1 == 2) {
    memzero(auStack_2c,0x20);
    uVar2 = FUN_0101c340();
    FUN_010182ca(auStack_2c,uVar2);
    iVar1 = BT_SetSDP_SERVICE(&DAT_01028c2c,0x2db);
    if (iVar1 == 0) {
      log_empty(STR_0101ff14);
    }
    else {
      log_empty(STR_0101fee8,0x2db);
    }
    BT_ResetFeatrues(0x205ec,8);
    FUN_0101a0f0(0);
  }
  else if (param_1 == 4) {
    memzero(auStack_2c,0x20);
    uVar2 = FUN_0101c340();
    FUN_010182ca(auStack_2c,uVar2);
    iVar1 = BT_SetSDP_SERVICE(&DAT_01028f07,0x1fc);
    if (iVar1 == 0) {
      log_empty(STR_0101ff68);
    }
    else {
      log_empty(STR_0101ff38,0x1fc);
    }
    BT_ResetFeatrues(0x205ec,8);
    FUN_0101a0f0(0);
  }
  iVar1 = FUN_0101a098(auStack_2c,0x1f);
  if (iVar1 == 1) {
    log_empty(STR_0101ff8c);
  }
  else {
    log_empty(STR_0101ff9c);
  }
  return;
}
#endif

/* 0101ffac */
#ifdef NONMATCHING
void pair_write_back(undefined4 param_1)
{
  flash_erase(0x107f000);
  flash_write(0x107f000,param_1,0xaa);
  return;
}
#endif

/* 0101ffc8 */
#ifdef NONMATCHING
undefined4 host_store(int param_1)
{
  undefined4 uVar1;
  undefined1 auStack_9c [6];
  undefined1 auStack_96 [134];
  
  memcpy((uint)DAT_000201b4 * 0x1c + 0x21ed4,param_1,0x1c);
  if (DAT_000201b8 == '\0') {
    flash_read(0x107e000,auStack_9c,0x8c);
    if (((*(char *)(param_1 + 0xb) == -0x1c) && (*(char *)(param_1 + 10) == '\x17')) &&
       (*(char *)(param_1 + 9) == -0x28)) {
      DAT_00020658 = 1;
      if (DAT_000201b4 == 0) {
        memcpy(auStack_9c + (uint)DAT_000201b4 * 0x1c,param_1,0x1c);
      }
      else {
        memzero(auStack_96 + (uint)DAT_000201b4 * 0x1c,6);
      }
    }
    else {
      DAT_00020658 = 0;
      memcpy(auStack_9c + (uint)DAT_000201b4 * 0x1c,param_1,0x1c);
    }
    flash_erase(0x107e000);
    uVar1 = flash_write(0x107e000,auStack_9c,0x8c);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}
#endif

/* 01020074 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01020074(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  undefined4 local_10;
  undefined4 uStack_c;
  
  local_10 = param_3;
  uStack_c = param_4;
  flash_read(0x107d100,&DAT_000219a8,0x34);
  if (_DAT_000219a8 != -0x74f43526) {
    memzero(&DAT_000219a8,0x34);
  }
  local_10 = CONCAT31(local_10._1_3_,0x33);
  memcpy((int)&local_10 + 1,0x219d0,6);
  FUN_01024b54(&local_10,9);
  return;
}
#endif

/* 010200bc */
void FUN_010200bc(void)
{
  return;
}

/* 010200be */
#ifdef NONMATCHING
void FUN_010200be(void)
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 5;
  FUN_01024900();
  FUN_010242e4();
  do {
    rom_delay_a(100);
    uVar1 = FUN_0101fb08();
    if ((uVar1 & 1) != 0) {
      FUN_01025154();
    }
    iVar2 = GPIO_ReadInputDataBit(1,0x40);
    if (iVar2 == 0) {
      uVar3 = uVar3 - 1;
    }
    else if (uVar3 < 10) {
      uVar3 = uVar3 + 1;
    }
    else {
      FUN_010242e4();
    }
  } while (uVar3 != 0);
  GPIO_ResetBits(2,4);
  rom_delay_a(1000);
  return;
}
#endif
