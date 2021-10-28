#include <iostream>
#include "lago.h"


Lago::Lago() : Superficie(identificador) {
    this -> color = "azul";
    this -> transitable = false;
    this -> construible = false;
    this -> accesible = false;
}

