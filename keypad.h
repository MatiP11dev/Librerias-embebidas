/*
 * keypad.h
 *
 *  Created on: Dec 27, 2021
 *      Author: matig
 */

#ifndef INC_KEYPAD_H_
#define INC_KEYPAD_H_
#include <stdio.h>
#include <stm32f1xx.h>
/**
 * @brief enumeracion de estados seguen el numero de filas filas
 * */
typedef enum{
	Row1,
	Row2,
	Row3,
	Row4
}keypadStates_typedef;
/**
 * @brief estructura de keypad
 * */
typedef struct{
	uint16_t GPIO_Pin_Col[4];//numero de pines columnas
	uint16_t GPIO_Pin_Row[4];//numero de pines
	char key[4][4];//matriz de caracteres
	char valor;//retorna el valor
	uint32_t tiempo;//carga el tiempo
	uint32_t t1;//retardo del pad
	GPIO_TypeDef* GPIO_Port;// puerto de los pines
	keypadStates_typedef states;
}keypad_Typedef;
void Keypad_init_fsm(keypad_Typedef*s);
void Keypad_process_fsm(keypad_Typedef*s);
void keypad_init();
void keypad_getKey();
#endif /* INC_KEYPAD_H_ */
