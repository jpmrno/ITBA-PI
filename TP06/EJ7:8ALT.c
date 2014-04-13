//
//  Ej 7.c
//  Programacion Imperativa
//
//  Created by Juan Moreno on 3/10/14.
//  Copyright (c) 2014 Juan Moreno. All rights reserved.
//

/* Ejercicio 7

INTERSECCION en vez de union.

Hacer una función que reciba dos parámetros de entrada representando arreglos de números enteros positivos, ordenados en forma ascendente y sin elementos repetidos. El último elemento de cada arreglo es -1. La función debe devolver en un tercer parámetro de salida un arreglo ordenado con la unión de los dos primeros, también terminado en -1.
*/

#include <stdio.h>

#define EOA -1
#define DIM 12
#define TRUE 1
#define FALSE 0

void interseccionA(int array1[], int array2[], int intA[]);

int main(void) {
	// que pasa si pongo unsigned int?
	int array1[] = {1, 2, 3, 3, 4, 5, 7, 7, EOA};
	int array2[] = {3, 4, 5, 6, 7, 9, 10, 11, EOA};
	int resultado[DIM], i;
	interseccionA(array1, array2, resultado);
	for(i = 0; array1[i] != EOA; i++) {
		printf("%d\t", array1[i]);
	}
	putchar('\n');
	for(i = 0; array2[i] != EOA; i++) {
		printf("%d\t", array2[i]);
	}
	putchar('\n');
	for(i = 0; resultado[i] != EOA; i++) {
		printf("%d\t", resultado[i]);
	}
	putchar('\n');
}

void interseccionA(int array1[], int array2[], int resultado[]) {
	int trueDim = 0, j = 0, i = 0, iguales;

	while((array1[i] != EOA) && (array2[j] != EOA)) {
		iguales = (array1[i] == array2[j])?TRUE:FALSE;
		switch(iguales) {
			case TRUE:
				resultado[trueDim++] = array1[i];
				j++;
				i++;
				break;
			case FALSE:
				if(array1[i] < array2[i]) {
					i++;
				} else {
					j++;
				}
				break;
		}
	}
	resultado[trueDim] = EOA;
}
