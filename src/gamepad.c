/* gamepad.c: guessed: buttons, reports, the IPC queue, USB power */

#include "zero2.h"

/* 0101ca40 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 poll_buttons(void)
{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar1 = poll_flags();
  if (((uVar1 & 0x800000) != 0) && (iVar2 = FUN_0101def4(), iVar2 != 0)) {
    FUN_0101a9e0(0x800000);
    FUN_010232b0();
  }
  iVar2 = FUN_0101f0bc();
  if (iVar2 == 0) {
    _DAT_0002012c = 0;
    _DAT_000200dc = 0;
    DAT_000201b4 = DAT_000201b5;
    if (DAT_00020346 != '\0') {
      DAT_00020346 = '\0';
      FUN_01020354(0x800000);
    }
  }
  else {
    FUN_0101a92c();
    if (DAT_00020346 == '\0') {
      DAT_00020346 = '\x01';
      FUN_01020354(0x800000);
    }
    FUN_0101fba0();
    FUN_0101fc18();
  }
  if ((uVar1 & 0x3ff9) != 0) {
    FUN_0101a9e0(&DAT_00003ff9);
  }
  if ((uVar1 & 0x80000000) != 0) {
    FUN_0101f60c();
  }
  if ((uVar1 & 0x20000000) == 0) {
    if ((uVar1 & 0x10000000) != 0) {
      FUN_0101a9e0(0x10000000);
      FUN_01024d78();
      FUN_01020074();
    }
    if ((uVar1 & 0x1000000) != 0) {
      FUN_0101a9e0(0x1000000);
      FUN_01022af0();
    }
    iVar2 = FUN_0101ef84(0x32);
    iVar4 = FUN_0101ed1c();
    if ((iVar4 < 800) && (DAT_00020182 == '\x02')) {
      uVar3 = 0;
    }
    else {
      if (DAT_000201b4 == '\0') {
        if (((iVar2 != 0) && (_DAT_000200dc == 0)) && (iVar4 = FUN_010251b0(), iVar4 != 0)) {
          return 1;
        }
      }
      else if (DAT_000201b4 != '\x05') {
        if (DAT_000201b4 == '\x02') {
          if (((DAT_00020182 == '\x02') && (iVar2 != 0)) && (iVar4 = FUN_0101f7d4(), iVar4 != 0)) {
            return 1;
          }
        }
        else if (DAT_000201b4 == '\x03') {
          if (((DAT_00020182 == '\x02') && (iVar2 != 0)) && (iVar4 = FUN_0101be8c(), iVar4 != 0)) {
            return 1;
          }
        }
        else if ((((DAT_000201b4 == '\x01') && (DAT_00020182 == '\x02')) && (iVar2 != 0)) &&
                (uVar1 = battery_byte(), uVar1 != DAT_00020345)) {
          DAT_00020345 = battery_byte();
          send_battery_report(DAT_00020345);
          return 1;
        }
      }
      if ((iVar2 == 0) && (DAT_00020182 == '\x02')) {
        FUN_01020544();
      }
      else {
        _DAT_00020334 = FUN_0101f718();
        _DAT_00020338 = 0xffffffff;
        _DAT_0002033c = 0xffffffff;
      }
      if ((DAT_000201b8 == '\0') && (_DAT_00020334 != 0xffffffff)) {
        _DAT_00020334 = FUN_0101de3c(_DAT_00020334);
        if ((_DAT_00020340 == _DAT_00020334) &&
           ((iVar2 = FUN_0101f09c(), iVar2 == 0 && ((_DAT_00020334 & 0xc000) == 0)))) {
          _DAT_00020334 = 0xffffffff;
        }
        else {
          _DAT_00020340 = _DAT_00020334;
        }
      }
      if ((DAT_000201b4 == '\0') && (_DAT_000200dc == 0)) {
        _DAT_0002032a = 0x10;
      }
      else if ((DAT_000201b4 == '\x02') && (DAT_00020658 == '\x01')) {
        _DAT_0002032a = 1;
      }
      else if (_DAT_00020348 != _DAT_00020334) {
        _DAT_00020348 = _DAT_00020334;
        _DAT_0002032a = 0x10;
      }
      if (_DAT_0002032a != 0) {
        _DAT_0002032a = _DAT_0002032a + -1;
        report_build(_DAT_00020334,_DAT_00020338,_DAT_0002033c);
      }
      FUN_0101cd48();
      FUN_0101dbcc();
      if ((_DAT_00020334 == 0xffffffff) || (_DAT_00020334 == _DAT_00020154)) {
        if ((DAT_00021864 == '\0') || (_DAT_0002186c == 0)) {
          uVar3 = 0;
        }
        else {
          uVar3 = 1;
        }
      }
      else {
        _DAT_00020154 = _DAT_00020334;
        uVar3 = 1;
      }
    }
  }
  else {
    FUN_0101c8d4(DAT_000201b6);
    FUN_0101a9e0(0x20000000);
    uVar3 = 1;
  }
  return uVar3;
}
#endif

/* 0101cd48 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0101cd48(void)
{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_0101fb14();
  if (iVar1 != 0) {
    if (DAT_00020182 == '\x02') {
      uVar2 = FUN_0101c6cc();
      if (_DAT_000201d8 + 0x15eU < uVar2) {
        if ((DAT_000201d1 & 1) == 0) {
          _DAT_000201d8 = FUN_0101c6cc();
        }
        else {
          DAT_000201d1 = DAT_000201d1 & 0xfe;
        }
      }
    }
    else {
      _DAT_000201d8 = FUN_0101c6cc();
    }
  }
  return;
}
#endif

/* 0101cda4 */
#ifdef NONMATCHING
void FUN_0101cda4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)
{
  report3_build(param_1,param_2,param_4,param_5);
  return;
}
#endif

