#ifndef YACIMIENTO_H
#define YACIMIENTO_H

#include "../edificio.h"

class Yacimiento: public Edificio {
public:
    Yacimiento(string identificador, int consto_piedra, int costo_madera, int costo_metal, int maximos_permitidos);
    ~Yacimiento(){};
    string obtener_tipo_edificio();
};


#endif //YACIMIENTO_H
