#include <iostream>
#include "terreno.h"


Terreno::Terreno() : Superficie(identificador) {
    this -> color = "verde";
    this -> transitable = false;
    this -> construible = true;
    this -> accesible = false;
}

