/*
Programa:			Imprime el texto introducido separando cada palabra en una nueva linea

Fecha creacion: 	11/05/2020
Programador:		Ali Cruz M - ali.cruz@me.com
Cambios:
	# 
*/

#include <stdio.h>

int main()
{
	int c;

	while((c = getchar()) != EOF)
	{
		if (c == ' ' || c == '\n' || c == '\t')
		{
			putchar('\n');
		}
		putchar(c);		
	}
}