/* startup.c: guessed: entry, __main and the scatter loader, armcc's memcpy and memclr */

#include "zero2.h"

/* 01018000 */
#ifdef NONMATCHING
void entry(void)
{
  FUN_01018200();
  return;
}
#endif

/* 01018004 */
#ifdef NONMATCHING
undefined4 FUN_01018004(void)
{
  FUN_010180e6();
  return 0xfffffff9;
}
#endif

/* 0101800a */
#ifdef NONMATCHING
undefined4 FUN_0101800a(void)
{
  FUN_010180e8();
  return 0xfffffff9;
}
#endif

/* 01018010 */
#ifdef NONMATCHING
undefined4 FUN_01018010(void)
{
  FUN_010180ea();
  return 0xfffffff9;
}
#endif

/* 01018016 */
#ifdef NONMATCHING
undefined4 FUN_01018016(void)
{
  FUN_01020210();
  return 0xfffffff9;
}
#endif

/* 0101801c */
#ifdef NONMATCHING
void FUN_0101801c(void)
{
  FUN_01022318();
  return;
}
#endif

/* 01018020 */
#ifdef NONMATCHING
void FUN_01018020(void)
{
  FUN_010180fa();
  return;
}
#endif

/* 01018024 */
#ifdef NONMATCHING
void FUN_01018024(void)
{
  FUN_010180fa();
  return;
}
#endif

/* 01018028 */
#ifdef NONMATCHING
void FUN_01018028(void)
{
  FUN_010180fa();
  return;
}
#endif

/* 0101802c */
#ifdef NONMATCHING
void FUN_0101802c(void)
{
  FUN_010180fa();
  return;
}
#endif

/* 01018030 */
#ifdef NONMATCHING
void FUN_01018030(void)
{
  FUN_010180fa();
  return;
}
#endif

/* 01018034 */
#ifdef NONMATCHING
void FUN_01018034(void)
{
  FUN_010180fa();
  return;
}
#endif

/* 01018038 */
#ifdef NONMATCHING
void FUN_01018038(void)
{
  FUN_010180fa();
  return;
}
#endif

/* 0101803c */
#ifdef NONMATCHING
void FUN_0101803c(void)
{
  FUN_010180fa();
  return;
}
#endif

/* 01018040 */
#ifdef NONMATCHING
void FUN_01018040(void)
{
  FUN_010180fa();
  return;
}
#endif

/* 01018044 */
#ifdef NONMATCHING
void FUN_01018044(void)
{
  FUN_010180fa();
  return;
}
#endif

/* 01018048 */
#ifdef NONMATCHING
void FUN_01018048(void)
{
  FUN_01018d2c();
  return;
}
#endif

/* 0101804c */
#ifdef NONMATCHING
void FUN_0101804c(void)
{
  FUN_0101b8fc();
  return;
}
#endif

/* 01018050 */
#ifdef NONMATCHING
void FUN_01018050(void)
{
  FUN_010180fa();
  return;
}
#endif

/* 01018054 */
#ifdef NONMATCHING
void FUN_01018054(void)
{
  FUN_010180fa();
  return;
}
#endif

/* 01018058 */
#ifdef NONMATCHING
void FUN_01018058(void)
{
  FUN_010180fa();
  return;
}
#endif

/* 0101805c */
#ifdef NONMATCHING
void FUN_0101805c(void)
{
  FUN_010180fa();
  return;
}
#endif

/* 01018060 */
#ifdef NONMATCHING
void FUN_01018060(void)
{
  FUN_010180fa();
  return;
}
#endif

/* 01018064 */
#ifdef NONMATCHING
void FUN_01018064(void)
{
  FUN_010180fa();
  return;
}
#endif

/* 01018068 */
#ifdef NONMATCHING
void FUN_01018068(void)
{
  FUN_010180fa();
  return;
}
#endif

/* 0101806c */
#ifdef NONMATCHING
void FUN_0101806c(void)
{
  FUN_010180fa();
  return;
}
#endif

/* 01018070 */
#ifdef NONMATCHING
void FUN_01018070(void)
{
  FUN_010180fa();
  return;
}
#endif

