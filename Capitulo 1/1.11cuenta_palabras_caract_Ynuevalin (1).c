/*
Programa:			Cuenta las palabras, caracteres y saltos de linea

Fecha creacion: 	11/05/2020
Programador:		Ali Cruz M - ali.cruz@me.com
Cambios:
	# 20/09/2020   -Se especifica en la salida en pantalla el significado de la impresion con mejor detalle.
*/



#include <stdio.h>
#define IN 1 // Dentro de la palabra
#define OUT 0 // Fuera de la palabra

int main()
{
	int c, nl, nw, nc, estatus;

	nl = nw = nc = 0;

	estatus = OUT;
	while ((c = getchar()) != EOF)
	{
		++nc;

		if (c == ' ' || c == '\n' || c == '\t') 		//Termina de comprobar cuando encuentra la primer expresion verdadera.
			estatus = OUT;		
		else if (estatus == OUT)
		{
			estatus = IN;
			++nw;
		}

		if (c == '\n')
		{
			++nl;
			printf("Lineas: %d Palabras: %d Caracteres: %d\n", nl, nw, nc);
			nl = nw = nc = 0;
		}
	}	
}