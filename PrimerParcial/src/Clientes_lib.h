/*
 * Clientes_lib.h
 *
 *  Created on: 10 oct. 2019
 *      Author: alumno
 */

#ifndef CLIENTES_LIB_H_
#define CLIENTES_LIB_H_

struct
{
	int id;
	char nombre[51];
	char direccion[51];
	char localidad[51];
	char cuit[11];
	int isEmpty;
}typedef Cliente;

int hardCodeClientesList(Cliente list[], int length);
int initClientes(Cliente list[],int length);
int printClienteList(Cliente list[], int length);
int addCliente(Cliente list[], int length, char name[], char direccion[],int strLength, char localidad[], char cuit[]);
int findClienteById(Cliente list[],int length,int *pId,int *position);
int printClienteById(Cliente list[],int length, int *id);
#endif /* CLIENTES_LIB_H_ */
