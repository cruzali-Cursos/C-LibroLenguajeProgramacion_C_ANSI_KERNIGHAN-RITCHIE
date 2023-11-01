/*
Programa:			Copia entrada a la salida reemplazando tabulacion por \t, retroceso por \b y diagonal invertida por \\					

Fecha creacion: 	10/05/2020
Programador:		Ali Cruz M - ali.cruz@me.com
Cambios:
	# 19/09/2020   - Comentarios sobre ASCII y pasar directamente el valor en ascii a putchar.
*/


#include <stdio.h>

int main()
{
	int char1;

	while ((char1 = getchar()) != EOF)
	{
		if (char1 == 9 || char1 == 92)
		{
			if (char1 == 9)			//Tab horizontal
			{
				putchar(92);		//Diagonal invertida				
				putchar(116);		//Letra t
			} else if (char1 == 92) 		//Diagonal invertida
			{				
				putchar(92);				
				putchar(char1);
			}
		} else {
			putchar(char1);
		}
	}
}