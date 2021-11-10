#ifndef FABRICA_H
#define FABRICA_H

#include "../edificio.h"
#include "../material.h"

const double CANTIDAD_METAL_BRINDADA = 40;

class Fabrica: public Edificio {
private:
    // Atributos
    char identificador_material_brindado;
    double cantidad_material_brindado;

public:
    // Metodos

    // pre: 
    // pos: 
    Fabrica(string identificador);

    // pre: 
    // pos: 
    ~Fabrica(){};

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


#endif //FABRICA_H
