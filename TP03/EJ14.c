//
//  Ej 14.c
//  Programacion Imperativa
//
//  Created by Juan Moreno on 3/10/14.
//  Copyright (c) 2014 Juan Moreno. All rights reserved.
//

/* Ejercicio 14
Leer desde la entrada estándar una serie de caracteres, hasta que uno 
de ellos no sea una letra ni un espacio. Luego imprimir por salida estándar 
el menor alfabéticamente de ellos respetando si fue mayúscula o minúscula, 
indicando además cuántas letras eran mayúsculas y cuántas minúsculas. 
No considerar el carácter ‘ñ’ como letra. (En no más de 15 líneas).
*/

#include <stdio.h>
#include "getnum.h"

#define DIFERENCIA ('a'-'A') // Conversor de minusculas a mayusculas

int main(void) {
	int c, menm = 'z', menM = 'Z';
	unsigned char respuesta;
	printf("Introduce un string: \n");
	while((c = getchar()) == ' ' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
		if(c >= 'A' && c <= 'Z'){
			if(c <= menM){
				menM = c;
			}
		} else if(c != ' '){
			if(c <= menm){
				menm = c;
			}
		}
	}
	if(menm - DIFERENCIA < menM)
		respuesta = menm;
	else 
		respuesta = menM;
	printf("La menor letra es: %c\n", respuesta);
	return 0;
}