/*
Programa:			Cuenta espacios en blanco, tabuladores y nuevas lineas.
Fecha creacion: 	07/05/2020
Programador:		Ali Cruz M - ali.cruz@me.com
Cambios:
	# 19/09/2020   -Se especifica en la salida en pantalla el significado de la impresion.
*/


#include <stdio.h>

int main() 
{
	int c, counters;
	counters = 0;

	while ((c = getchar()) != EOF) {
		if (c == '\n' || c == ' ' || c == '\t') {
			++counters;
		}

		if (c == '\n')
		{			
			printf("Suma total de espacios en blanco, tabuladores y nuevas lineas: %d \n", counters);
			counters = 0;
		}
	}
}