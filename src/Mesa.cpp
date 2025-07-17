/**
* @file Mesa.cpp
* @brief Implementación de la clase Mesa para el juego de Blackjack.
*
* @details
* Esta clase lo que permite es representar una mesa de blackjack, permite que hayan desde 1 hasta 5 jugadores 
* en la mesa jugando. 
*
* @project Blackjack
* @course Fundamentos de Programación Orientada a Objetos (FPOO)
* @institution Universidad del Valle
*
* @authors
* - Juan Jose Atuesta - atuesta.juan@correounivalle.edu.co
* - David Alejandro Garcia - david.grueso@correounivalle.edu.co
* - Sergio Garcia Ramos - sergio.garcia.ramos@correounivalle.edu.co
* - Paula Mariana Murillo - murillo.paula@correounivalle.edu.co
*
* @date Julio 2025
*/
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