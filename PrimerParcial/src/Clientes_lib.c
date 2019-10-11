/*
 * Clientes_lib.c
 *
 *  Created on: 10 oct. 2019
 *      Author: alumno
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "Clientes_lib.h"

int hardCodeClientesList(Cliente list[], int length)
{

	list[0].id=1;
	strncpy(list[0].nombre,"Hycite SRL",length);
	strncpy(list[0].direccion,"Suipacha 555",length);
	strncpy(list[0].localidad,"CABA",length);
	strncpy(list[0].cuit,"20-3213213-2",length);
	list[0].isEmpty=0;

	list[1].id=2;
	strncpy(list[1].nombre,"MAti SA", length);
	strncpy(list[1].direccion,"Mitre 420",length);
	strncpy(list[1].localidad,"Quilmes", length);
	strncpy(list[1].cuit,"20-789546548-2",length);
	list[1].isEmpty=0;

	list[0].id=3;
	strncpy(list[2].nombre,"Coca Cola ARG SRL", length);
	strncpy(list[2].direccion,"9 de julio 803", length);
	strncpy(list[2].localidad,"CABA", length);
	strncpy(list[2].cuit,"20-4564565213-2", length);
	list[2].isEmpty=0;

	return 0;
}
int initClientes(Cliente list[],int length)
{
	int retorno =-1;
	int i;
	if(list!=NULL && length>0)
	{
		for(i=0;i<length;i++)
		{
			list[i].isEmpty=1;
		}
		retorno =0;
	}

	return retorno;
}

int printClienteList(Cliente list[], int length)
{
int i;
int retorno =-1;
	if(list!=NULL && length>0)
	{

		for(i=0;i<length;i++)
		{
			if(list[i].isEmpty==0)
			{
				printf("\n****************************************\n");
				printf("\n id de cliente: %d",list[i].id);
				printf("\n Nombre: %s",list[i].nombre);
				printf("\n direccion: %s",list[i].direccion);
				printf("\n localidad: %s", list[i].localidad);
				printf("\n cuit: %s", list[i].cuit);
				printf("\n****************************************\n");
			}
		}
		retorno=0;
	}

	return retorno;
}
int addCliente(Cliente list[], int length, char name[], char direccion[],int strLength, char localidad[], char cuit[])
{
int retorno =-1;
int i;
if(list!= NULL && length>0)
   {
	for(i=0;i<length;i++)
	{
		if(list[i].isEmpty==0)
		{
			printf("\nla posicion %d esta siendo utilizada", list[i].id);
		}
		if(list[i].isEmpty==1){
			strncpy(list[i].nombre,name,strLength);
			strncpy(list[i].direccion,direccion,strLength);
			strncpy(list[i].localidad,localidad,strLength);
			strncpy(list[i].cuit,cuit,strlen(cuit));
			list[i].isEmpty=0;
			list[i].id=i+1;
			retorno=0;
			break;
		}
	}
}
if(retorno==0)
{
	printf("se ingreso correctamente el Cliente con el id: %d", list[i].id);
}
return retorno;
}
int findClienteById(Cliente list[],int length,int *pId,int *position)
{
int retorno =-1;
int i;
int id=*pId;
if(list!=NULL && length>0)
{
	for(i=0;i<length;i++)
	{
		if(list[i].isEmpty==1)
		{
			continue;
		}
		else if(list[i].id==id)
		{
			retorno=0;
			*position=i;
		}
	}
}


	return retorno;
}
int printClienteById(Cliente list[],int length, int *id)
{
	int retorno =-1;
	int i;
	int buffer = *id;

	if(list!=NULL && length>0)
	{
		for(i=0;i<length;i++)
		{
			if(list[i].id==buffer)
			{
				printf("\n****************************************");

				printf("\n Idcliente : %d", list[i].id);
				printf("\n nombre : %s", list[i].nombre);
				printf("\n direccion : %s", list[i].direccion);
				printf("\n localidad : %s", list[i].localidad);
				printf("\n cuit : %s\n", list[i].cuit);
				printf("\n****************************************\n");

				retorno=0;

				break;
			}
		}
	}


	return retorno;
}
