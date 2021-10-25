#ifndef EDIFICIO_H
#define EDIFICIO_H

#include <string>
#include <sstream>

using namespace std;


class Edificio{

private:
    string nombre;
    string identificador;
    string material_brindado;
    int costo_piedra{};
    int costo_madera{};
    int costo_metal{};
    int cantidad_construidos{};
    int maximos_permitidos{};

public:
    Edificio();
    Edificio(string linea);
    int obtener_costo_piedra();
    int obtener_costo_madera();
    int obtener_costo_metal();
    int obtener_maximos_permitidos();
    string obtener_nombre();
    string obtener_identificador();
    //string obtener_material_brindado(); // DUDAS
    void agregar_cantidad_construidos(); //Nombre prototipo, esta horrible eso xD.
    void restar_cantidad_construidos();
};

bool contiene_numeros(string s);

#endif // EDFICIO_H