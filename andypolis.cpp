#include <iostream>
#include "andypolis.h"


// ------------------------------------------------------------------------------------------------------------

// typedef Casillero* casilleroptr;
Andypolis::Andypolis(ifstream& archivo_edif, ifstream& archivo_ubics, ifstream& archivo_mapa, ifstream& archivo_mats) : 
mapa(archivo_mapa) , inventario(archivo_mats) {
    
    cargar_catalogo(archivo_edif);
    cargar_edificios(archivo_ubics);

}


// ------------------------------------------------------------------------------------------------------------


Andypolis::~Andypolis(){

    for(int i = 0 ; i < cantidad_edificios_catalogo ; ++i){
        for(int j = 0 ; j < catalogo.consulta(i) -> cantidad_construidos ; ++j){
            delete catalogo.consulta(i) -> ubicaciones_construidos.consulta(j);
            // catalogo.consulta(i) -> ubicaciones_construidos.consulta(j) = nullptr;
        }
        delete catalogo.consulta(i);
        // catalogo.consulta(i) = nullptr;
    }


}


// ------------------------------------------------------------------------------------------------------------


void Andypolis::cargar_catalogo(ifstream& archivo_edif){
   
    this -> cantidad_edificios_catalogo = 0;
    string linea_leida;

    while (getline(archivo_edif,linea_leida)){

        Parser parser(linea_leida);
        Datos_edificio* edificio_leido = parser.procesar_entrada_edificio();
        catalogo.alta(edificio_leido, this -> cantidad_edificios_catalogo);
        ++cantidad_edificios_catalogo;

    }   

}

 
// ------------------------------------------------------------------------------------------------------------


Estado_t Andypolis::cargar_edificios(ifstream& archivo_ubics){

    Estado_t estado = OK;
    string linea_leida;
    int coordenada_x, coordenada_y;

    if(archivo_ubics.peek() == ifstream::traits_type::eof())
        return ADVERTENCIA_UBICACIONES_VACIO;

    while(getline(archivo_ubics, linea_leida)){

        Parser parser(linea_leida);
        coordenada_x = parser.obtener_coordenada_x();
        coordenada_y = parser.obtener_coordenada_y();
        estado = mapa.construir_edificio_en_coord(parser.procesar_entrada_ubicaciones(), coordenada_x, coordenada_y);
        if (estado == OK){
            cargar_coordenadas_en_catalogo(parser.nombre_edificio_ubicaciones(), coordenada_x, coordenada_y);
        } else {
            estado = ADVERTENCIA_UBICACIONES_MAL_FORMADO;
            imprimir_error(estado);
        }

    }

    return estado;

}


// ------------------------------------------------------------------------------------------------------------


void Andypolis::cargar_coordenadas_en_catalogo(string nombre_edificio, int coord_x, int coord_y){

    Coordenadas* coord = new Coordenadas;
    *coord = {coord_x , coord_y};
    bool edificio_detectado = false;
    int i = 0;

    while(!edificio_detectado){
        if(nombre_edificio == catalogo.consulta(i) -> nombre){

            catalogo.consulta(i) -> ubicaciones_construidos.alta(coord,0);
            ++(catalogo.consulta(i) -> cantidad_construidos);
            edificio_detectado = true;
        } 
        ++i;
    }

}


// ------------------------------------------------------------------------------------------------------------


void Andypolis::quitar_coordenadas_en_catalogo(string nombre_edificio, int coord_x, int coord_y){

    bool edificio_detectado = false;
    bool coordenada_encontrada = false;
    int i = 0;

    while(!edificio_detectado){
        if(nombre_edificio == catalogo.consulta(i) -> nombre){
            int j = 0 ;
            edificio_detectado = true;
            while(!coordenada_encontrada){
                if(catalogo.consulta(i) -> ubicaciones_construidos.consulta(j) -> coordenada_x == coord_x
                    && catalogo.consulta(i) -> ubicaciones_construidos.consulta(j) -> coordenada_y == coord_y){
                        delete catalogo.consulta(i) -> ubicaciones_construidos.consulta(j);
                        catalogo.consulta(i) -> ubicaciones_construidos.baja(j);
                        --(catalogo.consulta(i) -> cantidad_construidos);
                        coordenada_encontrada = true;
                }
                ++j;
            }
        } 
        ++i;
    }

}


// ------------------------------------------------------------------------------------------------------------


