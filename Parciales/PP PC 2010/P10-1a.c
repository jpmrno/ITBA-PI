//
//  Ej #.c
//  Programacion Imperativa
//
//  Created by Juan Moreno on 3/10/14.
//  Copyright (c) 2014 Juan Moreno. All rights reserved.
//

/* Ejercicio #
Escribir una macro que reciba las coordenadas (X,Y) de los vértices inferior 
izquierdo y superior derecho de un segmento y obtenga la longitud de la diagonal
del mismo. Si los datos no están en el orden correcto, devuelve cero.
*/

#include <stdio.h>
#include "getnum.h"
#include <math.h>

#define DIAGONAL(x, y, z, w) ((z-x) > 0) && ((w-y) > 0)? pow((pow((z - x), 2) + pow((w - y), 2)), 0.5):0
#define DELTA 5

int main(void) {
	printf("La diagonal vale: %.2f\n", DIAGONAL(1, 2, 4, 6));
	printf("La diagonal vale: %.2f\n", DIAGONAL(1, 2, 1 + DELTA, 2 + DELTA));
	printf("La diagonal vale: %.2f\n", DIAGONAL(1, 2, 3, 0));
	printf("La diagonal vale: %.2f\n", DIAGONAL(2, 2, 1, 4));
}
