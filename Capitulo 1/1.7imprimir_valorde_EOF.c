/*
Programa:			Imprimir valor de EOF

Fecha creacion: 	07/05/2020
Programador:		Ali Cruz M - ali.cruz@me.com
Cambios:
	# 
*/


#include <stdio.h>

int main()
{
	int c;
	float val_eof;
	c = val_eof = 0;

	printf("%2f \n", EOF);					// Valor EOF por default -1

	while (val_eof = (getchar() != EOF))
	{
		printf("EOF: %2f \n", val_eof); 	// EOF = 1 sino se ha llegado al fin del stream.
	}
	
	printf("EOF: %2f \n", val_eof);			// EOF = 0 si se llego al fin del stream.
}