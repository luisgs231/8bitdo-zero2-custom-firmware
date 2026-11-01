/* btstack_memory.c: btstack_memory_pool_free's log */

#include "zero2.h"

/* 01023c90 */
#ifdef NONMATCHING
void btstack_memory_pool_free(undefined4 *param_1,undefined4 *param_2)
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)*param_1;
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      *param_2 = *param_1;
      *param_1 = param_2;
      return;
    }
    if (puVar1 == param_2) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  FUN_0102332e(STR_01023cc0,param_2,param_1);
  return;
}
#endif
