#ifndef ASERRADERO_H
#define ASERRADERO_H

#include "../edificio.h"
#include "../material.h"

const int CANTIDAD_MADERA_BRINDADA = 25;


class Aserradero: public Edificio {
private:
    // Atributos
    string material_brindado;
    int cantidad_material_brindado;

public:
    // Metodos

    // pre: 
    // pos: 
    Aserradero(string identificador, int costo_piedra, int costo_madera, int costo_metal, int maximos_permitidos);

    // pre: 
    // pos: 
    ~Aserradero(){};

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


#endif //ASERRADERO_H
