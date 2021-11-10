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

    // pre:
    // pos:
    char obtener_material_brindado(){return ' ';}

    // pre:
    // pos:
    double obtener_cantidad_material_brindado(){return 0;}
};


#endif //YACIMIENTO_H
