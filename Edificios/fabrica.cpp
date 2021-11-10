#include "fabrica.h"

Fabrica::Fabrica(string identificador) : Edificio(identificador) {
    this -> identificador_material_brindado = IDENTIF_METAL;
    this -> cantidad_material_brindado = CANTIDAD_METAL_BRINDADA;
}

string Fabrica::obtener_tipo_edificio(){
    return STR_FABRICA;
}

char Fabrica::obtener_material_brindado(){
    return this -> identificador_material_brindado;
}

double Fabrica::obtener_cantidad_material_brindado(){
    return this -> cantidad_material_brindado;
}