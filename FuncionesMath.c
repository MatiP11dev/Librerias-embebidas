/*
 * FuncionesMath.c
 *
 *  Created on: Sep 9, 2021
 *      Author: Addg.
 */

#include "FuncionesMath.h"

/*Prototipos de funciones publicas*/
uint8_t FuncionesMath_SumadorEnteros (uint8_t a, uint8_t b);
uint8_t FuncionesMath_Promedio8 (uint8_t *valores, uint16_t cantidad);
void FuncionesMath_InicializarBufferCeros(uint8_t *valores , uint16_t cantidad);
int8_t FuncionesMath_Sum_vector(int8_t *vector1,int8_t *vector2, uint16_t cantidad);
void FuncionesMath_vector_add(int8_t *resultado,int8_t *vector1,int8_t *vector2, uint16_t cantidad);
void FuncionesMath_vector_sub(int8_t *resultado,int8_t *vector1,int8_t *vector2, uint16_t cantidad);
int8_t FuncionesMath_Dot(int8_t *vector1,int8_t *vector2,int8_t cantidad);
int8_t det(int8_t **A);
uint8_t FuncionesContador(uint8_t *cnt);
void FuncionesMath_MarcarImpares(uint8_t *valores , uint16_t cantidad);
/*Funciones*/

/**
 * @brief Suma dos enteros de 8 bits no signados
 * @param a primer operador
 * @param b segundo operador
 * @retval Devuelve a + b en entero de 8 bits.
 */
uint8_t FuncionesMath_SumadorEnteros (uint8_t a, uint8_t b)
{
	return a + b;
}

uint8_t FuncionesMath_Promedio8 (uint8_t *valores , uint16_t cantidad)
{
	uint8_t promedio = 0;
	uint16_t aux = 0;
	uint16_t i;

	for (i = 0 ; i < cantidad ; i++)
	{
		aux = aux + valores[i];
	}
	promedio = aux / cantidad;


	return promedio;
}

void FuncionesMath_InicializarBufferCeros(uint8_t *valores , uint16_t cantidad)
{
	uint16_t i;

	for (i = 0 ; i < cantidad ; i++)
	{
		valores[i] = 0;
	}
}
void FuncionesMath_InicializarBuffer(FuncionesMath_EstructuraInicialTypedef *s){
	uint16_t i;

	for (i = 0 ; i < s->cantidad ; i++)
	{
		s->datos[i] = s->v_inicial;
	}
}
int8_t FuncionesMath_Sum_vector(int8_t *vector1,int8_t *vector2, uint16_t cantidad){
	int8_t resultado=0;
	for(uint8_t i=0;i<cantidad;i++){
	        	resultado=resultado+vector1[i]+vector2[i];
	}
	return resultado;
}
void FuncionesMath_vector_add(int8_t *resultado,int8_t *vector1,int8_t *vector2, uint16_t cantidad){
	FuncionesMath_InicializarBufferCeros(resultado,cantidad);
	for(uint8_t i=0;i<cantidad;i++){
		        	resultado[i]=resultado[i]+vector1[i]+vector2[i];
		}
}
void FuncionesMath_vector_sub(int8_t *resultado,int8_t *vector1,int8_t *vector2, uint16_t cantidad){
	FuncionesMath_InicializarBufferCeros(resultado,cantidad);
	for(uint8_t i=0;i<cantidad;i++){
		        	resultado[i]=resultado[i]+vector1[i]-vector2[i];
		}
}
int8_t FuncionesMath_Dot(int8_t *vector1,int8_t *vector2,int8_t cantidad){
	int8_t resultado=0;
	for(uint8_t i=0;i<cantidad;i++){
	        	resultado=resultado+vector1[i]*vector2[i];
	}
	return resultado;
}
int8_t det(int8_t **matriz){
    int8_t len=3;
    int8_t aux=6;
    int8_t matriz2[6][3];
    int8_t counter=0;
    int8_t mul=1;
    int8_t D=0;
    int8_t m_aux;
    for(uint8_t i=0;i<6;i++){
        for(uint8_t j=0;j<3;j++){
        	m_aux=matriz[counter][j];
            matriz2[i][j]=m_aux;
            counter=counter+1;
        }
        if(counter>=len){
            counter=0;
        }
    }
    for(uint8_t k=0;k<len;k++){
       for(uint8_t i=0;i<len;i++){
           mul=matriz2[i+k][i]*mul;
        }
        D=mul+D;
        mul=1;
    }
     for(uint8_t k=0;k<len;k++){
       for(uint8_t i=0;i<len;i++){
           mul=matriz2[i+k][2-i]*mul;
        }
        D=D-mul;
        mul=1;
    }
    return D;
}
uint8_t FuncionesContador(uint8_t *cnt)
{
	uint8_t aux;

	aux = (*cnt)++;

	if (aux > 255)
	{
		*cnt = 0;
	}
	return (*cnt);
}
void FuncionesMath_MarcarImpares(uint8_t *valores , uint16_t cantidad)
{
	uint16_t i;
	uint8_t *ptr = valores;

	ptr += 1;
	for (i = 0 ; i < cantidad ; i++)
	{
		*ptr = 255;
		ptr += 2;
	}
}
void FuncionesMath_almacenar(FuncionesMath_EstructuraGuardar *s){
	*(s->datos)=s->valor;
	 s->datos=s->datos+1;
}
