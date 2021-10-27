#include <iostream>
#include "parser.h"


// ------------------------------------------------------------------------------------------------------------


Parser::Parser(string linea) {

    this -> entrada = new string[cantidad_max_palabras_inicial];
    this -> cantidad_de_palabras = 0;
    this ->cantidad_de_palabras_max = cantidad_max_palabras_inicial;

    string palabra;
    string* nueva_entrada;
    int i = 0;

    stringstream sstream(linea);
    while (sstream.good()){

        if(cantidad_de_palabras < cantidad_de_palabras_max){
        sstream >> this -> entrada[i];
        cout << this -> entrada [i] << endl;
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


string Parser::obtener_identificador_con_nombre(string nombre){

    string aux_identif = "?"; // si no es de construccion, no tiene identificador.

    for (int i = 0 ; i < CANT_MATERIALES_CONSTRUCCION ; i++){
        if( nombre == materiales_de_construccion[i][0])
            aux_identif = materiales_de_construccion[i][1];
    }

    return aux_identif;
}


// ------------------------------------------------------------------------------------------------------------