/* 0101cdc8 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_0101cdc8(uint param_1,uint param_2,undefined4 param_3,int param_4)
{
  uint uVar1;
  uint uVar2;
  
  if (((param_1 & 8) == 8) &&
     ((((param_2 & 0xff00) == 0xff00 || ((param_2 & 0xff000000) == 0xff000000)) ||
      ((param_1 & 0x100) == 0x100)))) {
    param_2 = 0x7f7f7f7f;
    param_1 = param_1 & 0xfffffef7 | 0x20000;
  }
  uVar2 = param_1 & 0x3c0;
  uVar1 = param_2 & 0xff;
  if ((uVar1 != 0x7f) && (uVar1 != 0x80)) {
    *(char *)(param_4 + 3) = (char)param_2;
    if (uVar1 == 0) {
      *(undefined1 *)(param_4 + 2) = 0;
    }
    else {
      *(undefined1 *)(param_4 + 2) = 0xff;
    }
  }
  uVar1 = (param_2 & 0xffff) >> 8;
  if ((uVar1 != 0x7f) && (uVar1 != 0x80)) {
    *(char *)(param_4 + 5) = (char)((param_2 & 0xffff) >> 8);
    if (uVar1 == 0) {
      *(undefined1 *)(param_4 + 4) = 0;
    }
    else {
      *(undefined1 *)(param_4 + 4) = 0xff;
    }
  }
  uVar1 = (param_2 & 0xffffff) >> 0x10;
  if ((uVar1 != 0x7f) && (uVar1 != 0x80)) {
    *(char *)(param_4 + 7) = (char)((param_2 & 0xffffff) >> 0x10);
    if (uVar1 == 0) {
      *(undefined1 *)(param_4 + 6) = 0;
    }
    else {
      *(undefined1 *)(param_4 + 6) = 0xff;
    }
  }
  uVar1 = param_2 >> 0x18;
  if ((uVar1 != 0x7f) && (uVar1 != 0x80)) {
    *(char *)(param_4 + 9) = (char)(param_2 >> 0x18);
    if (uVar1 == 0) {
      *(undefined1 *)(param_4 + 8) = 0;
    }
    else {
      *(undefined1 *)(param_4 + 8) = 0xff;
    }
  }
  if (uVar2 == 0x200) {
    *(undefined1 *)(param_4 + 0xe) = 1;
  }
  else if (uVar2 == 0x100) {
    *(undefined1 *)(param_4 + 0xe) = 5;
  }
  else if (uVar2 == 0x80) {
    *(undefined1 *)(param_4 + 0xe) = 7;
  }
  else if (uVar2 == 0x40) {
    *(undefined1 *)(param_4 + 0xe) = 3;
  }
  else if (uVar2 == 0x280) {
    *(undefined1 *)(param_4 + 0xe) = 8;
  }
  else if (uVar2 == 0x240) {
    *(undefined1 *)(param_4 + 0xe) = 2;
  }
  else if (uVar2 == 0x180) {
    *(undefined1 *)(param_4 + 0xe) = 6;
  }
  else if (uVar2 == 0x140) {
    *(undefined1 *)(param_4 + 0xe) = 4;
  }
  else {
    *(undefined1 *)(param_4 + 0xe) = 0;
  }
  if ((param_1 & 0x10) != 0) {
    *(byte *)(param_4 + 0xf) = *(byte *)(param_4 + 0xf) | 8;
  }
  if ((param_1 & 0x2000) != 0) {
    *(byte *)(param_4 + 0xf) = *(byte *)(param_4 + 0xf) | 2;
  }
  if ((param_1 & 0x1000) != 0) {
    *(byte *)(param_4 + 0xf) = *(byte *)(param_4 + 0xf) | 1;
  }
  if ((param_1 & 0x20) != 0) {
    *(byte *)(param_4 + 0xf) = *(byte *)(param_4 + 0xf) | 4;
  }
  if ((param_1 & 0x400) != 0) {
    *(byte *)(param_4 + 0xf) = *(byte *)(param_4 + 0xf) | 0x10;
  }
  if ((param_1 & 0x800) != 0) {
    *(byte *)(param_4 + 0xf) = *(byte *)(param_4 + 0xf) | 0x20;
  }
  if ((param_1 & 0x4000) != 0) {
    *(undefined1 *)(param_4 + 10) = 0xff;
    *(undefined1 *)(param_4 + 0xb) = 3;
  }
  if ((param_1 & 2) != 0) {
    *(byte *)(param_4 + 0x10) = *(byte *)(param_4 + 0x10) | 1;
  }
  if ((param_1 & 4) != 0) {
    *(byte *)(param_4 + 0x10) = *(byte *)(param_4 + 0x10) | 2;
  }
  if ((param_1 & 0x8000) != 0) {
    *(undefined1 *)(param_4 + 0xc) = 0xff;
    *(undefined1 *)(param_4 + 0xd) = 3;
  }
  if ((param_1 & 8) != 0) {
    *(byte *)(param_4 + 0xf) = *(byte *)(param_4 + 0xf) | 0x40;
  }
  if ((param_1 & 1) != 0) {
    *(byte *)(param_4 + 0xf) = *(byte *)(param_4 + 0xf) | 0x80;
  }
  uVar1 = _DAT_000201f8 & 0x20000;
  _DAT_000201f8 = param_1;
  return (param_1 & 0x20000) != uVar1;
}
#endif

/* 0101cfe8 */
#ifdef NONMATCHING
/* WARNING: Removing unreachable block (ram,0x0101d002) */
/* WARNING: Removing unreachable block (ram,0x0101d048) */
/* WARNING: Removing unreachable block (ram,0x0101d032) */
/* WARNING: Removing unreachable block (ram,0x0101d03e) */
/* WARNING: Removing unreachable block (ram,0x0101d034) */
/* WARNING: Removing unreachable block (ram,0x0101d04a) */
/* WARNING: Removing unreachable block (ram,0x0101d04e) */
/* WARNING: Removing unreachable block (ram,0x0101d056) */
/* WARNING: Removing unreachable block (ram,0x0101d05a) */
/* WARNING: Removing unreachable block (ram,0x0101d090) */
/* WARNING: Removing unreachable block (ram,0x0101d06a) */
/* WARNING: Removing unreachable block (ram,0x0101d07e) */
/* WARNING: Removing unreachable block (ram,0x0101d070) */
/* WARNING: Removing unreachable block (ram,0x0101d094) */
/* WARNING: Removing unreachable block (ram,0x0101d09a) */
/* WARNING: Removing unreachable block (ram,0x0101d0a4) */
/* WARNING: Removing unreachable block (ram,0x0101d0ac) */
/* WARNING: Removing unreachable block (ram,0x0101d0de) */
/* WARNING: Removing unreachable block (ram,0x0101d0c0) */
/* WARNING: Removing unreachable block (ram,0x0101d0d2) */
/* WARNING: Removing unreachable block (ram,0x0101d0c6) */
/* WARNING: Removing unreachable block (ram,0x0101d0e2) */
/* WARNING: Removing unreachable block (ram,0x0101d0e8) */
/* WARNING: Removing unreachable block (ram,0x0101d0f2) */
/* WARNING: Removing unreachable block (ram,0x0101d0fa) */
/* WARNING: Removing unreachable block (ram,0x0101d138) */
/* WARNING: Removing unreachable block (ram,0x0101d112) */
/* WARNING: Removing unreachable block (ram,0x0101d126) */
/* WARNING: Removing unreachable block (ram,0x0101d118) */
/* WARNING: Removing unreachable block (ram,0x0101d13c) */
/* WARNING: Removing unreachable block (ram,0x0101d142) */
/* WARNING: Removing unreachable block (ram,0x0101d14c) */
/* WARNING: Removing unreachable block (ram,0x0101d154) */
/* WARNING: Removing unreachable block (ram,0x0101d178) */
/* WARNING: Removing unreachable block (ram,0x0101d182) */
/* WARNING: Removing unreachable block (ram,0x0101d16e) */
/* WARNING: Removing unreachable block (ram,0x0101d18a) */
/* WARNING: Removing unreachable block (ram,0x0101d19c) */
/* WARNING: Removing unreachable block (ram,0x0101d1a4) */
/* WARNING: Removing unreachable block (ram,0x0101d192) */
/* WARNING: Removing unreachable block (ram,0x0101d1ac) */
/* WARNING: Removing unreachable block (ram,0x0101d1b4) */
/* WARNING: Removing unreachable block (ram,0x0101d1bc) */
/* WARNING: Removing unreachable block (ram,0x0101d1c6) */
/* WARNING: Removing unreachable block (ram,0x0101d1ce) */
/* WARNING: Removing unreachable block (ram,0x0101d1d8) */
/* WARNING: Removing unreachable block (ram,0x0101d1e0) */
/* WARNING: Removing unreachable block (ram,0x0101d1e8) */
/* WARNING: Removing unreachable block (ram,0x0101d1f0) */
/* WARNING: Removing unreachable block (ram,0x0101d1fa) */
/* WARNING: Removing unreachable block (ram,0x0101d202) */
/* WARNING: Removing unreachable block (ram,0x0101d20c) */
/* WARNING: Removing unreachable block (ram,0x0101d214) */
/* WARNING: Removing unreachable block (ram,0x0101d21e) */
/* WARNING: Removing unreachable block (ram,0x0101d222) */
/* WARNING: Removing unreachable block (ram,0x0101d22c) */
/* WARNING: Removing unreachable block (ram,0x0101d230) */
/* WARNING: Removing unreachable block (ram,0x0101d238) */
/* WARNING: Removing unreachable block (ram,0x0101d240) */
/* WARNING: Removing unreachable block (ram,0x0101d248) */
/* WARNING: Removing unreachable block (ram,0x0101d250) */
/* WARNING: Removing unreachable block (ram,0x0101d258) */
/* WARNING: Removing unreachable block (ram,0x0101d260) */
/* WARNING: Removing unreachable block (ram,0x0101d268) */
/* WARNING: Removing unreachable block (ram,0x0101d270) */
/* WARNING: Removing unreachable block (ram,0x0101d27a) */
/* WARNING: Removing unreachable block (ram,0x0101d282) */

void FUN_0101cfe8(uint param_1,undefined4 param_2,undefined4 param_3,byte *param_4)
{
  uint uVar1;
  undefined4 local_20;
  undefined4 uStack_1c;
  byte *pbStack_18;
  
  uVar1 = param_1 & 0x3c0;
  local_20 = param_2;
  uStack_1c = param_3;
  pbStack_18 = param_4;
  memcpy(param_4,&DAT_01028111,0x1b);
  memcpy(param_4 + 3,&local_20,4);
  if (uVar1 == 0x200) {
    param_4[2] = 0;
  }
  else if (uVar1 == 0x100) {
    param_4[2] = 4;
  }
  else if (uVar1 == 0x80) {
    param_4[2] = 6;
  }
  else if (uVar1 == 0x40) {
    param_4[2] = 2;
  }
  else if (uVar1 == 0x280) {
    param_4[2] = 7;
  }
  else if (uVar1 == 0x240) {
    param_4[2] = 1;
  }
  else if (uVar1 == 0x180) {
    param_4[2] = 5;
  }
  else if (uVar1 == 0x140) {
    param_4[2] = 3;
  }
  if ((param_1 & 0x10) != 0) {
    *param_4 = *param_4 | 8;
  }
  if ((param_1 & 0x2000) != 0) {
    *param_4 = *param_4 | 1;
  }
  if ((param_1 & 0x1000) != 0) {
    *param_4 = *param_4 | 2;
  }
  if ((param_1 & 0x20) != 0) {
    *param_4 = *param_4 | 0x10;
  }
  if ((param_1 & 0x400) != 0) {
    *param_4 = *param_4 | 0x40;
  }
  if ((param_1 & 0x800) != 0) {
    *param_4 = *param_4 | 0x80;
  }
  if ((param_1 & 0x4000) != 0) {
    param_4[1] = param_4[1] | 1;
  }
  if ((param_1 & 0x8000) != 0) {
    param_4[1] = param_4[1] | 2;
  }
  if ((param_1 & 2) != 0) {
    param_4[1] = param_4[1] | 0x20;
  }
  if ((param_1 & 4) != 0) {
    param_4[1] = param_4[1] | 0x40;
  }
  if ((param_1 & 8) != 0) {
    param_4[1] = param_4[1] | 4;
  }
  if ((param_1 & 1) != 0) {
    param_4[1] = param_4[1] | 8;
  }
  if ((param_1 & 0x20000) != 0) {
    param_4[1] = param_4[1] | 0x10;
  }
  return;
}
#endif

