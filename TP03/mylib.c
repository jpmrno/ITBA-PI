/* SIMILAR A GETNUM, SOLO QUE SI A CONTINUACION DEL NUMERO HAY CARACTERES
** EXTRA QUE NO SEAN ESPACIOS, LO TOMA COMO INVALIDO
*/

#include <stdio.h>
#include "mylib.h"

#define BORRA_BUFFER while (getchar() != '\n')

int reverseNumber(int numero)
{
	int c;
	int flag = 1;
	while ( ( c= getchar()) != '\n')
		if (! isspace(c))
			flag = 0;
	
	return flag;
}

unsigned long int factorial(int numero) {
	int i;
	unsigned long int factorial = 1;
	if(numero >= 0) {
		for( i = 1; i <= numero; i++) {
			factorial*= i;
		}
	}
	return factorial;
}