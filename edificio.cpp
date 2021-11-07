#include "edificio.h"


// ------------------------------------------------------------------------------------------------------------


Edificio::Edificio(){

    this -> identificador = ' ';

}


// ------------------------------------------------------------------------------------------------------------


Edificio::Edificio(string identificador){

    this -> identificador = identificador;

}


// ------------------------------------------------------------------------------------------------------------


string Edificio::obtener_identificador(){
    return this -> identificador;
}


// ------------------------------------------------------------------------------------------------------------


// Esta funcion seguramente no quede definida aca. Va a ir en otro lado, esto es solo de prueba.
bool contiene_numeros(string s){
    const string CONT = "0123456789";
    if(s.find_first_of(CONT) != string::npos){
        return true;
    }else
        return false;
}