/* 0101d3e4 */
#ifdef NONMATCHING
void FUN_0101d3e4(uint param_1,uint param_2,undefined1 *param_3)
{
  undefined1 uVar1;
  uint uVar2;
  uint uVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  ushort uVar7;
  uint uVar8;
  uint local_30;
  uint local_2c;
  
  uVar2 = param_2 & 0xff;
  uVar5 = (param_2 & 0xffff) >> 8;
  uVar3 = (param_2 & 0xffffff) >> 0x10;
  param_2 = param_2 >> 0x18;
  if (((param_1 & 8) == 8) && (((uVar5 == 0 || (param_2 == 0)) || ((param_1 & 0x100) == 0x100)))) {
    param_1 = param_1 & 0xfffffef7 | 0x20000;
  }
  if ((DAT_00020777 == '0') || (DAT_00020777 == '1')) {
    local_2c = uVar2 << 4;
    uVar6 = uVar5 * 0x10;
    local_30 = uVar3 << 4;
    uVar8 = param_2 * 0x10;
    if (uVar2 != 0) {
      local_2c = local_2c | 0xf;
    }
    if (uVar5 != 0) {
      uVar6 = uVar6 | 0xf;
    }
    if (uVar3 != 0) {
      local_30 = local_30 | 0xf;
    }
    if (param_2 != 0) {
      uVar8 = uVar8 | 0xf;
    }
    uVar1 = param_3[2];
    memcpy(param_3,&DAT_010282df,0xe);
    *param_3 = 0xa1;
    param_3[1] = DAT_00020777;
    param_3[2] = uVar1;
    if ((param_1 & 0x200) != 0) {
      param_3[6] = (param_3[6] & 0xfd) + 2;
    }
    if ((param_1 & 0x100) != 0) {
      param_3[6] = (param_3[6] & 0xfe) + 1;
    }
    if ((param_1 & 0x80) != 0) {
      param_3[6] = (param_3[6] & 0xf7) + 8;
    }
    if ((param_1 & 0x40) != 0) {
      param_3[6] = (param_3[6] & 0xfb) + 4;
    }
    if ((param_1 & 0x2000) != 0) {
      param_3[4] = (param_3[4] & 0xf7) + 8;
    }
    if ((param_1 & 0x1000) != 0) {
      param_3[4] = (param_3[4] & 0xfb) + 4;
    }
    if ((param_1 & 0x10) != 0) {
      param_3[4] = (param_3[4] & 0xfd) + 2;
    }
    if ((param_1 & 0x20) != 0) {
      param_3[4] = (param_3[4] & 0xfe) + 1;
    }
    if ((param_1 & 0x400) != 0) {
      param_3[6] = (param_3[6] & 0xbf) + 0x40;
    }
    if ((param_1 & 0x800) != 0) {
      param_3[4] = (param_3[4] & 0xbf) + 0x40;
    }
    if ((param_1 & 0x4000) != 0) {
      param_3[6] = (param_3[6] & 0x7f) + 0x80;
    }
    if ((param_1 & 0x8000) != 0) {
      param_3[4] = (param_3[4] & 0x7f) + 0x80;
    }
    if ((param_1 & 2) != 0) {
      param_3[5] = (param_3[5] & 0xf7) + 8;
    }
    if ((param_1 & 4) != 0) {
      param_3[5] = (param_3[5] & 0xfb) + 4;
    }
    if ((param_1 & 8) != 0) {
      param_3[5] = (param_3[5] & 0xfe) + 1;
    }
    if ((param_1 & 1) != 0) {
      param_3[5] = (param_3[5] & 0xfd) + 2;
    }
    if ((param_1 & 0x20000) != 0) {
      param_3[5] = (param_3[5] & 0xef) + 0x10;
    }
    if ((param_1 & 0x10000) != 0) {
      param_3[5] = (param_3[5] & 0xdf) + 0x20;
    }
    if (DAT_000201b8 != '\0') {
      if ((param_1 & 0x80000000) != 0) {
        param_3[5] = (param_3[5] & 0x7f) + 0x80;
      }
      if (DAT_00020332 == '\0') {
        param_3[4] = (param_3[4] & 0xef) + 0x10;
      }
      else if (DAT_00020332 == '\x03') {
        param_3[4] = (param_3[4] & 0xdf) + 0x20;
      }
      else if (DAT_00020332 == '\x04') {
        param_3[5] = (param_3[5] & 0xbf) + 0x40;
      }
    }
    param_3[7] = param_3[7] & 0xf0 | (byte)local_2c & 0xf;
    uVar2 = *(ushort *)(param_3 + 7) & 0xfffff00f | ((int)local_2c >> 4) << 4;
    param_3[7] = (char)uVar2;
    param_3[8] = (char)(uVar2 >> 8);
    param_3[8] = param_3[8] & 0xf | (byte)((uVar6 & 0xf) << 4);
    param_3[9] = (char)(uVar6 >> 4);
    param_3[10] = param_3[10] & 0xf0 | (byte)local_30 & 0xf;
    uVar2 = ((int)local_30 >> 4) << 4 | *(ushort *)(param_3 + 10) & 0xfffff00f;
    param_3[10] = (char)uVar2;
    param_3[0xb] = (char)(uVar2 >> 8);
    param_3[0xb] = param_3[0xb] & 0xf | (byte)((uVar8 & 0xf) << 4);
    param_3[0xc] = (char)(uVar8 >> 4);
  }
  else if (DAT_00020777 == '?') {
    uVar6 = param_1 & 0x3c0;
    local_2c._0_2_ = (ushort)(uVar2 << 8);
    uVar5 = uVar5 * 0x100;
    local_30._0_2_ = (ushort)(uVar3 << 8);
    param_2 = param_2 * 0x100;
    if (uVar5 == 0x7f) {
      uVar5 = 0x80;
    }
    uVar4 = (ushort)~uVar5;
    if (param_2 == 0x7f) {
      param_2 = 0x80;
    }
    uVar7 = (ushort)~param_2;
    if (uVar2 != 0) {
      local_2c._0_2_ = (ushort)local_2c | 0xff;
    }
    if ((~uVar5 & 0xffff) != 0) {
      uVar4 = uVar4 | 0xff;
    }
    if (uVar3 != 0) {
      local_30._0_2_ = (ushort)local_30 | 0xff;
    }
    if ((~param_2 & 0xffff) != 0) {
      uVar7 = uVar7 | 0xff;
    }
    memcpy(param_3,&DAT_010282d2,0xe);
    *param_3 = 0xa1;
    param_3[1] = DAT_00020777;
    if (uVar6 == 0x200) {
      param_3[4] = param_3[4] & 0xf0;
    }
    else if (uVar6 == 0x240) {
      param_3[4] = (param_3[4] & 0xf0) + 1;
    }
    else if (uVar6 == 0x40) {
      param_3[4] = (param_3[4] & 0xf0) + 2;
    }
    else if (uVar6 == 0x140) {
      param_3[4] = (param_3[4] & 0xf0) + 3;
    }
    else if (uVar6 == 0x100) {
      param_3[4] = (param_3[4] & 0xf0) + 4;
    }
    else if (uVar6 == 0x180) {
      param_3[4] = (param_3[4] & 0xf0) + 5;
    }
    else if (uVar6 == 0x80) {
      param_3[4] = (param_3[4] & 0xf0) + 6;
    }
    else if (uVar6 == 0x280) {
      param_3[4] = (param_3[4] & 0xf0) + 7;
    }
    else {
      param_3[4] = (param_3[4] & 0xf0) + 8;
    }
    if ((param_1 & 0x2000) != 0) {
      param_3[2] = (param_3[2] & 0xfd) + 2;
    }
    if ((param_1 & 0x1000) != 0) {
      param_3[2] = (param_3[2] & 0xfe) + 1;
    }
    if ((param_1 & 0x10) != 0) {
      param_3[2] = (param_3[2] & 0xf7) + 8;
    }
    if ((param_1 & 0x20) != 0) {
      param_3[2] = (param_3[2] & 0xfb) + 4;
    }
    if ((param_1 & 0x400) != 0) {
      param_3[2] = (param_3[2] & 0xef) + 0x10;
    }
    if ((param_1 & 0x800) != 0) {
      param_3[2] = (param_3[2] & 0xdf) + 0x20;
    }
    if ((param_1 & 0x4000) != 0) {
      param_3[2] = (param_3[2] & 0xbf) + 0x40;
    }
    if ((param_1 & 0x8000) != 0) {
      param_3[2] = (param_3[2] & 0x7f) + 0x80;
    }
    if ((param_1 & 2) != 0) {
      param_3[3] = (param_3[3] & 0xfb) + 4;
    }
    if ((param_1 & 4) != 0) {
      param_3[3] = (param_3[3] & 0xf7) + 8;
    }
    if ((param_1 & 8) != 0) {
      param_3[3] = (param_3[3] & 0xfe) + 1;
    }
    if ((param_1 & 1) != 0) {
      param_3[3] = (param_3[3] & 0xfd) + 2;
    }
    if ((param_1 & 0x20000) != 0) {
      param_3[3] = (param_3[3] & 0xef) + 0x10;
    }
    if ((param_1 & 0x10000) != 0) {
      param_3[3] = (param_3[3] & 0xdf) + 0x20;
    }
    param_3[5] = (char)(ushort)local_2c;
    param_3[6] = (char)((ushort)local_2c >> 8);
    param_3[7] = (char)uVar4;
    param_3[8] = (char)(uVar4 >> 8);
    param_3[9] = (char)(ushort)local_30;
    param_3[10] = (char)((ushort)local_30 >> 8);
    param_3[0xb] = (char)uVar7;
    param_3[0xc] = (char)(uVar7 >> 8);
  }
  return;
}
#endif

/* 0101d964 */
#ifdef NONMATCHING
void FUN_0101d964(uint param_1,uint param_2,undefined4 param_3,int param_4)
{
  uint uVar1;
  uint local_20;
  undefined4 uStack_1c;
  int iStack_18;
  
  local_20 = param_2;
  if (((param_1 & 8) == 8) &&
     ((((param_2 & 0xff00) == 0xff00 || ((param_2 & 0xff000000) == 0xff000000)) ||
      ((param_1 & 0x100) == 0x100)))) {
    local_20 = 0x7f7f7f7f;
    param_1 = param_1 & 0xfffffef7 | 0x20000;
  }
  uVar1 = param_1 & 0x3c0;
  uStack_1c = param_3;
  iStack_18 = param_4;
  memcpy(param_4 + 1,&local_20,4);
  if (uVar1 == 0x200) {
    *(undefined1 *)(param_4 + 5) = 0;
  }
  else if (uVar1 == 0x100) {
    *(undefined1 *)(param_4 + 5) = 4;
  }
  else if (uVar1 == 0x80) {
    *(undefined1 *)(param_4 + 5) = 6;
  }
  else if (uVar1 == 0x40) {
    *(undefined1 *)(param_4 + 5) = 2;
  }
  else if (uVar1 == 0x280) {
    *(undefined1 *)(param_4 + 5) = 7;
  }
  else if (uVar1 == 0x240) {
    *(undefined1 *)(param_4 + 5) = 1;
  }
  else if (uVar1 == 0x180) {
    *(undefined1 *)(param_4 + 5) = 5;
  }
  else if (uVar1 == 0x140) {
    *(undefined1 *)(param_4 + 5) = 3;
  }
  else {
    *(undefined1 *)(param_4 + 5) = 8;
  }
  if ((param_1 & 0x10) != 0) {
    *(byte *)(param_4 + 5) = *(byte *)(param_4 + 5) | 0x80;
  }
  if ((param_1 & 0x2000) != 0) {
    *(byte *)(param_4 + 5) = *(byte *)(param_4 + 5) | 0x40;
  }
  if ((param_1 & 0x1000) != 0) {
    *(byte *)(param_4 + 5) = *(byte *)(param_4 + 5) | 0x20;
  }
  if ((param_1 & 0x20) != 0) {
    *(byte *)(param_4 + 5) = *(byte *)(param_4 + 5) | 0x10;
  }
  if ((param_1 & 0x400) != 0) {
    *(byte *)(param_4 + 6) = *(byte *)(param_4 + 6) | 1;
  }
  if ((param_1 & 0x800) != 0) {
    *(byte *)(param_4 + 6) = *(byte *)(param_4 + 6) | 2;
  }
  if ((param_1 & 0x4000) != 0) {
    *(byte *)(param_4 + 6) = *(byte *)(param_4 + 6) | 4;
    *(undefined1 *)(param_4 + 8) = 0xff;
  }
  if ((param_1 & 0x8000) != 0) {
    *(byte *)(param_4 + 6) = *(byte *)(param_4 + 6) | 8;
    *(undefined1 *)(param_4 + 9) = 0xff;
  }
  if ((param_1 & 2) != 0) {
    *(byte *)(param_4 + 6) = *(byte *)(param_4 + 6) | 0x40;
  }
  if ((param_1 & 4) != 0) {
    *(byte *)(param_4 + 6) = *(byte *)(param_4 + 6) | 0x80;
  }
  if ((param_1 & 8) != 0) {
    if ((param_1 & 0x100) == 0) {
      *(byte *)(param_4 + 6) = *(byte *)(param_4 + 6) | 0x10;
    }
    else {
      *(byte *)(param_4 + 7) = *(byte *)(param_4 + 7) | 1;
    }
  }
  if ((param_1 & 1) != 0) {
    *(byte *)(param_4 + 6) = *(byte *)(param_4 + 6) | 0x20;
  }
  if ((param_1 & 0x20000) == 0) {
    *(byte *)(param_4 + 7) = *(byte *)(param_4 + 7) & 0xfe;
  }
  else {
    *(byte *)(param_4 + 7) = *(byte *)(param_4 + 7) | 1;
  }
  return;
}
#endif

