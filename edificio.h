#ifndef EDIFICIO_H
#define EDIFICIO_H

#include <string>
#include <sstream>
#include "lista.h"
#include "errores.h"
#include "herramientas.h"

using namespace std;

const string STR_MINA = "mina";
const string STR_ASERRADERO = "aserradero";
const string STR_FABRICA = "fabrica";
const string STR_ESCUELA = "escuela";
const string STR_OBELISCO = "obelisco";
const string STR_YACIMIENTO = "yacimiento";
const string STR_P_ELECTRICA = "planta electrica";


struct Datos_edificio{
    string nombre;
    double costo_piedra;
    double costo_madera;
    double costo_metal;
    int cantidad_construidos;
    int maximos_permitidos;
    bool brinda_material;
    Lista<Coordenadas*> ubicaciones_construidos;
};

class Edificio{

protected:
    // Atributos
    string identificador;


public:
    // Metodos

    // pre: -
    // pos: CONSTRUCTOR edificio
    Edificio();

    // pre: identificador valido (entre los que hay en la consigna)
    // pos: CONSTRUCTOR con parametro
    Edificio(string identificador);

    // pre: -
    // pos: DESTRUCTOR de edificios
    virtual ~Edificio(){};

    // pre: -
    // pos: devuelve el tipo/nombre del edificio
    virtual string obtener_tipo_edificio() = 0;

    // pre: -
    // pos: obtiene (en caso de poder brindar materiales) el identificador del material que brinda el edificio
    virtual char obtener_material_brindado() = 0;

    // pre: -
    // pos: obtiene (en caso de poder brindar materiales) la cantidad de material que brinda el edificio
    virtual double obtener_cantidad_material_brindado() = 0;

    // pre: -
    // pos: devuelve el identificador del edificio
    string obtener_identificador();

};


#endif // EDIFICIO_H