void Andypolis::mostrar_catalogo(){

        cout
        << NEGRITA << SUBRAYADO
        << left
        << setw(22)
        << "Nombre del edificio"
        << left
        << setw(16)
        << "Costo (Piedra)"
        << left
        << setw(16)
        << "Costo (Madera)"
        << left
        << setw(16)
        << "Costo (Metal)"
        << left
        << setw(13)
        << "Construidos"
        << left
        << setw(24)
        << "Restantes hasta maximo"
        << left
        << setw(22)
        << "Material que brinda"
        << left
        << setw(33) // imposible poner un numero fijo xd
        << "Coordenadas donde se encuentran"
        << FIN_DE_FORMATO
        << endl;


    for(int i = 0 ; i < cantidad_edificios_catalogo ; ++i){
        cout
            << left
            << setw(22)
            << catalogo.consulta(i) -> nombre
            << left
            << setw(16)
            << catalogo.consulta(i) -> costo_piedra
            << left
            << setw(16)
            << catalogo.consulta(i) -> costo_madera
            << left
            << setw(16)
            << catalogo.consulta(i) -> costo_metal
            << left
            << setw(13)
            << catalogo.consulta(i) -> cantidad_construidos
            << left
            << setw(24)
            << catalogo.consulta(i) ->  maximos_permitidos - catalogo.consulta(i) ->  cantidad_construidos
            << left
            << setw(27)
            << obtener_material_brindado_por_edificio_str(i)
            << left
            << setw(29)   
            << obtener_ubicaciones_construidas_str(i)
            << endl;
    }

}


// ------------------------------------------------------------------------------------------------------------

string Andypolis::obtener_material_brindado_por_edificio_str(int posicion){ // VILLERISIMOOOOOOOOOO (NO SE ME OCURRE OTRA FORMA A ESTA HORA)
    if(catalogo.consulta(posicion) -> brinda_material){
        if(catalogo.consulta(posicion) -> nombre == STR_MINA){
            return STR_PIEDRA;
        }else if(catalogo.consulta(posicion) -> nombre == STR_FABRICA){
            return STR_METAL;
        }else if(catalogo.consulta(posicion) -> nombre == STR_ASERRADERO){
            return STR_MADERA;
        }
    }

    return "-";
}

// ------------------------------------------------------------------------------------------------------------

string Andypolis::obtener_ubicaciones_construidas_str(int pos_edif){

    stringstream sstream;

    if(catalogo.consulta(pos_edif)->cantidad_construidos != 0){
        for(int i = 0; i < catalogo.consulta(pos_edif) -> cantidad_construidos ; ++i){
            
            sstream << '(' << catalogo.consulta(pos_edif) -> ubicaciones_construidos.consulta(i) -> coordenada_x
            << ',' << ESPACIO << catalogo.consulta(pos_edif) -> ubicaciones_construidos.consulta(i) -> coordenada_y << ") ";
            /*
            cout << '(' << catalogo.consulta(pos_edif) -> ubicaciones_construidos.consulta(i) -> coordenada_x
            << ',' << ESPACIO << catalogo.consulta(pos_edif) -> ubicaciones_construidos.consulta(i) -> coordenada_y << ") ";
            */
        }
    }

    return sstream.str();

}


// ------------------------------------------------------------------------------------------------------------


void Andypolis::mostrar_andypolis(){

    mapa.mostrar_mapa();
    
}


// ------------------------------------------------------------------------------------------------------------


void Andypolis::mostrar_inventario(){

    inventario.mostrar_inventario();

}


// ------------------------------------------------------------------------------------------------------------


Estado_t Andypolis::consultar_casillero_de_mapa(int coord_x, int coord_y) const{ // BUENA PRACTICA poner en todos los Consultar/mostrar

    Estado_t estado = OK;

    return estado = mapa.consultar_casillero(coord_x,coord_y);

}


// ------------------------------------------------------------------------------------------------------------


void Andypolis::listar_edificios_construidos(){

    if(!cantidad_edificios_catalogo){
        cout << "No hay edificios construidos :(" << endl;
    } else{

    cout
        << NEGRITA << SUBRAYADO
        << left
        << setw(22)
        << "Nombre del edificio"
        << left
        << setw(13)
        << "Construidos"
        << left
        << setw(33)
        << "Coordenadas donde se encuentran"
        << FIN_DE_FORMATO
        << endl;


        for(int i = 0 ; i < cantidad_edificios_catalogo ; ++i){
            if(catalogo.consulta(i) -> cantidad_construidos != 0){        
            cout 
                << left
                << setw(22)
                << catalogo.consulta(i) -> nombre
                << left
                << setw(13)
                << catalogo.consulta(i) -> cantidad_construidos
                << left
                << setw(33)
                << obtener_ubicaciones_construidas_str(i)
                << endl;
            }
        }
    }

}


// ------------------------------------------------------------------------------------------------------------


