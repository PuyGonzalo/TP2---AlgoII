#ifndef CAMINO_H
#define CAMINO_H


#include <sstream>
#include <fstream>
#include <string>
#include "../errores.h"
#include "../superficie.h"

using namespace std;

class Camino : public Superficie {

public:
    // Metodos
    Camino(char identificador);

    ~Camino(){};

};





#endif // CAMINO_H