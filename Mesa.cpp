#include "Mesa.h"
#include "Jugador.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
Mesa::Mesa() {
    this->mesa_activa = false;  // Inicializa la mesa como inactiva
    
}

bool Mesa::get_mesa_activa() {
    if(mesa.empty()){
        return false;
    }
    else {
        return true;
    }
    }

vector<Jugador*> Mesa::get_jugadores(){

    return mesa;
    
}

bool Mesa::mesa_llena(){
    if(mesa.size()==5){
        return true;
    }
    else{
        return false;
    }
}

void Mesa::agregar_jugador(Jugador* jugador, Controlador* controlador){
	mesa.push_back(jugador);
    objetos_padre.push_back(controlador);
}


void Mesa::eliminar_jugador(int index){
    index--;
    delete mesa[index];
    mesa[index] = nullptr;
    mesa.erase(mesa.begin()+ index);  
}

void Mesa::repartir_cartas(Mazo& mazo) {
    for (Jugador* jugador : mesa) {
        if (jugador->get_esta_jugando()) {
            jugador->pedir_mano(mazo); // Reparte cartas a cada jugador activo
        }
    }
}

void Mesa::eliminar_todos_jugadores(){
    for(int i =1; i<= mesa.size(); i++){
        eliminar_jugador(i);
    }
}