//
//  Ej 11.c
//  Programacion Imperativa
//
//  Created by Juan Moreno on 3/10/14.
//  Copyright (c) 2014 Juan Moreno. All rights reserved.
//

/* Ejercicio 11
Escribir un programa que utilice ciclos para imprimir la siguiente tabla de valores, 
para N desde 1 hasta 20. (En no más de 6 líneas).
*/

#include <stdio.h>
#include "getnum.h"

#define INICIO 1
#define FIN 20

int main(void) {
	int numero;
	printf("N\t10*N\t100*N\t1000*N\n");
	for(numero = INICIO; numero <= FIN; numero++){
		printf("%d\t%d\t%d\t%d\n", numero, numero * 10, numero * 100, numero * 1000);
	}
	return 0;
}