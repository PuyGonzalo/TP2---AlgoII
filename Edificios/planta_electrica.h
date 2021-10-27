#ifndef PLANTA_ELECTRICA_H
#define PLANTA_ELECTRICA_H

#include "../edificio.h"

class Planta_Electrica: public Edificio {
public:
    Planta_Electrica(string identificador, int consto_piedra, int costo_madera, int costo_metal,int cantidad_construidos, int maximos_permitidos);
    ~Planta_Electrica(){};
    string obtener_tipo_edificio();
};


#endif //PLANTA_ELECTRICA_H
