//
//  Ej 10.c
//  Programacion Imperativa
//
//  Created by Juan Moreno on 3/10/14.
//  Copyright (c) 2014 Juan Moreno. All rights reserved.
//

/* Ejercicio 10

*/

#include <stdio.h>
#include "getnum.h"

#define NUM 0
#define DEN 1
#define POSITIVO 0
#define NEGATIVO 1

#define MIN(a, b) (a)<(b)?a:b
#define ABS(a) (a)>0?(a):-(a)
#define NEGATIVE(a) (a)<0?(a):-(a)

int mayorDivComun(int racional[2]);
void factorizarAlt(int racional[2]);
void sumarRacionales(int racional1[2], int racional2[2], int respuesta[2]);
char signosFraccion(int racional1[2]);

int main(void) {
	int racional1[2], racional2[2], respuesta[2];
	int option;

	racional1[NUM] = getint("Introduce el numerador: ");
	racional1[DEN] = getint("Introduce el denominador: ");

	printf("Menu:\n1) Factorizar\n2) Sumar\n");
	switch (option = getint("Que desea hacer? ")) {
		case 1:
			printf("\nNumero: %d/%d\n", racional1[NUM], racional1[DEN]);
			factorizarAlt(racional1);
			printf("Respuesta: %d/%d\n\n", racional1[NUM], racional1[DEN]);
			break;
		case 2:
			racional2[NUM] = getint("Introduce el 2do numerador: ");
			racional2[DEN] = getint("Introduce el 2do denominador: ");
			sumarRacionales(racional1, racional2, respuesta);
			printf("Numero: %d/%d +", racional1[NUM], racional1[DEN]);
			printf(" Numero: %d/%d\n", racional2[NUM], racional2[DEN]);
			printf("Respuesta: %d/%d\n", respuesta[NUM], respuesta[DEN]);
			break;
		default:
			printf("Opcion erronea.\n");
			break;
	}
}

void factorizarAlt(int racional[2]) {
	int d;
	char signo = POSITIVO;

	if(racional[DEN] != 0) {
		signo = signosFraccion(racional);
		racional[NUM] = ABS(racional[NUM]);
		racional[DEN] = ABS(racional[DEN]);
		d = mayorDivComun(racional);
		racional[NUM]/= d;
		racional[DEN]/= d;
		if(signo) {
			racional[NUM]*= (-1);
		}
	}
}

int mayorDivComun(int racional[2]) {
	int d;

	d = MIN(racional[NUM], racional[DEN]);
	while(racional[NUM] % d != 0 || racional[DEN] % d != 0) {
		d--;
	}

	return d;
}

void sumarRacionales(int racional1[2], int racional2[2], int respuesta[2]) {
	if(racional1[DEN] != 0 && racional2[DEN] != 0) {
		signosFraccion(racional1);
		signosFraccion(racional2);
		respuesta[NUM] = (racional1[NUM] * racional2[DEN]);
		respuesta[NUM]+= (racional2[NUM] * racional1[DEN]);
		respuesta[DEN] = (racional1[DEN] * racional2[DEN]);
		factorizarAlt(respuesta);
	}
}

char signosFraccion(int racional1[2]) {
	if (racional1[NUM] < 0 || racional1[DEN] < 0) {
		if (racional1[NUM] < 0 && racional1[DEN] < 0) {
			racional1[NUM] = ABS(racional1[NUM]);
			racional1[DEN] = ABS(racional1[DEN]);
			return POSITIVO;
		}
		racional1[NUM] = NEGATIVE(racional1[NUM]);
		racional1[DEN] = ABS(racional1[DEN]);
		return NEGATIVO;
	} else {
		return POSITIVO;
	}
}

//#define _NULL_ 0
//void factorizar(int racional[2]);

/*void factorizar(int racional[2]) {
	int d = 2, min;

	//if(racional1[NUM]%racional1[DEN] == 0) {
	//	racional1[NUM]/= racional1[DEN];
	//}
	if(racional[DEN] != 0) {
		racional[NUM] = ABS(racional[NUM]);
		racional[DEN] = ABS(racional[DEN]);
		min = MIN(racional[NUM], racional[DEN]);

		while(d <= min) {
			if(racional[NUM] % d == 0 && racional[DEN] % d == 0) {
				racional[NUM]/= d;
				racional[DEN]/= d;
			} else {
				d++;
			}
		}
	} else {
		racional[NUM] = _NULL_;
		racional[DEN] = _NULL_;
	}
}*/
