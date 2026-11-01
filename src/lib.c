/* lib.c: guessed: armcc library routines at the end of the code */

#include "zero2.h"

/* 010251b0 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_010251b0(void)
{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined1 auStack_ac [4];
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  byte local_9c [32];
  undefined4 local_7c;
  undefined4 local_78;
  int local_74;
  uint local_70;
  undefined1 auStack_6c [8];
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined1 local_54;
  undefined1 local_53;
  undefined1 local_52;
  undefined1 local_51;
  char local_50 [25];
  undefined1 local_37;
  
  if (_DAT_00020708 == 0) {
    if ((DAT_00020785 & 0x80) == 0) {
      return 0;
    }
    DAT_00020785 = DAT_00020785 + 1;
    if ((DAT_00020785 & 0x7f) < 0x71) {
      return 0;
    }
    _DAT_00020708 = 0x400000;
  }
  iVar3 = usb_powered();
  if ((iVar3 == 0) || (DAT_000201ea != '\0')) {
    local_74 = 0;
    memzero(&local_64,0x50);
    cVar1 = DAT_00020710;
    if ((_DAT_00020708 & 1) == 0) {
      if ((_DAT_00020708 & 2) == 0) {
        if ((_DAT_00020708 & 4) == 0) {
          if ((_DAT_00020708 & 8) == 0) {
            if ((_DAT_00020708 & 0x10) == 0) {
              if ((_DAT_00020708 & 0x20) == 0) {
                if ((_DAT_00020708 & 0x40) == 0) {
                  if ((_DAT_00020708 & 0x80) == 0) {
                    if ((_DAT_00020708 & 0x100) == 0) {
                      if ((_DAT_00020708 & 0x200) == 0) {
                        if ((_DAT_00020708 & 0x400) == 0) {
                          if ((_DAT_00020708 & 0x800) == 0) {
                            if ((_DAT_00020708 & 0x1000) == 0) {
                              if ((_DAT_00020708 & 0x2000) == 0) {
                                if ((_DAT_00020708 & 0x4000) == 0) {
                                  if ((_DAT_00020708 & 0x8000) == 0) {
                                    if ((_DAT_00020708 & 0x10000) == 0) {
                                      if ((_DAT_00020708 & 0x20000) == 0) {
                                        if ((_DAT_00020708 & 0x200000) == 0) {
                                          if ((_DAT_00020708 & 0x400000) == 0) {
                                            if ((_DAT_00020708 & 0x800000) == 0) {
                                              if ((_DAT_00020708 & 0x1000000) != 0) {
                                                _DAT_00020708 = _DAT_00020708 & 0xfeffffff;
                                                local_64._0_2_ = CONCAT11(0x81,(undefined1)local_64)
                                                ;
                                                local_64._0_3_ = CONCAT12(2,(undefined2)local_64);
                                                local_74 = 1;
                                              }
                                            }
                                            else {
                                              _DAT_00020708 = _DAT_00020708 & 0xff7fffff;
                                              local_64._0_2_ = CONCAT11(0x81,(undefined1)local_64);
                                              local_64._0_3_ = CONCAT12(3,(undefined2)local_64);
                                              local_74 = 1;
                                            }
                                          }
                                          else {
                                            _DAT_00020708 = _DAT_00020708 & 0xffbfffff;
                                            local_64._0_2_ = CONCAT11(0x81,(undefined1)local_64);
                                            local_64._0_3_ = CONCAT12(2,(undefined2)local_64);
                                            local_74 = 1;
                                            DAT_00020785 = 0;
                                          }
                                        }
                                        else {
                                          _DAT_00020708 = _DAT_00020708 & 0xffdfffff;
                                          memcpy(&local_64,&DAT_01029550,0xb);
                                          FUN_010206ca(auStack_6c,0);
                                          memcpy((int)&local_60 + 1,auStack_6c,6);
                                          local_74 = 1;
                                        }
                                      }
                                      else {
                                        _DAT_00020708 = _DAT_00020708 & 0xfffdffff;
                                        memzero(&local_64,0x50);
                                        iVar3 = FUN_0101c0f0((int)&local_64 + 1);
                                        if (0 < iVar3) {
                                          auStack_6c[iVar3 + 9] = 0x22;
                                          FUN_010241fa(0x1017040,auStack_ac,4);
                                          memcpy(auStack_6c + iVar3 + 10,auStack_ac,4);
                                          auStack_6c[iVar3 + 0xe] = 0x3f;
                                          auStack_6c[iVar3 + 0xf] = 0;
                                        }
                                        local_74 = 1;
                                      }
                                    }
                                    else {
                                      _DAT_00020708 = _DAT_00020708 & 0xfffeffff;
                                      local_74 = 0;
                                    }
                                  }
                                  else {
                                    _DAT_00020708 = _DAT_00020708 & 0xffff7fff;
                                    local_64._0_2_ = CONCAT11(0x81,(undefined1)local_64);
                                    local_64._0_3_ = CONCAT12(2,(undefined2)local_64);
                                    local_74 = 1;
                                  }
                                }
                                else {
                                  _DAT_00020708 = _DAT_00020708 & 0xffffbfff;
                                  if (DAT_00020777 != '0') {
                                    DAT_00020785 = 0x80;
                                    FUN_0102059c();
                                    memcpy(&local_64,&DAT_01029550,0xb);
                                    FUN_010206ca(auStack_6c,0);
                                    memcpy((int)&local_60 + 1,auStack_6c,6);
                                  }
                                  local_74 = 1;
                                }
                              }
                              else {
                                _DAT_00020708 = _DAT_00020708 & 0xffffdfff;
                                iVar3 = FUN_01024c60(DAT_000201b4);
                                if (iVar3 == 0) {
                                  local_a8 = 0;
                                  local_a4 = 0;
                                }
                                else {
                                  uVar4 = FUN_01024c60(DAT_000201b4);
                                  memcpy(&local_a8,uVar4,6);
                                }
                                iVar3 = FUN_010182b0(&local_a8,0x20179,6);
                                if (iVar3 == 0) {
                                  memcpy(&local_64,&DAT_01029542,0xe);
                                  local_58._0_3_ = CONCAT12(0x81,(undefined2)local_58);
                                  local_58 = CONCAT13(1,(undefined3)local_58);
                                  local_54 = 3;
                                  local_64._0_3_ =
                                       CONCAT12(DAT_000217b2 + '\x02',(undefined2)local_64);
                                  local_74 = 1;
                                }
                                else {
                                  memcpy(&local_64,&DAT_01029542,0xe);
                                  local_58._0_3_ = CONCAT12(0x81,(undefined2)local_58);
                                  local_58 = CONCAT13(1,(undefined3)local_58);
                                  local_54 = 1;
                                  FUN_010206ca(auStack_6c,0);
                                  memcpy(&local_53,auStack_6c,6);
                                  local_50[3] = 0;
                                  local_50[4] = 0x25;
                                  local_50[5] = 8;
                                  FUN_010182ca(local_50 + 6,"Pro Controller");
                                  local_37 = 0x68;
                                  local_64._0_3_ =
                                       CONCAT12(DAT_000217b2 + '\x02',(undefined2)local_64);
                                  local_74 = 1;
                                }
                              }
                            }
                            else {
                              _DAT_00020708 = _DAT_00020708 & 0xffffefff;
                              memcpy(&local_64,&DAT_01029542,0xe);
                              local_58._0_3_ = CONCAT12(0x81,(undefined2)local_58);
                              local_58 = CONCAT13(1,(undefined3)local_58);
                              local_54 = 3;
                              local_64._0_3_ = CONCAT12(DAT_000217b2 + '\x02',(undefined2)local_64);
                              local_74 = 1;
                            }
                          }
                          else {
                            _DAT_00020708 = _DAT_00020708 & 0xfffff7ff;
                            memcpy(&local_64,&DAT_01029542,0xe);
                            local_58._0_3_ = CONCAT12(0x81,(undefined2)local_58);
                            local_58 = CONCAT13(1,(undefined3)local_58);
                            local_54 = 2;
                            local_a0 = FUN_01024994();
                            for (uVar5 = 0; uVar5 < 0x10; uVar5 = uVar5 + 1 & 0xff) {
                              local_9c[uVar5] = (&DAT_0102955b)[uVar5] ^ (byte)local_a0;
                            }
                            FUN_01024a08(0x20179,local_9c,0);
                            for (uVar5 = 0; uVar5 < 0x10; uVar5 = uVar5 + 1 & 0xff) {
                              local_9c[uVar5 + 0x10] = local_9c[0xf - uVar5] ^ 0xaa;
                            }
                            memcpy(&local_53,local_9c + 0x10,0x10);
                            local_64._0_3_ = CONCAT12(DAT_000217b2 + '\x02',(undefined2)local_64);
                            local_74 = 1;
                          }
                        }
                        else {
                          _DAT_00020708 = _DAT_00020708 & 0xfffffbff;
                          memcpy(&local_64,&DAT_01029542,0xe);
                          local_58._0_3_ = CONCAT12(0x81,(undefined2)local_58);
                          local_58 = CONCAT13(1,(undefined3)local_58);
                          local_54 = 1;
                          FUN_010206ca(auStack_6c,0);
                          memcpy(&local_53,auStack_6c,6);
                          local_50[3] = 0;
                          local_50[4] = 0x25;
                          local_50[5] = 8;
                          FUN_010182ca(local_50 + 6,"Pro Controller");
                          local_37 = 0x68;
                          local_64._0_3_ = CONCAT12(DAT_000217b2 + '\x02',(undefined2)local_64);
                          local_74 = 1;
                        }
                      }
                      else {
                        _DAT_00020708 = _DAT_00020708 & 0xfffffdff;
                        memcpy(&local_64,&DAT_01029500,0x32);
                        local_64._0_3_ = CONCAT12(DAT_000217b2 + '\x02',(undefined2)local_64);
                        memcpy((int)&local_64 + 3,0x217b3,10);
                        local_74 = 1;
                      }
                    }
                    else {
                      _DAT_00020708 = _DAT_00020708 & 0xfffffeff;
                      local_5c = 0x479f7b67;
                      local_60 = 0xf0000000;
                      local_58 = 0x22800075;
                      local_64._0_3_ = CONCAT12(DAT_000217b2 + '\x02',0x21a1);
                      local_64 = CONCAT13(0x80,(undefined3)local_64);
                      memcpy((int)&local_64 + 3,0x217b3,10);
                      local_74 = 1;
                    }
                  }
                  else {
                    _DAT_00020708 = _DAT_00020708 & 0xffffff7f;
                    local_5c = 0x17a67847;
                    local_60 = 0xe2000000;
                    local_64 = 0x40b921a1;
                    local_58 = 0x30800a75;
                    usb_powered();
                    local_74 = 1;
                  }
                }
                else {
                  _DAT_00020708 = _DAT_00020708 & 0xffffffbf;
                  local_5c = 0x7aa78e7;
                  local_60 = 0xdd000000;
                  local_64 = 0x403821a1;
                  local_58 = 0x40800b75;
                  DAT_000201f7 = (DAT_00020717 & 0x80) != 0;
                  local_74 = 1;
                }
              }
              else {
                _DAT_00020708 = _DAT_00020708 & 0xffffffdf;
                local_5c = 0xf7aa7907;
                local_60 = 0xee000000;
                local_64 = 0x40e721a1;
                local_58 = 0x48800974;
                local_74 = 1;
              }
            }
            else {
              _DAT_00020708 = _DAT_00020708 & 0xffffffef;
              if (DAT_00020712 == '`') {
                local_70 = (uint)DAT_0002070c;
                memcpy(&local_64,&DAT_01029532,0x10);
                local_54 = (undefined1)local_70;
                local_53 = 0x60;
                local_52 = 0;
                local_51 = 0;
                local_50[0] = cVar1;
                if ((local_70 == 0xe0) && (cVar1 == '\x06')) {
                  local_50[1] = 200;
                  local_50[2] = 0x2d;
                  local_7c = FUN_0101c430(1);
                  local_50[3] = (char)local_7c;
                  local_50[4] = (char)((uint)local_7c >> 8);
                  local_50[5] = 0;
                  local_50[6] = 1;
                }
                else {
                  memcpy(local_50 + 1,&UNK_0102956b + local_70,cVar1);
                }
              }
              else if (DAT_00020712 == -0x80) {
                local_70 = (uint)DAT_0002070c;
                memcpy(&local_64,&DAT_01029532,0x10);
                local_54 = (undefined1)local_70;
                local_53 = 0x80;
                local_52 = 0;
                local_51 = 0;
                local_50[0] = cVar1;
                FUN_0101828c(local_50 + 1,cVar1,0xff);
              }
              local_74 = 1;
            }
          }
          else {
            _DAT_00020708 = _DAT_00020708 & 0xfffffff7;
            memcpy(&local_64,&DAT_010294a8,0x18);
            local_74 = 1;
          }
        }
        else {
          _DAT_00020708 = _DAT_00020708 & 0xfffffffb;
          local_5c = 0x27c07967;
          local_60 = 0xdf000000;
          local_64 = 0x408f21a1;
          local_58 = 0x3800975;
          DAT_00020777 = DAT_00020714;
          if (DAT_00020714 == '1') {
            memzero(0x217b0,0x32);
            memcpy(0x217b0,&DAT_0102966b,0x32);
            DAT_00020714 = '0';
            DAT_00020777 = '0';
          }
          else {
            memzero(0x217b0,0x32);
            memcpy(0x217b0,&DAT_0102966b,0x32);
          }
          local_74 = 1;
        }
      }
      else {
        _DAT_00020708 = _DAT_00020708 & 0xfffffffd;
        local_5c = 0x7c07957;
        local_60 = 0xde000000;
        local_64 = 0x40c421a1;
        local_58 = 0x8800a75;
        local_74 = 1;
      }
    }
    else {
      _DAT_00020708 = _DAT_00020708 & 0xfffffffe;
      FUN_010206ca(auStack_6c,1);
      memcpy(&local_64,&DAT_0102946c,0x1c);
      memcpy(local_50,auStack_6c,6);
      local_74 = 1;
    }
    if (local_74 != 0) {
      if (local_64._1_1_ == '!') {
        uVar2 = FUN_01024980();
        local_64._0_3_ = CONCAT12(uVar2,(undefined2)local_64);
      }
      iVar3 = usb_powered();
      if (iVar3 == 0) {
        if (DAT_00020182 == '\x02') {
          local_78 = FUN_01024a54();
          protocol_report_byte((int)&local_64 + 3);
          FUN_01024e8c(local_78,&local_64,0x32);
        }
      }
      else {
        DAT_000201ea = '\0';
        FUN_01023108((int)&local_64 + 1,0x40);
      }
    }
  }
  else {
    local_74 = 0;
  }
  return local_74;
}
#endif

/* 01025668 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int thunk_FUN_0102566a(void)
{
  undefined4 uVar1;
  int iVar2;
  undefined1 uStack00000004;
  undefined4 uStack00000008;
  undefined4 in_stack_0000000c;
  undefined4 in_stack_00000038;
  int in_stack_0000003c;
  undefined1 uStack00000044;
  undefined4 uStack0000004c;
  undefined1 uStack00000051;
  undefined1 uStack00000052;
  undefined1 uStack00000053;
  undefined4 in_stack_00000058;
  undefined1 in_stack_0000005c;
  undefined1 uStack0000005d;
  undefined4 in_stack_00000060;
  undefined4 uStack00000064;
  undefined4 in_stack_00000078;
  
  if ((_DAT_00020708 & 0x1000) == 0) {
    if ((_DAT_00020708 & 0x2000) == 0) {
      if ((_DAT_00020708 & 0x4000) == 0) {
        if ((_DAT_00020708 & 0x8000) == 0) {
          if ((_DAT_00020708 & 0x10000) == 0) {
            if ((_DAT_00020708 & 0x20000) == 0) {
              if ((_DAT_00020708 & 0x200000) == 0) {
                if ((_DAT_00020708 & 0x400000) == 0) {
                  if ((_DAT_00020708 & 0x800000) == 0) {
                    if ((_DAT_00020708 & 0x1000000) != 0) {
                      _DAT_00020708 = _DAT_00020708 & 0xfeffffff;
                      uStack0000004c._1_1_ = -0x7f;
                      uStack0000004c._2_1_ = '\x02';
                      in_stack_0000003c = 1;
                    }
                  }
                  else {
                    _DAT_00020708 = _DAT_00020708 & 0xff7fffff;
                    uStack0000004c._1_1_ = -0x7f;
                    uStack0000004c._2_1_ = '\x03';
                    in_stack_0000003c = 1;
                  }
                }
                else {
                  _DAT_00020708 = _DAT_00020708 & 0xffbfffff;
                  uStack0000004c._1_1_ = -0x7f;
                  uStack0000004c._2_1_ = '\x02';
                  in_stack_0000003c = 1;
                  DAT_00020785 = 0;
                }
              }
              else {
                _DAT_00020708 = _DAT_00020708 & 0xffdfffff;
                memcpy(&uStack0000004c,&DAT_01029550,0xb);
                FUN_010206ca(&uStack00000044,0);
                memcpy(&uStack00000051,&uStack00000044,6);
                in_stack_0000003c = 1;
              }
            }
            else {
              _DAT_00020708 = _DAT_00020708 & 0xfffdffff;
              memzero(&uStack0000004c,0x50);
              iVar2 = FUN_0101c0f0((int)&uStack0000004c + 1);
              if (0 < iVar2) {
                *(undefined1 *)((int)&uStack0000004c + iVar2 + 1) = 0x22;
                FUN_010241fa(0x1017040,&uStack00000004,4);
                memcpy((int)&uStack0000004c + iVar2 + 2,&uStack00000004,4);
                (&uStack00000052)[iVar2] = 0x3f;
                (&uStack00000053)[iVar2] = 0;
              }
              in_stack_0000003c = 1;
            }
          }
          else {
            _DAT_00020708 = _DAT_00020708 & 0xfffeffff;
            in_stack_0000003c = 0;
          }
        }
        else {
          _DAT_00020708 = _DAT_00020708 & 0xffff7fff;
          uStack0000004c._1_1_ = -0x7f;
          uStack0000004c._2_1_ = '\x02';
          in_stack_0000003c = 1;
        }
      }
      else {
        _DAT_00020708 = _DAT_00020708 & 0xffffbfff;
        if (DAT_00020777 != '0') {
          DAT_00020785 = 0x80;
          FUN_0102059c();
          memcpy(&uStack0000004c,&DAT_01029550,0xb);
          FUN_010206ca(&uStack00000044,0);
          memcpy(&uStack00000051,&uStack00000044,6);
        }
        in_stack_0000003c = 1;
      }
    }
    else {
      _DAT_00020708 = _DAT_00020708 & 0xffffdfff;
      iVar2 = FUN_01024c60(DAT_000201b4);
      if (iVar2 == 0) {
        uStack00000008 = 0;
        in_stack_0000000c = 0;
      }
      else {
        uVar1 = FUN_01024c60(DAT_000201b4);
        memcpy(&uStack00000008,uVar1,6);
      }
      iVar2 = FUN_010182b0(&uStack00000008,0x20179,6);
      if (iVar2 == 0) {
        memcpy(&uStack0000004c,&DAT_01029542,0xe);
        in_stack_00000058._2_1_ = 0x81;
        in_stack_00000058._3_1_ = 1;
        in_stack_0000005c = 3;
        uStack0000004c._2_1_ = DAT_000217b2 + '\x02';
        in_stack_0000003c = 1;
      }
      else {
        memcpy(&uStack0000004c,&DAT_01029542,0xe);
        in_stack_00000058._2_1_ = 0x81;
        in_stack_00000058._3_1_ = 1;
        in_stack_0000005c = 1;
        FUN_010206ca(&uStack00000044,0);
        memcpy(&uStack0000005d,&uStack00000044,6);
        in_stack_00000060._3_1_ = 0;
        uStack00000064._0_1_ = 0x25;
        uStack00000064._1_1_ = 8;
        FUN_010182ca((int)&uStack00000064 + 2,"Pro Controller");
        in_stack_00000078._1_1_ = 0x68;
        uStack0000004c._2_1_ = DAT_000217b2 + '\x02';
        in_stack_0000003c = 1;
      }
    }
  }
  else {
    _DAT_00020708 = _DAT_00020708 & 0xffffefff;
    memcpy(&uStack0000004c,&DAT_01029542,0xe);
    in_stack_00000058._2_1_ = 0x81;
    in_stack_00000058._3_1_ = 1;
    in_stack_0000005c = 3;
    uStack0000004c._2_1_ = DAT_000217b2 + '\x02';
    in_stack_0000003c = 1;
  }
  if (in_stack_0000003c != 0) {
    if (uStack0000004c._1_1_ == '!') {
      uStack0000004c._2_1_ = FUN_01024980();
    }
    iVar2 = usb_powered();
    if (iVar2 == 0) {
      if (DAT_00020182 == '\x02') {
        in_stack_00000038 = FUN_01024a54();
        protocol_report_byte((int)&uStack0000004c + 3);
        FUN_01024e8c(in_stack_00000038,&uStack0000004c,0x32);
      }
    }
    else {
      DAT_000201ea = 0;
      FUN_01023108((int)&uStack0000004c + 1,0x40);
    }
  }
  return in_stack_0000003c;
}
#endif

/* 0102566a */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0102566a(void)
{
  undefined4 uVar1;
  int iVar2;
  undefined1 uStack00000004;
  undefined4 uStack00000008;
  undefined4 in_stack_0000000c;
  undefined4 in_stack_00000038;
  int in_stack_0000003c;
  undefined1 uStack00000044;
  undefined4 uStack0000004c;
  undefined1 uStack00000051;
  undefined1 uStack00000052;
  undefined1 uStack00000053;
  undefined4 in_stack_00000058;
  undefined1 in_stack_0000005c;
  undefined1 uStack0000005d;
  undefined4 in_stack_00000060;
  undefined4 uStack00000064;
  undefined4 in_stack_00000078;
  
  if ((_DAT_00020708 & 0x1000) == 0) {
    if ((_DAT_00020708 & 0x2000) == 0) {
      if ((_DAT_00020708 & 0x4000) == 0) {
        if ((_DAT_00020708 & 0x8000) == 0) {
          if ((_DAT_00020708 & 0x10000) == 0) {
            if ((_DAT_00020708 & 0x20000) == 0) {
              if ((_DAT_00020708 & 0x200000) == 0) {
                if ((_DAT_00020708 & 0x400000) == 0) {
                  if ((_DAT_00020708 & 0x800000) == 0) {
                    if ((_DAT_00020708 & 0x1000000) != 0) {
                      _DAT_00020708 = _DAT_00020708 & 0xfeffffff;
                      uStack0000004c._1_1_ = -0x7f;
                      uStack0000004c._2_1_ = '\x02';
                      in_stack_0000003c = 1;
                    }
                  }
                  else {
                    _DAT_00020708 = _DAT_00020708 & 0xff7fffff;
                    uStack0000004c._1_1_ = -0x7f;
                    uStack0000004c._2_1_ = '\x03';
                    in_stack_0000003c = 1;
                  }
                }
                else {
                  _DAT_00020708 = _DAT_00020708 & 0xffbfffff;
                  uStack0000004c._1_1_ = -0x7f;
                  uStack0000004c._2_1_ = '\x02';
                  in_stack_0000003c = 1;
                  DAT_00020785 = 0;
                }
              }
              else {
                _DAT_00020708 = _DAT_00020708 & 0xffdfffff;
                memcpy(&uStack0000004c,&DAT_01029550,0xb);
                FUN_010206ca(&uStack00000044,0);
                memcpy(&uStack00000051,&uStack00000044,6);
                in_stack_0000003c = 1;
              }
            }
            else {
              _DAT_00020708 = _DAT_00020708 & 0xfffdffff;
              memzero(&uStack0000004c,0x50);
              iVar2 = FUN_0101c0f0((int)&uStack0000004c + 1);
              if (0 < iVar2) {
                *(undefined1 *)((int)&uStack0000004c + iVar2 + 1) = 0x22;
                FUN_010241fa(0x1017040,&uStack00000004,4);
                memcpy((int)&uStack0000004c + iVar2 + 2,&uStack00000004,4);
                (&uStack00000052)[iVar2] = 0x3f;
                (&uStack00000053)[iVar2] = 0;
              }
              in_stack_0000003c = 1;
            }
          }
          else {
            _DAT_00020708 = _DAT_00020708 & 0xfffeffff;
            in_stack_0000003c = 0;
          }
        }
        else {
          _DAT_00020708 = _DAT_00020708 & 0xffff7fff;
          uStack0000004c._1_1_ = -0x7f;
          uStack0000004c._2_1_ = '\x02';
          in_stack_0000003c = 1;
        }
      }
      else {
        _DAT_00020708 = _DAT_00020708 & 0xffffbfff;
        if (DAT_00020777 != '0') {
          DAT_00020785 = 0x80;
          FUN_0102059c();
          memcpy(&uStack0000004c,&DAT_01029550,0xb);
          FUN_010206ca(&uStack00000044,0);
          memcpy(&uStack00000051,&uStack00000044,6);
        }
        in_stack_0000003c = 1;
      }
    }
    else {
      _DAT_00020708 = _DAT_00020708 & 0xffffdfff;
      iVar2 = FUN_01024c60(DAT_000201b4);
      if (iVar2 == 0) {
        uStack00000008 = 0;
        in_stack_0000000c = 0;
      }
      else {
        uVar1 = FUN_01024c60(DAT_000201b4);
        memcpy(&uStack00000008,uVar1,6);
      }
      iVar2 = FUN_010182b0(&uStack00000008,0x20179,6);
      if (iVar2 == 0) {
        memcpy(&uStack0000004c,&DAT_01029542,0xe);
        in_stack_00000058._2_1_ = 0x81;
        in_stack_00000058._3_1_ = 1;
        in_stack_0000005c = 3;
        uStack0000004c._2_1_ = DAT_000217b2 + '\x02';
        in_stack_0000003c = 1;
      }
      else {
        memcpy(&uStack0000004c,&DAT_01029542,0xe);
        in_stack_00000058._2_1_ = 0x81;
        in_stack_00000058._3_1_ = 1;
        in_stack_0000005c = 1;
        FUN_010206ca(&uStack00000044,0);
        memcpy(&uStack0000005d,&uStack00000044,6);
        in_stack_00000060._3_1_ = 0;
        uStack00000064._0_1_ = 0x25;
        uStack00000064._1_1_ = 8;
        FUN_010182ca((int)&uStack00000064 + 2,"Pro Controller");
        in_stack_00000078._1_1_ = 0x68;
        uStack0000004c._2_1_ = DAT_000217b2 + '\x02';
        in_stack_0000003c = 1;
      }
    }
  }
  else {
    _DAT_00020708 = _DAT_00020708 & 0xffffefff;
    memcpy(&uStack0000004c,&DAT_01029542,0xe);
    in_stack_00000058._2_1_ = 0x81;
    in_stack_00000058._3_1_ = 1;
    in_stack_0000005c = 3;
    uStack0000004c._2_1_ = DAT_000217b2 + '\x02';
    in_stack_0000003c = 1;
  }
  if (in_stack_0000003c != 0) {
    if (uStack0000004c._1_1_ == '!') {
      uStack0000004c._2_1_ = FUN_01024980();
    }
    iVar2 = usb_powered();
    if (iVar2 == 0) {
      if (DAT_00020182 == '\x02') {
        in_stack_00000038 = FUN_01024a54();
        protocol_report_byte((int)&uStack0000004c + 3);
        FUN_01024e8c(in_stack_00000038,&uStack0000004c,0x32);
      }
    }
    else {
      DAT_000201ea = 0;
      FUN_01023108((int)&uStack0000004c + 1,0x40);
    }
  }
  return in_stack_0000003c;
}
#endif

/* 010259b4 */
#ifdef NONMATCHING
void FUN_010259b4(void)
{
  DAT_000f6010 = 0xc0;
  DAT_000f6000 = 0x3c;
  DAT_000f6026 = 0xff;
  DAT_000f6027 = 0xff;
  DAT_000f6004 = 0;
  DAT_000f6001 = 0x70;
  DAT_000f6002 = 0xf0;
  DAT_000f6003 = 0xff;
  return;
}
#endif

/* 010259e8 */
#ifdef NONMATCHING
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_010259e8(void)
{
  FUN_010241c8(0xd);
  DAT_000c8905 = 0xff;
  FUN_010241c8(6);
  _DAT_000f8560 = _DAT_000f8560 | 0x800;
  FUN_010259b4();
  _DAT_e000e100 = _DAT_e000e100 | 1;
  memzero(0x210b0,0x4a8);
  FUN_010217fc(0x210b0,1,0x20064,0x200f4,0x20090);
  rom_delay_a(100);
  return;
}
#endif

/* 01025a64 */
#ifdef NONMATCHING
void FUN_01025a64(void)
{
  bt_disconnect();
  return;
}
#endif
