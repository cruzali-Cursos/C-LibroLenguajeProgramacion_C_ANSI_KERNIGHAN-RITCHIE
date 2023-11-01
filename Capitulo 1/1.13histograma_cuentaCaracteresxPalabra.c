/*
Programa:			Introduce una cadena con o sin saltos de linea y se imprime un histograma 
					con la longitud de cada palabra.

Fecha creacion: 	24/05/2020
Programador:		Ali Cruz M - ali.cruz@me.com
Cambios:
	# 20/09/2020   -Inicializar array longitud_palabras sin usar 'for'. 
*/


#include <stdio.h>

int main()
{
	int c, tcpw, tw, i, j, bw, nw, pa, k, l, tc; // c = caracter, tcpw = total caracteres por palabra, 
		//tw = total palabras, bw = bigger word
		// nw = new word, pa = posicion array, i, j, k, l = auxiliares for, tc = total caracteres.

	int longitud_palabras[100] = {0};

	c = tcpw = tw = i = j = bw = nw = pa = k = l = tc = 0;

	// Count caracters
	while((c = getchar()) != EOF)
	{
		if (c == ' ' || c == '\n' || c == '\t')
		{
			// Detectamos nueva palabra
			++tw;
			longitud_palabras[pa++] = tcpw;	// Guardamos en el array la longitud de la palabra previa.			
			nw = tcpw;
			if (bw > nw)
			{
				bw = bw;		// La nueva palabra es mas chica que la mas grande guardada previamente.
			} else 
			{
				bw = nw;		// La nueva palabra es mas grande que todas las anteriores.
			}
			tcpw = 0;
		} else
		{
			++tcpw;				// Conteo de caracteres dentro de la misma palabra.
		}
		tc++;
	}

	// print histograma
		// La palabra mas grande
		for(j = bw; j > 0; j--)
		{
			// El total de palabras
			for(k = 0; k < tw; k++)
			{
				// Comparo la primera longitud guardada vs la palabra mas grande.
				if (longitud_palabras[k] < j && j > 1)
					printf("\t ");								// No es la palabra mas grande.
				else if (longitud_palabras[k] == 0 && j == 1)
					printf("\t_");								// No hay mas longitudes guardadas en el array. Palabras con longitud 1.
				else
					printf("\t*");								// Long. palabra selec. coincide con long. palabra mas larga.
			}
			printf("\n");
		}

		for(l = 0; l < tw; l++)
		{
			printf("________");
		}
	printf("\n tc = %d, tw = %d,  bw = %d \n", tc, tw, bw);
}
