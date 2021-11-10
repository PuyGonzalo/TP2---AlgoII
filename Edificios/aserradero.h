#ifndef ASERRADERO_H
#define ASERRADERO_H

#include "../edificio.h"
#include "../material.h"

const double CANTIDAD_MADERA_BRINDADA = 25;


class Aserradero: public Edificio {
private:
    // Atributos
    char identificador_material_brindado;
    double cantidad_material_brindado;

public:
    // Metodos

    // pre: -
    // pos: CONSTRUCTOR aserradero
    Aserradero(string identificador);

    // pre: -
    // pos: DESTRUCTOR aserradero
    ~Aserradero(){};

    // pre: -
    // pos: obtiene el tipo de edificio que es (su "nombre")
    string obtener_tipo_edificio();

    // pre: -
    // pos: obtiene el identificador del material que brinda
    char obtener_material_brindado();

    // pre: -
    // pos: obtiene la cantidad de material que brinda
    double obtener_cantidad_material_brindado();
};


#endif //ASERRADERO_H
