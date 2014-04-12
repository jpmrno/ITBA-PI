//
//  Ej 5.c
//  Programacion Imperativa
//
//  Created by Juan Moreno on 3/10/14.
//  Copyright (c) 2014 Juan Moreno. All rights reserved.
//

/* Ejercicio 5
Escribir una función potencia, que reciba en dos parámetros de entrada la base (de tipo double) y el exponente (entero), y devuelva el valor de dicha potencia (En no más de 10 líneas).
Por ejemplo, potencia(2,-4) debe devolver 0.0625. En caso de no poder calcularse el resultado debe devolver –1.
*/

#include <stdio.h>
#include "getnum.h"
#include "mylib.h"
#include <float.h>

int main(void) {
	double base;
	int exponente;
	base = getdouble("Introducir la base: ");
	exponente = getint("Introducir el exponente: ");
	printf("(%f)^(%d) = %g\n", base, exponente, calcPotencia(base,exponente));
}

double calcPotencia(double base, int exponente) {
	int i;
	double potencia = 1;
	if (exponente > 0){
		for( i = 1; i<=exponente; i++){
			potencia*= base;
		}
	} if (exponente < 0){
		exponente = (-1) * exponente;
		for( i = 1; i<=exponente; i++){
			potencia*= base;
		}
		potencia = 1.0 / potencia;

	}
	if (potencia <= DBL_MAX)
		return potencia;
	else
		return -1;
}
