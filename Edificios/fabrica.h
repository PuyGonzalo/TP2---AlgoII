#ifndef FABRICA_H
#define FABRICA_H

#include "../edificio.h"
#include "../material.h"

const int CANTIDAD_METAL_BRINDADA = 40;

class Fabrica: public Edificio {
private:
    string material_brindado;
    int cantidad_material_brindado;
public:
    Fabrica(string identificador, int consto_piedra, int costo_madera, int costo_metal,int cantidad_construidos, int maximos_permitidos);
    ~Fabrica(){};
    string obtener_tipo_edificio();
    string obtener_material_brindado();
    int obtener_cantidad_material_brindado();
};


#endif //FABRICA_H
