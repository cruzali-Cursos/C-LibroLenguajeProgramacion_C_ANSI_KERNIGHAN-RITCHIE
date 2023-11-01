/*
Cuenta las palabras, caracteres y saltos de linea
ACM 11/05/2020
*/

#include <stdio.h>
#define IN 1 // Dentro de la palabra
#define OUT 0 // Fuera de la palabra

int main()
{
	int c, nl, nw, nc, estatus;

	nl = nw = nc = 0;

	estatus = OUT;
	while((c = getchar()) != EOF)
	{
		++nc;
		if(c == '\n')
			++nl;
		if(c == ' ' || c == '\n' || c == '\t')
			estatus = OUT;
		else if(estatus == OUT)
		{
			estatus = IN;
			++nw;
		}
		printf("Lineas: %d Palabras: %d Caracteres: %d\n", nl, nw, nc);
	}	
}