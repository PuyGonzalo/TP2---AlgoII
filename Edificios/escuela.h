#ifndef ESCUELA_H
#define ESCUELA_H

#include "../edificio.h"

class Escuela: public Edificio {

public:
    // Metodos

    // pre: 
    // pos: 
    Escuela(string identificador);

    // pre: 
    // pos: 
    ~Escuela(){};

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


#endif //ESCUELA_H
