/**
* @file Controlador.cpp
* @brief Implementación de la clase Controlador para el juego de Blackjack.
*
* @details
* Este archivo implementa la clase Controlador, que representa a un Controlador
* humano en un juego de Blackjack. El Controlador administra su mano de cartas
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
#include "Controlador.h"
#include "Mazo.h"
#include "Carta.h"
using namespace std;

Controlador::Controlador(const string& _nombre, int _dinero) {
	nombre = _nombre;
	dinero_total = _dinero;
	apuesta = 0;
	valor_mano= 0;
	esta_jugando = true; // El Controlador inicia en juego
}
Controlador::~Controlador(){}

bool Controlador::iniciar_partida(){
	esta_jugando = true;
	return esta_jugando;
}

bool Controlador::terminar_partida(){
	esta_jugando = false;
	return esta_jugando;
}

//acciones

void Controlador::pedir_mano(Mazo& mazo){
	for(int i = 0 ; i<2; i++){
		Carta carta = mazo.get_carta();
		mano.push_back(carta);
	}
	if(mano[0].get_rank_carta()=="A" && mano[1].get_rank_carta() != "A"){
		valor_mano += 11 + mano[1].get_valor_carta();
	}
	else if (mano[1].get_rank_carta()=="A" && mano[0].get_rank_carta() != "A"){
		valor_mano += 11+mano[0].get_valor_carta();

	}
	else if (mano[0].get_rank_carta() == "A" && mano[1].get_rank_carta() == "A" ) {
		valor_mano += 1+mano[1].get_valor_carta();
	}
	else{
		valor_mano += mano[0].get_valor_carta() + mano[1].get_valor_carta();
	}
	
	
}

void Controlador::pedir_carta(Mazo &mazo) {
	Carta carta = mazo.get_carta();
	if(carta.get_rank_carta()== "A" && valor_mano+11 < 21){
		valor_mano += 11;
	}
	else if (carta.get_rank_carta()== "A" && valor_mano+11 > 21) {
		valor_mano +=1;
	}
	else{
		valor_mano += carta.get_valor_carta();
	}
	mano.push_back(carta);
}

bool Controlador::plantarse(){
	se_planta = true; // El Controlador se planta
	return se_planta;
}

void Controlador::mostrar_mano(){
	cout << "Mano del Controlador: " << endl;
	for (size_t i = 0; i < mano.size(); i++)
	{
		mano[i].display();
		cout<<endl;
	}
	
}

int Controlador::contar_cartas() {
	int total = 0;
	for (size_t i = 0; i < mano.size(); i++)
	{
		total ++;
	}
	return total;
	
}

void Controlador::apostar(long _apuesta) {
	apuesta = _apuesta;
	dinero_total -= apuesta; // Resta la apuesta del dinero total del Controlador
}

//setter

long Controlador::set_dinero (const long _cantidad_depositar){
	dinero_total+= _cantidad_depositar;
	return dinero_total;
}
	


//getter
/*
int Controlador::calcular_valor_mano_Controlador(){

	for (size_t i = 0; i < mano.size(); i++)
	{
		valor_mano_Controlador += mano[i].get_valor_carta();
		
	}

	if(valor_mano_Controlador > 21){
		for (size_t i = 0; i < mano.size(); i++)
		{
			if (mano[i].get_rank_carta() == "A") {
				valor_mano_Controlador -= 10; // Si el Controlador tiene un As y su mano supera 21, se le resta 10 al valor total
			}
			break; // Salimos del bucle una vez que hemos ajustado el valor del As
		}
	}
	return valor_mano_Controlador;
}
*/

//verificacion blackjack
bool Controlador::verificar_blackjack() {
	if (mano.size() == 2 && valor_mano == 21) {
		
		//lo comento porque probablemente no sea lo mejor, modificar todo el dinero total del Controlador en esta funcion
		//dinero_total += apuesta * 1.5; // El Controlador gana 1.5 veces su apuesta
		//apuesta = 0; // Se restablece la apuesta
		return true; // El Controlador tiene blackjack
	}
	return false; // El Controlador no tiene blackjack
}

void Controlador::reiniciar_mano() {
	mano.clear(); // Limpia el vector de cartas del Controlador
	valor_mano = 0; // Reinicia el valor de la mano
    apuesta = 0; // Reinicia la apuesta del Controlador
}

void Controlador::jugar_turno(){
    cout << "Easter egg, este metodo en esta clase realmente no se va a usar";
}