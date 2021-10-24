#ifndef MATERIAL_H
#define MATERIAL_H

#include <sstream>
#include <fstream>
#include <string>
//#include "errors.h"

// esto va en constantes.h o tipos.h?
const int CANT_MATERIALES_CONSTRUCCION = 3;

const string STR_PIEDRA = "piedra";
const string STR_MADERA = "madera";
const string STR_METAL = "metal";
const string IDENTIF_PIEDRA = "S";
const string IDENTIF_MADERA = "W";
const string IDENTIF_METAL = "I";

const string materiales_de_construccion[CANT_MATERIALES_CONSTRUCCION][CANT_MATERIALES_CONSTRUCCION] = {
    {STR_PIEDRA, IDENTIF_PIEDRA},
    {STR_MADERA,IDENTIF_MADERA},
    {STR_METAL,IDENTIF_METAL}
};

using namespace std;

class Material{

private:
    // Atributos
    string nombre;
    string identificador; // string por si en un futuro necesito identifadores de 2 letras, por ejemplo
    double cantidad;

public:
    // Metodos

    // pre: 
    // pos: 
    Material(string nombre, string indentificador, double cantidad); // Constructor con parametros

    // pre: 
    // pos: 
    Material(); // Constructor por default

    // pre: 
    // pos: 
    Material(string linea); // Constructor con linea

    // pre: 
    // pos: 
    string obtener_nombre();

    // pre: 
    // pos: 
    string obtener_identificador();

    // pre: 
    // pos: 
    double obtener_cantidad();

    // pre: 
    // pos:
    void agregar_cantidad(double cantidad);

    // pre: 
    // pos:
    void restar_cantidad(double cantidad);

    // pre: 
    // pos: 
    string obtener_identificador_con_nombre(string nombre);

};


#endif // MATERIAL_H