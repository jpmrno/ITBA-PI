//
//  Ej 20.c
//  Programacion Imperativa
//
//  Created by Juan Moreno on 3/10/14.
//  Copyright (c) 2014 Juan Moreno. All rights reserved.
//

/* Ejercicio 20
Escribir un programa (en no más de 10 líneas) que calcule el valor de la 
constante matemática e utilizando la fórmula e = 1 + 1/1! + 1/2! + 1/3! +... e 
imprima una tabla que indique cantidad de términos de la serie y el resultado parcial, 
con el siguiente formato:
¿Qué criterio utilizaría para detener la secuencia? ( No usar cantidad fija de 
términos ni preguntarle al usuario la cantidad de términos. Tampoco tendría sentido 
comparar con el verdadero valor de e).
*/

#include <stdio.h>
#include "getnum.h"

int main(void) {
	int termino;
	long int factorial = 1;
	double e = 1.0, eAnt = 0.0;
	printf("N\te\n");
	for(termino = 1;!(e == eAnt);termino++){
		factorial*= termino;
		printf("Numero: %d Factorial: %ld\n", termino, factorial);
		eAnt = e;
		e+=(1.0 / factorial);
		printf("%d\t%.25f\n", termino, e);
	}
}

/* Gonza's

#include <stdio.h>
#define DIFERENCIAL 0.00000000000001

int main(void) {
	double eNumber = 1.0;
	double eNumberAlt = 0.0;
	int factorial = 1;
	int contador = 1;
	printf("N\te\n");
	while ( (eNumber - eNumberAlt) > DIFERENCIAL ) {
		printf("%d\t%.15f\n", contador, eNumber);
		eNumberAlt = eNumber; //Reservar el valor y posteriormente hacer la resta en el while
		factorial *= contador; //Calculo factorial nuevo multiplicando el anterior por el num post.
		contador++;	
		eNumber += 1.0/factorial; //Polinomio de Taylor
	}
}*/