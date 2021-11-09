#include <iostream>
#include "mapa.h"


// ------------------------------------------------------------------------------------------------------------


Mapa::Mapa(ifstream& archivo_mapa){

    string letra_leida;

    archivo_mapa >> letra_leida;
    this -> cantidad_filas = stoi(letra_leida);
    archivo_mapa >> letra_leida;
    this -> cantidad_columnas = stoi(letra_leida);

    // Creo el mapa
    mapa = new Casillero**[cantidad_filas];
    for (int i = 0 ; i < cantidad_filas ; ++i){
        mapa[i] = new Casillero*[cantidad_columnas];
    }

    // Utilizo el polimorfismo para crear el casillero y superficie correspondiente
    for(int i = 0 ; i < cantidad_filas ; ++i){
        for (int j = 0 ; j < cantidad_columnas; ++j){
            
            archivo_mapa >> letra_leida;
            Parser parser(letra_leida);
            Superficie* superficie_leida = parser.procesar_entrada_superficie();
            if(superficie_leida -> es_accesible()){
                if ( superficie_leida -> es_construible()){
                    mapa[i][j] = new Casillero_Construible(superficie_leida, i, j, false);
                } else {
                    mapa[i][j] = new Casillero_Transitable(superficie_leida, i, j, false);
                    Coordenadas* coord = new Coordenadas;
                    *coord = {i,j};
                    casilleros_transitables_disponibles.alta(coord,0);
                }
            } else {
                mapa[i][j] = new Casillero_Inaccesible(superficie_leida, i, j, false);
            }

        }
    }

}


// ------------------------------------------------------------------------------------------------------------


Mapa::Mapa(){

    this -> mapa = nullptr;
    this -> cantidad_columnas = 0;
    this -> cantidad_filas = 0;

}


// ------------------------------------------------------------------------------------------------------------


Mapa::~Mapa(){

    for(int i = 0 ; i < cantidad_filas ; ++i){
        for(int j = 0 ; j < cantidad_columnas ; ++j){
            delete mapa[i][j];
            mapa[i][j] = nullptr;
        }

        delete [] mapa[i];
        mapa[i] = nullptr;
    }

    for(int i = 0 ; i < casilleros_transitables_disponibles.obtener_cantidad() ; ++i){
        delete casilleros_transitables_disponibles.consulta(i);
        // casilleros_transitables_disponibles.consulta(i) == nullptr;
    }

    delete [] mapa;
    mapa = nullptr;

}


// ------------------------------------------------------------------------------------------------------------


int Mapa::obtener_filas(){

    return cantidad_filas;

}


// ------------------------------------------------------------------------------------------------------------


int Mapa::obtener_columnas(){

    return cantidad_columnas;

}


// ------------------------------------------------------------------------------------------------------------


bool Mapa::se_puede_transitar(int coord_x, int coord_y){

    return mapa[coord_x][coord_y] -> es_casillero_transitable();

}


// ------------------------------------------------------------------------------------------------------------


bool Mapa::se_puede_construir(int coord_x, int coord_y){

    return mapa[coord_x][coord_y] -> es_casillero_construible();

}


// ------------------------------------------------------------------------------------------------------------


bool Mapa::se_puede_acceder(int coord_x, int coord_y){

    return mapa[coord_x][coord_y] -> es_casillero_accesible();

}

// ------------------------------------------------------------------------------------------------------------


bool Mapa::casillero_esta_ocupado(int coord_x, int coord_y){

    return mapa[coord_x][coord_y] -> esta_ocupado();

}


// ------------------------------------------------------------------------------------------------------------


Estado_t Mapa::construir_edificio_en_coord(Edificio* edificio, int coord_x, int coord_y){

    Estado_t estado = OK;

    if(mapa[coord_x][coord_y] -> es_casillero_construible()){
        if(!(casillero_esta_ocupado(coord_x,coord_y)) ){
            mapa[coord_x][coord_y] -> construir_edificio_en_casillero(edificio);
            } else estado = ERROR_CASILLERO_OCUPADO;
    } else estado = ERROR_COORDENADA_NO_CONSTRUIBLE;

    return estado;

}


// ------------------------------------------------------------------------------------------------------------

