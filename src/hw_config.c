/* hw_config.c: hw_config.c in Handle_HidConnectStateCallback's assert */

#include "zero2.h"

/* 0101be14 */
#ifdef NONMATCHING
void FUN_0101be14(void)
{
  int iVar1;
  
  FUN_01020e74();
  if (DAT_00020158 != '\0') {
    FUN_010232b0();
  }
  iVar1 = poll_buttons();
  if (iVar1 == 0) {
    FUN_0101ee50();
    power_off_idle();
  }
  else {
    FUN_010232b0();
  }
  FUN_0101c44c();
  if (DAT_000201b4 == '\0') {
    FUN_010240ac(0x219dc,0);
    FUN_01023d5c(0x219dc);
  }
  else {
    if (DAT_000201b8 == '\0') {
      FUN_010240ac(0x219dc,9);
    }
    else {
      FUN_010240ac(0x219dc,0x1d);
    }
    FUN_01023d5c(0x219dc);
  }
  return;
}
#endif

/* 0101be8c */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0101be8c(void)
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
            if (_DAT_00022ac2 == 8) {
              FUN_010203e0(0x22ac5,DAT_00022ac4);
            }
            memzero(&DAT_00022ac2,0x44);
            uVar1 = 1;
          }
        }
        else {
          _DAT_00020708 = _DAT_00020708 & 0xfffffffb;
          if (_DAT_00022ac2 == 4) {
            FUN_0101c43c(0x22ac5,DAT_00022ac4);
          }
          memzero(&DAT_00022ac2,0x44);
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

/* 0101c024 */
void FUN_0101c024(void)
{
  FUN_01024090(0x21a0c);
  return;
}

/* 0101c034 */
#ifdef NONMATCHING
/* WARNING: Removing unreachable block (ram,0x0101c0bc) */
/* WARNING: Removing unreachable block (ram,0x0101c0b8) */
/* WARNING: Removing unreachable block (ram,0x0101c0cc) */
/* WARNING: Removing unreachable block (ram,0x0101c0d0) */
/* WARNING: Removing unreachable block (ram,0x0101c062) */
/* WARNING: Removing unreachable block (ram,0x0101c076) */
/* WARNING: Removing unreachable block (ram,0x0101c054) */

void FUN_0101c034(undefined4 param_1,undefined4 param_2)
{
  bool bVar1;
  undefined1 auStack_54 [64];
  
  bVar1 = DAT_000201ea != '\0';
  if (bVar1) {
    memzero(auStack_54,0x40);
    memcpy(auStack_54,param_1,param_2);
    FUN_01023108(auStack_54,9);
  }
  DAT_000201ea = !bVar1;
  return;
}
#endif

/* 0101c0f0 */
#ifdef NONMATCHING
undefined4 FUN_0101c0f0(undefined4 param_1,undefined4 param_2)
{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined1 *extraout_r2;
  undefined4 uVar3;
  
  uVar3 = 0;
  uVar2 = FUN_0101c430(1,param_2,param_1);
  uVar1 = (undefined1)((ushort)uVar2 >> 8);
  if (DAT_000201b4 == '\0') {
    *extraout_r2 = 0x81;
    extraout_r2[1] = 0x66;
    extraout_r2[2] = 0xa5;
    extraout_r2[3] = uVar1;
    extraout_r2[4] = (char)uVar2;
    uVar3 = 5;
  }
  else if (DAT_000201b4 == '\x02') {
    *extraout_r2 = 1;
    extraout_r2[1] = 0x66;
    extraout_r2[2] = 0xa5;
    extraout_r2[3] = uVar1;
    extraout_r2[4] = (char)uVar2;
    uVar3 = 5;
  }
  return uVar3;
}
#endif

/* 0101c144 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_0101c144(int param_1)
{
  undefined1 uVar1;
  
  uVar1 = *(undefined1 *)(_DAT_00020f8c + _DAT_00020f98);
  if (param_1 != 0) {
    FUN_0101f98c(0xb);
    _DAT_00020f94 = _DAT_00020f94 + -1;
    FUN_0101f9a0(0xb);
    _DAT_00020f98 = _DAT_00020f98 + 1;
    if (_DAT_00020f90 <= _DAT_00020f98) {
      _DAT_00020f98 = 0;
    }
  }
  return uVar1;
}
#endif

/* 0101c190 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0101c190(uint param_1)
{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 0;
  if (DAT_00021878 == '\x01') {
    for (uVar2 = 0; uVar2 < 10; uVar2 = uVar2 + 1 & 0xff) {
      if ((_DAT_0002186c & param_1 & (uint)(&PTR_DAT_010283b8)[uVar2]) == 0) {
        *(undefined1 *)(uVar2 + 0x218ac) = 0;
      }
      else if (*(byte *)(uVar2 + 0x218ac) < 5) {
        *(char *)(uVar2 + 0x218ac) = *(char *)(uVar2 + 0x218ac) + '\x01';
        _DAT_00021880 = _DAT_00021880 | (uint)(&PTR_DAT_010283b8)[uVar2];
      }
      else {
        uVar1 = uVar1 | (uint)(&PTR_DAT_010283b8)[uVar2];
        _DAT_00021880 = _DAT_00021880 & ~(uint)(&PTR_DAT_010283b8)[uVar2];
      }
    }
  }
  else if (DAT_00021878 == '\x02') {
    uVar1 = _DAT_0002186c & param_1;
    _DAT_00021880 = _DAT_0002186c;
  }
  return uVar1;
}
#endif

/* 0101c22c */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_0101c22c(void)
{
  int iVar1;
  
  iVar1 = adc_sample(0);
  _DAT_000201c8 = FUN_01018240(iVar1 * 0x25,10);
  return DAT_0002062d;
}
#endif

/* 0101c254 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0101c254(void)
{
  return _DAT_000201c8;
}
#endif

/* 0101c260 */
#ifdef NONMATCHING
undefined1 battery_byte(void)
{
  ushort uVar1;
  undefined1 uVar2;
  
  uVar1 = FUN_0101c22c();
  if (uVar1 < 0x33) {
    if (uVar1 < 0x15) {
      if (uVar1 < 0xb) {
        uVar2 = 0x84;
      }
      else {
        uVar2 = 0x85;
      }
    }
    else {
      uVar2 = 0x86;
    }
  }
  else {
    uVar2 = 0x87;
  }
  return uVar2;
}
#endif

/* 0101c288 */
#ifdef NONMATCHING
undefined1 link_byte(void)
{
  return DAT_00020682;
}
#endif

/* 0101c294 */
#ifdef NONMATCHING
void FUN_0101c294(undefined4 param_1)
{
  classic_addr_for_mode(param_1,DAT_000201b4);
  return;
}
#endif

/* 0101c2a8 */
#ifdef NONMATCHING
void classic_addr_for_mode(byte *param_1,int param_2)
{
  read_uid(2,param_1,6);
  *param_1 = *param_1 ^ param_1[5];
  param_1[1] = param_1[1] ^ param_1[4];
  param_1[2] = param_1[2] ^ param_1[3];
  param_1[5] = 0xe4;
  param_1[4] = 0x17;
  param_1[3] = 0xd8;
  if (param_2 == 1) {
    param_1[1] = param_1[1] ^ ~*param_1 + 1;
    param_1[2] = param_1[2] ^ ~*param_1 + 2;
  }
  else if (param_2 == 2) {
    *param_1 = *param_1 ^ ~param_1[2] + 3;
    param_1[1] = param_1[1] ^ ~param_1[2] + 4;
  }
  else if (param_2 == 0) {
    *param_1 = *param_1 ^ param_1[1] + 5;
    param_1[1] = param_1[1] ^ param_1[2] + 6;
  }
  else if (param_2 == 4) {
    param_1[2] = ~param_1[2];
  }
  return;
}
#endif

/* 0101c340 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char * FUN_0101c340(void)
{
  char *pcVar1;
  
  pcVar1 = _DAT_000206a0;
  if ((DAT_000201b4 != '\x03') && (DAT_000201b4 != '\x01')) {
    if (DAT_000201b4 == '\0') {
      pcVar1 = STR_0101c37c;
    }
    else if (DAT_000201b4 == '\x02') {
      pcVar1 = STR_0101c38c;
    }
  }
  return pcVar1;
}
#endif

/* 0101c3a0 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 FUN_0101c3a0(void)
{
  return _DAT_00020620;
}
#endif

/* 0101c3ac */
#ifdef NONMATCHING
char FUN_0101c3ac(undefined4 param_1)
{
  char cVar1;
  int iVar2;
  
  if (DAT_000201b8 == '\0') {
    if (DAT_000201b4 == '\x06') {
      DAT_0002030a = FUN_0101c6f0(param_1);
      if (DAT_0002013c == DAT_0002030a) {
        if ((DAT_000201b6 == '\x06') || (iVar2 = FUN_0101f0bc(), iVar2 == 0)) {
          cVar1 = DAT_0002030a;
        }
        else {
          cVar1 = DAT_000201b6;
        }
      }
      else {
        cVar1 = DAT_0002030a;
      }
    }
    else {
      cVar1 = DAT_000201b4;
    }
  }
  else {
    cVar1 = '\x03';
  }
  return cVar1;
}
#endif

/* 0101c414 */
undefined4 FUN_0101c414(void)
{
  return;
}

/* 0101c418 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 poll_flags(void)
{
  return _DAT_000201bc;
}
#endif

/* 0101c424 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0101c424(void)
{
  return _DAT_0002fff4;
}
#endif

/* 0101c430 */
#ifdef NONMATCHING
undefined8 FUN_0101c430(undefined4 param_1)
{
  return CONCAT44(param_1,&DAT_00009018);
}
#endif

/* 0101c43c */
#ifdef NONMATCHING
void FUN_0101c43c(undefined4 param_1,undefined4 param_2)
{
  FUN_010188d2(param_1,param_2);
  return;
}
#endif

/* 0101c44c */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0101c44c(void)
{
  return _DAT_00020198;
}
#endif

/* 0101c458 */
#ifdef NONMATCHING
uint FUN_0101c458(uint param_1,int param_2,int param_3)
{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  uint uVar5;
  undefined2 local_40;
  ushort local_3e;
  undefined2 local_3c;
  ushort local_3a;
  uint local_2c;
  code *local_28;
  uint local_24;
  uint local_20;
  int local_1c;
  int local_18;
  
  uVar5 = 0;
  local_20 = param_1;
  local_1c = param_2;
  local_18 = param_3;
  do {
    if (1 < uVar5) {
      return param_1;
    }
    pbVar3 = (byte *)(uVar5 * 4 + 2 + local_20);
    if ((local_18 == 1) &&
       ((iVar2 = FUN_0101a9ac(uVar5 * 4 + 2 + local_20), iVar2 != 0 ||
        ((((pbVar3[1] == 0x80 && (pbVar3[2] == 0x31)) && (pbVar3[3] == 0x40)) &&
         (((*pbVar3 < 10 || ((*pbVar3 & 3) == 2)) || ((*pbVar3 & 3) == 3)))))))) {
      local_40 = 0;
      local_3e = 0;
      local_3c = 0;
      local_3a = 0;
LAB_0101c6a4:
      memcpy(uVar5 * 0x14 + local_1c,&local_40,0x14);
    }
    else {
      local_24 = (pbVar3[1] & 1) << 8 | (uint)*pbVar3;
      bVar1 = pbVar3[1];
      uVar4 = bVar1 & 0xfe;
      local_2c = pbVar3[2] & 0x7f;
      local_28 = (code *)((uint)pbVar3[3] << 8 | pbVar3[2] & 0x80);
      if (local_28 < (code *)0x4000) {
        if ((bVar1 & 0x1e) == 0) {
          local_28 = (code *)&DAT_00004680;
        }
        else if ((bVar1 & 0x1e) == 2) {
          local_28 = FUN_00004480;
        }
        else {
          local_28 = (code *)0x4000;
        }
LAB_0101c620:
        if (local_24 < 4) {
          local_24 = 4;
        }
        local_40 = *(undefined2 *)(&DAT_010291ac + (((int)(local_24 - 4) >> 2) + 0x21U & 0xff) * 2);
        local_3e = *(ushort *)(&DAT_010292ec + ((int)uVar4 >> 1) * 2);
        iVar2 = FUN_01020a50(local_40);
        local_3e = FUN_01018240(iVar2 * (uint)local_3e,100);
        local_3c = *(undefined2 *)(&DAT_010291ac + local_2c * 2);
        local_3a = *(ushort *)(&DAT_010292ec + (((uint)(local_28 + -0x4000) & 0x7fff) >> 7) * 2);
        iVar2 = FUN_01020a50(local_3c);
        local_3a = FUN_01018240(iVar2 * (uint)local_3a,100);
        goto LAB_0101c6a4;
      }
      if (local_28 < (code *)0x8000) goto LAB_0101c620;
      if (pbVar3[3] != 0x80) {
        if (uVar4 < 0x80) {
          if ((bVar1 & 2) == 0) {
            local_28 = FUN_00004480;
          }
          else {
            local_28 = (code *)&DAT_00004680;
          }
        }
        else {
          local_28 = (code *)&DAT_00006f80;
        }
        goto LAB_0101c620;
      }
      memzero(&local_40,0x14);
      if ((uint)pbVar3[2] == ((int)(uint)pbVar3[2] >> 2) * 4) {
        if ((*pbVar3 & 1) == 0) {
          if (0x1f < pbVar3[1]) {
            bVar1 = FUN_01018240((0xff - (uint)pbVar3[2]) * 5,9);
            uVar4 = (uint)bVar1;
            if (0x80 < uVar4) {
              uVar4 = 0x80;
            }
            local_3a = *(ushort *)(&DAT_010292ec + uVar4 * 2);
            local_3c = *(undefined2 *)(&DAT_010291ac + ((int)(uint)pbVar3[1] >> 1) * 2);
            iVar2 = FUN_01020a50(local_3c);
            local_3a = FUN_01018240(iVar2 * (uint)local_3e,100);
          }
        }
        else if (0x1f < pbVar3[1]) {
          bVar1 = FUN_01018240((0xff - (uint)pbVar3[2]) * 5,9);
          uVar4 = (uint)bVar1;
          if (0x80 < uVar4) {
            uVar4 = 0x80;
          }
          local_3e = *(ushort *)(&DAT_010292ec + uVar4 * 2);
          local_40 = *(undefined2 *)(&DAT_010291ac + ((int)(uint)pbVar3[1] >> 1) * 2);
          iVar2 = FUN_01020a50(local_40);
          local_3e = FUN_01018240(iVar2 * (uint)local_3e,100);
        }
      }
      memcpy(uVar5 * 0x14 + local_1c,&local_40,0x14);
    }
    param_1 = uVar5 + 1;
    uVar5 = param_1 & 0xff;
  } while( true );
}
#endif

/* 0101c6cc */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0101c6cc(void)
{
  return _DAT_000201d4;
}
#endif

/* 0101c6d8 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_0101c6d8(uint param_1)
{
  return (_DAT_000201c0 & param_1) != 0;
}
#endif

/* 0101c6f0 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_0101c6f0(undefined *param_1,int param_2)
{
  bool bVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  int local_20;
  
  uVar5 = 0xff;
  bVar1 = false;
  bVar6 = ((uint)param_1 & 0x400) != 0;
  uVar4 = (uint)param_1 & 0x3830;
  local_20 = param_2;
  if (_DAT_0002fff0 == 0x55667788) {
    DAT_000201b8 = '\x01';
    uVar5 = 3;
  }
  else if (uVar4 == 0x1000) {
    uVar5 = 3;
  }
  else if (uVar4 == 0x10) {
    uVar5 = 1;
  }
  else if (uVar4 == 0x800) {
    uVar5 = 4;
  }
  else if (uVar4 == 0x2000) {
    uVar5 = 2;
  }
  else if (uVar4 == 0x20) {
    uVar5 = 0;
  }
  else if (param_1 == &DAT_00003431) {
    thunk_FUN_0101f7d0();
  }
  else {
    if ((((uint)param_1 & 0x3c0) != 0) && (((uint)param_1 & 0xfffffc3f) == 0)) {
      cVar2 = '\0';
      local_20 = 0;
      while ((local_20 < 3 && (iVar3 = GPIO_ReadInputDataBit(1,0x40), iVar3 != 0))) {
        cVar2 = cVar2 + '\x01';
        rom_delay_a(0x32);
        local_20 = local_20 + 1;
      }
      if (cVar2 == '\x03') {
        bVar1 = true;
        uVar5 = 3;
      }
    }
    if (uVar5 == 0xff) {
      uVar5 = (uint)DAT_00021900;
    }
  }
  DAT_00020158 = bVar6;
  if (uVar5 < 5) {
    if (((DAT_000201b8 == '\0') && (DAT_00021900 != uVar5)) && (!bVar1)) {
      FUN_01022ca4(uVar5);
    }
  }
  else {
    uVar5 = 0;
  }
  return CONCAT44(local_20,uVar5);
}
#endif

/* 0101c808 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0101c808(uint param_1)
{
  _DAT_000f881c = _DAT_000f881c | 0x80;
  _DAT_000f8560 = _DAT_000f8560 & 0xfffffff0 | param_1;
  return;
}
#endif

/* 0101c830 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0101c830(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = FUN_01018240(192000000,(_DAT_000f8560 & 0xf) + 2,param_3,param_4,param_4);
  iVar3 = FUN_01018240(uVar2,200);
  bVar1 = FUN_01018240(param_1,5);
  SysTick_Config((uint)bVar1 * iVar3);
  DAT_0002058d = (char)param_1;
  return;
}
#endif

/* 0101c874 */
#ifdef NONMATCHING
void c874(int param_1)
{
  int iVar1;
  
  if (param_1 == 3) {
    idle_limit_set();
    if ((DAT_00020182 != '\x02') && (iVar1 = FUN_0101f0bc(), iVar1 == 0)) {
      FUN_0101f7d2();
    }
  }
  else {
    idle_limit_set();
    FUN_01020350(2);
    FUN_0102055c();
  }
  return;
}
#endif

/* 0101c8ac */
#ifdef NONMATCHING
void FUN_0101c8ac(void)
{
  int iVar1;
  
  iVar1 = usb_powered();
  if ((iVar1 == 0) && (DAT_00020168 == '\0')) {
    power_off();
  }
  DAT_000201dc = 0;
  return;
}
#endif

/* 0101c8d4 */
#ifdef NONMATCHING
void FUN_0101c8d4(uint param_1)
{
  if (DAT_000201b4 != param_1) {
    FUN_0101e01c();
    FUN_0101b242(0x32);
    DAT_000201b4 = (byte)param_1;
    FUN_01020354(0x800000);
  }
  return;
}
#endif

/* 0101c8fc */
void FUN_0101c8fc(void)
{
  return;
}

/* 0101c900 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Handle_HidConnectStateCallback(int param_1)
{
  int iVar1;
  uint uVar2;
  
  if (param_1 == 3) {
    if ((DAT_00020183 == '\x02') && (DAT_000201b8 != '\0')) {
      thunk_FUN_0101f7d0();
    }
    iVar1 = usb_powered();
    if (iVar1 == 0) {
      iVar1 = FUN_0101a8f4();
      if (iVar1 != 0) {
        FUN_010203c0();
        restart();
      }
      FUN_0101f7d2();
      iVar1 = usb_charging();
      if (iVar1 == 0) {
        if (DAT_00020167 == '\0') {
          if (DAT_00020183 == '\x02') {
            uVar2 = FUN_01023f04();
            if (uVar2 < _DAT_00020160 + 0xfaU) {
              Reconnect_Host(STR_0101ca04,STR_010283e0,&DAT_00002c60);
            }
            else {
              FUN_01024d0c(0);
              if (DAT_000201b8 == '\0') {
                FUN_0101fa38();
              }
            }
          }
          else {
            Reconnect_Host(STR_0101ca04,STR_010283e0,&DAT_00002c65);
          }
        }
        else {
          DAT_00020167 = '\0';
          rom_delay_a(200);
          restart();
        }
      }
      else {
        FUN_0101b5a0(0);
      }
    }
    else {
      FUN_0101b4ae(0);
    }
  }
  else {
    FUN_0101fba0();
    FUN_0101fc18();
    if (DAT_00020181 == '\x03') {
      if (DAT_000201b8 == '\0') {
        bt_disconnect();
      }
    }
    else {
      idle_limit_set();
      FUN_01020350(2);
      FUN_0102055c();
      _DAT_00020160 = FUN_01023f04();
      FUN_01024d7c();
    }
  }
  return;
}
#endif

/* 0101ca14 */
#ifdef NONMATCHING
void FUN_0101ca14(char *param_1,short param_2)
{
  if (*param_1 == -0x5b) {
    FUN_0101886c(param_1 + 1,param_2 + -1);
    FUN_01024cac(DAT_000201b4);
    FUN_01024bec();
  }
  return;
}
#endif
