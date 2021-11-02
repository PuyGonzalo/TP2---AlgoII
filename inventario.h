#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <string>
#include <fstream>
#include "material.h"
#include "parser.h"

using namespace std;

const int ampliacion_cantidad_materiales = 2;
const int cantidad_maxima_inicial = 1;

class Inventario{

private:
    // Atributos
    Material** lista_materiales;
    int cantidad_materiales_actual;
    int cantidad_materiales_maxima;

public:
    // Metodos

    // pre: el archivo debe estar bien formado (por ejemplo: no vacio)
    // pos: Constructor a partir de un archivo a la entrada
    Inventario(ifstream& archivo);

    // pre: -
    // pos: construye un inventario vacio con una capacidad inicial para cargar materiales
    Inventario(); // Constructor por default


    // pre: -
    // pos: destruye el inventario (especificamente la lista de materiales dinamica)
    ~Inventario(); // destructor

    // pre:
    // pos:
    void mostrar_inventario(); // agregar formato y status_t

};











#endif // INVENTARIO_H