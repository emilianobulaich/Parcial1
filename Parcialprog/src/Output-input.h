
#ifndef OUTPUT_INPUT_H_
#define OUTPUT_INPUT_H_

/// \brief Muestra el Menu .
void MostrarMenu (void);

/// \brief Imprime el mensaje de despida al salir del programa
/// \param mensaje[] char
void MensajeDeDespedida(char mensaje[]);

/// \brief Se pide un numero flotante, se lo ingresa y se lo compara contra un minimo y un maximo.
/// \param mensaje[] char
/// \param numMin float
/// \param numMax float
/// \return float  Retorna el numero enviado, ya validado
float IngresarFlotante(char mensaje[] ,float numMin ,float numMax);

/// \brief Se pide un numero entero, se lo ingresa y se lo compara contra un minimo y un maximo.
/// \param mensaje[] char
/// \param numMin int
/// \param numMax int
/// \return int Retorna el numero enviado, ya validado
int IngresarEntero(char mensaje[] ,int numMin ,int numMax);
#endif /* OUTPUT_INPUT_H_ */
