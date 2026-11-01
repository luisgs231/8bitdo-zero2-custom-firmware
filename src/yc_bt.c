/* yc_bt.c: guessed: the HCI link to the Bluetooth core, hci_bt and HCI_CMD_* logs */

#include "zero2.h"

/* 01018ac8 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ble_disconnect(undefined4 param_1,undefined4 param_2,undefined1 param_3)
{
  int iVar1;
  undefined4 uStack_10;
  undefined4 local_c;
  
  uStack_10 = (uint)CONCAT11(0x12,param_3);
  local_c = 0;
  FUN_01018a54(&DAT_00020010,0xc);
  ipc_send(&uStack_10);
  _DAT_0002000c = now();
  do {
    iVar1 = FUN_01018a76(&DAT_00020010,0xc);
    if (iVar1 != 0) {
      return 1;
    }
    iVar1 = elapsed(_DAT_0002000c,500);
  } while (iVar1 == 0);
  return 0;
}
#endif

/* 01018b1c */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 bt_disconnect(undefined4 param_1,undefined4 param_2,undefined1 param_3)
{
  int iVar1;
  undefined4 uStack_10;
  undefined4 local_c;
  
  uStack_10 = (uint)CONCAT11(0x11,param_3);
  local_c = 0;
  FUN_01018a54(&DAT_00020010,0xb);
  ipc_send(&uStack_10);
  _DAT_0002000c = now();
  do {
    iVar1 = FUN_01018a76(&DAT_00020010,0xb);
    if (iVar1 != 0) {
      return 1;
    }
    iVar1 = elapsed(_DAT_0002000c,500);
  } while (iVar1 == 0);
  return 0;
}
#endif

/* 01018b70 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_01018b70(undefined4 param_1,undefined4 param_2,undefined1 param_3)
{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_18;
  undefined1 uStack_14;
  undefined1 local_13;
  undefined2 local_12;
  undefined4 *local_10;
  
  local_10 = &local_18;
  _uStack_14 = CONCAT22(1,CONCAT11(0x28,param_3));
  local_18 = param_1;
  FUN_01018a54(&DAT_00020010,0x10);
  ipc_send(&uStack_14);
  _DAT_0002000c = now();
  do {
    iVar1 = FUN_01018a76(&DAT_00020010,0x10);
    if (iVar1 != 0) {
      uVar2 = 1;
      goto LAB_01018ba8;
    }
    iVar1 = elapsed(_DAT_0002000c,500);
  } while (iVar1 == 0);
  uVar2 = 0;
LAB_01018ba8:
  return CONCAT44(local_18,uVar2);
}
#endif

/* 01018bc8 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_01018bc8(undefined4 param_1,undefined2 param_2,undefined1 param_3)
{
  int iVar1;
  undefined1 uStack_18;
  undefined1 local_17;
  undefined2 local_16;
  undefined4 local_14;
  
  _uStack_18 = CONCAT22(param_2,CONCAT11(0xb1,param_3));
  local_14 = param_1;
  FUN_01018a54(&DAT_00020010,0x2c);
  ipc_send(&uStack_18);
  _DAT_0002000c = now();
  do {
    iVar1 = FUN_01018a76(&DAT_00020010,0x2c);
    if (iVar1 != 0) {
      return 1;
    }
    iVar1 = elapsed(_DAT_0002000c,500);
  } while (iVar1 == 0);
  return 0;
}
#endif

/* 01018c1c */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_01018c1c(undefined4 param_1,undefined4 param_2,undefined1 param_3)
{
  int iVar1;
  undefined4 uStack_10;
  undefined4 local_c;
  
  uStack_10 = (uint)CONCAT11(0x76,param_3);
  local_c = 0;
  FUN_01018a54(&DAT_00020010,0x1f);
  ipc_send(&uStack_10);
  _DAT_0002000c = now();
  do {
    iVar1 = FUN_01018a76(&DAT_00020010,0x1f);
    if (iVar1 != 0) {
      return 1;
    }
    iVar1 = elapsed(_DAT_0002000c,500);
  } while (iVar1 == 0);
  return 0;
}
#endif

/* 01018c70 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint core_event_read(void)
{
  uint uVar1;
  int iVar2;
  
  if (_DAT_00020020 < 1) {
    if (DAT_00020024 == '\x01') {
      FUN_0101f9a0(0xb);
      DAT_000c8043 = DAT_000c8043 | 0x80;
    }
    uVar1 = 0xffffffff;
  }
  else {
    iVar2 = _DAT_00020f98 + 1;
    if (_DAT_00020f90 == iVar2) {
      iVar2 = 0;
    }
    uVar1 = (uint)*(byte *)(_DAT_00020f8c + iVar2);
    if ((((((uVar1 == 0) || (uVar1 == 2)) || (uVar1 == 3)) || ((uVar1 == 5 || (uVar1 == 0x2c)))) ||
        ((uVar1 == 0x2d || ((uVar1 == 0x34 || (uVar1 == 0x36)))))) || (uVar1 == 0x10)) {
      log_empty(STR_01018d0c,uVar1);
      FUN_01020500(3);
    }
    FUN_0101f98c(0xb);
    _DAT_00020020 = _DAT_00020020 + -1;
    FUN_0101f9a0(0xb);
  }
  return uVar1;
}
#endif

/* 01018d2c */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01018d2c(void)
{
  int iVar1;
  
  do {
    iVar1 = FUN_0101ee04();
    if (iVar1 == 0) {
LAB_01018d5a:
      DAT_000c8043 = DAT_000c8043 & 0x7f;
      return;
    }
    if (_DAT_00020f90 - _DAT_00020f94 < 0x102) {
      FUN_0101f98c(0xb);
      DAT_00020024 = 1;
      goto LAB_01018d5a;
    }
    DAT_00020024 = 0;
    core_event_flag();
  } while( true );
}
#endif

/* 01018d8c */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_01018d8c(void)
{
  int iVar1;
  
  _DAT_00020f90 = 0x800;
  _DAT_00020f8c = 0x2078c;
  _DAT_00020f94 = 0;
  _DAT_00020f98 = 0;
  _DAT_00020f9c = 0;
  DAT_00020024 = 0;
  _DAT_00020010 = 0;
  _DAT_00020014 = 0;
  _DAT_0002000c = 0;
  _DAT_00020020 = 0;
  for (iVar1 = 0; iVar1 < 5; iVar1 = iVar1 + 1) {
    (&DAT_00020018)[iVar1] = 0;
  }
  for (iVar1 = 0; iVar1 < 0x800; iVar1 = iVar1 + 1) {
    *(undefined1 *)(iVar1 + 0x2078c) = 0;
  }
  FUN_010182f0(0x20fa0,0x20029);
  core_bringup();
  return 1;
}
#endif

/* 01018e0c */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void core_event_flag(void)
{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  char *pcVar4;
  bool bVar5;
  
  iVar1 = FUN_0101e9d0(&DAT_00020025);
  bVar5 = iVar1 == 1;
  do {
    if (!bVar5) {
      return;
    }
    bVar5 = DAT_00020025 == '\x02';
  } while (!bVar5);
  _DAT_0002000c = now();
  if (DAT_00020026 != 0x33) {
    if (DAT_00020026 < 0x34) {
      if (DAT_00020026 != 0x10) {
        if (DAT_00020026 < 0x11) {
                    /* WARNING: Subroutine does not return */
          yc_switch8();
        }
        if (DAT_00020026 != 0x2e) {
          if (DAT_00020026 < 0x2f) {
            if (DAT_00020026 == 0x29) {
              FUN_01018aa4(&DAT_00020010,0x20);
              puVar3 = (undefined1 *)FUN_010182dc(0x20029);
              DAT_00020018 = *puVar3;
              iVar1 = FUN_010182dc(0x20029);
              DAT_00020019 = *(undefined1 *)(iVar1 + 1);
              goto code_r0x0101980a;
            }
            if (DAT_00020026 < 0x2a) {
              if (DAT_00020026 != 0x11) {
                bVar5 = DAT_00020026 == 0x14;
                goto LAB_01018e62;
              }
            }
            else if (DAT_00020026 != 0x2c) {
              bVar5 = DAT_00020026 == 0x2d;
              goto joined_r0x01018e7e;
            }
          }
          else if ((DAT_00020026 != 0x2f) && (DAT_00020026 != 0x30)) {
            if (DAT_00020026 == 0x31) {
              FUN_0102024c(&DAT_00020025,3);
              uVar2 = FUN_010182dc(0x20029);
              FUN_0102024c(uVar2,_DAT_00020027);
              _DAT_00020020 = _DAT_00020020 + 1;
              log_empty(STR_010191d0,DAT_00020026,_DAT_00020020);
              log_empty(FUN_010191f4);
              goto code_r0x0101980a;
            }
            bVar5 = DAT_00020026 == 0x32;
joined_r0x01018e7e:
            if (!bVar5) goto LAB_01018e62;
          }
        }
      }
    }
    else {
      if (DAT_00020026 == 0xb2) {
switchD_01018ebe_caseD_bb:
        FUN_0102024c(&DAT_00020025,3);
        uVar2 = FUN_010182dc(0x20029);
        FUN_0102024c(uVar2,_DAT_00020027);
        _DAT_00020020 = _DAT_00020020 + 1;
        goto code_r0x0101980a;
      }
      if (0xb2 < DAT_00020026) {
        switch(DAT_00020026) {
        case 0xb3:
          log_empty(STR_01019830);
          break;
        case 0xb4:
          log_empty(STR_0101984c);
          break;
        case 0xb5:
        case 0xb7:
        case 0xb8:
          goto switchD_01018ebe_caseD_b8;
        case 0xb6:
          FUN_0102024c(&DAT_00020025,3);
          uVar2 = FUN_010182dc(0x20029);
          FUN_0102024c(uVar2,_DAT_00020027);
          _DAT_00020020 = _DAT_00020020 + 1;
          break;
        case 0xb9:
        case 0xba:
        case 0xbb:
        case 0xbf:
          goto switchD_01018ebe_caseD_bb;
        default:
          goto thunk_FUN_01019806;
        }
        goto code_r0x0101980a;
      }
      if (DAT_00020026 == 0x39) {
        FUN_0102024c(&DAT_00020025,3);
        uVar2 = FUN_010182dc(0x20029);
        FUN_0102024c(uVar2,_DAT_00020027);
        _DAT_00020020 = _DAT_00020020 + 1;
        log_empty(STR_010191d0,DAT_00020026,_DAT_00020020);
        goto code_r0x0101980a;
      }
      if (DAT_00020026 < 0x3a) {
                    /* WARNING: Subroutine does not return */
        yc_switch8();
      }
      if (DAT_00020026 == 0x3a) {
        pcVar4 = (char *)FUN_010182dc(0x20029);
        if (*pcVar4 == '\0') {
          FUN_01018aa4(&DAT_00020010,0x28);
        }
        goto code_r0x0101980a;
      }
      if (DAT_00020026 == 0x3b) {
        pcVar4 = (char *)FUN_010182dc(0x20029);
        if ((*pcVar4 == '\x03') || (pcVar4 = (char *)FUN_010182dc(0x20029), *pcVar4 == '\x04')) {
          FUN_01018aa4(&DAT_00020010,0x29);
        }
        goto code_r0x0101980a;
      }
      if (DAT_00020026 == 0xb0) {
        FUN_0102024c(&DAT_00020025,3);
        uVar2 = FUN_010182dc(0x20029);
        FUN_0102024c(uVar2,_DAT_00020027);
        _DAT_00020020 = _DAT_00020020 + 1;
        goto code_r0x0101980a;
      }
      bVar5 = false;
      if (DAT_00020026 == 0xb1) {
        thunk_FUN_010197c4();
        return;
      }
LAB_01018e62:
      if (!bVar5) {
thunk_FUN_01019806:
        goto code_r0x0101980a;
      }
    }
  }
switchD_01018ebe_caseD_b8:
  FUN_0102024c(&DAT_00020025,3);
  uVar2 = FUN_010182dc(0x20029);
  FUN_0102024c(uVar2,_DAT_00020027);
  _DAT_00020020 = _DAT_00020020 + 1;
  log_empty(STR_010191d0,DAT_00020026,_DAT_00020020);
code_r0x0101980a:
  DAT_000f853c = DAT_000f853c & 0xfb;
  DAT_000c4fef = 0;
  return;
}
#endif

