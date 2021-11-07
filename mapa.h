#ifndef MAPA_H
#define MAPA_H

#include "casillero.h"
#include "superficie.h"
#include "parser.h"
#include "Casilleros/casillero_construible.h"
#include "Casilleros/casillero_inaccesible.h"
#include "Casilleros/casillero_transitable.h"


class Mapa{

private:
    // Atributos
    Casillero*** mapa;
    int cantidad_filas;
    int cantidad_columnas;

public:
    // Metodos

    // pre: archivo debe ser valido
    // pos: CONSTRUCTOR del mapa
    Mapa(ifstream& archivo_mapa);

    // pre: archivo debe ser valido
    // pos: CONSTRUCTOR del mapa default
    Mapa();

    // pre: -
    // pos: DESCTRUCTOR del mapa
    ~Mapa();

    // pre: -
    // pos: obtiene la cantidad de filas que tiene el mapa
    int obtener_filas();

    // pre: -
    // pos: obtiene la cantidad de columnas que tiene el mapa
    int obtener_columnas();

    // pre: coordenadas validas (depende de mapa.txt)
    // pos: devuelve si un casillero particular del mapa es transitable
    bool se_puede_transitar(int coord_x, int coord_y);

    // pre: coordenadas validas (depende de mapa.txt)
    // pos: devuelve si un casillero particular del mapa es construible
    bool se_puede_construir(int coord_x, int coord_y);

    // pre: coordenadas validas (depende de mapa.txt)
    // pos: devuelve si un casillero particular del mapa es accesible
    bool se_puede_acceder(int coord_x, int coord_y);

    // pre: coordenadas validas (depende de mapa.txt)
    // pos: devuelve si un casillero particular del mapa esta ocupado
    bool casillero_esta_ocupado(int coord_x, int coord_y);

    // pre: coordenadas validas
    // pos: "construye" un edificio en una coordenada dada (y devuelve un error en caso de que sea no sea construible o ya este ocupado)
    void construir_edificio_en_coord(Edificio* edificio, int coord_x, int coord_y); // status t

    // pre: coordenadas validas
    // pos: consulta un casillero del mapa en particular
    void consultar_casillero(int coord_x, int coord_y);

    // pre: -
    // pos: muestra el mapa con sus edificios y materiales
    void mostrar_mapa();

};





#endif // MAPA_H