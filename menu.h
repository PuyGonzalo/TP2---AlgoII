#ifndef MENU_H
#define MENU_H

#include <sstream>
#include <string>
#include <ctime>
#include "errores.h"
#include "formatos.h"
#include "utilidades.h"
#include "herramientas.h"


using namespace std;


const int OPCION_MINIMA = 1;
const int OPCION_MAXIMA = 11;

enum Opciones_menu{
	CONSTRUIR_EDIFICIO_POR_NOMBRE = 1,
	LISTAR_EDIFICIOS_CONSTRUIDOS = 2,
	LISTAR_TODOS_LOS_EDIFICIOS = 3,
	DEMOLER_EDIFICIO_POR_COORD = 4,
	MOSTRAR_MAPA = 5,
	CONSULTAR_COORDENADA = 6,
	MOSTRAR_INVENTARIO = 7,
	RECOLETAR_RECURSOS_PRODUCIDOS = 8,
	LLUVIA_RECURSOS = 9,
	GUARDAR_SALIR = 10,
	MENU_SECRETO = 11
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

const string MSJ_MENU_BIENVENIDA = R"(
 _______  __    _  ______   __   __  _______  _______  ___      ___   _______ 
|   _   ||  |  | ||      | |  | |  ||       ||       ||   |    |   | |       |
|  |_|  ||   |_| ||  _    ||  |_|  ||    _  ||   _   ||   |    |   | |  _____|
|       ||       || | |   ||       ||   |_| ||  | |  ||   |    |   | | |_____ 
|       ||  _    || |_|   ||_     _||    ___||  |_|  ||   |___ |   | |_____  |
|   _   || | |   ||       |  |   |  |   |    |       ||       ||   |  _____| |
|__| |__||_|  |__||______|   |___|  |___|    |_______||_______||___| |_______|)";

const string MSJ_MENU_OPCION_1 = "1. Construir edificio por nombre";
const string MSJ_MENU_OPCION_2 = "2. Listar los edificios construidos";
const string MSJ_MENU_OPCION_3 = "3. Listar todos los edificios";
const string MSJ_MENU_OPCION_4 = "4. Demoler un edificio por coordenada";
const string MSJ_MENU_OPCION_5 = "5. Mostrar mapa";
const string MSJ_MENU_OPCION_6 = "6. Consultar coordenada";
const string MSJ_MENU_OPCION_7 = "7. Mostrar inventario";
const string MSJ_MENU_OPCION_8 = "8. Recolectar recursos producidos";
const string MSJ_MENU_OPCION_9 = "9. Lluvia de recursos";
const string MSJ_MENU_OPCION_10 = "10. Guardar y salir";
const string MSJ_MENU_INGRESO_OPCION = "Ingrese una opcion";


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
Estado_t procesar_opcion(int opcion_elegida, Andypolis &andypolis);

// pre: -
// pos: valida y procesa la opcion (existe para modularizar mejor)
Estado_t ingreso_menu(int &opcion , Andypolis &andypolis);

// pre: -
// pos: suma una cantidad "secreta" de un material dependiendo que codigo se ponga
Estado_t menu_secreto(Inventario inventario, string codigo);

// pre:
// pos
void procesar_juego(Andypolis& andypolis); // NO SE SI VA ACA O EN UTILIDADES

// pre:
// pos:
void guardar_cambios(Andypolis& andypolis, ofstream& archivo_salida_materiales, ofstream& archivo_salida_ubicaciones);

#endif //MENU_H
