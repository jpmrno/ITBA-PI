//
//  Ej 15.c
//  Programacion Imperativa
//
//  Created by Juan Moreno on 3/10/14.
//  Copyright (c) 2014 Juan Moreno. All rights reserved.
//

/* Ejercicio 15
Dado un entero que representa un número binario positivo 
(todos sus dígitos son cero o uno), imprimir por salida estándar 
el equivalente decimal. (En no más de 10 líneas)
*/

#include <stdio.h>
#include "getnum.h"

#define TRACE { printf("Executing %s line %d\n", __FILE__, __LINE__); }

int main(void) {
	int numero = getint("Introduce un numero en binario: ");
	printf("%d", sizeof(numero));
}