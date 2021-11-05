#ifndef MENU_H
#define MENU_H

#include <sstream>
#include <string>
#include "errores.h"
#include "formatos.h"
#include "inventario.h"
#include "andypolis.h"


using namespace std;


const int OPCION_MINIMA = 1;
const int OPCION_MAXIMA = 7;

enum Opciones_menu{
	LISTAR_MATERIALES = 1,
	CONSTRUIR_EDIFICIO_POR_NOMBRE = 2,
	LISTAR_EDIFICIOS_CONSTRUIDOS = 3,
	LISTAR_TODOS_LOS_EDIFICIOS = 4,
	DEMOLER_EDIFICIO_POR_NOMBRE = 5,
	GUARDAR_SALIR = 6,
	MENU_SECRETO = 7
};

const string CODIGO_SECRETO_PIEDRA = "piedra porfa";
const string CODIGO_SECRETO_MADERA = "madera porfa";
const string CODIGO_SERCRETO_METAL = "metal porfa";
const int MAX_CODIGOS_SECRETOS = 3;
const int CANTIDAD_SECRETA_AGREGADA = 500;

const string codigos_secretos[MAX_CODIGOS_SECRETOS] = {
	CODIGO_SECRETO_PIEDRA,
	CODIGO_SECRETO_MADERA,
	CODIGO_SERCRETO_METAL,
};

const string MSJ_MENU_BIENVENIDA = "Bienevenido a Andypolis, ¿Que desea?";
const string MSJ_MENU_OPCION_1 = "1. Listar todos los materiales      ";
const string MSJ_MENU_OPCION_2 = "2. Construir edificio por nombre    ";
const string MSJ_MENU_OPCION_3 = "3. Listar los edificios construidos " ;
const string MSJ_MENU_OPCION_4 = "4. Listar todos los edificios       ";
const string MSJ_MENU_OPCION_5 = "5. Demoler un edificio por nombre   ";
const string MSJ_MENU_OPCION_6 = "6. Guardar y salir                  ";
const string MSJ_MENU_INGRESO_OPCION = "Ingrese una opcion";

const string MSJ_INGRESO_EDIFICIO_CONSTRUIR = "Ingresa el nombre del edifico a construir:";
const string MSJ_INGRESO_EDIFICIO_DEMOLER = "Ingresa el nombre del edificio a demoler:";
const string MSJ_DESPEDIDA = "¡Hasta la proxima!";
const string MSJ_INGRESO_CODIGO_SECRETO = "Ingrese algun codigo secreto:";


//####################################################### FUNCIONES #################################################################

// Como pos general: en caso de tener Estado_t se devuelve OK si la funcion se ejecuto correctamente y un error en caso contrario

// pre: - 
// pos: muestra el menu
void mostrar_menu();

// pre: ingreso_menu() ya valida el puntero nulo
// pos: realiza la opcion del menu que el usuario elija
Estado_t procesar_opcion(int opcion_elegida, Andypolis andypolis, Inventario inventario);

// pre: -
// pos: devuelve true si esta dentro de las opciones posibles, false de lo contrario
bool es_opcion_valida(string str); // peligroso pasar por referencia la opcion?

// pre: -
// pos: valida y procesa la opcion (existe para modularizar mejor)
Estado_t ingreso_menu(int &opcion , Andypolis andypolis, Inventario inventario);

// pre: -
// pos: suma una cantidad "secreta" de un material dependiendo que codigo se ponga
Estado_t menu_secreto(Inventario inventario, string codigo);

#endif //MENU_H
