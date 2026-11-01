/* yc_rom.c: guessed: calls into the chip ROM and its delays */

#include "zero2.h"

/* 01024090 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01024090(undefined4 param_1)
{
  FUN_01023d74();
  (**(code **)(_DAT_00020700 + 0x1c))(param_1);
  return;
}
#endif

/* 010240a8 */
void FUN_010240a8(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 8) = param_2;
  return;
}

/* 010240ac */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_010240ac(undefined4 param_1,undefined4 param_2)
{
  FUN_01023d74();
  (**(code **)(_DAT_00020700 + 0x14))(param_1,param_2);
  return;
}
#endif

/* 010240c8 */
void FUN_010240c8(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 8) = param_2;
  return;
}

/* 010240cc */
#ifdef NONMATCHING
int FUN_010240cc(int param_1,int param_2,int param_3,int param_4,int param_5)
{
  int iVar1;
  
  iVar1 = FUN_01018240((param_4 - param_5) * (param_1 * 1000 - param_3),param_2 - param_3);
  iVar1 = iVar1 + param_5;
  if (iVar1 < 1) {
    iVar1 = -iVar1;
  }
  return iVar1;
}
#endif

/* 01024114 */
#ifdef NONMATCHING
undefined4 FUN_01024114(undefined4 param_1,int param_2)
{
  int iVar1;
  
  for (; 0 < param_2; param_2 = param_2 + -1) {
    for (iVar1 = 0; iVar1 < 8; iVar1 = iVar1 + 1) {
    }
  }
  return;
}
#endif

/* 01024150 */
#ifdef NONMATCHING
void FUN_01024150(void)
{
  FUN_00004480();
  return;
}
#endif

/* 0102415c */
#ifdef NONMATCHING
void rom_delay_a(undefined4 param_1)
{
  FUN_0000425c(param_1);
  return;
}
#endif

/* 0102416c */
#ifdef NONMATCHING
void rom_delay_b(undefined4 param_1)
{
  FUN_00004238(param_1);
  return;
}
#endif

/* 0102417c */
void FUN_0102417c(void)
{
  flash_read(0x107e000,0x21ed4,0x8c);
  return;
}

/* 01024194 */
#ifdef NONMATCHING
void FUN_01024194(void)
{
  if (DAT_00020659 != '\0') {
    DAT_00020659 = '\0';
    flash_erase(0x107e000);
    flash_write(0x107e000,0x21ed4,0x8c);
  }
  return;
}
#endif

/* 010241c4 */
void FUN_010241c4(void)
{
  return;
}

/* 010241c8 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_010241c8(uint param_1)
{
  _DAT_000f856c = _DAT_000f856c & ~(1 << (param_1 & 0xff));
  return;
}
#endif

/* 010241dc */
#ifdef NONMATCHING
void FUN_010241dc(void)
{
  uint uVar1;
  
  uVar1 = FUN_01024eb8(1);
  FUN_01024edc(1,uVar1 & 0xfffdffff);
  return;
}
#endif

/* 010241fa */
#ifdef NONMATCHING
void FUN_010241fa(uint param_1,int param_2,uint param_3)
{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  FUN_01024a7c();
  disableIRQinterrupts();
  uVar4 = 0x20 - (param_1 & 0x1f);
  if (param_3 < uVar4) {
    uVar4 = param_3;
  }
  iVar3 = 0;
  while (param_3 != 0) {
    iVar1 = FUN_010242b8(param_1,uVar4);
    if (iVar1 == 0) {
      thunk_FUN_00004404(param_1,param_1 + uVar4);
      for (uVar2 = 0; uVar2 < uVar4; uVar2 = uVar2 + 1) {
        *(undefined1 *)(param_2 + iVar3) = *(undefined1 *)(param_1 + uVar2);
        iVar3 = iVar3 + 1;
      }
    }
    else {
      FUN_0101828c(param_2 + iVar3,uVar4,0xff);
      iVar3 = iVar3 + uVar4;
    }
    param_1 = param_1 + uVar4;
    param_3 = param_3 - uVar4;
    if (param_3 < 0x20) {
      uVar4 = param_3;
    }
    else {
      uVar4 = 0x20;
    }
  }
  enableIRQinterrupts();
  return;
}
#endif

/* 01024264 */
#ifdef NONMATCHING
void FUN_01024264(uint param_1)
{
  thunk_FUN_00004404(0x1025111,0x1025151);
  FUN_01025110(param_1 & 0xffffff80,param_1 & 0xf);
  return;
}
#endif

/* 01024284 */
#ifdef NONMATCHING
void FUN_01024284(void)
{
  uint uVar1;
  
  for (uVar1 = 0; uVar1 < 0x1000; uVar1 = uVar1 + 1) {
    *(undefined1 *)(uVar1 + 0xc0000) = 0;
    rom_delay_b(1);
    *(undefined1 *)(uVar1 + 0xc4000) = 0;
    rom_delay_b(1);
  }
  return;
}
#endif

/* 010242b8 */
#ifdef NONMATCHING
undefined4 FUN_010242b8(uint param_1,int param_2)
{
  undefined4 uVar1;
  
  FUN_01024a7c();
  disableIRQinterrupts();
  FUN_01024e80();
  uVar1 = FUN_0000513c(param_1 & 0xffffffe0,param_1 + param_2);
  FUN_01024150();
  enableIRQinterrupts();
  return uVar1;
}
#endif
