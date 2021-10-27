#ifndef MINA_H
#define MINA_H

#include "../edificio.h"
#include "../material.h"

const int CANTIDAD_PIEDRA_BRINDADA = 15;

class Mina: public Edificio {
private:
    string material_brindado;
    int cantidad_material_brindado;
public:
    Mina(string identificador, int consto_piedra, int costo_madera, int costo_metal,int cantidad_construidos, int maximos_permitidos);
    ~Mina(){};
    string obtener_tipo_edificio();
    string obtener_material_brindado();
    int obtener_cantidad_material_brindado();
};


#endif //MINA_H
