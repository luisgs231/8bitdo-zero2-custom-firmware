    .syntax unified
    .cpu cortex-m0
    .thumb
    .text

    .equ PARAMS,    0x0102a800



    .equ TABLE,     0x000c4975
    .equ MODE,      0x000201b4
    .equ CLASSIC,   0x00020182
    .equ BLE,       0x00020682
    .equ NO_RECONN, 0x000201b8   @ the program's own "do not reconnect" byte
    .equ FF13,      0x00020648
    .equ BATT,      0x0002062d
    .equ PAIRS,     0x01075000
    .equ RECORDS,   170
    .equ ADDR,      0x00023ef0
    .equ LINKS,     0x00023efc
    .equ DISC,      0x00023efd
    .equ LEVEL,     0x00023efe
    .equ RING,      0x00023f00
    .equ LEDAGAIN,  0x000206b0
    .equ LEDPAT,    0x000206bc
    .equ LEDMASK,   0x000206c4
    .equ LED_RED,   1
    .equ LED_USB,   10

    .thumb_func
mode_params:
    ldr r1, =MODE
    ldrb r1, [r1]
    cmp r1, #4
    bls 1f
    movs r1, #3
1:  lsls r2, r1, #4
    lsls r1, r1, #3
    adds r1, r1, r2
    ldr r0, =PARAMS
    adds r0, r0, r1
    bx lr

    .thumb_func
pair_page:
    ldr r3, =MODE
    ldrb r3, [r3]
    cmp r3, #4
    bls 1f
    movs r3, #3
1:  lsls r3, r3, #12
    ldr r0, =PAIRS
    adds r0, r0, r3
    bx lr
    .ltorg

    .global pair_read
    .thumb_func
pair_read:
    push {lr}
    bl pair_page
    bl flash_read
    pop {pc}

    .global pair_write
    .thumb_func
pair_write:
    push {r4, lr}
    mov r4, r0
    bl pair_page
    bl flash_erase
    bl pair_page
    mov r1, r4
    movs r2, #RECORDS
    bl flash_write
    pop {r4, pc}

mode_colours:
    .byte 5, 4, 7, 2, 6
    .align 2

    .thumb_func
led_colour:
    push {r4, lr}
    ldr r4, =LEDMASK
    ldr r2, =LEDPAT
    ldrb r1, [r2]
    cmp r1, #LED_USB
    beq 2f
    ldrb r1, [r4]
    cmp r1, #LED_RED
    beq 2f
    cmp r1, #0
    beq 2f
    ldr r1, =MODE
    ldrb r1, [r1]
    cmp r1, #4
    bls 1f
    movs r1, #3
1:  ldr r3, =mode_colours
    ldrb r1, [r3, r1]
    strb r1, [r4]
