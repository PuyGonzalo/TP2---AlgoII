#include <iostream>
#include "utilidades.h"



// -------------------------------------------------------------------------------------------


Estado_t construir_edificio_por_nombre(Andypolis& andypolis){
    string nombre;
    string coord_x, coord_y;
    Estado_t estado = OK;

    cout << TAB << MSJ_INGRESO_EDIFICIO_CONSTRUIR << endl;
    cout << "> ";
    getline(cin, nombre);
    //if(!andypolis.esta_edificio(nombre))
    //    return ERROR_EDIFICIO_INEXISTENTE; // para mi si pone cualquier edificio esta mal (y sacaria la verificacion de construir_edificio)


    while(contiene_numeros(nombre)){
        if(system(CLR_SCREEN));
        imprimir_error(ERROR_ENTRADA_INVALIDA);
        cout << endl << "Ingrese una edificio valido: " << endl;
        cout << "> ";
        getline(cin, nombre);

    }

    cout << "Ingrese las coordenadas donde quiere construir el edificio: " << endl;
    cout << "Coordenada x > ";
    getline(cin, coord_x);

    while(contiene_letras(coord_x)){
        if(system(CLR_SCREEN));
        imprimir_error(ERROR_ENTRADA_INVALIDA);
        cout << endl << "Ingrese una coordenada valida: " << endl;
        cout << "> ";
        getline(cin, coord_x);
    }

    cout << endl << "Coordenada y > ";
    getline(cin, coord_y);

    while(contiene_letras(coord_y)){
        if(system(CLR_SCREEN));
        imprimir_error(ERROR_ENTRADA_INVALIDA);
        cout << endl << "Ingrese una coordenada valida: " << endl;
        cout << "> ";
        getline(cin, coord_y);
    }
        
    estado = andypolis.construir_edificio(nombre, stoi(coord_x), stoi(coord_y));
    
    return estado;

}


// -------------------------------------------------------------------------------------------

Estado_t consultar_coordenada(const Andypolis &andypolis){

    Estado_t estado = OK;
    string coord_x, coord_y;

    cout << "Ingrese las coordenada X que quiere consultar: " << endl;
    getline(cin, coord_x);
    if(contiene_letras(coord_x)) // NO VALIDA \n
        return ERROR_COORDENADA_INVALIDA;
    
    cout << endl;

    cout << "Ingrese las coordenada Y que quiere consultar: " << endl;   
    getline(cin, coord_y);
    if(contiene_letras(coord_y))
        return ERROR_COORDENADA_INVALIDA;
        
    cout << endl;

    estado = andypolis.consultar_casillero_de_mapa(stoi(coord_x),stoi(coord_y));

    return estado;

}

// -------------------------------------------------------------------------------------------


void lluvia_de_recursos(Andypolis& andypolis){
    Estado_t estado;
    int cantidad_piedra, cantidad_madera, cantidad_metal;

    cantidad_piedra = rand() % RAND_MAX_PIEDRA + 1;
    cantidad_madera = rand() % RAND_MAX_MADERA;
    cantidad_metal = rand() % RAND_MAX_METAL + 2;

    estado = andypolis.posicionar_lluvia_de_recursos( (double) cantidad_piedra, (double) cantidad_madera, (double) cantidad_metal);

    if(estado != OK)
        cout << TAB << "Advertencia: No se pudieron colocar todos los materiales" << endl;

}