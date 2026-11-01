/* yc_gpio.c: ..\Librarier\sdk\yc_gpio.c in the GPIO_* asserts */

#include "zero2.h"

/* 0101b690 */
#ifdef NONMATCHING
void GPIO_Config(int param_1,uint param_2,undefined1 param_3,undefined4 param_4)
{
  uint uVar1;
  
  if (2 < param_1) {
    assert_failed(STR_0101b724,0xe,STR_0102781c,param_4,param_4)
    ;
  }
  if (((((param_2 != 1) && (param_2 != 2)) && (param_2 != 4)) &&
      (((param_2 != 8 && (param_2 != 0x10)) &&
       ((param_2 != 0x20 && ((param_2 != 0x40 && (param_2 != 0x80)))))))) &&
     ((param_2 != 0x100 &&
      (((((param_2 != 0x200 && (param_2 != 0x400)) && (param_2 != 0x800)) &&
        ((param_2 != 0x1000 && (param_2 != 0x2000)))) &&
       ((param_2 != 0x4000 && (param_2 != 0x8000)))))))) {
    assert_failed(STR_0101b724,0xf,STR_0102781c);
  }
  for (uVar1 = 0; (int)uVar1 < 0x10; uVar1 = uVar1 + 1) {
    if ((1 << (uVar1 & 0xff) & param_2) != 0) {
      *(undefined1 *)(param_1 * 0x10 + 0xf8700 + uVar1) = param_3;
    }
  }
  return;
}
#endif

/* 0101b750 */
#ifdef NONMATCHING
void FUN_0101b750(void)
{
  int iVar1;
  undefined4 in_r3;
  undefined3 local_8;
  undefined1 uStack_5;
  
  uStack_5 = (undefined1)((uint)in_r3 >> 0x18);
  local_8 = 0x50800;
  GPIO_Init(2,&local_8);
  GPIO_ResetBits(2,0x800);
  local_8 = 0x21000;
  GPIO_Init(0,&local_8);
  local_8 = 0x20400;
  GPIO_Init(1,&local_8);
  local_8 = 0x21000;
  GPIO_Init(1,&local_8);
  local_8 = 0x24000;
  GPIO_Init(1,&local_8);
  local_8 = 0x22000;
  GPIO_Init(1,&local_8);
  local_8 = 0x20010;
  GPIO_Init(2,&local_8);
  local_8 = 0x20800;
  GPIO_Init(1,&local_8);
  local_8 = 0x20002;
  GPIO_Init(0,&local_8);
  local_8 = 0x20001;
  GPIO_Init(0,&local_8);
  local_8 = 0x20400;
  GPIO_Init(0,&local_8);
  local_8 = 0x20200;
  GPIO_Init(0,&local_8);
  local_8 = 0x20002;
  GPIO_Init(2,&local_8);
  local_8 = 0x20020;
  GPIO_Init(0,&local_8);
  local_8 = 0x50008;
  GPIO_Init(0,&local_8);
  GPIO_ResetBits(0,8);
  local_8 = 0x50004;
  GPIO_Init(0,&local_8);
  GPIO_ResetBits(0,4);
  local_8 = 0x50008;
  GPIO_Init(2,&local_8);
  GPIO_SetBits(2,8);
  _local_8 = CONCAT13(uStack_5,0x10040);
  GPIO_Init(1,&local_8);
  iVar1 = FUN_0101fa34();
  if (iVar1 != 0) {
    rom_delay_a(1);
    iVar1 = FUN_0101fa34();
    if (iVar1 != 0) {
      FUN_01020354(0x100000);
    }
  }
  iVar1 = FUN_0101c424();
  if (iVar1 == 0x20220228) {
    FUN_01020354(0x100000);
  }
  return;
}
#endif

