#ifndef CASILLERO_CONSTRUIBLE_H
#define CASILLERO_CONSTRUIBLE_H

#include "../edificio.h"
#include "../casillero.h"

class Casillero_Construible: public Casillero {

private:
    // Atributos
    Edificio* edificio_construido;

public:
    // Metodos
    Casillero_Construible(Superficie* superficie, int coord_x, int coord_y, bool ocupado);

    // pre:
    // pos:
    void imprimir_casillero();

    // pre:
    // pos:
    void consultar_casillero();

};



#endif // CASILLERO_CONSTRUIBLE_H