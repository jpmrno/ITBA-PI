//
//  Ej 16.c
//  Programacion Imperativa
//
//  Created by Juan Moreno on 3/10/14.
//  Copyright (c) 2014 Juan Moreno. All rights reserved.
//

/* Ejercicio 16
Escribir una función que devuelva un subvector de un arreglo de caracteres, recibiendo sólo los siguientes parámetros:
• arregloIn: vector de entrada, null terminated.
• arregloOut: vector de salida null terminated.
• desde, hasta: valores enteros, representan las posiciones de valores a copiar.
• dimMax: dimensión máxima del vector de salida (incluyendo el cero).
Dicha función debe almacenar en arregloOut los elementos de arregloIn cuyos índices estén comprendidos entre desde y hasta inclusive y colocar el valor cero al final. La cantidad máxima de elementos a copiar está dada por el parámetro dimMax. En caso de que la cantidad de valores a copiar supere dimMax, se copiarán solamente dimMax - 1 valores.
Si alguno de los parámetros es erróneo o la posición desde esté fuera de los límites del arreglo de entrada, la función debe retornar el valor cero y no alterar el arreglo de salida, caso contrario debe retornar la cantidad de elementos copiados.
*/

#include <stdio.h>
#include "getnum.h"

//#define TRUE 1
//#define FALSE 0
#define TOPE 20
#define DIMMAX 20

int function(char arregloIn[], char arregloOut[], int desde, int hasta, int dimMax);

int main(void) {
	char arregloIn[TOPE], arregloOut[DIMMAX];
	int desde, hasta, elementosC, dimMax;
	int i = 0; //end = FALSE;

	dimMax = sizeof(arregloOut) / sizeof(arregloOut[0]);
	printf("Introducir el texto: \n");
	while((arregloIn[i] = getchar()) != '\n' && i < (TOPE - 1)) {
		i++;
	}
	/*for(i = 0; i < (TOPE - 1) && !end; i++) {
		arregloIn[i++] = getchar();
		if(arregloIn[i] == '\n') {
			end = TRUE;
			i--;
		}
	}*/
	arregloIn[i++] = NULL;
	desde = getint("Copiar desde: ");
	hasta = getint("Copiar hasta: ");
	elementosC = function(arregloIn, arregloOut, desde, hasta, dimMax);
	printf("arrayIn[] = %s\n", arregloIn);
	printf("arrayOut[] = %s\n", arregloOut);
	printf("Elementos copiados: %d\n", elementosC);
}

int function(char arregloIn[], char arregloOut[], int desde, int hasta, int dimMax) {
	int i = desde, j = 0;

	// lo del dimMax me parece que ya esta contemplado abajo
	if(desde < 0 || dimMax == 1) {
		return 0;
	}

	while(i <= hasta && arregloIn[i] != NULL && j < (dimMax - 1)) {
		arregloOut[j++] = arregloIn[i++];
	}
	arregloOut[j] = NULL;
	return j;
}
