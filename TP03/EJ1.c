//
//  Ej 1.c
//  Programacion Imperativa
//
//  Created by Juan Moreno on 3/10/14.
//  Copyright (c) 2014 Juan Moreno. All rights reserved.
//

/* Ejercicio 1
Leer un caracter desde la entrada estándar e imprimir por salida estándar si el caracter 
es una letra o no y, en caso de ser una letra, indicar si es letra mayúscula o minúscula, 
sin tener en cuenta el caracter ‘ñ’. (En no más de 15 líneas). */

#include <stdio.h>
#include "getnum.h"

int main() {
    printf("Ingresar un caracter:\n");
    int c = getchar();
    if (c >= 'a' && c <= 'z')
        printf("El caracter es una minuscula.\n");
    else if (c >= 'A' && c <= 'Z')
        printf("El caracter es una mayuscula.\n");
    else if (c >= '0' && c <= '9')
        printf("Es un numero.\n");
    else
        printf("Es un simbolo.\n");
    return 0;
}