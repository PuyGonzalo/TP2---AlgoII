#ifndef EDIFICIO_H
#define EDIFICIO_H

#include <string>
#include <sstream>
#include <cctype>
#include "errores.h"

using namespace std;

const int POS_PRIMERA_LETRA = 0;
const string STR_MINA = "mina";
const string STR_ASERRADERO = "aserradero";
const string STR_FABRICA = "fabrica";
const string STR_ESCUELA = "escuela";
const string STR_OBELISCO = "obelisco";
const string STR_YACIMIENTO = "yacimiento";
const string STR_P_ELECTRICA = "planta electrica";


class Edificio{

protected:
    // Atributos
    string identificador;
    int costo_piedra;
    int costo_madera;
    int costo_metal;
    int cantidad_construidos;
    int maximos_permitidos;

public:
    // Metodos

    // pre: 
    // pos: 
    Edificio();

    // pre: 
    // pos: 
    Edificio(string identificador, int consto_piedra, int costo_madera, int costo_metal, int maximos_permitidos);

    // pre: 
    // pos: 
    virtual ~Edificio(){};

    // pre: 
    // pos: 
    int obtener_costo_piedra();

    // pre: 
    // pos: 
    int obtener_costo_madera();

    // pre: 
    // pos: 
    int obtener_costo_metal();

    // pre: 
    // pos: 
    int obtener_maximos_permitidos();

    // pre: 
    // pos: 
    virtual string obtener_tipo_edificio() = 0;

    // pre: 
    // pos: 
    string obtener_identificador();

    // pre: 
    // pos: 
    void agregar_cantidad_construidos();

    // pre: 
    // pos: 
    void restar_cantidad_construidos();
};

bool contiene_numeros(string s); // esto va en UTILES o HERRAMIENTAS

#endif // EDIFICIO_H