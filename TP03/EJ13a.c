//
//  Ej 13a.c
//  Programacion Imperativa
//
//  Created by Juan Moreno on 3/10/14.
//  Copyright (c) 2014 Juan Moreno. All rights reserved.
//

/* Ejercicio 13
Dada una variable entera que indica el lado de un cuadrado, imprimir por 
salida estándar dicho cuadrado en forma de asteriscos.
a) Resolverlo con dos ciclos anidados.
b) Resolverlo con un único ciclo for.
*/

#include <stdio.h>
#include "getnum.h"

int main(void) {
	int lado = getint("Introduce el lado del cuadrado: ");
	int i=1, n=1;
	while(i<=lado){
		while(n<=lado){
			printf("*");
			n++;
		}
		printf("\n");
		i++;
		n=1;
	}
	return 0;
}