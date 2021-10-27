#ifndef INVENTARIO_H
#define INVENARIO_H


#include <iostream>
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

    // pre: 
    // pos: 
    Inventario(Material** lista_materiales, int cantidad_materiales_actual, int cantidad_materiales_maxima); // Constructor con parametros

    // pre: 
    // pos: 
    Inventario(); // Constructor por default

    // pre: 
    // pos: 
    Inventario(ifstream& archivo); // Constructor a partir de un archivo

    // pre:
    // pos:
    ~Inventario(); // destructor

    // pre:
    // pos:
    void mostrar_inventario(); // agregar formato y status_t

};











#endif // INVENTARIO_H