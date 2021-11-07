#ifndef SUPERFICIE_H
#define SUPERFICIE_H

#include <sstream>
#include <fstream>
#include <string>
#include "errores.h"
#include "formatos.h"

using namespace std;

const int CANT_SUPERFICIES = 3;
const string STR_COLOR_AZUL = "azul";
const string STR_COLOR_VERDE = "verde";
const string STR_COLOR_GRIS = "gris";

const string codigos_color_superficies[CANT_SUPERFICIES][CANT_SUPERFICIES] = {
    {STR_COLOR_AZUL, FONDO_COLOR_AZUL},
    {STR_COLOR_GRIS, FONDO_COLOR_GRIS},
    {STR_COLOR_VERDE, FONDO_COLOR_VERDE}
};

const char identificador_lago = 'L';
const char identificador_terreno = 'T';
const char identificador_camino = 'C';

class Superficie{

protected:
    // Atributos
    char identificador;
    string color;
    bool transitable;
    bool construible;
    bool accesible;

public:
    // Metodos

    // pre: -
    // pos: CONSTRUCTOR de superficie
    Superficie(char identificador);

    // pre: -
    // pos: CONSTRUCTOR de una superficie default
    Superficie();

    // pre: -
    // pos: DESTRUCTOR de una superficie (virtual hacia todas las hiajs)
    virtual ~Superficie(){};

    // pre: -
    // pos: devuelve el identificador de la superficie
    char obtener_identificador();

    // pre: -
    // pos: obtiene el color caracteristico de la superficie
    string obtener_color();

    // pre: -
    // pos: devuelve si es una superficie transitable o no
    bool es_transitable();

    // pre: -
    // pos: devuelve si es una superficie construible o no
    bool es_construible();

    // pre: -
    // pos: devuelve si es una superficie accesible o no
    bool es_accesible();

};


#endif // SUPERFICIE_H