#ifndef PARSER_H
#define PARSER_H

#include "material.h"
#include "edificio.h"
#include "piedra.h"
#include "madera.h"
#include "metal.h"
#include <string>
#include <fstream>

using namespace std;

const char DELIM_ESPACIO = ' ';

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
    ~Parser(){}; // IMPLEMENTARLO (si pidio memoria..)


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



};


#endif // PARSER_H