//
//  Ej #.c
//  Programacion Imperativa
//
//  Created by Juan Moreno on 3/10/14.
//  Copyright (c) 2014 Juan Moreno. All rights reserved.
//

/* Ejercicio #
Reemplaza por 0 los elementos del cuadrante con mayor promedio.
*/

#include <stdio.h>
#include "getnum.h"

#define DIM 4
#define CUADRANTES 4

void mayorCuadrante(int matriz[DIM][DIM], int fil, int col);
void retCeros(int matriz[DIM][DIM], int dim, int cuadrante);
int sumCuadrante(int matriz[DIM][DIM], int dim, int cuadrante);

int main(void) {
	int matriz[DIM][DIM] = {{9, 8, 9, 9}, {9, 9, 6, 7}, {8, 9, 9, 9}, {4, 6, 9, 9}};
	int fil, col;
	int i, j;

	fil = col = DIM;
	for( i = 0; i < fil; i++) {
		for( j = 0; j < col; j++) {
			printf("%d\t", matriz[i][j]);
		}
		putchar('\n');
	}
	putchar('\n');

	mayorCuadrante(matriz, fil, col);
	for( i = 0; i < fil; i++) {
		for( j = 0; j < col; j++) {
			printf("%d\t", matriz[i][j]);
		}
		putchar('\n');
	}
}

void mayorCuadrante(int matriz[DIM][DIM], int fil, int col) {
	int mayor = 0, i, suma, cuadranteM;
	for( i = 1; i <= CUADRANTES; i++) {
		if((suma = sumCuadrante(matriz, fil, i)) >= mayor) {
			mayor = suma;
			cuadranteM = i;
		}
	}
	retCeros(matriz, fil, cuadranteM);
}

void retCeros(int matriz[DIM][DIM], int dim, int cuadrante) {
	int i, j, col, fil, desdeFil, desdeCol;

	switch(cuadrante) {
		case 1:
			desdeFil = 0;
			desdeCol = 0;
			break;
		case 2:
			desdeFil = 0;
			desdeCol = (dim/2);
			break;
		case 3:
			desdeFil = (dim/2);
			desdeCol = 0;
			break;
		case 4:
			desdeFil = (dim/2);
			desdeCol = (dim/2);
			break;
	}
	fil = (dim/2) + desdeFil;
	col = (dim/2) + desdeCol;
	for( i = desdeFil; i < fil; i++) {
		for( j = desdeCol; j < col; j++) {
			matriz[i][j] = 0;
		}
	}
}

int sumCuadrante(int matriz[DIM][DIM], int dim, int cuadrante) {
	int i, j, suma = 0, col, fil, desdeFil, desdeCol;

	switch(cuadrante) {
		case 1:
			desdeFil = 0;
			desdeCol = 0;
			break;
		case 2:
			desdeFil = 0;
			desdeCol = (dim/2);
			break;
		case 3:
			desdeFil = (dim/2);
			desdeCol = 0;
			break;
		case 4:
			desdeFil = (dim/2);
			desdeCol = (dim/2);
			break;
	}
	fil = (dim/2) + desdeFil;
	col = (dim/2) + desdeCol;
	for( i = desdeFil; i < fil; i++) {
		for( j = desdeCol; j < col; j++) {
			suma+= matriz[i][j];
		}
	}
	return suma;
}
