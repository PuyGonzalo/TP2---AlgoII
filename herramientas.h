#ifndef HERRAMIENTAS_H
#define HERRAMIENTAS_H

#include <string>

using namespace std;

struct Coordenadas{
    int coordenada_x;
    int coordenada_y;
};

// pre: -
// pos: devuelve true si la string tiene algun numero
bool contiene_numeros(string s);

// pre: -
// pos: devuelve true si la string contiene alguna letra
bool contiene_letras(string s);

// pre: -
// pos: devuelve true si es un numero, false de lo contrario (valida todos los casos posibles)
bool es_un_numero(string str);




#endif // HERRAMIENTAS_H