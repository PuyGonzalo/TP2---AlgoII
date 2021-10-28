#include <iostream>
#include "edificio.h"
#include "material.h"
#include "inventario.h"
#include "superficie.h"
#include "casillero.h"
#include "parser.h"
#include "errores.h"
#include "menu.h"

using namespace std;

const string PATH_ENTRADA_MATERIALES = "Archivos/materiales.txt";
const string PATH_ENTRADA_EDIFICIOS = "Archivos/edificios.txt";

int main (void){

    // Abro archivos de lectura
	ifstream archivo_entrada_materiales(PATH_ENTRADA_MATERIALES);
    ifstream archivo_entrada_edificios(PATH_ENTRADA_EDIFICIOS);

    /*Inventario inventario(archivo_entrada_materiales);

    inventario.mostrar_inventario();*/


    Parser parser("planta electrica 100 300 400 5");
    cout << parser.obtener_identificador_edificio() << endl;
    cout << parser.nombre_edificio() << endl; // planta electrica 100 imprime
    cout << parser.costo_piedra() << endl;
    cout << parser.costo_madera() << endl;
    cout << parser.costo_metal() << endl; // por la primera funcion (obtener nombre edif) todo está agarrando 1 a la derecha de lo que tiene que agarrar
  //  cout << parser.cantidad_maxima_permitida() << endl; ESTO LEAKEA 



    // Cierro archivos de lectura
	archivo_entrada_materiales.close(); 
	archivo_entrada_edificios.close();

    return 0;
}