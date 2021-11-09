#include <iostream>
#include "menu.h"


using namespace std;


// ------------------------------------------------------------------------------------------------------------


void mostrar_menu(){
    cout << endl << endl;
    cout << TAB <<NEGRITA<< MSJ_MENU_BIENVENIDA <<FIN_DE_FORMATO<< endl<<endl;
    cout << TAB << "╔════════════════════════════════════════╗" << endl;
    cout << TAB << "║ " << FONDO_COLOR_PURPURA  << MSJ_MENU_OPCION_1 << string(6, ' ') << FIN_DE_FORMATO << " ║" << endl;
    cout << TAB << "║ " << FONDO_COLOR_PURPURA  << MSJ_MENU_OPCION_2 << string(3, ' ') << FIN_DE_FORMATO << " ║" << endl;
    cout << TAB << "║ " << FONDO_COLOR_PURPURA  << MSJ_MENU_OPCION_3 << string(9, ' ') << FIN_DE_FORMATO << " ║" << endl;
    cout << TAB << "║ " << FONDO_COLOR_PURPURA  << MSJ_MENU_OPCION_4 << string(1, ' ') << FIN_DE_FORMATO << " ║" << endl;
    cout << TAB << "║ " << FONDO_COLOR_PURPURA  << MSJ_MENU_OPCION_5 << string(23, ' ') << FIN_DE_FORMATO << " ║" << endl;
    cout << TAB << "║ " << FONDO_COLOR_PURPURA  << MSJ_MENU_OPCION_6 << string(15, ' ') << FIN_DE_FORMATO << " ║" << endl;
    cout << TAB << "║ " << FONDO_COLOR_PURPURA  << MSJ_MENU_OPCION_7 << string(17, ' ') << FIN_DE_FORMATO << " ║" << endl;
    cout << TAB << "║ " << FONDO_COLOR_PURPURA  << MSJ_MENU_OPCION_8 << string(5, ' ') << FIN_DE_FORMATO << " ║" << endl;
    cout << TAB << "║ " << FONDO_COLOR_PURPURA  << MSJ_MENU_OPCION_9 << string(17, ' ') << FIN_DE_FORMATO << " ║" << endl;
    cout << TAB << "║ " << FONDO_COLOR_PURPURA  << MSJ_MENU_OPCION_10 << string(19, ' ') << FIN_DE_FORMATO << " ║" << endl;
    cout << TAB << "╚════════════════════════════════════════╝" << endl;
}


// ------------------------------------------------------------------------------------------------------------


Estado_t procesar_opcion(int opcion_elegida, Andypolis &andypolis){

    Estado_t estado = OK;
    string str_edificio;
    string codigo_ingresado;


    switch (opcion_elegida) {

        case CONSTRUIR_EDIFICIO_POR_NOMBRE:
            if(system(CLR_SCREEN)); // error: ignoring return value of ‘int system(const char*)’, declared with attribute warn_unused_result
            estado = construir_edificio_por_nombre(andypolis);
            break;

        case LISTAR_EDIFICIOS_CONSTRUIDOS:
            if(system(CLR_SCREEN));
            andypolis.listar_edificios_construidos();
            break;

        case LISTAR_TODOS_LOS_EDIFICIOS: 
            if(system(CLR_SCREEN));
            andypolis.mostrar_catalogo();
            break;

        case DEMOLER_EDIFICIO_POR_COORD:
            if(system(CLR_SCREEN));
            estado = demoler_edificio_por_coordenada(andypolis);
            break;

        case MOSTRAR_MAPA:
            if(system(CLR_SCREEN));
            andypolis.mostrar_andypolis();
            break;
        
        case CONSULTAR_COORDENADA: 
            if(system(CLR_SCREEN));
            estado = consultar_coordenada(andypolis);
            break;

        case MOSTRAR_INVENTARIO:
            if(system(CLR_SCREEN));
            andypolis.mostrar_inventario();
            break;

        case RECOLETAR_RECURSOS_PRODUCIDOS:
            //system(CLR_SCREEN);

            break;

        case LLUVIA_RECURSOS:
            if(system(CLR_SCREEN));
            estado = lluvia_de_recursos(andypolis);
            break;

        case GUARDAR_SALIR:
            if(system(CLR_SCREEN));
            cout << endl << TAB << NEGRITA << FONDO_COLOR_AZUL << MSJ_DESPEDIDA << FIN_DE_FORMATO <<endl;
            cout << endl << endl;
            break;
        
        case MENU_SECRETO:
            if(system(CLR_SCREEN));
            cout << TAB << MSJ_INGRESO_CODIGO_SECRETO << endl;
            getline(cin, codigo_ingresado);
            //if( (st = menu_secreto(lm, codigo_ingresado)) != OK)
            //    return st;
            break;

        default: 
            return ERROR_NUMERO_OPCION_INVALIDA;
    }

    return estado; 
}


// ------------------------------------------------------------------------------------------------------------


Estado_t ingreso_menu(int &opcion , Andypolis &andypolis){
    
    Estado_t estado = OK;
    string  opcion_elegida;

    cout << TAB << SUBRAYADO << MSJ_MENU_INGRESO_OPCION << FIN_DE_FORMATO <<endl;
    getline(cin, opcion_elegida);

    if(!es_un_numero(opcion_elegida))
        return ERROR_ENTRADA_INVALIDA;

    opcion = stoi(opcion_elegida);

    estado = procesar_opcion(opcion,andypolis);

    return estado;
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