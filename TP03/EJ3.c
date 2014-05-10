//
//  Ej 3.c
//  Programacion Imperativa
//
//  Created by Juan Moreno on 3/10/14.
//  Copyright (c) 2014 Juan Moreno. All rights reserved.
//

/* Ejercicio 3
 Una empresa paga a su personal de venta en base a comisiones.  El personal de
 ventas recibe $300 por semana más un porcentaje de las ventas brutas de esa semana.
 
 El porcentaje a aplicar depende del total vendido: si la venta no supera los $1000, no
 hay porcentaje, hasta $2000 es un 5%, hasta $4000 es un 7%, y más de $4000 es un 9%.
 
 Por ejemplo, un vendedor que vende $5000 en una semana, recibe $300 más 9%
 de $5000, o sea un total de $750.
 
 Hacer un programa en C que lea una única variable que indique la suma vendida
 en una semana, e imprima por salida estándar  el monto total a cobrar. Si la suma
 vendida es un valor incorrecto pedir un nuevo valor. (En no más de 15 líneas). */

#include <stdio.h>
#include "getnum.h"

#define FIJOSEMANA 300

int main(void) {
	int sumaVendida, porciento;
	float sueldoSemanal;
	enum limites {PrimerLim=1000, SegundoLim=2000, TercerLim=4000};
	enum porcentajes {menPrimero=0, menSegundo=5, mTercero=7, MayorT=9};
	while ((sumaVendida = getint("Ingrese suma de venta semanal: ")) < 0)
		printf("Suma erronea.\n");
	if(sumaVendida<PrimerLim)
		porciento = menPrimero;
    else if(sumaVendida<SegundoLim)
        porciento = menSegundo;
    else if(sumaVendida<TercerLim)
        porciento = mTercero;
    else
        porciento = MayorT;
	sueldoSemanal = FIJOSEMANA + sumaVendida * (porciento / 100.0);
	//printf("Venta semanal: %d.\n", sumaVendida);
	//printf("Porciento extra: %%%d.\n", porciento);
	printf("Suma: %.2f.\n", sueldoSemanal);
	return 0;
}