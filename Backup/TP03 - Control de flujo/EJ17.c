//
//  Ej 17.c
//  Programacion Imperativa
//
//  Created by Juan Moreno on 3/10/14.
//  Copyright (c) 2014 Juan Moreno. All rights reserved.
//

/* Ejercicio 17
Escriba y ejecute un programa que imprima todos los múltiplos de 10 
( 10, 100, 1000, etc.) en no más de 5 líneas ¿Qué sucede cuando ejecuta 
este programa ?
*/

#include <stdio.h>
#include "getnum.h"

int main(void) {
	long int i;
	for(i=1;;i*=10){
		printf("%d\n", 10*i);
	}
}