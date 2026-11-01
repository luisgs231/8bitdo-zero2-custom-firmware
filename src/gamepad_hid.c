/* gamepad_hid.c: gamepad_hid.c in Create_BtConnection's assert */

#include "zero2.h"

/* 0101a570 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void startup(void)
{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined *local_20;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  uint3 uStack_10;
  undefined1 uStack_d;
  
  local_1c = 0x4c453038;
  uStack_18 = 0;
  uStack_14 = 0;
  _uStack_10 = 0;
  local_20 = &DAT_0000e417;
  local_24 = 0xd8000000;
  local_2c = 0;
  local_28 = 0;
  DAT_00020682 = 0;
  FUN_01018d8c();
  _DAT_e000e100 = _DAT_e000e100 | 0x800;
  memcpy(&local_2c,0x20000,6);
  uVar1 = local_2c;
  cVar2 = (char)local_2c + local_2c._3_1_;
  local_2c._1_1_ = local_2c._1_1_ + (char)local_28;
  local_2c._0_2_ = CONCAT11(local_2c._1_1_,cVar2);
  local_2c._2_1_ = SUB41(uVar1,2);
  local_2c._2_1_ = local_2c._2_1_ + local_28._1_1_;
  uStack_10 = (uint3)(ushort)uStack_10;
  memcpy(&local_24,&local_2c,3);
  FUN_01019ff0(&local_1c,0xe);
  set_ble_addr(&local_24);
  FUN_0101c294(&local_24);
  FUN_0101a044(&local_24);
  FUN_0101a254(1);
  if (DAT_000201b4 == '\x04') {
    FUN_0101a154(0x2064d);
  }
  else {
    FUN_0101a154(0x2064a);
  }
  FUN_01019f98(200);
  FUN_0101a1a8(0x400);
  mode_setup(DAT_000201b4);
  flash_read(0x107f000,&DAT_00021f60,0xaa);
  if ((((5 < DAT_00021f60) || (5 < DAT_00021f82)) || (5 < DAT_00021fa4)) ||
     ((5 < DAT_00021fc6 || (5 < DAT_00021fe8)))) {
    memzero(&DAT_00021f60,0xaa);
  }
  iVar4 = 0;
  iVar3 = FUN_0101a200(&DAT_00021f60,0xaa);
  if (iVar3 == 1) {
    for (; iVar4 < 0xaa; iVar4 = iVar4 + 1) {
    }
  }
  set_vis(0,0,1);
  FUN_01018c1c();
  FUN_010189f0(0x2065a,0x11);
  _DAT_00020648 = FUN_0101898c(0x2066b,0x14);
  cmd_42(2);
  if (DAT_000201b8 == '\0') {
    set_vis(0,0);
  }
  else {
    set_vis(0,1);
  }
  data_source_add();
  return;
}
#endif

/* 0101a718 */
#ifdef NONMATCHING
void FUN_0101a718(void)
{
  FUN_0102059c();
  FUN_0101fa5c();
  FUN_0101e678(0);
  run_loop();
  return;
}
#endif

/* 0101a730 */
#ifdef NONMATCHING
undefined4 run_loop(void)
{
  FUN_01024bcc();
  FUN_01023ae8();
  FUN_01023bb4();
  FUN_01023efc();
  btstack_run_loop_init();
  FUN_0101a784();
  startup();
  hci_power_control();
  FUN_01024030();
  return 0;
}
#endif

/* 0101a75c */
void FUN_0101a75c(void)
{
  return;
}

/* 0101a760 */
#ifdef NONMATCHING
void data_source_add(void)
{
  FUN_010240a8(0x2200c,0x101986d);
  btstack_run_loop_remove_data_source(0x2200c,1);
  btstack_run_loop_add_data_source(0x2200c);
  return;
}
#endif

/* 0101a784 */
#ifdef NONMATCHING
void FUN_0101a784(void)
{
  FUN_010240a8(0x21e7c,0x1022a21);
  btstack_run_loop_remove_data_source(0x21e7c,1);
  btstack_run_loop_add_data_source(0x21e7c);
  return;
}
#endif

