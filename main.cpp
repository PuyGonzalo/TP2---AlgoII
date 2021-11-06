#include <iostream>
#include "errores.h"
#include "menu.h"
#include "andypolis.h"
#include "inventario.h"

using namespace std;

const string PATH_ENTRADA_MATERIALES = "Archivos/materiales.txt";
const string PATH_ENTRADA_EDIFICIOS = "Archivos/edificios.txt";
const string PATH_ENTRADA_UBICACIONES = "Archivos/ubicaciones.txt";
const string PATH_ENTRADA_MAPA = "Archivos/mapa.txt";


int main (void){

    // Abro archivos de lectura
	ifstream archivo_entrada_materiales(PATH_ENTRADA_MATERIALES);
    ifstream archivo_entrada_edificios(PATH_ENTRADA_EDIFICIOS);
    ifstream archivo_entrada_ubicaciones(PATH_ENTRADA_UBICACIONES);
    ifstream archivo_entrada_mapa(PATH_ENTRADA_MAPA);

 	// inicializo la ciudad
    Andypolis andypolis(archivo_entrada_edificios, archivo_entrada_ubicaciones, archivo_entrada_mapa, archivo_entrada_materiales);
	
	andypolis.mostrar_andypolis();


    // Cierro archivos de lectura
	archivo_entrada_materiales.close(); 
	archivo_entrada_edificios.close();
    archivo_entrada_ubicaciones.close();
    archivo_entrada_mapa.close();

    return 0;
}





/* 
int main(int argc, char const *argv[])
{
	system(CLR_SCREEN);
	// Inicializo las variables a utilizar
	Lista_Materiales* lista_de_materiales = new Lista_Materiales;
	Andypolis* andypolis = new Andypolis;
	Status_t st = OK;
	int opcion = 0;

	// Abro archivos de lectura
	ifstream archivo_entrada_materiales(PATH_ENTRADA_MATERIALES);
    ifstream archivo_entrada_edificios(PATH_ENTRADA_EDIFICIOS);

	// Inicializo el juego
	st = inicializar_juego(lista_de_materiales, andypolis, archivo_entrada_materiales, archivo_entrada_edificios);
	if(st != OK){
		imprimir_error(st);
		return st;
	}

	// Cierro los archivos de lectura
	archivo_entrada_materiales.close(); 
	archivo_entrada_edificios.close();

	// Juego
	while(opcion != GUARDAR_SALIR){
		mostrar_menu();
		st = ingreso_menu(opcion, andypolis, lista_de_materiales);
		if(st != OK)
			imprimir_error(st);
	}

	// Abro los archivos de escritura para guardar el juego
	ofstream archivo_salida_materiales(PATH_ENTRADA_MATERIALES, ios::trunc);
    ofstream archivo_salida_edificios(PATH_ENTRADA_EDIFICIOS, ios::trunc);
	
	// Guardo los cambios
	guardar_cambios(lista_de_materiales, andypolis, archivo_salida_materiales, archivo_salida_edificios);

	// Cierros los archivos de escritura
	archivo_salida_materiales.close();
	archivo_salida_edificios.close();
	
	// Finalizo el juego
	st = finalizar_juego(lista_de_materiales, andypolis);
	if(st != OK){
		imprimir_error(st);
		return st;
	}

	return OK;
}

*/