//
//  Ej 8d.c
//  Programacion Imperativa
//
//  Created by Juan Moreno on 3/10/14.
//  Copyright (c) 2014 Juan Moreno. All rights reserved.
//

/* Ejercicio 18
1-5) Display ranges of char shor int long signed and unsigned
*/

/* print Fahrenheit-Celsius table 
for fahr = 0, 20, ... , 300; floating-point version */

#include <stdio.h>
#include <limits.h>

int main(void) {
	printf("Signed CHAR: (%d,%d)\n", SCHAR_MIN, SCHAR_MAX);
	printf("Unsigned CHAR: (0,%u)\n\n", UCHAR_MAX);
	printf("Signed SHORT: (%d,%d)\n", SHRT_MIN, SHRT_MAX);
	printf("Unsigned SHORT: (0,%u)\n\n", USHRT_MAX);
	printf("Signed INT: (%d,%d)\n", INT_MIN, INT_MAX);
	printf("Unsigned INT: (0,%u)\n\n", UINT_MAX);
	printf("Signed LONG: (%ld,%ld)\n", LONG_MIN, LONG_MAX);
	printf("Unsigned LONG: (0,%lu)\n\n", ULONG_MAX);
	return 0;
}