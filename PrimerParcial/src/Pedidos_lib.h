/*
 * Pedidos_lib.h
 *
 *  Created on: 10 oct. 2019
 *      Author: alumno
 */

#ifndef PEDIDOS_LIB_H_
#define PEDIDOS_LIB_H_

struct
{
	int idPedido;
	int idCliente;
	int estado; // 0 = pendiente 1 =completado
	float kgTotales;
	int isEmpty;
}typedef Pedido;

int initPedidos(Pedido list[],int length);
int hardCodePedidos(Pedido list[], int length);
int printPedidosList(Pedido list[], int length);
int addPedido(Pedido list[], int length, int *idCliente, float *kgTotales);
int findPedidoById(Pedido list[],int length,int *pId,int *position);
int printPedidoById(Pedido list[],int length, int *id);

//mover a otro archivo
int getInt(	int *pResultado,char *pMensaje,char *pMensajeError,int minimo,int maximo,int reintentos);
int getStr(char charStr[], int length, char *pMensaje);
int getChar(char *letra, char *pMensaje);
int isValidAlphabetic(char *rcvdStr);
int isValidAlphanumeric(char *rcvdStr);
int isValidCuit(char *cuit);
int isValidFloat(char *number);
int mainMenu(int *option);
int printPedidoxEstado(Pedido list[],int length,int *estado);
int modificarClienteMenu(int *option);
#endif /* PEDIDOS_LIB_H_ */
