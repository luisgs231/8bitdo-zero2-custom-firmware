/* yc_adc.c: ..\Librarier\sdk\yc_adc.c in ADC_Init's assert */

#include "zero2.h"

/* 01018420 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01018420(void)
{
  undefined1 uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = DAT_000f872b;
  cVar2 = '\x05';
  DAT_000f872b = 0x3e;
  rom_delay_a(5);
  while( true ) {
    iVar3 = adc_once(6);
    log_empty(STR_010296f0
              ,cVar2,iVar3);
    if ((0x3e0 < iVar3) && (iVar3 < 0x420)) goto code_r0x0101847c;
    if (cVar2 == '\0') break;
    rom_delay_a(100);
    cVar2 = cVar2 + -1;
  }
  rom_delay_a(500);
code_r0x0101847c:
  DAT_000f872b = uVar1;
  iVar4 = FUN_01018240(((uint)CONCAT11(DAT_000210a3,DAT_000210a2) - iVar3) * 1000,500);
  iVar4 = FUN_01018240((uint)CONCAT11(DAT_000210a3,DAT_000210a2) * 1000 + iVar4 * 500,1000);
  if ((int)(uint)CONCAT11(DAT_000210a9,DAT_000210a8) < iVar4) {
    iVar4 = iVar4 - (uint)CONCAT11(DAT_000210a9,DAT_000210a8);
  }
  else {
    iVar4 = (uint)CONCAT11(DAT_000210a9,DAT_000210a8) - iVar4;
  }
  if (iVar4 < 0x21) {
    _DAT_00020040 = 500;
    _DAT_00020044 = 1000;
  }
  else {
    DAT_000210a9 = DAT_000210a3;
    DAT_000210a8 = DAT_000210a2;
    DAT_000210a2 = (undefined1)iVar3;
    DAT_000210a3 = (undefined1)((uint)iVar3 >> 8);
    _DAT_00020040 = 0;
    _DAT_00020044 = 500;
  }
  return;
}
#endif

/* 01018544 */
#ifdef NONMATCHING
void FUN_01018544(void)
{
  GPIO_Config(2,0x20,0xc0);
  GPIO_Config(2,0x40,0xc0);
  ADC_Init();
  GPIO_Config(2,0x20,0xc0);
  GPIO_Config(2,0x40,0xc0);
  battery_adc();
  return;
}
#endif

