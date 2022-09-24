/* SPDX-License-Identifier: GPL-2.0-or-later */

#include "kebab_snick.h"
#include "print.h"

char oled_frame[512];
uint16_t oled_frame_rcv = 0;

void raw_hid_receive_kb(uint8_t *data, uint8_t length) {
    uint8_t *command_id   = &(data[0]);
    uint8_t *command_data = &(data[1]);

    // static uint16_t oled_frame_rcv = 0;

    uint8_t added = 0;

    switch (*command_id) {
        case id_debug_num:
            *dat_h = (char)(*command_data + '0');

            break;
        case id_init_oled_frame:
            oled_frame_rcv = 0;
            for (int i = 0; i < length - 1; i++) {
                oled_frame[oled_frame_rcv + i] = (char)command_data[i];
            }
            oled_frame_rcv = length - 1;

            break;
        case id_continue_oled_frame:
            for (int i = 0; i < length - 1; i++) {
                oled_frame[oled_frame_rcv + i] = (char)command_data[i];
                added++;
                if (oled_frame_rcv >= 512) {
                    break;
                }
            }
            oled_frame_rcv += added;
            
            break;
        default:
            *command_id = id_unhandled;
            break;
    }
}