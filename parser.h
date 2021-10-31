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
/*#include "casillero.h"
#include "Casilleros/casillero_construible.h"
#include "Casilleros/casillero_inaccesible.h"
#include "Casilleros/casillero_transitable.h" creo que no hace faltan estos */
#include "superficie.h"
#include "Superficies/camino.h"
#include "Superficies/terreno.h"
#include "Superficies/lago.h"

#include <string>
#include <cstring>
#include <fstream>
#include <cctype>

using namespace std;

const string ESPACIO = " ";
const int ampliacion_max_palabras = 3;
const int cantidad_max_palabras_inicial = 1;
const int CANTIDAD_PARAMETROS_EDIFICIO = 4;
const int POS_PRIMERA_LETRA = 0;


class Parser {
private:
    // Atributos
    string* entrada;
    int cantidad_de_palabras;
    int cantidad_de_palabras_max;

public:
    // Metodos

    // pre:
    // pos:
    Parser(string linea);

    // pre:
    // pos:
    ~Parser();


    // ### Para materiales ###

    // pre:
    // pos: 
    Material* procesar_entrada_material();

    // pre:
    // pos: 
    string tipo_material();

    // pre:
    // pos: 
    double cantidad_material();

    // ### Para edificios ###

    // pre:
    // pos:
    Edificio* procesar_entrada_edificio();

    //PRE:
    //POST:
    string obtener_identificador_edificio();

    // pre:
    // pos:
    string nombre_edificio();

    // pre:
    // pos:
    int costo_piedra();

    // pre:
    // pos:
    int costo_madera();

    // pre:
    // pos:
    int costo_metal();

    // pre:
    // pos:
    int cantidad_maxima_permitida();


    // ### Para superficies ###

    // pre: 
    // pos: 
    Superficie* procesar_entrada_superficie();

    // pre:
    // pos:
    char identificador_superficie();




};


#endif // PARSER_H