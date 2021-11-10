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

    // pre: -
    // pos: CONSTRUCTOR con parametros
    Material(double cantidad);

    // pre: -
    // pos: CONSTRUCTOR por default
    Material(); 

    // pre: -
    // pos: DESTRUCTOR de material
    virtual ~Material(){};

    // pre: -
    // pos: obtiene el identificador del material
    char obtener_identificador();

    // pre: -
    // pos: obtiene la cantidad de un material
    double obtener_cantidad();

    // pre: -
    // pos: suma una cantidad de material
    void sumar_cantidad(double cantidad);

    // pre: no se deberia restar mas del valor actual de material que hay (validar antes de usar)
    // pos: resta una cantidad de material
    void restar_cantidad(double cantidad);

    // pre: -
    // pos: obtiene que tipo/nombre de material es
    virtual string obtener_tipo_material() = 0;

};


#endif // MATERIAL_H