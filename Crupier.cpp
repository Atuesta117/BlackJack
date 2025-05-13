/**
* @file Crupier.cpp
* @brief Implementación de la clase Crupier para el juego de Blackjack.
*
* @details
* Este archivo implementa la clase Crupier, que representa al repartidor de cartas
* en un juego de Blackjack. El crupier administra su propia mano y actúa de acuerdo
* a las reglas típicas del juego.
*​
*
* @project Blackjack
* @course Fundamentos de Programación Orientada a Objetos (FPOO)
* @institution Universidad del Valle
*
* @authors* - Juan Jose Atuesta - atuesta.juan@correounivalle.edu.co
* - David Alejandro Garcia - david.grueso@correounivalle.edu.co
* - Sergio Garcia Ramos - sergio.garcia.ramos@correounivalle.edu.co
* - Paula Mariana Murillo - murillo.paula@correounivalle.edu.co
*
* @date Abril 2025
*/
#include "Crupier.h"
#include <iostream>
#include <string>
#include <vector>
#include "Jugador.h"
#include "Controlador.h"
using namespace std;

Crupier::Crupier(const string& _nombre, long _dinero, Mazo& _mazo_crupier): Controlador(_nombre, _dinero), mazo(_mazo_crupier) // Inicializa el mazo de cartas
{
	this-> nombre = "Crupier";
	this->dinero_total = _dinero; //representaria el dinero total de la casa
	this->apuesta = 0;
	this->valor_mano= 0;
	this->mano.clear(); // Inicializa la mano del crupier
	this->se_planta = false;
	this->esta_jugando = false; // El crupier no está jugando al inicio
	this->mazo.shuffle(); // Baraja el mazo de cartas al inicio
}

/*
void Crupier::obtener_mano()
{
	for (int i = 0; i < 2; i++)
	{
		Carta carta = mazo_crupier.get_carta();
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
		valor_mano+= mano[0].get_valor_carta() + mano[1].get_valor_carta();
	}
}
*/	

/*
void Crupier::obtener_carta(){
	Carta carta = mazo_crupier.get_carta();
	
	if(carta.get_rank_carta()== "A" && valor_mano_crupier+11 < 21){
		valor_mano_crupier += 11;
	}
	else if (carta.get_rank_carta()== "A" && valor_mano_crupier+11 > 21) {
		valor_mano_crupier +=1;
	}
	else{
		valor_mano_crupier += carta.get_valor_carta();
	}
	mano_crupier.push_back(carta);
}


bool Crupier::plantarse()
{

	if(valor_mano_crupier < 17){
		return false; // El crupier no se planta	
	}
	else{
		cout << "El crupier se planta." << endl;
		return true; // El crupier se planta
	}
}
*/

void Crupier::mostrar_mano_parcial()
{
	if(this->mano.size() == 2)
	{
		this->mano[0].display();// Muestra la primera carta del crupier
		cout << endl;
		cout << "Carta oculta del crupier." << endl; // Muestra la segunda carta como oculta
	}
	else{
		cout << "El crupier no tiene cartas." << endl;
	}
	
}

