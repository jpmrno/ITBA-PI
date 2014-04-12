//
//  Ej 14.c
//  Programacion Imperativa
//
//  Created by Juan Moreno on 3/10/14.
//  Copyright (c) 2014 Juan Moreno. All rights reserved.
//

/* Ejercicio 14
Un número IP identifica en una red TCP/IP a un host particular (puede ser una computadora, impresora, router, cámara de seguridad, etc.). Todo número IP está compuesto de 32 bits, donde parte de ese número (una cantidad arbitraria de bits a la izquierda del número) identifican la red a la que pertenece y el resto de los bits identifican al host. Si bien el número se almacena como un entero sin signo de 4 bytes, se lo presenta al usuario en 4 grupos de números decimales

La función debe imprimir en salida estándar el número de red y el número de host correspondientes al parámetro ip.
*/

#include <stdio.h>
#include "getnum.h"

void infoNet(unsigned long ip, unsigned int bitsNet);

int main(void) {
	unsigned long ip = 0x10FF1112;
	unsigned int bitsNet;

	bitsNet = getint("Cantidad de bits que identifican la red: ");
	infoNet(ip, bitsNet);
}

void infoNet(unsigned long ip, unsigned int bitsNet) {
	unsigned long hostBin, redBin, decalaje = 0xFFFFFFFF;
	unsigned short host[4], red[4];
	int i;

	/*
	unsigned long preNum;
	int bits;
	printf("Host:\n");
	hostBin = ip & (0xFFFFFFFF << (32 - bitsNet));
	redBin = ip & (decalaje >> bitsNet);
	for (bits = 6, i = 0; i < 4; bits-=2, i++) {
		preNum = hostBin & (0xFFFFFFFF << (bits * 4));
		host[i] = (preNum >> (bits * 4)) & 0xFF;
		printf("%d ", host[i]);
	}
	printf("\nRed:\n");
	for (bits = 6, i = 0; i < 4; bits-=2, i++) {
		preNum = redBin & (0xFFFFFFFF << (bits * 4));
		red[i] = (preNum >> (bits * 4)) & 0xFF;
		printf("%d ", red[i]);
	}
	printf("\n");*/

	printf("Host:\n");
	hostBin = ip & (0xFFFFFFFF << (32 - bitsNet));
	redBin = ip & (decalaje >> bitsNet);
	for (i = 3; i >= 0; i--) {
		host[i] = hostBin & 0xFF;
		hostBin = hostBin >> (2 * 4);
	}
	for (i = 0; i < 4; i++) {
		printf("%d ", host[i]);
	}
	printf("\nRed:\n");
	for (i = 3; i >= 0; i--) {
		red[i] = redBin & 0xFF;
		redBin = redBin >> (2 * 4);
	}
	for (i = 0; i < 4; i++) {
		printf("%d ", red[i]);
	}
	printf("\n");
}
