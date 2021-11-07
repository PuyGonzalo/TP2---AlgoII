#include <iostream>
#include "utilidades.h"

Estado_t construir_edificio_por_nombre(Andypolis& andypolis){
    string nombre;
    Estado_t estado;

    cout << "Ingrese el nombre del edificio a construir: " << endl;
    cout << ">";

    getline(cin, nombre);

    while(contiene_numeros(nombre)){
        
        imprimir_error(ERROR_ENTRADA_INVALIDA);
        cout << endl << "Ingrese una opcion valida: " << endl;
        cout << ">";
        getline(cin, nombre);

    }

    if(!andypolis.esta_edificio(nombre))
        return ERROR_EDIFICIO_INEXISTENTE;
        
    



}

bool contiene_numeros(string s){
    const string CONT = "0123456789";
    if(s.find_first_of(CONT) != string::npos){
        return true;
    }else
        return false;
}