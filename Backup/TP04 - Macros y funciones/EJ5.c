//
//  Ej 5.c
//  Programacion Imperativa
//
//  Created by Juan Moreno on 3/10/14.
//  Copyright (c) 2014 Juan Moreno. All rights reserved.
//

/* Ejercicio 5
Escribir una macro MAXIMO2 que recibiendo tres parámetros, asigne al tercer parámetro el 
mayor de los dos primeros. Utilizarla en un programa para verificar su correcto funcionamiento. (En no 
más de 5 líneas)
*/

#include <stdio.h>
#include "getnum.h"
#include "mylib.h"

int main(void) {
	int num1, num2, max;
	num1 = getint("Introduce el primer numero: ");
	num2 = getint("Introduce el primer numero: ");
	MAXIMO2(num1,num2,max);
	printf("EL mayor es: %d\n", max);
}