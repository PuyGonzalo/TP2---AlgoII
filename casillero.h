#ifndef CASILLERO_H
#define CASILLERO_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "errores.h"
#include "superficie.h"
#include "edificio.h"

using namespace std;

class Casillero{

protected:
    // Atributos
    Superficie* superficie = nullptr;
    int coord_x;
    int coord_y;
    bool ocupado;


public:
    // Metodos
    Casillero(Superficie* superficie, int coord_x, int coord_y, bool ocupado);

    virtual ~Casillero();

    // pre: 
    // pos: 
    int obtener_coordenada_x();
    
    // pre: 
    // pos: 
    int obtener_coordenada_y();

    // pre:
    // pos:
    bool esta_ocupado();

    // pre:
    // pos:
    virtual void imprimir_casillero() = 0;

    // pre:
    // pos:
    virtual void consultar_casillero() = 0;

    // pre:
    // pos:
    bool es_casillero_transitable();

    // pre:
    // pos:
    bool es_casillero_construible();

    // pre:
    // pos:
    bool es_casillero_accesible();

    //PRE:
    //POST:
    virtual void construir_edificio_en_casillero(Edificio* edificio){};

};


#endif // CASILLERO_H