Estado_t Mapa::agregar_material_en_coordenadas(Material* material, int coord_x, int coord_y){
    Estado_t estado = OK;

    if(mapa[coord_x][coord_y] -> es_casillero_transitable()){
        if(!(casillero_esta_ocupado(coord_x, coord_y))){
            mapa[coord_x][coord_y] -> poner_material_en_casillero(material);
        }else estado = ERROR_CASILLERO_OCUPADO;

    }else estado = ERROR_CASILLERO_NO_TRANSITABLE;

    return estado;

}

// ------------------------------------------------------------------------------------------------------------


Estado_t Mapa::consultar_casillero(int coord_x, int coord_y) const{

    Estado_t estado = OK;

    if(coord_x < cantidad_columnas && coord_y < cantidad_filas){
        mapa[coord_x][coord_y] -> consultar_casillero();
    } else estado = ERROR_COORDENADA_INVALIDA;

    return estado;

}


// ------------------------------------------------------------------------------------------------------------


void Mapa::mostrar_mapa(){

    imprimir_leyenda_mapa();

    for (int i = 0 ; i < cantidad_filas ; ++i){
        cout << "\t\t";
        for (int j = 0 ; j < cantidad_columnas ; ++j){
            mapa[i][j] -> imprimir_casillero();
        }
        cout << endl;
    }

/* esta bueno esto para que se printee bien, si no se imprime todo el menua abajo y queda medio feo.. pero esto es re cabeza
    string retorno;
    cout << endl;
    cout << "Ingrese cualquier cosa para volver" << endl;
    getline(cin, retorno);
*/

}


// ------------------------------------------------------------------------------------------------------------


void Mapa::sacar_coordenada_transitable_disponible_de_lista(Coordenadas coord){

    for(int i = 0 ; i < casilleros_transitables_disponibles.obtener_cantidad() ; ++i){
        if(coord.coordenada_x == casilleros_transitables_disponibles.consulta(i) -> coordenada_x
            && coord.coordenada_y == casilleros_transitables_disponibles.consulta(i) -> coordenada_y){
                casilleros_transitables_disponibles.baja(i);
        }
    }

}


// ------------------------------------------------------------------------------------------------------------


int Mapa::cantidad_casilleros_transitables_disponibles(){

    return this -> casilleros_transitables_disponibles.obtener_cantidad();

}


// ------------------------------------------------------------------------------------------------------------


void Mapa::imprimir_leyenda_mapa(){

cout << TAB << "╔═══════════════════════════════════════╗" << endl;
cout << TAB << NEGRITA << "║ " << "Superficies:" << string(25, ' ') << FIN_DE_FORMATO " ║" << endl;
cout << TAB << "║ " << FONDO_COLOR_AZUL  << "LAGO" << string(3, ' ') << FIN_DE_FORMATO << string(30, ' ') << " ║" << endl;
cout << TAB << "║ " << FONDO_COLOR_GRIS  << "CAMINO" << string(1, ' ') << FIN_DE_FORMATO << string(30, ' ') << " ║" << endl;
cout << TAB << "║ " << FONDO_COLOR_VERDE  << "TERRENO" << FIN_DE_FORMATO << string(30, ' ') << " ║" << endl;
cout << TAB << "║ " << string(37, ' ') << " ║" << endl;
cout << TAB << NEGRITA << "║ " << "Edificios:" << string(27, ' ') << FIN_DE_FORMATO << " ║" << endl;
cout << TAB << "║ " << "(A) Aserradero"  <<  string(23, ' ') << " ║" << endl;
cout << TAB << "║ " << "(E) Escuela"  << string(26, ' ') << " ║" << endl;
cout << TAB << "║ " << "(F) Fabrica"  << string(26, ' ') << " ║" << endl;
cout << TAB << "║ " << "(M) Mina"  << string(29, ' ') << " ║" << endl;
cout << TAB << "║ " << "(O) Obelisco"  << string(25, ' ') << " ║" << endl;
cout << TAB << "║ " << "(P) Planta electrica" << string(17, ' ')  << " ║" << endl;
cout << TAB << "║ " << "(Y) Yacimiento" << string(23, ' ')  << " ║" << endl;
cout << TAB << "║ " << string(37, ' ') << " ║" << endl;
cout << TAB << NEGRITA << "║ " << "Materiales:" << string(26, ' ') << FIN_DE_FORMATO << " ║" << endl;
cout << TAB << "║ " << "(I) Metal || (W) Madera || (S) Piedra"  << " ║" << endl;
cout << TAB << "╚═══════════════════════════════════════╝" << endl;    

}