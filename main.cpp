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

    Inventario inventario(archivo_entrada_materiales); // inicializo el inventario
    Andypolis andypolis(archivo_entrada_edificios, archivo_entrada_ubicaciones, archivo_entrada_mapa); // inicializo la ciudad


    andypolis.mostrar_mapa();



    // Cierro archivos de lectura
	archivo_entrada_materiales.close(); 
	archivo_entrada_edificios.close();
    archivo_entrada_ubicaciones.close();
    archivo_entrada_mapa.close();

    return 0;
}