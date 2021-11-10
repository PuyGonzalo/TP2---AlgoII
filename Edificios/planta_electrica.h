#ifndef PLANTA_ELECTRICA_H
#define PLANTA_ELECTRICA_H

#include "../edificio.h"

class Planta_electrica: public Edificio {
public:
    // Metodos

    // pre: -
    // pos: CONSTRUCTOR planta electrica 
    Planta_electrica(string identificador);

    // pre: -
    // pos: DESTRUCTOR planta electrica 
    ~Planta_electrica(){};

    // pre: -
    // pos: obtiene el tipo de edificio que es (su "nombre")
    string obtener_tipo_edificio();

    // pre: -
    // pos: no brinda material (se necesita por metodo virtual puro que se uso para devolver return =/= void)
    char obtener_material_brindado(){return ' ';}

    // pre: -
    // pos: no brinda material (se necesita por metodo virtual puro que se uso para devolver return =/= void)
    double obtener_cantidad_material_brindado(){return 0;}
};


#endif //PLANTA_ELECTRICA_H
