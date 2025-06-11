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

void Mesa::agregar_jugador(Jugador* jugador){
	mesa.push_back(jugador);
}


void Mesa::eliminar_jugador(int index){
    for(int i = 0; i<5; i++){
        if(i == index){
            mesa.erase(mesa.begin() + index-1);
        }
    }   
}

void Mesa::repartir_cartas(Mazo& mazo) {
    for (Jugador* jugador : mesa) {
        if (jugador->get_esta_jugando()) {
            jugador->pedir_mano(mazo); // Reparte cartas a cada jugador activo
        }
    }
}