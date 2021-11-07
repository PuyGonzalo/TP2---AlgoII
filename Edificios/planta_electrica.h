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
};


#endif //PLANTA_ELECTRICA_H
