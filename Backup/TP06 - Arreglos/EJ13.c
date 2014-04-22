//
//  Ej 13.c
//  Programacion Imperativa
//
//  Created by Juan Moreno on 3/10/14.
//  Copyright (c) 2014 Juan Moreno. All rights reserved.
//

/* Ejercicio 13
Escribir una función que realice el producto de dos matrices cuadradas y lo
devuelva en una tercera. El algoritmo de la función que realiza el producto
no debe tener más de dos ciclos for anidados explícitamente, pero sí puede
utilizar funciones auxiliares que contengan ciclos (Ninguna de las funciones
debe superar las 5 líneas).
*/

#include <stdio.h>

#define DIM 3

void productoMatriz(int matriz1[DIM][DIM], int matriz2[DIM][DIM], int producto[DIM][DIM]);
int sumaProducto(int matriz1[DIM][DIM], int matriz2[DIM][DIM], int i, int j);

int main(void) {
	int matriz1[DIM][DIM] = {{1,2,3},{3,2,1},{2,1,3}};
	int matriz2[DIM][DIM] = {{4,5,6},{6,5,4},{4,6,5}};
	int producto[DIM][DIM];
	int i, j;
	productoMatriz( matriz1, matriz2, producto);
	for(i = 0; i < DIM; i++) {
		for(j = 0; j < DIM; j++) {
			printf("%d\t", producto[i][j]);
		}
		printf("\n");
	}
}

void productoMatriz(int matriz1[DIM][DIM], int matriz2[DIM][DIM], int producto[DIM][DIM]) {
	int i, j;
	for(i = 0; i < DIM; i++) {
		for(j = 0; j < DIM; j++) {
			producto[i][j] = sumaProducto(matriz1, matriz2, i, j);
		}
	}
}

int sumaProducto(int matriz1[DIM][DIM], int matriz2[DIM][DIM], int i, int j) {
	int r, sumatoria = 0;
	for(r = 0; r < DIM; r++) {
		sumatoria+= matriz1[i][r] * matriz2[r][j];
	}
	return sumatoria;
}