/* 0101a7a8 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0101a7a8(void)
{
  (*_DAT_000205f4)();
  return;
}
#endif

/* 0101a7b8 */
#ifdef NONMATCHING
void FUN_0101a7b8(int param_1)
{
  if (param_1 == 0) {
    FUN_01020354(0x80000000);
  }
  else if (param_1 == 1) {
    FUN_01020354(0x20000000);
    DAT_000201b6 = 3;
  }
  else if (param_1 == 2) {
    FUN_01020354(0x20000000);
    DAT_000201b6 = 1;
  }
  else if (param_1 == 3) {
    FUN_01020354(0x20000000);
    DAT_000201b6 = 2;
  }
  else if (param_1 == 4) {
    FUN_01020354(0x20000000);
    DAT_000201b6 = 0;
  }
  return;
}
#endif

/* 0101a818 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0101a818(undefined4 param_1,uint param_2)
{
  int iVar1;
  uint uVar2;
  
  if (DAT_000201b8 == '\x01') {
    uVar2 = _DAT_00020008 - _DAT_000201ec;
    if (_DAT_000201ec == 0) {
      _DAT_000201ec = _DAT_00020008;
    }
    if ((param_2 & 0x20000) != 0) {
      FUN_01024900();
    }
    if (uVar2 < 0x76d) {
      if (uVar2 < 0x579) {
        if (uVar2 < 0x385) {
          if (400 < uVar2) {
            led_set(7,0);
          }
        }
        else {
          led_set(7,1);
        }
      }
      else {
        led_set(7,2);
      }
    }
    else {
      led_set(7,4);
      _DAT_000201ec = _DAT_00020008;
    }
  }
  else {
    iVar1 = FUN_0101f0bc();
    if (iVar1 == 0) {
      led_set(7,0);
      FUN_0101fc30(0xff,DAT_000201b4);
      FUN_01024d78();
      FUN_01024194();
      rom_delay_a(0x14);
      FUN_01025a64(0);
      GPIO_ResetBits(2,4);
      FUN_0101b242(200);
    }
  }
  return;
}
#endif

/* 0101a8f4 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_0101a8f4(void)
{
  return _DAT_0002fff0 == -0x789abcdf;
}
#endif

/* 0101a910 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_0101a910(void)
{
  return _DAT_0002fff0 == 0x12345678;
}
#endif

/* 0101a92c */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0101a92c(void)
{
  short sVar1;
  uint uVar2;
  
  _DAT_000201f2 = _DAT_000201f0;
  sVar1 = CONCAT11(DAT_000f602a,DAT_000f6029);
  if ((sVar1 == _DAT_000201f0) && (sVar1 != 0)) {
    _DAT_000201f4 = _DAT_000201f4 + 1;
  }
  else {
    _DAT_000201f4 = 0;
  }
  _DAT_000201f0 = sVar1;
  uVar2 = FUN_01023fb8(3000);
  if (uVar2 <= _DAT_000201f4) {
    FUN_0101e01c();
    _DAT_000201f4 = 0;
    FUN_01020354(0x800000);
    DAT_00020181 = 5;
  }
  return;
}
#endif

/* 0101a9ac */
#ifdef NONMATCHING
undefined4 FUN_0101a9ac(undefined4 param_1)
{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  while( true ) {
    if (0xa0 < uVar2) {
      return 0;
    }
    iVar1 = FUN_010182b0(param_1,&DAT_01028420 + uVar2 * 4,4);
    if (iVar1 == 0) break;
    uVar2 = uVar2 + 1 & 0xffff;
  }
  return 1;
}
#endif

/* 0101a9dc */
void FUN_0101a9dc(void)
{
  return;
}

