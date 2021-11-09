#ifndef MAPA_H
#define MAPA_H

#include "casillero.h"
#include "superficie.h"
#include "parser.h"
#include "lista.h"
#include "herramientas.h"
#include "Casilleros/casillero_construible.h"
#include "Casilleros/casillero_inaccesible.h"
#include "Casilleros/casillero_transitable.h"


class Mapa{

private:
    // Atributos
    Casillero*** mapa;
    int cantidad_filas;
    int cantidad_columnas;
    Lista<Coordenadas*> casilleros_transitables_disponibles;

public:
    // Metodos

    // pre: archivo debe ser valido
    // pos: CONSTRUCTOR del mapa
    Mapa(ifstream& archivo_mapa);

    // pre: archivo debe ser valido
    // pos: CONSTRUCTOR del mapa default
    Mapa();

    // pre: -
    // pos: DESCTRUCTOR del mapa
    ~Mapa();

    // pre: -
    // pos: obtiene la cantidad de filas que tiene el mapa
    int obtener_filas();

    // pre: -
    // pos: obtiene la cantidad de columnas que tiene el mapa
    int obtener_columnas();

    // pre: coordenadas validas (depende de mapa.txt)
    // pos: devuelve si un casillero particular del mapa es transitable
    bool se_puede_transitar(int coord_x, int coord_y);

    // pre: coordenadas validas (depende de mapa.txt)
    // pos: devuelve si un casillero particular del mapa es construible
    bool se_puede_construir(int coord_x, int coord_y);

    // pre: coordenadas validas (depende de mapa.txt)
    // pos: devuelve si un casillero particular del mapa es accesible
    bool se_puede_acceder(int coord_x, int coord_y);

    // pre: coordenadas validas (depende de mapa.txt)
    // pos: devuelve si un casillero particular del mapa esta ocupado
    bool casillero_esta_ocupado(int coord_x, int coord_y);

    // pre: coordenadas validas
    // pos: "construye" un edificio en una coordenada dada (y devuelve un error en caso de que sea no sea construible o ya este ocupado)
    Estado_t construir_edificio_en_coord(Edificio* edificio, int coord_x, int coord_y);

    // pre:
    // pos:
    Estado_t agregar_material_en_coordenadas(Material* material, int coord_x, int coord_y);


    // pre: coordenadas validas
    // pos: consulta un casillero del mapa en particular
    Estado_t consultar_casillero(int coord_x, int coord_y) const;

    // pre: -
    // pos: muestra el mapa con sus edificios y materiales
    void mostrar_mapa();

    // pre: -
    // pos: imprime la leyenda del mapa (las referencias de que es cada cosa)
    void imprimir_leyenda_mapa();

    // pre: -
    // pos: saca una coordenada de la lista de trasitables ya que se ocupo
    void sacar_coordenada_transitable_disponible_de_lista(Coordenadas coord);

    // pre: -
    // pos: devuelve la cantidad de casilleros transitables desocupados/disponibles/libres
    int cantidad_casilleros_transitables_disponibles();

};





#endif // MAPA_H