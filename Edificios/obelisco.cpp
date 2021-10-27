#include "obelisco.h"

Obelisco::Obelisco(string identificador, int consto_piedra, int costo_madera, int costo_metal, int maximos_permitidos):
Edificio(identificador, consto_piedra, costo_madera, costo_metal, maximos_permitidos){}

string Obelisco::obtener_tipo_edificio(){
    return STR_OBELISCO;
}