/* 0101db3c */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void power_off_idle(void)
{
  uint uVar1;
  int iVar2;
  
  uVar1 = FUN_0101c44c();
  if (_DAT_00020194 <= uVar1) {
    if ((DAT_000201b8 == '\0') || (DAT_00020182 != '\x02')) {
      iVar2 = usb_powered();
      if (iVar2 == 0) {
        FUN_01020350(10);
        FUN_01024d0c(0);
        if (DAT_00020182 == '\x02') {
          FUN_0101a818(100,0);
        }
        else {
          GPIO_ResetBits(2,4);
          rom_delay_a(500);
        }
        if (DAT_000206b2 == '\0') {
          GPIO_SetBits(2,4);
          FUN_010232b0();
        }
        else {
          FUN_010200be();
        }
      }
      else {
        FUN_010232b0();
      }
    }
    else {
      FUN_010232b0();
    }
  }
  return;
}
#endif

/* 0101dbcc */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0101dbcc(void)
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar1 = FUN_0101fb08();
  uVar2 = uVar1 & 0xffe7ffff;
  if ((uVar1 & 0xdfe7ffff) == 1) {
    _DAT_000201de = _DAT_000201de + 1;
    if (_DAT_000201e4 == 0) {
      _DAT_000201e4 = _DAT_00020008;
    }
    if (((_DAT_000201e4 + 3000 <= _DAT_00020008) || (DAT_000201b8 != '\0')) &&
       (FUN_0101a818(100,uVar2), DAT_000201b8 == '\0')) {
      _DAT_000201de = 0;
    }
  }
  else {
    _DAT_000201de = 0;
    _DAT_000201e4 = _DAT_00020008;
    if ((DAT_000201b8 != '\0') && (_DAT_000201ec != 0)) {
      _DAT_000201ec = 0;
      led_set(7,0);
      FUN_010247c4();
    }
  }
  if (DAT_000201b8 == '\0') {
    if (uVar2 == 8) {
      if (DAT_0002030c == '\0') {
        _DAT_000201e0 = _DAT_000201e0 + 1;
      }
      uVar3 = FUN_01023fb8(1000);
      if (uVar3 < _DAT_000201e0) {
        iVar4 = usb_powered();
        if (iVar4 == 0) {
          if (DAT_00020182 == '\x02') {
            FUN_010203b0();
            FUN_010249e6();
          }
          else {
            FUN_010203c0();
            restart();
          }
        }
        _DAT_000201e0 = 0;
        DAT_0002030c = '\x01';
      }
    }
    else {
      _DAT_000201e0 = 0;
      DAT_0002030c = '\0';
    }
  }
  if ((DAT_000201b4 != '\x04') && ((DAT_00020658 == '\0' || (DAT_00020182 != '\x02')))) {
    if ((uVar2 == 0x208) || ((uVar2 == 0x88 || (uVar2 == 0x48)))) {
      if (_DAT_00020310 + 4000 <= _DAT_00020008) {
        _DAT_00020310 = 0xffff0000;
        if ((uVar1 & 0x3c0) != (uint)_DAT_0002015a) {
          _DAT_0002015a = (ushort)uVar1 & 0x3c0;
          FUN_01022ca4(DAT_000201b4);
        }
        FUN_010247e8();
      }
    }
    else {
      _DAT_00020310 = _DAT_00020008;
    }
  }
  if ((DAT_000201b4 != '\x04') && ((DAT_00020658 == '\0' || (DAT_00020182 != '\x02')))) {
    uVar1 = FUN_01023f04();
    if (uVar2 == 0x108) {
      if (_DAT_00020314 + 500 <= uVar1) {
        _DAT_00020314 = 0xfffffdfc;
        DAT_0002015c = DAT_0002015c == '\0';
        FUN_01022ca4(DAT_000201b4);
        FUN_010247e8();
      }
    }
    else {
      _DAT_00020314 = uVar1;
    }
  }
  FUN_010204bc(uVar2);
  iVar4 = FUN_0101f098();
  if (iVar4 == 0) {
    iVar4 = FUN_0101fa34();
    if (iVar4 == 0) {
      iVar4 = FUN_0101f0bc();
      if (iVar4 == 0) {
        GPIO_ResetBits(2,4);
        rom_delay_a(0x1e);
      }
    }
    else {
      rom_delay_a(1);
      iVar4 = FUN_0101fa34();
      if (iVar4 != 0) {
        FUN_01020354(0x100000);
        iVar4 = usb_powered();
        if (iVar4 == 0) {
          FUN_01024d0c(1);
        }
      }
    }
  }
  FUN_0101aa24(uVar2);
  return;
}
#endif

/* 0101de3c */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0101de3c(uint param_1)
{
  int iVar1;
  uint uVar2;
  
  if (_DAT_0002186c != 0) {
    if (((_DAT_0002186c & param_1) == 0) && (iVar1 = FUN_01022820(), iVar1 == 0)) {
      _DAT_00021870 = _DAT_0002186c;
      DAT_00021864 = '\0';
      _DAT_00021874 = 0;
      _DAT_00021876 = 0;
      FUN_01020352();
      _DAT_00020304 = 0;
      memzero(&DAT_0002187c,0x3c);
    }
    else {
      if (DAT_00021864 == '\0') {
        DAT_00021864 = '\x01';
        iVar1 = FUN_0101ef2c();
        if (iVar1 != 0) {
          FUN_0101c190(param_1);
        }
      }
      iVar1 = FUN_0101ef2c();
      uVar2 = param_1;
      if (iVar1 != 0) {
        uVar2 = param_1 | _DAT_00021880;
        _DAT_0002187c = param_1;
      }
      param_1 = uVar2 & ~_DAT_0002186c | _DAT_00021870 & _DAT_0002186c & uVar2;
    }
  }
  return param_1;
}
#endif

/* 0101ded0 */
#ifdef NONMATCHING
void FUN_0101ded0(void)
{
  if (DAT_00020181 != '\x03') {
    DAT_00020181 = '\x03';
    FUN_01020374();
    FUN_0101a9e0(0x800000);
  }
  return;
}
#endif

/* 0101def4 */
#ifdef NONMATCHING
undefined4 FUN_0101def4(void)
{
  int iVar1;
  
  iVar1 = FUN_0101f0bc();
  if (iVar1 == 0) {
    if (((DAT_00020181 == '\x03') || (DAT_00020181 == '\x02')) || (DAT_00020181 == '\x05')) {
      FUN_0101e01c();
      iVar1 = FUN_0101c6d8(0x8000);
      if ((iVar1 != 0) && (DAT_00020182 == '\x02')) {
        power_off();
      }
      FUN_0101aa14(0xffff);
      DAT_0002017f = 0;
      idle_limit_set();
      DAT_00020184 = 0;
      FUN_01022e8c();
      FUN_0101f7d2();
      FUN_0101a9e0(0x40000000);
      if (DAT_000201b8 != '\0') {
        FUN_0101b242(10);
        FUN_0101f940(5,5,2000,10,5);
      }
      if (DAT_000201b8 == '\0') {
        if (DAT_000201b4 == '\0') {
          FUN_0102059c();
          FUN_01024d78();
        }
        iVar1 = FUN_0101f098();
        if (iVar1 != 0) {
          Create_BtConnection();
        }
      }
    }
    else if (DAT_00020181 != '\0') {
      FUN_0101e01c();
    }
  }
  else {
    FUN_0101b274();
    iVar1 = FUN_0101c6d8(0x8000);
    if ((iVar1 != 0) && (DAT_00020182 == '\x02')) {
      return 0;
    }
    if ((DAT_00020181 == '\0') || (DAT_00020181 == '\x05')) {
      FUN_01022e8c();
      FUN_0101e008();
      DAT_00020184 = 1;
      return 0;
    }
  }
  return 1;
}
#endif

/* 0101e01c */
#ifdef NONMATCHING
void FUN_0101e01c(void)
{
  FUN_0101b242(10);
  DAT_00020181 = 0;
  FUN_010232b0();
  FUN_01024ad0();
  FUN_0101aa14(0x7fff);
  DAT_00020184 = 0;
  FUN_0101f7d2();
  return;
}
#endif

/* 0101e2fc */
#ifdef NONMATCHING
int FUN_0101e2fc(uint param_1,undefined4 param_2,undefined4 param_3,undefined1 *param_4,int param_5)
{
  char cVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  uint local_2c;
  uint local_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined1 *local_18;
  
  local_24 = param_1;
  uStack_20 = param_2;
  uStack_1c = param_3;
  local_18 = param_4;
  iVar2 = FUN_0101e41c(&local_24,param_4,param_5);
  if ((iVar2 == 0) && (iVar2 = FUN_0101e598(&local_24,local_18,param_5), iVar2 == 0)) {
    memzero(local_18,10);
    if (param_5 == 2) {
      *param_4 = 0xa1;
      param_4[1] = 1;
      param_4 = param_4 + 2;
    }
    *param_4 = 0;
    param_4[1] = 0;
    pcVar3 = param_4 + 2;
    if (local_24 != 0) {
      uVar4 = 0;
      while ((uVar4 < 0x10 && (pcVar3 < param_4 + 8))) {
        if ((local_24 & *(uint *)(uVar4 * 0xc + 0x201fc)) != 0) {
          for (local_2c = 0; local_2c < 4; local_2c = local_2c + 1 & 0xff) {
            cVar1 = *(char *)(uVar4 * 0xc + 0x20202 + local_2c);
            if (cVar1 != '\0') {
              if (cVar1 == -0x20) {
                *param_4 = 1;
              }
              else if (cVar1 == -0x1f) {
                *param_4 = 2;
              }
              else if (cVar1 == -0x1e) {
                *param_4 = 4;
              }
              else if (cVar1 == -0x1d) {
                *param_4 = 8;
              }
              else if (cVar1 == -0x1c) {
                *param_4 = 0x10;
              }
              else if (cVar1 == -0x1b) {
                *param_4 = 0x20;
              }
              else if (cVar1 == -0x1a) {
                *param_4 = 0x40;
              }
              else if (cVar1 == -0x19) {
                *param_4 = 0x80;
              }
              else {
                *pcVar3 = cVar1;
                pcVar3 = pcVar3 + 1;
              }
            }
          }
        }
        uVar4 = uVar4 + 1 & 0xff;
      }
    }
    if (param_5 == 1) {
      iVar2 = 8;
    }
    else {
      iVar2 = 10;
    }
  }
  return iVar2;
}
#endif

