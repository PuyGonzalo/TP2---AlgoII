#ifndef PLANTA_ELECTRICA_H
#define PLANTA_ELECTRICA_H

#include "../edificio.h"

class Planta_Electrica: public Edificio {
public:
    // Metodos

    // pre: 
    // pos: 
    Planta_Electrica(string identificador);

    // pre: 
    // pos: 
    ~Planta_Electrica(){};

    // pre: 
    // pos: 
    string obtener_tipo_edificio();

    // pre:
    // pos:
    char obtener_material_brindado(){return ' ';}

    // pre:
    // pos:
    double obtener_cantidad_material_brindado(){return 0;}
};


#endif //PLANTA_ELECTRICA_H
