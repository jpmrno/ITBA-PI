//
//  Ej 3.c
//  Programacion Imperativa
//
//  Created by Juan Moreno on 3/10/14.
//  Copyright (c) 2014 Juan Moreno. All rights reserved.
//

/* Ejercicio 3
Escribir, en no más de 5 líneas, un programa que defina y utilice una macro con un parámetro 
para calcular el volumen de una esfera. El programa deberá calcular el volumen para esferas de radios de 
1 a 10 cm., e imprimir los resultados en forma tabulada. 
Volumen de la Esfera = ( 4/3 ) * π * r3
*/

#include <stdio.h>
#include "mylib.h"

int main(void) {
	int cm;
	double volumenEsfera;
	for ( cm = 1; cm <= 10; cm++){
		volumenEsfera = VOLESFERA(cm);
		printf("Con radio: %d, el volumen de la esfera es: %f\n", cm, volumenEsfera);
	}
}