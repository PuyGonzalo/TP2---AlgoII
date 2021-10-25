#include <iostream>
#include "inventario.h"


// ------------------------------------------------------------------------------------------------------------


Inventario::Inventario(Material** lista_materiales, int cantidad_materiales_actual, int cantidad_materiales_maxima){

    this -> lista_materiales = lista_materiales; // esta bien=
    this -> cantidad_materiales_actual = cantidad_materiales_actual;
    this -> cantidad_materiales_maxima = cantidad_materiales_maxima;

}


// ------------------------------------------------------------------------------------------------------------


Inventario::Inventario(){

    this -> lista_materiales = nullptr; // esta bien?
    this -> cantidad_materiales_actual = 0;
    this -> cantidad_materiales_maxima = 0;


}


// ------------------------------------------------------------------------------------------------------------


Inventario::Inventario(ifstream& archivo){
    
    string linea_leida;
    Material** nueva_lista_materiales;
    
 
    while(getline(archivo, linea_leida)){
        
        Material* material_leido = new Material;
        Material mat(linea_leida);
        *material_leido = mat;

        if(cantidad_materiales_actual < cantidad_materiales_maxima){
            lista_materiales[cantidad_materiales_actual] = material_leido;
            cantidad_materiales_actual++;
        } else{
            nueva_lista_materiales = new Material*[cantidad_materiales_maxima+ampliacion_cantidad_materiales];
            for(int i = 0; i < cantidad_materiales_maxima ; i++)
                nueva_lista_materiales[i] = lista_materiales[i]; // reasigno punteros
            nueva_lista_materiales[cantidad_materiales_maxima] = material_leido;

            delete [] lista_materiales;
            lista_materiales = nueva_lista_materiales;
            cantidad_materiales_actual++;
            cantidad_materiales_maxima += ampliacion_cantidad_materiales;
        }

    }

}


// ------------------------------------------------------------------------------------------------------------


Inventario::~Inventario(){
    
    for (int i = 0 ; i < cantidad_materiales_maxima ; i++){
    delete lista_materiales[i];
    lista_materiales[i] = nullptr;
    }
    
    delete [] lista_materiales;
    lista_materiales = nullptr;

}