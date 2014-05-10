//
//  Ej 13b.c
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
	for(int n=1, i=1; i<=lado && n<=lado; i++){
		printf("*");
		if(i==lado){
			printf("\n");
			n++;
			i=0;
		}
	}
	return 0;
}