//
//  Ej 7.c
//  Programacion Imperativa
//
//  Created by Juan Moreno on 3/10/14.
//  Copyright (c) 2014 Juan Moreno. All rights reserved.
//

/* Ejercicio 7
Escribir la macro isdigit que dado un caracter indique si dicho caracter representa un dígito 
decimal o no. 
*/

#include <stdio.h>
#include "getnum.h"
#include "mylib.h"

int main(void) {
	int letra; 
	printf("Ingrese un caracter: \n");
	letra = getchar(); 
	if (ISDIGIT(letra)) 
		printf("Es un dígito.\n");
	else
		printf("No es un dígito.\n");
}