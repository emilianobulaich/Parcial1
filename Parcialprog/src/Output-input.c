#include "Output-input.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "ClienteYPedido.h"
#define TRUE 0
#define FALSE 1


void MostrarMenu (void){
	    printf("------------------> MENU <------------------");
	    printf("\n***************************************\n");
		printf("          Elija una opcion: \n");
		printf("*****************************************\n");
		printf("|  1. Alta de Cliente                   |\n");
		printf("|  2. Modificar datos del Cliente    	|\n");
		printf("|  3. Baja de cliente                   |\n");
		printf("|  4. Crear pedido de Recoleccion    	|\n");
		printf("|  5. Procesar residuos              	|\n");
		printf("|  6. Imprimir Clientes     	     	|\n");
		printf("|  7. Imprimir Pedidos pendientes    	|\n");
		printf("|  8. Imprimir Pedidos procesados    	|\n");
		printf("|  9. Pedidos por localidad             |\n");
		printf("|  10. Promedio de propileno reciclado  |\n");
		printf("|  11. Salir                            |\n");
		printf("*****************************************\n");
}
void ImprimirClientes(Clientes* listado,Localidad* listadoLocalidad, int len){
	if(listado != NULL && len >= 0){
		for(int i = 0; i < len; i++){
			if(listado[i].isEmpty == FALSE){

				printf("ID: %d\n",listado[i].idCliente);
				printf("Nombre empresa: %s\n",listado[i].nombreEmpresa);
				printf("Cuit: %s\n",listado[i].cuit);
				printf("Localidad: %s \n",listadoLocalidad[i].localidad);
				printf("Direccion: %s\n",listadoLocalidad[i].direccion);

			}

		}
	}
	else{
		printf("ERROR\n");
	}

}

//6
void MostrarListadoPorCliente(Clientes* listado, Recoleccion* listadoRecoleccion, Localidad* listadoLocalidad, int len){
   	if(listado != NULL && listadoRecoleccion != NULL && len ){
   		for(int i = 0; i < len; i++){
				if(listado[i].isEmpty == FALSE) {
				printf("ID: %d \n",listado[i].idCliente);
					if(listadoRecoleccion[i].isEmpty == FALSE){
						printf("ID Recoleccion: %d \n",listadoRecoleccion[i].idRecoleccion);
					}
				printf("Nombre de la empresa: %s",listado[i].nombreEmpresa);
				printf("Cuit: %s\n",listado[i].cuit);
				printf("Localidad: %s \n",listadoLocalidad[i].localidad);
				printf("Direccion: %s\n",listadoLocalidad[i].direccion);


				printf("Cantidad de pedidos pendientes : %d\n ",listadoRecoleccion[i].cantidadPedidosPendientes);

				}
   		}
   	}
   	else{
   		printf("ERROR\n");
   	}
 }


float IngresarFlotante(char mensaje[] ,float numMin ,float numMax){
	setbuf(stdout, NULL);

	float num;

	do{
	printf("%s entre %f y %f:",mensaje,numMin,numMax);
	fflush(stdin);
	scanf("%f",&num);
	}while(num < numMin || num > numMax);

    return num;
}

int IngresarEntero(char mensaje[] ,int numMin ,int numMax){
	setbuf(stdout, NULL);

	int num;

	do{
	printf(mensaje);

	scanf("%d",&num);
	}while(num < numMin || num > numMax);

    return num;
}
//FALTA TRAER LA UTN GET CHAR TRAER Y COMENTAR PARA HOY
void MensajeDeDespedida(char mensaje[]){
	printf("%s",mensaje);
}




