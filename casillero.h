#ifndef CASILLERO_H
#define CASILLERO_H

#include <sstream>
#include <fstream>
#include <string>
#include "errores.h"
#include "superficie.h"

using namespace std;

class Casillero{

protected:
    // Atributos
    Superficie* superficie;
    int coord_x;
    int coord_y;
    bool ocupado;


public:
    // Metodos
    Casillero(Superficie* superficie, int coord_x, int coord_y, bool ocupado);

    virtual ~Casillero(){};

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

};


#endif // CASILLERO_H