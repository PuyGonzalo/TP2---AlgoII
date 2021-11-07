#include "aserradero.h"

Aserradero::Aserradero(string identificador) : Edificio(identificador) {
    this -> material_brindado = STR_MADERA;
    this -> cantidad_material_brindado = CANTIDAD_MADERA_BRINDADA;
}

string Aserradero::obtener_tipo_edificio(){
    return STR_ASERRADERO;
}

string Aserradero::obtener_material_brindado(){
    return this -> material_brindado;
}

int Aserradero::obtener_cantidad_material_brindado(){
    return this -> cantidad_material_brindado;
}
