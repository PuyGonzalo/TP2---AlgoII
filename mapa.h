#ifndef MAPA_H
#define MAPA_H

#include "casillero.h"
#include "superficie.h"
#include "parser.h"
#include "Casilleros/casillero_construible.h"
#include "Casilleros/casillero_inaccesible.h"
#include "Casilleros/casillero_transitable.h"
//#include <string>

class Mapa{

private:
    // Atributos
    Casillero*** mapa;
    int cantidad_filas;
    int cantidad_columnas;

public:
    Mapa(ifstream& archivo_mapa);

    ~Mapa();

    int obtener_filas();

    int obtener_columnas();

    void mostrar_mapa();

    bool se_puede_transitar(int coord_x, int coord_y);

    bool se_puede_construir(int coord_x, int coord_y);

    bool se_puede_acceder(int coord_x, int coord_y);

    bool casillero_esta_ocupado(int coord_x, int coord_y);

    void construir_edificio_en_coord(Edificio* edificio, int coord_x, int coord_y); // status t

};





#endif // MAPA_H