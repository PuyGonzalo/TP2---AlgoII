#include <iostream>
#include "edificio.h"
#include "errores.h"
#include "material.h"
#include "inventario.h"
#include "menu.h"

using namespace std;

const string PATH_ENTRADA_MATERIALES = "Archivos/materiales.txt";
const string PATH_ENTRADA_EDIFICIOS = "Archivos/edificios.txt";

int main (void){

    // Abro archivos de lectura
	ifstream archivo_entrada_materiales(PATH_ENTRADA_MATERIALES);
    ifstream archivo_entrada_edificios(PATH_ENTRADA_EDIFICIOS);

    Inventario inventario(archivo_entrada_materiales);

    inventario.mostrar_inventario();

    cout << "hola mundo" << endl;


    return 0;
}