/* battery.c: guessed: battery ADC and percentage, idle limit */

#include "zero2.h"

/* 01022844 */
#ifdef NONMATCHING
/* WARNING: Removing unreachable block (ram,0x01022896) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void battery_adc(void)
{
  int iVar1;
  
  iVar1 = adc_sample(0);
  if (((iVar1 != -1) && (iVar1 < 0x48c)) && (0x32a < iVar1)) {
    _DAT_000201c8 = FUN_01018240(iVar1 * 0x25,10);
    if (_DAT_000201c8 < 3000) {
      DAT_000201cc = 0;
    }
    else {
      DAT_000201cc = FUN_01018240(_DAT_000201c8 + -3000,10);
    }
  }
  return;
}
#endif

/* 010228bc */
#ifdef NONMATCHING
void battery_percent(void)
{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_0101c254();
  iVar2 = always_one();
  if (iVar2 == 0) {
    if (iVar1 < 0x899) {
      DAT_0002062d = 10;
    }
    else {
      DAT_0002062d = (byte)((((uint)(iVar1 + -0x960 >> 0x1f) >> 0x1d) + iVar1 + -0x960 & 0x7ff) >> 3
                           );
    }
  }
  else if (iVar1 < 0xd49) {
    DAT_0002062d = 10;
  }
  else {
    DAT_0002062d = FUN_01018240(iVar1 + -0xd48,7);
  }
  if (DAT_0002062d < 10) {
    DAT_0002062d = 0xb;
  }
  else if (100 < DAT_0002062d) {
    DAT_0002062d = 100;
  }
  return;
}
#endif

/* 01022938 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void idle_limit_set(void)
{
  undefined4 uVar1;
  
  FUN_010232b0();
  if ((DAT_00020182 == '\x02') || (DAT_00020682 == '\x02')) {
    _DAT_00020194 = &DAT_00015f90;
  }
  else {
    _DAT_00020194 = &DAT_00004650;
  }
  if (DAT_000201b4 == '\0') {
    uVar1 = FUN_01024bc0();
    _DAT_00020194 = (undefined *)FUN_01018214((int)_DAT_00020194 * 10,uVar1);
  }
  return;
}
#endif

/* 01022998 */
#ifdef NONMATCHING
void FUN_01022998(void)
{
  int iVar1;
  
  iVar1 = adc_sample(1);
  if (4 < iVar1) {
    iVar1 = iVar1 + -5;
  }
  if (iVar1 < 0xa4) {
    if (DAT_00020324 < 0xc) {
      DAT_00020324 = DAT_00020324 + 1;
    }
  }
  else if (DAT_00020324 != 0) {
    DAT_00020324 = DAT_00020324 - 1;
  }
  if (DAT_00020324 == 0) {
    GPIO_ResetBits(2,0x800);
  }
  else if (0xb < DAT_00020324) {
    GPIO_SetBits(2,0x800);
  }
  return;
}
#endif

/* 01022a00 */
#ifdef NONMATCHING
void FUN_01022a00(void)
{
  if (DAT_000201b4 == '\x01') {
    FUN_01022aec(8);
  }
  else {
    FUN_01022aec(0x40);
  }
  return;
}
#endif

/* 01022a20 */
#ifdef NONMATCHING
/* WARNING: Removing unreachable block (ram,0x01022a84) */
/* WARNING: Removing unreachable block (ram,0x01022a8c) */
/* WARNING: Removing unreachable block (ram,0x01022a94) */
/* WARNING: Removing unreachable block (ram,0x01022aae) */
/* WARNING: Removing unreachable block (ram,0x01022a9c) */
/* WARNING: Removing unreachable block (ram,0x01022a74) */
/* WARNING: Removing unreachable block (ram,0x01022abe) */
/* WARNING: Removing unreachable block (ram,0x01022a3c) */
/* WARNING: Removing unreachable block (ram,0x01022a4e) */
/* WARNING: Removing unreachable block (ram,0x01022a56) */
/* WARNING: Removing unreachable block (ram,0x01022a5e) */

void FUN_01022a20(void)
{
  int iVar1;
  byte local_50;
  undefined1 local_4f [63];
  
  iVar1 = FUN_01024ab4();
  if (iVar1 == 1) {
    FUN_01024b28(&local_50,0x40);
    if (0x40 < local_50) {
      local_50 = 0x40;
    }
    FUN_01022d0c(0x97,0,local_4f,local_50);
  }
  return;
}
#endif

/* 01022aec */
void FUN_01022aec(void)
{
  return;
}

/* 01022af0 */
#ifdef NONMATCHING
void FUN_01022af0(void)
{
  if ((DAT_00020182 == '\x02') && (DAT_000201b8 == '\0')) {
    DAT_00020182 = '\x03';
    FUN_0101b4d8();
  }
  return;
}
#endif

