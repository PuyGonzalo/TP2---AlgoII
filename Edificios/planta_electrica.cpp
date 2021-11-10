#include "planta_electrica.h"


// ------------------------------------------------------------------------------------------------------------


Planta_electrica::Planta_electrica(string identificador) : Edificio(identificador){}


// ------------------------------------------------------------------------------------------------------------


string Planta_electrica::obtener_tipo_edificio(){

    return STR_P_ELECTRICA;
}