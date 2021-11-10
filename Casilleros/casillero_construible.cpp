#include <iostream>
#include "casillero_construible.h"



// ------------------------------------------------------------------------------------------------------------


Casillero_construible::Casillero_construible(Superficie* superficie, int coord_x, int coord_y, bool ocupado) 
        :Casillero(superficie, coord_x, coord_y, ocupado){}


// ------------------------------------------------------------------------------------------------------------

Casillero_construible::~Casillero_construible(){
    if(edificio_construido!=nullptr){
        delete edificio_construido;
        edificio_construido=nullptr;
    }
}

// ------------------------------------------------------------------------------------------------------------


void Casillero_construible::imprimir_casillero(){

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


void Casillero_construible::consultar_casillero(){
 
    cout << TAB << NEGRITA << FONDO_COLOR_ANARANJADO << "Soy un casillero construible y";
    if(!ocupado){
        cout << " estoy vacio" << FIN_DE_FORMATO << endl;
    } else {
        cout << " hay construido un/a " << edificio_construido -> obtener_tipo_edificio() << " en mi casillero" << FIN_DE_FORMATO << endl;
    }

}


// ------------------------------------------------------------------------------------------------------------


void Casillero_construible::construir_edificio(Edificio* edificio){

    this -> edificio_construido = edificio;
    this -> ocupado = true;

}


// ------------------------------------------------------------------------------------------------------------


void Casillero_construible::destruir_edificio(){

    delete edificio_construido;
    edificio_construido = nullptr;
    this -> ocupado = false;

}


// ------------------------------------------------------------------------------------------------------------


string Casillero_construible::obtener_nombre_objeto_de_casillero(){
    
    return edificio_construido -> obtener_tipo_edificio();

}


// ------------------------------------------------------------------------------------------------------------


char Casillero_construible::obtener_material_brindado_de_casillero(){
    
    return edificio_construido -> obtener_material_brindado();
}



// ------------------------------------------------------------------------------------------------------------


double Casillero_construible::obtener_cantidad_material_brindado_de_casillero(){

    return edificio_construido -> obtener_cantidad_material_brindado();

}