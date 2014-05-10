//
//  Ej 19b.c
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
	int numero, cincosE = 0, cincosD = 0, realState = 0;
	printf("Introduce un numero real: ");
	while(((numero = getchar()) >= '0' && numero <= '9') || numero == '.'){
		if(numero == '.'){
			realState = 1; // Para evitar el problema de mas de un punto puedo poner "+="
		}
		if(realState == 0){
			if(numero == '5')
				cincosE+= 1;
		} else { // y aca agregar un if(realState == 1)
			if(numero == '5')
				cincosD+= 1;
		}
	}
	printf("Hay %d cincos (5) en la parte entera y %d cincos (5) en la parte decimal.\n"
		, cincosE, cincosD);
}