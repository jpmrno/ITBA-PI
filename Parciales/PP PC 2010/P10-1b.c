//
//  Ej #.c
//  Programacion Imperativa
//
//  Created by Juan Moreno on 3/10/14.
//  Copyright (c) 2014 Juan Moreno. All rights reserved.
//

/* Ejercicio #
Escribir un programa que lea texto de la entrada estándar y envíe a la salida 
estándar el mismo texto pero sin incluir las palabras de una sola letra (y los 
espacios que la siguen).
*/

#include <stdio.h>

#define PALABRA 0
#define	LETRA 1
#define TOPE 50

void delChars(char s[]);

int main(void) {
	char s[] = "a jamon y queso, o pan y   manteca a cualquiera gustan. a s s ss s";
	delChars(s);
}

void delChars(char s[]) {
	int estado = LETRA;
	int i = 0;
	while(s[i]) {
		switch(estado) {
			case PALABRA:
				putchar(s[i]);
				if(s[i++] == ' ') {
					putchar(' ');
					while(s[i] == ' ') {
						i++;
					}
					estado = LETRA;
				}
				break;
			case LETRA:
				if(s[i+1] != ' ' && s[i+1] != 0) {
					estado = PALABRA;
				}
				else {
					i++;
					while(s[i] == ' ') {
						i++;
					}
				}
				break;
		}
	}
	putchar('\n');
}
