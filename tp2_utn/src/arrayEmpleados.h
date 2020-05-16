/*
 * empleados.h
 *
 *  Created on: May 9, 2020
 *      Author: juliana
 */

#ifndef ARRAYEMPLEADOS_H_
#define ARRAYEMPLEADOS_H_

#define TAM_E 1000
#define TAM_NOMBRE 51
#define TAM_APELLIDO 51

#define LIBRE 0
#define OCUPADO 1

typedef struct{
	int id;
	char nombre[51];
	char apellido[51];
	float salario;
	int sector;
	int isEmpty;
}eEmpleados;

/*
 * breif Indica que la posición isEmpty está vacía
 * 		la función pone el flag (isEmpty) en TRUE
 * 		en todas las posiciones del array
 * param lista, array en donde carga isEmpty
 * param tam, tamaño del array
 * return void
 */
void inicializar_empleados(eEmpleados lista[], int tam);

/*
 * breif Harcodea todos los campos de la estructura
 *		a fin de comprobar que los datos se vean
 *		correctamente
 *	param eEmplados, puntero a la estructura
 *	return void
 */

void hardcodeo(eEmpleados* lista);

/*
 * breif busca el primer espacio libre en isEmpty, al encontrarlo rompe la iteración
 * param lista, array en el que busca
 * param tam, tamaño del array
 * return, -1 si no se encontro lugar libre o [i] posicion libre
 */

int espacioLibre(eEmpleados lista[], int tam);
/*
 * breif da de alta un empleado
 * param lista, array a cargar
 * param tam, tamaño del array
 *return -1 si no cargo, 1 si se pudo
 */

int altaEmpleado(eEmpleados lista[], int tam);

/*
 * breif busca el id coincidente entre el pasado por parámetro
 * 		y el cargado en la estructura
 * param id; id a buscar
 * param tam, tamaño del array
 * param lista, array en el que busca
 * return -1 en caso de no haber encontrado coincidencia, o el índice correspondiente con el id
 */
int buscarId(int* id, int tam, eEmpleados lista[]);

/*
 * breif muestra un elemento de la estructura
 * param lista, estructura en la que busca
 * retur void
 */
void mostrarEmpleado(eEmpleados lista);

/*
 * breif muestar todos los empleados delarray
 * param lista, array a mostrar
 * param tam, tamaño del array
 * return void
 */

void mostrarEmpleados(eEmpleados list[],int len);

/*
 * breif da de baja un elemento del array empleados
 * param lista, array en el que busca el campo a dar
 * 		de baja
 * param tam, tamaño del array
 * return -1 si no se logro la baja y 1 si se pudo
 */

int darBaja(eEmpleados lista[], int tam);

/*
 * breif función que busca si empleados cargados y
 * 		lugar disponible para cargar
 * param pEmpleados, estructura en la que busca
 * param tam, tamaño de la estructura
 * return 1 si hay empleados dados de alta o 0 en caso que no lo haya
 */


int cantidadOcupado(eEmpleados* lista, int tam);

/*
 * brief modifica los campos del array
 *param lista, array a modificar
 *param tam, tamaño del array
 *return -1 si no se modifico y 1 si se logro
 */

int modificar(eEmpleados lista[], int tam);

/*
 * brief solicita confirmación al usuario para agregar
 * 		mas empleados
 * 		1 - Si // 2 - No
 * 	param void
 * return 1 o 2
 */

int agregarMasEmpleados(void);

#endif /* ARRAYEMPLEADOS_H_ */
