//
//  Ej 11.c
//  Programacion Imperativa
//
//  Created by Juan Moreno on 3/10/14.
//  Copyright (c) 2014 Juan Moreno. All rights reserved.
//

/* Ejercicio 11
Escribir una función que ordene las filas de una matriz de cualquier tamaño, según el valor de una determinada columna. La función recibirá como parámetros la matriz, la cantidad de filas, la cantidad de columnas y el número de columna a tomar como clave de ordenación, teniendo en cuenta que la primer columna es la columna 1 (uno).
*/

#include <stdio.h>
#include "getnum.h"

#define FILAS 4
#define COLUMNAS 5

#define TRUE 1
#define FALSE 0

void orderRow(int matriz[FILAS][COLUMNAS], int fils, int cols, int colSwap);
void swapRow(int matriz[FILAS][COLUMNAS], int fil1, int fil2, int cols);

int main(void) {
	int matriz[FILAS][COLUMNAS] = {{1,2,3,4,5},{6,7,8,9,10},{3,5,8,2,1},{8,1,3,6,7}};
	int fils = FILAS, cols = COLUMNAS;
	int colSwap;
	int i, j;

	colSwap = (getint("Introducir la fila por la cual ordenar: ") - 1);
	for(i = 0; i < fils; i++) {
		for(j = 0; j < cols; j++) {
			printf("%d\t", matriz[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	orderRow(matriz, fils, cols, colSwap);
	for(i = 0; i < fils; i++){
		for(j = 0; j < cols; j++) {
			printf("%d\t", matriz[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void orderRow(int matriz[FILAS][COLUMNAS], int fils, int cols, int colSwap) {
	int i, j, minor, n;
	for(i = 0; i < fils; i++) {
		minor = i;
		for(j = (i + 1); j < fils; j++) {
			if(matriz[j][colSwap] < matriz[minor][colSwap]) {
				minor = j;
			}
		}
		// estoy swapeando la ultima por la ultima me parece.
		swapRow(matriz, i, minor, cols);
	}
}

void swapRow(int matriz[FILAS][COLUMNAS], int fil1, int fil2, int cols) {
	int i, aux;
	for(i = 0; i < cols; i++) {
		aux = matriz[fil1][i];
		matriz[fil1][i] = matriz[fil2][i];
		matriz[fil2][i] = aux;
	}
}
