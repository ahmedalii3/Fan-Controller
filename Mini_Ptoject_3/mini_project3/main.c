/*
 * main.c
 *
 *  Created on: Jun 18, 2024
 *      Author: DELL
 */
#include "lcd.h"
#include "adc.h"
#include "lm35.h"
#include <util/delay.h> /* For the delay functions */
#include <avr/io.h> /* To use SREG register */
#include "motor.h"
int main(void){
	SREG |= (1<<7);/* Enable Global Interrupts */
	uint8 temp ;
	ADC_configType * config;
	config->prescaler = 2;
	config->ref_volt = 2;


	DcMotor_Init();
	LCD_init();
	ADC_init(config);

	LCD_displayStringRowColumn(0,3,"FAN is OFF");
	LCD_displayStringRowColumn(1,3,"Temp =    C");
	while(1){
    	temp = LM35_getTemperature();
		/* Display the temperature value every time at same position */
		LCD_moveCursor(1,10);
		if(temp >= 100)
		{
			LCD_intToString(temp);
		}
		else
		{
			LCD_intToString(temp);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayChar(' ');
		}
		LCD_moveCursor(0,10);
		if(temp < 30){
			DcMotor_Rotate(stop,100);
			LCD_displayString("OFF");
		}else if(temp < 60){
			DcMotor_Rotate(CW , 25);
			LCD_displayString("ON  ");
		}else if(temp < 90){
			DcMotor_Rotate(CW , 50);
			LCD_displayString("ON  ");
		}else if(temp < 120){
			DcMotor_Rotate(CW,75);
			LCD_displayString("ON  ");
		}else{
			DcMotor_Rotate(CW , 100);
			LCD_displayString("ON  ");
		}
	}
	return 0;
}
