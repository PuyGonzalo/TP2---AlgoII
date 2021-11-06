#include <iostream>
#include "mapa.h"


// ------------------------------------------------------------------------------------------------------------


Mapa::Mapa(ifstream& archivo_mapa){

    string letra_leida;

    archivo_mapa >> letra_leida;
    this -> cantidad_filas = stoi(letra_leida);
    archivo_mapa >> letra_leida;
    this -> cantidad_columnas = stoi(letra_leida);

    // Creo el mapa
    mapa = new Casillero**[cantidad_filas];
    for (int i = 0 ; i < cantidad_filas ; ++i){
        mapa[i] = new Casillero*[cantidad_columnas];
    }

    // Utilizo el polimorfismo para crear el casillero y superficie correspondiente
    for(int i = 0 ; i < cantidad_filas ; ++i){
        for (int j = 0 ; j < cantidad_columnas; ++j){
            
            archivo_mapa >> letra_leida;
            Parser parser(letra_leida);
            Superficie* superficie_leida = parser.procesar_entrada_superficie();
            if(superficie_leida -> es_accesible()){
                if ( superficie_leida -> es_construible()){
                    mapa[i][j] = new Casillero_Construible(superficie_leida, i, j, false);
                } else {
                    mapa[i][j] = new Casillero_Transitable(superficie_leida, i, j, false);
                }
            } else {
                mapa[i][j] = new Casillero_Inaccesible(superficie_leida, i, j, false);
            }

        }
    }

}


// ------------------------------------------------------------------------------------------------------------


int Mapa::obtener_filas(){

    return cantidad_filas;

}


// ------------------------------------------------------------------------------------------------------------


int Mapa::obtener_columnas(){

    return cantidad_columnas;

}


// ------------------------------------------------------------------------------------------------------------


void Mapa::mostrar_mapa(){

    for (int i = 0 ; i < cantidad_filas ; ++i){
        for (int j = 0 ; j < cantidad_columnas ; ++j){
            mapa[i][j] -> imprimir_casillero();
        }
        cout << endl;
    }

}


// ------------------------------------------------------------------------------------------------------------


bool Mapa::se_puede_transitar(int coord_x, int coord_y){

    return mapa[coord_x][coord_y] -> es_casillero_transitable();

}


// ------------------------------------------------------------------------------------------------------------


bool Mapa::se_puede_construir(int coord_x, int coord_y){

    return mapa[coord_x][coord_y] -> es_casillero_construible();

}


// ------------------------------------------------------------------------------------------------------------


bool Mapa::se_puede_acceder(int coord_x, int coord_y){

    return mapa[coord_x][coord_y] -> es_casillero_accesible();

}

// ------------------------------------------------------------------------------------------------------------


bool Mapa::casillero_esta_ocupado(int coord_x, int coord_y){

    return mapa[coord_x][coord_y] -> esta_ocupado();

}


// ------------------------------------------------------------------------------------------------------------


void Mapa::construir_edificio_en_coord(Edificio* edificio, int coord_x, int coord_y){

    if(mapa[coord_x][coord_y] -> es_casillero_construible() && !(casillero_esta_ocupado(coord_x,coord_y)) ){
        mapa[coord_x][coord_y] -> construir_edificio_en_casillero(edificio);
    }

}


// ------------------------------------------------------------------------------------------------------------


Mapa::~Mapa(){

    for(int i = 0 ; i < cantidad_filas ; ++i){
        for(int j = 0 ; j < cantidad_columnas ; ++j){
            delete mapa[i][j];
            mapa[i][j] = nullptr;
        }

        delete [] mapa[i];
        mapa[i] = nullptr;
    }

    delete [] mapa;
    mapa = nullptr;

}