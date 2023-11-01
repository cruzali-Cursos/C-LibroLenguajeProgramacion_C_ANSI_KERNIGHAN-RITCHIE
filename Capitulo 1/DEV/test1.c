/*
Programa:			Imprime sólo lineas mayores a 80 caracteres.
Fecha creacion: 	24/07/2020
Programador:		Ali Cruz M - ali.cruz@me.com
Cambios:
	#
*/

#include <stdio.h>
#define MAXLENGTH 8

void copyArr(char to[], char from[]);

int getLengthChar(char arr_new_line[], int length_arr);

int main()
{
	int new_line_l;
	int longest_line_l;
	char arr_long_l[MAXLENGTH] = {0};
	char arr_new_l[MAXLENGTH] = {0};
	new_line_l = longest_line_l = 0;

	while ((new_line_l = getLengthChar(arr_new_l, MAXLENGTH)) > 0)
	{
		if (new_line_l > longest_line_l)
		{
			longest_line_l = new_line_l;
			copyArr(arr_long_l, arr_new_l);
		}

		printf(" While new line: %d, longest line: %d arr_long_l: %s arr_new_l: %s \n", new_line_l, longest_line_l, arr_long_l, arr_new_l);
	}

	printf("new line: %d, longest line: %d \n", new_line_l, longest_line_l);
	return 0;
}

int getLengthChar(char arr_new_line[], int length_arr)
{
	int i = 0;
	int c = 0;

	for (i = 0; i < length_arr - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		arr_new_line[i] = c;

	return i;	
}

void copyArr(char to[], char from[])
{
	int i = 0;

	while ((to[i] = from[i]) != '\0')
		i++;
}
