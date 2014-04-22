//
//  Ej 8a.c
//  Programacion Imperativa
//
//  Created by Juan Moreno on 3/10/14.
//  Copyright (c) 2014 Juan Moreno. All rights reserved.
//

/* Ejercicio 18
1-3) Modify the temperature convertion program to print heading above the table
*/

/* print Fahrenheit-Celsius table 
for fahr = 0, 20, ... , 300; floating-point version */

#include <stdio.h>
#include "getnum.h"

#define LOWER 0
#define UPPER 300
#define STEP 20

int main(void) {
	float fahr, celsius; 
	fahr = LOWER;
	printf("F.\tC.\n"); 
	while (fahr <= UPPER) {
		celsius = (5.0 / 9.0) * (fahr - 32.0); 
		printf("%3.0f\t%6.1f\n", fahr, celsius); 
		fahr+= STEP;
	}
	return 0;
}