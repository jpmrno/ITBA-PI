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

#define SIR 1
#define NOR 0

int comprimeCar(char c, int vec[], char s[], int maxDim);

int main(void) {
	char s[] = "Aaa, bb aaa a c c a a a";
	int vec[10];
	int maxDim = 10;
	int dim = comprimeCar('a', vec, s, maxDim);
	printf("%s.\n", s);
	printf("%d caracteres borrados.\n", dim);
}


int comprimeCar(char c, int vec[], char s[], int dimMax) {
	int i = 0, estado = NOR, j = 0, iguales = 0;

	while(s[i] && j < dimMax) {
		switch(estado) {
			case NOR:
				s[j++] = s[i];
				if(s[i] == c) {
					estado = SIR;
				}
				i++;
				break;
			case SIR:
				if(s[i] != c) {
					s[j++] = s[i];
					estado = NOR;
				} else {
					iguales++;
				}
				i++;
				break;
		}
	}
	return iguales;
}
