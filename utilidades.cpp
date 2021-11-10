#include <iostream>
#include "utilidades.h"



// -------------------------------------------------------------------------------------------


Estado_t construir_edificio_por_nombre(Andypolis& andypolis){
    string nombre;
    string coord_x, coord_y;
    Estado_t estado = OK;

    cout << TAB << SUBRAYADO << MSJ_INGRESO_EDIFICIO_CONSTRUIR << FIN_DE_FORMATO << endl;
    cout << "> ";
    getline(cin, nombre);
    if(!andypolis.esta_edificio(nombre))
        return ERROR_EDIFICIO_INEXISTENTE;


    cout << endl << TAB << SUBRAYADO << "Ingrese las coordenadas donde quiere construir el edificio:" << FIN_DE_FORMATO << endl;
    cout << "Coordenada x > "; getline(cin, coord_x);
    cout << endl << "Coordenada y > "; getline(cin, coord_y);

    if(!es_un_numero(coord_x) || !es_un_numero(coord_y))
        return ERROR_PAR_COORDENADAS_INVALIDAS;
     
    estado = andypolis.construir_edificio_en_coord(nombre, stoi(coord_x), stoi(coord_y));
    
    return estado;

}


// -------------------------------------------------------------------------------------------


Estado_t consultar_coordenada(const Andypolis &andypolis){

    Estado_t estado = OK;
    string coord_x, coord_y;

    cout << TAB << SUBRAYADO << "Ingrese las coordenadas que quiere consultar:" << FIN_DE_FORMATO << endl;
    cout << "Coordenada x > "; getline(cin, coord_x);
    cout << endl << "Coordenada y > "; getline(cin, coord_y); cout << endl;


    if(!es_un_numero(coord_x) || !es_un_numero(coord_y))
        return ERROR_PAR_COORDENADAS_INVALIDAS;


    estado = andypolis.consultar_casillero_de_mapa(stoi(coord_x),stoi(coord_y));

    return estado;

}


// -------------------------------------------------------------------------------------------


Estado_t demoler_edificio_por_coordenada(Andypolis& andypolis){

    Estado_t estado = OK;
    string coord_x, coord_y;

    cout << TAB << SUBRAYADO << "Ingrese la coordenadas del edificio que quiere demoler:" << FIN_DE_FORMATO << endl;
    cout << "Coordenada x > "; getline(cin, coord_x);
    cout << endl << "Coordenada y > "; getline(cin, coord_y); cout << endl;
    


    if(!es_un_numero(coord_x) || !es_un_numero(coord_y))
        return ERROR_PAR_COORDENADAS_INVALIDAS;

    estado = andypolis.destruir_edificio_de_coord(stoi(coord_x), stoi(coord_y));

    return estado;

}


// -------------------------------------------------------------------------------------------


Estado_t lluvia_de_recursos(Andypolis& andypolis){
    
    Estado_t estado;
    int cantidad_lluvia_piedra, cantidad_lluvia_madera, cantidad_lluvia_metal;

    cantidad_lluvia_piedra = rand() % RAND_MAX_PIEDRA + 1;
    cantidad_lluvia_madera = rand() % RAND_MAX_MADERA;
    cantidad_lluvia_metal = rand() % RAND_MAX_METAL + 2;

    estado = andypolis.posicionar_lluvia_de_recursos( cantidad_lluvia_piedra, cantidad_lluvia_madera, cantidad_lluvia_metal);

    return estado;

}