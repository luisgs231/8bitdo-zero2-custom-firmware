/* yc_timer.c: ..\Librarier\sdk\yc_timer.c in TIM_Cmd's assert */

#include "zero2.h"

/* 01020d38 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TIM_Cmd(uint param_1,int param_2)
{
  if (8 < (int)param_1) {
    assert_failed(STR_01020d9c,0x21,STR_01027904);
  }
  if (param_2 == 1) {
    if ((int)param_1 < 8) {
      _DAT_000f0c48 = _DAT_000f0c48 | 1 << ((param_1 & 0x3f) << 2);
    }
    else {
      _DAT_000f0c4c = _DAT_000f0c4c | 1;
    }
  }
  else if ((int)param_1 < 8) {
    _DAT_000f0c48 = _DAT_000f0c48 & ~(1 << ((param_1 & 0x3f) << 2));
  }
  else {
    _DAT_000f0c4c = _DAT_000f0c4c & 0xfffffffe;
  }
  return;
}
#endif
