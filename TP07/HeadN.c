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

char * headN(char s[], int n);

int main(void) {
	char s[] = "Hola mundo";
	char * head;

	head = headN(s, 2);

	printf("%s\n", head);
}

char * headN(char s[], int n) {
	char * head;
	int i;

	head = malloc((n + 1) * sizeof(*head));
	if(head == NULL)
		return ERROR;

	for( i = 0; i < n; i++) {
		if(!s[i]) {
			free(head);
			return s;
		}
		head[i] = s[i];
	}
	head[i] = 0;

	return head;
}
