#ifndef CASILLERO_CONSTRUIBLE_H
#define CASILLERO_CONSTRUIBLE_H

#include "../edificio.h"
#include "../casillero.h"
#include "../formatos.h"

class Casillero_Construible: public Casillero {

private:
    // Atributos
    Edificio* edificio_construido = nullptr; // hasta no leer ubicaciones.txt no tiene sentido construir el casillero con el edificio

public:
    // Metodos

    // pre: -
    // pos: CONSTRUCTOR de un casillero construible
    Casillero_Construible(Superficie* superficie, int coord_x, int coord_y, bool ocupado);

    // pre: -
    // pos: CONSTRUCTOR de un casillero construible default
    Casillero_Construible():Casillero(){};

    // pre: -
    // pos: DESTRUCTOR de un casillero construible
    ~Casillero_Construible();

    // pre: -
    // pos: imprime una letra que representa el edificio que tiene construido y el color de la superficie del casillero
    void imprimir_casillero();

    // pre: -
    // pos: imprime un mensaje diciendo si tiene o no un edificio construido y que es un casillero construible
    void consultar_casillero();

    // pre: -
    // pos: "construye" un edificio en el casillero
    void construir_edificio_en_casillero(Edificio* edificio);

};



#endif // CASILLERO_CONSTRUIBLE_H