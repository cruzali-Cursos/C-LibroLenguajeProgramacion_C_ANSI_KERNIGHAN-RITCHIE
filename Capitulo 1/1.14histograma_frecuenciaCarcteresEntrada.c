/*
Programa:			Contabilizar frecuencia de caracteres capturados y mostrar histograma -incluye espacios en blanco
					y saltos de linea-.

Fecha creacion: 	31/05/2020
Programador:		Ali Cruz M - ali.cruz@me.com
Cambios:
	# 27/09/2020  	- Inicializar array sin usar for.

*/


#include <stdio.h>

int main()
{
	int g, h, i, k, c, pa, lcmr;			//pa = posicion array, lcmr = longit. caract. mas repetido, c = caracter
	g = h = i = k = c = pa = lcmr = 0;
	// g, h, i, k = contadores auxiliares en estructuras de repeticion.

	int arr_car[150] = {0};				// Array caracteres unicos.
	int arr_ocu[150] = {0};				// Array frecuencias por caracter.

	while((c = getchar()) != EOF)
	{
		pa++;							// Otro caracter y avanzamos una posición en el arr_car.
		for(i = 0; i < pa; i++)
		{
			if (c == arr_car[i])		//Comparamos el nuevo caracter con los valores de arr_car.
			{
				// caracter encontrado
				arr_ocu[i] = (arr_ocu[i] + 1);		// Incrementar conteo coincidencia caracter.

				if (lcmr > arr_ocu[i])	// Averiguar la frecuencia mas alta.
				{
					lcmr = lcmr;
				} else 
				{
					lcmr = arr_ocu[i];
				}
				i = pa;					// Forzar fin de for.
				pa--;					// Caracter ya existente.
			} else if (i == (pa - 1))	// 
			{
				// Caracter No encontrado. Definir no. ocurrencias.
				if (lcmr > arr_ocu[i])
				{
					lcmr = lcmr;
				} else 
				{
					lcmr = arr_ocu[i] + 1;
				}
				arr_car[i] = c;			// Guardar nuevo caracter.
				arr_ocu[i] = 1;			// Guardar primer coincidencia de caracter nuevo.
			}
		}
	}


	printf("\n");
	for(k = lcmr; k > 0; k--)			// Comenzamos con la frecuencia mas alta.
	{
		for(h = 0; h < pa; h++)			// Longitudes guardadas en el array
		{
			// Determinar caracter a impimir de a cuerdo a longitud de la ocurrencia seleccionada.
			if (arr_ocu[h] >= lcmr)
			{
				printf("\t*");
			} else
			{
				printf("\t ");
			}
		}
		lcmr--;							// Siguiente ocurrencia menor.
		printf("\n");
	}

	for(g = 0; g < pa; g++)
	{
		printf("________");
	}

	printf("\n caracteres: %d \n", pa);
}