/*
Programa:			Imprime tabla de valores Fahrenheit - Celsius

Fecha creacion: 	06/05/2020
Programador:		Ali Cruz M - ali.cruz@me.com
Cambios:
	# 
*/


#include <stdio.h>

int main() {

	int step, lower, upper;
	float celsius, fahr;

	lower = 0; /* Limite inferior */
	upper = 300; /* Limite superior */
	step = 20;

	printf("[*** Tabla valores Fahrenheit - Celsius ***]\n");
	printf("Fahrenheit - Celsius \n");

	for (fahr = lower; fahr < upper; fahr = fahr + step) {
		printf("%5.0f %11.2f \n", fahr, (fahr - 32) * (5.0 / 9.0));		//%5.0f -> Sin decimales y con 5 espacios para alojar caracteres.
																				//%11.2f -> 11 espacios y 2 decimales.
	}
}
