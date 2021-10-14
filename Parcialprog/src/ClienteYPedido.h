#ifndef CLIENTEYPEDIDO_H_
#define CLIENTEYPEDIDO_H_

struct{
	 int idCliente;
	 char nombreEmpresa[51];
	 char cuit[14];
	 int isEmpty;
}typedef Clientes;

struct{
	int idRecoleccion;
	int idCliente;
	int cantidadPedidosPendientes;
	int estado;
	float kilos;
	int isEmpty;
}typedef Recoleccion;

struct{
	int idLocalidad;
	int idCliente;
	char localidad[25];
	char direccion[21];
	int isEmpty;
}typedef Localidad;

/// \brief Para indicar que todas las posiciones del array están vacías, esta función pone la bandera (isEmpty) en TRUE en todas las posiciones del array.
/// \param listado Clientes* puntero al array de los clientes
/// \param len int tamaño del array
/// \return int Return (-1) si hay error [tamaño invalido o puntero nulo] - (0) si esta Ok
int InicializarClientes(Clientes* listado, int len);

/// \brief Para indicar que todas las posiciones del array están vacías, esta función pone la bandera (isEmpty) en TRUE en todas las posiciones del array.
/// \param listado Recoleccion* puntero al array de los pedidos del cliente
/// \param len int tamaño del array
/// \return int Return (-1) si hay error [tamaño invalido o puntero nulo] - (0) si esta Ok
int InicializarPedidos(Recoleccion* cliente, int len);

/// \brief Pide clientes al usuario y los carga llamando a la funcion AniadirCliente().
/// \param listado Clientes*
/// \param idCliente int
/// \param len int
int InicializarLocalidad(Localidad* listado, int len);
void PedirCliente(Clientes* listado, Localidad* listadoLocalidades, int idCliente, int len);

/// \brief Agrega en un array de clientes existente los valores recibidos como parámetro en la primer posición libre.
/// \param listado Clientes*
/// \param len int
/// \param id int
/// \param nombreEmpresa[] char
/// \param cuit[] char
/// \param direccion[] char
/// \param direccion[] localidad
/// \return int Return (-1) si hay error [tamaño invalido o puntero nulo o sin espacios libres] - (0) si esta Ok
int AniadirCliente(Clientes* listado, Localidad* listadoLocalidad, int len, int id, char nombreEmpresa[],char cuit[],char direccion[], char localidad[]);

/// \brief Busca un cliente recibiendo como parámetro de búsqueda su Id.
/// \param listado Clientes*
/// \param len int
/// \param id int
/// \return Return posicion del index del cliente o (-1) si [tamaño invalido o puntero nulo o cliente no encontrado]
int EncontrarClientePorId(Clientes* listado, int len,int id);

/// \brief Busca un cliente y lo modifica recibiendo como parámetro de búsqueda su Id.
/// \param listado Clientes*
/// \param len int
/// \param id int
void ModificarCliente( Clientes* listado, Localidad* listadoLocalidad,int len, int id);

/// \brief Elimina de manera lógica (isEmpty Flag en 1) un empleado recibiendo como parámetro su Id.
/// \param listado Clientes*
/// \param len int
/// \param id int
/// \return int Return (-1) si hay error [tamaño invalido o puntero nulo o cliente no encontrado] - (0) si esta Ok
int EliminarCliente(Clientes* listado, int len, int id);

/// \brief Crea el pedido . Pide los datos al usuario y lo guarda.
/// \param listado Clientes*
/// \param listadoRecoleccion Recoleccion*
/// \param len int
/// \param id int
/// \param idRecoleccion int
/// \return int Return (-1) si hay error [tamaño invalido o puntero/s nulo/s o cliente no encontrado] - (0) si esta Ok
int CrearPedido(Clientes* listado, Recoleccion* listadoRecoleccion, int len,  int idRecoleccion);

/// \brief Imprime todos los clientes cargados recorriendo listado.
/// \param listado Clientes*
/// \param len int
void ImprimirClientes(Clientes* listado,Localidad* listadoLocalidad, int len);

/// \brief Imprime todos los clientes cargados recorriendo listado y listadoRecoleccion.
/// \param listado Clientes*
/// \param listadoRecoleccion Recoleccion*
/// \param len int
void MostrarListadoPorCliente(Clientes* listado, Recoleccion* listadoRecoleccion, Localidad* listadoLocalidad, int len);

/// \brief Imprime todos los clientes cargados y muestra quellos que posean pedidos en estado: PENDIENTE.
/// \param listado Clientes*
/// \param listadoRecoleccion Recoleccion*
/// \param len int
void MostrarListadoPorPedidoPendiente(Clientes* listado, Recoleccion* listadoRecoleccion, Localidad* listadoLocalidad, int len);

/// \brief Imprime todos los clientes cargados y muestra quellos que posean pedidos en estado: COMPLETADO .
/// \param listado Clientes*
/// \param listadoRecoleccion Recoleccion*
/// \param len int
void MostrarListadoPorPedidoCompletado(Clientes* listado, Recoleccion* listadoRecoleccion, Localidad* listadoLocalidad, int len);


/// \brief Se pide ingresar la localidad a buscar, cuenta cuantos pedidos hay en esa localidad y los muestra.
/// \param listado Clientes*
/// \param listadoRecoleccion Recoleccion*
/// \param len int
void MostrarPedidoPorLocalidad(Clientes* listado,Recoleccion* listadoRecoleccion, Localidad* listadoLocalidad, int len);

/// \brief Se cambia el estado del pedido de Pendiente a Completado, se inicializa la cantidad de pedidos pendientes en 0 y se devuele por parametro
/// la cantidad de kilos en polipropileno ingresada
/// \param listado Clientes*
/// \param listadoRecoleccion Recoleccion*
/// \param  acumuladorPolipropileno float*
/// \param len int
void SepararResiduos(Clientes* listado ,Recoleccion* listadoRecoleccion, Localidad* listadoLocalidad, int len , float* acumuladorPolipropileno);

/// \brief Se calcula y muestra el promedio de polipropileno ingresado por cantidad de cliente (kilos/cliente)
/// \param listado Clientes*
/// \param listadoRecoleccion Recoleccion*
/// \param len int
/// \param polipropileno float
void CalcularPromedio(Clientes* listado,Recoleccion* listadoRecoleccion,int len, float polipropileno);


#endif /* CLIENTEYPEDIDO_H_ */

