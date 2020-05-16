/*
 * informes.c
 *
 *  Created on: May 13, 2020
 *      Author: juliana
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

int empleados_ordenar(eEmpleados lista[], int tam, int orden)
{
	int retorno=-1;
	eEmpleados aux;
	int verificacion;
	int i,j;

	system("clear");
	printf("\n*********ORDEN EMPLEADOS*********\n");

	verificacion = cantidadOcupado(lista, TAM_E);
	if(verificacion ==0)
	{
		printf("\n\tNo hay datos para ordenar\t\n");
	}
	else
	{

		if(orden==1)
		{
			retorno=1;
			system("clear");
			printf("\n\tOrden ascendente\t\n");

			for(i=0;i<tam-1;i++)
			{
				for(j=i+1; j<tam;j++)
				{
					if(strcmp(lista[i].apellido,lista[j].apellido)>0 && lista[i].isEmpty==OCUPADO && lista[j].isEmpty== OCUPADO)
					{
						aux=lista[i];
						lista[i]=lista[j];
						lista[j]=aux;
					}
				}
			}

		}
		if(orden==2)
		{
			retorno=1;
			system("clear");
			printf("\n\tOrden descendente\t\n");
			for(i=0;i<tam-1;i++)
			{
				for(j=i+1; j<tam;j++)
				{
					if(strcmp(lista[i].apellido,lista[j].apellido)<0 && lista[i].isEmpty==OCUPADO && lista[j].isEmpty== OCUPADO)
					{
						aux=lista[i];
						lista[i]=lista[j];
						lista[j]=aux;
					}
				}
			}
		}
	}

	return retorno;
}

void empleados_mostrarOrden(eEmpleados lista[], int tam)
{
    int i;

    printf("| \n\tAPELLIDO   -      SECTOR\t\n ");

    for(i=0; i<tam; i++)
    {
        if(lista[i].isEmpty==OCUPADO)
        {
            mostrarInforme(lista[i]);
        }
    }

}

void mostrarInforme(eEmpleados lista)
{
	printf("\n      %10s    -      %02d\n",
			lista.apellido,
			lista.sector
	);

}

int superanPromedio(eEmpleados lista[], int tam)
{
	int contador=0;
	int i;
	float promedio;

	promedio = promedioSalario(lista, tam);
	for(i=0;i<tam;i++)
	{
		if(lista[i].isEmpty==OCUPADO && lista[i].salario > promedio)
		{
			contador++;
		}
	}
	return contador;
}

float promedioSalario(eEmpleados lista[], int tam)
{
	float promedio;
	float acumulaSalario=0;
	int contador=0;
	int i;
	for(i=0;i<tam;i++)
		{
			if(lista[i].isEmpty==OCUPADO)
			{
				acumulaSalario = acumulaSalario + lista[i].salario;
				contador++;
			}
		}

	promedio=(acumulaSalario/contador);

	return promedio;
}

float totalSAlario(eEmpleados lista[], int tam)
{
	float acumulaSalario=0;
	int i;

	for(i=0;i<tam;i++)
	{
		if(lista[i].isEmpty==OCUPADO)
		{
			acumulaSalario += lista[i].salario;
		}
	}
	return acumulaSalario;
}
