/*
 * LedControl.h
 *
 *  Created on: Sep 26, 2021
 *      Author: matig
 */

#ifndef INC_LEDCONTROL_H_
#define INC_LEDCONTROL_H_


#include <stdio.h>
#include "stm32f1xx_hal.h"

/** Tipo de dato enumerado para la accion del led*/
typedef enum {
	LED_CONTROL_LED_APAGADO = 0,
	LED_CONTROL_LED_ENCENDIDO,
	LED_CONTROL_LED_BLINK
}LedControl_LedAccion_Typedef;
typedef enum {
	NORMAL_GND=0,
	NORMAL_VCC
}LedControl_NORMAL_Typedef;
/** Tipo de dato de los estados de la FSM*/
typedef enum {
	LED_CONTROL_ST_APAGADO_BLINK = 0,
	LED_CONTROL_ST_ENCENDIDO_BLINK,
	LED_CONTROL_ST_APAGADO,
	LED_CONTROL_ST_ENCENDIDO
}LedControl_LedEstados_Typedef;

/** Estructura base del TDA*/
typedef struct {
	LedControl_LedEstados_Typedef estado;
	LedControl_LedAccion_Typedef ctrl;
	uint32_t tiempo;
	uint32_t t1;
	uint32_t t2;
	uint16_t gpio_pin;
	GPIO_TypeDef * gpio_port;
	GPIO_PinState gpio_state_on;
	GPIO_PinState gpio_state_off;
}LedControl_BaseTypedef;
void LedControl_Init();
void LedControl_GPIO_Init(LedControl_BaseTypedef *s,GPIO_TypeDef *GPIO, uint16_t GPIO_PIN, LedControl_NORMAL_Typedef NORMAL);
void LedControl_Apagar(LedControl_BaseTypedef *s);
void LedControl_Encender(LedControl_BaseTypedef *s);
void LedControl_Proceso(LedControl_BaseTypedef *s);
void LedControl_blink(LedControl_BaseTypedef *s);
void LedControl_Tiempo_Off(LedControl_BaseTypedef *s, uint32_t tiempo);
void LedControl_Tiempo_On(LedControl_BaseTypedef *s,uint32_t tiempo);
#endif /* INC_LEDCONTROL_H_ */
