#include "planta_electrica.h"

Planta_Electrica::Planta_Electrica(string identificador, int consto_piedra, int costo_madera, int costo_metal, int maximos_permitidos) :
Edificio(identificador, consto_piedra, costo_madera, costo_metal, maximos_permitidos){}


string Planta_Electrica::obtener_tipo_edificio(){
    return STR_P_ELECTRICA;
}