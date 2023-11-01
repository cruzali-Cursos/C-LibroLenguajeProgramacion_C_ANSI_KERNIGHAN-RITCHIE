/*
Programa:		Imprime la tabla Celsius a Fahrenheit
Creado:		 	06/05/2020		- Sin hacer uso de funcion.
Modificado:	 	01/06/2020		- Se agregó el uso de una funcion para calcular Fah a Cels
Programador: 	Ali Cruz M - ali.cruz@me.com
*/

#include <stdio.h>
#define LOWER 	0 	/* Limite inferior de la tabla */
#define UPPER 	300 /* Limite superior de la tabla */
#define STEP 	20	/* Tamaño de saltos */

float calculaCelsToFah(float cels);

int main()
{
	float fahr, cels;
	fahr = cels = 0;	

	printf("[ ** Tabla de valores ** ]\n");
	printf("Celsius - Fahrenheit\n");

	cels = LOWER;
	while(cels <= UPPER) {		
		printf("%5.0f %13.2f \n", cels, calculaCelsToFah(cels));
		cels += STEP;
	}
}

float calculaCelsToFah(float cels)
{
	float fahr = 0;

	fahr = (cels * (9.0 / 5.0)) + 32;			//9.0 y 5.0 -colocar el .0 para que se consideren decimales en la operacion.
	return fahr;
}