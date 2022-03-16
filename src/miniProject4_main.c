/*
 ======================================================================================
 Name        : miniproject4_main.c
 Author      : Mostafa Medhat
 Description : Implement a system to measure the distance using Atmega16 microcontroller,
  	  	  	   ultrasonic sensor HC-SR04 & LCD
 ======================================================================================
 */

#include "lcd.h"
#include "ultrasonic.h"
#include "std_types.h"
#include "util/delay.h"
#include "avr/io.h" 	//To enable I-bit

int main (void)
{
	uint16 ultrasonic_distance=0;	//declare a variable to get distance value
	SREG|=(1<<7);					//Enable I-Bit
	Ultrasonic_init();				//Initialize Ultrasonic sensor
	LCD_init();						//Initialize LCD
	LCD_displayString("Distance=    cm");	//Print "Distance=   cm" on LCD
	while(1)
	{
		ultrasonic_distance=Ultrasonic_readDistance();		//Get distance value
		LCD_moveCursor(0, 10);								//Move Cursor to 1st row and column #10
		LCD_intgerToString(ultrasonic_distance);			//Print distance value on LCD
		/*
		 * if distance value < 100 .. print an empty space to erase the last digit of the previous value.
		 */
		if(ultrasonic_distance < 100)
		{
			LCD_displayCharacter(' ');
		}
		_delay_ms(100);				//delay 100ms between every two reads
	}
}

