#include <iostream>
#include "parser.h"


// ------------------------------------------------------------------------------------------------------------


Parser::Parser(string linea) {

    this -> entrada = new string[cantidad_max_palabras_inicial];
    this -> cantidad_de_palabras = 0;
    this -> cantidad_de_palabras_max = cantidad_max_palabras_inicial;
    
    int i = 0;
    stringstream sstream(linea);

    while (sstream.good()){

        if(cantidad_de_palabras == cantidad_de_palabras_max){
            string* nueva_entrada = new string[cantidad_de_palabras_max+ampliacion_max_palabras];
            for(int j = 0; j < cantidad_de_palabras_max ; j++){
                nueva_entrada[j] = this -> entrada[j]; // reasigno punteros
            }
            delete [] this -> entrada;
            this -> entrada = nueva_entrada;
            cantidad_de_palabras_max += ampliacion_max_palabras;
        }

        sstream >> this -> entrada[i];
        cantidad_de_palabras++;
        ++i;
    }

}


// ------------------------------------------------------------------------------------------------------------


Parser::~Parser(){

    delete [] entrada;

}


// ----------------------------------------------------------------------------------------------------------//
//                                     +-----------------------+                                             //
//                                     | Para  materiales.txt  |                                             //
//                                     +-----------------------+                                             //
// ----------------------------------------------------------------------------------------------------------//


Material* Parser::procesar_entrada_material(){

    Material* material = nullptr;

    if (tipo_material() == STR_PIEDRA){
        material = new Piedra(cantidad_material());
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


// ----------------------------------------------------------------------------------------------------------//
//                                     +-----------------------+                                             //
//                                     |  Para edificios.txt   |                                             //
//                                     +-----------------------+                                             //
// ----------------------------------------------------------------------------------------------------------//


Datos_edificio* Parser::procesar_entrada_edificio(){

    Datos_edificio* nuevos_datos = new Datos_edificio;    

    nuevos_datos -> nombre = nombre_edificio();
    nuevos_datos -> costo_piedra = costo_piedra();
    nuevos_datos -> costo_madera = costo_madera();
    nuevos_datos -> costo_metal = costo_metal();
    nuevos_datos -> cantidad_construidos = 0;
    nuevos_datos -> maximos_permitidos = cantidad_maxima_permitida();
    // ya carga la lista como vacia cuadno se declara en la linea del ppio

    return nuevos_datos;

}



string Parser::obtener_identificador_edificio(){

    string identificador;
    locale loc; // mmmmmmm

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


double Parser::costo_piedra(){
    return stod(entrada[cantidad_de_palabras - 4]);
}


// ------------------------------------------------------------------------------------------------------------


double Parser::costo_madera(){
    return stod(entrada[cantidad_de_palabras - 3]);
}


// ------------------------------------------------------------------------------------------------------------


double Parser::costo_metal(){
    return stod(entrada[cantidad_de_palabras - 2]);
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



// ----------------------------------------------------------------------------------------------------------//
//                                     +-----------------------+                                             //
//                                     | Para ubicaciones .txt |                                             //
//                                     +-----------------------+                                             //
// ----------------------------------------------------------------------------------------------------------//


Edificio* Parser::procesar_entrada_ubicaciones(){
   
    Edificio* edificio = nullptr;

    if(nombre_edificio_ubicaciones() == STR_MINA){
        edificio = new Mina(obtener_identificador_edificio());
    } else if(nombre_edificio_ubicaciones() == STR_P_ELECTRICA){
        edificio = new Planta_Electrica(obtener_identificador_edificio());
    } else if(nombre_edificio_ubicaciones() == STR_YACIMIENTO){
        edificio = new Yacimiento(obtener_identificador_edificio());
    } else if(nombre_edificio_ubicaciones() == STR_ESCUELA){
        edificio = new Escuela(obtener_identificador_edificio());
    } else if(nombre_edificio_ubicaciones() == STR_OBELISCO){
        edificio = new Obelisco(obtener_identificador_edificio());
    } else if(nombre_edificio_ubicaciones() == STR_FABRICA){
        edificio = new Fabrica(obtener_identificador_edificio());
    } else {
        edificio = new Aserradero(obtener_identificador_edificio());
    }

    return edificio;
}


// ------------------------------------------------------------------------------------------------------------


string Parser::nombre_edificio_ubicaciones(){
    
    string nombre_edificio;
    int i = 0;

    for (; i < cantidad_de_palabras - CANTIDAD_PARAMETROS_UBICACIONES ; ++i){
        nombre_edificio.append(this -> entrada[i]);
        nombre_edificio.append(ESPACIO);
    }
    nombre_edificio.append(this->entrada[i]);
    
    return nombre_edificio;

}


// ------------------------------------------------------------------------------------------------------------


int Parser::obtener_coordenada_x(){

    string coordenada;
    int i = 1;

    while(isdigit(this -> entrada[cantidad_de_palabras - 2][i])){
        coordenada.append(1,this -> entrada[cantidad_de_palabras - 2][i]);
        ++i;
    }


    // Si i > 1 significa que es un numero de mas de un digito
    return i > 1 ? stoi(coordenada) : this -> entrada[cantidad_de_palabras - 2][1] - '0';

}


// ------------------------------------------------------------------------------------------------------------


int Parser::obtener_coordenada_y(){

    string coordenada;
    int i = 0;

    while(isdigit(this -> entrada[cantidad_de_palabras - 1][i])){
        coordenada.append(1, this -> entrada[cantidad_de_palabras - 1][i]);
        ++i;
    }

    // Si i > 0 significa que es un numero de mas de un digito
    return i > 0 ? stoi(coordenada) : this -> entrada[cantidad_de_palabras - 1][0] - '0';

}


// ------------------------------------------------------------------------------------------------------------

// ··············· METODOS PARA DEBUGGEAR -> BORRAR

int Parser::obtener_cantidad_palabras(){

    return this -> cantidad_de_palabras;

}

void Parser::mostrar_entrada(){

    for(int i = 0; i < cantidad_de_palabras; ++i ){
        cout << this -> entrada[i] << endl;
    }

}