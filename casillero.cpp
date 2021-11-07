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


Casillero::Casillero(){

    this -> coord_x = -1; // 0,0 ES una posicion valida en el mapa.
    this -> coord_y = -1;
    this -> ocupado = false;

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


bool Casillero::es_casillero_transitable(){

    return superficie -> es_transitable();

}


// ------------------------------------------------------------------------------------------------------------


bool Casillero::es_casillero_construible(){

    return superficie -> es_construible();

}


// ------------------------------------------------------------------------------------------------------------


bool Casillero::es_casillero_accesible(){

    return superficie -> es_accesible();

}