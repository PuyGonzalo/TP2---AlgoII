#ifndef SUPERFICIE_H
#define SUPERFICIE_H

#include <sstream>
#include <fstream>
#include <string>
#include "errores.h"

using namespace std;

class Superficie{

protected:
    // Atributos
    char identificador;
    string color; // "ROJO" o "R" ? 
    bool transitable;
    bool construible;
    bool accesible;

public:
    // Metodos
    Superficie(char identificador);

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