#include <iostream>
#include "camino.h"


Camino::Camino(char identificador) : Superficie(identificador) {
    this -> color = "gris";
    this -> transitable = true;
    this -> construible = false;
    this -> accesible = true;
}