Estado_t Andypolis::construir_edificio_en_coord(string nombre_edificio, int coord_x, int coord_y){
    
    Estado_t estado = OK;
    int indice_edificio;
    string linea = "";

    if(esta_edificio(nombre_edificio)){
        indice_edificio = indice_edificio_en_catalogo(nombre_edificio);
        if(coord_x < mapa.obtener_filas() && coord_y < mapa.obtener_columnas()){
            if(catalogo.consulta(indice_edificio) -> cantidad_construidos < catalogo.consulta(indice_edificio) -> maximos_permitidos){
                if(catalogo.consulta(indice_edificio) -> costo_piedra < inventario.obtener_cantidad_de_piedra() 
                && catalogo.consulta(indice_edificio) -> costo_madera < inventario.obtener_cantidad_de_madera() 
                && catalogo.consulta(indice_edificio) -> costo_metal < inventario.obtener_cantidad_de_metal()){
                    if(mapa.se_puede_construir(coord_x,coord_y)){
                        if(!mapa.casillero_esta_ocupado(coord_x,coord_y)){
                            if(confirma_construccion(estado, nombre_edificio, coord_x, coord_y)){
                                
                                linea.append(catalogo.consulta(indice_edificio) -> nombre);
                                linea.append(ESPACIO);
                                linea.append("(");
                                linea.append(to_string(coord_x));
                                linea.append(", ");
                                linea.append(to_string(coord_y));
                                linea.append(")");

                                Parser parser(linea);

                                estado = mapa.construir_edificio_en_coord(parser.procesar_entrada_ubicaciones(), coord_x, coord_y);
                                cargar_coordenadas_en_catalogo(parser.nombre_edificio_ubicaciones(), coord_x, coord_y);
                                
                                inventario.restar_cantidad_materiales_construccion(catalogo.consulta(indice_edificio) -> costo_piedra, 
                                catalogo.consulta(indice_edificio) -> costo_madera, catalogo.consulta(indice_edificio) -> costo_metal);

                                cout<<TAB<<TAB<<NEGRITA<< "¡Se construyo " << nombre_edificio << " exitosamente!" <<FIN_DE_FORMATO<<endl;
                            }
                        } else estado = ERROR_CASILLERO_OCUPADO;
                    } else estado = ERROR_CASILLERO_NO_CONSTRUIBLE;
                } else estado = ERROR_MATERIALES_INSUFICIENTES;
            } else estado = ERROR_MAXIMO_EDIFICIOS_ALCANZADO;
        } else estado = ERROR_POSICION_INEXISTENTE;   
    } else estado = ERROR_EDIFICIO_INEXISTENTE;

    return estado;
    
}


// ------------------------------------------------------------------------------------------------------------


Estado_t Andypolis::destruir_edificio_de_coord(int coord_x, int coord_y){

    Estado_t estado = OK;
    string nombre_edificio;

    if(coord_x < mapa.obtener_filas() && coord_y < mapa.obtener_columnas()){
        if(mapa.se_puede_construir(coord_x,coord_y)){
            if(mapa.casillero_esta_ocupado(coord_x,coord_y)){
                
                nombre_edificio = mapa.obtener_nombre_objeto_de_casillero_ocupado(coord_x,coord_y);

                mapa.destruir_edificio_en_coord(coord_x, coord_y);

                // Devuelvo materiales
                int indice_edificio = indice_edificio_en_catalogo(nombre_edificio);
                inventario.sumar_cantidad_materiales_construccion(
                    catalogo.consulta(indice_edificio) -> costo_piedra/2,
                    catalogo.consulta(indice_edificio) -> costo_madera/2,
                    catalogo.consulta(indice_edificio) -> costo_metal/2);
                
                quitar_coordenadas_en_catalogo(nombre_edificio, coord_x, coord_y);

                cout<<TAB<<TAB<<NEGRITA<< "¡Se destruyo " << nombre_edificio << " exitosamente!" <<FIN_DE_FORMATO<<endl;

            } else estado = ERROR_CASILLERO_VACIO;
        } else estado = ERROR_CASILLERO_NO_CONSTRUIBLE;
    } else estado = ERROR_POSICION_INEXISTENTE;

    
 
    return estado;

}


// ------------------------------------------------------------------------------------------------------------


bool Andypolis::confirma_construccion(Estado_t &estado, string nombre_edificio, int coord_x, int coord_y){

    string confirmacion_construccion;
    
    if(system(CLR_SCREEN));
    cout << endl << TAB << "¿Esta seguro que desea construir " << nombre_edificio <<
    " en " << '(' << coord_x << ',' << coord_y << ')' << "? (escribir SI o NO)" << endl;
    getline(cin, confirmacion_construccion);

    if(confirmacion_construccion == CONFIRMACION_AFIRMATIVA_CONSTRUCCION)
        return true;
    if(confirmacion_construccion == CONFIRMACION_NEGATIVA_CONSTRUCCION)
        return false;
    
    // si no es ninguna de las 2, no edifico y devuelvo entrada invalida
    estado = ERROR_ENTRADA_INVALIDA;
    return false;   

}


