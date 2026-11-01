/* led.c: guessed: the LED pattern chooser and engine */

#include "zero2.h"

/* 010242f0 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void led_choose(void)
{
  int iVar1;
  
  DAT_000206c1 = 0;
  DAT_000206be = 0;
  DAT_000206bf = 0;
  _DAT_000206cc = 0;
  iVar1 = usb_charging();
  if (iVar1 == 0) {
    if (DAT_00020182 == '\x02') {
      if ((DAT_000206b1 == '\0') || (DAT_000206b2 != '\0')) {
        if (DAT_000206b3 == '\0') {
          DAT_000206bc = '\0';
          DAT_000206c0 = '\0';
          DAT_000206bd = '\0';
          if (DAT_00020158 == '\x01') {
            _DAT_000206c4 = 2;
          }
          else {
            _DAT_000206c4 = 4;
          }
        }
        else {
          DAT_000206bc = '\x1e';
          DAT_000206c0 = '\0';
          DAT_000206bd = '\x02';
          _DAT_000206c4 = 1;
        }
      }
      else {
        DAT_000206bc = DAT_000206b2;
        DAT_000206c0 = DAT_000206b2;
        DAT_000206bd = DAT_000206b2;
        _DAT_000206c4 = 1;
      }
    }
    else {
      if (DAT_000206b1 != '\0') {
        DAT_000206bc = '\0';
        DAT_000206c0 = '\0';
        DAT_000206bd = '\0';
        if (DAT_000206b2 == '\0') {
          _DAT_000206c4 = 1;
          goto LAB_01024516;
        }
        if (DAT_00020181 == '\x03') {
          _DAT_000206c4 = 4;
          goto LAB_01024516;
        }
      }
      if (DAT_000201b4 == '\x03') {
        DAT_000206bd = '\x02';
      }
      else if (DAT_000201b4 == '\x01') {
        DAT_000206bd = '\x04';
      }
      else if (DAT_000201b4 == '\x02') {
        DAT_000206bd = '\x06';
      }
      else if (DAT_000201b4 == '\0') {
        DAT_000206bd = '\b';
      }
      else if (DAT_000201b4 == '\x04') {
        DAT_000206bd = '\n';
      }
      else {
        DAT_000206bd = '\x02';
      }
      if (DAT_000201b4 == '\x03') {
        DAT_000206bc = '\x15';
      }
      else if (DAT_000201b4 == '\x04') {
        DAT_000206bc = '\x10';
      }
      else {
        DAT_000206bc = '\x10';
      }
      DAT_000206c0 = 'e';
      if (DAT_000206b3 == '\0') {
        if (DAT_00020158 == '\x01') {
          _DAT_000206c4 = 2;
        }
        else {
          _DAT_000206c4 = 4;
        }
      }
      else {
        _DAT_000206c4 = 1;
      }
    }
  }
  else {
    DAT_000206bc = '\n';
    DAT_000206c0 = '\0';
    DAT_000206bd = '\x02';
    _DAT_00020194 = &DAT_00001770;
    if ((DAT_000206b1 == '\0') || (DAT_000206b2 != '\0')) {
      if (DAT_000206b3 == '\0') {
        _DAT_000206c4 = 4;
      }
      else {
        _DAT_000206c4 = 1;
      }
    }
    else {
      _DAT_000206c4 = 1;
    }
  }
LAB_01024516:
  _DAT_000206cc = _DAT_000206c4;
  if (_DAT_000206c8 != _DAT_000206c4) {
    _DAT_000206c8 = _DAT_000206c4;
    led_set(7,0);
  }
  return;
}
#endif

/* 01024584 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void led_pattern(void)
{
  int iVar1;
  uint uVar2;
  
  iVar1 = GPIO_ReadInputDataBit(1,0x40);
  if (iVar1 == 0) {
    if (_DAT_000206b6 != 0) {
      _DAT_000206b6 = _DAT_000206b6 - 1;
    }
  }
  else if (_DAT_000206b6 < 100) {
    _DAT_000206b6 = _DAT_000206b6 + 1;
  }
  DAT_000206b1 = 0x31 < _DAT_000206b6;
  if (((((DAT_000206b0 != '\0') || (DAT_000206d9 != DAT_00020182)) || (DAT_000206de != DAT_00020181)
       ) || ((uVar2 = usb_charging(), uVar2 != DAT_000206da || (DAT_000206db != DAT_000206b1)))) ||
     ((DAT_000206dc != DAT_000206b3 || (DAT_000206dd != DAT_000206b2)))) {
    DAT_000206d9 = DAT_00020182;
    DAT_000206de = DAT_00020181;
    DAT_000206da = usb_charging();
    DAT_000206db = DAT_000206b1;
    DAT_000206dc = DAT_000206b3;
    DAT_000206dd = DAT_000206b2;
    DAT_000206b0 = '\0';
    led_choose();
  }
  if (DAT_000206bc == 0) {
    if (DAT_000206c0 == 0) {
      led_set(_DAT_000206c4 & 0xffff,_DAT_000206c4 & 0xffff);
    }
    else {
      led_set(_DAT_000206c4 & 0xffff,0);
      DAT_000206c1 = DAT_000206c1 + 1;
      if (DAT_000206c0 <= DAT_000206c1) {
        led_choose();
      }
    }
  }
  else if (DAT_000206bf < DAT_000206bd) {
    if (DAT_000206be == 0) {
      led_set(_DAT_000206c4 & 0xffff,_DAT_000206cc & 0xffff);
      _DAT_000206cc = _DAT_000206cc ^ _DAT_000206c4;
    }
    DAT_000206be = DAT_000206be + 1;
    if (DAT_000206bc <= DAT_000206be) {
      DAT_000206be = 0;
      DAT_000206bf = DAT_000206bf + 1;
      if ((DAT_000206bf == DAT_000206bd) && (DAT_000206c0 == 0)) {
        led_choose();
      }
    }
  }
  else {
    if (DAT_000206c1 == 0) {
      led_set(_DAT_000206c4 & 0xffff,0);
    }
    DAT_000206c1 = DAT_000206c1 + 1;
    if (DAT_000206c0 <= DAT_000206c1) {
      led_choose();
    }
  }
  return;
}
#endif

/* 010248e0 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_010248e0(int param_1)
{
  if (_DAT_000206b8 != (code *)0x0) {
    (*_DAT_000206b8)();
  }
  FUN_010249ce(param_1,*(undefined4 *)(param_1 + 0x10));
  return;
}
#endif
