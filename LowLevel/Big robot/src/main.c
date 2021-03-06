/*
**
**                           Main.c
**
**
**********************************************************************/
/*
   Last committed:     $Revision: 00 $
   Last changed by:    $Author: $
   Last changed date:  $Date:  $
   ID:                 $Id:  $

**********************************************************************/
#include "stm32f4xx_conf.h"

#include "stm32f4xx.h"
#include "Board.h"  //���� �������������

#include "gpio.h" // ������ � ������� �����-������
#include "Pins.h" // ����������� ����� �� �����
#include "Interrupts.h"
#include "regulator.h"
// ���������� �����, ����������, �����������

#include "usart.h" //����� � ������������� ��������
#include "robot.h"  //����������� ������������ ������ � ��� �������� �������
#include "Manipulators.h"
// ����� � �����������
#include "usbd_cdc_core.h"
#include "usbd_usr.h"
#include "usb_conf.h"
#include "usbd_desc.h"
#include "usbd_cdc_vcp.h"

#ifdef USB_OTG_HS_INTERNAL_DMA_ENABLED
  #if defined ( __ICCARM__ ) /*!< IAR Compiler */
    #pragma data_alignment=4
  #endif
#endif /* USB_OTG_HS_INTERNAL_DMA_ENABLED */

__ALIGN_BEGIN USB_OTG_CORE_HANDLE    USB_OTG_dev __ALIGN_END;

char mode;
float distance[10];
int stop_cnt = 0;
int flag_kostil = 0 ;
int main(void)
{

    __disable_irq();
    initAll();
    CloseLauncher();

      USBD_Init(&USB_OTG_dev,
#ifdef USE_USB_OTG_HS
            USB_OTG_HS_CORE_ID,
#else
            USB_OTG_FS_CORE_ID,
#endif
            &USR_desc,
            &USBD_CDC_cb,
            &USR_cb);

       //����� ��������� ������������� ������� � ������ ����������� �����������


//    __disable_irq();

//    conf_pin(EXTI2_PIN, INPUT, PUSH_PULL, FAST_S, PULL_UP);
__enable_irq();


while(1){
        //throwRightCollectorIntoBox(76);
//    setVoltage(6, 0.1);
//    setVoltage(6, 0.4);
//    setVoltage(6, 0.9);
//
//    setVoltage(6, -0.1);
//    setVoltage(6, -0.4);
//    setVoltage(6, -0.9);
//
//    setVoltage(6, 0.0);
// if (pin_val(EXTI9_PIN))
//      {
//        flag_kostil  = 1;
//        startFlag = 1;
//      }
//     else if (flag_kostil == 0)
//      {
//        stop_cnt = 0;
//        startFlag = 0;
//      }
//    distance_digital2[0] = pin_val(IR_LEFT_FRONT);
//    distance_digital2[1] = pin_val(IR_LEFT_BACK);
//    distance_digital2[2] = pin_val(IR_FRONT);
//    distance_digital2[3] = pin_val(IR_BACK);
//    distance_digital2[4] = pin_val(IR_RIGHT_FRONT);
//    distance_digital2[5] = pin_val(IR_RIGHT_BACK);
    }
}
