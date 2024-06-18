/*
 * lcd.h
 *
 *  Created on: Jun 14, 2024
 *      Author: Ahmed Ali
 */

#ifndef LCD_H_
#define LCD_H_

#include "std_types.h"


#define RS_pin   	 PIN0_ID
#define RS_port 	 PORTD_ID

#define RW_pin   	 PIN1_ID
#define RW_port 	 PORTD_ID

#define E_pin   	 PIN2_ID
#define E_port 	 	 PORTD_ID

#define Data_portId	 PORTC_ID

/* LCD Commands */
#define LCD_CLEAR_COMMAND                    0x01
#define LCD_GO_TO_HOME                       0x02
#define LCD_TWO_LINES_EIGHT_BITS_MODE        0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE         0x28
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT1   0x33
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT2   0x32
#define LCD_CURSOR_OFF                       0x0C
#define LCD_CURSOR_ON                        0x0E
#define LCD_SET_CURSOR_LOCATION              0x80

void LCD_init(void);
void LCD_sendCommand(uint8 command);
void LCD_displayChar(uint8 byte);
void LCD_displayString(const char* str);
void LCD_moveCursor(uint8 row, uint8 col);
void LCD_displayStringRowColumn(uint8 row, uint8 col, const char* str);
void LCD_clearScreen(void);
void LCD_intToString(int data);

#endif /* LCD_H_ */
