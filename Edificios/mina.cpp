#include "mina.h"

Mina::Mina(string identificador) : Edificio(identificador) {
    this -> identificador_material_brindado = IDENTIF_PIEDRA;
    this -> cantidad_material_brindado = CANTIDAD_PIEDRA_BRINDADA;
}

string Mina::obtener_tipo_edificio(){
    return STR_MINA;
}

char Mina::obtener_material_brindado(){
    return this -> identificador_material_brindado;
}

double Mina::obtener_cantidad_material_brindado(){
    return this -> cantidad_material_brindado;
}