/* 01018580 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort adc_once(byte param_1)
{
  ushort uVar1;
  
  uVar1 = 0;
  if (DAT_00020039 != '\0') {
    DAT_000c8970 = 0x7f;
    DAT_000c8972 = 0xaa;
    DAT_000c8973 = param_1 | 0x30;
    rom_delay_b(100);
    uVar1 = _DAT_000f850e & 0x7fe;
  }
  return uVar1;
}
#endif

/* 010185c0 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * adc_sample(undefined4 param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined *puVar5;
  int iVar6;
  int local_78 [20];
  int local_28;
  undefined *local_24;
  undefined4 local_20;
  undefined *local_1c;
  undefined4 local_18;
  
  local_1c = (undefined *)0x0;
  iVar3 = 0;
  iVar6 = 0;
  local_20 = 0xaf0;
  local_24 = &DAT_00001388;
  local_28 = 0xb5a40;
  local_18 = param_1;
  memzero(local_78,0x50);
  iVar1 = (int)(DAT_000c8971 & 0x70) >> 4;
  if (DAT_00020039 != '\0') {
    if (iVar1 == 0) {
      iVar1 = (uint)CONCAT11(DAT_000210a3,DAT_000210a2) * 1000;
      local_28 = (uint)CONCAT11(DAT_000210a9,DAT_000210a8) * 1000;
      local_20 = _DAT_00020040;
      local_24 = _DAT_00020044;
      local_1c = (undefined *)0x4b0;
    }
    else if (iVar1 == 2) {
      iVar1 = (uint)CONCAT11(DAT_000210a5,DAT_000210a4) * 1000;
      local_28 = (uint)CONCAT11(DAT_000210ab,DAT_000210aa) * 1000;
      local_20 = 0xce4;
      local_24 = &DAT_00001388;
      local_1c = &DAT_0000157c;
    }
    else {
      if (iVar1 != 3) {
        return (undefined *)0xffffffff;
      }
      iVar1 = (uint)CONCAT11(DAT_000210a5,DAT_000210a4) * 1000;
      local_28 = (uint)CONCAT11(DAT_000210ab,DAT_000210aa) * 1000;
      local_20 = 2000;
      local_24 = (undefined *)0xbb8;
      local_1c = (undefined *)0x4b0;
    }
    if ((iVar1 != 0) && (local_28 != 0)) {
      do {
        if (0x13 < iVar3) {
          for (iVar3 = 1; iVar3 < 0x14; iVar3 = iVar3 + 1) {
            iVar6 = local_78[iVar3];
            iVar1 = iVar3;
            while ((iVar4 = iVar1 + -1, -1 < iVar4 && (iVar6 < local_78[iVar4]))) {
              local_78[iVar1] = local_78[iVar4];
              iVar1 = iVar4;
            }
            local_78[iVar1] = iVar6;
          }
          iVar1 = 0;
          for (iVar3 = 6; iVar3 < 0xe; iVar3 = iVar3 + 1) {
            iVar1 = local_78[iVar3] + iVar1;
          }
          puVar5 = (undefined *)((int)(((uint)(iVar1 >> 0x1f) >> 0x1d) + iVar1) >> 3);
          if ((int)local_1c < (int)puVar5) {
            return local_1c;
          }
          return puVar5;
        }
        iVar2 = adc_once(local_18);
        iVar4 = iVar3;
        if (0 < iVar2) {
          iVar2 = FUN_010240cc(iVar2,local_28,iVar1,local_24,local_20);
          iVar4 = iVar3 + 1;
          local_78[iVar3] = iVar2;
        }
        iVar6 = iVar6 + 1;
        iVar3 = iVar4;
      } while (iVar6 < 0x1f);
    }
  }
  return (undefined *)0xffffffff;
}
#endif

/* 0101879c */
#ifdef NONMATCHING
void ADC_Init(byte *param_1)
{
  if ((((*param_1 != 0) && (*param_1 != 1)) && (*param_1 != 2)) &&
     (((*param_1 != 3 && (*param_1 != 4)) &&
      ((*param_1 != 5 && ((*param_1 != 6 && (*param_1 != 7)))))))) {
    assert_failed(STR_0101883c,0x61,STR_0102795a);
  }
  if ((((param_1[1] != 0) && (param_1[1] != 1)) && (param_1[1] != 2)) && (param_1[1] != 3)) {
    assert_failed(STR_0101883c,0x62,STR_0102795a);
  }
  core_bringup();
  DAT_000c8971 = param_1[1] << 4 | 0x8c;
  DAT_000c8970 = 0x7f;
  DAT_000c8972 = 0xaa;
  DAT_000c8973 = *param_1 | 0x30;
  read_uid(300,0x210a0,0x10);
  rom_delay_a(100);
  FUN_01018420();
  return;
}
#endif

/* 0101886c */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0101886c(char *param_1)
{
  if (*param_1 == -0x26) {
    DAT_000201d1 = DAT_000201d1 | 0x80;
  }
  else if (*param_1 == -0x24) {
    DAT_000201d1 = DAT_000201d1 | 1;
  }
  else if (*param_1 == -0x25) {
    FUN_010200bc(param_1[1],param_1[2],0x2d,3);
  }
  else {
    DAT_000201d1 = 0;
  }
  _DAT_000201d8 = FUN_0101c6cc();
  return;
}
#endif

/* 010188c8 */
void FUN_010188c8(void)
{
  FUN_0101e77c(0);
  return;
}

