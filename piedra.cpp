#include <iostream>
#include "piedra.h"


// idealmente en un cpp
Piedra::Piedra(double cantidad) : Material(cantidad) {
    this -> identificador = IDENTIF_PIEDRA;
}


string Piedra::obtener_tipo_material(){
    return STR_PIEDRA;
}