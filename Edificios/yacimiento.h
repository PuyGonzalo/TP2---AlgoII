#ifndef YACIMIENTO_H
#define YACIMIENTO_H

#include "../edificio.h"

class Yacimiento: public Edificio {
public:
    // Metodos

    // pre: 
    // pos: 
    Yacimiento(string identificador);

    // pre: 
    // pos: 
    ~Yacimiento(){};

    // pre: 
    // pos: 
    string obtener_tipo_edificio();
};


#endif //YACIMIENTO_H