// ------------------------------------------------------------------------------------------------------------


bool Andypolis::esta_edificio(string nombre_edificio){
    
    bool edificio_encontrado = false;
    int i = 0;

    while(!edificio_encontrado && i < cantidad_edificios_catalogo){
        if(catalogo.consulta(i) -> nombre == nombre_edificio){
            edificio_encontrado = true;
        }
        ++i;
    }

    return edificio_encontrado;
}


// ------------------------------------------------------------------------------------------------------------


int Andypolis::indice_edificio_en_catalogo(string nombre_edificio){
    
    int ubicacion = -1;
    int i = 0;
    bool edificio_encontrado = false;

    while(i < cantidad_edificios_catalogo && !edificio_encontrado){
        if(catalogo.consulta(i) -> nombre == nombre_edificio){
            ubicacion = i;
            edificio_encontrado = true;
        }
        ++i;
    }

    return ubicacion;

}


// ------------------------------------------------------------------------------------------------------------


Estado_t Andypolis::posicionar_lluvia_de_recursos(int cantidad_lluvia_piedra, int cantidad_lluvia_madera, int cantidad_lluvia_metal){

    string piedra = "piedra 1";
    string madera = "madera 1";
    string metal = "metal 1";

    int casilleros_disponibles = mapa.cantidad_casilleros_transitables_disponibles();

    if(casilleros_disponibles < cantidad_lluvia_piedra + cantidad_lluvia_madera + cantidad_lluvia_metal)
        return ADVERTENCIA_LLUVIA_RECURSOS; // no tiene sentido seguir si esto pasa
    

    for(int i = 1; i <= cantidad_lluvia_piedra; ++i){
        Parser parser(piedra);
        mapa.agregar_material_en_coordenada_transitable_aleatoria(parser.procesar_entrada_material());
    }

    for(int i = 1; i <= cantidad_lluvia_madera; ++i){
        Parser parser(madera);
        mapa.agregar_material_en_coordenada_transitable_aleatoria(parser.procesar_entrada_material());
    }

    for(int i = 1; i <= cantidad_lluvia_metal; ++i){
        Parser parser(metal);
        mapa.agregar_material_en_coordenada_transitable_aleatoria(parser.procesar_entrada_material());
    }

    cout << endl << TAB << FONDO_COLOR_AZUL << NEGRITA << "¡LLUVIA DE RECURSOS!" << FIN_DE_FORMATO << endl;


    return OK;
}

// ------------------------------------------------------------------------------------------------------------

Estado_t Andypolis::recolectar_materiales(){
    bool exito = false;
    
    
    for(int i = 0; i < cantidad_edificios_catalogo; ++i){
        
        if(catalogo.consulta(i) -> brinda_material){

            if(catalogo.consulta(i) -> cantidad_construidos > 0){
                char identificador;
                double cantidad_material, cantidad_a_agregar;
                int x = catalogo.consulta(i)->ubicaciones_construidos.consulta(0)->coordenada_x;//Tomo el primero construido siempre, cualquiera me sirve.
                int y = catalogo.consulta(i)->ubicaciones_construidos.consulta(0)->coordenada_y;

                identificador = mapa.obtener_material_brindado_casillero(x,y);

                cantidad_material = mapa.obtener_cantidad_material_brindado_casillero(x,y);

                cantidad_a_agregar = (double) catalogo.consulta(i) -> cantidad_construidos * cantidad_material;

                inventario.sumar_cantidad_material(identificador, cantidad_a_agregar);

                exito = true;
            }
        }
    }

    if(exito){
        return OK;
    }else{
        return ERROR_RECOLECCION_MATERIALES;
    }
}

// ------------------------------------------------------------------------------------------------------------

void Andypolis::guardar_andypolis(ofstream& archivo_materiales, ofstream& archivo_ubicaciones){

    for(int i = 0; i < mapa.obtener_filas(); ++i){
        for(int j = 0; j < mapa.obtener_columnas(); ++j){
            if(mapa.se_puede_construir(i,j) && mapa.casillero_esta_ocupado(i,j)){
                archivo_ubicaciones << mapa.obtener_nombre_objeto_de_casillero_ocupado(i,j)
                                    << ESPACIO << "(" << i << ", " << j << ")" << '\n';
            }
        }
    }

    inventario.guardar_inventario(archivo_materiales);
}