#include "edificio.h"

Edificio::Edificio(){
    this -> nombre = " ";
    this -> identificador = " ";
    this -> material_brindado = " ";
    this -> costo_piedra = -1;
    this -> costo_madera = -1;
    this -> costo_metal = -1;
    this -> cantidad_construidos = -1;
    this -> maximos_permitidos = -1;
}

Edificio::Edificio(string linea){
    const int CONSTATE_MAYUSCULA = 32;
    const int POS_PRIMERA_LETRA = 0;
    string aux;

    stringstream sstream(linea);
    sstream >> this -> nombre;
    this -> identificador = this -> nombre[POS_PRIMERA_LETRA] - CONSTATE_MAYUSCULA;
    sstream >> aux;
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

string Edificio::obtener_nombre(){
    return this -> nombre;
}

string Edificio::obtener_identificador(){
    return this -> identificador;
}

void Edificio::agregar_cantidad_construidos(){
    this -> cantidad_construidos++;
}

void Edificio::restar_cantidad_construidos(){
    if(this -> cantidad_construidos != 0)
        this -> cantidad_construidos--;
}