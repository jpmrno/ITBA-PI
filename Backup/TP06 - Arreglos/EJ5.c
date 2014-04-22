//
//  Ej 5.c
//  Programacion Imperativa
//
//  Created by Juan Moreno on 3/10/14.
//  Copyright (c) 2014 Juan Moreno. All rights reserved.
//

/* Ejercicio 5
Escribir una función que reciba un vector ordenado de números enteros y su dimensión, y construya otro vector eliminando los valores repetidos. La función deberá retornar en su nombre la dimensión del nuevo vector (La función solicitada no debe superar las 10 líneas).
*/

#include <stdio.h>
#include "getnum.h"

#define TRUE 1
#define FALSE 0

#define DIM 7

int deleteDuplicates(int array[], int dim);

int main(void) {
	int array[] = { 1, 2, 2, 2, 6, 7, 7 };
	int dim = (sizeof(array) / sizeof(array[0]));
	int i;
	for(i = 0; i < dim; i++) {
		printf("%d\t", array[i]);
	}
	putchar('\n');
	printf("Dim con repetidos: %d\n", dim);
	printf("Dim sin repetidos: %d\n", deleteDuplicates(array, dim));
}

int deleteDuplicates(int array[], int dim) {
	int noDuplicate[DIM];
	int i, j = 1;
	noDuplicate[0] = array[0];
	for(i = 1; i < dim; i++) {
		noDuplicate[j] = array[i];
		if(noDuplicate[j] != noDuplicate[j-1]) {
			j++;
		}
	}
	for(i = 0; i < j; i++) {
		printf("%d\t", noDuplicate[i]);
	}
	putchar('\n');
	return j;
}
