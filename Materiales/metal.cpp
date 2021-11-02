#include <iostream>
#include "metal.h"


// ------------------------------------------------------------------------------------------------------------


Metal::Metal(double cantidad) : Material(cantidad) {
    this -> identificador = IDENTIF_METAL;
}


// ------------------------------------------------------------------------------------------------------------


string Metal::obtener_tipo_material(){
    return STR_METAL;
}