/* 010188d2 */
#ifdef NONMATCHING
void FUN_010188d2(byte *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  undefined4 local_18;
  
  local_18 = param_4;
  if ((*param_1 & 3) == 1) {
    if (param_1[1] == 1) {
      local_18 = 1;
      FUN_0101e7a4(0,1,9,&local_18);
    }
    else {
      FUN_0101e7a4(2,1,0);
    }
  }
  else if ((*param_1 & 3) == 2) {
    if (param_1[1] == 1) {
      FUN_0101e7a4(0,2,1,&local_18);
    }
    else {
      FUN_0101e7a4(2,2,0);
    }
  }
  else {
    FUN_0101e7a4(4,2,0);
  }
  return;
}
#endif

/* 01018940 */
#ifdef NONMATCHING
void FUN_01018940(byte *param_1,int param_2)
{
  if (DAT_000201b4 == '\x02') {
    FUN_0101e7e2(0);
  }
  else if (((*param_1 & 3) == 2) && (1 < param_2)) {
    if (param_1[1] == 1) {
      FUN_0101e7d6(0);
    }
    else {
      FUN_0101e7d6(2);
    }
  }
  else {
    FUN_0101e7d6(4);
  }
  return;
}
#endif

/* 0101898c */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 FUN_0101898c(undefined4 param_1,undefined2 param_2,undefined1 param_3)
{
  int iVar1;
  undefined1 uStack_18;
  undefined1 local_17;
  undefined2 local_16;
  undefined4 local_14;
  
  _uStack_18 = CONCAT22(param_2,CONCAT11(0x78,param_3));
  local_14 = param_1;
  FUN_01018a54(&DAT_00020010,0x20);
  ipc_send(&uStack_18);
  _DAT_0002000c = now();
  do {
    iVar1 = FUN_01018a76(&DAT_00020010,0x20);
    if (iVar1 != 0) {
      return CONCAT11(DAT_00020019,DAT_00020018);
    }
    iVar1 = elapsed(_DAT_0002000c,500);
  } while (iVar1 == 0);
  return 0;
}
#endif

/* 010189f0 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 FUN_010189f0(undefined4 param_1,undefined2 param_2,undefined1 param_3)
{
  int iVar1;
  undefined1 uStack_18;
  undefined1 local_17;
  undefined2 local_16;
  undefined4 local_14;
  
  _uStack_18 = CONCAT22(param_2,CONCAT11(0x77,param_3));
  local_14 = param_1;
  FUN_01018a54(&DAT_00020010,0x20);
  ipc_send(&uStack_18);
  _DAT_0002000c = now();
  do {
    iVar1 = FUN_01018a76(&DAT_00020010,0x20);
    if (iVar1 != 0) {
      return CONCAT11(DAT_00020019,DAT_00020018);
    }
    iVar1 = elapsed(_DAT_0002000c,500);
  } while (iVar1 == 0);
  return 0;
}
#endif

/* 01018a54 */
#ifdef NONMATCHING
void FUN_01018a54(uint *param_1,uint param_2)
{
  if ((int)param_2 < 0x20) {
    *param_1 = *param_1 & ~(1 << (param_2 & 0xff));
  }
  else {
    param_1[1] = param_1[1] & ~(1 << (param_2 - 0x20 & 0xff));
  }
  return;
}
#endif

/* 01018a76 */
#ifdef NONMATCHING
uint FUN_01018a76(uint *param_1,uint param_2)
{
  uint uVar1;
  
  if ((int)param_2 < 0x20) {
    uVar1 = (*param_1 & 1 << (param_2 & 0xff)) >> (param_2 & 0xff);
  }
  else {
    uVar1 = (param_1[1] & 1 << (param_2 - 0x20 & 0xff)) >> (param_2 - 0x20 & 0xff);
  }
  return uVar1 & 0xff;
}
#endif

/* 01018aa4 */
#ifdef NONMATCHING
void FUN_01018aa4(uint *param_1,uint param_2)
{
  if ((int)param_2 < 0x20) {
    *param_1 = *param_1 | 1 << (param_2 & 0xff);
  }
  else {
    param_1[1] = param_1[1] | 1 << (param_2 - 0x20 & 0xff);
  }
  return;
}
#endif
