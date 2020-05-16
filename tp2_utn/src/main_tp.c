/*
 ============================================================================
 Name        : tp2_utn.c
 Objetivo:  *Manejo de arrays
 	 	 	*Manejo de pasaje por referencia
 	 	 	*Manejo de estructuras

 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio_ext.h>

#include "arrayEmpleados.h"
#include "tp_utn.h"
#include "tp_menu.h"
#include "informes.h"

int main() {

	int opcion;
	int seguirEmp;
	int opcionDos;
	int supPromedio;
	float totalSalario;
	float promedio;


	eEmpleados pEmpleados[TAM_E];

	inicializar_empleados(pEmpleados, TAM_E);
	//hardcodeo(pEmpleados);
	//mostrarEmpleados(pEmpleados, TAM_E);

	while(opcion !=6)
	{
		opcion = menu();

		switch(opcion)
		{
			case 1:
				while(seguirEmp != 2)
				{
					altaEmpleado(pEmpleados, TAM_E);
					seguirEmp =agregarMasEmpleados();

				}
				break;

			case 2:
				darBaja(pEmpleados, TAM_E);
				break;

			case 3:
				modificar(pEmpleados, TAM_E);
				break;

			case 4:
				mostrarEmpleados(pEmpleados, TAM_E);
				break;

			case 5:
			{
				printf("\n\tINFORMES\t\n");
				while(opcionDos !=6)
				{	opcionDos =menuDos();
					switch(opcionDos)
					{
					case 1:
						{
							empleados_ordenar(pEmpleados, TAM_E, 1);
							empleados_mostrarOrden(pEmpleados, TAM_E);
						}
						break;
					case 2:
						{
							empleados_ordenar(pEmpleados, TAM_E, 2);
							empleados_mostrarOrden(pEmpleados, TAM_E);
						}
						break;
					case 3:
						{
							if((cantidadOcupado(pEmpleados, TAM_E))==1)
							{
								totalSalario = totalSAlario(pEmpleados, TAM_E);
								printf("\nEl salario total es de: %.2f \n",totalSalario);
							}
						}
						break;
					case 4:
						{
							if((cantidadOcupado(pEmpleados, TAM_E))==1)
							{
								promedio=	promedioSalario(pEmpleados, TAM_E);
								printf("\nEl salario promedio es de: %.2f \n",promedio);
							}
						}
						break;
					case 5:
						{
							if((cantidadOcupado(pEmpleados, TAM_E))==1)
							{
								supPromedio = superanPromedio(pEmpleados,TAM_E);
								printf("\nLa cantidad de empleados con salario promedio es de: %d \n",supPromedio);
							}
						}
						break;
					}// fin switch
				}// fin del while case 5
				}
			break;
		}//fin de switch

	}//fin while

	return EXIT_SUCCESS;
}