/* 01018eda */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01018eda(void)
{
  undefined4 uVar1;
  
  FUN_0102024c(&DAT_00020025,3);
  uVar1 = FUN_010182dc(0x20029);
  FUN_0102024c(uVar1,CONCAT11(DAT_00020028,DAT_00020027));
  _DAT_00020020 = _DAT_00020020 + 1;
  if (0x400 < _DAT_00020020) {
    FUN_01020500(1);
    log_empty(FUN_010191c4);
  }
  log_empty(0x10191c8);
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01018f14 */
#ifdef NONMATCHING
void thunk_FUN_01019704(void)
{
  return;
}
#endif

/* 01018f16 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01018f16(void)
{
  undefined4 uVar1;
  
  FUN_0102024c(&DAT_00020025,3);
  uVar1 = FUN_010182dc(0x20029);
  FUN_0102024c(uVar1,CONCAT11(DAT_00020028,DAT_00020027));
  _DAT_00020020 = _DAT_00020020 + 1;
  log_empty(STR_010191d0,DAT_00020026,_DAT_00020020);
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01018f18 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01018f18(void)
{
  undefined4 uVar1;
  
  FUN_0102024c(&DAT_00020025,3);
  uVar1 = FUN_010182dc(0x20029);
  FUN_0102024c(uVar1,CONCAT11(DAT_00020028,DAT_00020027));
  _DAT_00020020 = _DAT_00020020 + 1;
  log_empty(STR_010191d0,DAT_00020026,_DAT_00020020);
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01018f30 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01018f30(void)
{
  undefined4 uVar1;
  
  if (_DAT_00020020 < 0x65) {
    FUN_0102024c(&DAT_00020025,3);
    uVar1 = FUN_010182dc(0x20029);
    FUN_0102024c(uVar1,CONCAT11(DAT_00020028,DAT_00020027));
    _DAT_00020020 = _DAT_00020020 + 1;
    log_empty(0x10191c8);
  }
  else {
    log_empty(0x10191cc);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01018f40 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01018f40(void)
{
  undefined4 uVar1;
  
  FUN_0102024c(&DAT_00020025,3);
  uVar1 = FUN_010182dc(0x20029);
  FUN_0102024c(uVar1,CONCAT11(DAT_00020028,DAT_00020027));
  _DAT_00020020 = _DAT_00020020 + 1;
  log_empty(STR_010191d0,DAT_00020026,_DAT_00020020);
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01018f42 */
#ifdef NONMATCHING
void thunk_FUN_01019732(void)
{
  undefined1 *puVar1;
  int iVar2;
  
  FUN_01018aa4(&DAT_00020010,0x20);
  puVar1 = (undefined1 *)FUN_010182dc(0x20029);
  DAT_00020018 = *puVar1;
  iVar2 = FUN_010182dc(0x20029);
  DAT_00020019 = *(undefined1 *)(iVar2 + 1);
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01018f44 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01018f44(void)
{
  undefined4 uVar1;
  
  FUN_0102024c(&DAT_00020025,3);
  uVar1 = FUN_010182dc(0x20029);
  FUN_0102024c(uVar1,CONCAT11(DAT_00020028,DAT_00020027));
  _DAT_00020020 = _DAT_00020020 + 1;
  log_empty(STR_010191d0,DAT_00020026,_DAT_00020020);
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01018f46 */
#ifdef NONMATCHING
void switchD_01018ebe__caseD_bc(void)
{
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01018f48 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01018f48(void)
{
  undefined4 uVar1;
  
  FUN_0102024c(&DAT_00020025,3);
  uVar1 = FUN_010182dc(0x20029);
  FUN_0102024c(uVar1,CONCAT11(DAT_00020028,DAT_00020027));
  _DAT_00020020 = _DAT_00020020 + 1;
  log_empty(STR_010191d0,DAT_00020026,_DAT_00020020);
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01018f4a */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01018f4a(void)
{
  undefined4 uVar1;
  
  FUN_0102024c(&DAT_00020025,3);
  uVar1 = FUN_010182dc(0x20029);
  FUN_0102024c(uVar1,CONCAT11(DAT_00020028,DAT_00020027));
  _DAT_00020020 = _DAT_00020020 + 1;
  log_empty(STR_010191d0,DAT_00020026,_DAT_00020020);
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01018f4c */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01018f4c(void)
{
  undefined4 uVar1;
  
  FUN_0102024c(&DAT_00020025,3);
  uVar1 = FUN_010182dc(0x20029);
  FUN_0102024c(uVar1,CONCAT11(DAT_00020028,DAT_00020027));
  _DAT_00020020 = _DAT_00020020 + 1;
  log_empty(STR_010191d0,DAT_00020026,_DAT_00020020);
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01018f4e */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_01018f92(void)
{
  undefined4 uVar1;
  
  FUN_0102024c(&DAT_00020025,3);
  uVar1 = FUN_010182dc(0x20029);
  FUN_0102024c(uVar1,CONCAT11(DAT_00020028,DAT_00020027));
  _DAT_00020020 = _DAT_00020020 + 1;
  log_empty(STR_010191d0,DAT_00020026,_DAT_00020020);
  log_empty(FUN_010191f4);
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01018f82 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_01019028(void)
{
  undefined4 uVar1;
  
  FUN_0102024c(&DAT_00020025,3);
  uVar1 = FUN_010182dc(0x20029);
  FUN_0102024c(uVar1,CONCAT11(DAT_00020028,DAT_00020027));
  _DAT_00020020 = _DAT_00020020 + 1;
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01018f84 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_01018fd6(void)
{
  undefined4 uVar1;
  
  FUN_0102024c(&DAT_00020025,3);
  uVar1 = FUN_010182dc(0x20029);
  FUN_0102024c(uVar1,CONCAT11(DAT_00020028,DAT_00020027));
  _DAT_00020020 = _DAT_00020020 + 1;
  log_empty(STR_010191d0,DAT_00020026,_DAT_00020020);
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01018f86 */
#ifdef NONMATCHING
void thunk_FUN_01019754(void)
{
  char *pcVar1;
  
  pcVar1 = (char *)FUN_010182dc(0x20029);
  if (*pcVar1 == '\0') {
    FUN_01018aa4(&DAT_00020010,0x28);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01018f88 */
#ifdef NONMATCHING
void thunk_FUN_0101976e(void)
{
  char *pcVar1;
  
  pcVar1 = (char *)FUN_010182dc(0x20029);
  if ((*pcVar1 == '\x03') || (pcVar1 = (char *)FUN_010182dc(0x20029), *pcVar1 == '\x04')) {
    FUN_01018aa4(&DAT_00020010,0x29);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01018f8a */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_01019790(void)
{
  undefined4 uVar1;
  
  FUN_0102024c(&DAT_00020025,3);
  uVar1 = FUN_010182dc(0x20029);
  FUN_0102024c(uVar1,_DAT_00020027);
  _DAT_00020020 = _DAT_00020020 + 1;
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01018f92 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01018f92(void)
{
  undefined4 uVar1;
  
  FUN_0102024c(&DAT_00020025,3);
  uVar1 = FUN_010182dc(0x20029);
  FUN_0102024c(uVar1,CONCAT11(DAT_00020028,DAT_00020027));
  _DAT_00020020 = _DAT_00020020 + 1;
  log_empty(STR_010191d0,DAT_00020026,_DAT_00020020);
  log_empty(FUN_010191f4);
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01018fd6 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01018fd6(void)
{
  undefined4 uVar1;
  
  FUN_0102024c(&DAT_00020025,3);
  uVar1 = FUN_010182dc(0x20029);
  FUN_0102024c(uVar1,CONCAT11(DAT_00020028,DAT_00020027));
  _DAT_00020020 = _DAT_00020020 + 1;
  log_empty(STR_010191d0,DAT_00020026,_DAT_00020020);
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01019014 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_01019062(void)
{
  undefined4 uVar1;
  
  FUN_0102024c(&DAT_00020025,3);
  uVar1 = FUN_010182dc(0x20029);
  FUN_0102024c(uVar1,CONCAT11(DAT_00020028,DAT_00020027));
  _DAT_00020020 = _DAT_00020020 + 1;
  log_empty(STR_010191d0,DAT_00020026,_DAT_00020020);
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01019016 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01019016(void)
{
  undefined4 uVar1;
  
  FUN_0102024c(&DAT_00020025,3);
  uVar1 = FUN_010182dc(0x20029);
  FUN_0102024c(uVar1,CONCAT11(DAT_00020028,DAT_00020027));
  _DAT_00020020 = _DAT_00020020 + 1;
  log_empty(STR_010191d0,DAT_00020026,_DAT_00020020);
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01019018 */
#ifdef NONMATCHING
void thunk_FUN_01019718(void)
{
  undefined1 *puVar1;
  
  FUN_01018aa4(&DAT_00020010,7);
  puVar1 = (undefined1 *)FUN_010182dc(0x20029);
  DAT_00020018 = *puVar1;
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 0101901a */
#ifdef NONMATCHING
void thunk_FUN_0101970e(void)
{
  FUN_01018aa4(&DAT_00020010,0x1c);
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 0101901c */
#ifdef NONMATCHING
void thunk_FUN_010190ca(void)
{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  bool bVar4;
  
  pbVar2 = (byte *)FUN_010182dc(0x20029);
  bVar1 = *pbVar2;
  if (bVar1 == 0x39) {
    iVar3 = FUN_010182dc(0x20029);
    if (*(char *)(iVar3 + 1) == '\0') {
      FUN_01018aa4(&DAT_00020010,0x36);
    }
    goto code_r0x0101970c;
  }
  if (bVar1 < 0x3a) {
    if (bVar1 == 0x11) {
      iVar3 = FUN_010182dc(0x20029);
      log_empty(STR_01019690,*(undefined1 *)(iVar3 + 1));
      iVar3 = FUN_010182dc(0x20029);
      if (*(char *)(iVar3 + 1) == '\0') {
        FUN_01018aa4(&DAT_00020010,0xb);
      }
      goto code_r0x0101970c;
    }
    if (bVar1 < 0x12) {
                    /* WARNING: Subroutine does not return */
      yc_switch8();
    }
    if (bVar1 == 0x33) {
      iVar3 = FUN_010182dc(0x20029);
      if (*(char *)(iVar3 + 1) == '\0') {
        FUN_01018aa4(&DAT_00020010,0x14);
      }
      goto code_r0x0101970c;
    }
    if (bVar1 < 0x34) {
      if (bVar1 == 0x26) {
        iVar3 = FUN_010182dc(0x20029);
        if (*(char *)(iVar3 + 1) == '\0') {
          FUN_01018aa4(&DAT_00020010,0xd);
        }
        goto code_r0x0101970c;
      }
      if (bVar1 < 0x27) {
        if (bVar1 == 0x12) {
          iVar3 = FUN_010182dc(0x20029);
          if (*(char *)(iVar3 + 1) == '\0') {
            FUN_01018aa4(&DAT_00020010,0xc);
          }
          goto code_r0x0101970c;
        }
        bVar4 = bVar1 == 0x15;
      }
      else {
        if (bVar1 == 0x28) {
          iVar3 = FUN_010182dc(0x20029);
          if (*(char *)(iVar3 + 1) == '\0') {
            FUN_01018aa4(&DAT_00020010,0x10);
          }
          goto code_r0x0101970c;
        }
        bVar4 = false;
        if (bVar1 == 0x30) {
          FUN_0101943a();
          return;
        }
      }
    }
    else {
      if (bVar1 == 0x34) {
        iVar3 = FUN_010182dc(0x20029);
        if (*(char *)(iVar3 + 1) == '\0') {
          FUN_01018aa4(&DAT_00020010,0x15);
        }
        goto code_r0x0101970c;
      }
      if (bVar1 == 0x35) {
        iVar3 = FUN_010182dc(0x20029);
        if (*(char *)(iVar3 + 1) == '\0') {
          FUN_01018aa4(&DAT_00020010,0x16);
        }
        goto code_r0x0101970c;
      }
      if (bVar1 == 0x36) {
        iVar3 = FUN_010182dc(0x20029);
        if (*(char *)(iVar3 + 1) == '\0') {
          FUN_01018aa4(&DAT_00020010,0x17);
        }
        goto code_r0x0101970c;
      }
      bVar4 = false;
      if (bVar1 == 0x37) {
        FUN_01019492();
        return;
      }
    }
  }
  else {
    if (bVar1 == 0x82) {
      iVar3 = FUN_010182dc(0x20029);
      if (*(char *)(iVar3 + 1) == '\0') {
        FUN_01018aa4(&DAT_00020010,0x21);
      }
      goto code_r0x0101970c;
    }
    if (bVar1 < 0x83) {
      if (bVar1 == 0x79) {
        iVar3 = FUN_010182dc(0x20029);
        if (*(char *)(iVar3 + 1) == '\0') {
          FUN_01018aa4(&DAT_00020010,0x37);
        }
        goto code_r0x0101970c;
      }
      if (bVar1 < 0x7a) {
        if (bVar1 == 0x61) {
          iVar3 = FUN_010182dc(0x20029);
          if (*(char *)(iVar3 + 1) == '\0') {
            FUN_01018aa4(&DAT_00020010,0x1a);
          }
          goto code_r0x0101970c;
        }
        if (bVar1 < 0x62) {
          if (bVar1 == 0x42) {
            iVar3 = FUN_010182dc(0x20029);
            if (*(char *)(iVar3 + 1) == '\0') {
              FUN_01018aa4(&DAT_00020010,0xe);
            }
            goto code_r0x0101970c;
          }
          bVar4 = false;
          if (bVar1 == 0x49) {
            FUN_010194ea();
            return;
          }
        }
        else {
          if (bVar1 == 0x70) {
            iVar3 = FUN_010182dc(0x20029);
            log_empty(STR_0101965c,*(undefined1 *)(iVar3 + 1));
            iVar3 = FUN_010182dc(0x20029);
            if (*(char *)(iVar3 + 1) == '\0') {
              FUN_01018aa4(&DAT_00020010,0x35);
            }
            goto code_r0x0101970c;
          }
          bVar4 = false;
          if (bVar1 == 0x76) {
            FUN_01019516();
            return;
          }
        }
      }
      else {
        if (bVar1 == 0x7e) {
          iVar3 = FUN_010182dc(0x20029);
          if (*(char *)(iVar3 + 1) == '\0') {
            FUN_01018aa4(&DAT_00020010,0x22);
          }
          goto code_r0x0101970c;
        }
        if (bVar1 == 0x7f) {
          iVar3 = FUN_010182dc(0x20029);
          if (*(char *)(iVar3 + 1) == '\0') {
            FUN_01018aa4(&DAT_00020010,0x23);
          }
          goto code_r0x0101970c;
        }
        if (bVar1 == 0x80) {
          iVar3 = FUN_010182dc(0x20029);
          if (*(char *)(iVar3 + 1) == '\0') {
            FUN_01018aa4(&DAT_00020010,0x25);
          }
          goto code_r0x0101970c;
        }
        bVar4 = false;
        if (bVar1 == 0x81) {
          FUN_01019584();
          return;
        }
      }
    }
    else {
      if (bVar1 == 0xa2) {
        iVar3 = FUN_010182dc(0x20029);
        log_empty(STR_01019630,*(undefined1 *)(iVar3 + 1));
        iVar3 = FUN_010182dc(0x20029);
        if (*(char *)(iVar3 + 1) == '\0') {
          FUN_01018aa4(&DAT_00020010,0x34);
        }
        goto code_r0x0101970c;
      }
      if (0xa2 < bVar1) {
        if (bVar1 != 0xb0) {
          if (bVar1 == 0xb1) {
            iVar3 = FUN_010182dc(0x20029);
            if (*(char *)(iVar3 + 1) == '\0') {
              FUN_01018aa4(&DAT_00020010,0x2c);
            }
            goto code_r0x0101970c;
          }
          if (bVar1 != 0xb2) {
            bVar4 = false;
            if (bVar1 == 0xff) {
              FUN_01019424();
              return;
            }
            goto LAB_0101910c;
          }
        }
        iVar3 = FUN_010182dc(0x20029);
        if (*(char *)(iVar3 + 1) == '\0') {
          FUN_01018aa4(&DAT_00020010,5);
        }
        goto code_r0x0101970c;
      }
      if (bVar1 == 0x84) {
        iVar3 = FUN_010182dc(0x20029);
        if (*(char *)(iVar3 + 1) == '\0') {
          FUN_01018aa4(&DAT_00020010,0x26);
        }
        goto code_r0x0101970c;
      }
      if (bVar1 == 0x85) {
        iVar3 = FUN_010182dc(0x20029);
        if (*(char *)(iVar3 + 1) == '\0') {
          FUN_01018aa4(&DAT_00020010,0x27);
        }
        goto code_r0x0101970c;
      }
      if (bVar1 == 0xa0) {
        iVar3 = FUN_010182dc(0x20029);
        FUN_01019214(iVar3,*(undefined1 *)(iVar3 + 1));
        return;
      }
      bVar4 = false;
      if (bVar1 == 0xa1) {
        FUN_0101923a();
        return;
      }
    }
  }
LAB_0101910c:
  if (bVar4) {
    FUN_01019500();
    return;
  }
code_r0x0101970c:
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 0101901e */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0101901e(void)
{
  undefined4 uVar1;
  
  FUN_0102024c(&DAT_00020025,3);
  uVar1 = FUN_010182dc(0x20029);
  FUN_0102024c(uVar1,CONCAT11(DAT_00020028,DAT_00020027));
  _DAT_00020020 = _DAT_00020020 + 1;
  log_empty(STR_010191d0,DAT_00020026,_DAT_00020020);
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01019020 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01019020(void)
{
  undefined4 uVar1;
  
  FUN_0102024c(&DAT_00020025,3);
  uVar1 = FUN_010182dc(0x20029);
  FUN_0102024c(uVar1,CONCAT11(DAT_00020028,DAT_00020027));
  _DAT_00020020 = _DAT_00020020 + 1;
  log_empty(STR_010191d0,DAT_00020026,_DAT_00020020);
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01019022 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_01019060(void)
{
  undefined4 uVar1;
  
  FUN_0102024c(&DAT_00020025,3);
  uVar1 = FUN_010182dc(0x20029);
  FUN_0102024c(uVar1,CONCAT11(DAT_00020028,DAT_00020027));
  _DAT_00020020 = _DAT_00020020 + 1;
  log_empty(STR_010191d0,DAT_00020026,_DAT_00020020);
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01019024 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_0101905e(void)
{
  undefined4 uVar1;
  
  FUN_0102024c(&DAT_00020025,3);
  uVar1 = FUN_010182dc(0x20029);
  FUN_0102024c(uVar1,CONCAT11(DAT_00020028,DAT_00020027));
  _DAT_00020020 = _DAT_00020020 + 1;
  log_empty(STR_010191d0,DAT_00020026,_DAT_00020020);
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01019026 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void switchD_01018ebe__caseD_b9(void)
{
  undefined4 uVar1;
  
  FUN_0102024c(&DAT_00020025,3);
  uVar1 = FUN_010182dc(0x20029);
  FUN_0102024c(uVar1,CONCAT11(DAT_00020028,DAT_00020027));
  _DAT_00020020 = _DAT_00020020 + 1;
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01019028 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01019028(void)
{
  undefined4 uVar1;
  
  FUN_0102024c(&DAT_00020025,3);
  uVar1 = FUN_010182dc(0x20029);
  FUN_0102024c(uVar1,CONCAT11(DAT_00020028,DAT_00020027));
  _DAT_00020020 = _DAT_00020020 + 1;
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 0101905e */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0101905e(void)
{
  undefined4 uVar1;
  
  FUN_0102024c(&DAT_00020025,3);
  uVar1 = FUN_010182dc(0x20029);
  FUN_0102024c(uVar1,CONCAT11(DAT_00020028,DAT_00020027));
  _DAT_00020020 = _DAT_00020020 + 1;
  log_empty(STR_010191d0,DAT_00020026,_DAT_00020020);
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01019060 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01019060(void)
{
  undefined4 uVar1;
  
  FUN_0102024c(&DAT_00020025,3);
  uVar1 = FUN_010182dc(0x20029);
  FUN_0102024c(uVar1,CONCAT11(DAT_00020028,DAT_00020027));
  _DAT_00020020 = _DAT_00020020 + 1;
  log_empty(STR_010191d0,DAT_00020026,_DAT_00020020);
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01019062 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01019062(void)
{
  undefined4 uVar1;
  
  FUN_0102024c(&DAT_00020025,3);
  uVar1 = FUN_010182dc(0x20029);
  FUN_0102024c(uVar1,CONCAT11(DAT_00020028,DAT_00020027));
  _DAT_00020020 = _DAT_00020020 + 1;
  log_empty(STR_010191d0,DAT_00020026,_DAT_00020020);
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 010190ca */
#ifdef NONMATCHING
void FUN_010190ca(void)
{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  bool bVar4;
  
  pbVar2 = (byte *)FUN_010182dc(0x20029);
  bVar1 = *pbVar2;
  if (bVar1 == 0x39) {
    iVar3 = FUN_010182dc(0x20029);
    if (*(char *)(iVar3 + 1) == '\0') {
      FUN_01018aa4(&DAT_00020010,0x36);
    }
    goto code_r0x0101970c;
  }
  if (bVar1 < 0x3a) {
    if (bVar1 == 0x11) {
      iVar3 = FUN_010182dc(0x20029);
      log_empty(STR_01019690,*(undefined1 *)(iVar3 + 1));
      iVar3 = FUN_010182dc(0x20029);
      if (*(char *)(iVar3 + 1) == '\0') {
        FUN_01018aa4(&DAT_00020010,0xb);
      }
      goto code_r0x0101970c;
    }
    if (bVar1 < 0x12) {
                    /* WARNING: Subroutine does not return */
      yc_switch8();
    }
    if (bVar1 == 0x33) {
      iVar3 = FUN_010182dc(0x20029);
      if (*(char *)(iVar3 + 1) == '\0') {
        FUN_01018aa4(&DAT_00020010,0x14);
      }
      goto code_r0x0101970c;
    }
    if (bVar1 < 0x34) {
      if (bVar1 == 0x26) {
        iVar3 = FUN_010182dc(0x20029);
        if (*(char *)(iVar3 + 1) == '\0') {
          FUN_01018aa4(&DAT_00020010,0xd);
        }
        goto code_r0x0101970c;
      }
      if (bVar1 < 0x27) {
        if (bVar1 == 0x12) {
          iVar3 = FUN_010182dc(0x20029);
          if (*(char *)(iVar3 + 1) == '\0') {
            FUN_01018aa4(&DAT_00020010,0xc);
          }
          goto code_r0x0101970c;
        }
        bVar4 = bVar1 == 0x15;
      }
      else {
        if (bVar1 == 0x28) {
          iVar3 = FUN_010182dc(0x20029);
          if (*(char *)(iVar3 + 1) == '\0') {
            FUN_01018aa4(&DAT_00020010,0x10);
          }
          goto code_r0x0101970c;
        }
        bVar4 = false;
        if (bVar1 == 0x30) {
          FUN_0101943a();
          return;
        }
      }
    }
    else {
      if (bVar1 == 0x34) {
        iVar3 = FUN_010182dc(0x20029);
        if (*(char *)(iVar3 + 1) == '\0') {
          FUN_01018aa4(&DAT_00020010,0x15);
        }
        goto code_r0x0101970c;
      }
      if (bVar1 == 0x35) {
        iVar3 = FUN_010182dc(0x20029);
        if (*(char *)(iVar3 + 1) == '\0') {
          FUN_01018aa4(&DAT_00020010,0x16);
        }
        goto code_r0x0101970c;
      }
      if (bVar1 == 0x36) {
        iVar3 = FUN_010182dc(0x20029);
        if (*(char *)(iVar3 + 1) == '\0') {
          FUN_01018aa4(&DAT_00020010,0x17);
        }
        goto code_r0x0101970c;
      }
      bVar4 = false;
      if (bVar1 == 0x37) {
        FUN_01019492();
        return;
      }
    }
  }
  else {
    if (bVar1 == 0x82) {
      iVar3 = FUN_010182dc(0x20029);
      if (*(char *)(iVar3 + 1) == '\0') {
        FUN_01018aa4(&DAT_00020010,0x21);
      }
      goto code_r0x0101970c;
    }
    if (bVar1 < 0x83) {
      if (bVar1 == 0x79) {
        iVar3 = FUN_010182dc(0x20029);
        if (*(char *)(iVar3 + 1) == '\0') {
          FUN_01018aa4(&DAT_00020010,0x37);
        }
        goto code_r0x0101970c;
      }
      if (bVar1 < 0x7a) {
        if (bVar1 == 0x61) {
          iVar3 = FUN_010182dc(0x20029);
          if (*(char *)(iVar3 + 1) == '\0') {
            FUN_01018aa4(&DAT_00020010,0x1a);
          }
          goto code_r0x0101970c;
        }
        if (bVar1 < 0x62) {
          if (bVar1 == 0x42) {
            iVar3 = FUN_010182dc(0x20029);
            if (*(char *)(iVar3 + 1) == '\0') {
              FUN_01018aa4(&DAT_00020010,0xe);
            }
            goto code_r0x0101970c;
          }
          bVar4 = false;
          if (bVar1 == 0x49) {
            FUN_010194ea();
            return;
          }
        }
        else {
          if (bVar1 == 0x70) {
            iVar3 = FUN_010182dc(0x20029);
            log_empty(STR_0101965c,*(undefined1 *)(iVar3 + 1));
            iVar3 = FUN_010182dc(0x20029);
            if (*(char *)(iVar3 + 1) == '\0') {
              FUN_01018aa4(&DAT_00020010,0x35);
            }
            goto code_r0x0101970c;
          }
          bVar4 = false;
          if (bVar1 == 0x76) {
            FUN_01019516();
            return;
          }
        }
      }
      else {
        if (bVar1 == 0x7e) {
          iVar3 = FUN_010182dc(0x20029);
          if (*(char *)(iVar3 + 1) == '\0') {
            FUN_01018aa4(&DAT_00020010,0x22);
          }
          goto code_r0x0101970c;
        }
        if (bVar1 == 0x7f) {
          iVar3 = FUN_010182dc(0x20029);
          if (*(char *)(iVar3 + 1) == '\0') {
            FUN_01018aa4(&DAT_00020010,0x23);
          }
          goto code_r0x0101970c;
        }
        if (bVar1 == 0x80) {
          iVar3 = FUN_010182dc(0x20029);
          if (*(char *)(iVar3 + 1) == '\0') {
            FUN_01018aa4(&DAT_00020010,0x25);
          }
          goto code_r0x0101970c;
        }
        bVar4 = false;
        if (bVar1 == 0x81) {
          FUN_01019584();
          return;
        }
      }
    }
    else {
      if (bVar1 == 0xa2) {
        iVar3 = FUN_010182dc(0x20029);
        log_empty(STR_01019630,*(undefined1 *)(iVar3 + 1));
        iVar3 = FUN_010182dc(0x20029);
        if (*(char *)(iVar3 + 1) == '\0') {
          FUN_01018aa4(&DAT_00020010,0x34);
        }
        goto code_r0x0101970c;
      }
      if (0xa2 < bVar1) {
        if (bVar1 != 0xb0) {
          if (bVar1 == 0xb1) {
            iVar3 = FUN_010182dc(0x20029);
            if (*(char *)(iVar3 + 1) == '\0') {
              FUN_01018aa4(&DAT_00020010,0x2c);
            }
            goto code_r0x0101970c;
          }
          if (bVar1 != 0xb2) {
            bVar4 = false;
            if (bVar1 == 0xff) {
              FUN_01019424();
              return;
            }
            goto LAB_0101910c;
          }
        }
        iVar3 = FUN_010182dc(0x20029);
        if (*(char *)(iVar3 + 1) == '\0') {
          FUN_01018aa4(&DAT_00020010,5);
        }
        goto code_r0x0101970c;
      }
      if (bVar1 == 0x84) {
        iVar3 = FUN_010182dc(0x20029);
        if (*(char *)(iVar3 + 1) == '\0') {
          FUN_01018aa4(&DAT_00020010,0x26);
        }
        goto code_r0x0101970c;
      }
      if (bVar1 == 0x85) {
        iVar3 = FUN_010182dc(0x20029);
        if (*(char *)(iVar3 + 1) == '\0') {
          FUN_01018aa4(&DAT_00020010,0x27);
        }
        goto code_r0x0101970c;
      }
      if (bVar1 == 0xa0) {
        iVar3 = FUN_010182dc(0x20029);
        FUN_01019214(iVar3,*(undefined1 *)(iVar3 + 1));
        return;
      }
      bVar4 = false;
      if (bVar1 == 0xa1) {
        FUN_0101923a();
        return;
      }
    }
  }
LAB_0101910c:
  if (bVar4) {
    FUN_01019500();
    return;
  }
code_r0x0101970c:
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 0101918e */
#ifdef NONMATCHING
void FUN_0101918e(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,0);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 010191a6 */
#ifdef NONMATCHING
void FUN_010191a6(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  FUN_01019214(iVar1,*(undefined1 *)(iVar1 + 1));
  return;
}
#endif

/* 010191b4 */
#ifdef NONMATCHING
void thunk_FUN_010194be(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,0x36);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 010191b6 */
#ifdef NONMATCHING
void thunk_FUN_010193bc(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  log_empty(STR_01019690,*(undefined1 *)(iVar1 + 1));
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,0xb);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 010191c4 */
#ifdef NONMATCHING
void FUN_010191c4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  byte bVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  byte *unaff_r4;
  int unaff_r5;
  byte *pbVar5;
  undefined4 unaff_r7;
  
  *(undefined4 *)(unaff_r5 + 0x34) = param_1;
  sVar2 = *(short *)(unaff_r5 * 2);
  unaff_r4[0x11] = (byte)unaff_r5;
  pbVar5 = *(byte **)(unaff_r5 + 0x70);
  *(undefined4 *)(pbVar5 + 0x34) = param_1;
  *(undefined4 *)(unaff_r5 + 0x44) = unaff_r7;
  uVar3 = (uint)*pbVar5;
  bVar1 = *unaff_r4;
  *(uint *)(unaff_r4 + uVar3) = uVar3;
  *(int *)(unaff_r4 + 0x34) = (int)sVar2;
  *(undefined4 *)(bVar1 + 0x54) = param_4;
  iVar4 = FUN_010182dc(0x20029,_FUN_010193bc,(int)sVar2);
  if (*(char *)(iVar4 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,0x14);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 010191f4 */
#ifdef NONMATCHING
void FUN_010191f4(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,0x14);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 010191fc */
#ifdef NONMATCHING
void thunk_FUN_010193a6(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,0x14);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 010191fe */
#ifdef NONMATCHING
void thunk_FUN_010193f8(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,0xd);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01019200 */
#ifdef NONMATCHING
void thunk_FUN_010193e2(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,0xc);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01019202 */
#ifdef NONMATCHING
void thunk_FUN_01019708(void)
{
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01019204 */
#ifdef NONMATCHING
void thunk_FUN_0101940e(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,0x10);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01019206 */
#ifdef NONMATCHING
void thunk_FUN_01019450(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,0x15);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01019208 */
#ifdef NONMATCHING
void thunk_FUN_01019466(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,0x16);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 0101920a */
#ifdef NONMATCHING
void thunk_FUN_0101947c(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,0x17);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 0101920c */
#ifdef NONMATCHING
void thunk_FUN_010196c0(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,0x21);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 0101920e */
#ifdef NONMATCHING
void thunk_FUN_010194d4(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,0x37);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01019210 */
#ifdef NONMATCHING
void thunk_FUN_0101952c(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,0x1a);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01019212 */
#ifdef NONMATCHING
void thunk_FUN_010194a8(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,0xe);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01019214 */
#ifdef NONMATCHING
void FUN_01019214(void)
{
  int iVar1;
  
  log_empty(STR_010195c8);
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,0x32);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01019230 */
#ifdef NONMATCHING
void thunk_FUN_01019290(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  log_empty(STR_0101965c,*(undefined1 *)(iVar1 + 1));
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,0x35);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01019232 */
#ifdef NONMATCHING
void thunk_FUN_01019542(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,0x22);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01019234 */
#ifdef NONMATCHING
void thunk_FUN_01019558(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,0x23);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01019236 */
#ifdef NONMATCHING
void thunk_FUN_0101956e(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,0x25);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01019238 */
#ifdef NONMATCHING
void thunk_FUN_0101926a(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  log_empty(STR_01019630,*(undefined1 *)(iVar1 + 1));
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,0x34);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 0101923a */
#ifdef NONMATCHING
void FUN_0101923a(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  log_empty(STR_01019600,*(undefined1 *)(iVar1 + 1));
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,0x33);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01019260 */
#ifdef NONMATCHING
void thunk_FUN_0101959a(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,0x26);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01019262 */
#ifdef NONMATCHING
void thunk_FUN_010195b0(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,0x27);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01019264 */
#ifdef NONMATCHING
void thunk_FUN_010196d6(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,5);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01019266 */
#ifdef NONMATCHING
void thunk_FUN_010196ee(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,0x2c);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01019268 */
#ifdef NONMATCHING
void FUN_01019268(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,5);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 0101926a */
#ifdef NONMATCHING
void FUN_0101926a(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  log_empty(STR_01019630,*(undefined1 *)(iVar1 + 1));
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,0x34);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01019290 */
#ifdef NONMATCHING
void FUN_01019290(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  log_empty(STR_0101965c,*(undefined1 *)(iVar1 + 1));
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,0x35);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 010192b6 */
#ifdef NONMATCHING
void thunk_FUN_01019378(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,10);
    iVar1 = FUN_010182dc(0x20029);
    DAT_00020018 = *(undefined1 *)(iVar1 + 2);
    iVar1 = FUN_010182dc(0x20029);
    DAT_00020019 = *(undefined1 *)(iVar1 + 3);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 010192b8 */
#ifdef NONMATCHING
void thunk_FUN_01019362(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,9);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 010192ba */
#ifdef NONMATCHING
void thunk_FUN_0101934c(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,8);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 010192bc */
#ifdef NONMATCHING
void thunk_FUN_01019336(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,6);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 010192be */
#ifdef NONMATCHING
void thunk_FUN_01019320(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,5);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 010192c0 */
#ifdef NONMATCHING
void thunk_FUN_0101930a(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,4);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 010192c2 */
#ifdef NONMATCHING
void thunk_FUN_010192f4(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,3);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 010192c4 */
#ifdef NONMATCHING
void thunk_FUN_010192de(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,2);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 010192c6 */
#ifdef NONMATCHING
void thunk_FUN_010192c8(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,1);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 010192c8 */
#ifdef NONMATCHING
void FUN_010192c8(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,1);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 010192de */
#ifdef NONMATCHING
void FUN_010192de(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,2);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 010192f4 */
#ifdef NONMATCHING
void FUN_010192f4(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,3);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 0101930a */
#ifdef NONMATCHING
void FUN_0101930a(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,4);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01019320 */
#ifdef NONMATCHING
void FUN_01019320(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,5);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01019336 */
#ifdef NONMATCHING
void FUN_01019336(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,6);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 0101934c */
#ifdef NONMATCHING
void FUN_0101934c(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,8);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01019362 */
#ifdef NONMATCHING
void FUN_01019362(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,9);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01019378 */
#ifdef NONMATCHING
void FUN_01019378(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,10);
    iVar1 = FUN_010182dc(0x20029);
    DAT_00020018 = *(undefined1 *)(iVar1 + 2);
    iVar1 = FUN_010182dc(0x20029);
    DAT_00020019 = *(undefined1 *)(iVar1 + 3);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 010193a6 */
#ifdef NONMATCHING
void FUN_010193a6(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,0x14);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 010193bc */
#ifdef NONMATCHING
void FUN_010193bc(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  log_empty(STR_01019690,*(undefined1 *)(iVar1 + 1));
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,0xb);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 010193e2 */
#ifdef NONMATCHING
void FUN_010193e2(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,0xc);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 010193f8 */
#ifdef NONMATCHING
void FUN_010193f8(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,0xd);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 0101940e */
#ifdef NONMATCHING
void FUN_0101940e(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,0x10);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01019424 */
#ifdef NONMATCHING
void FUN_01019424(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,0x2a);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 0101943a */
#ifdef NONMATCHING
void FUN_0101943a(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,0x13);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01019450 */
#ifdef NONMATCHING
void FUN_01019450(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,0x15);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01019466 */
#ifdef NONMATCHING
void FUN_01019466(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,0x16);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 0101947c */
#ifdef NONMATCHING
void FUN_0101947c(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,0x17);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01019492 */
#ifdef NONMATCHING
void FUN_01019492(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,0x18);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 010194a8 */
#ifdef NONMATCHING
void FUN_010194a8(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,0xe);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 010194be */
#ifdef NONMATCHING
void FUN_010194be(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,0x36);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 010194d4 */
#ifdef NONMATCHING
void FUN_010194d4(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,0x37);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 010194ea */
#ifdef NONMATCHING
void FUN_010194ea(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,0x19);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01019500 */
#ifdef NONMATCHING
void FUN_01019500(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,0x1d);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01019516 */
#ifdef NONMATCHING
void FUN_01019516(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,0x1f);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 0101952c */
#ifdef NONMATCHING
void FUN_0101952c(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,0x1a);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01019542 */
#ifdef NONMATCHING
void FUN_01019542(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,0x22);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01019558 */
#ifdef NONMATCHING
void FUN_01019558(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,0x23);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 0101956e */
#ifdef NONMATCHING
void FUN_0101956e(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,0x25);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01019584 */
#ifdef NONMATCHING
void FUN_01019584(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,0x24);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 0101959a */
#ifdef NONMATCHING
void FUN_0101959a(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,0x26);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 010195b0 */
#ifdef NONMATCHING
void FUN_010195b0(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,0x27);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 010195c6 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_010197c4(void)
{
  undefined4 uVar1;
  
  FUN_0102024c(&DAT_00020025,3);
  uVar1 = FUN_010182dc(0x20029);
  FUN_0102024c(uVar1,_DAT_00020027);
  _DAT_00020020 = _DAT_00020020 + 1;
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 010196c0 */
#ifdef NONMATCHING
void FUN_010196c0(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,0x21);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 010196d6 */
#ifdef NONMATCHING
void FUN_010196d6(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,5);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 010196ee */
#ifdef NONMATCHING
void FUN_010196ee(void)
{
  int iVar1;
  
  iVar1 = FUN_010182dc(0x20029);
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_01018aa4(&DAT_00020010,0x2c);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01019704 */
#ifdef NONMATCHING
void FUN_01019704(void)
{
  return;
}
#endif

/* 01019708 */
#ifdef NONMATCHING
void FUN_01019708(void)
{
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 0101970e */
#ifdef NONMATCHING
void FUN_0101970e(void)
{
  FUN_01018aa4(&DAT_00020010,0x1c);
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01019718 */
#ifdef NONMATCHING
void FUN_01019718(void)
{
  undefined1 *puVar1;
  
  FUN_01018aa4(&DAT_00020010,7);
  puVar1 = (undefined1 *)FUN_010182dc(0x20029);
  DAT_00020018 = *puVar1;
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 0101972e */
#ifdef NONMATCHING
void thunk_FUN_01019732(void)
{
  undefined1 *puVar1;
  int iVar2;
  
  FUN_01018aa4(&DAT_00020010,0x20);
  puVar1 = (undefined1 *)FUN_010182dc(0x20029);
  DAT_00020018 = *puVar1;
  iVar2 = FUN_010182dc(0x20029);
  DAT_00020019 = *(undefined1 *)(iVar2 + 1);
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01019730 */
#ifdef NONMATCHING
void thunk_FUN_01019806(void)
{
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01019732 */
#ifdef NONMATCHING
void FUN_01019732(void)
{
  undefined1 *puVar1;
  int iVar2;
  
  FUN_01018aa4(&DAT_00020010,0x20);
  puVar1 = (undefined1 *)FUN_010182dc(0x20029);
  DAT_00020018 = *puVar1;
  iVar2 = FUN_010182dc(0x20029);
  DAT_00020019 = *(undefined1 *)(iVar2 + 1);
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01019754 */
#ifdef NONMATCHING
void FUN_01019754(void)
{
  char *pcVar1;
  
  pcVar1 = (char *)FUN_010182dc(0x20029);
  if (*pcVar1 == '\0') {
    FUN_01018aa4(&DAT_00020010,0x28);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 0101976a */
#ifdef NONMATCHING
void thunk_FUN_0101976e(void)
{
  char *pcVar1;
  
  pcVar1 = (char *)FUN_010182dc(0x20029);
  if ((*pcVar1 == '\x03') || (pcVar1 = (char *)FUN_010182dc(0x20029), *pcVar1 == '\x04')) {
    FUN_01018aa4(&DAT_00020010,0x29);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 0101976c */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_01019790(void)
{
  undefined4 uVar1;
  
  FUN_0102024c(&DAT_00020025,3);
  uVar1 = FUN_010182dc(0x20029);
  FUN_0102024c(uVar1,_DAT_00020027);
  _DAT_00020020 = _DAT_00020020 + 1;
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 0101976e */
#ifdef NONMATCHING
void FUN_0101976e(void)
{
  char *pcVar1;
  
  pcVar1 = (char *)FUN_010182dc(0x20029);
  if ((*pcVar1 == '\x03') || (pcVar1 = (char *)FUN_010182dc(0x20029), *pcVar1 == '\x04')) {
    FUN_01018aa4(&DAT_00020010,0x29);
  }
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01019790 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01019790(void)
{
  undefined4 uVar1;
  
  FUN_0102024c(&DAT_00020025,3);
  uVar1 = FUN_010182dc(0x20029);
  FUN_0102024c(uVar1,_DAT_00020027);
  _DAT_00020020 = _DAT_00020020 + 1;
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 010197c2 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void switchD_01018ebe__caseD_b6(void)
{
  undefined4 uVar1;
  
  FUN_0102024c(&DAT_00020025,3);
  uVar1 = FUN_010182dc(0x20029);
  FUN_0102024c(uVar1,_DAT_00020027);
  _DAT_00020020 = _DAT_00020020 + 1;
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 010197c4 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_010197c4(void)
{
  undefined4 uVar1;
  
  FUN_0102024c(&DAT_00020025,3);
  uVar1 = FUN_010182dc(0x20029);
  FUN_0102024c(uVar1,_DAT_00020027);
  _DAT_00020020 = _DAT_00020020 + 1;
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 010197f6 */
#ifdef NONMATCHING
void switchD_01018ebe__caseD_b3(void)
{
  log_empty(STR_01019830);
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 010197fe */
#ifdef NONMATCHING
void switchD_01018ebe__caseD_b4(void)
{
  log_empty(STR_0101984c);
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 01019806 */
#ifdef NONMATCHING
void FUN_01019806(void)
{
  DAT_000c4fef = 0;
  DAT_000f853c = DAT_000f853c & 0xfb;
  return;
}
#endif

/* 0101986c */
#ifdef NONMATCHING
void loop_once(void)
{
  undefined1 auStack_118 [256];
  int local_18;
  
  local_18 = core_event_read();
  if (local_18 == 0xb0) {
    FUN_01019c7c(auStack_118);
    FUN_01024e24();
    DAT_00020183 = DAT_00020182;
    DAT_00020182 = 2;
    Handle_HidConnectStateCallback();
    return;
  }
  if (local_18 < 0xb1) {
                    /* WARNING: Subroutine does not return */
    yc_switch8();
  }
                    /* WARNING: Subroutine does not return */
  yc_switch8();
}
#endif

/* 010198bc */
#ifdef NONMATCHING
void FUN_010198bc(void)
{
  uint uVar1;
  int iVar2;
  undefined1 auStack_7ffffffe [2147483646];
  
  uVar1 = FUN_01019c7c((int)register0x00000054 + 0x220);
  if (0 < (int)uVar1) {
    for (iVar2 = 0; iVar2 < (int)uVar1; iVar2 = iVar2 + 1) {
    }
    FUN_01019de8((int)register0x00000054 + 0x220,uVar1 & 0xffff);
    for (iVar2 = 0; iVar2 < (int)uVar1; iVar2 = iVar2 + 1) {
    }
  }
  return;
}
#endif

/* 0101991e */
#ifdef NONMATCHING
void FUN_0101991e(void)
{
  int iVar1;
  undefined1 auStack_7ffffffe [2147483646];
  
  iVar1 = FUN_01019c7c((int)register0x00000054 + 0x220);
  if (0 < iVar1) {
    FUN_0101e980((int)register0x00000054 + 0x220,iVar1,2);
  }
  return;
}
#endif

/* 01019938 */
#ifdef NONMATCHING
void FUN_01019938(void)
{
  int iVar1;
  int iVar2;
  undefined1 auStack_7ffffffe [2147483646];
  
  iVar1 = FUN_01019c7c((int)register0x00000054 + 0x220);
  if (0 < iVar1) {
    for (iVar2 = 0; iVar2 < iVar1; iVar2 = iVar2 + 1) {
    }
    hid_control((int)register0x00000054 + 0x220,iVar1,2);
  }
  return;
}
#endif

/* 0101995a */
#ifdef NONMATCHING
void FUN_0101995a(void)
{
  undefined1 auStack_7ffffffe [2147483646];
  
  FUN_01019c7c((int)register0x00000054 + 0x220);
  FUN_01020e08();
  return;
}
#endif

/* 01019968 */
#ifdef NONMATCHING
void thunk_FUN_01019b40(void)
{
  undefined1 auStack_7ffffffe [2147483646];
  
  FUN_01019c7c((int)register0x00000054 + 0x220);
  FUN_01024e24();
  DAT_00020183 = DAT_00020182;
  DAT_00020182 = 2;
  Handle_HidConnectStateCallback();
  return;
}
#endif

/* 0101996a */
#ifdef NONMATCHING
void FUN_0101996a(void)
{
  undefined1 auStack_7ffffffe [2147483646];
  
  FUN_01019c7c((int)register0x00000054 + 0x220);
  FUN_01020e08();
  return;
}
#endif

/* 01019978 */
#ifdef NONMATCHING
void FUN_01019978(void)
{
  undefined1 auStack_7ffffffe [2147483646];
  
  FUN_01019c7c((int)register0x00000054 + 0x220);
  if (DAT_0002067f != '\0') {
    rom_delay_a(1000);
    bt_disconnect();
    rom_delay_a(2000);
    FUN_0102513c();
  }
  if (DAT_00020650 == '\0') {
    DAT_00020650 = '\x01';
  }
  return;
}
#endif

/* 010199b4 */
#ifdef NONMATCHING
void FUN_010199b4(void)
{
  int iVar1;
  undefined1 auStack_7ffffffe [2147483646];
  
  if (DAT_00020650 != '\0') {
    DAT_00020650 = DAT_00020650 + -1;
  }
  FUN_01019c7c((int)register0x00000054 + 0x220);
  iVar1 = usb_powered();
  if (iVar1 == 0) {
    iVar1 = FUN_0101eefc();
    if (iVar1 == 0) {
      iVar1 = usb_charging();
      if ((iVar1 == 0) && (iVar1 = link_byte(), iVar1 != 2)) {
        FUN_01024d0c(0);
      }
      FUN_0101b5a0(0);
    }
    else {
      FUN_0101fbb8();
      DAT_000201dc = DAT_000201dc + '\x01';
    }
  }
  else {
    FUN_0101b4ae(0);
  }
  return;
}
#endif

/* 01019a14 */
#ifdef NONMATCHING
void FUN_01019a14(void)
{
  int iVar1;
  int iVar2;
  undefined1 uStack0000001c;
  
  memzero(&uStack0000001c,0x100);
  iVar1 = FUN_01019c7c(&uStack0000001c);
  if (0 < iVar1) {
    memcpy();
    host_store();
  }
  for (iVar2 = 0; iVar2 < iVar1; iVar2 = iVar2 + 1) {
  }
  return;
}
#endif

/* 01019a48 */
#ifdef NONMATCHING
void FUN_01019a48(void)
{
  undefined1 uStack0000001c;
  
  DAT_00020183 = DAT_00020182;
  DAT_00020182 = 2;
  memzero(&uStack0000001c,0x100);
  FUN_01019c7c(&uStack0000001c);
  DAT_000201dc = 0;
  return;
}
#endif

/* 01019a72 */
#ifdef NONMATCHING
void thunk_FUN_01019bfa(void)
{
  undefined2 uStack0000001c;
  
  FUN_01019c7c(&uStack0000001c);
  return;
}
#endif

/* 01019a74 */
#ifdef NONMATCHING
void thunk_FUN_01019be0(void)
{
  int iVar1;
  int iVar2;
  undefined1 uStack0000001c;
  
  iVar1 = FUN_01019c7c(&uStack0000001c);
  if (0 < iVar1) {
    for (iVar2 = 0; iVar2 < iVar1; iVar2 = iVar2 + 1) {
    }
  }
  return;
}
#endif

/* 01019a76 */
#ifdef NONMATCHING
void thunk_FUN_01019bde(void)
{
  return;
}
#endif

/* 01019a78 */
#ifdef NONMATCHING
void thunk_FUN_01019bbe(void)
{
  int iVar1;
  int iVar2;
  undefined1 uStack0000001c;
  
  iVar1 = FUN_01019c7c(&uStack0000001c);
  if (0 < iVar1) {
    for (iVar2 = 0; iVar2 < iVar1; iVar2 = iVar2 + 1) {
    }
  }
  FUN_01018b70(0);
  return;
}
#endif

/* 01019a7a */
#ifdef NONMATCHING
void thunk_FUN_01019b9e(void)
{
  int iVar1;
  int iVar2;
  undefined1 uStack0000001c;
  
  iVar1 = FUN_01019c7c(&uStack0000001c);
  if (0 < iVar1) {
    for (iVar2 = 0; iVar2 < iVar1; iVar2 = iVar2 + 1) {
    }
    pair_write_back(&uStack0000001c);
  }
  return;
}
#endif

/* 01019a7c */
#ifdef NONMATCHING
void thunk_FUN_01019b2c(void)
{
  undefined1 auStack_7ffffffe [2147483646];
  
  FUN_01019c7c((int)register0x00000054 + 0x220);
  DAT_00020682 = 3;
  c874();
  return;
}
#endif

/* 01019a7e */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_01019aea(void)
{
  int iVar1;
  undefined1 auStack_7ffffffe [2147483646];
  
  FUN_01019c7c((int)register0x00000054 + 0x220);
  iVar1 = usb_charging();
  if ((iVar1 == 0) && (iVar1 = link_byte(), iVar1 != 2)) {
    FUN_01024d0c(0);
  }
  if (DAT_00020182 == '\x02') {
    _DAT_00020654 = 0;
  }
  Handle_HidConnectStateCallback(3);
  iVar1 = usb_charging();
  if (iVar1 != 0) {
    FUN_0101b5a0(0);
  }
  return;
}
#endif

/* 01019a80 */
#ifdef NONMATCHING
void thunk_FUN_01019ad2(void)
{
  undefined1 auStack_7ffffffe [2147483646];
  
  FUN_01019c7c((int)register0x00000054 + 0x220);
  DAT_00020682 = 2;
  c874();
  FUN_01023a5c();
  return;
}
#endif

/* 01019a82 */
#ifdef NONMATCHING
void thunk_FUN_01019c3e(void)
{
  undefined1 uStack0000001c;
  
  FUN_01019c7c(&uStack0000001c);
  return;
}
#endif

/* 01019a84 */
#ifdef NONMATCHING
void thunk_FUN_01019c3c(void)
{
  return;
}
#endif

/* 01019a86 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_01019a8a(void)
{
  int iVar1;
  int iVar2;
  undefined2 uStack00000120;
  
  memzero(&uStack00000120,0x100);
  iVar1 = FUN_01019c7c(&uStack00000120);
  _DAT_00020680 = FUN_01018240((uint)uStack00000120 * 0x271,1000);
  for (iVar2 = 0; iVar2 < iVar1; iVar2 = iVar2 + 1) {
  }
  FUN_0101c830(_DAT_00020680 + 5);
  return;
}
#endif

/* 01019a88 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_01019b60(void)
{
  undefined1 auStack_7ffffffe [2147483646];
  
  FUN_01019c7c((int)register0x00000054 + 0x220);
  if (DAT_00020182 == '\x02') {
    _DAT_00020654 = 0;
  }
  DAT_00020183 = DAT_00020182;
  DAT_00020182 = 3;
  if (DAT_00020650 != '\0') {
    DAT_00020650 = DAT_00020650 + -1;
    Handle_HidConnectStateCallback(3);
  }
  return;
}
#endif

/* 01019a8a */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01019a8a(void)
{
  int iVar1;
  int iVar2;
  undefined2 uStack00000120;
  
  memzero(&uStack00000120,0x100);
  iVar1 = FUN_01019c7c(&uStack00000120);
  _DAT_00020680 = FUN_01018240((uint)uStack00000120 * 0x271,1000);
  for (iVar2 = 0; iVar2 < iVar1; iVar2 = iVar2 + 1) {
  }
  FUN_0101c830(_DAT_00020680 + 5);
  return;
}
#endif

/* 01019ad2 */
#ifdef NONMATCHING
void FUN_01019ad2(void)
{
  undefined1 auStack_7ffffffe [2147483646];
  
  FUN_01019c7c((int)register0x00000054 + 0x220);
  DAT_00020682 = 2;
  c874();
  FUN_01023a5c();
  return;
}
#endif

/* 01019aea */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01019aea(void)
{
  int iVar1;
  undefined1 auStack_7ffffffe [2147483646];
  
  FUN_01019c7c((int)register0x00000054 + 0x220);
  iVar1 = usb_charging();
  if ((iVar1 == 0) && (iVar1 = link_byte(), iVar1 != 2)) {
    FUN_01024d0c(0);
  }
  if (DAT_00020182 == '\x02') {
    _DAT_00020654 = 0;
  }
  Handle_HidConnectStateCallback(3);
  iVar1 = usb_charging();
  if (iVar1 != 0) {
    FUN_0101b5a0(0);
  }
  return;
}
#endif

/* 01019b2c */
#ifdef NONMATCHING
void FUN_01019b2c(void)
{
  undefined1 auStack_7ffffffe [2147483646];
  
  FUN_01019c7c((int)register0x00000054 + 0x220);
  DAT_00020682 = 3;
  c874();
  return;
}
#endif

/* 01019b40 */
#ifdef NONMATCHING
void FUN_01019b40(void)
{
  undefined1 auStack_7ffffffe [2147483646];
  
  FUN_01019c7c((int)register0x00000054 + 0x220);
  FUN_01024e24();
  DAT_00020183 = DAT_00020182;
  DAT_00020182 = 2;
  Handle_HidConnectStateCallback();
  return;
}
#endif

/* 01019b60 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01019b60(void)
{
  undefined1 auStack_7ffffffe [2147483646];
  
  FUN_01019c7c((int)register0x00000054 + 0x220);
  if (DAT_00020182 == '\x02') {
    _DAT_00020654 = 0;
  }
  DAT_00020183 = DAT_00020182;
  DAT_00020182 = 3;
  if (DAT_00020650 != '\0') {
    DAT_00020650 = DAT_00020650 + -1;
    Handle_HidConnectStateCallback(3);
  }
  return;
}
#endif

/* 01019b9e */
#ifdef NONMATCHING
void FUN_01019b9e(void)
{
  int iVar1;
  int iVar2;
  undefined1 uStack0000001c;
  
  iVar1 = FUN_01019c7c(&uStack0000001c);
  if (0 < iVar1) {
    for (iVar2 = 0; iVar2 < iVar1; iVar2 = iVar2 + 1) {
    }
    pair_write_back(&uStack0000001c);
  }
  return;
}
#endif

/* 01019bbe */
#ifdef NONMATCHING
void FUN_01019bbe(void)
{
  int iVar1;
  int iVar2;
  undefined1 uStack0000001c;
  
  iVar1 = FUN_01019c7c(&uStack0000001c);
  if (0 < iVar1) {
    for (iVar2 = 0; iVar2 < iVar1; iVar2 = iVar2 + 1) {
    }
  }
  FUN_01018b70(0);
  return;
}
#endif

/* 01019bde */
#ifdef NONMATCHING
void FUN_01019bde(void)
{
  return;
}
#endif

/* 01019be0 */
#ifdef NONMATCHING
void FUN_01019be0(void)
{
  int iVar1;
  int iVar2;
  undefined1 uStack0000001c;
  
  iVar1 = FUN_01019c7c(&uStack0000001c);
  if (0 < iVar1) {
    for (iVar2 = 0; iVar2 < iVar1; iVar2 = iVar2 + 1) {
    }
  }
  return;
}
#endif

/* 01019bfa */
#ifdef NONMATCHING
void FUN_01019bfa(void)
{
  undefined2 uStack0000001c;
  
  FUN_01019c7c(&uStack0000001c);
  return;
}
#endif

/* 01019c3c */
#ifdef NONMATCHING
void FUN_01019c3c(void)
{
  return;
}
#endif

/* 01019c3e */
#ifdef NONMATCHING
void FUN_01019c3e(void)
{
  undefined1 uStack0000001c;
  
  FUN_01019c7c(&uStack0000001c);
  return;
}
#endif

/* 01019c7c */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_01019c7c(int param_1)
{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  
  if (_DAT_00020f94 < 3) {
    iVar2 = 0;
  }
  else {
    FUN_01020500(1);
    FUN_0101c144(1);
    iVar2 = FUN_0101c144(1);
    for (iVar3 = 0; iVar3 < iVar2; iVar3 = iVar3 + 1) {
      uVar1 = FUN_0101c144(1);
      *(undefined1 *)(param_1 + iVar3) = uVar1;
    }
  }
  return iVar2;
}
#endif

/* 01019cc0 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 BT_ResetFeatrues(undefined4 param_1,undefined2 param_2,undefined1 param_3)
{
  int iVar1;
  undefined1 uStack_18;
  undefined1 local_17;
  undefined2 local_16;
  undefined4 local_14;
  
  _uStack_18 = CONCAT22(param_2,CONCAT11(0xa1,param_3));
  local_14 = param_1;
  log_empty(STR_01019d14);
  FUN_01018a54(&DAT_00020010,0x33);
  ipc_send(&uStack_18);
  _DAT_0002000c = now();
  do {
    iVar1 = FUN_01018a76(&DAT_00020010,0x33);
    if (iVar1 != 0) {
      return 1;
    }
    iVar1 = elapsed(_DAT_0002000c,500);
  } while (iVar1 == 0);
  return 0;
}
#endif

/* 01019d34 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 BT_SendHidControlData(undefined4 param_1,int param_2,undefined1 param_3)
{
  int iVar1;
  undefined1 uStack_18;
  undefined1 local_17;
  undefined2 local_16;
  undefined4 local_14;
  
  if ((param_2 != 0) && (param_2 < 0x100)) {
    _uStack_18 = CONCAT22((short)param_2,CONCAT11(0xb2,param_3));
    local_14 = param_1;
    log_empty(STR_01019d94);
    FUN_01018a54(&DAT_00020010,5);
    ipc_send(&uStack_18);
    _DAT_0002000c = now();
    do {
      iVar1 = FUN_01018a76(&DAT_00020010,5);
      if (iVar1 != 0) {
        return 1;
      }
      iVar1 = elapsed(_DAT_0002000c,500);
    } while (iVar1 == 0);
  }
  return 0;
}
#endif

/* 01019db8 */
#ifdef NONMATCHING
undefined4 send_b0(undefined4 param_1,undefined4 param_2,undefined1 param_3)
{
  undefined1 uStack_18;
  undefined1 local_17;
  undefined1 local_16;
  undefined1 local_15;
  undefined4 local_14;
  
  _uStack_18 = CONCAT13((char)((uint)param_2 >> 8),CONCAT12((char)param_2,CONCAT11(0xb0,param_3)));
  local_14 = param_1;
  FUN_01018a54(&DAT_00020010,5);
  ipc_send_long(&uStack_18);
  return 1;
}
#endif

/* 01019de8 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_01019de8(undefined4 param_1,int param_2,undefined1 param_3)
{
  int iVar1;
  undefined1 uStack_18;
  undefined1 local_17;
  undefined2 local_16;
  undefined4 local_14;
  
  if ((param_2 != 0) && (param_2 < 0x100)) {
    _uStack_18 = CONCAT22((short)param_2,CONCAT11(5,param_3));
    local_14 = param_1;
    FUN_01018a54(&DAT_00020010);
    ipc_send(&uStack_18);
    _DAT_0002000c = now();
    do {
      iVar1 = FUN_01018a76(&DAT_00020010,5);
      if (iVar1 != 0) {
        return 1;
      }
      iVar1 = elapsed(_DAT_0002000c,500);
    } while (iVar1 == 0);
  }
  return 0;
}
#endif

/* 01019eb8 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 BT_SetSDP_SERVICE(undefined4 param_1,undefined4 param_2,undefined1 param_3)
{
  int iVar1;
  undefined1 uStack_18;
  undefined1 local_17;
  undefined1 local_16;
  undefined1 local_15;
  undefined4 local_14;
  
  _uStack_18 = CONCAT13((char)((uint)param_2 >> 8),CONCAT12((char)param_2,CONCAT11(0xa0,param_3)));
  local_14 = param_1;
  FUN_01018a54(&DAT_00020010,0x32);
  ipc_send_long(&uStack_18);
  _DAT_0002000c = now();
  do {
    iVar1 = FUN_01018a76(&DAT_00020010,0x32);
    if (iVar1 != 0) {
      return 1;
    }
    iVar1 = elapsed(_DAT_0002000c,500);
  } while (iVar1 == 0);
  log_empty(STR_01019f1c);
  return 0;
}
#endif

/* 01019f44 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 set_ble_addr(undefined4 param_1,undefined4 param_2,undefined1 param_3)
{
  int iVar1;
  undefined1 uStack_10;
  undefined1 local_f;
  undefined2 local_e;
  undefined4 local_c;
  
  _uStack_10 = CONCAT22(6,CONCAT11(1,param_3));
  local_c = param_1;
  FUN_01018a54(&DAT_00020010,1);
  ipc_send(&uStack_10);
  _DAT_0002000c = now();
  do {
    iVar1 = FUN_01018a76(&DAT_00020010,1);
    if (iVar1 != 0) {
      return 1;
    }
    iVar1 = elapsed(_DAT_0002000c,500);
  } while (iVar1 == 0);
  return 0;
}
#endif

/* 01019f98 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_01019f98(undefined4 param_1,undefined1 param_2)
{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_18;
  undefined4 *local_14;
  undefined4 local_10;
  
  uStack_18 = CONCAT22(2,CONCAT11(0x39,param_2));
  local_14 = &local_10;
  local_10 = param_1;
  FUN_01018a54(&DAT_00020010,0x36);
  ipc_send(&uStack_18);
  _DAT_0002000c = now();
  do {
    iVar1 = FUN_01018a76(&DAT_00020010,0x36);
    if (iVar1 != 0) {
      uVar2 = 1;
      goto LAB_01019fd2;
    }
    iVar1 = elapsed(_DAT_0002000c,500);
  } while (iVar1 == 0);
  uVar2 = 0;
LAB_01019fd2:
  return CONCAT44(uStack_18,uVar2);
}
#endif

/* 01019ff0 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_01019ff0(undefined4 param_1,undefined2 param_2,undefined1 param_3)
{
  int iVar1;
  undefined1 uStack_18;
  undefined1 local_17;
  undefined2 local_16;
  undefined4 local_14;
  
  _uStack_18 = CONCAT22(param_2,CONCAT11(4,param_3));
  local_14 = param_1;
  FUN_01018a54(&DAT_00020010);
  ipc_send(&uStack_18);
  _DAT_0002000c = now();
  do {
    iVar1 = FUN_01018a76(&DAT_00020010,4);
    if (iVar1 != 0) {
      return 1;
    }
    iVar1 = elapsed(_DAT_0002000c,500);
  } while (iVar1 == 0);
  return 0;
}
#endif

/* 0101a044 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0101a044(undefined4 param_1,undefined4 param_2,byte param_3)
{
  int iVar1;
  ushort uStack_10;
  undefined2 local_e;
  undefined4 local_c;
  
  _uStack_10 = CONCAT22(6,(ushort)param_3);
  local_c = param_1;
  FUN_01018a54(&DAT_00020010,0);
  ipc_send(&uStack_10);
  _DAT_0002000c = now();
  do {
    iVar1 = FUN_01018a76(&DAT_00020010,0);
    if (iVar1 != 0) {
      return 1;
    }
    iVar1 = elapsed(_DAT_0002000c,500);
  } while (iVar1 == 0);
  return 0;
}
#endif

/* 0101a098 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0101a098(undefined4 param_1,undefined2 param_2)
{
  int iVar1;
  undefined2 local_18;
  undefined2 local_16;
  undefined4 local_14;
  
  _local_18 = CONCAT22(param_2,0x305);
  local_14 = param_1;
  FUN_01018a54(&DAT_00020010);
  ipc_send(&local_18);
  _DAT_0002000c = now();
  do {
    iVar1 = FUN_01018a76(&DAT_00020010,3);
    if (iVar1 != 0) {
      return 1;
    }
    iVar1 = elapsed(_DAT_0002000c,500);
  } while (iVar1 == 0);
  return 0;
}
#endif

/* 0101a0f0 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_0101a0f0(undefined1 param_1,undefined4 param_2,undefined1 param_3)
{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_18;
  undefined1 uStack_14;
  undefined1 local_13;
  undefined2 local_12;
  undefined4 *local_10;
  
  local_10 = &local_18;
  local_18._3_1_ = (undefined1)((uint)param_2 >> 0x18);
  local_18._0_3_ = CONCAT12((char)((uint)param_2 >> 8),CONCAT11((char)param_2,param_1));
  _uStack_14 = CONCAT22(3,CONCAT11(0xa2,param_3));
  FUN_01018a54(&DAT_00020010,0x34);
  ipc_send(&uStack_14);
  _DAT_0002000c = now();
  do {
    iVar1 = FUN_01018a76(&DAT_00020010,0x34);
    if (iVar1 != 0) {
      uVar2 = 1;
      goto LAB_0101a134;
    }
    iVar1 = elapsed(_DAT_0002000c,500);
  } while (iVar1 == 0);
  uVar2 = 0;
LAB_0101a134:
  return CONCAT44(local_18,uVar2);
}
#endif

/* 0101a154 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0101a154(undefined4 param_1,undefined4 param_2,undefined1 param_3)
{
  int iVar1;
  undefined1 uStack_10;
  undefined1 local_f;
  undefined2 local_e;
  undefined4 local_c;
  
  _uStack_10 = CONCAT22(3,CONCAT11(0x15,param_3));
  local_c = param_1;
  FUN_01018a54(&DAT_00020010,0x1d);
  ipc_send(&uStack_10);
  _DAT_0002000c = now();
  do {
    iVar1 = FUN_01018a76(&DAT_00020010,0x1d);
    if (iVar1 != 0) {
      return 1;
    }
    iVar1 = elapsed(_DAT_0002000c,500);
  } while (iVar1 == 0);
  return 0;
}
#endif

/* 0101a1a8 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_0101a1a8(undefined4 param_1,undefined1 param_2)
{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_18;
  undefined4 *local_14;
  undefined4 local_10;
  
  uStack_18 = CONCAT22(2,CONCAT11(0x79,param_2));
  local_14 = &local_10;
  local_10 = param_1;
  FUN_01018a54(&DAT_00020010,0x37);
  ipc_send(&uStack_18);
  _DAT_0002000c = now();
  do {
    iVar1 = FUN_01018a76(&DAT_00020010,0x37);
    if (iVar1 != 0) {
      uVar2 = 1;
      goto LAB_0101a1e2;
    }
    iVar1 = elapsed(_DAT_0002000c,500);
  } while (iVar1 == 0);
  uVar2 = 0;
LAB_0101a1e2:
  return CONCAT44(uStack_18,uVar2);
}
#endif

/* 0101a200 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0101a200(undefined4 param_1,undefined2 param_2,undefined1 param_3)
{
  int iVar1;
  undefined1 uStack_18;
  undefined1 local_17;
  undefined2 local_16;
  undefined4 local_14;
  
  _uStack_18 = CONCAT22(param_2,CONCAT11(0x26,param_3));
  local_14 = param_1;
  FUN_01018a54(&DAT_00020010,0xd);
  ipc_send(&uStack_18);
  _DAT_0002000c = now();
  do {
    iVar1 = FUN_01018a76(&DAT_00020010,0xd);
    if (iVar1 != 0) {
      return 1;
    }
    iVar1 = elapsed(_DAT_0002000c,500);
  } while (iVar1 == 0);
  return 0;
}
#endif

/* 0101a254 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_0101a254(undefined4 param_1,undefined1 param_2)
{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_18;
  undefined4 *local_14;
  undefined4 local_10;
  
  uStack_18 = CONCAT22(1,CONCAT11(0xc,param_2));
  local_14 = &local_10;
  local_10 = param_1;
  FUN_01018a54(&DAT_00020010,8);
  ipc_send(&uStack_18);
  _DAT_0002000c = now();
  do {
    iVar1 = FUN_01018a76(&DAT_00020010,8);
    if (iVar1 != 0) {
      uVar2 = 1;
      goto LAB_0101a28e;
    }
    iVar1 = elapsed(_DAT_0002000c,500);
  } while (iVar1 == 0);
  uVar2 = 0;
LAB_0101a28e:
  return CONCAT44(uStack_18,uVar2);
}
#endif

/* 0101a2ac */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 cmd_42(undefined4 param_1,undefined1 param_2)
{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_18;
  undefined4 *local_14;
  undefined4 local_10;
  
  uStack_18 = CONCAT22(1,CONCAT11(0x42,param_2));
  local_14 = &local_10;
  local_10 = param_1;
  FUN_01018a54(&DAT_00020010,0xe);
  ipc_send(&uStack_18);
  _DAT_0002000c = now();
  do {
    iVar1 = FUN_01018a76(&DAT_00020010,0xe);
    if (iVar1 != 0) {
      uVar2 = 1;
      goto LAB_0101a2e6;
    }
    iVar1 = elapsed(_DAT_0002000c,500);
  } while (iVar1 == 0);
  uVar2 = 0;
LAB_0101a2e6:
  return CONCAT44(uStack_18,uVar2);
}
#endif

/* 0101a304 */
#ifdef NONMATCHING
/* WARNING: Removing unreachable block (ram,0x0101a334) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 set_vis(int param_1,undefined4 param_2,undefined1 param_3)
{
  int iVar1;
  undefined4 uVar2;
  uint local_20;
  undefined1 uStack_1c;
  undefined1 local_1b;
  undefined2 local_1a;
  uint *local_18;
  
  local_18 = &local_20;
  local_20 = param_1 == 1 | 2;
  _uStack_1c = CONCAT22(1,CONCAT11(2,param_3));
  FUN_01018a54(&DAT_00020010,2);
  ipc_send(&uStack_1c);
  _DAT_0002000c = now();
  do {
    iVar1 = FUN_01018a76(&DAT_00020010,2);
    if (iVar1 != 0) {
      uVar2 = 1;
      goto LAB_0101a370;
    }
    iVar1 = elapsed(_DAT_0002000c,500);
  } while (iVar1 == 0);
  uVar2 = 0;
LAB_0101a370:
  return CONCAT44(local_20,uVar2);
}
#endif

/* 0101a390 */
#ifdef NONMATCHING
void FUN_0101a390(uint param_1,uint *param_2,uint *param_3,undefined4 param_4)
{
  undefined4 extraout_r3;
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint local_28;
  
  uVar7 = 0x83848d96;
  uVar6 = 0xbbcc54fc;
  uVar5 = 0x2c000000;
  uVar4 = 0x13000000;
  log_empty(STR_0101a444,param_1,param_3,param_4,0x13000000,0x2c000000,0xbbcc54fc,0x83848d96);
  if ((param_1 & 0x800000) == 0) {
    param_1 = param_1 | 0x2c000000;
  }
  else {
    param_1 = param_1 | 0x13000000;
  }
  uVar1 = (param_1 ^ 0x20e12365) << 2;
  uVar3 = 0;
  local_28 = 0;
  uVar2 = uVar1;
  while (local_28 = local_28 + 1, local_28 < 0x1f) {
    if ((uVar2 & 0x80000000) != 0) {
      uVar2 = uVar2 ^ 0xb0ae27b5;
      uVar3 = uVar3 ^ 0x20000000;
    }
    uVar2 = uVar2 * 2 - ((int)uVar3 >> 0x1f);
    uVar3 = uVar3 << 1;
  }
  log_empty("regHi %x regLo %x\r\n",uVar2,uVar3,extraout_r3,uVar4,uVar5,uVar6,uVar7);
  *param_3 = uVar2 << 2 ^ uVar3 >> 0x1e ^ 0xbbcc54fc;
  *param_2 = uVar2 >> 0x1e ^ uVar1 ^ 0x83848d96;
  return;
}
#endif

/* 0101a468 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0101a468(int param_1)
{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 2000;
  battery_adc();
  iVar1 = FUN_0101f0bc();
  if (iVar1 == 0) {
    if (DAT_00020635 != 0) {
      DAT_00020635 = DAT_00020635 - 1;
    }
  }
  else if (DAT_00020635 < 10) {
    DAT_00020635 = DAT_00020635 + 1;
  }
  if (DAT_00020635 < 2) {
    _DAT_00020620 = 0;
    _DAT_00020622 = 0;
    _DAT_00020628 = 0;
    iVar1 = FUN_0101efa4();
    if (iVar1 == 0) {
      DAT_000206b3 = 0;
      battery_percent();
    }
    else {
      DAT_000206b3 = 1;
      _DAT_00020622 = 0;
      _DAT_00020628 = 0;
      uVar2 = 500;
      DAT_0002062d = 9;
    }
  }
  else {
    _DAT_00020620 = _DAT_00020620 + 1;
    FUN_0101a564();
    iVar1 = FUN_0101b274();
    if (iVar1 == 0) {
      DAT_000206b2 = 0;
      FUN_010232b0();
    }
    battery_percent();
  }
  if (param_1 != 0) {
    FUN_010240ac(0x21a24,uVar2);
    FUN_01023d5c(0x21a24);
  }
  return;
}
#endif

/* 0101a540 */
#ifdef NONMATCHING
void FUN_0101a540(undefined4 param_1)
{
  FUN_010240c8(0x21a24,0x101a469);
  FUN_010240ac(0x21a24,param_1);
  FUN_01023d5c(0x21a24);
  return;
}
#endif

/* 0101a564 */
#ifdef NONMATCHING
void FUN_0101a564(void)
{
  DAT_0002062c = 0;
  return;
}
#endif
