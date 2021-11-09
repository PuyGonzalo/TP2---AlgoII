#ifndef ERRORES_H
#define ERRORES_H

#include <string>
#include "formatos.h"

using namespace std;


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
const string STR_ERROR_POSICION_INEXISTENTE = "¡La posicion ingresada no existe en el mapa!";
const string STR_ERROR_CASILLERO_NO_CONSTRUIBLE = "¡No se puede construir en esta posicion!";
const string STR_ERROR_CASILLERO_OCUPADO = "¡El casillero esta ocupado!";
const string STR_ERROR_CASILLERO_NO_TRANSITABLE = "¡El casillero no es del tipo transitable!";
const string STR_ERROR_PAR_COORDENADAS_INVALIDAS = "¡Alguna de esas coordenadas no es un numero!";
const string STR_ERROR_CASILLERO_VACIO = "¡Este casillero esta vacio!";
const string STR_ADVERTENCIA_LLUVIA_RECURSOS = "Advertencia: No hay suficientes casilleros para realizar la lluvia de materiales";

const string errores[] = {
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
	STR_ERROR_CASILLERO_NO_CONSTRUIBLE,
	STR_ERROR_CASILLERO_OCUPADO,
	STR_ERROR_CASILLERO_NO_TRANSITABLE,
	STR_ERROR_PAR_COORDENADAS_INVALIDAS,
	STR_ERROR_CASILLERO_VACIO,
	STR_ADVERTENCIA_LLUVIA_RECURSOS
};

enum Estado_t {
	OK,
	ERROR_ENTRADA_INVALIDA, 
	ERROR_PUNTERO_NULO,
	ERROR_MATERIAL_INVALIDO,
	ERROR_EDIFICIO_INEXISTENTE,
	ERROR_NO_HAY_CONSTRUIDOS,
	ERROR_MAXIMO_EDIFICIOS_ALCANZADO,
	ERROR_MATERIALES_INSUFICIENTES,
	ERROR_NUMERO_OPCION_INVALIDA,
	ERROR_CODIGO_INEXISTENTE,
	ERROR_POSICION_INEXISTENTE,
	ERROR_CASILLERO_NO_CONSTRUIBLE,
	ERROR_CASILLERO_OCUPADO ,
	ERROR_CASILLERO_NO_TRANSITABLE,
	ERROR_PAR_COORDENADAS_INVALIDAS,
	ERROR_CASILLERO_VACIO,
	ADVERTENCIA_LLUVIA_RECURSOS};


//####################################################### FUNCIONES #################################################################


// pre: -
// pos: imprime el error en funcion del tipo de Estado_t que ingresan
void imprimir_error(Estado_t st);




#endif //ERRORES_H
