#ifndef CASILLERO_INACCESIBLE_H
#define CASILLERO_INACCESIBLE_H


#include "../casillero.h"
#include "../formatos.h"

class Casillero_Inaccesible : public Casillero {

public:
    // Metodos
    Casillero_Inaccesible(Superficie* superficie, int coord_x, int coord_y, bool ocupado);

    // pre:
    // pos:
    void imprimir_casillero();

    // pre:
    // pos:
    void consultar_casillero();
};



#endif // CASILLERO_INACCESIBLE_H