/*
Programa:					Quita los espacios en blanco y tabuladores que estan al final de la linea 
							de entrada arbitrariamente largas y borra lineas en blanco. 
Fecha de Creacion:			26/07/2020
Fecha de Modificacion:		26/07/2020
Programador:				Ali Cruz - ali.cruz@me.com
*/

#include <stdio.h>
#define LIMITARR1 999

int getcharacm(char buffer[], int li);

void removelastspaceandtab(char arr[], int lpa);

int main() 
{
	int li;
	// li = length input
	li = 0;
	char buffer[LIMITARR1] = {0};

	while ((li = getcharacm(buffer, LIMITARR1)) > 0)
	{
		removelastspaceandtab(buffer, li - 1);
		printf("%s", buffer);
		// Limpio array para un nuevo uso
		buffer[0] = '\0';
	}	

	return 0;
}

int getcharacm(char arr[], int maxl)
{
	int i, c;
	i = c = 0;

	// se guarca caracteres leidos hasta que se encuentra EOF, nueva linea 
	// o limite del array
	for (i = 0; i <= maxl - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		arr[i] = c;

	// nueva linea se guarda en el array.
	if (c == '\n')
	{
		arr[i++] = '\n';
		arr[i++] = '\0';
	}

	// Se señala el final del array
	//arr[++i] = '\0';

	return i;
}

// Le paso como argumento el array y la ultima posición del mismo
// lpa = last position array
void removelastspaceandtab(char arr[], int lpa)
{
	int i = 0;
	int c;

	// Recorro el array desde el final hacia el inicio para ir quitando tabs y
	// espacios en blanco
	for (i = lpa; i >= 0; i--)
	{
		c = arr[i];

		// Si resulta que estamos en la primer posición y hay nueva 
		// linea entonces se marca el final del array con \0
		if (lpa == 0 && c == '\n')
		{
			// Coloco el salto de linea y la terminación.
			arr[i++] = '\n';
			arr[i++] = '\0';
		}

		// si se lee un tab o espacio en blanco, se marca el final del array
		// no es necesario hacer esto.
		if (c == '\t' || c == ' ')
		{
			// usar '_' en lugar de \0 para visualizar su funcion.
			arr[i] = '\0';
		}

		// si se encuentra un caracter diferente a tab, espacio blanco o salto de linea
		// entonces se coloca salto de linea en la posición siguiente y se termina la busqueda
		if (c != '\t' && c != ' ' && c != '\n')
		{
			arr[++i] = '\n';
			arr[++i] = '\0';
			i = -1;
		}
	}	
}
