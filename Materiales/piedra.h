#ifndef PIEDRA_H
#define PIEDRA_H

#include "../material.h"


class Piedra: public Material {

public:
    Piedra(double cantidad);
    ~Piedra(){};

    string obtener_tipo_material();

};




#endif // PIEDRA_H
