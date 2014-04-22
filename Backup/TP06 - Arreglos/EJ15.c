//
//  Ej .c
//  Programacion Imperativa
//
//  Created by Juan Moreno on 3/10/14.
//  Copyright (c) 2014 Juan Moreno. All rights reserved.
//

/* Ejercicio 6
Dado un arreglo ordenado ascendentemente se pide escribir una función
que reciba como parámetro de entrada/salida el arreglo y como parámetro
de entrada su dimensión y que lo devuelva desordenado, simulando la
mezcla de un mazo de cartas o de un bolillero (en no más de 10 líneas).
*/

#include <stdio.h>
#define ESPACIO 1
#define PALABRA 0

void main(void) {
	char estado = PALABRA;
	int c;
	while((c = getchar()) != EOF) {
		switch(estado) {
			case PALABRA:
				if(c == ' ')
					estado = ESPACIO;
				putchar(c);
				break;
			case ESPACIO:
				if(c != ' ') {
					estado = PALABRA;
					putchar(c);
				}
				break;
		}
	}
}
