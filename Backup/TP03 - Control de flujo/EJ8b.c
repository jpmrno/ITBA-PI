//
//  Ej 8b.c
//  Programacion Imperativa
//
//  Created by Juan Moreno on 3/10/14.
//  Copyright (c) 2014 Juan Moreno. All rights reserved.
//

/* Ejercicio 18
1-4) Modify the temperature convertion program: Celsius to Fahr
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
	celsius = LOWER;
	printf("Cels.\tFahr.\n");
	while (celsius <= UPPER) {
		fahr = ((9.0 / 5.0) * celsius) + 32; 
		printf("%.1f\t%.1f\n", celsius, fahr); 
		celsius+= STEP;
	}
	return 0;
}