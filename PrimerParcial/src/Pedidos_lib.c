/*
 * Pedidos_lib.c
 *
 *  Created on: 10 oct. 2019
 *      Author: alumno
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "Pedidos_lib.h"

int initPedidos(Pedido list[],int length)
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

int hardCodePedidos(Pedido list[], int length)
{

		list[0].idPedido=1;
		list[0].idCliente=1;
		list[0].estado=0;
		list[0].kgTotales=300;
		list[0].isEmpty=0;

		list[1].idPedido=2;
		list[1].idCliente=2;
		list[1].estado=0;
		list[1].kgTotales=450;
		list[1].isEmpty=0;

		list[2].idPedido=3;
		list[2].idCliente=3;
		list[2].estado=1;
		list[2].kgTotales=1300;
		list[2].isEmpty=0;

	return 0;
}

int printPedidosList(Pedido list[], int length)
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
				printf("\n id de pedido: %d",list[i].idPedido);
				printf("\n id de cliente que hizo el pedido: %d",list[i].idCliente);
				if(list[i].estado==0)
				{
				printf("\n el estado del pedido es: Pendiente");
				}else
				{
				printf("\n el estado del pedido es: completado");
				}
				printf("\n la cantidad total de Kg es : %2.f", list[i].kgTotales);
				printf("\n el isempty esta en: %d", list[i].isEmpty);
				printf("\n****************************************\n");
			}
		}
		retorno=0;
	}

	return retorno;
}
int addPedido(Pedido list[], int length, int *idCliente, float *kgTotales)
{

	int retorno =-1;
	int i;
	if(list!= NULL && length>0)
	   {
		for(i=0;i<length;i++)
		{
			if(list[i].isEmpty==0)
			{
				printf("\nla posicion %d esta siendo utilizada", i);
			}
			if(list[i].isEmpty==1){

				list[i].isEmpty=0;
				list[i].idPedido=i+1;
				list[i].idCliente=*idCliente;
				list[i].kgTotales=*kgTotales;
				list[i].estado=0;
				retorno=0;
				break;
			}
		}
	}
	if(retorno==0)
	{
		printf("se ingreso correctamente el pedido del Cliente con el id: %d", list[i].idPedido);
	}
	return 0;
}

int findPedidoById(Pedido list[],int length,int *pId,int *position)
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
		else if(list[i].idPedido==id)
		{
			retorno=0;
			*position=i;
		}
	}
}


	return retorno;
}


int printPedidoById(Pedido list[],int length, int *id)
{
	int retorno =-1;
	int i;
	int buffer = *id;

	if(list!=NULL && length>0)
	{
		for(i=0;i<length;i++)
		{
			if(list[i].idPedido==buffer)
			{
				printf("\n****************************************");
				printf("\n el id del pedido es: %d", list[i].idPedido);
				printf("\n el id del cliente que hizo el pedido es: %d", list[i].idCliente);
				printf("\n Los Kg Totales de residuos son: %f", list[i].kgTotales);
				if(list[i].estado==0)
				{
				printf("\n el estado del pedido es: Pendiente");
				}else
				{
				printf("\n el estado del pedido es: completado");
				}
				printf("\n****************************************\n");

				retorno=0;

				break;
			}
		}
	}


	return retorno;
}

int getInt(	int *pResultado,char *pMensaje,char *pMensajeError,int minimo,int maximo,int reintentos)
{
	int retorno = -1;
	int buffer;
	do
	{
		printf("%s",pMensaje);
		__fpurge(stdin);
		if(scanf("%d",&buffer)==1 && buffer >= minimo && buffer <= maximo)
		{
			*pResultado = buffer;
			retorno = 0;
			break;
		}
		printf("%s",pMensajeError);
		reintentos--;
	}while(reintentos >= 0);
	return retorno;
}
int getStr(char charStr[], int length, char *pMensaje)
{
char buffer[length];
printf("%s", pMensaje);
__fpurge(stdin);
fgets(buffer, length,stdin);
strncpy(charStr,buffer,length);
	return 0;
}

int getChar(char *letra, char *pMensaje)
{
	char buffer;
	printf("%s", pMensaje);
	__fpurge(stdin);
	buffer = getchar();

	*letra =buffer;

	return 0;
}

int isValidAlphabetic(char *rcvdStr)
{
int retorno =0;
int i;
int length=strlen(rcvdStr)-1;

	if(rcvdStr!=NULL && length>0)
	{
		for(i=0;i<length;i++)
		{
			if((rcvdStr[i]>='A' && rcvdStr[i]<='Z') || (rcvdStr[i]>='a' && rcvdStr[i]<='z') || (rcvdStr[i]==' '))
			{
				retorno=0;

			}else
			{
				printf("Error. Ingreso algun caracter no alfabetico.\n");
				retorno = -1;
				break;
			}
		}
	}
return retorno;
}
int isValidAlphanumeric(char *rcvdStr)
{
int retorno =0;
int i;
int length=strlen(rcvdStr)-1;

	if(rcvdStr!=NULL && length>0)
	{
		for(i=0;i<length;i++)
		{
			if((rcvdStr[i]>='A' && rcvdStr[i]<='Z') || (rcvdStr[i]>='a' && rcvdStr[i]<='z') || (rcvdStr[i]>='0' && rcvdStr[i]<='9') || (rcvdStr[i] ==' '))
			{
				retorno=0;

			}else
			{
				printf("Error. Ingreso algun caracter no alfanumerico.\n");
				retorno = -1;
				break;
			}
		}
	}
return retorno;
}
int isValidCuit(char *cuit)
{
int retorno =0;
int i;
int length=strlen(cuit)-1;
	if(cuit!=NULL && length>0)
	{
		for(i=0;i<length;i++)
		{
			if((cuit[i]>='0' && cuit[i]<='9') || cuit[i]=='-')
			{
			retorno=0;

			}
			else
			{
				printf("Error. Ingreso algun caracter no valido.\n");
				retorno = -1;
				break;
			}
		}
	}
return retorno;
}
int isValidFloat(char *number)
{
	{
	int retorno =0;
	int i;
	int length=strlen(number)-1;
	printf("length es: %d",length);
	printf("se va a validar el str %s",number);
	if(number!=NULL && length>0)
		{
			for(i=0;i<length;i++)
			{
				if((number[i]>='0' && number[i]<='9') || (number[i]=='.'))
				{
					retorno=0;
				}
				else
				{
					printf("Error. Ingreso algun caracter no numerico.\n");
					retorno = -1;
					break;
				}
			}
		}
	return retorno;
	}
}
int mainMenu(int *option)
{
int buffer;

printf("\n 1.- Alta Clientes");
printf("\n 2.- Modificar datos de Cliente");
printf("\n 3.- Baja Clientes");
printf("\n 4.- Crear Pedido de recoleccion.");
printf("\n 5.- Procesar residuos.");
printf("\n 6.- imprimir clientes");
printf("\n 7.- imprimir pedidos pendientes");
printf("\n 8.- imprimir pedidos procesados");
printf("\n 9.- Salir");
getInt(&buffer,"\ningrese la opcion deseada", "\nopcion incorrecta",1,8,3);
*option=buffer;
	return 0;
}

int printPedidoxEstado(Pedido list[],int length,int *estado)
{
	int retorno =-1;
	int i;
	int buffer = *estado;

	if(list!=NULL && length>0)
	{
		for(i=0;i<length;i++)
		{
			if(list[i].isEmpty==0)
			{
				if(list[i].estado==buffer)
				{
					printf("\n****************************************\n");
					printf("\n id de pedido: %d",list[i].idPedido);
					printf("\n id de cliente que hizo el pedido: %d",list[i].idCliente);
					if(list[i].estado==0)
					{
					printf("\n el estado del pedido es: Pendiente");
					}else
					{
					printf("\n el estado del pedido es: completado");
					}
					printf("\n la cantidad total de Kg es : %.2f", list[i].kgTotales);
					printf("\n el isempty esta en: %d", list[i].isEmpty);
					printf("\n****************************************\n");
				}
				retorno=0;

				break;
			}
		}
	}

	return retorno;
}

int modificarClienteMenu(int *option)
{
int buffer;

printf("\n 1.- modificar direccion");
printf("\n 2.- Modificar localidad");

getInt(&buffer,"\ningrese la opcion deseada", "\nopcion incorrecta",1,2,3);
*option=buffer;
	return 0;
}

