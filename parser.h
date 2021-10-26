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

class Parser {
private:
    string entrada;
public:
    Parser(string linea);
    ~Parser(){};
    Material* procesar_entrada();
    string tipo_material();
    double cantidad_material();
    string obtener_identificador_con_nombre(string nombre);
};


#endif // PARSER_H
