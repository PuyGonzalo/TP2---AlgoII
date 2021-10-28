#ifndef YACIMIENTO_H
#define YACIMIENTO_H

#include "../edificio.h"

class Yacimiento: public Edificio {
public:
    // Metodos

    // pre: 
    // pos: 
    Yacimiento(string identificador, int costo_piedra, int costo_madera, int costo_metal, int maximos_permitidos);

    // pre: 
    // pos: 
    ~Yacimiento(){};

    // pre: 
    // pos: 
    string obtener_tipo_edificio();
};


#endif //YACIMIENTO_H
