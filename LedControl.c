/*
 * LedControl.c
 *
 *  Created on: 23 sept. 2021
 *      Author: Matias Ponce
 */
/**@file   :LedControl.c
 * @brief  :Controlar el tiempo y los estados de prendido y apagado del led.
 */

#include "LedControl.h"
#include "stm32f1xx_hal.h"
#include "stdio.h"
void LedControl_Init(LedControl_BaseTypedef *s);
void LedControl_Proceso(LedControl_BaseTypedef *s);
/**@brief :Inicia la maquina de estados.
 * @param s: es un puntero a la enum de maquina de estados.
 * @attention antes debera inicializar los GPIO con la funcion LedControl_GPIO_Init().
 * @retval nada
 */
void LedControl_Init(LedControl_BaseTypedef *s) {
	s->ctrl = LED_CONTROL_LED_BLINK;
	s->tiempo = HAL_GetTick();//obtiene el valor del systick timer
	s->estado = LED_CONTROL_ST_APAGADO_BLINK;
	HAL_GPIO_WritePin(s->gpio_port, s->gpio_pin, s->gpio_state_off);//apagar
}
/**@brief Proceso de control de led.
 *@param *s: es un puntero a la lista de estados de la maquina de estados.
 *@retval None.
 **/
void LedControl_Proceso(LedControl_BaseTypedef *s) {
	switch (s->estado) {
	case LED_CONTROL_ST_APAGADO_BLINK:
		HAL_GPIO_WritePin(s->gpio_port, s->gpio_pin, s->gpio_state_off);
		if (HAL_GetTick()-s->tiempo >= s->t1) {
			s->estado = LED_CONTROL_ST_ENCENDIDO_BLINK;//cambia a estado de apagado del led parpadeo
			s->tiempo = HAL_GetTick();
		} else if (s->ctrl == LED_CONTROL_LED_ENCENDIDO) {
			s->estado = LED_CONTROL_ST_ENCENDIDO;//pasa al estado del led ecendido de forma constante
		} else if (s->ctrl == LED_CONTROL_LED_APAGADO) {
			s->estado = LED_CONTROL_ST_APAGADO;//pasa al estado del led apagado constantemente
		}
		break;
	case LED_CONTROL_ST_ENCENDIDO_BLINK:
		HAL_GPIO_WritePin(s->gpio_port, s->gpio_pin, s->gpio_state_on);
		if (HAL_GetTick()-s->tiempo >= s->t2) {
			s->estado = LED_CONTROL_ST_APAGADO_BLINK;
			s->tiempo = HAL_GetTick();
		}
		  else if (s->ctrl == LED_CONTROL_LED_ENCENDIDO) {
			s->estado = LED_CONTROL_ST_ENCENDIDO;//pasa al estado del led ecendido de forma constante
		} else if (s->ctrl == LED_CONTROL_LED_APAGADO) {
			s->estado = LED_CONTROL_ST_APAGADO;
		}
		break;
		case LED_CONTROL_ST_APAGADO:
			HAL_GPIO_WritePin(s->gpio_port,s->gpio_pin, s->gpio_state_off);//funcion para setear el estado del puerto.
			if(s->ctrl==LED_CONTROL_LED_BLINK){
				s->estado=LED_CONTROL_ST_APAGADO_BLINK;
			}
			else if(s->ctrl==LED_CONTROL_LED_ENCENDIDO){
				s->estado=LED_CONTROL_ST_ENCENDIDO;//pasa al estado del led ecendido de forma constante
			}
		break;
		case LED_CONTROL_ST_ENCENDIDO:
			HAL_GPIO_WritePin(s->gpio_port,s->gpio_pin, s->gpio_state_on);
			if(s->ctrl==LED_CONTROL_LED_BLINK){
				  s->estado=LED_CONTROL_ST_APAGADO_BLINK;//cambia a estado de apagado del led parpadeo
			}
			else if(s->ctrl==LED_CONTROL_LED_APAGADO){
			     s->estado=LED_CONTROL_ST_APAGADO;//pasa al estado del led ecendido de forma constante
			}
		break;
	default:
		break;
	}
}
/**
 * @brief :Inicia los valores predetirminados del GPIO
 * @param *s: es la estructura del ledControl_base
 * @param *GPIO: es un puntero a la direccion del puerto
 * @param GPIO_PIN: es el numero del pin del puerto de salida
 * @param bool: booleano para configurar el estado del pin en "NORMAL_GND"('0' es apagado y '1' es encendido)
 * , si esta en "NORMAL_VCC"('0' es encendido y '1' es apagado).
 * @retval None
 * */
void LedControl_GPIO_Init(LedControl_BaseTypedef *s,GPIO_TypeDef *GPIO, uint16_t GPIO_PIN, LedControl_NORMAL_Typedef NORMAL){
	s->gpio_port=GPIO;//carga el valor de GPIO a la estructura
	s->gpio_pin=GPIO_PIN;//carga el valor de GPIO-PIN a la estructura
	s->t1=500;//el tiempo de apagado del led en 500 segundos como predeterminado
	s->t2=500;//el tiempo de encendido del led en 500 segundos como predeterminado
	if(NORMAL==NORMAL_GND){
		s->gpio_state_off=GPIO_PIN_RESET;//esta apagado cuando se pone en 0 el puerto de salida
		s->gpio_state_on=GPIO_PIN_SET;//esta prendido cuando se pone en 1 el puerto de salida
	}
	else if(NORMAL==NORMAL_VCC){
			s->gpio_state_off=GPIO_PIN_SET;//esta apagado cuando se pone en 1 el puerto de salida
			s->gpio_state_on=GPIO_PIN_RESET;//esta prendido cuando se pone en 0 el puerto de salida
		}
}
/**
 * @brief: funcion para apagar el led.
 * @param *s:puntero estructura de datos del ledControl.
 * @retval None
 * */
void LedControl_Apagar(LedControl_BaseTypedef *s){
	s->ctrl=LED_CONTROL_LED_APAGADO;
}
/**
 * @brief: funcion para prender el led.
 * @param *s:puntero estructura de datos del ledControl.
 * @retval None
 * */
void LedControl_Encender(LedControl_BaseTypedef *s){
	s->ctrl=LED_CONTROL_LED_ENCENDIDO;
}
/**
 * @brief: funcion para parpadear el led.
 * @param *s:puntero estructura de datos del ledControl.
 * @retval None
 * */
void LedControl_blink(LedControl_BaseTypedef *s){
	s->ctrl=LED_CONTROL_LED_BLINK;
}
/**
 * @brief: modifica el tiempo en que esta apagado.
 * @param *s: estructura de datos del led.
 * @param tiempo: tiempo que esta apagado el led.
 * @retval None
 * */
void LedControl_Tiempo_Off(LedControl_BaseTypedef *s, uint32_t tiempo){
	s->t1=tiempo;
}
/**
 * @brief: modifica el tiempo en que esta encendido.
 * @param *s: estructura de datos del led.
 * @param tiempo: tiempo que esta encendido el led.
 * @retval None
 * */
void LedControl_Tiempo_On(LedControl_BaseTypedef *s,uint32_t tiempo){
	s->t2=tiempo;
}
/**
 * @brief: modifica el periodo.
 * @param *s: estructura de datos del led.
 * @param tiempo: periodo de tiempo.
 * @retval None
 * */
void LedControl_Periodo(LedControl_BaseTypedef *s,uint32_t tiempo){
	s->t1=tiempo/2;
	s->t2=tiempo/2;
}
