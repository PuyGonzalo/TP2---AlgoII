#ifndef ESCUELA_H
#define ESCUELA_H

#include "../edificio.h"

class Escuela: public Edificio {
public:
    Escuela(string identificador, int consto_piedra, int costo_madera, int costo_metal,int cantidad_construidos, int maximos_permitidos);
    ~Escuela(){};
    string obtener_tipo_edificio();
};


#endif //ESCUELA_H
