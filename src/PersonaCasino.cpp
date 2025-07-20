/**
* @file PersonaCasino.cpp
* @brief Implementación de la clase PersonaCasino para el juego de Blackjack.
*
* @details
* Este archivo implementa la clase PersonaCasino, que representa a un PersonaCasino
* humano en un juego de Blackjack. El PersonaCasino administra su mano de cartas
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
#include "PersonaCasino.h"
#include "Mazo.h"
#include "Carta.h"
#include "Jugador.h"
#include "Crupier.h"
using namespace std;

PersonaCasino::PersonaCasino(const string& _nombre) {
	this->nombre = _nombre;
	this->valor_mano= 0;
	this->esta_jugando = false; // El PersonaCasino inicia en juego
	this->se_planta = false; // El PersonaCasino no se ha plantado al inicio
	this->mano.clear(); // Inicializa la mano del PersonaCasino
	this->contador_as = 0;
}


void PersonaCasino::iniciar_partida(){
	this->esta_jugando = true;
	
}

void PersonaCasino::terminar_partida(){
	this->esta_jugando = false;
	
}

//acciones

void PersonaCasino::pedir_mano(Mazo& mazo){
	for(int i = 0 ; i<2; i++){
		Carta carta = mazo.get_carta();
		mano.push_back(carta);
	}
	if(mano[0].get_rank_carta()=="A" && mano[1].get_rank_carta() != "A"){
		this->valor_mano += 11 + mano[1].get_valor_carta();
	}
	else if (mano[1].get_rank_carta()=="A" && mano[0].get_rank_carta() != "A"){
		this->valor_mano += 11+mano[0].get_valor_carta();

	}
	else if (mano[0].get_rank_carta() == "A" && mano[1].get_rank_carta() == "A" ) {
		contador_as++;
		this->valor_mano += 1+mano[1].get_valor_carta();
	}
	else{
		this->valor_mano += mano[0].get_valor_carta() + mano[1].get_valor_carta();
	}
	
	
}

void PersonaCasino::pedir_carta(Mazo &mazo) {
	Carta carta = mazo.get_carta();
	this->valor_mano += carta.get_valor_carta();
	this->mano.push_back(carta);
	int contador =0;
	for (size_t i = 0; i < mano.size(); i++)
	{
		if(this->mano[i].get_rank_carta()== "A"){
			contador++;
		}
	}
	if(this->contador_as != contador){
		if(this->valor_mano > 21){
			this->valor_mano += -10;
			this->contador_as++;
		}
	}
	else{	
		cout << this->contador_as<<endl<<contador;
	}

}

bool PersonaCasino::plantarse(){
	this->se_planta = true; // El PersonaCasino se planta
	return this->se_planta;
}






//setter

long PersonaCasino::set_dinero (const long _cantidad_depositar){
	this->dinero_total+= _cantidad_depositar;
	return this->dinero_total;
}
	


//verificacion blackjack
bool PersonaCasino::verificar_blackjack() {
	if (mano.size() == 2 && this->valor_mano == 21) {
		
		return true; // El PersonaCasino tiene blackjack
	}
	return false; // El PersonaCasino no tiene blackjack
}



