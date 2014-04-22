//
//  Ej #.c
//  Programacion Imperativa
//
//  Created by Juan Moreno on 3/10/14.
//  Copyright (c) 2014 Juan Moreno. All rights reserved.
//

/* Ejercicio #
Escribir la función insertaDesde, que recibe dos strings (null terminated) y un caracter.
Al primer string se le inserta el segundo a partir de la primera aparición del caracter 
indicado. Si el carácter no aparece en el primer string, el mismo no debe ser alterado.
*/

#include <stdio.h>

#define TRUE 1
#define FALSE 0

void insertaDesde(char s1[], char s2[], char c);

int main(void) {
	char s1[20] = "manuel";
	char s2[] = "javi";
	insertaDesde(s1, s2, 'm');
	printf("%s\n", s1);
}

// supone s1[] es suficientemente grande
void insertaDesde(char s1[], char s2[], char c) {
	int i = 0, j;

	while(s1[i]) {
		if(s1[i] == c) {
			for( j = 0; s2[j]; j++) {
				s1[i++] = s2[j];
			}
			s1[i] = 0;
		} else
			i++;
	}
}

// Para el punto b) es mandarle un string constante.
