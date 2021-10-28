#ifndef ESCUELA_H
#define ESCUELA_H

#include "../edificio.h"

class Escuela: public Edificio {

public:
    // Metodos

    // pre: 
    // pos: 
    Escuela(string identificador, int consto_piedra, int costo_madera, int costo_metal, int maximos_permitidos);

    // pre: 
    // pos: 
    ~Escuela(){};

    // pre: 
    // pos: 
    string obtener_tipo_edificio();
};


#endif //ESCUELA_H
