#include "edificio.h"

Edificio::Edificio(){
    this -> identificador = ' ';
    this -> costo_piedra = -1;
    this -> costo_madera = -1;
    this -> costo_metal = -1;
    this -> maximos_permitidos = -1;
}

/*
Edificio::Edificio(string linea){
    //Resolvi el problema usando toupper.
    // Tengo entendido que es una funcion de C (habria que ver si nos dicen algo por usarla).
    //Ni puta idea que es eso de locale loc (lo saque de la documentacion de toupper en cplusplus.com).
    locale loc;
    string aux;

    stringstream sstream(linea);
    sstream >> this -> nombre;
    this -> identificador = toupper(this->nombre[POS_PRIMERA_LETRA],loc);
    sstream >> aux;
    while(!contiene_numeros(aux)){
        this -> nombre.append(ESPACIO);
        this -> nombre.append(aux);
        sstream >> aux;
    }
    this -> costo_piedra = stoi(aux);
    sstream >> aux;
    this -> costo_madera = stoi(aux);
    sstream >> aux;
    this -> costo_metal = stoi(aux);
    sstream >> aux;
    this -> maximos_permitidos = stoi(aux);

    this -> cantidad_construidos = 0; // Esta bien esto ?
    // Faltaria material brindado. No se nos ocurre como hacerlo de una manera elegante.
}
*/

Edificio::Edificio(string identificador, int consto_piedra, int costo_madera, int costo_metal, int maximos_permitidos){
    this -> identificador = identificador;
    this -> costo_piedra = consto_piedra;
    this -> costo_madera = costo_madera;
    this -> costo_metal = costo_metal;
    this -> cantidad_construidos = 0;
    this -> maximos_permitidos = maximos_permitidos;
}

int Edificio::obtener_costo_piedra(){
    return this -> costo_piedra;
}

int Edificio::obtener_costo_madera(){
    return this -> costo_madera;
}

int Edificio::obtener_costo_metal() {
    return this -> costo_metal;
}

int Edificio::obtener_maximos_permitidos(){
    return this -> maximos_permitidos;
}


string Edificio::obtener_identificador(){
    return this -> identificador;
}


void Edificio::agregar_cantidad_construidos(){
    this -> cantidad_construidos++;
}

void Edificio::restar_cantidad_construidos(){
    if(this -> cantidad_construidos != 0) {
        this -> cantidad_construidos--;
    }
    // Retornar error con estado_t
}


// Esta funcion seguramente no quede definida aca. Va a ir en otro lado, esto es solo de prueba.
bool contiene_numeros(string s){
    const string CONT = "0123456789";
    if(s.find_first_of(CONT) != string::npos){
        return true;
    }else
        return false;
}