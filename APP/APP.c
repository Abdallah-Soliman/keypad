/*
 * APP.c
 *
 *  Created on: Jan 20, 2022
 *      Author: abdalah
 */

#include "primitive_data_types.h"
#include "LCD_interface.h"
#include "keypad_interface.h"
#include "DIO_interface.h"

void main ()
{
	DIO_SetPinDirection(PORTB ,PIN4 ,OUTPUT);
	uint8_t au8_test=0;
	LCD_VoidInit4b();

	 Keyad_VoidINit();




	 while(1)
	 {
		 au8_test=KeyPad_U8Data();
            if(au8_test !=20)
            	LCD_WriteData4b(au8_test);
	 }


}
