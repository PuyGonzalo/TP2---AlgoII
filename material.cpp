#include <iostream>
#include "material.h"


// ------------------------------------------------------------------------------------------------------------


Material::Material(string nombre, string indentificador, double cantidad){

    this -> nombre = nombre;
    this -> identificador = identificador;
    this -> cantidad = cantidad;

}


// ------------------------------------------------------------------------------------------------------------


Material::Material(){

    this -> nombre = " ";
    this -> identificador = ' ';
    this -> cantidad = -1; // 0 es una cantidad viable.. OJO

}


// ------------------------------------------------------------------------------------------------------------


Material::Material(string linea){

    string aux_nombre;
    string aux_cantidad_str;

    stringstream sstream(linea);

    sstream >> aux_nombre;
    sstream >> aux_cantidad_str;

    this -> identificador = obtener_identificador_con_nombre(aux_nombre);
    this -> nombre = aux_nombre;
    this -> cantidad = stod(aux_cantidad_str);

}


// ------------------------------------------------------------------------------------------------------------


string Material::obtener_nombre(){

    return nombre;

}


// ------------------------------------------------------------------------------------------------------------


string Material::obtener_identificador(){

    return identificador;

}


// ------------------------------------------------------------------------------------------------------------


double Material::obtener_cantidad(){

    return cantidad;

}


// ------------------------------------------------------------------------------------------------------------


void Material::agregar_cantidad(double cantidad){

    cantidad += cantidad;

}


// ------------------------------------------------------------------------------------------------------------


void Material::restar_cantidad(double cantidad){

    cantidad -= cantidad;

}


// ------------------------------------------------------------------------------------------------------------


string Material::obtener_identificador_con_nombre(string nombre){

    string aux_identif = "?"; // si no es de construccion, no tiene identificador.

    for (int i = 0 ; i < CANT_MATERIALES_CONSTRUCCION ; i++){
        if( nombre == materiales_de_construccion[i][0])
            aux_identif = materiales_de_construccion[i][1];
    }

    return aux_identif;

}