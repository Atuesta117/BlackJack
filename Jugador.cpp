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

Jugador::Jugador(const string& _nombre, int _dinero):Controlador(_nombre, _dinero){
	this->nombre = _nombre;
	this->dinero_total = _dinero;
	this->apuesta = 0;
	this->valor_mano= 0;
	this->esta_jugando = true; // El jugador inicia en juego
	this->se_planta = false;
}



void Jugador::apostar(long _apuesta) {
	this->apuesta = _apuesta;
	this->dinero_total -= this->apuesta; // Resta la apuesta del dinero total del jugador
}

void Jugador::set_nombre(string nombre){
	this->nombre == nombre;
}
/*
void Jugador::jugar_turno(Mazo& mazo){
	
}


void Jugador::mostrar_mano(){
	
	
}
// por ahora las pongo vacias pero tengo que eliminar estass funciones de controlador 
*/