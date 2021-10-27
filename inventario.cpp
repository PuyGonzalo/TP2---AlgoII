#include <iostream>
#include "inventario.h"


// ------------------------------------------------------------------------------------------------------------


Inventario::Inventario(Material** lista_materiales, int cantidad_materiales_actual, int cantidad_materiales_maxima){

    this -> lista_materiales = lista_materiales; // esta bien?
    this -> cantidad_materiales_actual = cantidad_materiales_actual;
    this -> cantidad_materiales_maxima = cantidad_materiales_maxima;

}


// ------------------------------------------------------------------------------------------------------------


Inventario::Inventario(){

    this -> lista_materiales = new Material*[cantidad_maxima_inicial]; // esta bien esto en el construct sin param?
    this -> cantidad_materiales_actual = 0;
    this -> cantidad_materiales_maxima = cantidad_maxima_inicial;


}


// ------------------------------------------------------------------------------------------------------------


Inventario::Inventario(ifstream& archivo){
    
    string linea_leida;
    Material** nueva_lista_materiales;

    this -> lista_materiales = new Material*[cantidad_maxima_inicial]; // mmmmm
    this -> cantidad_materiales_actual = 0;
    this -> cantidad_materiales_maxima = cantidad_maxima_inicial; 
 
    while(getline(archivo, linea_leida)){
        
        Parser parser(linea_leida);
        Material* material_leido = parser.procesar_entrada_material();

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


// ------------------------------------------------------------------------------------------------------------


void Inventario::mostrar_inventario(){
    for(int i = 0 ; i < cantidad_materiales_actual ; i++)
        cout << "> " << lista_materiales[i] -> obtener_tipo_material() << ": " << lista_materiales[i] -> obtener_cantidad() << endl;

}

