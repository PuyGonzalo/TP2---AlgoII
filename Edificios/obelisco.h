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

    // pre:
    // pos:
    char obtener_material_brindado(){return ' ';}

    // pre:
    // pos:
    double obtener_cantidad_material_brindado(){return 0;}
};


#endif //OBELISCO_H
