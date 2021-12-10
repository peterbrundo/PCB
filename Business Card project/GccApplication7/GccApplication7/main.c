/* Name: main.c
 * Project: HID-Test
 * Author: Christian Starkjohann
 * Creation Date: 2006-02-02
 * Tabsize: 4
 * Copyright: (c) 2006 by OBJECTIVE DEVELOPMENT Software GmbH
 * License: GNU GPL v2 (see License.txt) or proprietary (CommercialLicense.txt)
 * This Revision: $Id$
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <avr/wdt.h>

#include "usbdrv.h"
#include "oddebug.h"
#define MOD_CONTROL_LEFT    (1<<0)
#define MOD_SHIFT_LEFT      (1<<1)
#define MOD_ALT_LEFT        (1<<2)
#define MOD_GUI_LEFT        (1<<3)
#define MOD_CONTROL_RIGHT   (1<<4)
#define MOD_SHIFT_RIGHT     (1<<5)
#define MOD_ALT_RIGHT       (1<<6)
#define MOD_GUI_RIGHT       (1<<7)

#define KEY_A       4
#define KEY_B       5
#define KEY_C       6
#define KEY_D       7
#define KEY_E       8
#define KEY_F       9
#define KEY_G       10
#define KEY_H       11
#define KEY_I       12
#define KEY_J       13
#define KEY_K       14
#define KEY_L       15
#define KEY_M       16
#define KEY_N       17
#define KEY_O       18
#define KEY_P       19
#define KEY_Q       20
#define KEY_R       21
#define KEY_S       22
#define KEY_T       23
#define KEY_U       24
#define KEY_V       25
#define KEY_W       26
#define KEY_X       27
#define KEY_Y       28
#define KEY_Z       29
#define KEY_1       30
#define KEY_2       31
#define KEY_3       32
#define KEY_4       33
#define KEY_5       34
#define KEY_6       35
#define KEY_7       36
#define KEY_8       37
#define KEY_9       38
#define KEY_0       39

#define KEY_F1      58
#define KEY_F2      59
#define KEY_F3      60
#define KEY_F4      61
#define KEY_F5      62
#define KEY_F6      63
#define KEY_F7      64
#define KEY_F8      65
#define KEY_F9      66
#define KEY_F10     67
#define KEY_F11     68
#define KEY_F12     69

#define KEY_PETER 93

#define KEY_NUM1 89
#define KEY_NUM2 90
#define KEY_NUM3 91
#define KEY_NUM4 92
#define KEY_NUM5 93
#define KEY_NUM6 94
#define KEY_NUM7 95
#define KEY_NUM8 96
#define KEY_NUM9 97
#define KEY_NUM0 98

#define KEY_VOLUME_MUTE 127
#define KEY_VOLUME_UP 128
#define KEY_VOLUME_DOWN 129

	#define KEY_NUM_LOCK 83
	#define KEY_NUM_div 84
	#define KEY_NUM_mul 85
	#define KEY_NUM_sub 86
	#define KEY_NUM_add 87
	#define KEY_NUM_ENTER 88
	#define KEY_NUM_per 99
/* ----------------------- hardware I/O abstraction ------------------------ */

/* pin assignments:
PB0	Key 1
PB1	Key 2
PB2	Key 3
PB3	Key 4
PB4	Key 5
PB5 Key 6

PC0	Key 7
PC1	Key 8
PC2	Key 9
PC3	Key 10
PC4	Key 11
PC5	Key 12

PD0	USB-
PD1	debug tx
PD2	USB+ (int0)
PD3	Key 13
PD4	Key 14
PD5	Key 15
PD6	Key 16
PD7	Key 17
*/

static void hardwareInit(void)
{
uchar	i, j;

    PORTB = 0xff;   /* activate all pull-ups */
    DDRB = 0;       /* all pins input */
    PORTC = 0xff;   /* activate all pull-ups */
    DDRC = 0;       /* all pins input */
    PORTD = 0xfa;   /* 1111 1010 bin: activate pull-ups except on USB lines */
    DDRD = 0x07;    /* 0000 0111 bin: all pins input except USB (-> USB reset) */
	j = 0;
	while(--j){     /* USB Reset by device only required on Watchdog Reset */
		i = 0;
		while(--i); /* delay >10ms for USB reset */
	}
    DDRD = 0x02;    /* 0000 0010 bin: remove USB reset condition */
    /* configure timer 0 for a rate of 12M/(1024 * 256) = 45.78 Hz (~22ms) */
    TCCR0 = 5;      /* timer 0 prescaler: 1024 */
}

/* ------------------------------------------------------------------------- */

#define NUM_KEYS    74

/* The following function returns an index for the first key pressed. It
 * returns 0 if no key is pressed.
 */
