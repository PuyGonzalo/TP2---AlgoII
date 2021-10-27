#include "fabrica.h"

Fabrica::Fabrica(string identificador, int consto_piedra, int costo_madera, int costo_metal, int maximos_permitidos) :
Edificio(identificador, consto_piedra, costo_madera, costo_metal, maximos_permitidos) {
    this -> material_brindado = STR_METAL;
    this -> cantidad_material_brindado = CANTIDAD_METAL_BRINDADA;
}

string Fabrica::obtener_tipo_edificio(){
    return STR_FABRICA;
}

string Fabrica::obtener_material_brindado(){
    return this -> material_brindado;
}

int Fabrica::obtener_cantidad_material_brindado(){
    return this -> cantidad_material_brindado;
}