#include <iostream>
#include "herramientas.h"


bool contiene_numeros(string s){
    const string CONT = "0123456789";
    if(s.find_first_of(CONT) != string::npos){
        return true;
    }else
        return false;
}

bool contiene_letras(string s){
    const string CONT = "0123456789";
    if(s.find_first_not_of(CONT) != string::npos){
        return true;
    }else
        return false;
}
