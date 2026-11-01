/* btstack_run_loop.c: the btstack_run_loop_* logs */

#include "zero2.h"

/* 01023cfc */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void btstack_run_loop_add_data_source(undefined4 param_1)
{
  FUN_01023d74();
  if (*(int *)(_DAT_00020700 + 4) == 0) {
    FUN_01023330(STR_01023d28);
  }
  else {
    (**(code **)(_DAT_00020700 + 4))(param_1);
  }
  return;
}
#endif

/* 01023d5c */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01023d5c(undefined4 param_1)
{
  FUN_01023d74();
  (**(code **)(_DAT_00020700 + 0x18))(param_1);
  return;
}
#endif

/* 01023d74 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01023d74(void)
{
  if (_DAT_00020700 != 0) {
    return;
  }
  FUN_01023330(STR_01023d90);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}
#endif

/* 01023dd0 */
#ifdef NONMATCHING
void FUN_01023dd0(undefined4 param_1)
{
  FUN_01023b08(&DAT_00020638,param_1);
  return;
}
#endif

/* 01023de4 */
#ifdef NONMATCHING
void btstack_run_loop_add_timer(int *param_1)
{
  int *piVar1;
  
  for (piVar1 = (int *)&DAT_0002063c; *piVar1 != 0; piVar1 = (int *)*piVar1) {
    if ((int *)*piVar1 == param_1) {
      FUN_0102332c(STR_01023e24);
      return;
    }
    if ((uint)param_1[1] < *(uint *)(*piVar1 + 4)) break;
  }
  *param_1 = *piVar1;
  *piVar1 = (int)param_1;
  *(undefined1 *)(param_1 + 5) = 1;
  return;
}
#endif

/* 01023e6c */
void FUN_01023e6c(void)
{
  return;
}

/* 01023e6e */
#ifdef NONMATCHING
void FUN_01023e6e(int param_1,ushort param_2)
{
  *(ushort *)(param_1 + 0xc) = *(ushort *)(param_1 + 0xc) | param_2;
  return;
}
#endif

/* 01023e7c */
#ifdef NONMATCHING
void FUN_01023e7c(void)
{
  do {
    FUN_01023e80();
  } while( true );
}
#endif

/* 01023e7e */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01023e7e(void)
{
  uint uVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = (int *)_DAT_00020638;
  while (uVar1 = _DAT_00020640, piVar2 != (int *)0x0) {
    iVar3 = *piVar2;
    if ((*(byte *)(piVar2 + 3) & 1) != 0) {
      (*(code *)piVar2[2])(piVar2,1);
    }
    piVar2 = (int *)iVar3;
  }
  while ((iVar3 = _DAT_0002063c, _DAT_0002063c != 0 && (*(uint *)(_DAT_0002063c + 4) <= uVar1))) {
    FUN_01024090(_DAT_0002063c);
    (**(code **)(iVar3 + 8))(iVar3);
  }
  FUN_01024bb8();
  if (_DAT_00020644 == 0) {
    FUN_01024bbc();
  }
  else {
    _DAT_00020644 = 0;
    FUN_01024bba();
  }
  return;
}
#endif

/* 01023efc */
undefined ** FUN_01023efc(void)
{
  return &PTR_FUN_01023f24_1_01029158;
}

/* 01023f04 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_01023f04(void)
{
  return _DAT_00020640;
}
#endif

/* 01023f10 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_01023f10(void)
{
  int iVar1;
  
  iVar1 = FUN_01024bc0();
  return _DAT_00020640 * iVar1;
}
#endif

/* 01023f24 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01023f24(void)
{
  _DAT_00020638 = 0;
  _DAT_0002063c = 0;
  _DAT_00020640 = 0;
  FUN_01024bcc();
  FUN_01024bd0(0x1023f9d);
  return;
}
#endif

/* 01023f50 */
#ifdef NONMATCHING
void FUN_01023f50(undefined4 param_1)
{
  FUN_01023b22(&DAT_00020638,param_1);
  return;
}
#endif

/* 01023f64 */
#ifdef NONMATCHING
void FUN_01023f64(int param_1)
{
  *(undefined1 *)(param_1 + 0x14) = 0;
  FUN_01023b22(&DAT_0002063c,param_1);
  return;
}
#endif

/* 01023f7c */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01023f7c(int param_1,undefined4 param_2)
{
  int iVar1;
  
  iVar1 = FUN_01023fb8(param_2);
  *(int *)(param_1 + 4) = _DAT_00020640 + 1 + iVar1;
  return;
}
#endif

/* 01023f9c */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01023f9c(void)
{
  _DAT_00020640 = _DAT_00020640 + 1;
  _DAT_00020644 = 1;
  return;
}
#endif

/* 01023fb8 */
#ifdef NONMATCHING
undefined4 FUN_01023fb8(undefined4 param_1)
{
  undefined4 uVar1;
  
  uVar1 = FUN_01024bc0();
  FUN_01018214(param_1,uVar1);
  return;
}
#endif

/* 01023fcc */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void btstack_run_loop_remove_data_source(undefined4 param_1,undefined4 param_2)
{
  FUN_01023d74();
  if (*(int *)(_DAT_00020700 + 0xc) == 0) {
    FUN_01023330(STR_01023ffc);
  }
  else {
    (**(code **)(_DAT_00020700 + 0xc))(param_1,param_2);
  }
  return;
}
#endif

/* 01024030 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01024030(void)
{
  FUN_01023d74();
  (**(code **)(_DAT_00020700 + 0x20))();
  return;
}
#endif

/* 01024044 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void btstack_run_loop_init(undefined4 *param_1)
{
  if (_DAT_00020700 == (undefined4 *)0x0) {
    _DAT_00020700 = param_1;
    (*(code *)*param_1)();
    return;
  }
  FUN_01023330(STR_0102406c);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}
#endif
