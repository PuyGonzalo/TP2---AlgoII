#include <iostream>
#include "parser.h"

using namespace std;



// ------------------------------------------------------------------------------------------------------------


Parser::Parser(string linea) {

    this -> entrada = new string[1]; // deshardcodear ese numero
    string palabra;
    int i = 0;

    while(getline(linea, palabra , DELIM_ESPACIO)){
        if (cantidad_de_palabras < cantidad_de_palabras_max)
            this -> entrada[i] = palabra;
        else{

        }
    }

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

    string tipo_material; // buscar forma mas elegante de hacer esto (si o si)

    stringstream sstream(entrada);
    
    sstream >> tipo_material;

    return tipo_material;
}


// ------------------------------------------------------------------------------------------------------------


double Parser::cantidad_material(){

    string tipo_material;
    string cantidad_material; // buscar forma mas elegante de hacer esto (si o si)

    stringstream sstream(entrada);
    
    sstream >> tipo_material;
    sstream >> cantidad_material; // ESTO ES HORRIBLE

    return stod(cantidad_material);
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


