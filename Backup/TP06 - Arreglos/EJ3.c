//
//  Ej 3.c
//  Programacion Imperativa
//
//  Created by Juan Moreno on 3/10/14.
//  Copyright (c) 2014 Juan Moreno. All rights reserved.
//

/* Ejercicio 3
Dado un arreglo lineal de números reales, cuyo indicador de fin de
elementos es cero, escribir una función para obtener la mayor
diferencia entre dos elementos consecutivos. (En no más de 5 líneas).
Tener en cuenta que los números pueden ser negativos. En caso de que el
vector tenga un solo elemento deberá retornar como diferencia el valor
cero.

*/

#include <stdio.h>
#include "getnum.h"

#define EOA 0
#define MODULO(x) ((x) >= 0? x: -x)

float mayorDif(float arrayLineal[]);

int main(void) {
	float arrayLineal[] = { 2, 2, -1, -16.5, -8, EOA };
	printf("La mayor diferencia es: %f\n", mayorDif(arrayLineal));
}

float mayorDif(float arrayLineal[]) {
	float mayor, mayorTemp;
	int i;
	mayor = mayorTemp = 0;
	for ( i = 0; arrayLineal[i+1] != 0; i++) {
		mayorTemp = arrayLineal[i] - arrayLineal[i+1];
		mayorTemp = MODULO(mayorTemp);
		if(mayorTemp > mayor)
			mayor = mayorTemp;
	}
	return mayor;
}
