#include <iostream>
#include "parser.h"


// ------------------------------------------------------------------------------------------------------------


Parser::Parser(string linea) {

    this -> entrada = new string[cantidad_max_palabras_inicial];
    this -> cantidad_de_palabras = 0;
    this -> cantidad_de_palabras_max = cantidad_max_palabras_inicial;

    string palabra;
    string* nueva_entrada; // declararlo directo en el else?
    int i = 0;

    stringstream sstream(linea);
    while (sstream.good()){

        if(cantidad_de_palabras < cantidad_de_palabras_max){
        sstream >> this -> entrada[i];
        ++cantidad_de_palabras;
        ++i;
        } else {
            nueva_entrada = new string[cantidad_de_palabras_max+ampliacion_max_palabras];
            for(int j = 0; j < cantidad_de_palabras_max ; j++){
                nueva_entrada[j] = this -> entrada[j]; // reasigno punteros
            }
            sstream >> nueva_entrada[cantidad_de_palabras_max];

            delete [] this -> entrada;
            this -> entrada = nueva_entrada;
            cantidad_de_palabras_max += ampliacion_max_palabras;
            cantidad_de_palabras++;
            ++i;
        }
    }

}


// ------------------------------------------------------------------------------------------------------------


Parser::~Parser(){

    delete [] entrada;

}


// ------------------------------------------------------------------------------------------------------------


Material* Parser::procesar_entrada_material(){

    Material* material = nullptr; // esto no es instanciar la clase material

    // me fijo que tipo de material es para poder crearlo
    if (tipo_material() == STR_PIEDRA){
        material = new Piedra(cantidad_material()); // puedo hacerlo xq es un puntero, no una instancia (Y PORQUE PPALMENTE son madre-hijo)
    } else if (tipo_material() == STR_MADERA){
        material = new Madera(cantidad_material());
    } else {
        material = new Metal(cantidad_material());
    }

    return material;
}


// ------------------------------------------------------------------------------------------------------------


string Parser::tipo_material(){

    return entrada[0];

}


// ------------------------------------------------------------------------------------------------------------


double Parser::cantidad_material(){

    return stod(entrada[1]);

}


// ------------------------------------------------------------------------------------------------------------


Edificio* Parser::procesar_entrada_edificio(){
   
    Edificio* edificio = nullptr;

    if(nombre_edificio() == STR_MINA){
        edificio = new Mina(obtener_identificador_edificio(), costo_piedra(), costo_madera(), costo_metal(), cantidad_maxima_permitida());
    } else if(nombre_edificio() == STR_P_ELECTRICA){
        edificio = new Planta_Electrica(obtener_identificador_edificio(), costo_piedra(), costo_madera(), costo_metal(), cantidad_maxima_permitida());
    } else if(nombre_edificio() == STR_YACIMIENTO){
        edificio = new Yacimiento(obtener_identificador_edificio(), costo_piedra(), costo_madera(), costo_metal(), cantidad_maxima_permitida());
    } else if(nombre_edificio() == STR_ESCUELA){
        edificio = new Escuela(obtener_identificador_edificio(), costo_piedra(), costo_madera(), costo_metal(), cantidad_maxima_permitida());
    } else if(nombre_edificio() == STR_OBELISCO){
        edificio = new Obelisco(obtener_identificador_edificio(), costo_piedra(), costo_madera(), costo_metal(), cantidad_maxima_permitida());
    } else if(nombre_edificio() == STR_FABRICA){
        edificio = new Fabrica(obtener_identificador_edificio(), costo_piedra(), costo_madera(), costo_metal(), cantidad_maxima_permitida());
    } else {
        edificio = new Aserradero(obtener_identificador_edificio(), costo_piedra(), costo_madera(), costo_metal(), cantidad_maxima_permitida());
    }

    return edificio;
}


// ------------------------------------------------------------------------------------------------------------


string Parser::obtener_identificador_edificio(){
    string identificador;
    locale loc;

    identificador = toupper(this->entrada[0][POS_PRIMERA_LETRA],loc);

    return identificador;
}


// ------------------------------------------------------------------------------------------------------------


string Parser::nombre_edificio(){
    string nombre_edificio;
    int i = 0;

    if(!contiene_numeros(this -> entrada[i+1])) {
        for (; i < this -> cantidad_de_palabras - CANTIDAD_PARAMETROS_EDIFICIO - 1; ++i) {
            nombre_edificio.append(this->entrada[i]);
            nombre_edificio.append(ESPACIO);
        }

        nombre_edificio.append(this->entrada[i]);
        return nombre_edificio;
    } else return this -> entrada[i];

}


// ------------------------------------------------------------------------------------------------------------


int Parser::costo_piedra(){
    return stoi(entrada[cantidad_de_palabras - 4]);
}


// ------------------------------------------------------------------------------------------------------------


int Parser::costo_madera(){
    return stoi(entrada[cantidad_de_palabras - 3]);
}


// ------------------------------------------------------------------------------------------------------------


int Parser::costo_metal(){
    return stoi(entrada[cantidad_de_palabras - 2]);
}


// ------------------------------------------------------------------------------------------------------------


int Parser::cantidad_maxima_permitida(){
    return stoi(entrada[cantidad_de_palabras - 1]);
}


// ------------------------------------------------------------------------------------------------------------


Superficie* Parser::procesar_entrada_superficie(){

    Superficie* superficie = nullptr; 

    if (identificador_superficie() == identificador_lago){
        superficie = new Lago(identificador_superficie());
    } else if (identificador_superficie() == identificador_camino){
        superficie = new Camino(identificador_superficie());
    } else {
        superficie = new Terreno(identificador_superficie());
    }

    return superficie; 

}


// ------------------------------------------------------------------------------------------------------------

char Parser::identificador_superficie(){

    return entrada[0][0];

}

//                                     ### Para ubicaciones
// ------------------------------------------------------------------------------------------------------------
