/*
 * informes.h
 *
 *  Created on: May 13, 2020
 *      Author: juliana
 */

#ifndef INFORMES_H_
#define INFORMES_H_
/*
 * brief ordena empleados según el campo apellido en forma
 * 		  ascendente o descendednte y por sector
 * param pEmplados arraya ordenar
 * param tam, tamaño de la estructura
 * param orden, tipo de orden 1 - ascendente/ 2 - descendente
 * return -1 si no se pudo ordenar y 1 si se pudo
 */
int empleados_ordenar(eEmpleados pEmpleados[], int tam, int orden);
/*
 *brief recorre toda la estructura y muestra todos los empleados por
 *		apellido y sector
 * param lista, array en el que busca
 * param tam, tamaño de la estrutura
 * return void
*/

void empleados_mostrarOrden(eEmpleados lista[], int tam);
/*
 *brief muestra un apellido y sector del empleado
 *param eEmpleados, estructura en la que busca los datos
 *return void
 */
void mostrarInforme(eEmpleados lista);

/*
 * brief calcula el total de los salarios
 * param lista, estructura en la que va a buscar
 * param tam, tamaño del array
 * return total calculado
 */
float totalSAlario(eEmpleados lista[], int tam);
/*
 * breif calcula el promedio de salarios
 * param lista, array en el que busca los datos
 * param tam, tamaño del array
 * return, float promedio
 */

float promedioSalario(eEmpleados lista[], int tam);
/*
 * brief la cantidad de empleados que superan el promedio de salarios
 * param lista, array en el que busca
 * param tam, tamaño del array
 * return contador, número de empleados que superan el promedio
 */

int superanPromedio(eEmpleados lista[], int tam);


#endif /* INFORMES_H_ */
