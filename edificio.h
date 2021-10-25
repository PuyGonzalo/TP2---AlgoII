#ifndef EDIFICIO_H
#define EDIFICIO_H

#include <string>
#include <sstream>
#include <cctype>

using namespace std;

const int POS_PRIMERA_LETRA = 0;
const string ESPACIO = " ";


class Edificio{

private:
    string nombre;
    string identificador;
    string material_brindado;
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
    Edificio(string linea);

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
    string obtener_nombre();

    //PRE:
    //POST:
    string obtener_identificador();

    //PRE:
    //POST:
    //string obtener_material_brindado(); // DUDAS

    //PRE:
    //POST:
    void agregar_cantidad_construidos(); //Nombre prototipo, esta horrible eso xD.

    //PRE:
    //POST:
    void restar_cantidad_construidos();
};

bool contiene_numeros(string s);

#endif // EDFICIO_H