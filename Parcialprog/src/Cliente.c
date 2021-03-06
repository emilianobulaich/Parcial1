#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "ClienteYPedido.h"


#define TRUE 0
#define FALSE 1

int InicializarClientes(Clientes* listado, int len){

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


void PedirCliente(Clientes* listado, Localidad* listadoLocalidades, int idCliente, int len){
	char nombreEmpresa[51];
	char localidad[25];
	char direccion[21];
	char cuit[12];
	printf("Ingrese nombre de la empresa ");

			fflush(stdin);
			gets(nombreEmpresa);

			printf("Ingrese la localidad Cliente ");
			fflush(stdin);
			gets(localidad);

			printf("Ingrese la direccon del Cliente ");
			fflush(stdin);
			gets(direccion);

			printf("Ingresar el cuit del Cliente (CON GUIONES) ");
			fflush(stdin);
			gets(cuit);
			AniadirCliente(listado, listadoLocalidades, len, idCliente,nombreEmpresa,cuit,direccion,localidad);
}

int AniadirCliente(Clientes* listado, Localidad* listadoLocalidad, int len, int id, char nombreEmpresa[],char cuit[],char direccion[], char localidad[]){


	int retorno = -1;
     for ( int i = 0;  i < len; ++ i) {

		if(listado != NULL && len >= 0 && id >= 0 && listado[i].isEmpty== TRUE && listadoLocalidad[i].isEmpty == TRUE){


			listado[i].idCliente = id;
			strcpy(listado[i].nombreEmpresa, nombreEmpresa);
			strcpy(listado[i].cuit, cuit);
			strcpy(listadoLocalidad[i].direccion, direccion);
			strcpy(listadoLocalidad[i].localidad, localidad);
			listado[i].isEmpty = FALSE;
			break;
			retorno = 0;
			}
		}

    return retorno;
}
int EncontrarClientePorId(Clientes* listado, int len,int id){

	int retorno = -1;
	for (int i = 0; i < len; ++i) {

		 if(listado[i].idCliente == id){

			 retorno = i;

		}
    }

    return retorno;

}
void ModificarCliente( Clientes* listado, Localidad* listadoLocalidad,int len, int id){

	int ModificarLocalidad;
    int retorno = -1;
    retorno = EncontrarClientePorId(listado,len,id);

	if(retorno != -1 ){
         printf("?Quiere cambiar la localidad y direccion?\n 1-Si \n 2-No: ");
		 scanf ("%d",&ModificarLocalidad);

		 switch (ModificarLocalidad) {
			case 1:
				printf("Ingrese la nueva localidad: ");
				fflush(stdin);
				gets(listadoLocalidad[retorno].localidad);


				printf("Ingrese la nueva direccion: ");
				fflush(stdin);
				gets(listadoLocalidad[retorno].direccion);
				break;
			case 2:
				printf("Saliendo...\n");

				break;

		 }
	}
	else{
		printf("No existe ningun empleado con ese ID\n");

	}
}
int EliminarCliente(Clientes* listado, int len, int id){

	int retorno = -1;
	int respuesta = -1;
    if(listado != NULL && len >= 0 && id >= 0){
		retorno = EncontrarClientePorId(listado,len,id);
		printf("?Esta seguro que desea eliminar el usuario de ID: %d? \n 1-Si \n 2-No: ",id);
		scanf("%d",&respuesta);
		if(retorno != -1 &&  respuesta == 1 ){

				if(listado[retorno].idCliente == id )
				{
					listado[retorno].isEmpty = TRUE;
				}

			printf("Elimado usuario de ID: %d con ?xito\n",id);
		}
		else{
			printf("No se ha eliminado el cliente. Saliendo...\n");
		}
    }
	return retorno;
}
