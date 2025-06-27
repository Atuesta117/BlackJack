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
	this->contador_as = 0;
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
		contador_as++;
		this->valor_mano += 1+mano[1].get_valor_carta();
	}
	else{
		this->valor_mano += mano[0].get_valor_carta() + mano[1].get_valor_carta();
	}
	
	
}

void Controlador::pedir_carta(Mazo &mazo) {
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
		cout <<"en efecto son diferentes";
		cout << this->contador_as<<endl<<contador;
		if(this->valor_mano > 21){
			this->valor_mano += -10;
			this->contador_as++;
		}
	}
	else{
		cout <<"son iguales";
		cout << this->contador_as<<endl<<contador;
	}
	/*
	Idea: hay un conetador de as y un atributo que me dice cuantas as hay en mi mano
	AHora, se aumenta el valor de la carta primero, y luego se recorre el vector buscando la cantidad
	de as que hay en la mano actual (obiamente primero se anexa la nueva carta). AHora bien si 
	hay al menos una carta que sea ass entonces se compara con el contador de as, si son diferentes quiere decir
	que hay un as que no se ha convertido en 1, entonces se evalua el caso para ver si se debe de convertir en 1, y si es asi
	entonces al contador de as se le aumenta 1, de esta manera, la cantidad de ases y el contador va a ser igual
	y si es igual entonces no se hace el proceso de cambiar el valor de la carta, si se pide una nueva carta entonces 
	la cantidad de cartas cambiariaria con respecto al contador y ahi se evqalua si es necesario cambiar su valor a 1
	de lo contraro simplemente se deja el valor sumadp.
	*/

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
	this->contador_as =	 0;
	cout << "se hizo con exito";
}

