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

int comprimeCar(char c, int vec[], char s[], int maxDim);

int main(void) {
	char s[] = "Aaa, bb aaaa cc aaa";
	int vec[10];
	int maxDim = 10;
	int dim = comprimeCar('a', vec, s, maxDim);
	printf("%s.\n", s);
	printf("%d caracteres borrados.\n", dim);
}


int comprimeCar(char c, int vec[], char s[], int maxDim) {
	int i, aux = 0, j = 0, repetidos = 0;
	for(i=0; s[i] && j < maxDim; i++) {
		if(s[i] == c) {
			for(i++; s[i] != c; i++) {
				aux+= 1;
				s[i] = s[i+1];
			}
			vec[j++] = aux;
		}
	}
	for(i = 0; i < j; i++) {
		repetidos+= vec[i];
	}
	return repetidos;
}
