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


void Andypolis::cargar_catalogo(ifstream& archivo_edif){
   
    this -> cantidad_edificios_catalogo = 0;
    string linea_leida;

    while (getline(archivo_edif,linea_leida)){

        Parser parser(linea_leida);
        Datos_edificio edificio_leido = parser.procesar_entrada_edificio();
        catalogo.alta(edificio_leido, this -> cantidad_edificios_catalogo);
        ++cantidad_edificios_catalogo;

    }   

}

 
// ------------------------------------------------------------------------------------------------------------


void Andypolis::cargar_edificios(ifstream& archivo_ubics){

    string linea_leida;
    int coordenada_x, coordenada_y;

    /*if(archivo_ubics.peek() == ifstream::traits_type::eof())
        int pistola = 1; // estado_t st = ARCHIVO_VACIO
        */

    while(getline(archivo_ubics, linea_leida)){

        Parser parser(linea_leida);
        coordenada_x = parser.obtener_coordenada_x();
        coordenada_y = parser.obtener_coordenada_y();
        mapa.construir_edificio_en_coord(parser.procesar_entrada_ubicaciones(), coordenada_x, coordenada_y);
        cargar_coordenadas_en_catalogo(parser.nombre_edificio_ubicaciones(), coordenada_x, coordenada_y);

    }

}


// ------------------------------------------------------------------------------------------------------------


/*Edificio* Andypolis::buscar_por_nombre_edificio_en_lista(string nombre){



}*/


// ------------------------------------------------------------------------------------------------------------


void Andypolis::mostrar_catalogo(){

    for(int i = 0 ; i < cantidad_edificios_catalogo ; ++i){
        cout << catalogo.consulta(i).nombre << endl;
        cout << catalogo.consulta(i).costo_piedra<< endl;
        cout << catalogo.consulta(i).costo_madera << endl;
        cout << catalogo.consulta(i).costo_metal << endl;
        cout << catalogo.consulta(i).cantidad_construidos << endl;
        cout << catalogo.consulta(i). maximos_permitidos << endl;
        // Metodo MOSTRAR UBICACIONES cout << catalogo.consulta(i) -> ubicaciones_construidos << endl;
    }

}


// ------------------------------------------------------------------------------------------------------------


void Andypolis::mostrar_andypolis(){

    mapa.mostrar_mapa();
    
}


// ------------------------------------------------------------------------------------------------------------


void Andypolis::consultar_casillero_de_mapa(int coord_x, int coord_y){

    mapa.consultar_casillero(coord_x,coord_y);

}


// ------------------------------------------------------------------------------------------------------------


void Andypolis::mostrar_inventario(){

    inventario.mostrar_inventario();

}


// ------------------------------------------------------------------------------------------------------------


void Andypolis::cargar_coordenadas_en_catalogo(string nombre_edificio, int coord_x, int coord_y){

    Coordenadas_ubicaciones coord = {coord_x , coord_y};
    bool edificio_detectado = false;
    int i = 0;

    while(!edificio_detectado){
        if(nombre_edificio == catalogo.consulta(i).nombre){

            catalogo.consulta(i).ubicaciones_construidos.alta(coord,0);
            ++catalogo.consulta(i).cantidad_construidos;
            edificio_detectado = true;
        } 
        ++i;
    }

}


// ------------------------------------------------------------------------------------------------------------


void Andypolis::listar_edificios_construidos(){

    if(!cantidad_edificios_catalogo){
        cout << "No hay edificios, rey" << endl;
    } else{
        for(int i = 0 ; i < cantidad_edificios_catalogo ; ++i){
            if(catalogo.consulta(i).cantidad_construidos != 0){
            cout << catalogo.consulta(i).nombre << ESPACIO << "(Totales = " << catalogo.consulta(i).cantidad_construidos << ")" << endl;
            cout << "Construidos en: ";
            mostrar_ubicaciones_construidas(i);
            cout << endl;
            }
        }
    }

}


// ------------------------------------------------------------------------------------------------------------


void Andypolis::mostrar_ubicaciones_construidas(int pos_edif){

    for(int i = 0; i < catalogo.consulta(pos_edif).cantidad_construidos ; ++i){
        cout << '(' << catalogo.consulta(pos_edif).ubicaciones_construidos.consulta(i).coordenada_x
        << ',' << ESPACIO << catalogo.consulta(pos_edif).ubicaciones_construidos.consulta(i).coordenada_y << ') ';
    }

}

// ------------------------------------------------------------------------------------------------------------

