#ifndef ANDYPOLIS_H
#define ANDYPOLIS_H

#include <sstream>
#include <fstream>
#include <string>
#include "casillero.h"

using namespace std;


class Andypolis{

protected:
    // Atributos
    Casillero*** mapa; // matriz dinamica (1 nivel mas porque son estructuras complejas y un nivel mas por ser abstracta)

public:
    // Metodos
    Andypolis();


};


#endif // ANDYPOLIS_H