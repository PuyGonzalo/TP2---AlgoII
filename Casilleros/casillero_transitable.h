#ifndef CASILLERO_TRANSITABLE_H
#define CASILLERO_TRANSITABLE_H

#include "../material.h"
#include "../casillero.h"
#include "../formatos.h"

class Casillero_Transitable: public Casillero {

private:
    // Atributos
    Material* material_ocupado;

public:
    // Metodos
    Casillero_Transitable(Superficie* superficie, int coord_x, int coord_y, bool ocupado);

    ~Casillero_Transitable(){};

    // pre:
    // pos:
    void imprimir_casillero();

    // pre:
    // pos:
    void consultar_casillero();

    // pre: 
    // pos: 
    void poner_material_en_casillero(Material* mat);

};



#endif // CASILLERO_TRANSITABLE_H