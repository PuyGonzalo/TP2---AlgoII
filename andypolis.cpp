#include <iostream>
#include "andypolis.h"


// ------------------------------------------------------------------------------------------------------------

// typedef Casillero* casilleroptr;
Andypolis::Andypolis(ifstream& archivo_edif, ifstream& archivo_ubics, ifstream& archivo_mapa, ifstream& archivo_mats) : 
mapa(archivo_mapa) , inventario(archivo_mats) {
    
    cargar_catalogo(archivo_edif);
    cargar_edificios(archivo_ubics);

}


// ------------------------------------------------------------------------------------------------------------


void Andypolis::cargar_catalogo(ifstream& archivo_edif){

    this -> catalogo = new Datos_edificio*[MAX_EDIF_CONSTRUIBLES_INICIAL];
    this -> cantidad_edificios_catalogo = 0;
    this -> cantidad_max_edificios_catalogo = MAX_EDIF_CONSTRUIBLES_INICIAL; 
    Datos_edificio** nuevo_catalogo;
    
    string linea_leida;
    int i = 0;

    while (getline(archivo_edif,linea_leida)){

        Parser parser(linea_leida);

        if(cantidad_edificios_catalogo == cantidad_max_edificios_catalogo){
            nuevo_catalogo = new Datos_edificio*[cantidad_edificios_catalogo+AMPLIACION_EDIF_CONSTRUIBLES];
            for (int j = 0 ; j < cantidad_edificios_catalogo ; ++j){
                nuevo_catalogo[j] = catalogo[j];
            }

            delete [] catalogo;
            catalogo = nuevo_catalogo;
            cantidad_max_edificios_catalogo = cantidad_edificios_catalogo + AMPLIACION_EDIF_CONSTRUIBLES;
        }

        this -> catalogo[i] = parser.procesar_entrada_edificio();
        ++cantidad_edificios_catalogo;
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

        Parser parser(linea_leida);
        coordenada_x = parser.obtener_coordenada_x();
        coordenada_y = parser.obtener_coordenada_y();
        mapa.construir_edificio_en_coord(parser.procesar_entrada_ubicaciones(), coordenada_x, coordenada_y);
        cargar_coordenadas_en_catalogo(parser.nombre_edificio_ubicaciones(), coordenada_x, coordenada_y);

    }



}


// ------------------------------------------------------------------------------------------------------------


/*Edificio* Andypolis::buscar_por_nombre_edificio_en_lista(string nombre){



}*/


// ------------------------------------------------------------------------------------------------------------


void Andypolis::mostrar_catalogo(){

    for(int i = 0 ; i < cantidad_edificios_catalogo ; ++i){
        cout << catalogo[i]->nombre << endl;
        cout << catalogo[i]-> costo_piedra<< endl;
        cout << catalogo[i]-> costo_madera << endl;
        cout << catalogo[i]-> costo_metal << endl;
        cout << catalogo[i]-> cantidad_construidos << endl;
        cout << catalogo[i]-> maximos_permitidos << endl;
        cout << catalogo[i]-> ubicaciones_construidos << endl;
    }

}


// ------------------------------------------------------------------------------------------------------------


void Andypolis::mostrar_andypolis(){

    mapa.mostrar_mapa();
    
}


// ------------------------------------------------------------------------------------------------------------


void Andypolis::consultar_casillero_de_mapa(int coord_x, int coord_y){

    mapa.consultar_casillero(coord_x,coord_y);

}


// ------------------------------------------------------------------------------------------------------------


void Andypolis::mostrar_inventario(){

    inventario.mostrar_inventario();

}

// ------------------------------------------------------------------------------------------------------------


void Andypolis::mostrar_edificios_en_andypolis(){
    
    mapa.mostrar_edificios_construidos();

}


// ------------------------------------------------------------------------------------------------------------


void Andypolis::cargar_coordenadas_en_catalogo(string nombre_edificio, int coord_x, int coord_y){

    string coordenada;
    bool edificio_detectado = false;
    int i = 0;

    while(!edificio_detectado){
        if(nombre_edificio == catalogo[i] -> nombre){
            stringstream ss;
            ss << "(" << to_string(coord_x) << ", " << to_string(coord_y) << ")" << ESPACIO; // DESHARDCODEAR
            coordenada = ss.str();
            catalogo[i] -> ubicaciones_construidos.append(coordenada);
            ++catalogo[i] -> cantidad_construidos;
            edificio_detectado = true;
        } 
        ++i;
    }

}


// ------------------------------------------------------------------------------------------------------------


void Andypolis::listar_edificios_construidos(){

    if(!cantidad_edificios_catalogo){
        cout << "No hay edificios, rey" << endl;
    } else{
        for(int i = 0 ; i < cantidad_edificios_catalogo ; ++i){
            if(catalogo[i] -> cantidad_construidos != 0){
            cout << catalogo[i] -> nombre << ESPACIO << "(Totales = " << catalogo[i]->cantidad_construidos << ")" << endl;
            cout << "Construidos en: " << catalogo[i] -> ubicaciones_construidos << endl << endl;
            }
        }
    }

}


// ------------------------------------------------------------------------------------------------------------


Andypolis::~Andypolis(){

    for (int i = 0 ; i < cantidad_edificios_catalogo ; ++i){
        delete catalogo[i];
        catalogo[i] = nullptr;
    }
    
    delete [] catalogo;
    catalogo = nullptr;

}