/* 0101a9e0 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0101a9e0(uint param_1)
{
  _DAT_000201bc = _DAT_000201bc & ~param_1;
  return;
}
#endif

/* 0101a9f0 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_0101a9f0(uint param_1)
{
  bool bVar1;
  
  bVar1 = (_DAT_00020140 & param_1) != 0;
  if (bVar1) {
    _DAT_00020140 = _DAT_00020140 & ~param_1;
  }
  return bVar1;
}
#endif

/* 0101aa14 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0101aa14(uint param_1)
{
  _DAT_000201c0 = _DAT_000201c0 & ~param_1;
  return;
}
#endif

/* 0101aa24 */
void FUN_0101aa24(void)
{
  return;
}

/* 0101aa28 */
#ifdef NONMATCHING
char FUN_0101aa28(void)
{
  char cVar1;
  
  cVar1 = DAT_000201b4;
  if (DAT_000201b4 != '\0') {
    if (DAT_000201b4 == '\x03') {
      cVar1 = '\x01';
    }
    else if (DAT_000201b4 == '\x01') {
      cVar1 = '\x03';
    }
    else if ((DAT_000201b4 != '\x02') && (DAT_000201b4 == '\x04')) {
      cVar1 = '\x01';
    }
  }
  return cVar1;
}
#endif

/* 0101aa6c */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0101aa6c(uint *param_1,uint *param_2)
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint local_1c;
  uint local_18;
  
  uVar1 = *param_1;
  if (DAT_0002015c != '\0') {
    if ((~(*param_1 >> 0xd) & 1) != (~(*param_1 >> 0xc) & 1)) {
      *param_1 = *param_1 ^ 0x3000;
    }
    if ((~(*param_1 >> 4) & 1) != (~(*param_1 >> 5) & 1)) {
      *param_1 = *param_1 ^ 0x30;
    }
  }
  uVar3 = (uint)(byte)*param_2;
  local_18 = (uint)(ushort)((ushort)*param_2 >> 8);
  local_1c = (*param_2 & 0xffffff) >> 0x10;
  uVar2 = *param_2 >> 0x18;
  if (_DAT_0002015a == 0x80) {
    if (DAT_000201b4 == '\0') {
      if ((uVar1 & 0x200) == 0) {
        if ((uVar1 & 0x100) == 0) {
          local_18 = 0x7f;
        }
        else {
          local_18 = 0;
        }
      }
      else {
        local_18 = 0xff;
      }
    }
    else if ((uVar1 & 0x200) == 0) {
      if ((uVar1 & 0x100) == 0) {
        local_18 = 0x7f;
      }
      else {
        local_18 = 0xff;
      }
    }
    else {
      local_18 = 0;
    }
    if ((uVar1 & 0x80) == 0) {
      if ((uVar1 & 0x40) == 0) {
        uVar3 = 0x7f;
      }
      else {
        uVar3 = 0xff;
      }
    }
    else {
      uVar3 = 0;
    }
  }
  else {
    if (_DAT_0002015a != 0x40) {
      return;
    }
    if (DAT_000201b4 == '\0') {
      if ((uVar1 & 0x200) == 0) {
        if ((uVar1 & 0x100) == 0) {
          uVar2 = 0x7f;
        }
        else {
          uVar2 = 0;
        }
      }
      else {
        uVar2 = 0xff;
      }
    }
    else if ((uVar1 & 0x200) == 0) {
      if ((uVar1 & 0x100) == 0) {
        uVar2 = 0x7f;
      }
      else {
        uVar2 = 0xff;
      }
    }
    else {
      uVar2 = 0;
    }
    if ((uVar1 & 0x80) == 0) {
      if ((uVar1 & 0x40) == 0) {
        local_1c = 0x7f;
      }
      else {
        local_1c = 0xff;
      }
    }
    else {
      local_1c = 0;
    }
  }
  *param_1 = *param_1 & 0xfffffc3f;
  *param_2 = local_18 << 8 | uVar3 | local_1c << 0x10 | uVar2 << 0x18;
  return;
}
#endif

