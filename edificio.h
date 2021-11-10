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

    // pre: 
    // pos: 
    Edificio();

    // pre: 
    // pos: 
    Edificio(string identificador);

    // pre: 
    // pos: 
    virtual ~Edificio(){};

    // pre: 
    // pos: 
    virtual string obtener_tipo_edificio() = 0;

    // pre:
    // pos:
    virtual char obtener_material_brindado() = 0;

    // pre:
    // pos:
    virtual double obtener_cantidad_material_brindado() = 0;

    // pre: 
    // pos: 
    string obtener_identificador();

};


#endif // EDIFICIO_H