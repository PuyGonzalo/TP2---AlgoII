#include <iostream>
#include "madera.h"

// idealmente en un cpp
Madera::Madera(double cantidad) : Material(cantidad) {
    this -> identificador = IDENTIF_MADERA;
}


string Madera::obtener_tipo_material(){
    return STR_MADERA;
}
