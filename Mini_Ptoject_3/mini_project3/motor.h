/*
 * motor.h
 *
 *  Created on: Jun 19, 2024
 *      Author: DELL
 */

#ifndef MOTOR_H_
#define MOTOR_H_
typedef enum{
	CW,
	ACW,
	stop,
}DcMotor_State;

void DcMotor_Init(void);
void DcMotor_Rotate(DcMotor_State state,uint8 speed);

#endif /* MOTOR_H_ */
