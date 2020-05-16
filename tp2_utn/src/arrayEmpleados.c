/*
 * empleados.c
 *
 *  Created on: May 9, 2020
 *      Author: juliana
 */
#include "arrayEmpleados.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio_ext.h>
#include "tp_utn.h"
#include "tp_menu.h"

void inicializar_empleados(eEmpleados lista[], int tam)
{
	int i;
	for(i=0; i<tam;i++)
		{
			lista[i].isEmpty=LIBRE;
		}
}

void hardcodeo(eEmpleados* lista)
{
    int harcodeo = 6;

    int ID[6]                      ={2000,2001,2002,2003,2004,2005};
    char nombre[6][52]        ={"Eduardo","Maria", "Cristina", "Sabrina", "Gabriel","Tomas"};
    char apellido[6][51]={"Casarero","Gomez", "Sanchez", "Villar", "Chaves","Gallegos"};
    float salario[6]                ={40500.50,75800.60,34000.30,38700.40,24900.50,43800.70};
    int sector[6]                  ={5,7,5,3,1,7};

    for(int i=0; i<harcodeo; i++)
    {
    	lista[i].id=ID[i];
        strcpy(lista[i].nombre, nombre[i]);
        strcpy(lista[i].apellido, apellido[i]);
        lista[i].salario=salario[i];
        lista[i].sector=sector[i];
        lista[i].isEmpty=OCUPADO;
    }
}

int espacioLibre(eEmpleados lista[], int tam)
{	int i;
	int retorno=-1;
	for(i=0; i<tam;i++)
	{
		if(lista[i].isEmpty== LIBRE)
		{
			return i;
			break;
		}
	}
	return retorno;
}


int altaEmpleado(eEmpleados lista[], int tam)
{
	eEmpleados nuevoEmpleado;
	int retorno =-1;
	char nombre[50];
	char apellido[50];
	float salario;
	int sector;
	int indice;


	if(lista != NULL && tam >0)
	{
		system("clear");
		__fpurge(stdin);

		printf("\n\t|*********ALTA*********|\t\n");

		indice = espacioLibre(lista, TAM_E);
		if(indice==-1)
		{
			printf("\n**********No hay espacios libres**********\n");
		}
		else
		{	//**********************************VALIDAR LO INGRESADO
			getStringLetras("\n\tIngrese el nombre del empleado\t\n","\n\tError, debe contener letras\t\n", nombre);
			getStringLetras("\n\tIngrese el apellido del empleado\t\n","\n\tError, debe contener letras\t\n", apellido);
			salario= esFlotante("\n\tIngrese el salario\t\n");
			sector= validaEntero("\n\tIngrese el sector del empleado\t\n");

			nuevoEmpleado.id=indice;
			strcpy(nuevoEmpleado.nombre,nombre);
			strcpy(nuevoEmpleado.apellido,apellido);
			nuevoEmpleado.salario=salario;
			nuevoEmpleado.sector=sector;
			nuevoEmpleado.isEmpty=OCUPADO;
			lista[indice] =nuevoEmpleado;

		printf("\n|**********CARGA EXITOSA**********|\n");
		retorno=1;
	}

	}
	return retorno;
}
void mostrarEmpleado(eEmpleados lista)
{
	printf("\n\t%d\t\t%s\t\t%s\t\t%.2f\t\t%d\n",
			lista.id,
			lista.nombre,
			lista.apellido,
			lista.salario,
			lista.sector
	);

}
void mostrarEmpleados(eEmpleados list[],int len)
{
    system("clear");
    printf("\n\tID\t\tNOMBRE\t\tAPELLIDO\t\tSALARIO\t\tSECTOR\t\n");

    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty == OCUPADO)
        {
        	mostrarEmpleado(list[i]);
        }
    }

}

int buscarId(int* id, int tam, eEmpleados lista[])
{
	int indice=-1;
	int i;
	for(i=0;i<tam;i++)
	{
		if(lista[i].isEmpty == OCUPADO && lista[i].id==*id)
		{
			indice=i;
			break;
		}
	}
	return indice;
}
int cantidadOcupado(eEmpleados* lista, int tam)
{

    int cantOcupados=0;
    int i;

    for(i=0; i<tam; i++)
    {
        if(lista[i].isEmpty==OCUPADO)
        {
            cantOcupados =1;
            break;
        }
    }
    return cantOcupados;
}

