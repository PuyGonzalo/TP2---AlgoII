#ifndef SUPERFICIE_H
#define SUPERFICIE_H

#include <sstream>
#include <fstream>
#include <string>
#include "errores.h"
#include "Casilleros/formatos.h"

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
    Superficie(char identificador);

    // pre:
    // pos:
    Superficie(){}; // IMPLEMENTAR?

    // pre: 
    // pos: 
    char obtener_identificador();

    // pre: 
    // pos: 
    string obtener_color();

    // pre: 
    // pos: 
    bool es_transitable();

    // pre: 
    // pos: 
    bool es_construible();

    // pre: 
    // pos: 
    bool es_accesible();

};


#endif // SUPERFICIE_H