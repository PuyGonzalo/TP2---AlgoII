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

    Inventario inventario(archivo_entrada_materiales);

    inventario.mostrar_inventario();


    Parser parser("planta electrica 100 300 400 5");
    Edificio* edificio = parser.procesar_entrada_edificio();
    cout << edificio -> obtener_tipo_edificio() << endl;
    cout << edificio -> obtener_costo_piedra() << endl;
    cout << edificio -> obtener_costo_madera() << endl;
    cout << edificio -> obtener_costo_metal() << endl;
    cout << edificio -> obtener_maximos_permitidos() << endl;

    delete edificio;

    Parser parserserdos("L");
    Superficie* superficie = parserserdos.procesar_entrada_superficie();
    cout << superficie->obtener_identificador() << endl;
    cout << superficie->obtener_color() << endl;

    delete superficie;



    // Cierro archivos de lectura
	archivo_entrada_materiales.close(); 
	archivo_entrada_edificios.close();

    return 0;
}