/* 0101abe0 */
#ifdef NONMATCHING
void FUN_0101abe0(byte *param_1,int param_2,undefined4 param_3,undefined4 param_4)
{
  uint uVar1;
  uint local_1c;
  undefined4 local_18;
  
  uVar1 = (uint)CONCAT12(*(undefined1 *)(param_2 + 3),
                         CONCAT11(*(undefined1 *)(param_2 + 4),*(undefined1 *)(param_2 + 5)));
  local_18 = 0;
  local_1c = 0;
  FUN_0101a390(uVar1,&local_18,&local_1c,param_4,param_2);
  log_empty(STR_0101ac50,uVar1,local_18,local_1c,~local_1c);
  *param_1 = ~(byte)local_1c;
  param_1[1] = ~(byte)(local_1c >> 8);
  param_1[2] = ~(byte)(local_1c >> 0x10);
  param_1[3] = ~(byte)(local_1c >> 0x18);
  memcpy(param_1 + 4,&local_1c,4);
  memcpy(param_1 + 8,&local_18,4);
  return;
}
#endif

/* 0101ac7c */
#ifdef NONMATCHING
void Create_BtConnection(void)
{
  int iVar1;
  
  DAT_00020182 = 1;
  idle_limit_set();
  if ((((DAT_000201b8 == '\0') && (iVar1 = FUN_0101f098(), iVar1 != 0)) &&
      (iVar1 = usb_powered(), iVar1 == 0)) &&
     (iVar1 = Reconnect_Host(STR_0101acd0,STR_01029143,0x135), iVar1 != 0)) {
    DAT_000201dc = DAT_000201dc | 0x80;
  }
  return;
}
#endif

/* 0101ace4 */
#ifdef NONMATCHING
undefined4 FUN_0101ace4(int param_1,uint param_2)
{
  byte *pbVar1;
  
  if ((param_2 & 0x80) == 0x80) {
    pbVar1 = (byte *)((param_2 & 0x7f) * 0x24 + param_1 + 0x44);
  }
  else {
    pbVar1 = (byte *)((param_2 & 0x7f) * 0x24 + param_1 + 0x260);
  }
  *pbVar1 = (byte)param_2 & 0x7f;
  pbVar1[1] = (byte)param_2 & 0x80;
  FUN_0102244a(param_1,pbVar1);
  return 0;
}
#endif

/* 0101ad2e */
#ifdef NONMATCHING
undefined4 FUN_0101ad2e(int param_1,uint param_2,byte param_3,int param_4)
{
  byte *pbVar1;
  
  if ((param_2 & 0x80) == 0x80) {
    pbVar1 = (byte *)((param_2 & 0x7f) * 0x24 + param_1 + 0x44);
  }
  else {
    pbVar1 = (byte *)((param_2 & 0x7f) * 0x24 + param_1 + 0x260);
  }
  *pbVar1 = (byte)param_2 & 0x7f;
  pbVar1[1] = (byte)((param_2 & 0x80) >> 7);
  pbVar1[7] = param_3;
  pbVar1[3] = (byte)param_4;
  if (pbVar1[1] != 0) {
    pbVar1[6] = *pbVar1;
  }
  if (param_4 == 2) {
    pbVar1[4] = 0;
  }
  FUN_0102240c(param_1,pbVar1);
  return 0;
}
#endif

/* 0101ad98 */
#ifdef NONMATCHING
/* WARNING: Removing unreachable block (ram,0x0101ae1c) */

