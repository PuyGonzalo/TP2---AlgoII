#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <string>
#include <fstream>
#include <iomanip>
#include "material.h"
#include "parser.h"
#include "lista.h"

using namespace std;


class Inventario{

private:
    // Atributos
    Lista<Material*> lista_materiales;
    int cantidad_materiales;

public:
    // Metodos

    // pre: el archivo debe estar bien formado (por ejemplo: no vacio)
    // pos: Constructor a partir de un archivo a la entrada
    Inventario(ifstream& archivo);

    // pre: -
    // pos: CONSTRUCTOR un inventario vacio con una capacidad inicial para cargar materiales
    Inventario(); // Constructor por default


    // pre: -
    // pos: DESTRUCTOR del inventario (especificamente la lista de materiales dinamica)
    ~Inventario(); // destructor

    // pre: -
    // pos: devuelve la ubicacion de un material en la lista de materiales
    int ubicacion_material_en_lista(char identificador);

    // pre: -
    // pos: obtiene cuanta cantidad de piedra hay en el inventario
    double obtener_cantidad_de_piedra();

    // pre: -
    // pos: obtiene cuanta cantidad de madera hay en el inventario
    double obtener_cantidad_de_madera();

    // pre: -
    // pos: obtiene cuanta cantidad de metal hay en el inventario
    double obtener_cantidad_de_metal();

    // pre: deberia ya estar chequeado que la resta queda > 0 como cantidad final de c/material
    // pos: resta una cantidad de material de los 3 elementos de construccion
    void restar_cantidad_materiales_construccion(double costo_piedra, double costo_madera, double costo_metal);

    // pre: -
    // pos: resta una cantidad de material de los 3 elementos de construccion
    void sumar_cantidad_materiales_construccion(double costo_piedra, double costo_madera, double costo_metal);

    // pre: -
    // pos: se suma una cantidad especifica de un material especifico en funcion de su identificador
    void sumar_cantidad_material(char identificador, double cantidad);

    // pre: -
    // pos: mustra el inventario
    void mostrar_inventario();

    // pre: -
    // pos: guarda el inventario
    void guardar_inventario(ofstream& archivo_materiales);

};











#endif // INVENTARIO_H