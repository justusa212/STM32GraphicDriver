/* babydriver.h - Just made a driver 3 days that's quick
 *
 * Last updated 12/03/2025
 *
 * This library licensed with BSD 3-Clause:
 *
 * Copyright 2025 hoff.industries
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS “AS IS” AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. */

#ifndef BABYDRIVER_H
#define BABYDRIVER_H

#include <stdint.h>
#include <stdbool.h>

#define BD_FB_WIDTH 256
#define BD_FB_HEIGHT 128

#define BD_FB_SIZE (BD_FB_WIDTH * BD_FB_HEIGHT) / 8

#define BD_COM_PSR			0x00
#define BD_COM_PWR			0x01
#define BD_COM_OFF			0x02
#define BD_COM_PFS			0x03
#define BD_COM_PON			0x04
#define BD_COM_PMES			0x05
#define BD_COM_BTST			0x06
#define BD_COM_DSLP			0x07

#define BD_COM_DTM1			0x10
#define BD_COM_DSP			0x11
#define BD_COM_DRF			0x12
#define BD_COM_DTM2			0x13
#define BD_COM_AUTO			0x17

#define BD_COM_LUTC			0x20
#define BD_COM_LUTWW		0x21
#define BD_COM_LUTKW		0x22
#define BD_COM_LUTWK		0x23
#define BD_COM_LUTKK		0x24
#define BD_COM_LUTOPT		0x2A

#define BD_COM_PLL			0x30
#define BD_COM_TSC			0x40
#define BD_COM_TSE			0x41
#define BD_COM_TSW			0x42
#define BD_COM_TSR			0x43
#define BD_COM_PBC			0x44
#define BD_COM_CDI			0x50
#define BD_COM_LPD			0x51

#define BD_COM_TCON			0x60
#define BD_COM_TRES			0x61
#define BD_COM_GSST			0x65

#define BD_COM_REV			0x70
#define BD_COM_FLG			0x71
#define BD_COM_CRC			0x72

#define BD_COM_AMV			0x80
#define BD_COM_VV			0x81
#define BD_COM_VDCS			0x82

#define BD_COM_PTL			0x90
#define BD_COM_PTIN			0x91
#define BD_COM_PTOUT		0x92

#define BD_COM_PGM			0xA0
#define BD_COM_APG			0xA1
#define BD_COM_ROTP			0xA2

#define BD_COM_CCSET		0xE0
#define BD_COM_PWS			0xE3
#define BD_COM_LVSEL		0xE4
#define BD_COM_TSSET		0xE5

#define BD_PSR_FULL_LANDSCAPE	0xF7

#define BD_PWR_VSG_18V		0x03
#define BD_PWR_VGHL_20V		0x00
#define BD_PWR_VSH_15V		0x3F
#define BD_PWR_VSL_15V		0x3F
#define BD_PWR_VDHR_2v8		0x03

#define BD_PFS_VDOFF_1F		0x00
#define BD_VCOM_AMV_3S		0x00

#define BD_BTST_PHA_10_5_658	0x27
#define BD_BTST_PHB_10_5_658	0x27
#define BD_BTST_PHC_6_658		0x2F

#define BD_PLL_FRS_50		0x09

#define BD_TCON_SG_12_12	0x22
#define BD_PWS_LVD_2v2	0x00

#define BD_TSE_ENABLE 0x00
#define BD_GSST_HST_NIL	0x00
#define BD_GSST_VST_NIL 0x00

#define BD_CDI_LUTW_LUTW_10	0xB7

#define BD_AUTO_PON_DRF_POF			0xA5
#define BD_AUTO_PON_DRF_POF_DSLP	0xA7

enum BDLUTType {

	BD_LUT_T_DU,
	BD_LUT_T_GC
} typedef bd_luttype_e;

struct BDState {

	int upTo;
	int scanRunner;
	int lutState;
	bool doBorder;
	bool initialised;
} typedef bd_state_s;

extern uint8_t BD_FRAMEBUFFER[BD_FB_SIZE];

void bd_draw_bitmap(int x, int y, int width, int height, const uint8_t *bitmap);
void bd_draw_bitmap_alt(int x, int y, int width, int height, const uint8_t *bitmap);
bool bd_get_pixel(int x, int y);
void bd_set_pixel(int x, int y, bool state);
void bd_draw_rectangle(int x, int y, int width, int height);
void bd_draw_rdiagonal(int x, int y, int width, int height);
void bd_draw_ldiagonal(int x, int y, int width, int height);
void bd_draw_triangle(int x, int y, int side, int width);
void bd_draw_text(int x, int y, int size, char *text);
void bd_print_framebuffer();
void bd_fill_framebuffer(bool colour);

/* NOTE: BEGIN PHYSICAL COMMS */

void bd_set_spi_tx(void (*spi_tx)(uint8_t byte));
void bd_set_set_cd(void (*set_cd)(bool state));
void bd_set_set_cs(void (*set_cs)(bool state));

void bd_power_on();
void bd_power_off();

void bd_render_framebuffer(bool fullRefresh);
void bd_init();
#endif