/* 0101e41c */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0101e41c(uint *param_1,undefined1 *param_2,int param_3)
{
  char cVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  uint uVar4;
  uint local_34;
  uint local_30;
  uint local_2c;
  
  local_34 = 0;
  memzero(param_2,7);
  if (param_3 == 2) {
    *param_2 = 0xa1;
    param_2[1] = 1;
    param_2 = param_2 + 2;
  }
  *param_2 = 3;
  puVar3 = param_2 + 1;
  if ((*param_1 & _DAT_000202bc) != 0) {
    local_2c = 0;
    while ((local_2c < 0x10 && (puVar3 < param_2 + 5))) {
      uVar4 = *(uint *)(local_2c * 0xc + 0x201fc);
      if ((*param_1 & uVar4) != 0) {
        for (local_30 = 0; local_30 < 4; local_30 = local_30 + 1 & 0xff) {
          cVar1 = *(char *)(local_2c * 0xc + 0x20202 + local_30);
          if (cVar1 != '\0') {
            if (cVar1 == -0x3d) {
              local_34 = local_34 | uVar4;
              *param_1 = *param_1 & ~uVar4;
              *puVar3 = 0xe9;
              puVar3[1] = 0;
              puVar3 = puVar3 + 2;
            }
            else if (cVar1 == -0x43) {
              local_34 = local_34 | uVar4;
              *param_1 = *param_1 & ~uVar4;
              *puVar3 = 0xea;
              puVar3[1] = 0;
              puVar3 = puVar3 + 2;
            }
            else if (cVar1 == -0x32) {
              local_34 = local_34 | uVar4;
              *param_1 = *param_1 & ~uVar4;
              *puVar3 = 0xe2;
              puVar3[1] = 0;
              puVar3 = puVar3 + 2;
            }
            else if (cVar1 == -0x3e) {
              local_34 = local_34 | uVar4;
              *param_1 = *param_1 & ~uVar4;
              *puVar3 = 0xcd;
              puVar3[1] = 0;
              puVar3 = puVar3 + 2;
            }
            else if (cVar1 == -0x2c) {
              local_34 = local_34 | uVar4;
              *param_1 = *param_1 & ~uVar4;
              *puVar3 = 0x23;
              puVar3[1] = 2;
              puVar3 = puVar3 + 2;
            }
            else if (cVar1 == -0x4f) {
              local_34 = local_34 | uVar4;
              *param_1 = *param_1 & ~uVar4;
              *puVar3 = 0x8a;
              puVar3[1] = 1;
              puVar3 = puVar3 + 2;
            }
          }
        }
      }
      local_2c = local_2c + 1 & 0xff;
    }
  }
  if (local_34 == _DAT_00020318) {
    uVar2 = 0;
  }
  else {
    _DAT_00020318 = local_34;
    if (param_3 == 1) {
      uVar2 = 5;
    }
    else {
      uVar2 = 7;
    }
  }
  return uVar2;
}
#endif

/* 0101e598 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0101e598(uint *param_1,undefined1 *param_2,int param_3)
{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  uint uVar5;
  uint local_30;
  uint local_2c;
  
  local_30 = 0;
  memzero(param_2,4);
  if (param_3 == 2) {
    *param_2 = 0xa1;
    param_2[1] = 1;
    param_2 = param_2 + 2;
  }
  *param_2 = 4;
  puVar4 = param_2 + 1;
  if ((*param_1 & _DAT_000202c0) != 0) {
    uVar5 = 0;
    while ((uVar5 < 0x10 && (puVar4 < param_2 + 2))) {
      uVar2 = *(uint *)(uVar5 * 0xc + 0x201fc);
      if ((*param_1 & uVar2) != 0) {
        for (local_2c = 0; local_2c < 4; local_2c = local_2c + 1 & 0xff) {
          cVar1 = *(char *)(uVar5 * 0xc + 0x20202 + local_2c);
          if ((cVar1 != '\0') && (cVar1 == -0x4d)) {
            local_30 = local_30 | uVar2;
            *param_1 = *param_1 & ~uVar2;
            *puVar4 = 1;
            puVar4 = puVar4 + 1;
          }
        }
      }
      uVar5 = uVar5 + 1 & 0xff;
    }
  }
  if (local_30 == _DAT_0002031c) {
    uVar3 = 0;
  }
  else {
    _DAT_0002031c = local_30;
    if (param_3 == 1) {
      uVar3 = 2;
    }
    else {
      uVar3 = 4;
    }
  }
  return uVar3;
}
#endif

/* 0101e674 */
void FUN_0101e674(void)
{
  return;
}

/* 0101e678 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0101e678(int param_1)
{
  int iVar1;
  undefined4 uVar2;
  
  DAT_000201e8 = 0;
  flash_read(0x107d000,&DAT_00021920,0x88);
  if (((_DAT_00021920 == -1) || (_DAT_00021920 == 0)) &&
     ((_DAT_00021922 == -1 || (_DAT_00021922 == 0)))) {
    memzero(&DAT_00021920,0x88);
    _DAT_000201b2 = 8;
    DAT_00021926 = 6;
    DAT_00021929 = 6;
    DAT_00021928 = 6;
    DAT_00021927 = 6;
  }
  else {
    _DAT_000201b2 = _DAT_00021924;
  }
  iVar1 = FUN_0101fb14();
  if (iVar1 != 0) {
    param_1 = 1;
  }
  if (param_1 == 0) {
    iVar1 = FUN_01024c60(DAT_000201b4);
    if (iVar1 != 0) {
      uVar2 = FUN_01024c60(DAT_000201b4);
      memcpy(0x20179,uVar2,6);
      if (DAT_000201b9 != '\0') {
        memcpy(0x20179,&DAT_0102823e,6);
        DAT_000201b9 = '\0';
      }
      FUN_01025008(0x20179);
    }
    iVar1 = FUN_010182b0(0x20179,&DAT_0102823e,6);
    if (iVar1 == 0) {
      DAT_000201b7 = 1;
    }
    else {
      DAT_000201b7 = 0;
    }
  }
  else {
    memcpy(0x20179,&DAT_0102823e,6);
    DAT_000201b7 = 1;
  }
  return;
}
#endif

/* 0101e77c */
#ifdef NONMATCHING
void FUN_0101e77c(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)
{
  uint local_10;
  
  if (param_1 == 0) {
    local_10 = (uint)DAT_00020718;
    FUN_0101e7f2(0xa0,&local_10,1);
  }
  else {
    local_10 = param_4;
    FUN_0101e7e2(param_1);
  }
  return;
}
#endif

/* 0101e7a4 */
#ifdef NONMATCHING
void FUN_0101e7a4(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)
{
  if (param_1 == 0) {
    FUN_0101e7f2(param_2 | 0xa0,param_4,param_3,param_4,param_4);
  }
  else {
    FUN_0101e7e2(param_1);
  }
  return;
}
#endif

/* 0101e7ca */
#ifdef NONMATCHING
void FUN_0101e7ca(undefined4 param_1)
{
  FUN_0101e7e2(param_1);
  return;
}
#endif

/* 0101e7d6 */
#ifdef NONMATCHING
void FUN_0101e7d6(undefined4 param_1)
{
  FUN_0101e7e2(param_1);
  return;
}
#endif

/* 0101e7e2 */
#ifdef NONMATCHING
void FUN_0101e7e2(undefined4 param_1)
{
  FUN_0101e7f2(param_1,0);
  return;
}
#endif

/* 0101e7f2 */
#ifdef NONMATCHING
void FUN_0101e7f2(byte param_1,undefined4 param_2,int param_3)
{
  byte local_50;
  undefined1 auStack_4f [63];
  
  memzero(&local_50,0x40);
  local_50 = param_1;
  if (0 < param_3) {
    memcpy(auStack_4f,param_2,param_3);
  }
  if ((param_1 & 0xf0) != 0xa0) {
    BT_SendHidControlData(&local_50,param_3 + 1);
  }
  return;
}
#endif

/* 0101e82c */
#ifdef NONMATCHING
/* WARNING: Removing unreachable block (ram,0x0101e95a) */

void hid_control(char *param_1,undefined4 param_2,int param_3,undefined4 param_4)
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

/* 0101e880 */
#ifdef NONMATCHING
void FUN_0101e880(void)
{
  FUN_0101e7e2(0);
  return;
}
#endif

/* 0101e888 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0101e888(void)
{
  uint unaff_r6;
  
  if ((unaff_r6 & 0xf) == 5) {
    _DAT_00020708 = _DAT_00020708 | 2;
  }
  return;
}
#endif

/* 0101e89e */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0101e89e(void)
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
  FUN_0101e7d6(2);
  return;
}
#endif

/* 0101e8d2 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0101e8d2(void)
{
  uint unaff_r5;
  
  if (DAT_000201b4 == '\x03') {
    _DAT_00022ac2 = 8;
    if (0x40 < unaff_r5) {
      unaff_r5 = 0x40;
    }
    DAT_00022ac4 = (undefined1)unaff_r5;
    memcpy(0x22ac5);
  }
  FUN_0101e7e2(0);
  return;
}
#endif

/* 0101e8fe */
#ifdef NONMATCHING
void FUN_0101e8fe(void)
{
  FUN_010188c8();
  return;
}
#endif

/* 0101e904 */
#ifdef NONMATCHING
void FUN_0101e904(void)
{
  byte unaff_r6;
  
  DAT_00020718 = unaff_r6 & 1;
  FUN_0101e7ca(0);
  return;
}
#endif

/* 0101e914 */
#ifdef NONMATCHING
void FUN_0101e914(void)
{
  FUN_0101e7e2(2);
  return;
}
#endif

/* 0101e91c */
#ifdef NONMATCHING
void FUN_0101e91c(void)
{
  FUN_0101e7e2(2);
  return;
}
#endif

