#ifndef CASILLERO_H
#define CASILLERO_H

#include <sstream>
#include <fstream>
#include <string>
#include "errores.h"
#include "superficie.h"

using namespace std;

class Casillero{

protected:
    // Atributos
    Superficie superficie;
    int coord_x;
    int coord_y;
    bool ocupado;


public:
    // Metodos
    Casillero();

    

};


#endif // CASILLERO_H