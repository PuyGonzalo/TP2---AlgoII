#include "obelisco.h"


// ------------------------------------------------------------------------------------------------------------


Obelisco::Obelisco(string identificador): Edificio(identificador){}

// ------------------------------------------------------------------------------------------------------------


string Obelisco::obtener_tipo_edificio(){
    return STR_OBELISCO;
}
