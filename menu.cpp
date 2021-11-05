#include <iostream>
#include "menu.h"


using namespace std;


// ------------------------------------------------------------------------------------------------------------


void mostrar_menu(){
    cout << endl << endl;
    cout << TAB <<NEGRITA<< MSJ_MENU_BIENVENIDA <<FIN_DE_FORMATO<< endl;
    cout << TAB << "╔═══════════════════════════════════════╗" << endl;
    cout << TAB << "║ " << FONDO_COLOR_ROJO        << MSJ_MENU_OPCION_1 << TAB << FIN_DE_FORMATO << "║" << endl;
    cout << TAB << "║ " << FONDO_COLOR_ANARANJADO  << MSJ_MENU_OPCION_2 << TAB << FIN_DE_FORMATO << "║" << endl;
    cout << TAB << "║ " << FONDO_COLOR_AMARILLO    << MSJ_MENU_OPCION_3 << TAB << FIN_DE_FORMATO << "║" << endl;
    cout << TAB << "║ " << FONDO_COLOR_VERDE       << MSJ_MENU_OPCION_4 << TAB << FIN_DE_FORMATO << "║" << endl;
    cout << TAB << "║ " << FONDO_COLOR_AZUL        << MSJ_MENU_OPCION_5 << TAB << FIN_DE_FORMATO << "║" << endl;
    cout << TAB << "║ " << FONDO_COLOR_PURPURA     << MSJ_MENU_OPCION_6 << TAB << FIN_DE_FORMATO << "║" << endl;
    cout << TAB << "╚═══════════════════════════════════════╝" << endl;
}


// ------------------------------------------------------------------------------------------------------------


Estado_t procesar_opcion(int opcion_elegida, Andypolis andypolis, Inventario inventario){

    // Estado_t st; unused variable ‘st’
    string str_edificio;
    string codigo_ingresado;


    switch (opcion_elegida) {

        case LISTAR_MATERIALES:
            // system(CLR_SCREEN); error: ignoring return value of ‘int system(const char*)’, declared with attribute warn_unused_result
            //if( (st = listar_materiales(lm)) != OK )
            //    return st;
            break;

        case CONSTRUIR_EDIFICIO_POR_NOMBRE:
            // system(CLR_SCREEN);
            cout << TAB << MSJ_INGRESO_EDIFICIO_CONSTRUIR << endl;
            getline(cin, str_edificio);
            //if( (st = construir_edificio_nombre(andypolis, lm, str_edificio)) != OK )
            //    return st;
            break;

        case LISTAR_EDIFICIOS_CONSTRUIDOS:
            //system(CLR_SCREEN);
            //if( (st = listar_edificios_construidos(andypolis)) != OK )
            //    return st;
            break;

        case LISTAR_TODOS_LOS_EDIFICIOS:
            //system(CLR_SCREEN);
            //if( (st = listar_edificios_todos(andypolis)) != OK )
            //    return st;
            break;

        case DEMOLER_EDIFICIO_POR_NOMBRE:
            //system(CLR_SCREEN);
            cout << TAB << MSJ_INGRESO_EDIFICIO_DEMOLER << endl;
            getline(cin, str_edificio);
            //if( (st = demoler_edificio_nombre(andypolis, lm, str_edificio)) != OK )
            //    return st;
            break;

        case GUARDAR_SALIR:
            //system(CLR_SCREEN);
            cout << TAB << NEGRITA << FONDO_COLOR_AZUL << MSJ_DESPEDIDA << FIN_DE_FORMATO <<endl;
            cout << endl << endl;
            break;
        
        case MENU_SECRETO:
            //system(CLR_SCREEN);
            cout << TAB << MSJ_INGRESO_CODIGO_SECRETO << endl;
            getline(cin, codigo_ingresado);
            //if( (st = menu_secreto(lm, codigo_ingresado)) != OK)
            //    return st;
            break;

        default: 
            return ERROR_NUMERO_OPCION_INVALIDA;
    }

    return OK; 
}


// ------------------------------------------------------------------------------------------------------------


 bool es_entrada_valida(string str)
{
	char c;
	int N = (int) str.length();
    bool validez = true;

    if(!N) // string vacia
        validez = false; // si N == 0 ni va a entrar al for()

    for (int i = 0 ; i < N ; i++) { // && validez = true ?
    	c = str[i];
        if (isdigit(c) == 0) validez = false;
    }

    
    
    return validez;
}


// ------------------------------------------------------------------------------------------------------------


Estado_t ingreso_menu(int &opcion , Andypolis andypolis, Inventario inventario){
    
    Estado_t st = OK;
    string  opcion_elegida;

    //if(andypolis == nullptr || lm == nullptr)
    //    return ERROR_PUNTERO_NULO;

    cout << TAB << SUBRAYADO << MSJ_MENU_INGRESO_OPCION << FIN_DE_FORMATO <<endl;
    getline(cin, opcion_elegida);

    if(!es_entrada_valida(opcion_elegida))
        return ERROR_ENTRADA_INVALIDA;

    opcion = stoi(opcion_elegida);

    //st = procesar_opcion(opcion,andypolis,lm);

    return st;
}


// ------------------------------------------------------------------------------------------------------------


Estado_t menu_secreto(Inventario inventario, string codigo){
    
    Estado_t st = OK;
    string material_a_sumar;
    bool codigo_encontrado = false;
    int i = 0;

    //if (lm == nullptr)
    //    return ERROR_PUNTERO_NULO;

    while(!codigo_encontrado &&  i < MAX_CODIGOS_SECRETOS){
        if( codigo == codigos_secretos[i] ){
            stringstream sstream(codigo);
            sstream >> material_a_sumar;
            //agregar_cantidad_material(lm, material_a_sumar, CANTIDAD_SECRETA_AGREGADA);
            codigo_encontrado = true;
            cout << endl << endl;
            cout << TAB << NEGRITA << "¡Se agrego " << CANTIDAD_SECRETA_AGREGADA << " de " << material_a_sumar << "!" << FIN_DE_FORMATO << endl; 
        }
        i++;
    }

    if(!codigo_encontrado)
        st = ERROR_CODIGO_INEXISTENTE;


    return st;

}