/* 0101e924 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0101e924(void)
{
  int unaff_r4;
  short unaff_r5;
  
  _DAT_00020708 = _DAT_00020708 | 0x100;
  if (DAT_000201b4 == '\x03') {
    FUN_0101c8fc(unaff_r4 + 1,unaff_r5 + -1);
  }
  return;
}
#endif

/* 0101e948 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0101e948(void)
{
  _DAT_00020708 = _DAT_00020708 | 0x200;
  return;
}
#endif

/* 0101e958 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_0101e95a(void)
{
  _DAT_00020708 = _DAT_00020708 | 0x400;
  return;
}
#endif

/* 0101e95a */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0101e95a(void)
{
  _DAT_00020708 = _DAT_00020708 | 0x400;
  return;
}
#endif

/* 0101e980 */
#ifdef NONMATCHING
void FUN_0101e980(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  if (DAT_000201b4 == '\0') {
    switch_host_data(param_1,param_2,param_3);
  }
  else if (DAT_000201b4 == '\x01') {
    xinput_host_data(param_1,param_2,param_3);
  }
  else if (DAT_000201b4 == '\x03') {
    android_host_data(param_1,param_2,param_3,param_4,param_4);
  }
  return;
}
#endif

/* 0101e9d0 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0101e9d0(undefined1 *param_1)
{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  if (_DAT_00020030[2] == _DAT_00020030[3]) {
    uVar3 = 0;
  }
  else {
    uVar1 = (uint)_DAT_00020030[2];
    *param_1 = *(undefined1 *)(uVar1 + 0xc0000);
    if (_DAT_00020030[1] == uVar1) {
      uVar1 = (uint)*_DAT_00020030;
    }
    else {
      uVar1 = uVar1 + 1 & 0xffff;
    }
    param_1[1] = *(undefined1 *)(uVar1 + 0xc0000);
    if (_DAT_00020030[1] == uVar1) {
      uVar1 = (uint)*_DAT_00020030;
    }
    else {
      uVar1 = uVar1 + 1 & 0xffff;
    }
    param_1[2] = *(undefined1 *)(uVar1 + 0xc0000);
    param_1[3] = 0;
    if (_DAT_00020030[1] == uVar1) {
      uVar1 = (uint)*_DAT_00020030;
    }
    else {
      uVar1 = uVar1 + 1 & 0xffff;
    }
    for (uVar4 = 0; uVar4 < *(ushort *)(param_1 + 2); uVar4 = uVar4 + 1 & 0xff) {
      iVar2 = FUN_010182dc(param_1 + 4);
      *(undefined1 *)(iVar2 + uVar4) = *(undefined1 *)(uVar1 + 0xc0000);
      if (_DAT_00020030[1] == uVar1) {
        uVar1 = (uint)*_DAT_00020030;
      }
      else {
        uVar1 = uVar1 + 1 & 0xffff;
      }
    }
    *(char *)(_DAT_00020030 + 2) = (char)uVar1;
    *(char *)((int)_DAT_00020030 + 5) = (char)(uVar1 >> 8);
    uVar3 = 1;
  }
  return uVar3;
}
#endif

/* 0101eb50 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ipc_queue_write(undefined1 *param_1)
{
  short sVar1;
  uint uVar2;
  undefined1 *puVar3;
  short sVar4;
  
  if (DAT_00020038 == '\x01') {
    DAT_000f853c = DAT_000f853c | 4;
    DAT_000c4fef = 1;
    rom_delay_a(10);
  }
  uVar2 = (uint)_DAT_00020034[3];
  puVar3 = param_1;
  sVar4 = *(short *)(param_1 + 2) + 3;
  while (sVar1 = sVar4 + -1, sVar4 != 0) {
    *(undefined1 *)(uVar2 + 0xc0000) = *puVar3;
    puVar3 = puVar3 + 1;
    if (_DAT_00020034[1] == uVar2) {
      uVar2 = (uint)*_DAT_00020034;
    }
    else {
      uVar2 = uVar2 + 1 & 0xffff;
    }
    sVar4 = sVar1;
    if (*(short *)(param_1 + 2) == sVar1) {
      puVar3 = (undefined1 *)FUN_010182dc(param_1 + 4);
    }
  }
  *(char *)(_DAT_00020034 + 3) = (char)uVar2;
  *(char *)((int)_DAT_00020034 + 7) = (char)(uVar2 >> 8);
  if (DAT_00020038 == '\x01') {
    DAT_000c4fef = 0;
    DAT_000f853c = DAT_000f853c & 0xfb;
  }
  return;
}
#endif

/* 0101ec38 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0101ec38(undefined1 *param_1)
{
  short sVar1;
  short sVar2;
  uint uVar3;
  short sVar4;
  undefined1 *puVar5;
  
  sVar1 = *(short *)(param_1 + 2);
  if (DAT_00020038 == '\x01') {
    DAT_000f853c = DAT_000f853c | 4;
    DAT_000c4fef = 1;
    rom_delay_a(10);
  }
  uVar3 = (uint)_DAT_00020034[3];
  puVar5 = param_1;
  sVar4 = sVar1 + 4;
  while (sVar2 = sVar4 + -1, sVar4 != 0) {
    *(undefined1 *)(uVar3 + 0xc0000) = *puVar5;
    puVar5 = puVar5 + 1;
    if (_DAT_00020034[1] == uVar3) {
      uVar3 = (uint)*_DAT_00020034;
    }
    else {
      uVar3 = uVar3 + 1 & 0xffff;
    }
    sVar4 = sVar2;
    if (sVar2 == sVar1) {
      puVar5 = (undefined1 *)FUN_010182dc(param_1 + 4);
    }
  }
  *(char *)(_DAT_00020034 + 3) = (char)uVar3;
  *(char *)((int)_DAT_00020034 + 7) = (char)(uVar3 >> 8);
  if (DAT_00020038 == '\x01') {
    DAT_000c4fef = 0;
    DAT_000f853c = DAT_000f853c & 0xfb;
  }
  return;
}
#endif

/* 0101ed1c */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

short FUN_0101ed1c(void)
{
  ushort uVar1;
  ushort uVar2;
  short sVar3;
  
  if (DAT_00020038 == '\x01') {
    DAT_000f853c = DAT_000f853c | 4;
    DAT_000c4fef = 1;
    log_empty(STR_0101edd8);
    rom_delay_a(10);
  }
  uVar1 = _DAT_00020034[2];
  uVar2 = _DAT_00020034[3];
  if (uVar2 < uVar1) {
    sVar3 = uVar1 - uVar2;
  }
  else {
    sVar3 = ((_DAT_00020034[1] - *_DAT_00020034) + 1) - (uVar2 - uVar1);
  }
  if (DAT_00020038 == '\x01') {
    DAT_000c4fef = 0;
    DAT_000f853c = DAT_000f853c & 0xfb;
  }
  return sVar3;
}
#endif

/* 0101ee04 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_0101ee04(void)
{
  return *(short *)(_DAT_00020030 + 4) != *(short *)(_DAT_00020030 + 6);
}
#endif

/* 0101ee40 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0101ee40(void)
{
  _DAT_000201d4 = _DAT_000201d4 + 1;
  return;
}
#endif

/* 0101ee50 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0101ee50(void)
{
  _DAT_00020198 = _DAT_00020198 + 1;
  return;
}
#endif

/* 0101ee60 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void core_bringup(void)
{
  uint uVar1;
  
  if (DAT_00020039 == '\0') {
    _DAT_e000e180 = 0x800;
    DAT_00020039 = '\x01';
    DAT_000f853c = 0x94;
    rom_delay_a(10);
    DAT_000c8010 = 1;
    rom_delay_a();
    do {
    } while ((DAT_000c8043 & 0x80) == 0);
    DAT_000c8043 = DAT_000c8043 & 0x7f;
    uVar1 = FUN_01024eb8(1);
    FUN_01024edc(1,uVar1 | 0xd00000);
    FUN_01024edc(0,0x3084cf0f);
    FUN_01024284();
    core_load_blob(&DAT_01025a6e);
    DAT_000f853c = 0x9c;
    rom_delay_a(100);
  }
  return;
}
#endif

/* 0101eefc */
#ifdef NONMATCHING
bool FUN_0101eefc(void)
{
  return (DAT_000201dc & 0x80) != 0;
}
#endif

/* 0101ef14 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_0101ef14(void)
{
  return 0xe10 < _DAT_00020620;
}
#endif

/* 0101ef2c */
#ifdef NONMATCHING
undefined4 FUN_0101ef2c(void)
{
  undefined4 uVar1;
  
  if ((DAT_00021878 == '\x01') || (DAT_00021878 == '\x02')) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}
#endif

/* 0101ef48 */
#ifdef NONMATCHING
undefined4 FUN_0101ef48(uint param_1)
{
  int iVar1;
  
  if (DAT_000201b8 == '\0') {
    if ((param_1 & 0x10000) == 0) {
      FUN_010203d0(0x10000);
    }
    else {
      iVar1 = FUN_0101a9f0(0x10000);
      if (iVar1 != 0) {
        return 1;
      }
    }
  }
  return 0;
}
#endif

/* 0101ef84 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_0101ef84(int param_1)
{
  return _DAT_00020f94 + param_1 < _DAT_00020f90;
}
#endif

/* 0101efa0 */
undefined4 always_one(void)
{
  return 1;
}

/* 0101efa4 */
#ifdef NONMATCHING
undefined4 FUN_0101efa4(void)
{
  byte bVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  byte bVar5;
  
  bVar2 = false;
  iVar3 = always_one();
  if (iVar3 == 0) {
    iVar3 = FUN_0101c254();
    if (iVar3 < 0x898) {
      bVar2 = true;
    }
  }
  else {
    iVar3 = FUN_0101c254();
    if ((iVar3 < 0xd80) && (iVar3 = FUN_0101c254(), 0xb53 < iVar3)) {
      bVar2 = true;
    }
  }
  bVar1 = DAT_0002062c & 0x7f;
  bVar5 = DAT_0002062c & 0x7f;
  DAT_0002062c = DAT_0002062c & 0x80;
  if (bVar2) {
    bVar5 = bVar5 + 1;
    if (10 < bVar5) {
      bVar5 = 10;
      DAT_0002062c = 0x80;
    }
  }
  else if (bVar1 == 0) {
    DAT_0002062c = 0;
  }
  else {
    bVar5 = bVar5 - 1;
  }
  bVar1 = bVar5 & 0x7f | DAT_0002062c;
  if (DAT_0002062c == 0) {
    uVar4 = 0;
    DAT_00020634 = 0;
    DAT_0002062c = bVar1;
  }
  else {
    DAT_0002062c = bVar1;
    iVar3 = FUN_0101c254();
    if (iVar3 < 0xc80) {
      DAT_00020634 = DAT_00020634 + 1;
      if (9 < DAT_00020634) {
        FUN_0101a818(100,0);
      }
    }
    else {
      DAT_00020634 = 0;
    }
    uVar4 = 1;
  }
  return uVar4;
}
#endif

