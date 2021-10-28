#include "escuela.h"

Escuela::Escuela(string identificador, int costo_piedra, int costo_madera, int costo_metal, int maximos_permitidos) :
Edificio(identificador, costo_piedra, costo_madera, costo_metal, maximos_permitidos){}

string Escuela::obtener_tipo_edificio(){
    return STR_ESCUELA;
}