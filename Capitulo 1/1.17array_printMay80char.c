/*
Programa:			Imprime sólo lineas mayores a 80 caracteres. 
Fecha creacion: 	24/07/2020
Programador:		Ali Cruz M - ali.cruz@me.com
Cambios:
	#
*/

#include <stdio.h>
#define MAXLENGTH 1500
#define LIMITARRAY 80

int getLengthChar(char arr_new_line[], int length_arr);

int main()
{
	int new_line_l;
	char arr_new_l[MAXLENGTH] = {0};
	new_line_l = 0;

	while ((new_line_l = getLengthChar(arr_new_l, MAXLENGTH)) > 0)
	{		
		if (new_line_l > LIMITARRAY)
		{
			printf("Linea mayor a %d caracteres: Size: %d, - Contenido: %s \n", LIMITARRAY, new_line_l, arr_new_l);
		}
	}

	printf("Tamaño: %d, - Contenido: %s \n", new_line_l, arr_new_l);
	return 0;
}

int getLengthChar(char arr_new_line[], int length_arr)
{
	int i = 0;
	int c = 0;

	for (i = 0; i <= length_arr - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		arr_new_line[i] = c;

	// Si hay salto de linea defino final del array con \0
	// Si solo existe un salto de linea en toda la entrada el array se "limpia"
	// porque se agrega \0 en la posición 0 del array.
	if (c == '\n')
	{
		arr_new_line[i] = '\0';
		++i;
	}

	// Si no se ingresa ningun caracter i vale 0, si se ingresa un salto de linea i vale 1
	// Si el contenido del input es mas largo que el tamaño del array entonces se desborda y
	// actua de forma inesperada. 
	return i;
}