/* 0101f080 */
#ifdef NONMATCHING
bool usb_charging(void)
{
  return (DAT_000201dc & 0x40) != 0;
}
#endif

/* 0101f098 */
undefined4 FUN_0101f098(void)
{
  return 1;
}

/* 0101f09c */
undefined4 FUN_0101f09c(void)
{
  return 1;
}

/* 0101f0a0 */
#ifdef NONMATCHING
undefined4 usb_powered(void)
{
  undefined4 uVar1;
  
  if ((DAT_00020181 == '\x03') || (DAT_00020181 == '\x02')) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}
#endif

/* 0101f0bc */
#ifdef NONMATCHING
undefined4 FUN_0101f0bc(void)
{
  int iVar1;
  
  iVar1 = GPIO_ReadInputDataBit(1,0x40);
  if (iVar1 != 0) {
    thunk_FUN_0101b23c(100);
    iVar1 = GPIO_ReadInputDataBit(1,0x40);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}
#endif

/* 0101f0e4 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_0101f0e4(void)
{
  int iVar1;
  undefined *puVar2;
  bool bVar3;
  
  iVar1 = FUN_0101c254();
  if (iVar1 < 0x1068) {
    if (iVar1 < 0x105e) {
      if (iVar1 < 0x1040) {
        if (iVar1 < 0x1022) {
          if (iVar1 < 0x1004) {
            if (iVar1 < 0xf6e) {
              puVar2 = (undefined *)0x5265c0;
            }
            else {
              puVar2 = (undefined *)0x927c0;
            }
          }
          else {
            puVar2 = (undefined *)0x493e0;
          }
        }
        else {
          puVar2 = (undefined *)0x3a980;
        }
      }
      else {
        puVar2 = (undefined *)0x2bf20;
      }
    }
    else {
      puVar2 = &UNK_0001d4c0;
    }
  }
  else {
    puVar2 = &DAT_0000ea60;
  }
  if (iVar1 < 0x10cc) {
    if ((int)(_DAT_00020622 + 5) <= iVar1) {
      _DAT_00020622 = (ushort)iVar1;
      _DAT_00020628 = (undefined *)0x0;
    }
    DAT_0002062e = 0;
  }
  else {
    DAT_0002062e = DAT_0002062e + 1;
    if (0x1d < DAT_0002062e) {
      DAT_0002062e = 0;
      _DAT_00020628 = puVar2;
    }
  }
  _DAT_00020628 = _DAT_00020628 + 2000;
  bVar3 = puVar2 <= _DAT_00020628;
  if (bVar3) {
    DAT_000206b2 = 1;
    DAT_000206b3 = 0;
    _DAT_00020628 = puVar2;
  }
  return bVar3;
}
#endif

/* 0101f1d4 */
#ifdef NONMATCHING
/* WARNING: Removing unreachable block (ram,0x0101f57c) */
/* WARNING: Removing unreachable block (ram,0x0101f59e) */
/* WARNING: Removing unreachable block (ram,0x0101f5ac) */
/* WARNING: Removing unreachable block (ram,0x0101f5a2) */
/* WARNING: Removing unreachable block (ram,0x0101f592) */
/* WARNING: Removing unreachable block (ram,0x0101f578) */
/* WARNING: Removing unreachable block (ram,0x0101f480) */
/* WARNING: Removing unreachable block (ram,0x0101f488) */
/* WARNING: Removing unreachable block (ram,0x0101f4d0) */
/* WARNING: Removing unreachable block (ram,0x0101f466) */
/* WARNING: Removing unreachable block (ram,0x0101f47a) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void report_build(uint param_1,int param_2,uint param_3)
{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  int unaff_r4;
  uint uVar4;
  undefined *local_110 [35];
  uint local_84;
  undefined1 local_80;
  undefined1 local_7f;
  undefined1 local_7e;
  undefined1 auStack_74 [12];
  undefined1 local_68;
  undefined1 local_67;
  undefined1 local_66 [70];
  uint local_20;
  int local_1c;
  uint local_18;
  
  local_84 = (uint)DAT_000201b4;
  if ((param_1 == 0xffffffff) && (param_2 == -1)) {
    local_1c = 0x7f7f7f7f;
    local_20 = 0;
  }
  else {
    local_20 = param_1;
    local_1c = param_2;
    if (param_1 == 0xffffffff) {
      local_20 = _DAT_00020150;
    }
  }
  if (local_1c == -1) {
    local_1c = 0x7f7f7f7f;
  }
  if (param_3 == 0xffffffff) {
    uVar4 = 0;
  }
  else {
    uVar4 = param_3 & 0xffff;
  }
  local_18 = param_3;
  if (((DAT_00020658 != '\0') || (DAT_000201b4 != 4)) && (DAT_000201b8 == '\0')) {
    FUN_0101aa6c(&local_20,&local_1c);
  }
  if (DAT_00020182 == '\x02') {
    if (DAT_000201b4 == 3) {
      if (DAT_000201b8 == '\0') {
        memcpy(auStack_74,&DAT_010280fc,10);
        memcpy(&local_80,&DAT_01028106,0xc);
        local_110[0] = &local_80;
        FUN_0101cda4(local_20,local_1c,auStack_74,uVar4);
        uVar2 = FUN_01024a54(2);
        FUN_01024e8c(uVar2,&local_80,0xc);
      }
      else {
        DAT_00020777 = 0x30;
        FUN_0101d3e4(local_20,local_1c,0x217b0);
        FUN_010205e0(0x217b0,2,1);
      }
    }
    else if (DAT_000201b4 == 2) {
      if (DAT_0002018d == '\x01') {
        bVar1 = DAT_000217ec + 4;
        memcpy(0x217e2,&DAT_01028148,0x4f);
        FUN_0101d964(local_20,local_1c,uVar4,0x217e5);
        DAT_000217ec = bVar1 & 0xfc | DAT_000217ec & 3;
      }
      else {
        memcpy(0x217e2,&DAT_0102813d,0xb);
        FUN_0101d964(local_20,local_1c,uVar4,0x217e3);
      }
      FUN_0101fa98(1);
    }
    else if (DAT_000201b4 == 1) {
      memcpy(&local_68,&DAT_0102812c,0x11);
      iVar3 = FUN_0101cdc8(local_20,local_1c,uVar4,&local_68);
      if (iVar3 != 0) {
        local_80 = 0xa1;
        local_7f = 2;
        local_7e = (local_20 & 0x20000) != 0;
        uVar2 = FUN_01024a54(2);
        FUN_01024e8c(uVar2,&local_80,3);
        FUN_0101b242(1);
      }
      uVar2 = FUN_01024a54(2);
      FUN_01024e8c(uVar2,&local_68,0x11);
    }
    else if (DAT_000201b4 == 0) {
      if ((local_20 & 9) == 9) {
        local_20 = local_20 & 0xfffffff6 | 0xc000;
      }
      FUN_0101d3e4(local_20,local_1c,0x217b0);
      FUN_010205e0(0x217b0,2,1);
    }
    else if (DAT_000201b4 == 4) {
      if (DAT_00020658 != '\0') {
        local_110[0] = &local_80;
        FUN_0101cda4(local_20,local_1c,auStack_74,uVar4);
        uVar2 = FUN_01024a54(2);
        FUN_01024e8c(uVar2,&local_80,0xc);
        return;
      }
      local_110[0] = &UNK_00000002;
      FUN_0101e2fc(local_20,local_1c,uVar4,&local_80);
      if (unaff_r4 == 1) {
        FUN_01024a9c(&local_68,1);
      }
      else if (unaff_r4 == 8) {
        FUN_01023108(&local_68,8);
      }
      else {
        FUN_0101b5b0(&local_68);
      }
      uVar2 = FUN_01024a54(2);
      FUN_01024e8c(uVar2,&local_80,10);
    }
  }
  iVar3 = usb_powered();
  if (iVar3 != 0) {
    if (DAT_000201ea == '\0') {
      DAT_00020309 = DAT_00020309 + 1;
      if (1 < DAT_00020309) {
        DAT_00020309 = 0;
        DAT_000201ea = '\x01';
      }
    }
    else if (DAT_000201b8 == '\0') {
      if ((undefined *)(local_20 & 0x3c39) == &UNK_00003c39) {
        memzero(&local_68,0x40);
        local_68 = 2;
        flash_read(0x107e000,local_110,0x8c);
        local_67 = (undefined1)local_84;
        memcpy(local_66,local_110 + local_84 * 7,0x1c);
        FUN_01023108(&local_68,0x40);
      }
      else {
        report3_build(local_20,local_1c,uVar4,&local_68);
        FUN_01023108(local_66,9);
      }
    }
  }
  return;
}
#endif

/* 0101f60c */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0101f60c(void)
{
  FUN_0101f98c(0xc);
  _DAT_0002fff0 = 0x5a5aa5a5;
  FUN_0101e01c();
  if (DAT_00020682 == '\x02') {
    ble_disconnect();
    FUN_0101b242(2);
  }
  FUN_01020bf8();
  FUN_01020364();
  FUN_010180d4();
  return;
}
#endif

/* 0101f64c */
#ifdef NONMATCHING
uint FUN_0101f64c(void)
{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  uVar1 = GPIO_ReadInputData(0);
  uVar1 = ~uVar1;
  if ((uVar1 & 2) != 0) {
    uVar2 = 0x20;
  }
  if ((uVar1 & 1) != 0) {
    uVar2 = uVar2 | 0x10;
  }
  if ((uVar1 & 0x200) != 0) {
    uVar2 = uVar2 | 0x2000;
  }
  if ((uVar1 & 0x400) != 0) {
    uVar2 = uVar2 | 0x1000;
  }
  if ((uVar1 & 0x20) != 0) {
    uVar2 = uVar2 | 0x800;
  }
  uVar1 = GPIO_ReadInputData(1);
  uVar1 = ~uVar1;
  if ((uVar1 & 0x4000) != 0) {
    uVar2 = uVar2 | 0x200;
  }
  if ((uVar1 & 0x400) != 0) {
    uVar2 = uVar2 | 0x100;
  }
  if ((uVar1 & 0x2000) != 0) {
    uVar2 = uVar2 | 0x80;
  }
  if ((uVar1 & 0x1000) != 0) {
    uVar2 = uVar2 | 0x40;
  }
  if ((uVar1 & 0x800) != 0) {
    uVar2 = uVar2 | 1;
  }
  uVar1 = GPIO_ReadInputData(2);
  if ((~uVar1 & 0x10) != 0) {
    uVar2 = uVar2 | 8;
  }
  if ((~uVar1 & 2) != 0) {
    uVar2 = uVar2 | 0x400;
  }
  return uVar2;
}
#endif

/* 0101f718 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0101f718(void)
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = FUN_0101fb08();
  iVar2 = FUN_0101f09c();
  uVar3 = uVar1;
  if ((iVar2 == 0) && (DAT_000201b8 == '\0')) {
    if (uVar1 == _DAT_00020150) {
      uVar3 = 0xffffffff;
    }
    else {
      thunk_FUN_0101b23c(10);
      uVar3 = FUN_0101fb08();
      if (uVar3 == _DAT_00020150) {
        uVar3 = 0xffffffff;
      }
      else {
        _DAT_00020150 = uVar3;
      }
    }
    if ((DAT_000201b8 == '\0') && (((_DAT_0002186c & uVar1) != 0 || ((uVar1 & 0x10000) != 0)))) {
      uVar3 = uVar1;
    }
  }
  return uVar3;
}
#endif

/* 0101f798 */
#ifdef NONMATCHING
void thunk_FUN_0101f7d0(void)
{
  do {
    led_set(7,1);
    rom_delay_a(300);
    led_set(7,2);
    rom_delay_a(300);
    led_set(7,4);
    rom_delay_a(300);
    rom_delay_a(200);
  } while( true );
}
#endif

/* 0101f7d0 */
#ifdef NONMATCHING
void FUN_0101f7d0(void)
{
  do {
    led_set(7,1);
    rom_delay_a(300);
    led_set(7,2);
    rom_delay_a(300);
    led_set(7,4);
    rom_delay_a(300);
    rom_delay_a(200);
  } while( true );
}
#endif

/* 0101f7d2 */
void FUN_0101f7d2(void)
{
  return;
}

/* 0101f7d4 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0101f7d4(void)
{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (_DAT_00020708 != 0) {
    uVar1 = 0;
    if ((_DAT_00020708 & 1) == 0) {
      if ((_DAT_00020708 & 2) == 0) {
        if ((_DAT_00020708 & 4) == 0) {
          if ((_DAT_00020708 & 8) == 0) {
            if ((_DAT_00020708 & 0x10) == 0) {
              if ((_DAT_00020708 & 0x20) == 0) {
                if ((_DAT_00020708 & 0x40) == 0) {
                  if ((_DAT_00020708 & 0x80) == 0) {
                    if ((_DAT_00020708 & 0x100) == 0) {
                      if ((_DAT_00020708 & 0x200) == 0) {
                        if ((_DAT_00020708 & 0x400) != 0) {
                          _DAT_00020708 = _DAT_00020708 & 0xfffffbff;
                          FUN_0101e7e2(3);
                          uVar1 = 1;
                        }
                      }
                      else {
                        _DAT_00020708 = _DAT_00020708 & 0xfffffdff;
                        uVar1 = 1;
                      }
                    }
                    else {
                      _DAT_00020708 = _DAT_00020708 & 0xfffffeff;
                      uVar1 = 1;
                    }
                  }
                  else {
                    _DAT_00020708 = _DAT_00020708 & 0xffffff7f;
                    FUN_0101e7e2(2);
                    uVar1 = 1;
                  }
                }
                else {
                  _DAT_00020708 = _DAT_00020708 & 0xffffffbf;
                  FUN_0101e7e2(2);
                  uVar1 = 1;
                }
              }
              else {
                _DAT_00020708 = _DAT_00020708 & 0xffffffdf;
                FUN_0101e7ca(0);
                uVar1 = 1;
              }
            }
            else {
              _DAT_00020708 = _DAT_00020708 & 0xffffffef;
              FUN_010188c8();
              uVar1 = 1;
            }
          }
          else {
            _DAT_00020708 = _DAT_00020708 & 0xfffffff7;
            FUN_0101e7e2(0);
            uVar1 = 1;
          }
        }
        else {
          _DAT_00020708 = _DAT_00020708 & 0xfffffffb;
          FUN_0101e7d6(2);
          uVar1 = 1;
        }
      }
      else {
        _DAT_00020708 = _DAT_00020708 & 0xfffffffd;
        FUN_0101b4d8();
        uVar1 = 1;
      }
    }
    else {
      _DAT_00020708 = _DAT_00020708 & 0xfffffffe;
      FUN_0101e7e2(0);
      uVar1 = 1;
    }
  }
  return uVar1;
}
#endif

/* 0101f940 */
#ifdef NONMATCHING
undefined8 FUN_0101f940(int param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5)
{
  if (param_1 < 0xb) {
    if ((param_1 < param_5) && (0 < param_1)) {
      param_1 = param_5;
    }
  }
  else {
    param_1 = 10;
  }
  if (param_2 < 0xb) {
    if ((param_2 < param_5) && (0 < param_2)) {
      param_2 = param_5;
    }
  }
  else {
    param_2 = 10;
  }
  return CONCAT44(param_2,param_1);
}
#endif

/* 0101f96a */
void log_empty(void)
{
  return;
}

/* 0101f96c */
void FUN_0101f96c(void)
{
  FUN_0101f9a0(0xc);
  FUN_0101f9b8(0xc,1);
  FUN_0101f9a0(0x10);
  FUN_0101f9b8(0x10,1);
  return;
}

/* 0101f98c */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0101f98c(uint param_1)
{
  _DAT_e000e180 = 1 << (param_1 & 0xff);
  return;
}
#endif

/* 0101f9a0 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0101f9a0(uint param_1)
{
  _DAT_e000e100 = _DAT_e000e100 | 1 << (param_1 & 0xff);
  return;
}
#endif

/* 0101f9b8 */
#ifdef NONMATCHING
undefined4 FUN_0101f9b8(uint param_1,uint param_2)
{
  if ((int)param_1 < 0) {
    *(uint *)(((param_1 & 0xf) - 8 & 0xfffffffc) + 0xe000ed1c) =
         *(uint *)(((param_1 & 0xf) - 8 & 0xfffffffc) + 0xe000ed1c) &
         ~(0xff << ((param_1 & 3) << 3)) | ((param_2 & 3) << 6) << ((param_1 & 3) << 3);
  }
  else {
    *(uint *)((param_1 & 0xfffffffc) + 0xe000e400) =
         *(uint *)((param_1 & 0xfffffffc) + 0xe000e400) & ~(0xff << ((param_1 & 3) << 3)) |
         ((param_2 & 3) << 6) << ((param_1 & 3) << 3);
  }
  return 1;
}
#endif

/* 0101fa34 */
undefined4 FUN_0101fa34(void)
{
  return 0;
}

/* 0101fa38 */
#ifdef NONMATCHING
void FUN_0101fa38(void)
{
  GPIO_ResetBits(2,4);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}
#endif

/* 0101fa44 */
#ifdef NONMATCHING
void FUN_0101fa44(void)
{
  FUN_01024a84(2,4,5);
  GPIO_SetBits(2,4);
  return;
}
#endif

/* 0101fa5c */
#ifdef NONMATCHING
void FUN_0101fa5c(void)
{
  if (DAT_0002018d == '\x01') {
    memcpy(0x217e2,&DAT_01028148,0x4f);
  }
  else if (DAT_0002018d == '\0') {
    memcpy(0x217e2,&DAT_0102813d,0xb);
  }
  return;
}
#endif

/* 0101fa98 */
#ifdef NONMATCHING
void FUN_0101fa98(void)
{
  undefined4 uVar1;
  
  uVar1 = FUN_01024a54(2);
  if (DAT_0002018d == '\x01') {
    DAT_000217ec = DAT_000217ec + '\x04';
    FUN_01024e8c(uVar1,0x217e2,0x4f);
  }
  else if (DAT_0002018d == '\0') {
    FUN_01024e8c(uVar1,0x217e2,0xb);
  }
  return;
}
#endif

/* 0101fae0 */
#ifdef NONMATCHING
undefined4 FUN_0101fae0(void)
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = always_one();
  if (((iVar1 == 0) || (iVar1 = GPIO_ReadInputDataBit(0,0x1000), iVar1 == 0)) ||
     (iVar1 = FUN_0101c3a0(), iVar1 < 4)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}
#endif

/* 0101fb08 */
#ifdef NONMATCHING
undefined4 FUN_0101fb08(void)
{
  FUN_0101f64c();
  return;
}
#endif

/* 0101fb14 */
#ifdef NONMATCHING
bool FUN_0101fb14(void)
{
  return (DAT_000201d1 & 0x80) != 0;
}
#endif

/* 0101fb2c */
#ifdef NONMATCHING
void FUN_0101fb2c(void)
{
  if (DAT_00021eb8 != '\0') {
    FUN_01024090(0x21ea4);
  }
  FUN_010240c8(0x21ea4,0x101fb61);
  FUN_010240ac(0x21ea4,&DAT_0000176f);
  FUN_01023d5c(0x21ea4);
  return;
}
#endif

/* 0101fb60 */
#ifdef NONMATCHING
void FUN_0101fb60(void)
{
  int iVar1;
  
  if (((DAT_00020682 != '\x02') && (DAT_00020181 != '\x03')) && (iVar1 = usb_charging(), iVar1 == 0)
     ) {
    restart();
  }
  FUN_010240ac(0x21ea4,&DAT_0000176f);
  FUN_01023d5c(0x21ea4);
  return;
}
#endif

/* 0101fba0 */
#ifdef NONMATCHING
void FUN_0101fba0(void)
{
  if (DAT_00021eb8 != '\0') {
    FUN_01024090(0x21ea4);
  }
  return;
}
#endif

/* 0101fbb8 */
#ifdef NONMATCHING
void FUN_0101fbb8(void)
{
  FUN_0101fba0();
  if (DAT_00021ea0 != '\0') {
    FUN_01024090(0x21e8c);
  }
  FUN_010240c8(0x21e8c,0x101fbf1);
  FUN_010240ac(0x21e8c,0x5db);
  FUN_01023d5c(0x21e8c);
  return;
}
#endif
