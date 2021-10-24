#ifndef
#define EDIFICIO_H

#include <sstream>
#include <string>

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
    Edificio();
    Edificio(string linea);
    int obtener_costo_piedra();
    int obtener_costo_madera();
    int obtener_costo_metal();
};

#endif // EDFICIO_H