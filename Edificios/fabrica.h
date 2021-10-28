#ifndef FABRICA_H
#define FABRICA_H

#include "../edificio.h"
#include "../material.h"

const int CANTIDAD_METAL_BRINDADA = 40;

class Fabrica: public Edificio {
private:
    // Atributos
    string material_brindado;
    int cantidad_material_brindado;

public:
    // Metodos

    // pre: 
    // pos: 
    Fabrica(string identificador, int consto_piedra, int costo_madera, int costo_metal, int maximos_permitidos);

    // pre: 
    // pos: 
    ~Fabrica(){};

    // pre: 
    // pos: 
    string obtener_tipo_edificio();

    // pre: 
    // pos: 
    string obtener_material_brindado();

    // pre: 
    // pos: 
    int obtener_cantidad_material_brindado();
};


#endif //FABRICA_H
