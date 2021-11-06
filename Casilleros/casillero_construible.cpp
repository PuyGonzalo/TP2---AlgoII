#include <iostream>
#include "casillero_construible.h"



// ------------------------------------------------------------------------------------------------------------


Casillero_Construible::Casillero_Construible(Superficie* superficie, int coord_x, int coord_y, bool ocupado) : Casillero(superficie, coord_x, coord_y, ocupado){

    this -> edificio_construido = nullptr; // hasta no leer ubicaciones.txt no tiene sentido construir el casillero con el edificio (ni se cual poner)

}


// ------------------------------------------------------------------------------------------------------------

Casillero_Construible::~Casillero_Construible(){
    if(edificio_construido!=nullptr){
        delete edificio_construido;
        edificio_construido=nullptr;
    }
}

// ------------------------------------------------------------------------------------------------------------


void Casillero_Construible::imprimir_casillero(){

    bool color_superficie_encontrada = false;
    int i = 0;

    while(!color_superficie_encontrada && i < CANT_SUPERFICIES){

        if(superficie -> obtener_color() == codigos_color_superficies[i][0]){
            color_superficie_encontrada = true;
            if(ocupado)
                cout << codigos_color_superficies[i][1] << edificio_construido -> obtener_identificador() << FIN_DE_FORMATO;
            else
                cout << codigos_color_superficies[i][1] << ' ' << FIN_DE_FORMATO;
        }

        ++i;
    }

}


// ------------------------------------------------------------------------------------------------------------


void Casillero_Construible::consultar_casillero(){
 
    cout << "Soy un casillero construible y";
    if(!ocupado){
        cout << " estoy vacio" << endl;
    } else {
        cout << " hay construido un/a " << edificio_construido -> obtener_tipo_edificio() << " en mi casillero" << endl;
    }

}


// ------------------------------------------------------------------------------------------------------------


void Casillero_Construible::construir_edificio_en_casillero(Edificio* edificio){

    this -> edificio_construido = edificio;
    this -> ocupado = true;

}