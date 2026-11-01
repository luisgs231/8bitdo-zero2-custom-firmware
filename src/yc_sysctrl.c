/* yc_sysctrl.c: ..\Librarier\sdk\yc_sysctrl.c in the SYSCTRL_* asserts */

#include "zero2.h"

/* 01020118 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SYSCTRL_AHBPeriphClockCmd(uint param_1,int param_2)
{
  if ((param_1 & 0x7fffe) == 0) {
    assert_failed(STR_01020154,5,STR_01027963);
  }
  if (param_2 == 0) {
    _DAT_000f856c = _DAT_000f856c | param_1;
  }
  else {
    _DAT_000f856c = _DAT_000f856c & ~param_1;
  }
  return;
}
#endif

/* 01020184 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SYSCTRL_HCLKConfig(uint param_1)
{
  if ((((param_1 != 0) && (param_1 != 2)) && (param_1 != 6)) && (param_1 != 0xe)) {
    assert_failed(STR_010201d8,0x1f,STR_01027990);
  }
  disableIRQinterrupts();
  if (param_1 == 0) {
    FUN_00004404(0x101c809,0x101c849);
    FUN_0101c808(0);
  }
  else {
    _DAT_000f8560 = _DAT_000f8560 & 0xfffffff0 | param_1;
  }
  enableIRQinterrupts();
  return;
}
#endif

/* 01020210 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01020210(void)
{
  _DAT_0002003c = _DAT_0002003c + 1;
  if (_DAT_0002003c == 0x7fffffff) {
    _DAT_0002003c = 0;
  }
  FUN_0101a7a8();
  FUN_0101ee40();
  _DAT_00020008 = _DAT_00020008 + 10;
  return;
}
#endif

/* 0102024c */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0102024c(int param_1,int param_2)
{
  int iVar1;
  
  if (_DAT_00020f94 + param_2 <= _DAT_00020f90) {
    for (iVar1 = 0; iVar1 < param_2; iVar1 = iVar1 + 1) {
      *(undefined1 *)(_DAT_00020f8c + _DAT_00020f9c) = *(undefined1 *)(param_1 + iVar1);
      _DAT_00020f94 = _DAT_00020f94 + 1;
      _DAT_00020f9c = _DAT_00020f9c + 1;
      if (_DAT_00020f90 <= _DAT_00020f9c) {
        _DAT_00020f9c = 0;
      }
    }
  }
  return;
}
#endif

/* 010202a0 */
void FUN_010202a0(void)
{
  return;
}

/* 010202a4 */
#ifdef NONMATCHING
void FUN_010202a4(void)
{
  FUN_010240c8(0x219dc,0x101be15);
  FUN_010240ac(0x219dc,9);
  FUN_01023d5c(0x219dc);
  return;
}
#endif
