//
//  Ej #.c
//  Programacion Imperativa
//
//  Created by Juan Moreno on 3/10/14.
//  Copyright (c) 2014 Juan Moreno. All rights reserved.
//

/* Ejercicio #

*/

#include <stdio.h>
#include "getnum.h"
#include <string.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1
#define FALSE 0
#define TRUE 1

#define ALUMNOS 7
#define TOPE 20
#define EOA ""
#define BLOQUE 10

typedef char * TipoNombre[];
//typedef char TipoNombre[ALUMNOS][TOPE];

char ** aprobados(TipoNombre alumnos, int notas[]);

int main(void) {
	TipoNombre alumnos = {"Agustin Orion", "Forlin", "Erbes", "Fernando Gago", "Juan Roman Riquelme", "Juan Martinez", EOA};
	int notas[] = {2, 6, 4, 6, 8, 4};
	char ** soloAprobados;

	soloAprobados = aprobados(alumnos, notas);

	printf("%s\n", soloAprobados[3]);

	return OK;
}

char ** aprobados(TipoNombre alumnos, int notas[]) {
	int i, j = 0, aprobaron = 0;
	char ** aprobados;

	aprobados = malloc(ALUMNOS * sizeof(*aprobados));
	if(alumnos == NULL)
		return ERROR;

	for(i = 0; alumnos[i] != EOA; i++) {
		if(notas[i] >= 4) {
			aprobados[j] = malloc(TOPE * sizeof(**aprobados));
			if(aprobados[j] == NULL)
				return ERROR;
			strcpy(aprobados[j], alumnos[i]);
			aprobaron++;
			j++;
		}
	}

	return aprobados;
}
