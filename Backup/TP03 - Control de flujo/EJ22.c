//
//  Ej 22.c
//  Programacion Imperativa
//
//  Created by Juan Moreno on 3/10/14.
//  Copyright (c) 2014 Juan Moreno. All rights reserved.
//

/* Ejercicio 22
Tabla de decimales a romanos.
*/

/* print Fahrenheit-Celsius table 
for fahr = 0, 20, ... , 300; floating-point version */

#include <stdio.h>

#define LIMITE 100

int main(void) {
	int num, auxiliar, mirror, lastDigit;
	int sistDecimal;
	int var1, var2, var3;	
	int i, j;
	printf("Decimal:\tRomano:\n");
	for( num = 1; num <= LIMITE; num++) {
		printf("%d\t\t", num);
		auxiliar = num;
		sistDecimal = 0;
		mirror = 0;
		while ( auxiliar != 0 ) { //Invierto para que la represent. no quede al revés
			mirror = mirror*10 + auxiliar%10;
			auxiliar/= 10;
			sistDecimal++; //Por cada cifra en el número original suma
		}
		for ( i=sistDecimal; i>=1; i-- ) { //Conversión de decimal a números romanos
			switch(i) { //Depende de si está en una unidad, decena o centena
				case 1: var1= 'I';
						var2= 'V';
						var3= 'X';
						break;
				case 2: var1= 'X';
						var2= 'L';
						var3= 'C';
						break;
				case 3: var1= 'C';
						break;
			}
			lastDigit = mirror%10;
			mirror/= 10;
			if ( lastDigit == 4 || lastDigit == 9 )	// En el caso de que esté antes de var 2 o var 3
				printf("%c%c", var1 , lastDigit==9? var3: var2 );
			else {//Considero el caso de <=3 y >=5
				if ( lastDigit >= 5 ) {
					printf("%c", var2);
					lastDigit-=5; //Para que quede la cantidad de iteraciones en el prox. instrucción
				}
					for ( j=0; j!=lastDigit; j++) /*En el caso de >=5 agregan I a la derecha V*/ 
						printf("%c", var1);		  /*Si es <=3 no se toma en cuenta y se imprimen solo I*/
			} /*Todos los casos anteriores están ordenados así porque de otra manera podría haber error
              																		 de representación*/
		}
		putchar('\n');
	}
}