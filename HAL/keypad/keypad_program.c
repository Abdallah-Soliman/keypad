

#include "primitive_data_types.h"
#include "BIT_MATH.h"

#include "DIO_private.h"







# define   column_nums 3

# define   ROW_nums    3




 static const uint8_t g_keymap[3][3]={{'1','2','3'},
	                                          {'4','5','6'},
								              {'7','8','9'},
								                          };





void Keyad_VoidINit(void){

		// DIO_SetPortDirection(PORTD ,0b00001111);
	      /*all rows inputs */
	DIO_SetPinDirection(PORTC ,PIN2 ,INPUT);
	DIO_SetPinDirection(PORTC ,PIN3 ,INPUT);
	DIO_SetPinDirection(PORTC ,PIN4 ,INPUT);

	        /*all columns are outputs*/
	DIO_SetPinDirection(PORTC ,PIN5 ,OUTPUT);
	DIO_SetPinDirection(PORTC ,PIN6 ,OUTPUT);
	DIO_SetPinDirection(PORTC ,PIN7 ,OUTPUT);

	          /*all output high*/
	 DIO_SetPinValue(PORTC , PIN5 , HIGH);
	 DIO_SetPinValue(PORTC , PIN6 , HIGH);
	 DIO_SetPinValue(PORTC , PIN7 , HIGH);
             /*pull up for inputs*/
	 DIO_SetPinValue(PORTC , PIN2 , HIGH);
	 DIO_SetPinValue(PORTC , PIN3 , HIGH);
	 DIO_SetPinValue(PORTC , PIN4 , HIGH);
}













/*uint8_t*/char KeyPad_U8Data(void)
   {
	   uint8_t au8_Copy_Pressed_key=20;
	   uint8_t au8_Copy_Colum;
	   uint8_t au8_Copy_Row;

	   for(au8_Copy_Colum=5;au8_Copy_Colum<=7;au8_Copy_Colum++)
	   {
		   DIO_SetPinValue(PORTC ,(au8_Copy_Colum), LOW);

		  for(au8_Copy_Row=2;au8_Copy_Row<=4; au8_Copy_Row++)
		  {

			  if (0 == DIO_GetPinValue(PORTC,(au8_Copy_Row )))
			  {
				  LCD_VoidDelay(20);

           	    while(0 == DIO_GetPinValue(PORTC,au8_Copy_Row )){
				         DIO_SetPinValue(PORTC ,(au8_Copy_Colum),HIGH);
					    	 return g_keymap[au8_Copy_Row-2][au8_Copy_Colum-5];
           	    }
					    }


			   else
			   {/*for MEZRARULE */};

		  }
		  DIO_SetPinValue(PORTC ,(au8_Copy_Colum),HIGH);
	   }
	   return au8_Copy_Pressed_key;





   }