static uchar    keyPressed(void)
{
uchar   i, mask, x;

    x = PINB;
    mask = 1;
    for(i=0;i<6;i++){
        if((x & mask) == 0){
			switch(i){
			case 0:
				return 69;
			case 1:
				return 70;
			case 2:
				return 71;
			case 3:
				return 72;
			case 4:
				return 73;
			case 5:
				return 74;
			}
		}
		mask <<= 1;
    }
    x = PINC;
    mask = 1;
    for(i=0;i<6;i++){
        if((x & mask) == 0){
	        switch(i){
		        
				case 0:
		        return 59;
		        case 1:
		        return 60;
		        case 2:
		        return 61;
		        case 3:
		        return 62;
		        case 4:
		        return 63;
		        case 5:
		        return 64;
				/*
				case 0:
				return 4;
				case 1:
				return 5;
				case 2:
				return 6;
				case 3:
				return 7;
				case 4:
				return 8;
				case 5:
				return 9;
*/

	        }
        }
        mask <<= 1;
        }
    x = PIND;
    mask = 1 << 3;
    for(i=0;i<5;i++){
        if((x & mask) == 0){
	        switch(i){
		        /*
				case 0:
				return 11;
				case 1:
				return 12;
				case 2:
				return 13;
				case 3:
				return 14;
				case 4:
				return 15;
			
			*/
				case 0:
				return 65;
				case 1:
				return 66;
				case 2:
				return 67;
				case 3:
				return 68;
				case 4:
				return 73;
			}
        }
        mask <<= 1;
        }
    return 0;
}

/* ------------------------------------------------------------------------- */
/* ----------------------------- USB interface ----------------------------- */
/* ------------------------------------------------------------------------- */

static uchar    reportBuffer[2];    /* buffer for HID reports */
static uchar    idleRate;           /* in 4 ms units */

const PROGMEM char usbHidReportDescriptor[35] = {   /* USB report descriptor */
    0x05, 0x01,                    // USAGE_PAGE (Generic Desktop)
    0x09, 0x06,                    // USAGE (Keyboard)
    0xa1, 0x01,                    // COLLECTION (Application)
    0x05, 0x07,                    //   USAGE_PAGE (Keyboard)
    0x19, 0xe0,                    //   USAGE_MINIMUM (Keyboard LeftControl)
    0x29, 0xe7,                    //   USAGE_MAXIMUM (Keyboard Right GUI)
    0x15, 0x00,                    //   LOGICAL_MINIMUM (0)
    0x25, 0x01,                    //   LOGICAL_MAXIMUM (1)
    0x75, 0x01,                    //   REPORT_SIZE (1)
    0x95, 0x08,                    //   REPORT_COUNT (8)
    0x81, 0x02,                    //   INPUT (Data,Var,Abs)
    0x95, 0x01,                    //   REPORT_COUNT (1)
    0x75, 0x08,                    //   REPORT_SIZE (8)
    0x25, 0x65,                    //   LOGICAL_MAXIMUM (101)
    0x19, 0x00,                    //   USAGE_MINIMUM (Reserved (no event indicated))
    0x29, 0x65,                    //   USAGE_MAXIMUM (Keyboard Application)
    0x81, 0x00,                    //   INPUT (Data,Ary,Abs)
    0xc0                           // END_COLLECTION
};
/* We use a simplifed keyboard report descriptor which does not support the
 * boot protocol. We don't allow setting status LEDs and we only allow one
 * simultaneous key press (except modifiers). We can therefore use short
 * 2 byte input reports.
 * The report descriptor has been created with usb.org's "HID Descriptor Tool"
 * which can be downloaded from http://www.usb.org/developers/hidpage/.
 * Redundant entries (such as LOGICAL_MINIMUM and USAGE_PAGE) have been omitted
 * for the second INPUT item.
 */

/* Keyboard usage values, see usb.org's HID-usage-tables document, chapter
 * 10 Keyboard/Keypad Page for more codes.
 */