/* 01018074 */
#ifdef NONMATCHING
void FUN_01018074(void)
{
  FUN_010180fa();
  return;
}
#endif

/* 01018078 */
#ifdef NONMATCHING
void FUN_01018078(void)
{
  FUN_010180fa();
  return;
}
#endif

/* 0101807c */
#ifdef NONMATCHING
void FUN_0101807c(void)
{
  FUN_010180fa();
  return;
}
#endif

/* 01018080 */
#ifdef NONMATCHING
void FUN_01018080(void)
{
  FUN_010180fa();
  return;
}
#endif

/* 01018084 */
#ifdef NONMATCHING
void FUN_01018084(void)
{
  FUN_010180fa();
  return;
}
#endif

/* 01018088 */
#ifdef NONMATCHING
void FUN_01018088(void)
{
  FUN_01018200();
  return;
}
#endif

/* 0101808c */
#ifdef NONMATCHING
void FUN_0101808c(void)
{
  (*(code *)&PTR_FUN_01022318_1_010180fc)();
  return;
}
#endif

/* 01018090 */
#ifdef NONMATCHING
void FUN_01018090(void)
{
  (*(code *)&DAT_010180ac)();
  return;
}
#endif

/* 01018094 */
#ifdef NONMATCHING
void thunk_FUN_01022318(void)
{
  (*(code *)&DAT_010180b0)();
  return;
}
#endif

/* 01018098 */
#ifdef NONMATCHING
void thunk_FUN_01022318(void)
{
  (*(code *)&DAT_010180d0)();
  return;
}
#endif

/* 010180aa */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_010180aa(undefined2 *param_1,undefined2 param_2)
{
  int unaff_r4;
  
  *(short *)(unaff_r4 + 0x2a) = (short)unaff_r4;
  *param_1 = param_2;
  _DAT_000f8564 = 1;
  entry();
  return;
}
#endif

/* 010180b4 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_010180b4(void)
{
  _DAT_000f8564 = 1;
  entry();
  return;
}
#endif

/* 010180c2 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_010180c2(void)
{
  _DAT_000f8564 = 2;
  return;
}
#endif

/* 010180ce */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_010180ce(void)
{
  _DAT_000f8564 = 2;
  (*(code *)0x1000201)();
  return;
}
#endif

/* 010180d4 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_010180d4(void)
{
  _DAT_000f8564 = 2;
  (*(code *)0x1000201)();
  return;
}
#endif

/* 010180e2 */
#ifdef NONMATCHING
void thunk_FUN_010180e4(void)
{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}
#endif

