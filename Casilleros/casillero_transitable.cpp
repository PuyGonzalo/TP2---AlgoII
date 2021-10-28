#include <iostream>
#include "casillero_transitable.h"



Casillero_Transitable::Casillero_Transitable(Superficie* superficie, int coord_x, int coord_y, bool ocupado) : Casillero(superficie, coord_x, coord_y, ocupado){}

void Casillero_Transitable::imprimir_casillero(){

    bool color_superficie_encontrada = false;
    int i = 0;

    while(!color_superficie_encontrada && i < CANT_SUPERFICIES){

        if(superficie -> obtener_color() == codigos_color_superficies[i][0]){
            color_superficie_encontrada = true;
            cout << codigos_color_superficies[i][1] << material_ocupado -> obtener_identificador() << FIN_DE_FORMATO;
        }

        ++i;
    }

}


void Casillero_Transitable::consultar_casillero(){

    cout << "Soy un casillero transitable y";
    if(ocupado){
        cout << "estoy vacio" << endl;
    } else {
        cout << "tengo " << material_ocupado -> obtener_tipo_material() << " en mi casillero" << endl;
    }

}