#ifndef MATERIAL_H
#define MATERIAL_H

#include <sstream>
#include <fstream>
#include <string>
#include "errores.h"

using namespace std;

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


class Material{

protected:
    // Atributos
    string identificador; // string por si en un futuro necesito identifadores de 2 letras, por ejemplo
    double cantidad;

public:
    // Metodos

    // pre: 
    // pos: 
    Material(double cantidad); // Constructor con parametros (solo cantidad.. esta bien?)

    // pre: 
    // pos: 
    Material(); // Constructor por default

    // pre:
    // pos:
    virtual ~Material(){}; // destructor?? deleting object of abstract class type ‘Material’ which has non-virtual destructor will cause undefined behavior

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
    virtual string obtener_tipo_material() = 0;

};


#endif // MATERIAL_H