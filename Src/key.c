#include "key.h"
#include "usbd_hid.h"
#include "usb_device.h"

MEDIA_HID   media;
uint8_t     numLeft = 0;
uint8_t     numRight = 0;

void initKeyBoard(void)
{
  media.id = 2;
  media.keys = 0;
}

void keyVolUp(void)
{
  for(uint8_t i=0; i<1; i++)
  {
    media.keys = USB_HID_VOL_UP;
    USBD_HID_SendReport(&hUsbDeviceFS, (uint8_t*)&media, sizeof(MEDIA_HID));
    HAL_Delay(30);
//    media.keys = 0;
//    USBD_HID_SendReport(&hUsbDeviceFS, (uint8_t*)&media, sizeof(MEDIA_HID));
//    HAL_Delay(30);
    media.keys = USB_HID_VOL_UP;
    USBD_HID_SendReport(&hUsbDeviceFS, (uint8_t*)&media, sizeof(MEDIA_HID));
    HAL_Delay(30);
  }
}

void keyVolDec(void)
{
  media.keys = USB_HID_VOL_DEC;
  USBD_HID_SendReport(&hUsbDeviceFS, (uint8_t*)&media, sizeof(MEDIA_HID));
  HAL_Delay(30);
//  media.keys = 0;
//  USBD_HID_SendReport(&hUsbDeviceFS, (uint8_t*)&media, sizeof(MEDIA_HID));
//  HAL_Delay(30);
  media.keys = USB_HID_VOL_DEC;
  USBD_HID_SendReport(&hUsbDeviceFS, (uint8_t*)&media, sizeof(MEDIA_HID));
  HAL_Delay(30);
}

void keyPausePlay(void)
{
  for(uint8_t i=0; i<2; i++)
  {
    media.keys = USB_HID_PAUSE;
    USBD_HID_SendReport(&hUsbDeviceFS, (uint8_t*)&media, sizeof(MEDIA_HID));
    HAL_Delay(30);
    media.keys = 0;
    USBD_HID_SendReport(&hUsbDeviceFS, (uint8_t*)&media, sizeof(MEDIA_HID));
    HAL_Delay(30);
  }
}

void keyVolUp_New(void)
{
  media.keys = USB_HID_VOL_UP;
  USBD_HID_SendReport(&hUsbDeviceFS, (uint8_t*)&media, sizeof(MEDIA_HID));
}

void keyVolDec_New(void)
{
  media.keys = USB_HID_VOL_DEC;
	USBD_HID_SendReport(&hUsbDeviceFS, (uint8_t*)&media, sizeof(MEDIA_HID));
}

void controlKey(void)
{
  if(HAL_GPIO_ReadPin(INPUT_NOR_GPIO_Port, INPUT_NOR_Pin))
  {
    numRight += 1;
		//keyVolUp_New();
  }
  else
  {
    numLeft += 1;
		//keyVolDec_New();
  }
}
