#include "escuela.h"

Escuela::Escuela(string identificador, int consto_piedra, int costo_madera, int costo_metal,int cantidad_construidos, int maximos_permitidos) :
Edificio(identificador, consto_piedra, costo_madera, costo_metal, cantidad_construidos, maximos_permitidos){}

string Escuela::obtener_tipo_edificio(){
    return STR_ESCUELA;
}