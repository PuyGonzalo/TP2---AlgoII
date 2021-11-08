#include <iostream>
#include "utilidades.h"

Estado_t construir_edificio_por_nombre(Andypolis& andypolis){
    string nombre;
    string coord_x, coord_y;
    Estado_t estado = OK;

    cout << TAB << MSJ_INGRESO_EDIFICIO_CONSTRUIR << endl;
    cout << ">";
    getline(cin, nombre);

    while(contiene_numeros(nombre)){
        
        imprimir_error(ERROR_ENTRADA_INVALIDA);
        cout << endl << "Ingrese una opcion valida: " << endl;
        cout << ">";
        getline(cin, nombre);

    }

    cout << "Ingrese las coordenadas donde quiere construir: " << endl;
    cout << "Coordenada x >";
    getline(cin, coord_x);

    while(contiene_letras(coord_x)){
        imprimir_error(ERROR_ENTRADA_INVALIDA);
        cout << endl << "Ingrese una opcion valida: " << endl;
        cout << ">";
        getline(cin, coord_x);
    }

    cout << endl << "Coordenada y >";
    getline(cin, coord_y);

    while(contiene_letras(coord_y)){
        imprimir_error(ERROR_ENTRADA_INVALIDA);
        cout << endl << "Ingrese una opcion valida: " << endl;
        cout << ">";
        getline(cin, coord_y);
    }
        
    estado = andypolis.construir_edificio(nombre, stoi(coord_x), stoi(coord_y));
    
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