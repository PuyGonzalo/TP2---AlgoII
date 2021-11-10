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

    // pre: -
    // pos: CONSTRUCTOR mina
    Mina(string identificador);

    // pre: -
    // pos: DESTRUCTOR mina
    ~Mina(){};

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


#endif //MINA_H
