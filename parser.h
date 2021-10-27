#ifndef PARSER_H
#define PARSER_H

#include "material.h"
#include "edificio.h"
#include "Materiales/piedra.h"
#include "Materiales/madera.h"
#include "Materiales/metal.h"
#include <string>
#include <fstream>

using namespace std;

const string ESPACIO = " ";
const int ampliacion_max_palabras = 3;
const int cantidad_max_palabras_inicial = 1;

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

    // pre:
    // pos: 
    string obtener_identificador_con_nombre(string nombre);


    // ### Para edificios ###

    //PRE:
    //POST:
    Edificio* procesar_entrada_edificio();

    // pre:
    // pos:
    string nombre_edificio();

    // pre:
    // pos:
    double cantidad_piedra();

    // pre:
    // pos:
    double cantidad_madera();

    // pre:
    // pos:
    double cantidad_metal();

    // pre:
    // pos:
    double cantidad_maxima_permitida();





};


#endif // PARSER_H