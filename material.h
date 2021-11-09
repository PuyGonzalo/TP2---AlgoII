#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>
#include "errores.h"

using namespace std;


const int CANT_MATERIALES_CONSTRUCCION = 3;

const string STR_PIEDRA = "piedra";
const string STR_MADERA = "madera";
const string STR_METAL = "metal";
const char IDENTIF_PIEDRA = 'S';
const char IDENTIF_MADERA = 'W';
const char IDENTIF_METAL = 'I';


class Material{

protected:
    // Atributos
    char identificador;
    double cantidad;

public:
    // Metodos

    // pre: 
    // pos: 
    Material(double cantidad); // Constructor con parametros

    // pre: 
    // pos: 
    Material(); // Constructor por default

    // pre:
    // pos:
    virtual ~Material(){};

    // pre: 
    // pos: 
    char obtener_identificador();

    // pre: 
    // pos: 
    double obtener_cantidad();

    // pre: 
    // pos:
    void sumar_cantidad(double cantidad);

    // pre: 
    // pos:
    void restar_cantidad(double cantidad);

    // pre:
    // pos:
    virtual string obtener_tipo_material() = 0;

};


#endif // MATERIAL_H