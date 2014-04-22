#ifndef _MYLIB_H

#define _MYLIB_H

#define PI 3.14159265

// Calcula el volumen de una esfera
#define VOLESFERA(r) ((4.0/3.0) * PI * (r) * (r) * (r))

// Recibe tres parámetros, asigna al tercer parámetro el mayor de los dos primeros
#define MAXIMO2(a,b,max) (max=((a)>(b)))?(a):(b)

// Recibe 3 parametros, devuelve el maximo de los 3
#define MAXIMO3(a,b,c) (MAXIMO2(a,b,max))>(c)?(max):(c)

// Indica si dicho caracter representa un dígito decimal o no
#define ISDIGIT(c) (((c) >= '0') && ((c) <= '9'))?1:0
 
#endif