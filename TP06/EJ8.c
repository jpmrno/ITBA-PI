//
//  Ej 8.c
//  Programacion Imperativa
//
//  Created by Juan Moreno on 3/10/14.
//  Copyright (c) 2014 Juan Moreno. All rights reserved.
//

/* Ejercicio 8

*/

#include <stdio.h>
#include "getnum.h"

double redondeo(double numero, int decimales);

int main(void) {
	double numero, redondeado;
	int decimales;

	numero = getint("Numero a redondear?: ");
	decimales = getint("Cantidad de decimales a redondear?: ");

	redondeado = floor(numero, decimales);
}

double redondeo(double numero, int decimales) {
	
	
	return numero;
}