int darBaja(eEmpleados lista[], int tam)
{
	int retorno=-1;
	int indice;
	int verifBaja=0;
	int verifIndice;
	int aux;

	system("clear");

	printf("|*********BAJA*********|");
	verifIndice = cantidadOcupado(lista, TAM_E);
	if(verifIndice==0)
	{
		printf("\n\tNo hay empleados para dar de baja\t\n");
	}
	else
	{
		aux = validaEntero("\n\tIngrese el número de ID que quiere dar de baja\t\n");
		indice = buscarId(&aux, TAM_E, lista);

		if(indice==-1)
		{
			printf("\n\tNo hay ningun empleado con ese ID\t\n");
		}
		else
		{
			mostrarEmpleado(lista[indice]);
			verifBaja= validaConfirmacion();
			if(verifBaja==1)
			{
				printf("\n\tBaja exitosa\t\n");
				lista[indice].isEmpty=LIBRE;
				retorno=1;
			}
			else
			{
					printf("\n\tSe ha cancelado la baja\t\n");
			}
		}

	}

	return retorno;
}


int modificar(eEmpleados lista[], int tam)
{
	int retorno = -1;
	int buscaId;
	int verificacion;
	int auxIndice;
	int confirmacion;
	char nombre[51];
	char apellido[51];

	system("clear");
	printf("\n*********MODIFICACION*********\n");


	verificacion = cantidadOcupado(lista, TAM_E);
	if(verificacion ==0)
	{
		printf("\n\tNo hay datos para modificar\t\n");
	}
	else
	{
		auxIndice = validaEntero("\n\tIngrese el id que quiere modificar\t\n");
		buscaId = buscarId(&auxIndice, tam, lista);
		if(buscaId == -1)
		{
			printf("\n\tNo hay empleado con ese id\t\n");
		}
		else
		{
			printf("\n\tSe modificará el ID %d\n\t",auxIndice);

			switch(subMenuUno())
			{
				case 1:
				{
					system("clear");
					confirmacion = validaConfirmacion();
					if(confirmacion == 1 )
					{
						getStringLetras("\n\tIngrese el nombre del empleado\t\n", "\n\tError, debe contener letras. VUelva a intentarlo", nombre);
						strcpy(lista[auxIndice].nombre,nombre);
						printf("\n\tSe realizo la modificación\t\n");
						retorno=1;
					}
					else
					{
						printf("\n\tSe cancelo la modificación\t\n");
					}
				}
					break;
				case 2:
				{
					system("clear");
					confirmacion = validaConfirmacion();
					if(confirmacion == 1 )
					{
						getStringLetras("\n\tIngrese el apellido del empleado\t\n", "\n\tError, debe contener letras. VUelva a intentarlo", apellido);
						strcpy(lista[auxIndice].apellido,apellido);
						printf("\n\tSe realizo la modificación\t\n");
						retorno = 1;
					}
					else
					{
						printf("\n\tSe cancelo la modificación\t\n");
					}
				}
					break;
				case 3:
				{
					system("clear");
					confirmacion = validaConfirmacion();
					if(confirmacion==1)
					{
						lista[auxIndice].salario = esFlotante("\nIngrese el nuevo salario\n");
						printf("\n\tSe realizo la modificación\t\n");
						retorno=1;
					}
					else
					{
						printf("\n\tSe cancelo la modificación\t\n");
					}
				}
					break;
				case 4:
				{
					system("clear");
					confirmacion = validaConfirmacion();
					if(confirmacion==1)
					{
						lista[auxIndice].sector= validaEntero("\nIngrese el nuevo sector\n");
						printf("\n\tSe realizo la modificación\t\n");
						retorno =1;
					}
					else
					{{
						printf("\n\tSe cancelo la modificación\t\n");
					}
					}
				}
					break;

			}
		}
	}
	return retorno;
}

int agregarMasEmpleados(void)
{
	int validar;


	validar =validaEntero("\nDesea continuar agregando empleados? Ingrese:\n1 - Si\n2 - No\n");
	while(validar != 1 && validar != 2)
	{
			printf("Error. Debe ingresar\n 1 - Si\n2 - No");
			__fpurge(stdin);
			scanf("%d",&validar);
	}
	return validar;
}
