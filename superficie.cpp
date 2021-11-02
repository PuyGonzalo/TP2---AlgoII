#include <iostream>
#include "superficie.h"


// ------------------------------------------------------------------------------------------------------------


Superficie::Superficie(char identificador){

    this -> identificador = identificador;

}


// ------------------------------------------------------------------------------------------------------------


char Superficie::obtener_identificador(){

    return identificador;

}


// ------------------------------------------------------------------------------------------------------------


string Superficie::obtener_color(){

    return color;

}


// ------------------------------------------------------------------------------------------------------------


bool Superficie::es_transitable(){

    return transitable;

}


// ------------------------------------------------------------------------------------------------------------


bool Superficie::es_construible(){

    return construible;

}


// ------------------------------------------------------------------------------------------------------------


bool Superficie::es_accesible(){

    return accesible;

}