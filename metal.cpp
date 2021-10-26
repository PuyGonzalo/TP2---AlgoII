#include <iostream>
#include "metal.h"

// idealmente en un cpp
Metal::Metal(double cantidad) : Material(cantidad) {
    this -> identificador = IDENTIF_METAL;
}


string Metal::obtener_tipo_material(){
    return STR_METAL;
}