//
//  Ej 14.c
//  Programacion Imperativa
//
//  Created by Juan Moreno on 3/10/14.
//  Copyright (c) 2014 Juan Moreno. All rights reserved.
//

/* Ejercicio 14
Escribir una función que reciba un string con el formato 'dd/mm/yyyy' que representa una fecha y devuelva en tres parámetros de salida el número de día, el número del mes y el año. En caso de que la fecha sea incorrecta retorna el valor cero y no altera los parámetros recibidos, caso contrario retorna 1. (Ninguna función debe superar las 8 líneas).
*/

#include <stdio.h>

int divideDate(char fecha[]);

int main(void) {
	char fecha[] = "04/10/1993";
	divideDate(fecha);
}

int divideDate(char fecha[]) {
	int i, j;
	char dia[3], mes[3], anio[5];
	for(i = 0, j = 0; fecha[i] != '/'; i++) {
		dia[j++] = fecha[i];
	}
	dia[j] = NULL;
	for(i++, j = 0; fecha[i] != '/'; i++) {
		mes[j++] = fecha[i];
	}
	mes[j] = NULL;
	for(i++, j = 0; fecha[i] != NULL; i++) {
		anio[j++] = fecha[i];
	}
	anio[j] = NULL;
	printf("%s/", dia);
	printf("%s/", mes);
	printf("%s\n", anio);
	return 1;
}
