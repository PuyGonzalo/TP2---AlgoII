#include <iostream>
#include "andypolis.h"


// ------------------------------------------------------------------------------------------------------------

// typedef Casillero* casilleroptr;
Andypolis::Andypolis(ifstream& archivo_edif, ifstream& archivo_ubics, ifstream& archivo_mapa, ifstream& archivo_mats) : 
mapa(archivo_mapa) , inventario(archivo_mats) {
    
    cargar_lista_edificios_construibles(archivo_edif);
    cargar_edificios(archivo_ubics);

}


// ------------------------------------------------------------------------------------------------------------


void Andypolis::cargar_lista_edificios_construibles(ifstream& archivo_edif){

    this -> lista_edificios_construibles = new Edificio*[MAX_EDIF_CONSTRUIBLES_INICIAL];
    this -> cantidad_edificios_construibles = 0;
    this -> cantidad_max_edificios_construibles = MAX_EDIF_CONSTRUIBLES_INICIAL; 
    Edificio** nueva_lista_edif_construibles;
    
    string linea_leida;
    int i = 0;

    while (getline(archivo_edif,linea_leida)){

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


void Andypolis::cargar_edificios(ifstream& archivo_ubics){

    string linea_leida;
    int coordenada_x, coordenada_y;

    /*if(archivo_ubics.peek() == ifstream::traits_type::eof())
        int pistola = 1; // estado_t st = ARCHIVO_VACIO
        */

    while(getline(archivo_ubics, linea_leida)){

        string aux;
        stringstream sstream;
        Parser parser(linea_leida);
        coordenada_x = parser.obtener_coordenada_x();
        coordenada_y = parser.obtener_coordenada_y();

        for(int i = 0; i < cantidad_edificios_construibles; ++i){
            if(lista_edificios_construibles[i] -> obtener_tipo_edificio() == parser.nombre_edificio_ubicaciones()){
                sstream << lista_edificios_construibles[i] -> obtener_tipo_edificio()
                << ESPACIO << to_string(lista_edificios_construibles[i] -> obtener_costo_piedra())
                << ESPACIO << to_string(lista_edificios_construibles[i] -> obtener_costo_madera())
                << ESPACIO << to_string(lista_edificios_construibles[i] -> obtener_costo_metal())
                << ESPACIO << to_string(lista_edificios_construibles[i] -> obtener_maximos_permitidos());
                aux = sstream.str();
                lista_edificios_construibles[i] -> agregar_cantidad_construidos();
            }
        }

        Parser parser_auxiliar(aux); //Ver si podemos poner mas lindo esto de la string auxiliar.
        mapa.construir_edificio_en_coord(parser_auxiliar.procesar_entrada_edificio(), coordenada_x , coordenada_y);

    }
}


// ------------------------------------------------------------------------------------------------------------


/*Edificio* Andypolis::buscar_por_nombre_edificio_en_lista(string nombre){



}*/


// ------------------------------------------------------------------------------------------------------------


void Andypolis::mostrar_edificios_construibles(){

    for(int i = 0 ; i < cantidad_edificios_construibles ; ++i){
        cout << lista_edificios_construibles[i] << endl;
    }

}


// ------------------------------------------------------------------------------------------------------------


void Andypolis::mostrar_edificios_construidos(){

    for(int i = 0 ; i < mapa.obtener_filas() ; ++i){

    }

}


// ------------------------------------------------------------------------------------------------------------


void Andypolis::mostrar_andypolis(){

    mapa.mostrar_mapa();
    
}


// ------------------------------------------------------------------------------------------------------------


Andypolis::~Andypolis(){

    for (int i = 0 ; i < cantidad_edificios_construibles ; ++i){
        delete lista_edificios_construibles[i];
        lista_edificios_construibles[i] = nullptr;
    }
    
    delete [] lista_edificios_construibles;
    lista_edificios_construibles = nullptr;

}