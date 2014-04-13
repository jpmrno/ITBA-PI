//
//  Ej 12.c
//  Programacion Imperativa
//
//  Created by Juan Moreno on 3/10/14.
//  Copyright (c) 2014 Juan Moreno. All rights reserved.
//

/* Ejercicio 12
Escribir una función que cambie una matriz cuadrada por su traspuesta, recibiendo
sólo los siguientes 2 parámetros:
• la matriz cuadrada
• un número entero positivo que indique la dimensión de la matriz
Dicha función debe hacer la conversión sobre la misma matriz recibida, sin usar
vectores auxiliares.
Nota: La traspuesta de una matriz se obtiene cambiando cada elemento Aij por el
elemento Aji.
*/

#include <stdio.h>

#define DIM 3

void traspuesta(int matriz[DIM][DIM], int dim);

int main(void) {
	int matriz[DIM][DIM] = {{1,2,3},{4,5,6},{7,8,9}};
	int dim = DIM;
	int i, j;
	printf("Matriz:\n");
	for(i = 0; i < DIM; i++) {
		for(j = 0; j < DIM; j++) {
			printf("%d\t", matriz[i][j]);
		}
		printf("\n");
	}
	traspuesta(matriz, dim);
	printf("\nTraspuesta:\n");
	for(i = 0; i < DIM; i++) {
		for(j = 0; j < DIM; j++) {
			printf("%d\t", matriz[i][j]);
		}
		printf("\n");
	}
}

void traspuesta(int matriz[DIM][DIM], int dim) {
	int i, j, aux;
	for(i = 0; i < dim; i++) {
		for(j = 0; j <= i; j++) {
			aux = matriz[i][j];
			matriz[i][j] = matriz[j][i];
			matriz[j][i] = aux;
		}
	}
}
