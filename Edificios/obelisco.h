#ifndef OBELISCO_H
#define OBELISCO_H

#include "../edificio.h"


class Obelisco: public Edificio {
public:
    // Metodos

    // pre: 
    // pos: 
    Obelisco(string identificador);

    // pre: 
    // pos: 
    ~Obelisco(){};

    // pre: 
    // pos: 
    string obtener_tipo_edificio();
};


#endif //OBELISCO_H
