/*
 ============================================================================
 Name        : PrimerParcial.c
 Author      : Ignacio canay
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "Clientes_lib.h"
#include "Pedidos_lib.h"

#define LENGTH 100
#define PEDIDOSLENGTH 1000
#define STRLENGTH 50
#define CUITLENGTH 13
int main(void) {
Cliente clientesLista[LENGTH];
char nombre[STRLENGTH], direccion[STRLENGTH], localidad[STRLENGTH], cuit[STRLENGTH];
char borrarSoN, recolectarSON;
Pedido pedidoLista[PEDIDOSLENGTH];
char kgtotales[STRLENGTH];

float kgTotales;
int opcionMenu, idABuscar, posicion;
int flagPrimeraAlta=0, flagPrimerRecoleccion=0;
initClientes(clientesLista,LENGTH);
hardCodeClientesList(clientesLista,LENGTH);
printClienteList(clientesLista,LENGTH);

 initPedidos(pedidoLista,PEDIDOSLENGTH);
 hardCodePedidos(pedidoLista,PEDIDOSLENGTH);
 printPedidosList(pedidoLista,PEDIDOSLENGTH);
//ABM//

do
{
mainMenu(&opcionMenu);
switch(opcionMenu)
{
case 1:
	//aklta cliente
	if(flagPrimeraAlta==0)
	{
	initClientes(clientesLista,LENGTH);
	}
	do{
		getStr(nombre, STRLENGTH,"ingrese el nombre de la empresa");
	}while(isValidAlphabetic(nombre)!=0);
	do{
		getStr(direccion, STRLENGTH,"ingrese la direccion de la empresa");
	}while(isValidAlphanumeric(direccion)!=0);
	do{
		getStr(localidad, STRLENGTH,"ingrese localidad donde esta ubicada la empresa");
	}while(isValidAlphabetic(localidad)!=0);
	do{
		getStr(cuit, CUITLENGTH,"ingrese el cuit de la empresa");
	}while(isValidCuit(cuit)!=0);

	addCliente(clientesLista,LENGTH,nombre,direccion,STRLENGTH,localidad,cuit);

	break;
case 2:
	//modificar
	getInt(&idABuscar,"Ingrese el id de cliente a buscar","ERROR. fuera de rango",1,LENGTH,3);
	findClienteById(clientesLista,LENGTH,&idABuscar,&posicion);
	printClienteById(clientesLista,LENGTH,&idABuscar);

	printf("que desea hacer con este cliente?");
	modificarClienteMenu(&opcionMenu);
		switch(opcionMenu)
		{
		case 1:
			do{
				getStr(direccion, STRLENGTH,"ingrese la nueva direccion de la empresa");
			}while(isValidAlphanumeric(direccion)!=0);
			if(isValidAlphanumeric(direccion)==0)
			{
				strncpy(clientesLista[posicion].direccion,direccion,STRLENGTH);
			}
			break;
		case 2:
			do{
			getStr(localidad, STRLENGTH,"ingrese la nueva direccion de la empresa");
			}while(isValidAlphanumeric(localidad)!=0);
			if(isValidAlphanumeric(localidad)==0)
			{
				strncpy(clientesLista[posicion].localidad,localidad,STRLENGTH);
			}
			break;
		default :
			break;
		}
	break;
case 3:
	//baja
	getInt(&idABuscar,"Ingrese el id de cliente a buscar","ERROR. fuera de rango",1,LENGTH,3);
		findClienteById(clientesLista,LENGTH,&idABuscar,&posicion);
		printClienteById(clientesLista,LENGTH,&idABuscar);
		do{
		getChar(&borrarSoN,"\nDesea borrar este cliente (s o n)");
		}while(borrarSoN !='n' && borrarSoN != 's');
		if(borrarSoN=='s')
		{
			clientesLista[posicion].isEmpty=1;
		}
	break;
case 4:
	//crear pedido recoleccion
if(flagPrimerRecoleccion==0)
{
	 initPedidos(pedidoLista,PEDIDOSLENGTH);
}
	printClienteList(clientesLista,LENGTH);
	getInt(&idABuscar,"Ingrese el id de cliente a buscar","ERROR. fuera de rango",1,LENGTH,3);
	findClienteById(clientesLista,LENGTH,&idABuscar,&posicion);
	printClienteById(clientesLista,LENGTH,&idABuscar);

	do{
	getStr(kgtotales,STRLENGTH,"ingrese el total de Kg a recolectar");
	}while(isValidFloat(kgtotales)!=0);
	if(isValidFloat(kgtotales)==0)
	{
	kgTotales=atof(kgtotales);
	addPedido(pedidoLista,PEDIDOSLENGTH,&idABuscar,&kgTotales);
	}
	break;
case 5:
	//procesar residuos
	 printPedidosList(pedidoLista,PEDIDOSLENGTH);
	 getInt(&idABuscar,"Ingrese el id del peddo a buscar","ERROR. fuera de rango",1,PEDIDOSLENGTH,3);
	 printPedidoById(pedidoLista,PEDIDOSLENGTH,&idABuscar);
		do{
		getChar(&recolectarSON,"\nDesea borrar este cliente (s o n)");
		}while(recolectarSON !='n' && borrarSoN != 's');
		if(recolectarSON=='s')
		{
			pedidoLista[posicion].estado=1;
		}

	break;
case 6:
	//imprimirclientes
	printClienteList(clientesLista,LENGTH);

	break;
case 7:
	//imprimir pedidos pendientes
	printPedidoxEstado(pedidoLista,PEDIDOSLENGTH,0);
	break;
case 8:
	break;
case 9:
	break;
default :
	break;
}


}while(opcionMenu!=9);


}
