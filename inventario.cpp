#include <iostream>
#include "inventario.h"


// ------------------------------------------------------------------------------------------------------------


Inventario::Inventario(){

    this -> lista_materiales = new Material*[cantidad_maxima_inicial];
    this -> cantidad_materiales_actual = 0;
    this -> cantidad_materiales_maxima = cantidad_maxima_inicial;


}


// ------------------------------------------------------------------------------------------------------------


Inventario::Inventario(ifstream& archivo){
    
    string linea_leida;
    Material** nueva_lista_materiales;

    this -> lista_materiales = new Material*[cantidad_maxima_inicial]; // esta bien esto?
    this -> cantidad_materiales_actual = 0;
    this -> cantidad_materiales_maxima = cantidad_maxima_inicial; 
 
    while(getline(archivo, linea_leida)){
        
        Parser parser(linea_leida);
        Material* material_leido = parser.procesar_entrada_material();

        if(cantidad_materiales_actual < cantidad_materiales_maxima){ // CAMBIAR IF ELSE POR IF (act == max) -> REALLOC
            lista_materiales[cantidad_materiales_actual] = material_leido;
            cantidad_materiales_actual++;
        } else{
            nueva_lista_materiales = new Material*[cantidad_materiales_maxima+ampliacion_cantidad_materiales];
            for(int i = 0; i < cantidad_materiales_maxima ; ++i)
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
    
    for (int i = 0 ; i < cantidad_materiales_maxima ; ++i){
        delete lista_materiales[i];
        lista_materiales[i] = nullptr;
    }
    
    delete [] lista_materiales;
    lista_materiales = nullptr;

}


// ------------------------------------------------------------------------------------------------------------


void Inventario::mostrar_inventario(){
    for(int i = 0 ; i < cantidad_materiales_actual ; ++i)
        cout << "> " << lista_materiales[i] -> obtener_tipo_material() << ": " << lista_materiales[i] -> obtener_cantidad() << endl;

}

// ------------------------------------------------------------------------------------------------------------

int Inventario::ubicacion_material_en_lista(char identificador){
    int i = 0;
    int ubicacion = -1;
    bool material_encontrado = false;

    while(i < cantidad_materiales_actual && !material_encontrado ){
        if(lista_materiales[i] -> obtener_identificador() == identificador){
            ubicacion = i;
            material_encontrado = true;
        }
        ++i;
    }

    return ubicacion;
}

// ------------------------------------------------------------------------------------------------------------

double Inventario::obtener_cantidad_de_piedra(){
    int ubicacion_material;

    ubicacion_material = ubicacion_material_en_lista(IDENTIF_PIEDRA);

    return lista_materiales[ubicacion_material]->obtener_cantidad();
}

// ------------------------------------------------------------------------------------------------------------

double Inventario::obtener_cantidad_de_madera(){
    int ubicacion_material;

    ubicacion_material = ubicacion_material_en_lista(IDENTIF_MADERA);

    return lista_materiales[ubicacion_material]->obtener_cantidad();
}

// ------------------------------------------------------------------------------------------------------------

double Inventario::obtener_cantidad_de_metal(){
    int ubicacion_material;

    ubicacion_material = ubicacion_material_en_lista(IDENTIF_METAL);

    return lista_materiales[ubicacion_material]->obtener_cantidad();
}

void Inventario::restar_cantidad_materiales_construccion(double costo_piedra, double costo_madera, double costo_metal){
    int ubicacion_piedra, ubicacion_madera, ubicacion_metal;

    ubicacion_piedra = ubicacion_material_en_lista(IDENTIF_PIEDRA);
    ubicacion_madera = ubicacion_material_en_lista(IDENTIF_MADERA);
    ubicacion_metal = ubicacion_material_en_lista(IDENTIF_METAL);

    lista_materiales[ubicacion_piedra]->restar_cantidad(costo_piedra);
    lista_materiales[ubicacion_madera]->restar_cantidad(costo_madera);
    lista_materiales[ubicacion_metal]->restar_cantidad(costo_metal);

}