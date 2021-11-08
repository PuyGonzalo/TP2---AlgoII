#ifndef CASILLERO_TRANSITABLE_H
#define CASILLERO_TRANSITABLE_H

#include "../material.h"
#include "../casillero.h"
#include "../formatos.h"

class Casillero_Transitable: public Casillero {

private:
    // Atributos
    Material* material_ocupado = nullptr; // al momento de crearse no tiene nada "en el piso"

public:
    // Metodos

    // pre: -
    // pos: CONSTRUCTOR de un casillero transitable
    Casillero_Transitable(Superficie* superficie, int coord_x, int coord_y, bool ocupado);

    // pre: -
    // pos: CONSTRUCTOR de un casillero transitable default
    Casillero_Transitable():Casillero(){};

    // pre: -
    // pos: DESTRUCTOR de un casillero transitable
    ~Casillero_Transitable();

    // pre: -
    // pos: imprime una letra que representa el material que tiene "en el piso" y el color de la superficie del casillero
    void imprimir_casillero();

    // pre: -
    // pos: imprime un mensaje diciendo si tiene o no un material y que es un casillero transitable
    void consultar_casillero();

    // pre: -
    // pos: pone/"tira" un material en el casillero
    void poner_material_en_casillero(Material* material);

};



#endif // CASILLERO_TRANSITABLE_H