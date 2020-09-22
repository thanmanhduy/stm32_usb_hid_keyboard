#ifndef __KEY_H
#define __KEY_H

#include "stm32f1xx_hal.h"

// USB media codes
#define USB_HID_SCAN_NEXT 0x01
#define USB_HID_SCAN_PREV 0x02
#define USB_HID_STOP      0x04
#define USB_HID_EJECT     0x08
#define USB_HID_PAUSE     0x10
#define USB_HID_MUTE      0x20
#define USB_HID_VOL_UP    0x40
#define USB_HID_VOL_DEC   0x80

// USB keyboard codes
#define USB_HID_MODIFIER_LEFT_CTRL   0x01
#define USB_HID_MODIFIER_LEFT_SHIFT  0x02
#define USB_HID_MODIFIER_LEFT_ALT    0x04
#define USB_HID_MODIFIER_LEFT_GUI    0x08 // (Win/Apple/Meta)
#define USB_HID_MODIFIER_RIGHT_CTRL  0x10
#define USB_HID_MODIFIER_RIGHT_SHIFT 0x20
#define USB_HID_MODIFIER_RIGHT_ALT   0x40
#define USB_HID_MODIFIER_RIGHT_GUI   0x80
#define USB_HID_KEY_L                0x0F

typedef struct
{
  uint8_t id;
  uint8_t modifiers;
  uint8_t key1;
  uint8_t key2;
  uint8_t key3;
}KEYBOARD_HID;
  
typedef struct
{
  uint8_t id;
  uint8_t keys;
}MEDIA_HID;

void initKeyBoard(void);
void keyVolUp(void);
void keyVolDec(void);
void keyPausePlay(void);
void keyVolUp_New(void);
void keyVolDec_New(void);
void controlKey(void);

extern uint8_t     numLeft;
extern uint8_t     numRight;

#endif
