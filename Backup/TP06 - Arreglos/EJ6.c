//
//  Ej 6.c
//  Programacion Imperativa
//
//  Created by Juan Moreno on 3/10/14.
//  Copyright (c) 2014 Juan Moreno. All rights reserved.
//

/* Ejercicio 6
Dado un arreglo ordenado ascendentemente se pide escribir una función
que reciba como parámetro de entrada/salida el arreglo y como parámetro
de entrada su dimensión y que lo devuelva desordenado, simulando la
mezcla de un mazo de cartas o de un bolillero (en no más de 10 líneas).
*/

#include <stdio.h>
#include "getnum.h"
#include <stdlib.h>
#include <time.h>

#define VUELTAS (dim * 3)

void randomiceArray(int arrayInicial[], int dim);
double randNormalize(void);


int main(void) {

	srand(time(NULL));
	int i;
	int arrayInicial[] = { 2, 5, 7, 9, 15, 32, 45};
	int dim = (sizeof(arrayInicial)/sizeof(arrayInicial[0]));

	printf("Vector inicial: ");
	for(i = 0; i < dim; i++) {
		printf("%d\t", arrayInicial[i]);
	}
	randomiceArray(arrayInicial, dim);
	printf("\nVector random:  ");
	for(i = 0; i < dim; i++) {
		printf("%d\t", arrayInicial[i]);
	}
	printf("\n");
}

void randomiceArray( int arrayInicial[], int dim) {
	int j, randNum1, randNum2, oldElement;

	for( j = 0; j < VUELTAS; j++) {
		randNum1 = (int) (randNormalize() * (dim));
		randNum2 = (int) (randNormalize() * (dim));
		oldElement = arrayInicial[randNum2];
		arrayInicial[randNum2] = arrayInicial[randNum1];
		arrayInicial[randNum1] = oldElement;
	}

}

double randNormalize(void) {
	return rand() / ((double) RAND_MAX + 1);
}
