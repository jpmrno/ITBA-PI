//
//  Ej 4.c
//  Programacion Imperativa
//
//  Created by Juan Moreno on 3/10/14.
//  Copyright (c) 2014 Juan Moreno. All rights reserved.
//

/* Ejercicio 4
Escribir una función que reciba dos parámetros de entrada de tipo entero y
devuelva en su nombre un numero aleatorio entre ambos números. (En una línea).
*/

#include <stdio.h>
#include <stdlib.h>
//#include <time.h>
#include "getnum.h"

double aleatorio(int izq, int der);
double randNormalize(void);

int main(void) {
    //srand(time(NULL));
    int izq, der;
    izq = getint("Numero inicial: ");
    der = getint("Numero final: ");
    printf("Numero aleatoreo entre [%d,%d] = %f\n", izq, der, aleatorio(izq, der));
}

double aleatorio(int izq, int der) {
    return (randNormalize() * ((der - izq + 1) + izq));
}

double randNormalize(void) {
	return rand() / ((double) RAND_MAX);
}
