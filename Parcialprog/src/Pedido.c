#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "Output-input.h"

#define TRUE 0
#define FALSE 1
#include "ClienteYPedido.h"
int InicializarPedidos(Recoleccion* cliente, int len){

	setbuf(stdout,NULL);

	int retorno;
	retorno = -1;

	if(cliente != NULL && len>=0){
		for (int i = 0; i < len; i++) {

		cliente[i].isEmpty = TRUE;
		cliente[i].cantidadPedidosPendientes = 0;

		}
		retorno = 0;
	}


	return retorno;

}
//4
int CrearPedido(Clientes* listado, Recoleccion* listadoRecoleccion, int len,  int idRecoleccion){
	 int retorno = -1;

	 int idCliente;
	 float kilos;
		printf("?A que cliente quiere a?adirle un pedido?");

		scanf("%d",&idCliente);
		printf("?De cuantos kilos es el pedido?");

		scanf("%f",&kilos);
		 if(listado != NULL && listadoRecoleccion != NULL && len >= 0 && idCliente >=0 && idRecoleccion >= 0 ){
			 retorno = 0;
				 for(int i = 0; i < len; i++){
					 if(listadoRecoleccion[i].isEmpty == TRUE && listado[i].idCliente == idCliente){

						 listadoRecoleccion[i].idCliente = idCliente;
						 listadoRecoleccion[i].idRecoleccion = idRecoleccion;
						 listadoRecoleccion[i].kilos = kilos;
						 listadoRecoleccion[i].cantidadPedidosPendientes = 1;
						 listadoRecoleccion[i].estado = 1;
						 listadoRecoleccion[i].isEmpty = FALSE;

						 break;
					 }
					 else if(listadoRecoleccion[i].isEmpty == FALSE && listado[i].idCliente == idCliente){
						 listadoRecoleccion[i].cantidadPedidosPendientes++;
					 }
				 }

		 }
return retorno;
}
void MostrarListadoPorPedidoPendiente(Clientes* listado, Recoleccion* listadoRecoleccion, Localidad* listadoLocalidad, int len){
	if(listado != NULL && listadoRecoleccion != NULL && len >=0  ){
		for(int i = 0; i < len; i++){
			if(listadoRecoleccion[i].isEmpty == FALSE && listadoRecoleccion[i].estado == 1){
				printf("ID: %d\n",listado[i].idCliente);
				printf("ID RECOLECCION: %d\n",listadoRecoleccion[i].idRecoleccion);
				printf("Cuit: %s\n",listado[i].cuit);
				printf("Localidad: %s \n",listadoLocalidad[i].localidad);
				printf("Direccion: %s\n",listadoLocalidad[i].direccion);
				printf("Kilos: %f \n",listadoRecoleccion[i].kilos);
                printf("Estado: PENDIENTE \n");


				}
		}
	}
}
//8
void MostrarListadoPorPedidoCompletado(Clientes* listado, Recoleccion* listadoRecoleccion,Localidad* listadoLocalidad, int len){
	if(listado != NULL && listadoRecoleccion != NULL && len >=0){
			for(int i = 0; i < len; i++){
				if(listadoRecoleccion[i].isEmpty == FALSE && listadoRecoleccion[i].estado == 0){
					printf("ID: %d\n",listado[i].idCliente);
					printf("ID RECOLECCION: %d\n",listadoRecoleccion[i].idRecoleccion);
					printf("Cuit: %s\n",listado[i].cuit);
					printf("Localidad: %s \n",listadoLocalidad[i].localidad);
					printf("Direccion: %s\n",listadoLocalidad[i].direccion);
					printf("Kilos: %f \n",listadoRecoleccion[i].kilos);
	                printf("Estado: COMPLETADO \n");


				}

			}
		}
	else{
   		printf("ERROR");
   	}
}
//5
void SepararResiduos(Clientes* listado ,Recoleccion* listadoRecoleccion, Localidad* listadoLocalidad, int len , float* acumuladorPolipropileno){


    if(listado != NULL && listadoRecoleccion != NULL && len >= 0){

		int idRecoleccion;
		float kilosTotales;

		float cantidadPolietilenoBaja;
		float cantidadPolietilenoAlta;
		float cantidadPolipropileno;
		float basura;

		MostrarListadoPorPedidoPendiente(listado,listadoRecoleccion,listadoLocalidad,len);
		printf("Que ID RECOLECCION que desea separar en residuos \n ");
		scanf("%d",&idRecoleccion);
		for(int i = 0; i < len; i++){

			 if(listadoRecoleccion[i].idRecoleccion == idRecoleccion && listadoRecoleccion[i].estado == 1){
				   kilosTotales = listadoRecoleccion[i].kilos;
				   listadoRecoleccion[i].estado = 0;
				   listadoRecoleccion[i].cantidadPedidosPendientes = 0;


			 }

		 }

		cantidadPolipropileno = IngresarFlotante("Ingrese la cantidad de Polipropileno" , 0 ,kilosTotales);
		kilosTotales -=  cantidadPolipropileno;
		cantidadPolietilenoBaja =IngresarFlotante("Ingrese la cantidad de Polietileno de Baja densidad" , 0 ,kilosTotales);
		kilosTotales -= cantidadPolietilenoBaja;
		cantidadPolietilenoAlta =IngresarFlotante("Ingrese la cantidad de Polietileno de Alta densidad" , 0 ,kilosTotales);
		kilosTotales -= cantidadPolietilenoAlta;
		basura = kilosTotales;
		printf("La cantidad de basura desechada es de: %.2f\n",basura);
		*acumuladorPolipropileno += cantidadPolipropileno;

		printf("PEDIDO COMPLETADO \n");

    }else{
    	printf("ERROR");
    }
}
//9
void MostrarPedidoPorLocalidad(Clientes* listado,Recoleccion* listadoRecoleccion, Localidad* listadoLocalidad, int len){
	  if(listado != NULL && listadoRecoleccion != NULL && len >= 0){
			int contador = 0;
			char localidadABuscar[25];
			printf("Ingresar localidad a buscar");
			fflush(stdin);
			gets(localidadABuscar);

			for(int i = 0; i < len; i++){
				 if(strcmp(listadoLocalidad[i].localidad, localidadABuscar) == 0 && listadoRecoleccion[i].estado == 1){

					contador += listadoRecoleccion[i].cantidadPedidosPendientes;
				 }
			 }
			printf("Los estados pendientes son: %d \n",contador);
	  }
}
//10
void CalcularPromedio(Clientes* listado,Recoleccion* listadoRecoleccion,int len, float polipropileno){
	if(listado != NULL && listadoRecoleccion != NULL && len >= 0 && polipropileno>=0){
		float resultado;
    	resultado = polipropileno / (float)len;
        printf("El promedio de kilos de polipropileno por cliente es de : %.2f \n",resultado);
    }
	else{
		printf("Datos cargados con error \n");
	}

}
