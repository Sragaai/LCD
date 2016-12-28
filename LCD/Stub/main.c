/*
 * main.c
 *
 *  Created on: Dec 27, 2016
 *      Author: Sragaai
 */
#include "Std_Types.h"
#include "Macros.h"
#include "util/delay.h"
#include "Dio.h"
#include "Lcd.h"

int main(void)
{

  /* Port Initialization                                                                                             */
  Dio_vidSetPortDirection(DIO_PORTA, 0xFF);

  Dio_vidSetPortDirection(DIO_PORTD, 0xFF);

  /* LCD initialization                                                                                              */
  Lcd_vidInit();

  /* Write Character                                                                                                 */
  Lcd_vidWriteCharctr('a');
  Lcd_vidWriteCharctr('c');

  while (1)
  {
  }

}

