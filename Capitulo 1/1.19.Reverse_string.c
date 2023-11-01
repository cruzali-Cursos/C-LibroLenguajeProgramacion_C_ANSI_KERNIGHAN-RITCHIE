/*
Programa:			Recibe una cadena de texto para retornarla invertida palabra por palabra
					y solo una linea a la ves.

Fecha creacion: 	30/07/2020
Programador:		Ali Cruz M - ali.cruz@me.com
Cambios:
	# 31/07/2020 - Permitir solo 1 espacio entre palabras.
	# 01/08/2020 - Permitir solo 1 tabuladores entre palabras.
	# 02/08/2020 - Imprimir solo caracteres diferentes a space y salto de linea.
	# 03/08/2020 - Corregir bug si comienza con espacios se cicla...
*/


#include <stdio.h>

#define MAXLENGTH	1000			//Tamaño maximo
#define YES			1
#define NO			0

void reverse_string(char buffer[], int l_new_line);

void array_cleaner(char buffer[]);

int get_char(char buffer[], int max_l);

int main()
{

	int l_new_line = 0;
	// l_new_line = longitud de la nueva linea ingresada.
	char buffer[MAXLENGTH] = {0};

	while ((l_new_line = get_char(buffer, MAXLENGTH)) > 0)
	{
		printf("ARR:%s - l_new_line: %d\n", buffer, l_new_line);
		reverse_string(buffer, l_new_line);		
		//array_cleaner(buffer);
	}

	return 0;
}

// Llena buffer con ayuda de getchar
int get_char(char buffer[], int max_l)
{
	int c, thereis_prev_space, thereis_prev_tab, next;
	next = 0;
	// next = posicion del array para guardar caracter
	thereis_prev_space = thereis_prev_tab = NO;

	// Leer cada caracter ingresado hasta que encuentre salto de linea, EOF o fin del buffer.
	for (int i = 0; i <= max_l - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
	{
		// Guardo un espacio SOLO si no existe un espacio previo.
		if (c == ' ' && thereis_prev_space == NO)
		{
			thereis_prev_space = YES;
			buffer[next++] = '_';
		}

		// Guardo un tab SOLO sino existe un Tab previo.
		if (c == '\t' && thereis_prev_tab == NO)
		{
			thereis_prev_tab = YES;
			buffer[next++] = '*';
		}

		// Si no es espacio ni tab entonces guardo caracter y reseteo los flags
		//  de tab y w space.
		if (c != ' ' && c != '\t')
		{
			buffer[next++] = c;
			thereis_prev_space = NO;
			thereis_prev_tab = NO;
		}
	}

	// Guardo el ultimo caracter y luego indico final del array.
	// Si es una linea vacia se indica el fin de linea.
	if (c == '\n')
	{
		buffer[next++] = '\n';
		buffer[next] = '\0';
	}

	return next;
}


// Recorro el array desde el inicio hasta el primer espacio en blanco o tab.
// Si comienza con espacio en blanco
void reverse_string(char buffer[], int l_new_line)
{
	int i, next, c, pos_st_found;
	i = next = pos_st_found = 0;
	// next = Posicion en el array.
	// l_new_line = longitud linea ingresada
	// pos_st_found = Posicion espacio en blanco o tab encontrado.
	// _ = espacio, - = salto linea, * = tabulador.

	while (l_new_line >= 2)
	{
		// Si comienza con espacio blanco o tabulador los ignoro hasta encontrar el primer caracter.
		while ((c = buffer[next]) == '_' || c == '*')
			next++;

		// Termino recorrer array cuando encuentro espacio, tab o nueva linea.
		while (c != '_' && c != '*' && c != '\n')
			c = buffer[next++];

		// Si por lo menos existe un caracter en el arr y el ultimo caracter
		// leido es tab, space, nueva linea
		if (next > 0 && (c == '-' || c == '*' || c == '_'))
		{
			// Me regreso una posicion en el array
			next -= 2;
			// Recorro array desde la posicion anterior al primer espacio
			// tab o salto de linea encontrado y hasta el espacio o tab 
			// encontrado anteriormente ó hasta la posicion cero del array.
			for (i = next; i >= pos_st_found; --i)
			{
				if (buffer[i] == '-')
					printf("-");
				
				if (buffer[i] == '_')
					printf("_");

				if (buffer[i] == '*')
					printf("*");

				printf("%c", buffer[i]);
			}
		}

		pos_st_found = next + 1;

		if (c == '_' || c == '*')
			next++;

		c = buffer[next];

		l_new_line = l_new_line - pos_st_found;
	}

	printf("\n");
}


void array_cleaner(char buffer[])
{

	buffer[0] = '\0';
}

/*
BUFF = [h] [o] [l] [a] [_] [q] [_] [p] [\n] [\n] [] [] [][][] [][][]
		0   1   2   3   4   5   6   7    8   9   10  11   12 13 14  15

		hola que pasa aqui
*/