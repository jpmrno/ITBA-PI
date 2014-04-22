//
//  Ej 19a.c
//  Programacion Imperativa
//
//  Created by Juan Moreno on 3/10/14.
//  Copyright (c) 2014 Juan Moreno. All rights reserved.
//

/* Ejercicio 19
Leer un número entero e indicar cuantos dígitos de ese número son iguales a 5. 
Repetir para el caso de ser un número real, indicando cuántos 5 tiene en su parte 
entera y cuántos en su parte decimal. (En no más de 10 líneas el primer caso, 
y no más de 25 el segundo caso)
*/

#include <stdio.h>
#include "getnum.h"

int main(void) {
	int numero, cincos = 0;
	printf("Introduce un numero entero: ");
	while((numero = getchar()) >= '0' && numero <= '9'){
		if(numero == '5')
			cincos+= 1;
	}
	printf("Hay %d cincos (5).\n", cincos);
}