#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "ClienteYPedido.h"
#include "Output-input.h"

#define TRUE 0
#define FALSE 1
#define TAM 20
#define MINIMO 1
#define MAXIMO 10
#define ITERADOR 0

int main(void) {
	setbuf(stdout,NULL);
	Clientes listado[TAM];
    Recoleccion cliente[TAM];
    Localidad localidades[TAM];

	int respuesta;
	int idInicial = 0;
	int idModificar;
	int idEliminar;
	int idRecoleccion = 0;
	int idLocalidad = 0;
	float cantidadPolipropileno;

	if (InicializarClientes(listado,TAM) != -1 && InicializarPedidos(cliente,TAM) != -1){


   do{
			MostrarMenu();

            respuesta = IngresarEntero("Opcion: \n",1,11);

    		switch (respuesta) {

			case 1:
				idInicial++;
				idLocalidad++;
				PedirCliente(listado,localidades,idInicial,TAM);
				break;
			case 2:
				printf("¿Que cliente quiere modificar? Elegir por ID: ");
				scanf("%d",&idModificar);
				ModificarCliente(listado,localidades,TAM,idModificar);
				break;

			case 3:
				printf("¿Que cliente quiere eliminar? Elegir por ID:");
				scanf("%d",&idEliminar);
				EliminarCliente(listado,TAM,idEliminar);


				break;
			case 4:
				idRecoleccion++;
				ImprimirClientes(listado, localidades,TAM);


				CrearPedido(listado,cliente,TAM,idRecoleccion);

				break;
			case 5:
				SepararResiduos(listado,cliente,localidades,TAM,&cantidadPolipropileno);
				break;
			case 6:

				MostrarListadoPorCliente(listado,cliente,localidades,TAM);

				break;
			case 7:
				MostrarListadoPorPedidoPendiente(listado,cliente,localidades,TAM);
				break;
			case 8:

				MostrarListadoPorPedidoCompletado(listado,cliente,localidades,TAM);
				break;
			case 9:


				MostrarPedidoPorLocalidad(listado,cliente,localidades,TAM);
				break;
			case 10:

				CalcularPromedio(listado,cliente,idInicial,cantidadPolipropileno);

				break;
			case 11:
				MensajeDeDespedida("Vuelva pronto");
				break;

		}

	}while(respuesta != 11 || idInicial <= TAM);
	 }



	return EXIT_SUCCESS;

}
