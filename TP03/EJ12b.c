//
//  Ej 12a.c
//  Programacion Imperativa
//
//  Created by Juan Moreno on 3/10/14.
//  Copyright (c) 2014 Juan Moreno. All rights reserved.
//

/* Ejercicio 12
Escriba enunciados for que impriman las siguientes secuencias de valores:
a) 3,8,13,18,23
b) 20,14,8,2,-4,-10
c) 19,27,35,43,51
*/

#include <stdio.h>
#include "getnum.h"

#define INICIO 20
#define STEP -6
#define CANTIDAD 6

int main(void) {
	unsigned char i = 1;
	for(int numero = INICIO; i <= CANTIDAD; numero+= STEP){
		printf("%d\n", numero);
		i++;
	}
	return 0;
}