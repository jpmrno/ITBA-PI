//
//  Ej 8.c
//  Programacion Imperativa
//
//  Created by Juan Moreno on 3/10/14.
//  Copyright (c) 2014 Juan Moreno. All rights reserved.
//

/* Ejercicio 8

*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "getnum.h"

// Condiciones iniciales
#define FILAS 3
#define COLUMNAS 5
#define MAXNUM 90

#define ERROR 0
#define FALSE 0
#define TRUE 1

int ** generarCarton(int filas, int columnas, int maxnum);

int repiteNum(int ** carton, int filas, int columnas, int randNum, int fil, int col);
void liberaMatriz(int ** matriz, size_t filas);

int main(void) {
	srand(time(0));
	int i, j, k;
	int filas = FILAS, columnas = COLUMNAS, maxnum = MAXNUM;
	int *** carton;
	int jugadores = getint("Cuantos jugadores? ");
carton = malloc(jugadores * sizeof(**carton));
	for( i = 0; i < jugadores; i++) {
		if(carton[i] == NULL)
			return ERROR;
		carton[i] = generarCarton(filas, columnas, maxnum);
		if(carton[i] == NULL) {
			return ERROR;
		}
	}
	for (k = 0; i < jugadores; i++) {
		printf("Carton del jugador %d:\n", k);
		for (i = 0; i < filas; i++) {
			for(j = 0; j < columnas; j++) {
				printf("%d\t", carton[k][i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}

int ** generarCarton(int filas, int columnas, int maxnum) {
	int i, j, randNum;
	int ** carton;

	carton = malloc(filas * sizeof(*carton));
	if(carton == NULL)
		return ERROR;
	for( i = 0; i < filas; i++) {
		carton[i] = malloc(columnas * sizeof(**carton));
		if(carton[i] == NULL) {
			liberaMatriz(carton, i);
			return ERROR;
		}
		for( j = 0; j < columnas; j++) {
			do 
				randNum = (rand() % maxnum) + 1;
			while(repiteNum(carton, filas, columnas, randNum, i, j));
			carton[i][j] = randNum;
		}
	}
	return carton;
}

int repiteNum(int ** carton, int filas, int columnas, int randNum, int fil, int col) {
	int i, j;
	for( i = 0; i < filas; i++) {
		for( j = 0; j < columnas; j++) {
			if(i == fil && j == col)
				return FALSE;
			if(carton[i][j] == randNum)
				return TRUE;
		}
	}
	return ERROR;
}

void liberaMatriz(int ** matriz, size_t filas) {
	int i;
	for (i = 0; i < filas; i++) {
		free(matriz[i]);
	}
	free(matriz);
}