/* 01022b18 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01022b18(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  undefined4 uVar1;
  int iVar2;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_18 = param_3;
  uStack_14 = param_4;
  FUN_01020c1c();
  FUN_0101f96c();
  uVar1 = FUN_01018240(192000000,(_DAT_000f8560 & 0xf) + 2);
  FUN_01018240(uVar1,100);
  SysTick_Config();
  DAT_000201b7 = 1;
  DAT_000201b8 = 0;
  DAT_000201cd = 1;
  DAT_000201cf = 1;
  DAT_000201dc = 0;
  DAT_000201b6 = 6;
  memzero(&DAT_00021864,0x54);
  _DAT_00020340 = 0;
  _DAT_00020154 = 0;
  FUN_0101aa14(0xffff);
  FUN_01022c48();
  FUN_0102041c();
  FUN_01020400(1,DAT_000201b4);
  FUN_0101c294(&uStack_18);
  FUN_01023aea(0x2032c,&uStack_18);
  FUN_0101a9e0(0xfffff);
  FUN_01020b8e();
  FUN_01022328();
  DAT_00020181 = 0;
  DAT_00020182 = 0;
  DAT_00020184 = 0;
  DAT_0002058c = 0xf;
  FUN_0101a564();
  FUN_01020354(0x200000);
  iVar2 = FUN_0101f0bc();
  if (iVar2 != 0) {
    FUN_01020354(0x800000);
  }
  FUN_01024ce4();
  memcpy(0x20179,&DAT_0102823e,6);
  FUN_0101a9dc();
  FUN_0101a718(0);
  return;
}
#endif

/* 01022c48 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01022c48(void)
{
  uint uVar1;
  
  FUN_0101828c(&DAT_00021900,0x20,0xff);
  flash_read(0x1074000,&DAT_00021900,0x20);
  uVar1 = FUN_01024114(&DAT_00021900,0x1e);
  if (uVar1 == _DAT_0002191e) {
    DAT_0002015c = DAT_00021901;
    _DAT_0002015a = _DAT_00021902;
  }
  else {
    memzero(&DAT_00021900,0x20);
    DAT_00021900 = 0;
  }
  FUN_0102417c();
  return;
}
#endif

/* 01022ca4 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01022ca4(undefined1 param_1)
{
  undefined1 auStack_28 [32];
  
  DAT_00021901 = DAT_0002015c;
  _DAT_00021902 = _DAT_0002015a;
  DAT_00021900 = param_1;
  _DAT_0002191e = FUN_01024114(&DAT_00021900,0x1e);
  FUN_0101828c(auStack_28,0x20,0xff);
  memcpy(auStack_28,&DAT_00021900,0x20);
  flash_erase(0x1074000);
  flash_write(0x1074000,auStack_28,0x20);
  flash_read(0x1074000,&DAT_00021900,0x20);
  return;
}
#endif

/* 01022d0c */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01022d0c(int param_1,undefined4 param_2,char *param_3,undefined4 param_4)
{
  if (*param_3 != '\x01') {
    if (*param_3 == '\0') {
      if ((param_3[1] == '\x1e') && (DAT_00020182 == '\x02')) {
        DAT_00020185 = 3;
      }
      if (param_3[1] == '\x1a') {
        FUN_01022e14(param_1,param_2);
      }
      if (param_3[1] == '\x1f') {
        DAT_000201b8 = '\x01';
        FUN_01022768();
        if (DAT_000201b8 != '\0') {
          FUN_0101b5a0(0);
        }
        FUN_0101b66c();
      }
      if (param_3[1] == '!') {
        FUN_010227dc();
      }
      if (param_3[1] == 'P') {
        FUN_01020354(0x80000000);
      }
      if (param_3[1] == '\x1b') {
        DAT_00020182 = 0;
        FUN_0101a75c();
        do {
                    /* WARNING: Do nothing block with infinite loop */
        } while( true );
      }
      if (param_3[1] == '0') {
        FUN_0101e674(param_3 + 3);
      }
      if (param_3[1] == '\x1c') {
        _DAT_00020358 = *(undefined2 *)(&DAT_01028400 + (uint)(byte)param_3[4] * 2);
        DAT_00020182 = '\x02';
        if (param_1 == 6) {
          DAT_0002035a = 1;
        }
        else if (param_1 == 7) {
          DAT_0002035a = 3;
        }
        idle_limit_set();
        FUN_01024d78();
        DAT_00020185 = 0;
      }
      if (param_3[1] == 'Q') {
        FUN_0101a7b8(param_3[2]);
      }
    }
    else if (*param_3 == '\x03') {
      FUN_01022f48(param_3 + 1,6,param_3,param_4,param_4);
    }
  }
  return;
}
#endif

/* 01022e8c */
void FUN_01022e8c(void)
{
  TIM_Cmd(1,0);
  TIM_Cmd(2,0);
  return;
}
