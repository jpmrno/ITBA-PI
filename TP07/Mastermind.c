//
//  Ej 6.c
//  Programacion Imperativa
//
//  Created by Juan Moreno on 3/10/14.
//  Copyright (c) 2014 Juan Moreno. All rights reserved.
//

/* Ejercicio 6
Escribir un programa para desarrollar el juego Mastermind descripto por las siguientes reglas: 
 
 La computadora construye un conjunto aleatorio de X dígitos distintos (para X usar una 
constante simbólica). 
 Se le pide ingresar al usuario el nivel en que quiere jugar. Según esto se trabajará con 
una tolerancia de hasta N pasos, dentro de los cuales si no logra ganar el juego se termina 
automáticamente. 
 El jugador entra un conjunto de X dígitos distintos por teclado. 
 Si el número propuesto por el jugador coincide con el que generó la máquina o la cantidad 
de chances excedió el número tope N , el juego finaliza; sino el programa debe informarle 
cuántos dígitos están BIEN (son correctos y están en su lugar) y cuántos son REGULARES (son
correctos pero están fuera de lugar) y se vuelve a ejecutar el paso anterior. Así se va guiando
al jugador hasta que adivine el número. 
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "getnum.h"

#define LVLMAX 10
#define ERROR 0
#define FALSE 0
#define TRUE 1

double randNormalize(void);

int elegirCantDigitos(void);
void generaAleatorio(int incognita[], int dim);
int elegirNivel(int lvlMax);
void leerNumero(int numero[], int digits);
int coincideNumero(int incognita[], int numero[], int dim);
int cantBien(int incognita[], int numero[], int dim);
int cantRegular(int incognita[], int numero[], int dim);

int main(void) {
	srand(time(0));
	int * incognita;
	int * numero;
	int digits, nivel, i, j;

	digits = elegirCantDigitos();
	incognita = malloc(digits * sizeof(int));
	numero = calloc(digits, sizeof(int));
	if(incognita == NULL || numero == NULL) {
		return ERROR;
	}

	generaAleatorio(incognita, digits);

	nivel = elegirNivel(LVLMAX);

	for (i = 1; i <= nivel; i++) {
		leerNumero(numero, digits);
		printf("Numero ingresado = ");
		for(j = 0; j < digits; j++) {
			printf("%d", numero[j]);
		}
		printf("\n");
		if(coincideNumero(incognita, numero, digits)) {
			printf("\n~~~ GANASTE! ~~~\n\n");
			return 1;
		}
		else if(i == nivel)
			printf("\n~~~ Perdiste ~~~\n\n");
		else 
			printf("\n~~~ Intenta de nuevo ~~~\n\n");
	}
	printf("El numero era: ");
	for(i = 0; i < digits; i++) {
		printf("%d", incognita[i]);
	}
	printf("\n");
	return 1;
}

void generaAleatorio(int incognita[], int dim) {
	char numeros[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int i, randNum;

	for(i = 0; i < dim; i++) {
		do {
			randNum = rand() % 9;
		} while(numeros[randNum] == -1);
		incognita[i] = numeros[randNum];
		numeros[randNum] = -1;
	}
}

int elegirCantDigitos(void) {
	int num;

	do {
		num = getint("~~~ Elegir cant. de digitos: ...(entre 1 y 9)... ");
	} while(num <= 0 || num > 9);
	return num;
}

int elegirNivel(int lvlMax) {
	int num;

	do {
		num = getint("~~~ Elegir nivel: ...(entre 1 y %d)... ", lvlMax);
	} while(num <= 0 || num > lvlMax);
	return num;
}

void leerNumero(int numero[], int digits) {
	int num, dim, error, j;

	do {
		num = getint("Que numero? ");
		error = FALSE;
		dim = (digits - 1);
		while(num > 0 && !error && dim >= 0){
	        numero[dim] = (num % 10);
	        num/= 10;
	    	for(j = (digits - 1); j > dim; j--) {
	    		if(numero[dim] == numero[j])
	    			error = TRUE;
			}
			dim--;
	    }
	    if(dim != -1 || num != 0)
	    	error = TRUE;
	} while (error);
}

int coincideNumero(int incognita[], int numero[], int dim) {
	int bien, regular;

	bien = cantBien(incognita, numero, dim);

	if(bien == dim) {
		return TRUE;
	}
	else {
		regular = cantRegular(incognita, numero, dim);
		printf("Tienes %d BIEN, %d REGULAR y %d ERRORES!\n", bien, regular, (dim - bien - regular));
		return FALSE;	
	}
}

int cantBien(int incognita[], int numero[], int dim) {
	int i, bien = 0;

	for (i = 0; i < dim; i++) {
		if(incognita[i] == numero[i])
			bien++;
	}
	return bien;
}

int cantRegular(int incognita[], int numero[], int dim) {
	int i, regular = 0, j;

	for (i = 0; i < dim; i++) {
		for (j = 0; j < dim; j++) {
			if(incognita[i] == numero[j] && j != i)
				regular++;
		}
	}
	return regular;
}

double randNormalize(void) {
	return rand() / ((double) RAND_MAX + 1);
}
