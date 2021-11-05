#include <iostream>
#include "errores.h"

using namespace std;

void imprimir_error(Estado_t st){
	//system(CLR_SCREEN); // error: ignoring return value of ‘int system(const char*)’, declared with attribute warn_unused_result
	cout << endl;
	cout << TAB << NEGRITA << FONDO_COLOR_ROJO << errores[st] << FIN_DE_FORMATO << endl;
}
