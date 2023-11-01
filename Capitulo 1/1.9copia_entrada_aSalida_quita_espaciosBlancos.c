/*
Programa:			Programa que copia la entrada y a la salida y quita la cadena de espacios en blanco solo deja un espacio en blanco.
Fecha creacion: 	09/05/2020
Programador:		Ali Cruz M - ali.cruz@me.com
Cambios:
	# 
*/

#include <stdio.h>

int main()
{
	int c, count_space;
	count_space = 0;

	while((c = getchar()) != EOF)
	{
		if (c == ' ') 
		{
			if (count_space == 0)
			{
				// Solo el primer espacio en blanco se imprime.
				putchar(c);
				count_space = 1;
			} else {
				// Quitamos espacio... alteramos el c				
			}
		} else {
			// Todo normal, no es espacio entonces ignoramos el c y reseteamos la bandera de espacios en blanco.			
			count_space = 0;
			putchar(c);
		}
	}
}