undefined4 FUN_0101ad98(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)
{
  byte *pbVar1;
  
  pbVar1 = (byte *)((param_2 & 0x7f) * 0x24 + param_1 + 0x260);
  *(undefined4 *)(pbVar1 + 8) = param_3;
  *(undefined4 *)(pbVar1 + 0x10) = param_4;
  pbVar1[0x14] = 0;
  pbVar1[0x15] = 0;
  pbVar1[0x16] = 0;
  pbVar1[0x17] = 0;
  pbVar1[1] = 0;
  *pbVar1 = (byte)param_2 & 0x7f;
  if (*(char *)(param_1 + 3) == '\x01') {
    *(undefined4 *)(pbVar1 + 0xc) = param_3;
  }
  if (*pbVar1 == 0) {
    FUN_01022330(param_1,pbVar1);
  }
  else {
    DAT_00020132 = '\x01';
    DAT_000f6026 = 0x40;
    FUN_010224bc(param_1,pbVar1);
    if (DAT_00020132 == '\0') {
      DAT_000f6026 = *pbVar1 ^ 2;
      FUN_010224bc(param_1,pbVar1);
    }
  }
  return 0;
}
#endif

/* 0101ae58 */
#ifdef NONMATCHING
undefined4 FUN_0101ae58(int param_1,uint param_2)
{
  byte *pbVar1;
  
  if ((param_2 & 0x80) == 0x80) {
    pbVar1 = (byte *)((param_2 & 0x7f) * 0x24 + param_1 + 0x44);
  }
  else {
    pbVar1 = (byte *)(param_2 * 0x24 + param_1 + 0x260);
  }
  pbVar1[2] = 1;
  *pbVar1 = (byte)param_2 & 0x7f;
  pbVar1[1] = (byte)((param_2 & 0x80) >> 7);
  FUN_0102249c(param_1,pbVar1);
  return 0;
}
#endif

/* 0101aea4 */
#ifdef NONMATCHING
undefined4 FUN_0101aea4(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)
{
  byte *pbVar1;
  
  pbVar1 = (byte *)((param_2 & 0x7f) * 0x24 + param_1 + 0x44);
  pbVar1[1] = 1;
  *pbVar1 = (byte)param_2 & 0x7f;
  *(undefined4 *)(pbVar1 + 8) = param_3;
  pbVar1[0x14] = 0;
  pbVar1[0x15] = 0;
  pbVar1[0x16] = 0;
  pbVar1[0x17] = 0;
  *(undefined4 *)(pbVar1 + 0x10) = param_4;
  if (*pbVar1 == 0) {
    FUN_01022330(param_1,pbVar1);
  }
  else {
    FUN_010224bc(param_1,pbVar1);
  }
  return 0;
}
#endif

