#ifndef ERRORES_H
#define ERRORES_H

#include <string>
#include "formatos.h"

using namespace std;

// hay que adaptarlos!!!! pero muchos son los que vamos a poner
const int MAX_ERRORS = 13;
const string STR_OK = "Ok";
const string STR_ERROR_ENTRADA_INVALIDA = "¡El dato ingresado es invalido!";
const string STR_ERROR_PUNTERO_NULO = "Error interno del sistema";
const string STR_ERROR_MATERIAL_INVALIDO = "¡Ese material no es valido!";
const string STR_ERROR_EDIFICIO_INEXISTENTE = "¡Este edificio no existe!";
const string STR_ERROR_NO_HAY_CONSTRUIDOS = "¡No hay mas edificios de este tipo, no podes destruir mas!";
const string STR_ERROR_MAXIMO_EDIFICIOS_ALCANZADO = "¡Alcanzaste el maximo de edificios posible!";
const string STR_ERROR_MATERIALES_INSUFICIENTES = "¡No tenes suficiente materiales para construir!";
const string STR_ERROR_NUMERO_OPCION_INVALIDA = "¡Ese numero está fuera de rango!";
const string STR_ERROR_CODIGO_INEXISTENTE = "¡Ese codigo no existe!";
const string STR_ERROR_POSICION_INEXISTENTE = "La posicion ingresada no existe en el mapa!";
const string STR_ERROR_COORDENADA_NO_CONSTRUIBLE = "¡No se puede construir en esta posicion!";
const string STR_ERROR_CASILLERO_OCUPADO = "¡El casillero esta ocupado!";

const string errores[MAX_ERRORS] = {
	STR_OK,
	STR_ERROR_ENTRADA_INVALIDA,
	STR_ERROR_PUNTERO_NULO,
	STR_ERROR_MATERIAL_INVALIDO,
	STR_ERROR_EDIFICIO_INEXISTENTE,
	STR_ERROR_NO_HAY_CONSTRUIDOS,
	STR_ERROR_MAXIMO_EDIFICIOS_ALCANZADO,
	STR_ERROR_MATERIALES_INSUFICIENTES,
	STR_ERROR_NUMERO_OPCION_INVALIDA,
	STR_ERROR_CODIGO_INEXISTENTE,
	STR_ERROR_POSICION_INEXISTENTE,
	STR_ERROR_COORDENADA_NO_CONSTRUIBLE,
	STR_ERROR_CASILLERO_OCUPADO
};

enum Estado_t {
	OK = 0,
	ERROR_ENTRADA_INVALIDA = 1, 
	ERROR_PUNTERO_NULO = 2,
	ERROR_MATERIAL_INVALIDO = 3,
	ERROR_EDIFICIO_INEXISTENTE = 4,
	ERROR_NO_HAY_CONSTRUIDOS = 5,
	ERROR_MAXIMO_EDIFICIOS_ALCANZADO = 6,
	ERROR_MATERIALES_INSUFICIENTES = 7,
	ERROR_NUMERO_OPCION_INVALIDA = 8,
	ERROR_CODIGO_INEXISTENTE = 9,
	ERROR_POSICION_INEXISTENTE = 10,
	ERROR_COORDENADA_NO_CONSTRUIBLE = 11,
	ERROR_CASILLERO_OCUPADO = 12};


//####################################################### FUNCIONES #################################################################


// pre: -
// pos: imprime el error en funcion del tipo de Estado_t que ingresan
void imprimir_error(Estado_t st);




#endif //ERRORES_H
