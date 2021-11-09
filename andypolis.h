#ifndef ANDYPOLIS_H
#define ANDYPOLIS_H

#include <sstream>
#include <fstream>
#include <string>
#include <locale>
#include <iomanip>
#include "parser.h"
#include "inventario.h"
#include "mapa.h"
#include "errores.h"

using namespace std;

const int MAX_EDIF_CONSTRUIBLES_INICIAL = 3;
const int AMPLIACION_EDIF_CONSTRUIBLES = 2;
const char DELIM_ESPACIO = ' ';


class Andypolis{

private:
    // Atributos
    //Casilleroptr** mapa;
    Mapa mapa;
    Lista<Datos_edificio*> catalogo;
    int cantidad_edificios_catalogo;
    Inventario inventario;


public:
    // Metodos

    // pre: archivos bien formados
    // pos: CONSTRUCTOR de andypolis a partir de todos los archivos
    Andypolis(ifstream& archivo_edif, ifstream& archivo_ubics, ifstream& archivo_mapa, ifstream& archivo_mats);

    // pre: -
    // pos: DESTRUCTOR de andypolis
    ~Andypolis();

    // pre: archivo bien formado
    // pos: carga el catalogo con la lista de edificios que se pueden construir, sus costos, maximos posibles y cantidad construidos
    void cargar_catalogo(ifstream& archivo_edif);

    // pre: -
    // pos carga los edificios ya construidos en otras sesiones del juego
    void cargar_edificios(ifstream& archivo_ubics); // AGREGAR ESTADO_T DE ARCHIVO VACIO

    // pre: coordenadas posibles y edificio que este en el catalogo
    // pos: se cargan sobre el catalogo las coordenadas de un edificio construido (a la lista de coordenadas de los distintos del mismo)
    void cargar_coordenadas_en_catalogo(string nombre_edificio, int coord_x, int coord_y);

    // pre: -
    // pos: muestra el catalogo completo
    void mostrar_catalogo();

    // pre:  -
    // pos: muestra las ubicaciones del catalogo de un edificio en particular (en funcion de su indice en la lista)
    void mostrar_ubicaciones_construidas(int pos_edif_catalogo);

    // pre: -
    // pos: le pide al mapa que se imprima, mostrando Andypolis
    void mostrar_andypolis();

    // pre: -
    // pos: le pide al inventario que se imprima en pantalla, mostrandose
    void mostrar_inventario();

    // pre: coordenadas posibles
    // pos: le pide al mapa que consulte sobre la informacion de un casillero en particular
    Estado_t consultar_casillero_de_mapa(int coord_x, int coord_y) const;

    // pre: -
    // pos: lista/muestra SOLO los edificios construidos (y un mensaje en caso de que no haya ninguno)
    void listar_edificios_construidos();

    // pre: -
    // pos: construye un edificio particular en unas coordenadas particulares (y devuelve un error si hay algun dato que no concuerda)
    Estado_t construir_edificio(string nombre_edificio, int coord_x, int coord_y);

    // pre: -
    // pos: devuelve si hay o no un edificio en el catalogo
    bool esta_edificio(string nombre_edificio);

    // pre: -
    // pos: devuelve en que lugar de la lista (indice) hay un edificio en particular (devuelve -1 si lo encuentra)
    int indice_edificio_en_catalogo(string nombre_edificio);

    // pre: -
    // pos: posiciona los elementos de la lluvia de recursos
    Estado_t posicionar_lluvia_de_recursos(double cantidad_piedra, double cantidad_madera, double cantidad_metal);



};


#endif // ANDYPOLIS_H