/*
Programa:			Copia la entrada desde el teclado y lo imprime en pantalla

Fecha creacion: 	06/05/2020
Programador:		Ali Cruz M - ali.cruz@me.com
Cambios:

*/

#include <stdio.h>

int main()
{
	int c;
	
	c = getchar();
	while (c != EOF) 
	{
		putchar(c);
		c = getchar();
	}
}
