#ifndef CASILLERO_H
#define CASILLERO_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "errores.h"
#include "superficie.h"
#include "edificio.h"
#include "material.h"

using namespace std;

class Casillero{

protected:
    // Atributos
    Superficie* superficie = nullptr; // hasta no leer el mapa.txt no se que superficie tiene
    int coord_x;
    int coord_y;
    bool ocupado;


public:
    // Metodos

    // pre: -
    // pos: CONSTRUCTOR de casillero
    Casillero(Superficie* superficie, int coord_x, int coord_y, bool ocupado);

    // pre: -
    // pos: CONSTRUCTOR de casillero default
    Casillero();

    // pre: -
    // pos: DESTRUCTOR de casillero
    virtual ~Casillero(); // Destructor

    // pre: -
    // pos: devuelve la coordenada x del casillero
    int obtener_coordenada_x();
    
    // pre: 
    // pos: devuelve la coordenada x del casillero
    int obtener_coordenada_y();

    // pre: -
    // pos: devuelve si el casillero esta ocupado (ya sea por un material o edificio) o no
    bool esta_ocupado();

    // pre: -
    // pos: devuelve, en funcion de su superficie, si es un casillero transitable o no
    bool es_casillero_transitable();

    // pre: -
    // pos: devuelve, en funcion de su superficie, si es un casillero construible o no
    bool es_casillero_construible();

    // pre: -
    // pos: devuelve, en funcion de su superficie, si es un casillero accesible o no
    bool es_casillero_accesible();

    // pre: -
    // pos: pone un edificio en el casillero (solo en construible)
    virtual void construir_edificio(Edificio* edificio){};

    // pre: usar habiendo chequeado que el casillero esta ocupado
    // pos: metodo virtual para que <los casilleros construibles> devuelvan el material que brindan (si tienen un edificio)
    virtual char obtener_material_brindado_de_casillero() = 0; // virtual puro porque metodo virtual con ret =/= void

    // pre: usar habiendo chequeado que el casillero esta ocupado
    // pos: metodo virtual para que <los casilleros construibles> devuelvan la cantidad material que brindan (si tienen un edificio)
    virtual double obtener_cantidad_material_brindado_de_casillero() = 0;

    // pre: -
    // pos: elimina el edificio del casillero (solo en construible)
    virtual void destruir_edificio(){};

    // pre: -
    // pos: pone un material en un casillero (solo en transitables)
    virtual void poner_material(Material* material){};

    // pre: solo puede llamarse si se esta seguro que el casillero esta ocupado
    // pos: devuelve el nombre del edificio (construible), material (transitable)
    virtual string obtener_nombre_objeto_de_casillero() = 0;

    // pre: -
    // pos: imprime un mensaje con informacion del casillero (que casillero es y si esta o no ocupado)
    virtual void consultar_casillero() = 0;

    // pre: -
    // pos: imprime el casillero (cada casillero se imprime distinto en funcion de su superficie y si esta ocupado)
    virtual void imprimir_casillero() = 0;

};


#endif // CASILLERO_H