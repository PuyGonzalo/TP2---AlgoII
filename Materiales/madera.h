#ifndef MADERA_H
#define MADERA_H

#include "../material.h"


class Madera: public Material {

public:
    Madera(double cantidad);
    ~Madera(){};

    string obtener_tipo_material();

};




#endif // MADERA_H