/* 0101b8fc */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0101b8fc(void)
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  _DAT_e000e180 = 0x1000;
  for (uVar2 = 0; (int)uVar2 < 3; uVar2 = uVar2 + 1) {
    for (uVar3 = 0; (int)uVar3 < 0x10; uVar3 = uVar3 + 1) {
      if ((((uint)*(ushort *)(uVar2 * 2 + 0x20048) & 1 << (uVar3 & 0xff)) != 0) &&
         (iVar1 = GPIO_ReadInputDataBit(uVar2 & 0xff,1 << (uVar3 & 0xff) & 0xffff),
         iVar1 == (int)(1 << (uVar3 & 0xff) & ~(uint)*(ushort *)(uVar2 * 2 + 0xf8736)) >>
                  (uVar3 & 0xff))) {
        if (((uint)*(ushort *)(uVar2 * 2 + 0x20054) & 1 << (uVar3 & 0xff)) == 0) {
          if (((uint)*(ushort *)(uVar2 * 2 + 0x2004e) & 1 << (uVar3 & 0xff)) ==
              ((uint)*(ushort *)(uVar2 * 2 + 0xf8736) & 1 << (uVar3 & 0xff))) {
            *(ushort *)(uVar2 * 2 + 0x2005a) =
                 *(ushort *)(uVar2 * 2 + 0x2005a) | (ushort)(1 << (uVar3 & 0xff));
            if (uVar2 == 0) {
              FUN_0101b4ec();
            }
            else if (uVar2 == 1) {
              FUN_0101b4f8();
            }
            else if (uVar2 == 2) {
              FUN_010180f2();
            }
          }
          EXTI_ClearITPendingBit(uVar2,1 << (uVar3 & 0xff) & 0xffff);
        }
        else {
          *(ushort *)(uVar2 * 2 + 0x2005a) =
               *(ushort *)(uVar2 * 2 + 0x2005a) | (ushort)(1 << (uVar3 & 0xff));
          if (uVar2 == 0) {
            FUN_0101b4ec();
          }
          else if (uVar2 == 1) {
            FUN_0101b4f8();
          }
          else if (uVar2 == 2) {
            FUN_010180f2();
          }
          EXTI_ClearITPendingBit(uVar2,1 << (uVar3 & 0xff) & 0xffff);
        }
      }
    }
  }
  _DAT_e000e100 = _DAT_e000e100 | 0x1000;
  return;
}
#endif

/* 0101ba34 */
#ifdef NONMATCHING
void GPIO_Init(int param_1,short *param_2)
{
  if (2 < param_1) {
    assert_failed(STR_0101bb4c,0x1c,STR_01027828);
  }
  if (*param_2 == 0) {
    assert_failed(STR_0101bb4c,0x1d,STR_01027828);
  }
  if (((((char)param_2[1] != '\x01') && ((char)param_2[1] != '\x02')) &&
      ((char)param_2[1] != '\x03')) &&
     (((char)param_2[1] != '\x05' && ((char)param_2[1] != '\x04')))) {
    assert_failed(STR_0101bb4c,0x1e,STR_01027828);
  }
                    /* WARNING: Subroutine does not return */
  yc_switch8();
}
#endif

/* 0101ba98 */
#ifdef NONMATCHING
void FUN_0101ba98(void)
{
  uint uVar1;
  ushort *unaff_r5;
  int unaff_r6;
  
  for (uVar1 = 0; (int)uVar1 < 0x10; uVar1 = uVar1 + 1) {
    if (((uint)*unaff_r5 & 1 << (uVar1 & 0xff)) != 0) {
      *(undefined1 *)(unaff_r6 * 0x10 + 0xf8700 + uVar1) = 0;
    }
  }
  return;
}
#endif

/* 0101baba */
#ifdef NONMATCHING
void FUN_0101baba(void)
{
  uint uVar1;
  ushort *unaff_r5;
  int unaff_r6;
  
  for (uVar1 = 0; (int)uVar1 < 0x10; uVar1 = uVar1 + 1) {
    if (((uint)*unaff_r5 & 1 << (uVar1 & 0xff)) != 0) {
      *(undefined1 *)(unaff_r6 * 0x10 + 0xf8700 + uVar1) = 0x40;
    }
  }
  return;
}
#endif

/* 0101badc */
#ifdef NONMATCHING
void FUN_0101badc(void)
{
  uint uVar1;
  ushort *unaff_r5;
  int unaff_r6;
  
  for (uVar1 = 0; (int)uVar1 < 0x10; uVar1 = uVar1 + 1) {
    if (((uint)*unaff_r5 & 1 << (uVar1 & 0xff)) != 0) {
      *(undefined1 *)(unaff_r6 * 0x10 + 0xf8700 + uVar1) = 0x80;
    }
  }
  return;
}
#endif

/* 0101bafe */
#ifdef NONMATCHING
void FUN_0101bafe(void)
{
  uint uVar1;
  ushort *unaff_r5;
  int unaff_r6;
  
  for (uVar1 = 0; (int)uVar1 < 0x10; uVar1 = uVar1 + 1) {
    if (((uint)*unaff_r5 & 1 << (uVar1 & 0xff)) != 0) {
      *(undefined1 *)(unaff_r6 * 0x10 + 0xf8700 + uVar1) = 0xc0;
    }
  }
  return;
}
#endif

