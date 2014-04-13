//
//  Ej 4.c
//  Programacion Imperativa
//
//  Created by Juan Moreno on 3/10/14.
//  Copyright (c) 2014 Juan Moreno. All rights reserved.
//

/* Ejercicio 4
Escribir una función que reciba un vector desordenado de números enteros y su dimensión, y construya otro vector eliminando los valores repetidos. La función deberá retornar en su nombre la dimensión del nuevo vector (La función solicitada no debe superar las 10 líneas).
*/

#include <stdio.h>
#include "getnum.h"

#define TRUE 1
#define FALSE 0

#define DIM 7

int deleteDuplicates(int array[], int dim);

int main(void) {
	int array[] = { 4, 2, -1, -12, 8, 2, 3 };
	int dim = (sizeof(array) / sizeof(array[0]));
	int i;
	for(i = 0; i < dim; i++) {
		printf("%d\t", array[i]);
	}
	putchar('\n');
	printf("Dim con repetidos: %d\n", dim);
	printf("Dim sin repetidos: %d\n", deleteDuplicates(array, dim));
}

/*int deleteDuplicates(int array[], int dim) {
	int noDuplicate[dim], i, j, equal = 0, dif = TRUE;
	for(i = 0; i < dim; i++) {
		for(j = 0; j < i && dif; j++) {
			if(array[i] == array[j]) {
				dif = FALSE;
				equal+= 1;
			}
		}
		if(dif) {
			noDuplicate[i] = array[i];
			printf("%d\t", array[i]);
		}
		dif = TRUE;
	}
	putchar('\n');
	return dim-equal;
}*/

int deleteDuplicates(int array[], int dim) {
	int noDuplicate[DIM];
	int i, h, j = 0, dif = TRUE;
	for(i = 0; i < dim; i++) {
		noDuplicate[j] = array[i];
		for( h = 0; h < j && dif; h++) {
			if(noDuplicate[j] == noDuplicate[h]) {
				dif = FALSE;
			}
		}
		if(dif) {
			j++;
		}
		dif = TRUE;
	}
	for(i = 0; i < j; i++) {
		printf("%d\t", noDuplicate[i]);
	}
	putchar('\n');
	return j;
}
