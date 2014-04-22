//
//  Ej 7.c
//  Programacion Imperativa
//
//  Created by Juan Moreno on 3/10/14.
//  Copyright (c) 2014 Juan Moreno. All rights reserved.
//

/* Ejercicio 7
Escribir una función real para calcular aproximadamente el valor de ex por medio de la serie 1 + x + x2 / 2! + x3 / 3! + ....... Dicha función recibe como parámetros de entrada el valor de x. (En no más
de 10 líneas)
Hacer un programa que invoque a la función y escriba el resultado de la misma y el valor de la
función exp(x) de C.
*/

#include <stdio.h>
#include "getnum.h"

double exValue(int x);

int main(void) {
	int x;
	x = getint("Introducir la potencia: ");
	printf("e^(%d) = %.10f\n", x, exValue(x));
}

double exValue(int x) {
	int termino;
	double factorial = 1, potencia = 1;
	double e = 1.0, eAnt = 0.0;

	if(x < 0) {
		return -1;
	}

	for(termino = 1; (e != eAnt); termino++){
		eAnt = e;
		factorial*= termino;
		potencia*= x;
		e+= (potencia / factorial);
	}
	return e;
}
