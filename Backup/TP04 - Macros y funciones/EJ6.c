//
//  Ej 6.c
//  Programacion Imperativa
//
//  Created by Juan Moreno on 3/10/14.
//  Copyright (c) 2014 Juan Moreno. All rights reserved.
//

/* Ejercicio 6
Escribir la macro MAXIMO3 para determinar el mayor de 3 valores, usando la macro definida en 
el ejercicio anterior. (En no más de 10 líneas). Verificar su funcionamiento invocándola desde un 
programa. 
*/

#include <stdio.h>
#include "getnum.h"
#include "mylib.h"

int main(void) {
	int num1, num2, num3, max;
	num1 = getint("Introduce el primer numero: ");
	num2 = getint("Introduce el segundo numero: ");
	num3 = getint("Introduce el tercer numero: ");
	printf("EL mayor es: %d\n", MAXIMO3(num1,num2,num3));
}