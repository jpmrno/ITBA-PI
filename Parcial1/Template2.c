//
//  Ej #.c
//  Programacion Imperativa
//
//  Created by Juan Moreno on 3/10/14.
//  Copyright (c) 2014 Juan Moreno. All rights reserved.
//

/* Ejercicio #

*/

#include <stdio.h>
#include "getnum.h"

#define TRUE 1
#define FALSE 0

#define FILS 4
#define COLS 3

void elimFila(int matriz[][COLS], int fils, int cols, int fila);
void cerosFila(int matriz[][COLS], int fila, int cols);

int main(void) {
	int matriz[][COLS] = {{1, 2, 2}, {2, 3, 4}, {3, 5, 6}, {1, 2, 3}};
	int fils = FILS;
	int cols = COLS;
	int i, j;
	for(i = 0; i < fils; i++) {
		for( j = 0; j < cols; j++) {
			printf("%d\t", matriz[i][j]);
		}
		putchar('\n');
	}
	putchar('\n');
	int fila = (getint("Que fila? ")) - 1;
	printf("%d", fila);
	putchar('\n');
	elimFila(matriz, fils, cols, fila);
	for(i = 0; i < fils; i++) {
		for( j = 0; j < cols; j++) {
			printf("%d\t", matriz[i][j]);
		}
		putchar('\n');
	}
}

void elimFila(int matriz[][COLS], int fils, int cols, int fila) {
	int i, j, k, iguales = TRUE;
	for( k = 0; k < fils; k++) {
		if(k != fila) {
			for(i = (k + 1); i < fils; i++) {
				for(j = 0; j < cols && iguales; j++) {
					if((matriz[k][j] + matriz[i][j]) == matriz[fila][j]) {
						iguales = TRUE;
					} else {
						iguales = FALSE;
					}
				}
			}
		}
	}
	if(iguales) {
		cerosFila(matriz, fila, cols);
	}
}

void cerosFila(int matriz[][COLS], int fila, int cols) {
	int i;
	for( i = 0; i < cols; i++) {
		matriz[fila][i] = 0;
	}
}
