#include "yacimiento.h"

Yacimiento::Yacimiento(string identificador) : Edificio(identificador){}


string Yacimiento::obtener_tipo_edificio(){
    return STR_YACIMIENTO;
}