#include <iostream>
#include "casillero_inaccesible.h"


// ------------------------------------------------------------------------------------------------------------


Casillero_Inaccesible::Casillero_Inaccesible(Superficie* superficie, int coord_x, int coord_y, bool ocupado) 
        :Casillero(superficie, coord_x, coord_y, ocupado){}


// ------------------------------------------------------------------------------------------------------------


void Casillero_Inaccesible::imprimir_casillero(){

    bool color_superficie_encontrada = false;
    int i = 0;

    while(!color_superficie_encontrada && i < CANT_SUPERFICIES){

        if(superficie -> obtener_color() == codigos_color_superficies[i][0]){
            color_superficie_encontrada = true;
            cout << codigos_color_superficies[i][1] << ' ' << FIN_DE_FORMATO; // deshardcodear espacio
        }

        ++i;
    }

}

// ------------------------------------------------------------------------------------------------------------


void Casillero_Inaccesible::consultar_casillero(){

    cout << "Soy un casillero inaccesible y obviamente estoy vacio" << endl;

}