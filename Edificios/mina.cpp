#include "mina.h"

Mina::Mina(string identificador, int consto_piedra, int costo_madera, int costo_metal,int cantidad_construidos, int maximos_permitidos) :
Edificio(identificador, consto_piedra, costo_madera, costo_metal, cantidad_construidos, maximos_permitidos) {
    this -> material_brindado = STR_PIEDRA;
    this -> cantidad_material_brindado = CANTIDAD_PIEDRA_BRINDADA;
}

string Mina::obtener_tipo_edificio(){
    return STR_MINA;
}

string Mina::obtener_material_brindado(){
    return this -> material_brindado;
}

int Mina::obtener_cantidad_material_brindado(){
    return this -> cantidad_material_brindado;
}
