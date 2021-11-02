#ifndef LAGO_H
#define LAGO_H


#include <sstream>
#include <fstream>
#include <string>
#include "../errores.h"
#include "../superficie.h"

using namespace std;

class Lago : public Superficie {

public:
    // Metodos
    Lago(char identificador);

    ~Lago(){};

};





#endif // LAGO_H