/* 0101aef0 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_0101aef0(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)
{
  undefined4 uVar1;
  uint uVar2;
  int extraout_r1;
  uint uVar3;
  undefined1 *puVar4;
  
  uVar3 = 0;
  uVar2 = param_2;
  do {
    if (param_2 == 0) {
      uVar1 = 1;
LAB_0101af74:
      return CONCAT44(uVar2,uVar1);
    }
    puVar4 = (undefined1 *)(uVar3 * 0x24 + param_1 + 0x44);
    puVar4[1] = 1;
    *puVar4 = (char)uVar3;
    if ((param_2 & 1) != 0) {
      if (*(int *)(uVar3 * 0x24 + param_1 + 0x5c) == 0) {
        if ((*(int *)(uVar3 * 0x24 + param_1 + 0x54) != 0) &&
           (FUN_01018214(*(undefined4 *)(uVar3 * 0x24 + param_1 + 0x54),
                         *(undefined1 *)(uVar3 * 0x24 + param_1 + 0x4b)), extraout_r1 == 0)) {
          FUN_01022488(param_1,puVar4);
          *(undefined4 *)(uVar3 * 0x24 + param_1 + 0x54) = 0;
        }
        uVar1 = 0;
        goto LAB_0101af74;
      }
      if ((uint)(*(int *)(uVar3 * 0x24 + param_1 + 0x54) - *(int *)(uVar3 * 0x24 + param_1 + 0x58))
          < (uint)*(byte *)(uVar3 * 0x24 + param_1 + 0x4b)) {
        uVar2 = *(int *)(uVar3 * 0x24 + param_1 + 0x4c) + *(int *)(uVar3 * 0x24 + param_1 + 0x58);
        FUN_01022724(param_1,uVar2,uVar3 & 0xff,
                     *(char *)(uVar3 * 0x24 + param_1 + 0x54) -
                     *(char *)(uVar3 * 0x24 + param_1 + 0x58),uVar2,uVar3 & 0xff,param_4);
        FUN_010226dc(param_1,puVar4);
        *(undefined4 *)(uVar3 * 0x24 + param_1 + 0x58) =
             *(undefined4 *)(uVar3 * 0x24 + param_1 + 0x54);
        *(undefined4 *)(uVar3 * 0x24 + param_1 + 0x5c) = 0;
        (**(code **)(_DAT_000200d8 + 4))(param_1,uVar3 & 0xff);
        *(undefined1 *)(param_1 + 0x4a4) = 0;
      }
      else {
        uVar2 = *(int *)(uVar3 * 0x24 + param_1 + 0x4c) + *(int *)(uVar3 * 0x24 + param_1 + 0x58);
        FUN_01022724(param_1,uVar2,uVar3 & 0xff,*(undefined1 *)(uVar3 * 0x24 + param_1 + 0x4b),uVar2
                     ,uVar3 & 0xff,param_4);
        FUN_010226dc(param_1,puVar4);
        *(uint *)(uVar3 * 0x24 + param_1 + 0x58) =
             *(int *)(uVar3 * 0x24 + param_1 + 0x58) +
             (uint)*(byte *)(uVar3 * 0x24 + param_1 + 0x4b);
        *(int *)(uVar3 * 0x24 + param_1 + 0x5c) =
             *(int *)(uVar3 * 0x24 + param_1 + 0x54) - *(int *)(uVar3 * 0x24 + param_1 + 0x58);
        *(undefined1 *)(param_1 + 0x4a4) = 1;
      }
    }
    uVar3 = uVar3 + 1 & 0xffff;
    param_2 = (int)param_2 >> 1;
  } while( true );
}
#endif

/* 0101b108 */
#ifdef NONMATCHING
void FUN_0101b108(int param_1)
{
  int iVar1;
  
  DAT_00020136 = **(byte **)(param_1 + 0x24);
  if (DAT_00020134 == '\x02') {
    for (iVar1 = 0; iVar1 < (int)(uint)DAT_00020136; iVar1 = iVar1 + 1) {
      *(undefined1 *)(iVar1 + 0x21658) = DAT_000f6018;
    }
    FUN_01022488(param_1,0);
  }
  else if (DAT_00020134 == '\x03') {
    for (iVar1 = 0; iVar1 < (int)(uint)DAT_00020136; iVar1 = iVar1 + 1) {
      *(undefined1 *)(iVar1 + 0x21658) = DAT_000f6018;
    }
    FUN_01022488(param_1,0);
  }
  return;
}
#endif

/* 0101b174 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0101b174(int param_1,uint param_2)
{
  uint uVar1;
  
  uVar1 = 1;
  while (param_2 = (int)param_2 >> 1, param_2 != 0) {
    if (((param_2 & 1) != 0) && (*(char *)(param_1 + 0x24 + uVar1 * 4) != '\0')) {
      (*(code *)*_DAT_000200d8)(param_1,uVar1 & 0xff);
    }
    uVar1 = uVar1 + 1;
  }
  return 1;
}
#endif

/* 0101b1b0 */
#ifdef NONMATCHING
void FUN_0101b1b0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  undefined1 *puVar1;
  uint uVar2;
  
  FUN_01022614(param_1,param_2,param_3,param_4,param_4);
  *(undefined1 *)(param_1 + 0x3a) = 1;
  *(undefined1 *)(param_1 + 0x3d) = 0;
  for (uVar2 = 0; uVar2 < *(byte *)(param_1 + 1); uVar2 = uVar2 + 1) {
    puVar1 = (undefined1 *)(uVar2 * 0x24 + param_1 + 0x44);
    puVar1[1] = 1;
    *puVar1 = (char)uVar2;
    puVar1[6] = (char)uVar2;
    puVar1[3] = 0;
    puVar1[7] = 0x40;
    *(undefined4 *)(puVar1 + 8) = 0;
    *(undefined4 *)(puVar1 + 0x10) = 0;
  }
  for (uVar2 = 0; uVar2 < *(byte *)(param_1 + 1); uVar2 = uVar2 + 1) {
    puVar1 = (undefined1 *)(uVar2 * 0x24 + param_1 + 0x260);
    puVar1[1] = 0;
    *puVar1 = (char)uVar2;
    puVar1[6] = (char)uVar2;
    puVar1[3] = 0;
    puVar1[7] = 0x40;
    *(undefined4 *)(puVar1 + 8) = 0;
    *(undefined4 *)(puVar1 + 0x10) = 0;
  }
  FUN_0102232a(param_1);
  FUN_010226a4(param_1,0);
  return;
}
#endif

