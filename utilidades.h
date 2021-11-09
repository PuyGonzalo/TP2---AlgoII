#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <iostream>
#include <cstdlib>
#include "andypolis.h"
#include "errores.h"
#include "herramientas.h"


using namespace std;

const int RAND_MAX_PIEDRA = 2;
const int RAND_MAX_MADERA = 2;
const int RAND_MAX_METAL = 3;

const string MSJ_INGRESO_EDIFICIO_CONSTRUIR = "Ingresa el nombre del edifico a construir:";

// pre: 
// pos:
Estado_t construir_edificio_por_nombre(Andypolis& andypolis);

// pre:
// pos:
Estado_t demoler_edificio_por_coordenada(Andypolis& andypolis);

// pre:
// pos:
Estado_t consultar_coordenada(const Andypolis &andypolis); // (me evito crear un nuevo objeto andypolis..)

// pre:
// pos:
Estado_t lluvia_de_recursos(Andypolis& andypolis);

#endif // UTILIDADES_H