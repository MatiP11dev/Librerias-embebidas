/*
 * FuncionesMath.h
 *
 *  Created on: Sep 9, 2021
 *      Author: Addg
 */

#ifndef INC_FUNCIONESMATH_H_
#define INC_FUNCIONESMATH_H_
#include "stdint.h"
typedef struct {
	uint8_t *datos;
	uint16_t cantidad;
	uint8_t v_inicial;
}FuncionesMath_EstructuraInicialTypedef;
typedef struct {
	uint8_t *datos;
	uint8_t cantidad;
	uint8_t valor;
}FuncionesMath_EstructuraGuardar;
typedef struct {
	uint8_t *datos;
	uint8_t cantidad;
	uint8_t valor;
}FuncionesMath_EstructuraExtraer;
uint8_t FuncionesMath_SumadorEnteros (uint8_t a, uint8_t b);
uint8_t FuncionesMath_Promedio8 (uint8_t *valores, uint16_t cantidad);
void FuncionesMath_InicializarBufferCeros(uint8_t *valores , uint16_t cantidad);
void FuncionesMath_InicializarBuffer(FuncionesMath_EstructuraInicialTypedef *s);
int8_t FuncionesMath_Sum_vector(int8_t *vector1,int8_t *vector2, uint16_t cantidad);
void FuncionesMath_vector_add(int8_t *resultado,int8_t *vector1,int8_t *vector2, uint16_t cantidad);
void FuncionesMath_vector_sub(int8_t *resultado,int8_t *vector1,int8_t *vector2, uint16_t cantidad);
int8_t FuncionesMath_Dot(int8_t *vector1,int8_t *vector2,int8_t cantidad);
int8_t det(int8_t **A);
uint8_t FuncionesContador(uint8_t *cnt);
void FuncionesMath_MarcarImpares(uint8_t *valores , uint16_t cantidad);
void FuncionesMath_almacenar(FuncionesMath_EstructuraGuardar *s);
#endif /* INC_FUNCIONESMATH_H_ */