/* 0101b238 */
#ifdef NONMATCHING
void thunk_FUN_0101b23c(int param_1)
{
  for (; param_1 != 0; param_1 = param_1 + -1) {
  }
  return;
}
#endif

/* 0101b23c */
#ifdef NONMATCHING
void FUN_0101b23c(int param_1)
{
  for (; param_1 != 0; param_1 = param_1 + -1) {
  }
  return;
}
#endif

/* 0101b242 */
#ifdef NONMATCHING
void FUN_0101b242(int param_1)
{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = FUN_01023f04();
  iVar2 = FUN_01023fb8(param_1 * 10);
  while (uVar3 = FUN_01023f04(), uVar3 <= (uint)(iVar2 + iVar1)) {
    thunk_FUN_0101b23c(2);
  }
  return;
}
#endif

/* 0101b274 */
#ifdef NONMATCHING
undefined4 FUN_0101b274(void)
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_0101fae0();
  if (((iVar1 == 0) && (iVar1 = FUN_0101ef14(), iVar1 == 0)) && (iVar1 = FUN_0101f0e4(), iVar1 == 0)
     ) {
    uVar2 = 0;
  }
  else {
    if (((DAT_00020182 != '\x02') && (iVar1 = usb_powered(), iVar1 == 0)) && (DAT_000201b8 == '\0'))
    {
      DAT_000206b2 = 1;
      FUN_01024838();
    }
    uVar2 = 1;
  }
  return uVar2;
}
#endif

/* 0101b2c4 */
#ifdef NONMATCHING
/* WARNING: Removing unreachable block (ram,0x0101b3ec) */

void android_host_data(char *param_1,undefined4 param_2,int param_3,undefined4 param_4)
{
  bool bVar1;
  
  if (param_3 == 1) {
    bVar1 = DAT_000201b4 == '\x02';
    do {
      if (!bVar1) {
        return;
      }
      bVar1 = *param_1 == '\x05';
    } while (!bVar1);
    FUN_010200bc((int)(uint)(byte)param_1[5] >> 1,(int)(uint)(byte)param_1[4] >> 1,0x2d,3,param_4);
  }
  else if (param_3 == 2) {
                    /* WARNING: Subroutine does not return */
    yc_switch8();
  }
  return;
}
#endif

/* 0101b318 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0101b318(void)
{
  _DAT_00020708 = _DAT_00020708 | 1;
  return;
}
#endif

/* 0101b326 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0101b326(void)
{
  uint unaff_r6;
  
  if ((unaff_r6 & 0xf) == 5) {
    _DAT_00020708 = _DAT_00020708 | 2;
  }
  return;
}
#endif

/* 0101b33c */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0101b33c(void)
{
  uint unaff_r5;
  
  if ((DAT_000201b4 != '\x02') && (DAT_000201b4 == '\x03')) {
    _DAT_00022ac2 = 4;
    if (0x40 < unaff_r5) {
      unaff_r5 = 0x40;
    }
    DAT_00022ac4 = (undefined1)unaff_r5;
    memcpy(0x22ac5);
  }
  _DAT_00020708 = _DAT_00020708 | 4;
  return;
}
#endif

