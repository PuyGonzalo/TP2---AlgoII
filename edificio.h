#ifndef EDIFICIO_H
#define EDIFICIO_H

#include <string>
#include <sstream>
#include <cctype>

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
    string identificador;
    int costo_piedra;
    int costo_madera;
    int costo_metal;
    int cantidad_construidos;
    int maximos_permitidos;

public:

    //PRE:
    //POST:
    Edificio();

    //PRE:
    //POST:
    Edificio(string identificador, int consto_piedra, int costo_madera, int costo_metal, int maximos_permitidos);

    //PRE:
    //POST:
    virtual ~Edificio(){};

    //PRE:
    //POST:
    int obtener_costo_piedra();

    //PRE:
    //POST:
    int obtener_costo_madera();

    //PRE:
    //POST:
    int obtener_costo_metal();

    //PRE:
    //POST:
    int obtener_maximos_permitidos();

    //PRE:
    //POST:
    virtual string obtener_tipo_edificio() = 0;

    //PRE:
    //POST:
    string obtener_identificador();

    //PRE:
    //POST:
    void agregar_cantidad_construidos();

    //PRE:
    //POST:
    void restar_cantidad_construidos();
};

bool contiene_numeros(string s);

#endif // EDFICIO_H