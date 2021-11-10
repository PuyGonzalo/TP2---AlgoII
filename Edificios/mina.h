#ifndef MINA_H
#define MINA_H

#include "../edificio.h"
#include "../material.h"

const double CANTIDAD_PIEDRA_BRINDADA = 15;

class Mina: public Edificio {
private:
    // Atributos
    char identificador_material_brindado;
    double cantidad_material_brindado;

public:
    // Metodos

    // pre: 
    // pos: 
    Mina(string identificador);

    // pre: 
    // pos: 
    ~Mina(){};

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


#endif //MINA_H