bool Andypolis::esta_edificio(string nombre_edificio){
    
    bool edificio_encontrado = false;
    int i = 0;

    while(!edificio_encontrado && i < cantidad_edificios_catalogo){
        if(catalogo.consulta(i).nombre == nombre_edificio){
            edificio_encontrado = true;
        }
        ++i;
    }

    return edificio_encontrado;
}

// ------------------------------------------------------------------------------------------------------------

int Andypolis::ubicacion_edificio_en_catalogo(string nombre_edificio){
    
    int ubicacion = -1;
    int i = 0;
    bool edificio_encontrado = false;

    while(i < cantidad_edificios_catalogo && !edificio_encontrado){
        if(catalogo.consulta(i).nombre == nombre_edificio){
            ubicacion = i;
            edificio_encontrado = true;
        }
        ++i;
    }

    return ubicacion;

}

// ------------------------------------------------------------------------------------------------------------

Estado_t Andypolis::construir_edificio(string nombre_edificio, int coord_x, int coord_y){
    
    Estado_t estado = OK;
    int ubicacion_edificio;
    string linea = "";

    if(esta_edificio(nombre_edificio)){
        ubicacion_edificio = ubicacion_edificio_en_catalogo(nombre_edificio);
        if(coord_x < mapa.obtener_filas() && coord_y < mapa.obtener_columnas()){
            if(catalogo.consulta(ubicacion_edificio).cantidad_construidos < catalogo.consulta(ubicacion_edificio).maximos_permitidos){
                if(catalogo.consulta(ubicacion_edificio).costo_piedra < inventario.obtener_cantidad_de_piedra() 
                && catalogo.consulta(ubicacion_edificio).costo_madera < inventario.obtener_cantidad_de_madera() 
                && catalogo.consulta(ubicacion_edificio).costo_metal < inventario.obtener_cantidad_de_metal()){

                    linea.append(catalogo.consulta(ubicacion_edificio).nombre);
                    linea.append(ESPACIO);
                    linea.append("(");
                    linea.append(to_string(coord_x));
                    linea.append(", ");
                    linea.append(to_string(coord_y));
                    linea.append(")");

                    Parser parser(linea);

                    estado = mapa.construir_edificio_en_coord(parser.procesar_entrada_ubicaciones(), coord_x, coord_y);
                    cargar_coordenadas_en_catalogo(parser.nombre_edificio_ubicaciones(), coord_x, coord_y);
                    
                    inventario.restar_cantidad_materiales_construccion(catalogo.consulta(ubicacion_edificio).costo_piedra, 
                    catalogo.consulta(ubicacion_edificio).costo_madera, catalogo.consulta(ubicacion_edificio).costo_metal);

                } else estado = ERROR_MATERIALES_INSUFICIENTES;

            } else estado = ERROR_MAXIMO_EDIFICIOS_ALCANZADO;

        } else estado = ERROR_POSICION_INEXISTENTE;
        
    } else estado = ERROR_EDIFICIO_INEXISTENTE;

    return estado;
    
}

// ------------------------------------------------------------------------------------------------------------

Estado_t Andypolis::posicionar_lluvia_de_recursos(double cantidad_piedra, double cantidad_madera, double cantidad_metal){
    Estado_t estado_final = OK;
    /*Estado_t estado_piedra, estado_madera, estado_metal;


    string piedra = "piedra 1";
    string madera = "madera 1";
    string metal = "metal 1";
    

    for(int i = 1; i <= cantidad_piedra; ++i){
        Parser parser(piedra);
    
        while(estado_piedra != OK){
            int coord_x = rand() % mapa.obtener_filas();
            int coord_y = rand() % mapa.obtener_columnas();
            estado_piedra = mapa.agregar_material_en_coordenadas(parser.procesar_entrada_material(), coord_x, coord_y);
        }
        
    }

    for(int i = 1; i <= cantidad_madera; ++i){int contador = 0;
        Parser parser(madera);

        while(estado_madera != OK){
            int coord_x = rand() % mapa.obtener_filas();
            int coord_y = rand() % mapa.obtener_columnas();
            estado_madera = mapa.agregar_material_en_coordenadas(parser.procesar_entrada_material(), coord_x, coord_y);

        }
        
    }

    for(int i = 1; i <= cantidad_metal; ++i){
        Parser parser(metal);
    
        while(estado_metal != OK){
            int coord_x = rand() % mapa.obtener_filas();
            int coord_y = rand() % mapa.obtener_columnas();
            estado_metal = mapa.agregar_material_en_coordenadas(parser.procesar_entrada_material(), coord_x, coord_y);

        }

        
    }

    
    return estado_final;*/

    cout << endl << "No hay tal lluvia de recursos chinchulin :P" << endl;
    return estado_final;
}

// ------------------------------------------------------------------------------------------------------------


Andypolis::~Andypolis(){}