/* 0101b376 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0101b376(void)
{
  char *unaff_r4;
  uint unaff_r5;
  
  if (DAT_000201b4 == '\x03') {
    _DAT_00022ac2 = 8;
    if (0x40 < unaff_r5) {
      unaff_r5 = 0x40;
    }
    DAT_00022ac4 = (undefined1)unaff_r5;
    memcpy(0x22ac5);
  }
  else if ((DAT_000201b4 == '\x02') && (*unaff_r4 == 'R')) {
    FUN_010200bc((int)(uint)(byte)unaff_r4[8] >> 1,(int)(uint)(byte)unaff_r4[7] >> 1,0x2d,3);
  }
  _DAT_00020708 = _DAT_00020708 | 8;
  return;
}
#endif

/* 0101b3c8 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0101b3c8(void)
{
  _DAT_00020708 = _DAT_00020708 | 0x10;
  return;
}
#endif

/* 0101b3d6 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0101b3d6(void)
{
  byte unaff_r6;
  
  DAT_00020718 = unaff_r6 & 1;
  _DAT_00020708 = _DAT_00020708 | 0x20;
  return;
}
#endif

/* 0101b3ec */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_0101b482(void)
{
  _DAT_00020708 = _DAT_00020708 | 0x400;
  return;
}
#endif

/* 0101b3ee */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0101b3ee(void)
{
  _DAT_00020708 = _DAT_00020708 | 0x40;
  return;
}
#endif

/* 0101b3fc */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0101b3fc(void)
{
  _DAT_00020708 = _DAT_00020708 | 0x80;
  return;
}
#endif

/* 0101b40a */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0101b40a(void)
{
  char *unaff_r4;
  short unaff_r5;
  
  _DAT_00020708 = _DAT_00020708 | 0x100;
  if (DAT_000201b4 == '\x03') {
    FUN_0101ca14(unaff_r4 + 1,unaff_r5 + -1);
  }
  else if ((DAT_000201b4 == '\x02') && (*unaff_r4 == -0x5e)) {
    if ((unaff_r4[1] == '\x11') && ((unaff_r4[2] & 0xc0U) == 0xc0)) {
      if (DAT_0002018d != '\x01') {
        DAT_0002018d = '\x01';
        FUN_0101fa5c();
      }
      FUN_010200bc(unaff_r4[7],unaff_r4[8],0x2d,3);
    }
    else {
      DAT_0002018d = '\0';
    }
  }
  return;
}
#endif

/* 0101b472 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0101b472(void)
{
  _DAT_00020708 = _DAT_00020708 | 0x200;
  return;
}
#endif

/* 0101b482 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0101b482(void)
{
  _DAT_00020708 = _DAT_00020708 | 0x400;
  return;
}
#endif

/* 0101b4ac */
void FUN_0101b4ac(void)
{
  return;
}

/* 0101b4ae */
#ifdef NONMATCHING
void FUN_0101b4ae(void)
{
  set_vis(0,0);
  return;
}
#endif

/* 0101b4c0 */
#ifdef NONMATCHING
void FUN_0101b4c0(void)
{
  DAT_000f8523 = 0;
  DAT_000f8522 = DAT_000f8522 & 1;
  return;
}
#endif

/* 0101b4d8 */
#ifdef NONMATCHING
void FUN_0101b4d8(void)
{
  bt_disconnect();
  return;
}
#endif

/* 0101b4e0 */
#ifdef NONMATCHING
void FUN_0101b4e0(void)
{
  DAT_000201ea = 1;
  return;
}
#endif

/* 0101b4ec */
#ifdef NONMATCHING
void FUN_0101b4ec(void)
{
  FUN_01020354(0x800000);
  return;
}
#endif

/* 0101b4f8 */
#ifdef NONMATCHING
void FUN_0101b4f8(void)
{
  FUN_01020354(0x800000);
  return;
}
#endif
