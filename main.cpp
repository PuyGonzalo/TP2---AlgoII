#include <iostream>
#include "edificio.h"
#include "errores.h"
#include "material.h"
#include "menu.h"


int main (void){

    Material mat1("piedra 123");
    Material mat2("oro 139");

    cout << mat1.obtener_identificador() << endl;
    cout << mat2.obtener_identificador() << endl;



    return 0;
}