//
//  Ej #.c
//  Programacion Imperativa
//
//  Created by Juan Moreno on 3/10/14.
//  Copyright (c) 2014 Juan Moreno. All rights reserved.
//

/* Ejercicio #
Escribir la función extremos que reciba los siguientes parámetros:
• intervalo: un string (null terminated), que representa un intervalo de números enteros
mayores o iguales a cero.
• inf: de tipo int, parámetro de salida
• sup: de tipo int, parámetro de salida
La función debe devolver en el argumento inf el menor número natural que pertenezca al 
intervalo y en sup el mayor número natural que pertenezca al intervalo.
Si hay error en la sintaxis del intervalo, la función devuelve 0 y no modifica inf ni sup.
Si el intervalo es inválido, la función devuelve -1 y no modifica inf ni sup.
Si todo es correcto, devuelve 1.
*/

#include <stdio.h>
#include "math.h"

void extremos(char intervalo[], int * inf, int * sup);

int main(void) {
	int sup = 0, inf = 0;
	char s[] = "[123,456]";
	extremos(s, &inf, &sup);
	printf("Intervalo = %s\nInf = %d\nSup = %d\n", s, inf, sup);
}

void extremos(char intervalo[], int * inf, int * sup) {
	int i, j = 0, dim, infA = 0, supA = 0, num;

	//if(intervalo[0] != '[' || intervalo[0] != '(')
	//	return 0;

	for (i = 1; intervalo[i] != ','; i++) {
		;
	}
	while((--i) > 0) {
		num = intervalo[i];
		infA+= num * pow(10, 0);
		printf("intervalo[i] = %d", num);
	}
	*inf = infA;
}
