#include "aserradero.h"



// ------------------------------------------------------------------------------------------------------------


Aserradero::Aserradero(string identificador) : Edificio(identificador) {
    this -> identificador_material_brindado = IDENTIF_MADERA;
    this -> cantidad_material_brindado = CANTIDAD_MADERA_BRINDADA;
}


// ------------------------------------------------------------------------------------------------------------


string Aserradero::obtener_tipo_edificio(){
    return STR_ASERRADERO;
}


// ------------------------------------------------------------------------------------------------------------


char Aserradero::obtener_material_brindado(){
    return this -> identificador_material_brindado;
}


// ------------------------------------------------------------------------------------------------------------


double Aserradero::obtener_cantidad_material_brindado(){
    return this -> cantidad_material_brindado;
}
