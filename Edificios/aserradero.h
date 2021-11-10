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

    // pre: 
    // pos: 
    Aserradero(string identificador);

    // pre: 
    // pos: 
    ~Aserradero(){};

    // pre: 
    // pos: 
    string obtener_tipo_edificio();

    // pre: 
    // pos: 
    char obtener_material_brindado();

    // pre: 
    // pos: 
    double obtener_cantidad_material_brindado();
};


#endif //ASERRADERO_H
