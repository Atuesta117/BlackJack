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
#include "Jugador.h"
#include "Crupier.h"
using namespace std;

Controlador::Controlador(const string& _nombre, int _dinero) {
	this->nombre = _nombre;
	this->dinero_total = _dinero;
	this->apuesta = 0;
	this->valor_mano= 0;
	this->esta_jugando = false; // El Controlador inicia en juego
	this->se_planta = false; // El Controlador no se ha plantado al inicio
	this->mano.clear(); // Inicializa la mano del Controlador
}


void Controlador::iniciar_partida(){
	this->esta_jugando = true;
	
}

void Controlador::terminar_partida(){
	this->esta_jugando = false;
	
}

//acciones

void Controlador::pedir_mano(Mazo& mazo){
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
		this->valor_mano += 1+mano[1].get_valor_carta();
	}
	else{
		this->valor_mano += mano[0].get_valor_carta() + mano[1].get_valor_carta();
	}
	
	
}

void Controlador::pedir_carta(Mazo &mazo) {
	Carta carta = mazo.get_carta();
	int contador=0;
	for (size_t i = 0; i < mano.size(); i++)
	{
		if(mano[i].get_rank_carta()=="A"){
			contador++;
			break;
		}
	}
	
	if(carta.get_rank_carta()== "A" && valor_mano+11 < 21){
		valor_mano += 11;
	}
	else if (carta.get_rank_carta()== "A" && this->valor_mano+11 > 21) {
		valor_mano +=1;
	}
	else if(contador == 1 && carta.get_valor_carta()+ valor_mano >21){
		valor_mano += -10 ;
	}
	else{
		valor_mano += carta.get_valor_carta();
	}
	mano.push_back(carta);
}

bool Controlador::plantarse(){
	this->se_planta = true; // El Controlador se planta
	return this->se_planta;
}
/*
void Controlador::mostrar_mano(){
	cout << "Mano del : " << endl;
	for (size_t i = 0; i < mano.size(); i++)
	{
		this->mano[i].display();
		cout<<endl;
	}
	
}
*/

int Controlador::contar_cartas() {
	int total = 0;
	for (size_t i = 0; i < mano.size(); i++)
	{
		total ++;
	}
	return total;
	
}

void Controlador::apostar(long _apuesta) {
	this->apuesta = _apuesta;
	this->dinero_total -= apuesta; // Resta la apuesta del dinero total del Controlador
}

//setter

long Controlador::set_dinero (const long _cantidad_depositar){
	this->dinero_total+= _cantidad_depositar;
	return this->dinero_total;
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
	if (mano.size() == 2 && this->valor_mano == 21) {
		
		//lo comento porque probablemente no sea lo mejor, modificar todo el dinero total del Controlador en esta funcion
		//this->dinero_total += apuesta * 1.5; // El Controlador gana 1.5 veces su apuesta
		//apuesta = 0; // Se restablece la apuesta
		return true; // El Controlador tiene blackjack
	}
	return false; // El Controlador no tiene blackjack
}

void Controlador::reiniciar_valores() {
	this->mano.clear(); // Limpia el vector de cartas del Controlador
	this->valor_mano = 0; // Reinicia el valor de la mano
    this->apuesta = 0; // Reinicia la apuesta del Controlador
	this->se_planta = false; // Reinicia el estado de plantarse

}
