#ifndef ANDYPOLIS_H
#define ANDYPOLIS_H

#include <sstream>
#include <fstream>
#include <string>
#include "casillero.h"
#include "Casilleros/casillero_construible.h"
#include "Casilleros/casillero_inaccesible.h"
#include "Casilleros/casillero_transitable.h"
#include "edificio.h"
#include "parser.h"
#include "inventario.h"
#include "mapa.h"

using namespace std;

const int MAX_EDIF_CONSTRUIBLES_INICIAL = 3;
const int AMPLIACION_EDIF_CONSTRUIBLES = 2;
const char DELIM_ESPACIO = ' ';


class Andypolis{

private:
    // Atributos
    //Casilleroptr** mapa;
    Mapa mapa;
    Edificio** lista_edificios_construibles;
    Inventario inventario;
    int cantidad_edificios_construibles;
    int cantidad_max_edificios_construibles;


public:
    // Metodos
    Andypolis(ifstream& archivo_edif, ifstream& archivo_ubics, ifstream& archivo_mapa, ifstream& archivo_mats);

    ~Andypolis(); // destruir lista y mapa

    // pre:
    // pos: 
    void cargar_lista_edificios_construibles(ifstream& archivo_edif);

    // pre:
    // pos:
    void cargar_mapa(ifstream& archivo_mapa);

    // pre:
    // pos
    void cargar_edificios(ifstream& archivo_ubics); // AGREGAR ESTADO_T

    // pre:
    // pos: 
    Edificio* buscar_por_nombre_edificio_en_lista(string nombre);

    // pre:
    // pos:
    int obtener_filas_mapa();

    // pre:
    // pos:
    int obtener_columnas_mapa();

    // pre: 
    // pos: 
    void mostrar_mapa();

    // pre:
    // pos: 
    void mostrar_edificios_construibles();

    // pre: 
    // pos: 
    void mostrar_edificios_construidos();

    // pre: 
    // pos: 
    void mostrar_andypolis();



};


#endif // ANDYPOLIS_H