#ifndef ANDYPOLIS_H
#define ANDYPOLIS_H

#include <sstream>
#include <fstream>
#include <string>
#include <locale>
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
    Datos_edificio** catalogo;
    Inventario inventario;
    int cantidad_edificios_catalogo;
    int cantidad_max_edificios_catalogo;


public:
    // Metodos
    Andypolis(ifstream& archivo_edif, ifstream& archivo_ubics, ifstream& archivo_mapa, ifstream& archivo_mats);

    ~Andypolis(); // destruir lista y mapa

    // pre:
    // pos: 
    void cargar_catalogo(ifstream& archivo_edif);

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
    void mostrar_catalogo();

    // pre: 
    // pos: 
    void mostrar_andypolis();

    // pre:
    // pos:
    void consultar_casillero_de_mapa(int coord_x, int coord_y); // estado t

    // pre:
    // pos:
    void mostrar_inventario();

    // pre:
    // pos:
    void mostrar_edificios_en_andypolis();

    // pre: 
    // pos: 
    void cargar_coordenadas_en_catalogo(string nombre_edificio, int coord_x, int coord_y);

    // pre:
    // pos:
    void listar_edificios_construidos();



};


#endif // ANDYPOLIS_H