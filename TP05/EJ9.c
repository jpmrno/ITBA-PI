//
//  Ej 9.c
//  Programacion Imperativa
//
//  Created by Juan Moreno on 3/10/14.
//  Copyright (c) 2014 Juan Moreno. All rights reserved.
//

/* Ejercicio 9
Escribir un programa (en no más 15 líneas) para encontrar raíces de funciones en
un intervalo dado. Se deberá recorrer el intervalo a incrementos de 0.001,
evaluando la función en cada paso y escribiendo por salida estándar los puntos
que son raíces. Los extremos del intervalo serán de tipo real y su valor estara
dado por constantes del programa.

Tener en cuenta no sólo el caso en el que el resultado de evaluar la función sea
cero, sino también aquellos puntos en los cuales la función cambia de signo.
*/

#include <stdio.h>
#include <math.h>

#define ABS(x) ((x) > 0)? (x):-(x)

#define TRUE 1
#define FALSE 0
#define DELTA 0.0000001

#define INTERVALO_UP 7
#define INTERVALO_DOWN 0
#define INCREMENTO 0.001

void ceros(void);
double funcion(double x);

int main(void) {
	ceros();
}

void ceros(void) {
	double i, anterior;

    anterior = funcion(INTERVALO_DOWN);

	for(i = INTERVALO_DOWN; i <= INTERVALO_UP; i+= INCREMENTO ){
        if( (funcion(i) * anterior) < 0 )  {
			printf("Tiene un cero en X=%f por cambio de signo.\n", i);
		} else if( fabs(funcion(i)) < DELTA ) {
            printf("Tiene un cero en X=%f por evaluacion.\n", i);
        }
        anterior = funcion(i);
	}
}

double funcion(double x) {
    return sin(x);
    //return cos(x);
}
