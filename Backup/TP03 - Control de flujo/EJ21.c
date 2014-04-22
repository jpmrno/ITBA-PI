//
//  Ej 21.c
//  Programacion Imperativa
//
//  Created by Juan Moreno on 3/10/14.
//  Copyright (c) 2014 Juan Moreno. All rights reserved.
//

/* Ejercicio 21
Escribir un programa que lea un número entero, y escriba por salida estándar 
dicho número y un cartel indicando si es capicúa o no. (En no más de 10 líneas)
*/

#include <stdio.h>
#include "getnum.h"

int main(void) {
    int numero = 0, unidad, reverseNumero = 0, saveNumero;
    numero = getint("Ingresar un numero entero: ");
    saveNumero = numero;
    while(numero != 0){
        unidad = numero % 10;
        reverseNumero = reverseNumero * 10 + unidad;
        numero /= 10;
    }
    if(reverseNumero == saveNumero)
        printf("El numero %d es capicua.\n", saveNumero);
    else
        printf("El numero %d no es capicua.\n", saveNumero);
    return 0;
}
