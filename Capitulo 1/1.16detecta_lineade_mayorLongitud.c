/*
* Programa:			Compara las lineas ingresadas para identificar la de mayor
					longitud e imprimir su contenido.
* Fecha creacion: 	22/06/2020
* Programador:		Ali Cruz M - ali.cruz@me.com
* Cambios:
* 	# 23/06/2020	- 
* 	# Corregir: 	1. Si la longitud de la linea es igual o mayor a MAXLENGTH 
*						se sobreescribe	en la posición de \n del arr_pl
*/


#include <stdio.h>
#define MAXLENGTH 8

// Funcionnes prototipo.
int getline_acm(char ar_nl[], int max_l);

void copy(char arr_to[], char arr_from[]);

/*
newline_length  Nueva linea mas larga.
previousline_length Linea mas larga.
ar_nl Nueva linea mas larga recientemente identificada
ar_pl La linea mas larga al momento ya identificada.
*/
int main()
{
	int newline_length;
	int previousline_length;
	char ar_nl[MAXLENGTH] = {0};
	char ar_pl[MAXLENGTH] = {0};
	newline_length = previousline_length = 0;
	
	while ((newline_length = getline_acm(ar_nl, MAXLENGTH)) > 0)
		if (newline_length > previousline_length)
		{
			previousline_length = newline_length;
			// Sobre escribo los valores de ar_nl sobre ar_pl
			copy(ar_pl, ar_nl);
		}
	if (previousline_length >= 0)
	{
		if(previousline_length > MAXLENGTH)
		{
			printf("Fuera del limite del Array! Rebase por :");
			printf("%d Length = %d. Arr: %s  \n", previousline_length - MAXLENGTH, previousline_length, ar_pl);
		} else
		{
			printf("Length: %d Valor: %s \n", previousline_length, ar_pl);
		}
	}
	
	return 0;
}

/*
i contador caracteres en la linea
c caracter
*/

int getline_acm(char ar_nl[], int max_l)
{	
	int tmp = (max_l - 1);
	int i, c;
	i = c = 0;

	for(i = 0; i <= max_l - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		ar_nl[i] = c;
	}
	
	if(c == '\n') {
		if(i <= max_l - 1)
			ar_nl[i] = c;
		++i;
	}

	

	if(i > max_l - 1 && c != '\n') {
		while((c = getchar()) != '\n')
			++i;			
	}
	ar_nl[i] = '\0';
	
	if(i == max_l && c != '\n')
				++i;
	
	return i;
}

// Sobre escribo los valores en el array de la linea previa mas larga con los valores del 
// array de la nueva linea mas larga
void copy(char ar_pl[], char ar_nl[])
{
	int i = 0;

	while ((ar_pl[i] = ar_nl[i]) != '\0') 			// Posible overflow
		++i;
}
