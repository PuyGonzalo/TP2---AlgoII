#include "planta_electrica.h"

Planta_Electrica::Planta_Electrica(string identificador) : Edificio(identificador){}


string Planta_Electrica::obtener_tipo_edificio(){

    return STR_P_ELECTRICA;
}