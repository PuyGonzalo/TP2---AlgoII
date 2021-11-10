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

const string CONFIRMACION_AFIRMATIVA_CONSTRUCCION = "SI";
const string CONFIRMACION_NEGATIVA_CONSTRUCCION = "NO";


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
    Estado_t cargar_edificios(ifstream& archivo_ubics);

    // pre: coordenadas posibles y edificio que este en el catalogo
    // pos: se cargan sobre el catalogo las coordenadas de un edificio construido (a la lista de coordenadas de construidos del mismo)
    void cargar_coordenadas_en_catalogo(string nombre_edificio, int coord_x, int coord_y);

    // pre: coordenadas posibles y edificio que este en el catalogo
    // pos: usada para sacar una coordenada de un edificio construido (porque seguro el usuario lo destruyo)
    void quitar_coordenadas_en_catalogo(string nombre_edificio, int coord_x, int coord_y);

    // pre: -
    // pos: muestra el catalogo completo
    void mostrar_catalogo();

    // pre:  -
    // pos: muestra las ubicaciones del catalogo de un edificio en particular (en funcion de su indice en la lista)
    string obtener_ubicaciones_construidas_str(int pos_edif_catalogo);

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
    Estado_t construir_edificio_en_coord(string nombre_edificio, int coord_x, int coord_y);

    // pre: -
    // pos: destruye un edificio en caso de que en la coordenada que pase el usuario haya un edificio, si no devuelve un error/aviso
    Estado_t destruir_edificio_de_coord(int coord_x, int coord_y);

    // pre: -
    // pos: le pregunta al usuario que confirme su construccion (y cambia el estado si pone cualquier cosa que no sea si o no)
    bool confirma_construccion(Estado_t &estado, string nombre_edificio, int coord_x, int coord_y);

    // pre: -
    // pos: devuelve si hay o no un edificio en el catalogo
    bool esta_edificio(string nombre_edificio);

    // pre: -
    // pos: devuelve en que lugar de la lista (indice) hay un edificio en particular (devuelve -1 si lo encuentra)
    int indice_edificio_en_catalogo(string nombre_edificio);

    // pre: -
    // pos: posiciona los elementos de la lluvia de recursos
    Estado_t posicionar_lluvia_de_recursos(int cantidad_lluvia_piedra, int cantidad_lluvia_madera, int cantidad_lluvia_metal);

    // pre:
    // pos:
    Estado_t recolectar_materiales();


};


#endif // ANDYPOLIS_H