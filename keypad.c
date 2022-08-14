/*
 * keypad.c
 *
 *  Created on: Dec 27, 2021
 *      Author: matig
 */
#include<keypad.h>
/**
 * @brief Inicializa la maquina de estados
 * @param *s:estructura de datos Keypad
 * @retval None
 * */
void Keypad_init_fsm(keypad_Typedef*s){
	s->states=Row1;
	s->tiempo=HAL_GetTick();
}
/**
 * @brief Pone en funcionamiento la maquina de estados.
 * @param *s: estructura de datos del Keypad.
 * @retval None.
 * */
void Keypad_process_fsm(keypad_Typedef*s){
	switch (s->states) {
		case Row1:
			if(HAL_GPIO_ReadPin(s->GPIO_Port,s->GPIO_Pin_Col[0])==GPIO_PIN_SET){
				s->valor=key[0][0];
			}
			else if(HAL_GPIO_ReadPin(s->GPIO_Port,s->GPIO_Pin_Col[1])==GPIO_PIN_SET){
				s->valor=key[0][1];
			}
			else if(HAL_GPIO_ReadPin(s->GPIO_Port,s->GPIO_Pin_Col[2])==GPIO_PIN_SET){
				s->valor=key[0][2];
			}
			else if(HAL_GPIO_ReadPin(s->GPIO_Port,s->GPIO_Pin_Col[3])==GPIO_PIN_SET){
				s->valor=key[0][3];
			}
			if(HAL_GetTick()-s->tiempo>=s->t1){
				s->states=Row2;
			}
			break;
		case Row2:
			if(HAL_GPIO_ReadPin(s->GPIO_Port,s->GPIO_Pin_Col[0])==GPIO_PIN_SET){
				s->valor=key[1][0];
			}
			else if(HAL_GPIO_ReadPin(s->GPIO_Port,s->GPIO_Pin_Col[1])==GPIO_PIN_SET){
				s->valor=key[1][1];
			}
			else if(HAL_GPIO_ReadPin(s->GPIO_Port,s->GPIO_Pin_Col[2])==GPIO_PIN_SET){
				s->valor=key[1][2];
			}
			else if(HAL_GPIO_ReadPin(s->GPIO_Port,s->GPIO_Pin_Col[3])==GPIO_PIN_SET){
				s->valor=key[1][3];
			}
			if(HAL_GetTick()-s->tiempo>=s->t1){
				s->states=Row3;
			}
			break;
		case Row3:
			if(HAL_GPIO_ReadPin(s->GPIO_Port,s->GPIO_Pin_Col[0])==GPIO_PIN_SET){
				s->valor=key[2][0];
			}
			else if(HAL_GPIO_ReadPin(s->GPIO_Port,s->GPIO_Pin_Col[1])==GPIO_PIN_SET){
				s->valor=key[2][1];
			}
			else if(HAL_GPIO_ReadPin(s->GPIO_Port,s->GPIO_Pin_Col[2])==GPIO_PIN_SET){
				s->valor=key[2][2];
			}
			else if(HAL_GPIO_ReadPin(s->GPIO_Port,s->GPIO_Pin_Col[3])==GPIO_PIN_SET){
				s->valor=key[2][3];
			}
			if(HAL_GetTick()-s->tiempo>=s->t1){
				s->states=Row4;
			}
			break;
		case Row4:
			if(HAL_GPIO_ReadPin(s->GPIO_Port,s->GPIO_Pin_Col[0])==GPIO_PIN_SET){
				s->valor=key[3][0];
			}
			else if(HAL_GPIO_ReadPin(s->GPIO_Port,s->GPIO_Pin_Col[1])==GPIO_PIN_SET){
				s->valor=key[3][1];
			}
			else if(HAL_GPIO_ReadPin(s->GPIO_Port,s->GPIO_Pin_Col[2])==GPIO_PIN_SET){
				s->valor=key[3][2];
			}
			else if(HAL_GPIO_ReadPin(s->GPIO_Port,s->GPIO_Pin_Col[3])==GPIO_PIN_SET){
				s->valor=key[3][3];
			}
			if(HAL_GetTick()-s->tiempo>=s->t1){
				s->states=Row1;
			}
			break;
		default:
			break;
	}
}
