/**
* @file Jugador.cpp
* @brief Implementación de la clase Jugador para el juego de Blackjack.
*
* @details
* Este archivo implementa la clase Jugador, que representa a un jugador
* humano en un juego de Blackjack. El jugador administra su mano de cartas
* y decide sus acciones durante el transcurso del juego.
*
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
* @date Abril 2025
*/
#include <iostream>
#include <string>
#include <vector>
#include "Jugador.h"
#include "Mazo.h"
#include "Carta.h"
using namespace std;
#include "PersonaCasino.h"

#include <algorithm>
#include <cctype>
#include <string>

string aMayusculas(std::string texto) {
    
	transform(texto.begin(), texto.end(), texto.begin(),
        [](unsigned char c){ return std::toupper(c); });
    return texto;
}
Jugador::Jugador(const string& _nombre, long _dinero):PersonaCasino(_nombre){
	this->nombre = aMayusculas(_nombre);
	this->dinero_total = _dinero;
	this->apuesta = 0;
	this->valor_mano= 0;
	this->se_planta = false;
	this->esta_jugando= false;
	this->contador_as =0;
}



void Jugador::apostar(long _apuesta) {
	this->apuesta = _apuesta;
	this->dinero_total -= this->apuesta; // Resta la apuesta del dinero total del jugador
}

void Jugador::reiniciar_valores(){
	this->mano.clear(); // Limpia el vector de cartas del PersonaCasino
	this->valor_mano = 0; // Reinicia el valor de la mano
	this->se_planta = false; // Reinicia el estado de plantarse
	this->contador_as =	 0;
	this->apuesta=0;
}


long Jugador::set_dinero (const long _cantidad_depositar){
	this->dinero_total+= _cantidad_depositar;
	return this->dinero_total;
}
	