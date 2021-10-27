#ifndef ASERRADERO_H
#define ASERRADERO_H

#include "../edificio.h"
#include "../material.h"

const int CANTIDAD_MADERA_BRINDADA = 25;


class Aserradero: public Edificio {
private:
    string material_brindado;
    int cantidad_material_brindado;
public:
    Aserradero(string identificador, int consto_piedra, int costo_madera, int costo_metal,int cantidad_construidos, int maximos_permitidos);
    ~Aserradero(){};
    string obtener_tipo_edificio();
    string obtener_material_brindado();
    int obtener_cantidad_material_brindado();
};


#endif //TP2___ALGOII_ASERRADERO_H
