#ifndef CASILLERO_INACCESIBLE_H
#define CASILLERO_INACCESIBLE_H


#include "../casillero.h"
#include "../formatos.h"

class Casillero_Inaccesible : public Casillero {

public:
    // Metodos

    // pre: -
    // pos: CONSTRUCTOR de un casillero inaccesible
    Casillero_Inaccesible(Superficie* superficie, int coord_x, int coord_y, bool ocupado);

    // pre: -
    // pos: CONSTRUCTOR de un casillero inaccesible default
    Casillero_Inaccesible():Casillero(){};

    // pre: -
    // pos: DESTRUCTOR de un casillero transitable
    ~Casillero_Inaccesible(){};

    // pre: -
    // pos: imprime el color de la superficie del casillero (es inaccesible asi que no tiene nada)
    void imprimir_casillero();

    // pre: -
    // pos: imprime un mensaje diciendo que es un casillero inaccesible
    void consultar_casillero();
};



#endif // CASILLERO_INACCESIBLE_H