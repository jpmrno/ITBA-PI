//
//  Ej #.c
//  Programacion Imperativa
//
//  Created by Juan Moreno on 3/10/14.
//  Copyright (c) 2014 Juan Moreno. All rights reserved.
//

/* Ejercicio #
Escribir una función que reciba como parámetros
• matriz: una matriz de enteros
• filas: la cantidad de filas reales de la matriz
• cols: la cantidad de columnas reales de la matriz
• fila: un número entero que indica la fila a tratar

La función debe completar con el valor 0 la fila indicada por el parámetro fila
si la misma resulta de sumar otro par de filas cualquiera.
La cantidad de columnas con la que se define la matriz está dada por la constante 
simbólica COLS
*/

#include <stdio.h>
#include "getnum.h"

#define COLUMNAS 4
#define FILAS 4

int CeroSiSumFilas(int matriz[][COLUMNAS], int fils, int cols, int fila);
void filaCeros(int matriz[][COLUMNAS], int cols, int fila);
int compareSumFil(int matriz[][COLUMNAS], int fils, int cols, int fila, int i);

int main(void) {
	int matriz[][COLUMNAS] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 8, 7, 5}, {6, 8, 10, 12} };
	int fils = FILAS, cols = COLUMNAS;
	int i, j, fila;
	for( i = 0; i < fils; i++) {
		for( j = 0; j < cols; j++) {
			printf("%d\t", matriz[i][j]);
		}
		putchar('\n');
	}
	putchar('\n');
	fila = (getint("Que fila quieres analizar? ") - 1);
	if(CeroSiSumFilas(matriz, fils, cols, fila)) {
		for( i = 0; i < fils; i++) {
			for( j = 0; j < cols; j++) {
				printf("%d\t", matriz[i][j]);
			}
			putchar('\n');
		}
	}
}

int CeroSiSumFilas(int matriz[FILAS][COLUMNAS], int fils, int cols, int fila) {
	int i;
	for( i = 0; i < fils; i++) {
		if(i != fila) {
			if(compareSumFil(matriz, fils, cols, fila, i)){
				filaCeros(matriz, cols, fila);
				return 1;
			}
		}
	}
	return 0;
}

void filaCeros(int matriz[][COLUMNAS], int cols, int fila) {
	int i;
	for( i = 0; i < cols; i++) {
		matriz[fila][i] = 0;
	}
}

// otra forma es comparar solo las columnas en esta funcion y devolver cuantas son iguales a la matriz[fila][i]
int compareSumFil(int matriz[][COLUMNAS], int fils, int cols, int fila, int i) {
	int j, k, iguales = 0;
	for( j = (i + 1); j < fils; j++) {
		if(j != fila) {	
			for( k = 0; k < cols; k++) {
				if(matriz[fila][k] == (matriz[i][k] + matriz[j][k])){
					iguales++;
				}
			}
			if(iguales == cols) {
				return 1;
			} else 
				iguales = 0;
		}
	}
	return 0;
}

