#ifndef MINA_H
#define MINA_H

#include "../edificio.h"
#include "../material.h"

const int CANTIDAD_PIEDRA_BRINDADA = 15;

class Mina: public Edificio {
private:
    // Atributos
    string material_brindado;
    int cantidad_material_brindado;

public:
    // Metodos

    // pre: 
    // pos: 
    Mina(string identificador, int costo_piedra, int costo_madera, int costo_metal, int maximos_permitidos);

    // pre: 
    // pos: 
    ~Mina(){};

    // pre: 
    // pos: 
    string obtener_tipo_edificio();

    // pre: 
    // pos: 
    string obtener_material_brindado();

    // pre: 
    // pos: 
    int obtener_cantidad_material_brindado();
};


#endif //MINA_H
