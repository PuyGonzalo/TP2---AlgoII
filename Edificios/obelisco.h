#ifndef OBELISCO_H
#define OBELISCO_H

#include "../edificio.h"


class Obelisco: public Edificio {
public:
    Obelisco(string identificador, int consto_piedra, int costo_madera, int costo_metal,int cantidad_construidos, int maximos_permitidos);
    ~Obelisco(){};
    string obtener_tipo_edificio();
};


#endif //OBELISCO_H
