#include <iostream>
#include "inventario.h"


// ------------------------------------------------------------------------------------------------------------


Inventario::Inventario(){

    // CREAR LISTA VACIA DE Lista<Material*> lista_materiales;
    this -> cantidad_materiales = 0;

}


// ------------------------------------------------------------------------------------------------------------


Inventario::Inventario(ifstream& archivo){
    
    string linea_leida;
    this -> cantidad_materiales = 0;
    // inicializar la lista como vacia? o ya siendo atributo se "crea vacia" -> si, printear para ver?


    while(getline(archivo, linea_leida)){

        Parser parser(linea_leida);
        Material* material_leido = parser.procesar_entrada_material();
        lista_materiales.alta(material_leido, this->cantidad_materiales); // medio cabeza pero los voy metiendo todos al ppio (pila xd)
        this ->cantidad_materiales++;
        
    }
}


// ------------------------------------------------------------------------------------------------------------


Inventario::~Inventario(){
    
    for (int i = 0 ; i < cantidad_materiales ; ++i){
        delete lista_materiales.consulta(i);
        // lista_materiales.consulta(i) == nullptr; value computed is not used [-Werror=unused-value]
    }

}


// ------------------------------------------------------------------------------------------------------------


void Inventario::mostrar_inventario(){
    for(int i = 0 ; i < cantidad_materiales ; ++i)
        cout << "> " << lista_materiales.consulta(i) -> obtener_tipo_material() << ": " << 
        lista_materiales.consulta(i) -> obtener_cantidad() << endl;

}

// ------------------------------------------------------------------------------------------------------------

int Inventario::ubicacion_material_en_lista(char identificador){
    int i = 0;
    int ubicacion = -1;
    bool material_encontrado = false;

    while(i < cantidad_materiales && !material_encontrado ){
        if(lista_materiales.consulta(i) -> obtener_identificador() == identificador){
            ubicacion = i;
            material_encontrado = true;
        }
        ++i;
    }

    return ubicacion;
}

// ------------------------------------------------------------------------------------------------------------

double Inventario::obtener_cantidad_de_piedra(){
    
    int ubicacion_material;
    ubicacion_material = ubicacion_material_en_lista(IDENTIF_PIEDRA);

    return lista_materiales.consulta(ubicacion_material) -> obtener_cantidad();
}

// ------------------------------------------------------------------------------------------------------------

double Inventario::obtener_cantidad_de_madera(){
   
    int ubicacion_material;
    ubicacion_material = ubicacion_material_en_lista(IDENTIF_MADERA);

    return lista_materiales.consulta(ubicacion_material) -> obtener_cantidad();
}

// ------------------------------------------------------------------------------------------------------------


double Inventario::obtener_cantidad_de_metal(){
    
    int ubicacion_material;
    ubicacion_material = ubicacion_material_en_lista(IDENTIF_METAL);

    return lista_materiales.consulta(ubicacion_material) -> obtener_cantidad();
}


// ------------------------------------------------------------------------------------------------------------


void Inventario::restar_cantidad_materiales_construccion(double costo_piedra, double costo_madera, double costo_metal){
    int ubicacion_piedra, ubicacion_madera, ubicacion_metal;

    ubicacion_piedra = ubicacion_material_en_lista(IDENTIF_PIEDRA);
    ubicacion_madera = ubicacion_material_en_lista(IDENTIF_MADERA);
    ubicacion_metal = ubicacion_material_en_lista(IDENTIF_METAL);

    lista_materiales.consulta(ubicacion_piedra) -> restar_cantidad(costo_piedra);
    lista_materiales.consulta(ubicacion_madera) -> restar_cantidad(costo_madera);
    lista_materiales.consulta(ubicacion_metal) -> restar_cantidad(costo_metal);

}


// ------------------------------------------------------------------------------------------------------------


void Inventario::sumar_cantidad_materiales_construccion(double costo_piedra, double costo_madera, double costo_metal){
    int ubicacion_piedra, ubicacion_madera, ubicacion_metal;

    ubicacion_piedra = ubicacion_material_en_lista(IDENTIF_PIEDRA);
    ubicacion_madera = ubicacion_material_en_lista(IDENTIF_MADERA);
    ubicacion_metal = ubicacion_material_en_lista(IDENTIF_METAL);

    lista_materiales.consulta(ubicacion_piedra) -> sumar_cantidad(costo_piedra);
    lista_materiales.consulta(ubicacion_madera) -> sumar_cantidad(costo_madera);
    lista_materiales.consulta(ubicacion_metal) -> sumar_cantidad(costo_metal);

}

// ------------------------------------------------------------------------------------------------------------

void Inventario::sumar_cantidad_material(char identificador, double cantidad){
    
    int ubicacion = ubicacion_material_en_lista(identificador);

    lista_materiales.consulta(ubicacion) -> sumar_cantidad(cantidad);
}