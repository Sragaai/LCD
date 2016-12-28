/*
 * Lcd.c
 *
 *  Created on: Dec 28, 2016
 *      Author: Sragaai
 */
#include "Std_Types.h"
#include "Macros.h"
#include "util/delay.h"
#include "Dio.h"
#include "Lcd.h"

/* Interface to initialize the LCD Driver                                                                            */
void Lcd_vidInit(void)
{
  /* Delay 100ms to ensure the initialization of the LCD driver                                                      */
  _delay_ms(100);

  /* Clear Display                                                                                                   */
  Lcd_vidSendCommand(0b00000001);

  /* Return Home                                                                                                     */
  Lcd_vidSendCommand(0b00000010);

  /* Entry Mode Set                                                                                                  */
  Lcd_vidSendCommand(0b00000110);

  /* Display ON OFF Control                                                                                          */
  Lcd_vidSendCommand(0b00001100);

  /* Function Set                                                                                                    */
  Lcd_vidSendCommand(0b00111000);

}

/* Interface to send the configuration commands to the LCD Driver                                                    */
void Lcd_vidSendCommand(u8 u8CmdCpy)
{

  /* Set RS to LOW                                                                                                   */
  Dio_vidSetPinValue(DIO_PORTA, 0, STD_LOW);

  /* Set R/W to LOW                                                                                                  */
  Dio_vidSetPinValue(DIO_PORTA, 1, STD_LOW);

  /* Set E to HIGH                                                                                                   */
  Dio_vidSetPinValue(DIO_PORTA, 2, STD_HIGH);

  /* Load Command on Data bus                                                                                        */
  Dio_vidSetPortValue(DIO_PORTD, u8CmdCpy);

  /* Set E to LOW                                                                                                    */
  Dio_vidSetPinValue(DIO_PORTA, 2, STD_LOW);

  /* Wait for E to settle                                                                                            */
  _delay_ms(10);

  /* Set E to HIGH                                                                                                   */
  Dio_vidSetPinValue(DIO_PORTA, 2, STD_HIGH);

  /* Delay for 100ms to let the LCD execute command                                                                  */
  _delay_ms(50);

}

/* Interface to write character on LCD screen                                                                        */
void Lcd_vidWriteCharctr(u8 u8DataCpy)
{
  /* Set RS to HIGH                                                                                                  */
  Dio_vidSetPinValue(DIO_PORTA, 0, STD_HIGH);

  /* Set R/W to LOW                                                                                                  */
  Dio_vidSetPinValue(DIO_PORTA, 1, STD_LOW);

  /* Set E to HIGH                                                                                                   */
  Dio_vidSetPinValue(DIO_PORTA, 2, STD_HIGH);

  /* Load Command on Data bus                                                                                        */
  Dio_vidSetPortValue(DIO_PORTD, u8DataCpy);

  /* Set E to LOW                                                                                                    */
  Dio_vidSetPinValue(DIO_PORTA, 2, STD_LOW);

  /* Wait for E to settle                                                                                            */
  _delay_ms(10);

  /* Set E to HIGH                                                                                                   */
  Dio_vidSetPinValue(DIO_PORTA, 2, STD_HIGH);

  /* Delay for 100ms to let the LCD Display the character                                                            */
  _delay_ms(50);

}

/* Interface to write string on LCD screen                                                                           */
void Lcd_vidWriteString(u8* pu8StringCpy)
{
}