/* 010180ea */
void FUN_010180ea(void)
{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

/* 010180ec */
void FUN_010180ec(void)
{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

/* 010180ee */
void FUN_010180ee(void)
{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

/* 010180f0 */
void FUN_010180f0(void)
{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

/* 010180f2 */
void FUN_010180f2(void)
{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

/* 010180f4 */
void FUN_010180f4(void)
{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

/* 010180f6 */
void FUN_010180f6(void)
{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

/* 010180f8 */
void FUN_010180f8(void)
{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

/* 010180fa */
void FUN_010180fa(void)
{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

/* 01018200 */
#ifdef NONMATCHING
/* WARNING: This function may have set the stack pointer */

void FUN_01018200(void)
{
  FUN_01018364();
  main();
  return;
}
#endif

/* 01018208 */
#ifdef NONMATCHING
void __main(void)
{
  main();
  return;
}
#endif

/* 01018214 */
#ifdef NONMATCHING
int FUN_01018214(uint param_1,uint param_2)
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = 0;
  uVar2 = 0x20;
  while (uVar3 = uVar2 - 1, 0 < (int)uVar2) {
    uVar2 = uVar3;
    if (param_2 <= param_1 >> (uVar3 & 0xff)) {
      param_1 = param_1 - (param_2 << (uVar3 & 0xff));
      iVar1 = iVar1 + (1 << (uVar3 & 0xff));
    }
  }
  return iVar1;
}
#endif

/* 01018240 */
#ifdef NONMATCHING
int FUN_01018240(int param_1,int param_2)
{
  int iVar1;
  bool bVar2;
  bool bVar3;
  
  bVar2 = param_1 < 0;
  if (bVar2) {
    param_1 = -param_1;
  }
  bVar3 = param_2 < 0;
  if (bVar3) {
    param_2 = -param_2;
  }
  iVar1 = FUN_01018214(param_1,param_2);
  if (bVar2 != bVar3) {
    iVar1 = -iVar1;
  }
  return iVar1;
}
#endif

/* 01018268 */
#ifdef NONMATCHING
void memcpy(undefined4 *param_1,undefined4 *param_2,uint param_3)
{
  undefined4 uVar1;
  bool bVar2;
  
  if ((((uint)param_1 | (uint)param_2) & 3) == 0) {
    for (; 3 < param_3; param_3 = param_3 - 4) {
      uVar1 = *param_2;
      param_2 = param_2 + 1;
      *param_1 = uVar1;
      param_1 = param_1 + 1;
    }
  }
  while (bVar2 = param_3 != 0, param_3 = param_3 - 1, bVar2) {
    *(undefined1 *)param_1 = *(undefined1 *)param_2;
    param_1 = (undefined4 *)((int)param_1 + 1);
    param_2 = (undefined4 *)((int)param_2 + 1);
  }
  return;
}
#endif

/* 0101828c */
#ifdef NONMATCHING
void FUN_0101828c(undefined1 *param_1,int param_2,undefined1 param_3)
{
  bool bVar1;
  
  while (bVar1 = param_2 != 0, param_2 = param_2 + -1, bVar1) {
    *param_1 = param_3;
    param_1 = param_1 + 1;
  }
  return;
}
#endif

/* 0101829a */
#ifdef NONMATCHING
void memzero(undefined4 param_1,undefined4 param_2)
{
  FUN_0101828c(param_1,param_2,0);
  return;
}
#endif

/* 0101829e */
#ifdef NONMATCHING
undefined4 FUN_0101829e(undefined4 param_1,undefined4 param_2,undefined4 param_3)
{
  FUN_0101828c(param_1,param_3,param_2);
  return param_1;
}
#endif

/* 010182b0 */
#ifdef NONMATCHING
undefined4 FUN_010182b0(int param_1,int param_2,uint param_3)
{
  uint uVar1;
  
  for (uVar1 = 0; (uVar1 < param_3 && (*(char *)(param_1 + uVar1) == *(char *)(param_2 + uVar1)));
      uVar1 = uVar1 + 1) {
  }
  return;
}
#endif

/* 010182ca */
#ifdef NONMATCHING
char * FUN_010182ca(char *param_1,char *param_2)
{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = param_1;
  do {
    cVar1 = *param_2;
    *pcVar2 = cVar1;
    pcVar2 = pcVar2 + 1;
    param_2 = param_2 + 1;
  } while (cVar1 != '\0');
  return param_1;
}
#endif

/* 010182dc */
#ifdef NONMATCHING
uint FUN_010182dc(int param_1,undefined4 param_2,uint param_3)
{
  byte *pbVar1;
  int iVar2;
  
  iVar2 = 3;
  pbVar1 = (byte *)(param_1 + 4);
  do {
    pbVar1 = pbVar1 + -1;
    param_3 = param_3 << 8 | (uint)*pbVar1;
    iVar2 = iVar2 + -1;
  } while (-1 < iVar2);
  return param_3;
}
#endif

/* 010182f0 */
#ifdef NONMATCHING
uint FUN_010182f0(uint param_1,undefined1 *param_2)
{
  uint uVar1;
  int iVar2;
  
  iVar2 = 3;
  uVar1 = param_1;
  do {
    *param_2 = (char)uVar1;
    uVar1 = uVar1 >> 8;
    param_2 = param_2 + 1;
    iVar2 = iVar2 + -1;
  } while (-1 < iVar2);
  return param_1;
}
#endif

/* 01018302 */
#ifdef NONMATCHING
longlong FUN_01018302(uint param_1,int param_2,uint param_3,uint param_4)
{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  undefined8 uVar6;
  longlong lVar7;
  int local_2c;
  
  lVar1 = 0;
  iVar3 = 0x40;
  local_2c = param_2;
  while (iVar4 = iVar3 + -1, 0 < iVar3) {
    uVar6 = FUN_010183a8(param_1,local_2c,iVar4);
    uVar2 = (uint)((ulonglong)uVar6 >> 0x20);
    iVar3 = iVar4;
    if (param_4 < uVar2 || uVar2 - param_4 < (uint)(param_3 <= (uint)uVar6)) {
      uVar6 = FUN_01018388(param_3,param_4,iVar4);
      bVar5 = param_1 < (uint)uVar6;
      param_1 = param_1 - (uint)uVar6;
      local_2c = (local_2c - (int)((ulonglong)uVar6 >> 0x20)) - (uint)bVar5;
      lVar7 = FUN_01018388(1,0,iVar4);
      lVar1 = lVar7 + lVar1;
    }
  }
  return lVar1;
}
#endif

/* 01018364 */
#ifdef NONMATCHING
longlong FUN_01018364(void)
{
  int extraout_r1;
  uint uVar1;
  undefined4 *puVar2;
  uint in_stack_00000130;
  
  for (puVar2 = &DAT_0102982c; puVar2 < &DAT_0102984c; puVar2 = puVar2 + 4) {
    (*(code *)puVar2[3])(*puVar2,puVar2[1],puVar2[2]);
  }
  __main();
  uVar1 = in_stack_00000130 * 0x10;
  if ((int)uVar1 < 0x20) {
    return CONCAT44(extraout_r1 << (uVar1 & 0xff) |
                    in_stack_00000130 >> (in_stack_00000130 * -0x10 + 0x20 & 0xff),
                    in_stack_00000130 << (uVar1 & 0xff));
  }
  return (ulonglong)(in_stack_00000130 << (uVar1 - 0x20 & 0xff)) << 0x20;
}
#endif

/* 01018388 */
#ifdef NONMATCHING
longlong FUN_01018388(uint param_1,int param_2,uint param_3)
{
  if ((int)param_3 < 0x20) {
    return CONCAT44(param_2 << (param_3 & 0xff) | param_1 >> (0x20 - param_3 & 0xff),
                    param_1 << (param_3 & 0xff));
  }
  return (ulonglong)(param_1 << (param_3 - 0x20 & 0xff)) << 0x20;
}
#endif

/* 010183a8 */
#ifdef NONMATCHING
ulonglong FUN_010183a8(uint param_1,uint param_2,uint param_3)
{
  if ((int)param_3 < 0x20) {
    return CONCAT44(param_2 >> (param_3 & 0xff),
                    param_1 >> (param_3 & 0xff) | param_2 << (0x20 - param_3 & 0xff));
  }
  return (ulonglong)(param_2 >> (param_3 - 0x20 & 0xff));
}
#endif

/* 010183ca */
#ifdef NONMATCHING
undefined4 FUN_010183ca(byte *param_1,byte *param_2,int param_3)
{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  byte *pbVar6;
  uint uVar7;
  
  pbVar6 = param_2 + param_3;
  do {
    uVar7 = (uint)*param_1;
    uVar4 = uVar7 & 7;
    pbVar5 = param_1 + 1;
    if ((*param_1 & 7) == 0) {
      uVar4 = (uint)param_1[1];
      pbVar5 = param_1 + 2;
    }
    param_1 = pbVar5;
    uVar2 = (int)uVar7 >> 4;
    if (uVar2 == 0) {
      uVar2 = (uint)*param_1;
      param_1 = param_1 + 1;
    }
    while (uVar4 = uVar4 - 1, uVar4 != 0) {
      *param_2 = *param_1;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    }
    if ((int)(uVar7 << 0x1c) < 0) {
      bVar1 = *param_1;
      param_1 = param_1 + 1;
      pbVar5 = param_2 + -(uint)bVar1;
      iVar3 = uVar2 + 2;
      while (iVar3 = iVar3 + -1, -1 < iVar3) {
        *param_2 = *pbVar5;
        param_2 = param_2 + 1;
        pbVar5 = pbVar5 + 1;
      }
    }
    else {
      while (uVar2 = uVar2 - 1, -1 < (int)uVar2) {
        *param_2 = 0;
        param_2 = param_2 + 1;
      }
    }
  } while (param_2 < pbVar6);
  return 0;
}
#endif