/*
void Crupier::mostrar_mano_completa()
{
	if(mano_crupier.size() > 0)
	{
		cout << "Mano Completa del crupier: " << endl;
		for (size_t i = 0; i < mano_crupier.size(); i++)
		{
			mano_crupier[i].display();
			cout << endl;
		}
	}
	else{
		cout << "El crupier no tiene cartas." << endl;
	}
	
}

int Crupier::contar_cartas() {
	int total = 0;
	for (size_t i = 0; i < mano_crupier.size(); i++)
	{
		total ++;
	}
	return total;
	
}

bool Crupier::verificar_blackjack()
{
	if (mano_crupier.size() == 2 && valor_mano_crupier == 21)  
		{ // Verifica si el crupier tiene exactamente 2 cartas y su valor es 21
			return true; // El crupier tiene blackjack
		}
	
	return false; // El crupier no tiene blackjack
}

*/
void Crupier::determinar_ganador(Jugador &jugador)
{
	int valor_mano_jugador = jugador.get_valor_mano(); // Calcular el valor de la mano del jugador
	
	//caso 1: El crupier se pasa y el jugador no
	if (this->valor_mano > 21 && valor_mano_jugador<=21) 
	{
		if(jugador.verificar_blackjack()) // Verifica si el jugador tiene blackjack
		{
			cout << "El jugador tiene blackjack. El jugador gana." << endl;
			jugador.set_dinero(jugador.get_apuesta() + jugador.get_apuesta() * 1.5); //Al jugador se le devuelven su apuesta y se le da el valor de su apuesta por 1.5.
			//Este es el famoso 3 a 2, que es el pago del blackjack.
		}
		else 
		{
			cout << "El crupier se ha pasado. El jugador gana." << endl;
			jugador.set_dinero(2*jugador.get_apuesta()); // El jugador gana su apuesta (1:1)
		}
	} 
	
	//caso 2: El jugador se pasa y el crupier no
	else if (valor_mano_jugador > 21 && valor_mano <= 21) 
	{
		cout << "El jugador se ha pasado. El Crupier gana." << endl;
		set_dinero(apuesta + jugador.get_apuesta()); // El crupier gana su apuesta. La casa gana 1:1
			
	} 
	
	//caso 3: ambos se pasan de 21
	else if ((valor_mano > 21 && valor_mano > 21)) 
	{
		cout << "Ambos se han pasado de 21. Tenemos un empate." << endl;
		jugador.set_dinero(jugador.get_apuesta()); // El jugador recupera su apuesta
	}
	//caso 4: ambos tienen blackjack
	else if (valor_mano == 21 && valor_mano_jugador == 21) 
	{
		cout << "Ambos tienen blackjack. Tenemos un empate." << endl;
        jugador.set_dinero(jugador.get_apuesta()); // El jugador recupera su apuesta
	}
	// caso 5 el crupier y jugador sacan el mismo puntaje 
	else if((valor_mano == valor_mano_jugador)){
		cout<< "Ambos sacaron el mismo puntaje. Tenemos un empate." << endl;
		jugador.set_dinero(jugador.get_apuesta()); // El jugador recupera su apuesta

	} //caso 5: el crupier es mayor que el jugador y  el crupies es menor o igual que 21
	else if (valor_mano > valor_mano_jugador && valor_mano <= 21) 
	{
		cout << "El Crupier gana." << endl;
		set_dinero(apuesta+jugador.get_apuesta()); // al crupier se le devuelve su apuesta "implicita" y se le suma la apuesta del jugador.
	} 
	// caso 6: el jugador es mayor que el crupier y el jugador es menor o igual que 21
	else if(valor_mano_jugador > valor_mano && valor_mano_jugador <= 21)
	{
		if(jugador.verificar_blackjack()) // Verifica si el jugador tiene blackjack
		{
			cout << "El jugador tiene blackjack. El jugador gana." << endl;
			jugador.set_dinero(jugador.get_apuesta()+ jugador.get_apuesta()* 1.5); //EL jugador gana 1.5 veces su apuesta.
		}
		else 
		{
			cout << "El Jugador gana." << endl;
			jugador.set_dinero(jugador.get_apuesta()+jugador.get_apuesta()); // El crupier gana su apuesta (1:1)
		}
	} 	
}

//setter
/*
long Crupier::set_dinero_crupier(const long _cantidad_depositar){
	this->dinero_total_crupier += _cantidad_depositar;
	this->return this->dinero_total_crupithis->ethis->this->mano.clear(); // Inicializa la mano del crupierCrupier::reiniciar_mano()
{
	mano_crupier.clear(); // Limpia la mano del crupier
	valor_mano_crupier = 0; // Reinicia el valor de la mano del crupier
    apuesta_crupier = 0; // Reinicia la apuesta del crupier
}	
*/
void Crupier::apostar(Jugador& jugador) {
	apuesta = jugador.get_apuesta();
	this->dinero_total -= apuesta; // Inicializa la mano del crupierCrupier::jugar_turno(Mazo& mazo){
	while(valor_mano < 17) // El crupier pide cartas hasta que su mano sea 17 o más
			{
				cout<<"---------------------------------------------------"<<endl;
				cout << "El crupier pide otra carta." << endl;
				pedir_carta(this->mazo); // El crupier obtiene una carta del mazo
				mostrar_mano();
				cout << "Valor de la mano del crupier: " << get_valor_mano() << endl; 
			}
	plantarse();
}

