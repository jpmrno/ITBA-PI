//
//  Ej 10.c
//  Programacion Imperativa
//
//  Created by Juan Moreno on 3/10/14.
//  Copyright (c) 2014 Juan Moreno. All rights reserved.
//

/* Ejercicio 10
Los laboratorios de Propulsión por Reacción tienen la representación del cielo y
sus estrellas, digitalizada en una matriz bidimensional de hasta 80 columnas por
20 filas. Cada elemento de la misma representa la cantidad de luz que hay en una
zona del cielo con un rango de intensidad entre 0 y 20. En el lugar de coordenadas
(i,j) del cielo se considera que hay una estrella si el elemento Aij correspondiente
cumple con la siguiente relación:

( A[i,j] + suma de las ocho intensidades circundantes ) / 9 > 10

Escribir una función (en no más de 15 líneas) que reciba tres parámetros de entrada representando a una matriz de dichas características y sus dimensiones. Dicha función debe localizar gráficamente las estrellas en la pantalla representando las mismas con el caracter ‘*’. La función debe ignorar las aristas de la matriz.
Nota: para completar la matriz no hace falta interactuar con el usuario, utilizar números aleatorios.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILAS 5
#define COLUMNAS 20
#define RANGO 20

double randNormalize(void);
int circundantes(int i, int j, int matriz[FILAS][COLUMNAS]);
void matrizEstrellas(int matriz[FILAS][COLUMNAS]);
void makeMatriz(int matriz[FILAS][COLUMNAS]);


int main(void) {
	srand(time(0));

	int matriz[FILAS][COLUMNAS];
	int i, j;

	makeMatriz(matriz);
	for (i = 0; i < FILAS; i++) {
		printf("%d)\t", i+1);
		for (j = 0; j < COLUMNAS; j++) {
			printf("%d\t", matriz[i][j]);
		}
		printf("\n");
	}

	matrizEstrellas(matriz);
	for (i = 0; i < FILAS; i++) {
		printf("%d)\t", i+1);
		for (j = 0; j < COLUMNAS; j++) {
			printf("%c\t", matriz[i][j]);
		}
		printf("\n");
	}
}

void makeMatriz(int matriz[FILAS][COLUMNAS]) {
	int i, j;

	for (i = 0; i < FILAS; i++) {
		for (j = 0; j < COLUMNAS; j++) {
			matriz[i][j] = (int) (randNormalize() * (RANGO));
			// matriz[i][j] = (int) (rand() % (RANGO));
		}
	}
}

void matrizEstrellas(int matriz[FILAS][COLUMNAS]) {
	int i, j;

	for (i = 1; i < FILAS - 1; i++) {
		for (j = 1; j < COLUMNAS - 1; j++) {
			if(((matriz[i][j] + circundantes(i, j, matriz)) / 9) > 4) {
				matriz[i][j] = '*';
			} else {
				matriz[i][j] = ' ';
			}
		}
	}
}

int circundantes(int i, int j, int matriz[FILAS][COLUMNAS]) {
	int cond1;
	int cond2;
	int suma = 0;

	for(cond1 = (i - 1); cond1 <= (i + 1); cond1++) {
		for(cond2 = (j - 1); cond2 <= (j + 1); cond2++) {
			if (cond1 != i && cond2 != j){
				suma+= matriz[i][j];
			}
		}
	}
	return suma;
}

double randNormalize(void) {
	return rand() / ((double) RAND_MAX + 1);
}
