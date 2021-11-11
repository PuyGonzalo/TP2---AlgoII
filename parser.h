#ifndef PARSER_H
#define PARSER_H

#include "material.h"
#include "Materiales/piedra.h"
#include "Materiales/madera.h"
#include "Materiales/metal.h"
#include "edificio.h"
#include "Edificios/mina.h"
#include "Edificios/aserradero.h"
#include "Edificios/escuela.h"
#include "Edificios/fabrica.h"
#include "Edificios/obelisco.h"
#include "Edificios/planta_electrica.h"
#include "Edificios/yacimiento.h"
#include "superficie.h"
#include "Superficies/camino.h"
#include "Superficies/terreno.h"
#include "Superficies/lago.h"
#include "herramientas.h"

#include <string>
#include <cstring>
#include <fstream>
#include <cctype>

using namespace std;

const string ESPACIO = " ";
const int ampliacion_max_palabras = 3;
const int cantidad_max_palabras_inicial = 1;
const int CANTIDAD_PARAMETROS_EDIFICIO = 4;
const int CANTIDAD_PARAMETROS_UBICACIONES = 3;
const int POS_PRIMERA_LETRA = 0;


class Parser {
private:
    // Atributos
    string* entrada;
    int cantidad_de_palabras;
    int cantidad_de_palabras_max;

public:
    // Metodos

    // pre: linea debe ser un string cuyo delimitador de campos sea un espacio
    // pos: Constructor de parser a partir de un string
    Parser(string linea);

    // pre: -
    // pos: Destructor de parser
    ~Parser();


    // ### Para materiales ###

    // pre: Parser tiene que estar instanciado con una linea del tipo "materiales.txt"
    // pos: Pide memoria para un material segun la linea que haya leido y devuelve un puntero a Material
    Material* procesar_entrada_material();

    // pre: Parser tiene que estar instanciado con una linea del tipo "materiales.txt"
    // pos: Devuelve el tipo de material
    string tipo_material();

    // pre: Parser tiene que estar instanciado con una linea del tipo "materiales.txt"
    // pos: Devuelve la cantidad de material
    double cantidad_material();

    // ### Para edificios ###

    // pre: Parser tiene que estar instanciado con una linea del tipo "edificios.txt"
    // pos: Crea una estructura del tipo Datos_edificio
    Datos_edificio* procesar_entrada_edificio();

    // pre: Parser tiene que estar instanciado con una linea del tipo "edificios.txt"
    // pos: Devuelve la primer letra del nombre en mayuscula (identificador)
    string obtener_identificador_edificio();

    // pre: Parser tiene que estar instanciado con una linea del tipo "edificios.txt"
    // pos: Devuelve el nombre del edificio
    string nombre_edificio();

    // pre: Parser tiene que estar instanciado con una linea del tipo "edificios.txt"
    // pos: Devuelve el costo de piedra
    double costo_piedra();

    // pre: Parser tiene que estar instanciado con una linea del tipo "edificios.txt"
    // pos: Devuelve el costo de madera
    double costo_madera();

    // pre: Parser tiene que estar instanciado con una linea del tipo "edificios.txt"
    // pos: Devuelve el costo de metal
    double costo_metal();

    // pre: Parser tiene que estar instanciado con una linea del tipo "edificios.txt"
    // pos: Devuelve la cantidad maxima permitida para construir
    int cantidad_maxima_permitida();


    // ### Para superficies ###

    // pre: Parser tiene que estar instanciado con una linea del tipo "mapa.txt"
    // pos: Pide memoria para un Edificio segun la linea que haya leido y devuelve un puntero a Edificio
    Edificio* procesar_entrada_ubicaciones();

    // pre: Parser tiene que estar instanciado con una linea del tipo "mapa.txt"
    // pos: Pide memoria para una Superficie segun la linea que haya leido y devuelve un puntero a Superficie
    Superficie* procesar_entrada_superficie();

    // pre: Parser tiene que estar instanciado con una linea del tipo "mapa.txt"
    // pos: Devuelve el identificador de la superficie
    char identificador_superficie();

    // pre: Parser tiene que estar instanciado con una linea del tipo "mapa.txt"
    // pos: Devuelve el nombre del edificio
    string nombre_edificio_ubicaciones();

    // pre: Parser tiene que estar instanciado con una linea del tipo "mapa.txt"
    // pos: Obtiene la coordenada X
    int obtener_coordenada_x();

    // pre: Parser tiene que estar instanciado con una linea del tipo "mapa.txt"
    // pos: Obtiene la coordenada Y
    int obtener_coordenada_y();





};


#endif // PARSER_H