#include "planta_electrica.h"

Planta_Electrica::Planta_Electrica(string identificador, int consto_piedra, int costo_madera, int costo_metal,int cantidad_construidos, int maximos_permitidos) :
Edificio(identificador, consto_piedra, costo_madera, costo_metal, cantidad_construidos, maximos_permitidos){}


string Planta_Electrica::obtener_tipo_edificio(){
    return STR_P_ELECTRICA;
}