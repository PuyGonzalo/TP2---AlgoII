#include "escuela.h"

Escuela::Escuela(string identificador) : Edificio(identificador){}

string Escuela::obtener_tipo_edificio(){
    return STR_ESCUELA;
}