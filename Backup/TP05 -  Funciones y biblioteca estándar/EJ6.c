//
//  Ej 6.c
//  Programacion Imperativa
//
//  Created by Juan Moreno on 3/10/14.
//  Copyright (c) 2014 Juan Moreno. All rights reserved.
//

/* Ejercicio 6
Escribir un programa que ofrezca las siguientes opciones para accionar sobre un
caracter leído desde la entrada estándar. Utilizar distintas funciones (con no más de
4 líneas) para cada una de las opciones y una función para el menú de opciones:
􏰀 Convertir de mayúscula a minúscula.
􏰀 Convertir de minúscula a mayúscula.
􏰀 Imprimir el carácter siguiente.
􏰀 Imprimir la siguiente letra en forma circular (si la letra es 'z', debe imprimir 'a')
*/

#include <stdio.h>
#include "getnum.h"
#include "mylib.h"

#define DELTA ('A' - 'a')

int main(void) {
	int c, m;
	printf("Introducir un caracter:\n");
	c = getchar();
	printf("Que quieres hacer?\n");
	printf("1) Convertir de Mayusculas a Minusculas\n");
	printf("2) Convertir de Minusculas a Mayusculas\n");
	printf("3) Imprimir caracter siguiente\n");
	printf("4) Imprimir la siguiente letra en forma circular\n");
	switch (m = getint("Opcion: ")) {
		case 1:
				printf("%c\n", toLower(c));
				break;
		case 2:
				printf("%c\n", toUpper(c));
				break;
		case 3:
				printf("%c\n", nextChar(c));
				break;
		case 4:
				printf("%c\n", mirrorLetter(c));
				break;
		default:
				printf("Parametro incorrecto.\n");
				break;
	}

}

char toLower(int c) {
	if (c >= 'A' && c <= 'Z') {
		c-= DELTA;
	}
	return c;
}

char toUpper(int c) {
	if (c >= 'a' && c <= 'z') {
		c+= DELTA;
	}
	return c;
}

char nextChar(int c) {
	return c++;
}

char mirrorLetter(int c) {
	int delta;
	if (c >= 'A' && c <= 'Z') {
		delta = 'Z' - c;
		c = 'A' + delta;
	} else if (c >= 'a' && c <= 'z') {
		delta = 'z' - c;
		c = 'a' + delta;
	}
	return c;
}
