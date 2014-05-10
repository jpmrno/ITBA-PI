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

// Condicione
#define FILAS 3
#define COLUMNAS 5
#define MAXNUM 90 // multiplos de 10
#define MAXPLAYERS 20

#define ERROR 0
#define OK 1
#define FALSE 0
#define TRUE 1

typedef int * TipoLinea;
typedef TipoLinea * TipoCarton;

int cantJugadores(void);
TipoCarton * generarJugadores(int jugadores);
TipoCarton generarCarton(void);
TipoCarton generarBolillero(void);
int jugar(int jugadores, TipoCarton * carton, TipoCarton bolillero);
int sacarBolilla(TipoCarton bolillero, int * cantBolillas);
int controlarCarton(TipoCarton carton, int bolilla);
int buscarBolilla(TipoCarton carton, int bolilla);
int controlarLinea(TipoLinea linea);
void imprimeCarton(TipoCarton carton, int jugador);

void imprimeBolillero(TipoCarton bolillero);
int repiteNum(TipoCarton carton, int randNum, int fil, int col);
void liberaMatriz(int ** matriz, size_t filas);

int main(void) {
	srand(time(0));
	TipoCarton * carton;
	TipoCarton bolillero;
	int jugadores, i;

	jugadores = cantJugadores();
	
	carton = generarJugadores(jugadores);
	for(i = 0; i < jugadores; i++)
		imprimeCarton(carton[i], i);

	bolillero = generarBolillero();

	if(bolillero == NULL || carton == NULL)
		return ERROR;

	if(jugar(jugadores, carton, bolillero)) {
		imprimeBolillero(bolillero);
		return OK;
	}
	return ERROR;
}

int cantJugadores(void) {
	int jugadores;
	do
		jugadores = getint("Cuantos jugadores? ...(Maximo %d)... ", MAXPLAYERS);
	while(jugadores <= 0 || jugadores > MAXPLAYERS);
	return jugadores;
}

TipoCarton * generarJugadores(int jugadores) {
	TipoCarton * carton;
	int i;
	
	carton = malloc(jugadores * sizeof(TipoCarton));
	if(carton == NULL)
		return ERROR;
	for( i = 0; i < jugadores; i++) {
		carton[i] = generarCarton();
		if(carton[i] == NULL)
			return ERROR;
	}
	return carton;
}

TipoCarton generarCarton(void) {
	int i, j, randNum;
	TipoCarton carton;

	carton = malloc(FILAS * sizeof(TipoLinea));
	if(carton == NULL)
		return ERROR;
	for( i = 0; i < FILAS; i++) {
		carton[i] = malloc(COLUMNAS * sizeof(TipoCarton));
		if(carton[i] == NULL) {
			liberaMatriz(carton, i);
			return ERROR;
		}
		for( j = 0; j < COLUMNAS; j++) {
			do 
				randNum = (rand() % MAXNUM) + 1;
			while(repiteNum(carton, randNum, i, j));
			carton[i][j] = randNum;
		}
	}
	return carton;
}

TipoCarton generarBolillero(void) {
	int filas = (MAXNUM / 10), columnas = 10;
	TipoCarton bolillero;
	int i, j, contador = 1;
	
	bolillero = malloc(filas * sizeof(TipoLinea));
	if(bolillero == NULL)
		return ERROR;
	for( i = 0; i < filas; i++) {
		bolillero[i] = malloc(columnas * sizeof(TipoCarton));
		if(bolillero[i] == NULL) {
			liberaMatriz(bolillero, i);
			return ERROR;
		}
		for( j = 0; j < columnas; j++)
			bolillero[i][j] = contador++;
	}
	return bolillero;
}

// Se fija si el numero ya pertenece a la matriz.
int repiteNum(TipoCarton carton, int randNum, int fil, int col) {
	int i, j;

	for( i = 0; i < FILAS; i++)
		for( j = 0; j < COLUMNAS; j++) {
			if(i == fil && j == col)
				return FALSE;
			if(carton[i][j] == randNum)
				return TRUE;
		}
	return ERROR;
}

void liberaMatriz(int ** matriz, size_t filas) {
	int i;

	for (i = 0; i < filas; i++)
		free(matriz[i]);
	free(matriz);
}

int jugar(int jugadores, TipoCarton * carton, TipoCarton bolillero) {
	int cantBolillas = MAXNUM, bolilla, lineas;
	int huboLinea = FALSE, bingo = 0;
	int i;

	while(cantBolillas) {
		//getchar();
		bolilla = sacarBolilla(bolillero, &cantBolillas);
		printf("~~~ Salio la bolilla: %d ~~~\n", bolilla);
		printf("~~~ Restan %d bolillas ~~~\n\n", cantBolillas);
		for(i = 0; i < jugadores; i++) {
			lineas = controlarCarton(carton[i], bolilla);
			imprimeCarton(carton[i], i);
			if(lineas == FILAS) {
				// por si hay mas de 1 bingo.
				bingo++;
				printf("~~~ BINGO! del jugador %d ~~~\n\n", i+1);
			}
			if(!huboLinea && lineas) {
				// solo se cuenta la primera fila.
				huboLinea = TRUE;
				printf("~~~ LINEA! del jugador %d ~~~\n\n", i+1);
			}
		}
		if(bingo)
			return bingo;
	}

	return ERROR;
}

// Saca una bolita del bolillero (reemplaza por 0).
int sacarBolilla(TipoCarton bolillero, int * cantBolillas) {
	int bolilla, randFil, randCol;

	do {
		randFil = rand() % (MAXNUM / 10);
		randCol = rand() % 10;
	} while(bolillero[randFil][randCol] == 0);
	bolilla = bolillero[randFil][randCol];
	bolillero[randFil][randCol] = 0;
	(*cantBolillas) = (*cantBolillas) - 1;
	return bolilla;
}

// Controla la cantidad de lineas completadas.
int controlarCarton(TipoCarton carton, int bolilla) {
	int i, lineas = 0;

	if(buscarBolilla(carton, bolilla))
		for( i = 0; i < FILAS; i++)
			if(controlarLinea(carton[i]))
				lineas++;
	return lineas;
}

// Se fija si la bolilla pertenece al carton.
int buscarBolilla(TipoCarton carton, int bolilla) {
	int i, j;

	for( i = 0; i < FILAS; i++)
		for( j = 0; j < COLUMNAS; j++)
			if(carton[i][j] == bolilla) {
				carton[i][j] = 0;
				return TRUE;
			}
	return FALSE;
}

// Se fija si la linea esta llena de ceros.
int controlarLinea(TipoLinea linea) {
	int i;

	for( i = 0; i < COLUMNAS; i++)
		if(linea[i] != 0)
			return FALSE;
	return TRUE;
}

// Imprime el carton del jugador.
void imprimeCarton(TipoCarton carton, int jugador) {
	int i, j;

	printf("Carton del jugador %d:\n", jugador+1);
	for (i = 0; i < FILAS; i++) {
		for(j = 0; j < COLUMNAS; j++) {
			printf("%d\t", carton[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

// Imprime bolillero.
void imprimeBolillero(TipoCarton bolillero) {
	int filas = (MAXNUM / 10), columnas = 10;
	int i, j;

	printf("Bolillero\n");
	for (i = 0; i < filas; i++) {
		for(j = 0; j < columnas; j++)
			printf("%d\t", bolillero[i][j]);
		printf("\n");
	}
	printf("\n");
}