static const uchar  keyReport[NUM_KEYS + 1][2] PROGMEM = {
	/* none */  {0, 0},                     /* no key pressed */
		/*  1 */    {MOD_SHIFT_LEFT, KEY_A},
		/*  2 */    {MOD_SHIFT_LEFT, KEY_B},
		/*  3 */    {MOD_SHIFT_LEFT, KEY_C},
		/*  4 */    {MOD_SHIFT_LEFT, KEY_D},
		/*  5 */    {MOD_SHIFT_LEFT, KEY_E},
		/*  6 */    {MOD_SHIFT_LEFT, KEY_F},
		/*  7 */    {MOD_SHIFT_LEFT, KEY_G},
		/*  8 */    {MOD_SHIFT_LEFT, KEY_H},
		/*  9 */    {MOD_SHIFT_LEFT, KEY_I},
		/* 10 */    {MOD_SHIFT_LEFT, KEY_J},
		/* 11 */    {MOD_SHIFT_LEFT, KEY_K},
		/* 12 */    {MOD_SHIFT_LEFT, KEY_L},
		/* 13 */    {MOD_SHIFT_LEFT, KEY_M},
		/* 14 */    {MOD_SHIFT_LEFT, KEY_N},
		/* 15 */    {MOD_SHIFT_LEFT, KEY_O},
		/* 16 */    {MOD_SHIFT_LEFT, KEY_P},
		/* 17 */    {MOD_SHIFT_LEFT, KEY_Q},
		/* 18 */    {MOD_SHIFT_LEFT, KEY_R},
		/* 19 */    {MOD_SHIFT_LEFT, KEY_S},
		/* 20 */    {MOD_SHIFT_LEFT, KEY_T},
		/* 21 */    {MOD_SHIFT_LEFT, KEY_U},
		/* 22 */    {MOD_SHIFT_LEFT, KEY_V},
		/* 23 */    {MOD_SHIFT_LEFT, KEY_W},
		/* 24 */    {MOD_SHIFT_LEFT, KEY_X},
		/* 25 */    {MOD_SHIFT_LEFT, KEY_Y},
		/* 26 */    {MOD_SHIFT_LEFT, KEY_Z},
		/* 27 */    {0, 0},
		/* 28 */    {0, 0},
		/* 29 */    {0, 0},
		/* 30 */    {0, 0},
		/* 31 */    {0, 0},
		/* 32 */    {0, 0},
		/* 33 */    {0, 0},
		/* 34 */    {0, 0},
		/* 35 */    {0, 0},
		/* 36 */    {0, 0},
		/* 37 */    {0, 0},
		/* 38 */    {0, 0},
		/* 39 */    {0, 0},
		/* 40 */    {0, 0},
		/* 41 */    {0, 0},
		/* 42 */    {0, 0},
		/* 43 */    {0, 0},
		/* 44 */    {0, 0},
		/* 45 */    {0, 0},
		/* 46 */    {0, 0},
		/* 47 */    {0, 0},
		/* 48 */    {0, 0},
		/* 49 */    {0, 0},
		/* 50 */    {0, 0},
		/* 51 */    {0, 0},
		/* 52 */    {0, 0},
		/* 53 */    {0, 0},
		/* 54 */    {0, 0},
		/* 55 */    {0, 0},
		/* 56 */    {0, 0},
		/* 57 */    {0, 0},
		/* 58 */    {0, 0},
		/* 59 */    {0, KEY_NUM_LOCK},
		/* 60 */    {0, KEY_NUM_div},
		/* 61 */    {0, KEY_NUM_mul},
		/* 62 */    {0, KEY_NUM_sub},
		/* 63 */    {0, KEY_NUM_add},
		/* 64 */    {0, KEY_NUM_ENTER},
		/* 65 */    {0, KEY_NUM_per},
		/* 66 */    {0, KEY_VOLUME_MUTE},
		/* 67 */    {0, KEY_VOLUME_DOWN},
		/* 68 */    {0, KEY_VOLUME_UP},
		/* 69 */    {0, KEY_NUM1},
		/* 70 */    {0, KEY_NUM2},
		/* 71 */    {0, KEY_NUM3},
		/* 72 */    {0, KEY_NUM4},
		/* 73 */    {0, KEY_NUM5},
		/* 74 */    {0, KEY_NUM6},
};


static void buildReport(uchar key)
{
/* This (not so elegant) cast saves us 10 bytes of program memory */
    *(int *)reportBuffer = pgm_read_word(keyReport[key]);
}

uchar	usbFunctionSetup(uchar data[8])
{
usbRequest_t    *rq = (void *)data;

    usbMsgPtr = reportBuffer;
    if((rq->bmRequestType & USBRQ_TYPE_MASK) == USBRQ_TYPE_CLASS){    /* class request type */
        if(rq->bRequest == USBRQ_HID_GET_REPORT){  /* wValue: ReportType (highbyte), ReportID (lowbyte) */
            /* we only have one report type, so don't look at wValue */
            buildReport(keyPressed());
            return sizeof(reportBuffer);
        }else if(rq->bRequest == USBRQ_HID_GET_IDLE){
            usbMsgPtr = &idleRate;
            return 1;
        }else if(rq->bRequest == USBRQ_HID_SET_IDLE){
            idleRate = rq->wValue.bytes[1];
        }
    }else{
        /* no vendor specific requests implemented */
    }
	return 0;
}

/* ------------------------------------------------------------------------- */

int	main(void)
{
uchar   key, lastKey = 0, keyDidChange = 0;
uchar   idleCounter = 0;

	wdt_enable(WDTO_2S);
    hardwareInit();
	odDebugInit();
	usbInit();
	sei();
    DBG1(0x00, 0, 0);
	for(;;){	/* main event loop */
		wdt_reset();
		usbPoll();
        key = keyPressed();
        if(lastKey != key){
            lastKey = key;
            keyDidChange = 1;
        }
        if(TIFR & (1<<TOV0)){   /* 22 ms timer */
            TIFR = 1<<TOV0;
            if(idleRate != 0){
                if(idleCounter > 4){
                    idleCounter -= 5;   /* 22 ms in units of 4 ms */
                }else{
                    idleCounter = idleRate;
                    keyDidChange = 1;
                }
            }
        }
        if(keyDidChange && usbInterruptIsReady()){
            keyDidChange = 0;
            /* use last key and not current key status in order to avoid lost
               changes in key status. */
            buildReport(lastKey);
            usbSetInterrupt(reportBuffer, sizeof(reportBuffer));
        }
	}
	return 0;
}

/* ------------------------------------------------------------------------- */