/* 0101bb20 */
#ifdef NONMATCHING
void FUN_0101bb20(void)
{
  uint uVar1;
  ushort *unaff_r5;
  int unaff_r6;
  
  for (uVar1 = 0; (int)uVar1 < 0x10; uVar1 = uVar1 + 1) {
    if (((uint)*unaff_r5 & 1 << (uVar1 & 0xff)) != 0) {
      *(undefined1 *)(unaff_r6 * 0x10 + 0xf8700 + uVar1) = 0x3e;
    }
  }
  return;
}
#endif

/* 0101bb42 */
#ifdef NONMATCHING
void FUN_0101bb42(void)
{
  return;
}
#endif

/* 0101bb78 */
#ifdef NONMATCHING
undefined2 GPIO_ReadInputData(int param_1)
{
  if (2 < param_1) {
    assert_failed(STR_0101bb98,0x6a,STR_01027841);
  }
  return *(undefined2 *)(param_1 * 2 + 0xf873c);
}
#endif

/* 0101bbc4 */
#ifdef NONMATCHING
bool GPIO_ReadInputDataBit(int param_1,uint param_2)
{
  if (2 < param_1) {
    assert_failed(STR_0101bc50,0x71,STR_01027854);
  }
  if (((((param_2 != 1) && (param_2 != 2)) && (param_2 != 4)) &&
      (((param_2 != 8 && (param_2 != 0x10)) &&
       ((param_2 != 0x20 && ((param_2 != 0x40 && (param_2 != 0x80)))))))) &&
     ((param_2 != 0x100 &&
      (((((param_2 != 0x200 && (param_2 != 0x400)) && (param_2 != 0x800)) &&
        ((param_2 != 0x1000 && (param_2 != 0x2000)))) &&
       ((param_2 != 0x4000 && (param_2 != 0x8000)))))))) {
    assert_failed(STR_0101bc50,0x72,STR_01027854);
  }
  return (*(ushort *)(param_1 * 2 + 0xf873c) & param_2) != 0;
}
#endif

/* 0101bc7c */
#ifdef NONMATCHING
void GPIO_ResetBits(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)
{
  uint uVar1;
  
  if (2 < param_1) {
    assert_failed(STR_0101bd1c,0x96,STR_01027895,param_4,
                  param_4);
  }
  if (((((param_2 != 1) && (param_2 != 2)) && (param_2 != 4)) &&
      (((param_2 != 8 && (param_2 != 0x10)) &&
       ((param_2 != 0x20 && ((param_2 != 0x40 && (param_2 != 0x80)))))))) &&
     ((param_2 != 0x100 &&
      (((((param_2 != 0x200 && (param_2 != 0x400)) && (param_2 != 0x800)) &&
        ((param_2 != 0x1000 && (param_2 != 0x2000)))) &&
       ((param_2 != 0x4000 && (param_2 != 0x8000)))))))) {
    assert_failed(STR_0101bd1c,0x97,STR_01027895);
  }
  for (uVar1 = 0; (int)uVar1 < 0x10; uVar1 = uVar1 + 1) {
    if ((1 << (uVar1 & 0xff) & param_2) != 0) {
      *(byte *)(param_1 * 0x10 + 0xf8700 + uVar1) =
           (*(byte *)(param_1 * 0x10 + 0xf8700 + uVar1) | 0x3f) & 0xfe;
    }
  }
  return;
}
#endif

/* 0101bd48 */
#ifdef NONMATCHING
void GPIO_SetBits(int param_1,uint param_2)
{
  uint uVar1;
  
  if (2 < param_1) {
    assert_failed(STR_0101bde8,0xaa,STR_010278a4);
  }
  if (((((param_2 != 1) && (param_2 != 2)) && (param_2 != 4)) &&
      (((param_2 != 8 && (param_2 != 0x10)) &&
       ((param_2 != 0x20 && ((param_2 != 0x40 && (param_2 != 0x80)))))))) &&
     ((param_2 != 0x100 &&
      (((((param_2 != 0x200 && (param_2 != 0x400)) && (param_2 != 0x800)) &&
        ((param_2 != 0x1000 && (param_2 != 0x2000)))) &&
       ((param_2 != 0x4000 && (param_2 != 0x8000)))))))) {
    assert_failed(STR_0101bde8,0xab,STR_010278a4);
  }
  for (uVar1 = 0; (int)uVar1 < 0x10; uVar1 = uVar1 + 1) {
    if ((1 << (uVar1 & 0xff) & param_2) != 0) {
      *(byte *)(param_1 * 0x10 + 0xf8700 + uVar1) =
           *(byte *)(param_1 * 0x10 + 0xf8700 + uVar1) | 0x3f;
    }
  }
  return;
}
#endif
