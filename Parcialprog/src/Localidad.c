#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "ClienteYPedido.h"


#define TRUE 0
#define FALSE 1


int InicializarLocalidad(Localidad* listado, int len){

	setbuf(stdout,NULL);

	int retorno;
	retorno = -1;

	if(listado != NULL && len>=0){
		for (int i = 0; i < len; i++) {
		listado[i].isEmpty = TRUE;

		}
		retorno = 0;
	}


	return retorno;

}
