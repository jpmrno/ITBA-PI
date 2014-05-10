//
//  Ej 18.c
//  Programacion Imperativa
//
//  Created by Juan Moreno on 3/10/14.
//  Copyright (c) 2014 Juan Moreno. All rights reserved.
//

/* Ejercicio 18
Escriba un programa que lea un entero no negativo ( cero o mayor ) 
y que calcule e imprima su factorial. En caso de ingresar un valor inválido, 
imprimir un cartel aclarando cuáles son los valores válidos. (En no más de 10 líneas)
*/

#include <stdio.h>
#include "getnum.h"

// Llega hasta el 20! inclusive, 21 ya da cualquier dato

int main(void) {
	int numero, i;
	unsigned long int factorial = 1;
	numero = getint("Introducir un numero positivo: ");
	if(numero >= 0){
		for(i = 1;i <= numero;i++){
			factorial*= i;
		}
		printf("Su factorial es: %lu\n", factorial);
	} else {
		printf("Valor invalido.\n");
	}
}
	
/*int main(void) {
	int i, n, lim;
	long int factorial = 1;
	lim = getint("Hasta que numero?: ");
	for(n=1;n<=lim;n++){	
		factorial*= n;
		printf("Numero: %d, su factorial es: %ld\n", n, factorial);
	}
}*/