2:  ldrb r1, [r4]
    cmp r1, #0
    beq 9f
    ldrb r3, [r2]
    cmp r3, #0
    bne 3f
    ldrb r3, [r2, #4]
    cmp r3, #0
    bne 3f
    movs r0, #7
    bl led_set
    b 9f
3:  movs r0, #7
    bics r0, r1
    movs r1, #0
    bl led_set
9:  pop {r4, pc}
    .ltorg

    .global led_link
    .thumb_func
led_link:
    ldr r0, =CLASSIC
    ldrb r0, [r0]
    cmp r0, #2
    beq 1f
    ldr r0, =BLE
    ldrb r0, [r0]
1:  bx lr
    .ltorg

    .thumb_func
send_cmd:
    push {r4, lr}
    sub sp, #8
    mov r4, sp
    strb r0, [r4, #1]
    strh r2, [r4, #2]
    str r1, [r4, #4]
    mov r0, r4
    bl ipc_send
    add sp, #8
    pop {r4, pc}

    .global gatt_setup
    .thumb_func
gatt_setup:
    push {r4, r5, lr}
    sub sp, #16
    bl mode_params
    mov r5, r0
    ldr r0, =TABLE
    ldr r1, [r5]
    ldrh r2, [r5, #4]
    bl memcpy
    ldr r0, =FF13
    ldrh r1, [r5, #18]
    strh r1, [r0]
    ldr r0, =LEVEL
    movs r1, #0
    strb r1, [r0]
    mov r4, sp
    ldrh r0, [r5, #10]
    strh r0, [r4, #0]
    movs r0, #0x39
    mov r1, r4
    movs r2, #2
    bl send_cmd
    movs r0, #2
    strb r0, [r4, #0]
    movs r0, #1
    strb r0, [r4, #1]
    movs r0, #6
    strb r0, [r4, #2]
    movs r0, #3
    strb r0, [r4, #3]
    movs r0, #0x19
    strb r0, [r4, #4]
    ldrb r0, [r5, #6]
    strb r0, [r4, #5]
    ldrb r0, [r5, #7]
    strb r0, [r4, #6]
    movs r0, #3
    strb r0, [r4, #7]
    movs r0, #3
    strb r0, [r4, #8]
    movs r0, #0x12
    strb r0, [r4, #9]
    movs r0, #0x18
    strb r0, [r4, #10]
    movs r0, #0x34
    mov r1, r4
    movs r2, #11
    bl send_cmd
    ldr r1, =scan_rsp
    movs r0, #0x35
    movs r2, #12
    bl send_cmd
    movs r0, #2
    bl cmd_42
    add sp, #16
    pop {r4, r5, pc}
    .ltorg
scan_rsp:
    .byte 11, 0x09
    .ascii "Zero 2 BLE"
    .align 2

    .global vis_bits
    .thumb_func
vis_bits:
    movs r5, #1
    movs r6, #1
    movs r1, #0
    cmp r4, #1
    bne 1f
    movs r1, #1
1:  ldr r0, =BLE
    ldrb r0, [r0]
    cmp r0, #2
    bne 2f
    movs r5, #0
    b 4f
2:  ldr r0, =CLASSIC
    ldrb r0, [r0]
    cmp r0, #2
    bne 3f
    movs r6, #0
4:  movs r1, #0
    movs r4, #0
3:  ldr r0, =DISC
    strb r1, [r0]
    bx lr

    .thumb_func
ble_address:
    push {r4, lr}
    sub sp, #8
    mov r4, r0
    ldr r1, =ADDR
    mov r0, sp
    movs r2, #6
    bl memcpy
    cmp r4, #0
    beq 1f
    mov r0, sp
    ldrb r1, [r0, #0]
    movs r2, #128
    eors r1, r2
    strb r1, [r0, #0]
1:  mov r0, sp
    bl set_ble_addr
    add sp, #8
    pop {r4, pc}
    .ltorg

    .thumb_func
ble_reach:
    push {lr}
    ldr r0, =CLASSIC
    ldrb r0, [r0]
    cmp r0, #2
    beq 1f
    movs r0, #0
    bl ble_address
    pop {pc}
1:  movs r0, #1
    bl ble_address
    ldr r0, =BLE
    ldrb r0, [r0]
    cmp r0, #2
    bne 2f
    bl ble_disconnect
2:  pop {pc}

    .thumb_func
apply_vis:
    push {lr}
    movs r2, #0
    movs r1, #0
    ldr r0, =DISC
    ldrb r0, [r0]
    bl set_vis
    pop {pc}
    .ltorg

    .thumb_func
battery_again:
    ldr r0, =LEVEL
    movs r1, #0
    strb r1, [r0]
    bx lr
    .ltorg

    .global on_ble_up
    .thumb_func
on_ble_up:
    push {lr}
    bl apply_vis
    bl ble_reach
    bl battery_again
    pop {pc}

    .global on_ble_down
    .thumb_func
on_ble_down:
    push {lr}
    bl c874
    bl apply_vis
    pop {pc}

    .global on_classic_up
    .thumb_func
on_classic_up:
    push {lr}
    bl c900
    ldr r0, =BLE
    ldrb r0, [r0]
    cmp r0, #2
    bne 1f
    bl ble_disconnect
1:  bl apply_vis
    bl battery_again
    pop {pc}

    .global on_classic_down
    .thumb_func
on_classic_down:
    push {lr}
    ldr r1, =CLASSIC
    strb r0, [r1]
    bl apply_vis
    pop {pc}

    .thumb_func
battery_sync:
    push {r4, r5, r6, lr}
    sub sp, #8
    bl mode_params
    mov r5, r0
    ldrh r6, [r5, #14]
    cmp r6, #0
    beq 9f
    ldr r0, =BATT
    ldrb r0, [r0]
    cmp r0, #0
    beq 9f
    ldr r1, =LEVEL
    ldrb r2, [r1]
    cmp r0, r2
    beq 9f
    strb r0, [r1]
    mov r4, r0
    ldr r1, =TABLE
    ldrh r2, [r5, #16]
    adds r1, r1, r2
    strb r0, [r1]
    ldr r1, =BLE
    ldrb r1, [r1]
    cmp r1, #2
    bne 1f
    mov r1, sp
    strh r6, [r1]
    strb r4, [r1, #2]
    movs r2, #3
    movs r0, #9
    bl send_cmd
1:  ldrb r0, [r5, #20]
    cmp r0, #0
    beq 9f
    ldr r1, =CLASSIC
    ldrb r1, [r1]
    cmp r1, #2
    bne 9f
    mov r1, sp
    movs r2, #0xa1
    strb r2, [r1]
    strb r0, [r1, #1]
    strb r4, [r1, #2]
    mov r0, r1
    movs r1, #3
    bl send_b0
9:  add sp, #8
    pop {r4, r5, r6, pc}
    .ltorg

    .global poll_sync
    .thumb_func
poll_sync:
    push {r4, lr}
    ldr r2, =CLASSIC
    ldrb r2, [r2]
    ldr r3, =BLE
    ldrb r3, [r3]
    lsls r3, r3, #4
    orrs r2, r3
    ldr r3, =LINKS
    ldrb r1, [r3]
    cmp r1, r2
    beq 1f
    strb r2, [r3]
    movs r0, #1
    ldr r1, =LEDAGAIN
    strb r0, [r1]
    bl apply_vis
    bl ble_reach
1:  bl battery_sync
    bl led_colour
    bl poll_flags
    pop {r4, pc}
    .ltorg

    .global reconnect_blocked
    .thumb_func
reconnect_blocked:
    ldr r0, =BLE
    ldrb r0, [r0]
    cmp r0, #2
    beq 1f
    ldr r0, =NO_RECONN
    ldrb r0, [r0]
    bx lr
1:  movs r0, #1
    bx lr

    .global link_state
    .thumb_func
link_state:
    ldr r0, =CLASSIC
    ldrb r0, [r0]
    cmp r0, #2
    beq 1f
    ldr r0, =BLE
    ldrb r0, [r0]
    cmp r0, #2
    bne 1f
    movs r0, #2
1:  bx lr

    .global send_report
    .thumb_func
send_report:
    push {r4, r5, r6, lr}
    sub sp, #56
    mov r4, r0
    mov r5, r1
    ldr r0, =BLE
    ldrb r0, [r0]
    cmp r0, #2
    bne 9f
    bl mode_params
    mov r6, r0
    ldrb r0, [r6, #8]
    ldrb r1, [r4, #1]
    cmp r0, r1
    bne 9f
    ldrb r2, [r6, #9]
    adds r0, r2, #2
    cmp r5, r0
    blt 9f
    mov r0, sp
    ldrh r1, [r6, #12]
    strh r1, [r0]
    adds r0, #2
    adds r1, r4, #2
1:  subs r2, #1
    bmi 2f
    ldrb r3, [r1, r2]
    strb r3, [r0, r2]
    b 1b
2:  ldrb r2, [r6, #9]
    adds r2, #2
    mov r1, sp
    movs r0, #9
    bl send_cmd
9:  add sp, #56
    ldr r0, =CLASSIC
    ldrb r0, [r0]
    cmp r0, #2
    bne 8f
    mov r0, r4
    mov r1, r5
    bl send_b0
8:  pop {r4, r5, r6, pc}

    .global ble_addr
    .thumb_func
ble_addr:
    push {r4, lr}
    sub sp, #8
    mov r1, r0
    mov r0, sp
    movs r2, #6
    bl memcpy
    ldr r0, =MODE
    ldrb r0, [r0]
    adds r0, #1
    mov r1, sp
    ldrb r2, [r1, #0]
    eors r2, r0
    strb r2, [r1, #0]
    ldr r0, =ADDR
    mov r1, sp
    movs r2, #6
    bl memcpy
    mov r0, sp
    bl set_ble_addr
    add sp, #8
    pop {r4, pc}
    .ltorg

    .global probe
    .thumb_func
probe:
    push {r4, r5, r6, lr}
    sub sp, #136
    mov r4, sp
    subs r1, r1, #2
    blt out
    cmp r1, #120
    ble 1f
    movs r1, #120
1:  ldrb r2, [r0, #0]
    strb r2, [r4, #1]
    ldrb r6, [r0, #1]
    adds r0, r0, #2
    cmp r6, #2
    blt fill
    subs r1, r1, #4
    blt out
    movs r3, #4
5:  lsls r2, r2, #8
    subs r3, r3, #1
    ldrb r5, [r0, r3]
    orrs r2, r5
    cmp r3, #0
    bne 5b
    adds r0, r0, #4
    cmp r6, #3
    beq poke
    cmp r6, #2
    bne flash
    ldrb r1, [r0]
    cmp r1, #120
    ble 2f
    movs r1, #120
2:  mov r0, r2
    movs r2, #9
    strb r2, [r4, #1]
    movs r6, #0
fill:
    cmp r6, #0
    bne send
    add r5, sp, #8
    ldr r2, =FF13
    ldrh r2, [r2]
    strh r2, [r5]
    adds r5, r5, #2
    movs r3, r1
3:  subs r3, r3, #1
    bmi 4f
    ldrb r2, [r0, r3]
    strb r2, [r5, r3]
    b 3b
4:  subs r0, r5, #2
    adds r1, r1, #2
send:
    strh r1, [r4, #2]
    str r0, [r4, #4]
    mov r0, r4
    bl ipc_send
out:
    add sp, #136
    pop {r4, r5, r6, pc}
poke:
    subs r1, r1, #1
    bmi out
    ldrb r3, [r0, r1]
    strb r3, [r2, r1]
    b poke

flash:
    ldr r3, =0x01070000
    cmp r2, r3
    blo out
    ldr r3, =0x01080000
    cmp r2, r3
    bhs out
    cmp r6, #4
    bne 7f
    mov r0, r2
    bl flash_erase
    b out
7:  cmp r6, #5
    bne out
    cmp r1, #0
    ble out
    mov r3, r1
    mov r1, r0
    mov r0, r2
    mov r2, r3
    bl flash_write
    b out
    .ltorg


    .global hook_rx
    .thumb_func
hook_rx:
    push {r4, r5, r6, lr}
    ldr r4, =RING
    ldr r3, =0x20025
    ldrb r5, [r3, #1]
    ldrb r6, [r3, #7]
    ldrb r0, [r3, #6]
    lsls r6, r6, #8
    orrs r6, r0
    ldrb r0, [r3, #5]
    lsls r6, r6, #8
    orrs r6, r0
    ldrb r0, [r3, #4]
    lsls r6, r6, #8
    orrs r6, r0
    cmp r5, #6
    bne 1f
    ldrb r0, [r6]
    cmp r0, #9
    bne 1f
    movs r0, #0
    strb r0, [r4, #2]
    b 9f
1:  movs r2, #7
    ldrb r0, [r4]
    ands r0, r2
    adds r1, r0, #1
    ands r1, r2
    ldrb r2, [r4, #1]
    cmp r1, r2
    beq 9f
    strb r1, [r4]
    movs r2, #20
    muls r0, r2, r0
    adds r0, r0, r4
    adds r0, #8
    strb r5, [r0]
    ldrb r1, [r3, #2]
    ldrb r2, [r3, #3]
    cmp r2, #0
    beq 2f
    movs r1, #255
2:  strb r1, [r0, #1]
    cmp r1, #18
    bls 3f
    movs r1, #18
3:  adds r0, #2
4:  subs r1, #1
    bmi 9f
    ldrb r2, [r6, r1]
    strb r2, [r0, r1]
    b 4b
9:  bl now
    pop {r4, r5, r6, pc}
    .ltorg

    .global drain
    .thumb_func
drain:
    push {r4, r5, r6, lr}
    sub sp, #32
    bl loop_once
    ldr r4, =RING
    ldr r0, =0x20682
    ldrb r0, [r0]
    cmp r0, #2
    bne 0f
    ldr r0, =FF13
    ldrh r0, [r0]
    cmp r0, #0
    bne 1f
0:  ldrb r0, [r4]
    movs r1, #7
    ands r0, r1
    strb r0, [r4]
    strb r0, [r4, #1]
    b 8f
1:  ldrb r0, [r4, #2]
    cmp r0, #0
    beq 2f
    ldr r0, [r4, #4]
    movs r1, #100
    bl elapsed
    cmp r0, #0
    beq 9f
2:  ldrb r5, [r4, #1]
    movs r0, #7
    ands r5, r0
    ldrb r0, [r4]
    cmp r0, r5
    beq 8f
    movs r1, #20
    muls r1, r5, r1
    adds r1, r1, r4
    adds r1, #8
    ldrb r6, [r1, #1]
    cmp r6, #18
    bls 3f
    movs r6, #18
3:  adds r6, #2
    add r2, sp, #8
    ldr r0, =FF13
    ldrh r0, [r0]
    strh r0, [r2]
    adds r2, #2
    movs r3, r6
4:  subs r3, #1
    bmi 5f
    ldrb r0, [r1, r3]
    strb r0, [r2, r3]
    b 4b
5:  mov r0, sp
    movs r1, #9
    strb r1, [r0, #1]
    adds r6, #2
    strh r6, [r0, #2]
    add r1, sp, #8
    str r1, [r0, #4]
    bl ipc_send
    cmp r0, #0
    beq 8f
    adds r5, #1
    movs r0, #7
    ands r5, r0
    strb r5, [r4, #1]
    bl now
    str r0, [r4, #4]
    movs r0, #1
    b 7f
8:  movs r0, #0
7:  strb r0, [r4, #2]
9:  add sp, #32
    pop {r4, r5, r6, pc}
    .ltorg
