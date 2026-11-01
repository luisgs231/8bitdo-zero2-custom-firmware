/* hci.c: hci_power_control's log */

#include "zero2.h"

/* 01023b4c */
#ifdef NONMATCHING
undefined4 hci_power_control(void)
{
  int iVar1;
  
  if (DAT_000201b7 == '\0') {
    FUN_010249ee();
  }
  FUN_0101f7d2();
  FUN_010202a4();
  FUN_010249c4();
  FUN_0101a540(100);
  FUN_01020de4();
  iVar1 = FUN_0101f098();
  if (iVar1 != 0) {
    FUN_0102332a(STR_01023b90);
    FUN_01024d0c(1);
  }
  idle_limit_set();
  return 0;
}
#endif

/* 01023bb4 */
#ifdef NONMATCHING
void FUN_01023bb4(void)
{
  FUN_01023c5c(0x206e0,0x22064,3,600);
  FUN_01023c5c(0x206e4,0x2276c,4,0x14);
  FUN_01023c5c(0x206e8,0x227bc,4,0x40);
  FUN_01023c5c(0x206ec,0x228bc,3,0x3c);
  FUN_01023c5c(0x206f0,0x22970,1,0x10);
  FUN_01023c5c(0x206f4,0x22980,3,0x28);
  FUN_01023c5c(0x206f8,0x229f8,5,0x1c);
  FUN_01023c5c(0x206fc,0x22a84,3,0xc);
  return;
}
#endif

/* 01023c5c */
#ifdef NONMATCHING
void FUN_01023c5c(undefined4 *param_1,int param_2,int param_3,int param_4)
{
  int local_20;
  int local_1c;
  
  *param_1 = 0;
  local_1c = param_2;
  for (local_20 = 0; local_20 < param_3; local_20 = local_20 + 1) {
    btstack_memory_pool_free(param_1,local_1c);
    local_1c = local_1c + param_4;
  }
  return;
}
#endif
