#ifndef TERRENO_H
#define TERRENO_H


#include <sstream>
#include <fstream>
#include <string>
#include "../errores.h"
#include "../superficie.h"

using namespace std;

class Terreno : public Superficie {

public:
    // Metodos
    Terreno(char identificador);

};





#endif // TERRENO_H