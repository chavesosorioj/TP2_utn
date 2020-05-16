/*
 * menu.c
 *
 *  Created on: May 7, 2020
 *      Author: juliana
 */

#include "tp_menu.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio_ext.h>
#include "tp_utn.h"


// VERIFICAR CON NUMEROS
int menu()
{
     int opcion;

    printf("\n******MENU*******\n\n");

    printf(" - 1  - ALTAS\n\n");
    printf(" - 2  - BAJAS\n\n");
    printf(" - 3  - MODIFICAR\n\n");
    printf(" - 4  - MOSTRAR\n\n");
    printf(" - 5  - INFORMES\n\n");
    printf(" - 6  - SALIR\n\n");
    __fpurge(stdin);
    scanf("%d",&opcion);

    printf("\n OPCION ELEGIDA: %d\n", opcion);
    return opcion;
}

int subMenuUno()
{
	int opcion;

	printf("\n***INGRESE NÚMERO DE LO QUE DESEA MODIFICAR***\n\n");

	printf(" - 1  - NOMBRE\n\n");
	printf(" - 2  - APELLIDO\n\n");
	printf(" - 3  - SALARIO\n\n");
	printf(" - 4  - SECTOR\n\n");
	__fpurge(stdin);
	scanf("%d",&opcion);

	printf("\nOPCION ELEGIDA: %d\n", opcion);
	return opcion;;
}

int menuDos()
{
	int opcion;

	printf("\n***INGRESE EL INFORME QUE DESEA VER***\n\n");

	printf(" - 1  - ORDEN ASCENDENTE\n\n");
	printf(" - 2  - ORDEN DESCENDENTE\n\n");
	printf(" - 3  - SALARIO TOTAL\n\n");
	printf(" - 4  - SALARIO PROMEDIO\n\n");
	printf(" - 5  - CANTIDAD DE EMPLEADOS CON SALARIO PROMEDIO\n\n");
	printf(" - 6  - SALIR\n\n");
	__fpurge(stdin);
	scanf("%d",&opcion);

	printf("\nOPCION ELEGIDA: %d\n", opcion);
	return opcion;;
}
