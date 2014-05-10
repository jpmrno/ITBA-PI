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
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include "getnum.h"

#define LETRAS_ALFABETO 26
#define TOPE 100

#define ERROR 0
#define OK 1
#define FALSE 0
#define TRUE 1

void crearAlfabero(char alfabeto[]);
int leerTexto(char string[]);
int codificarF(char codificar[], char alfabeto[], char codificado[]);
int decodificarF(char decodificar[], char alfabeto[], char decodificado[]);

int retPosVector(char letra, char alfabeto[]);

int main(void) {
	srand(time(0));
	static char alfabeto[LETRAS_ALFABETO];
	char codificar[TOPE];
	char salida[TOPE];
	int opcion;

	crearAlfabero(alfabeto);

	do {
		printf("Introducir el texto:\n");
		leerTexto(codificar);

		do {
			printf("\nQue desea hacer?\n1) Codificar\n2) Decodificar\n");
			switch(opcion = getint("Opcion: ")) {
				case 1:
					codificarF(codificar, alfabeto, salida);
					break;
				case 2:
					decodificarF(codificar, alfabeto, salida);
					break;
				case 3:
					return OK;
				default:
					printf("Opcion incorrecta.\n");
					break;
			}
		} while(opcion != 1 && opcion != 2);

		printf("%s", codificar);
		printf("\n");
		printf("%s", salida);
		printf("\n");
	} while(yesNo("Seguir? "));

	return OK;
}

void crearAlfabero(char alfabeto[]) {
	int i, j, found;
	char letra;

	for (i = 0; i < LETRAS_ALFABETO; ++i) {
		do {
			letra = (rand() % LETRAS_ALFABETO) + 'A';
			found = FALSE;
			for(j = 0; j < i && !found; j++)
				if(alfabeto[j] == letra)
					found = TRUE;
		} while(found);
		if(!found)
			alfabeto[i] = letra;
	}
}

int leerTexto(char string[]) {
	int c, i = 0;

	while((c = getchar()) != '\n')
		string[i++] = c;
	string[i] = 0;
	return i;
}

int codificarF(char codificar[], char alfabeto[], char codificado[]) {
	int i;
	char aux;

	for (i = 0; codificar[i]; i++) {
		if((aux = toupper(codificar[i])) >= 'A' && aux <= 'Z') {
			codificado[i] = alfabeto[aux - 'A'];
		} else {
			codificado[i] = codificar[i];
		}
	}
	codificado[i] = 0;
	return 1;
}

int decodificarF(char decodificar[], char alfabeto[], char decodificado[]) {
	int i;
	char aux;

	for (i = 0; decodificar[i]; i++) {
		if((aux = toupper(decodificar[i])) >= 'A' && aux <= 'Z') {
			decodificado[i] = retPosVector(aux, alfabeto) + 'A';
		}else {
			decodificado[i] = decodificar[i];
		}
	}
	decodificado[i] = 0;
	return 1;
}

int retPosVector(char letra, char alfabeto[]) {
	int i;

	for( i = 0; alfabeto[i]; i++) {
		if(alfabeto[i] == letra) {
			return i;
		}
	}
}