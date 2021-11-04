#include <iostream>
#include "casillero.h"


// ------------------------------------------------------------------------------------------------------------


Casillero::Casillero(Superficie* superficie, int coord_x, int coord_y, bool ocupado){

    this -> superficie = superficie;
    this -> coord_x = coord_x;
    this -> coord_y = coord_y;
    this -> ocupado = ocupado;

}

// ------------------------------------------------------------------------------------------------------------

Casillero::~Casillero(){
    if(superficie!=nullptr){
        delete superficie;
        superficie=nullptr;
    }
}


// ------------------------------------------------------------------------------------------------------------


int Casillero::obtener_coordenada_x(){

    return coord_x;

}


// ------------------------------------------------------------------------------------------------------------


int Casillero::obtener_coordenada_y(){

    return coord_y;

}


// ------------------------------------------------------------------------------------------------------------


bool Casillero::esta_ocupado(){

    return ocupado;

}

// ------------------------------------------------------------------------------------------------------------

Superficie* Casillero::obtener_superficie(){
    return this -> superficie;
}