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
/*
bool Jugador::iniciar_partida(){
	esta_jugando = true;
	return esta_jugando;
}

bool Jugador::terminar_partida(){
	esta_jugando = false;
	return esta_jugando;
}

//acciones

void Jugador::pedir_mano(Mazo& mazo){
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

void Jugador::pedir_carta(Mazo &mazo) {
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

bool Jugador::plantarse(){
	se_planta = true; // El jugador se planta
	return se_planta;
}

void Jugador::mostrar_mano(){
	cout << "Mano del jugador: " << endl;
	for (size_t i = 0; i < mano.size(); i++)
	{
		mano[i].display();
		cout<<endl;
	}
	
}

int Jugador::contar_cartas() {
	int total = 0;
	for (size_t i = 0; i < mano.size(); i++)
	{
		total ++;
	}
	return total;
	
}
*/

void Jugador::apostar(long _apuesta) {
	this->apuesta = _apuesta;
	this->dinero_total -= this->apuesta; // Resta la apuesta del dinero total del jugador
}
/*
//setter

long Jugador::set_dinero (const long _cantidad_depositar){
	dinero_total+= _cantidad_depositar;
	return dinero_total;
}
	


//getter

int Jugador::calcular_valor_mano_jugador(){

	for (size_t i = 0; i < mano.size(); i++)
	{
		valor_mano_jugador += mano[i].get_valor_carta();
		
	}

	if(valor_mano_jugador > 21){
		for (size_t i = 0; i < mano.size(); i++)
		{
			if (mano[i].get_rank_carta() == "A") {
				valor_mano_jugador -= 10; // Si el jugador tiene un As y su mano supera 21, se le resta 10 al valor total
			}
			break; // Salimos del bucle una vez que hemos ajustado el valor del As
		}
	}
	return valor_mano_jugador;
}


//verificacion blackjack
bool Jugador::verificar_blackjack() {
	if (mano.size() == 2 && valor_mano == 21) {
		
		//lo comento porque probablemente no sea lo mejor, modificar todo el dinero total del jugador en esta funcion
		//dinero_total += apuesta * 1.5; // El jugador gana 1.5 veces su apuesta
		//apuesta = 0; // Se restablece la apuesta
		return true; // El jugador tiene blackjack
	}
	return false; // El jugador no tiene blackjack
}

void Jugador::reiniciar_mano() {
	mano.clear(); // Limpia el vector de cartas del jugador
	valor_mano = 0; // Reinicia el valor de la mano
    apuesta = 0; // Reinicia la apuesta del jugador
}

*/

void Jugador::jugar_turno(Mazo& mazo){
	if(verificar_blackjack()){
		plantarse(); // Si el jugador tiene blackjack, se planta automáticamente
		cout << "¡Tienes blackjack! Fin de tu turno." << endl;
	}

	while (se_planta == false)
			{
				string opc_jugador;
				cout<< "Acciones disponibles: " << endl;
				cout<< "1. Pedir carta" << endl;
				cout<< "2. Plantarse" << endl;
				cout<< "3. Ver mano" << endl;
				cout<< "4. Ver el valor de la mano" << endl;
				cin >> opc_jugador;
				if (opc_jugador == "1")
				{
					pedir_carta(mazo); // El jugador pide otra carta
					mostrar_mano(); // Muestra la mano del jugador
					cout << "Valor de la mano del jugador "<< get_nombre()<< ":" << get_valor_mano() << endl; // Muestra el valor de la mano del jugador
					cout << endl;
					if(get_valor_mano() >= 21){
						if(get_valor_mano() > 21) {
							cout << "¡Te has pasado de 21! Fin de tu turno." << endl;
						} else {
							cout << "¡Tienes 21! Fin de tu turno." << endl;
						}
						plantarse(); // Cambia el controlador a false para salir del bucle
					}
				}
				else if (opc_jugador == "2")
				{
					plantarse(); // El jugador se planta
				}
				else if (opc_jugador == "3")
				{
					mostrar_mano(); // Muestra la mano del jugador
				}
				else if (opc_jugador == "4")
				{
					cout << "Valor de la mano del jugador " << this->nombre<< ":" << this->valor_mano << endl; // Muestra el valor de la mano del jugador
				}
				else{
					cout<< "Opción inválida. Por favor, ingrese una opción válida."<<endl;
				



			}
		}
}

void Jugador::mostrar_mano(){
	cout << "Mano del jugador "<< this->nombre<<":" << endl;
	for (size_t i = 0; i < mano.size(); i++)
	{
		mano[i].display();
		cout<<endl;
	}
	
}