#include <iostream>
#include "andypolis.h"


// ------------------------------------------------------------------------------------------------------------


Andypolis::Andypolis(ifstream& archivo_edif, ifstream& archivo_ubics, ifstream& archivo_mapa){

    cargar_lista_edificios_construibles(archivo_edif);

    cargar_mapa(archivo_mapa);
    //cargar_edificios(archivo_ubics);


    }


// ------------------------------------------------------------------------------------------------------------


void Andypolis::cargar_lista_edificios_construibles(ifstream& archivo_edif){

    this -> lista_edificios_construibles = new Edificio*[MAX_EDIF_CONSTRUIBLES_INICIAL];
    this -> cantidad_edificios_construibles = 0;
    this -> cantidad_max_edificios_construibles = MAX_EDIF_CONSTRUIBLES_INICIAL; 
    Edificio** nueva_lista_edif_construibles;
    
    string linea_leida;
    int i = 0;

    while (getline(archivo_edif,linea_leida))
    {
        Parser parser(linea_leida);

        if(cantidad_edificios_construibles == cantidad_max_edificios_construibles){
            nueva_lista_edif_construibles = new Edificio*[cantidad_edificios_construibles+AMPLIACION_EDIF_CONSTRUIBLES];
            for (int j = 0 ; j < cantidad_edificios_construibles ; ++j){
                nueva_lista_edif_construibles[j] = lista_edificios_construibles[j];
            }

            delete [] lista_edificios_construibles;
            lista_edificios_construibles = nueva_lista_edif_construibles;
            cantidad_max_edificios_construibles = cantidad_edificios_construibles + AMPLIACION_EDIF_CONSTRUIBLES;
        }

        this -> lista_edificios_construibles[i] = parser.procesar_entrada_edificio();
        ++cantidad_edificios_construibles;
        ++i;

    }
    

}


// ------------------------------------------------------------------------------------------------------------


void Andypolis::cargar_mapa(ifstream& archivo_mapa){

    string letra_leida;

    archivo_mapa >> letra_leida;
    this -> cantidad_filas = stoi(letra_leida);
    archivo_mapa >> letra_leida;
    this -> cantidad_columnas = stoi(letra_leida);

    mapa = new Casillero**[cantidad_filas];
    for (int i = 0 ; i < cantidad_filas ; ++i){
        mapa[i] = new Casillero*[cantidad_columnas];
    }

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
            delete superficie_leida;
        }
    }

}


// ------------------------------------------------------------------------------------------------------------


void Andypolis::cargar_edificios(ifstream& archivo_ubics){

    /*if(archivo_ubics.peek() == ifstream::traits_type::eof())
        int pistola = 1; // estado_t st = ARCHIVO_VACIO */

    


}


// ------------------------------------------------------------------------------------------------------------


/*Edificio* Andypolis::buscar_por_nombre_edificio_en_lista(string nombre){



}*/


// ------------------------------------------------------------------------------------------------------------


void Andypolis::mostrar_mapa(){

    for (int i = 0 ; i < cantidad_filas ; ++i){
        for (int j = 0 ; j < cantidad_columnas ; ++j){
            mapa[i][j] -> imprimir_casillero();
        }
        cout << endl;
    }


}


// ------------------------------------------------------------------------------------------------------------


Andypolis::~Andypolis(){

    for (int i = 0 ; i < cantidad_max_edificios_construibles ; ++i){
        delete lista_edificios_construibles[i];
        lista_edificios_construibles[i] = nullptr;
    }
    
    delete [] lista_edificios_construibles;
    lista_edificios_construibles = nullptr;


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