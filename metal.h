#ifndef METAL_H
#define METAL_H

#include "material.h"

class Metal: public Material {

public:
    Metal(double cantidad);
    ~Metal(){};

    string obtener_tipo_material();

};






#endif // METAL_H
