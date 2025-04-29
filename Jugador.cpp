#include <iostream>
#include <string>
#include <vector>
#include "Jugador.h"
#include "Mazo.h"
#include "Carta.h"
using namespace std;

Jugador::Jugador(const string& _nombre, int _dinero) {
	nombre = _nombre;
	dinero_total_jugador = _dinero;
	apuesta_jugador = 0;
	valor_mano_jugador = 0;
	estado_jugador = true; // El jugador inicia en juego
}

bool Jugador::iniciar_partida(){
	estado_jugador = true;
	return estado_jugador;
}

bool Jugador::terminar_partida(){
	estado_jugador = false;
	return estado_jugador;
}

//acciones

void Jugador::pedir_mano(Mazo& mazo){
	for(int i = 0 ; i<2; i++){
		Carta carta = mazo.get_carta();
		mano.push_back(carta);
	}
	if(mano[0].get_rank_carta()=="A" && mano[1].get_rank_carta() != "A"){
		valor_mano_jugador += 11 + mano[1].get_valor_carta();
	}
	else if (mano[1].get_rank_carta()=="A" && mano[0].get_rank_carta() != "A"){
		valor_mano_jugador += 11+mano[0].get_valor_carta();

	}
	else if (mano[0].get_rank_carta() == "A" && mano[1].get_rank_carta() == "A" ) {
		valor_mano_jugador += 1+mano[1].get_valor_carta();
	}
	else{
		valor_mano_jugador += mano[0].get_valor_carta() + mano[1].get_valor_carta();
	}
	
	
}

void Jugador::pedir_carta(Mazo &mazo) {
	Carta carta = mazo.get_carta();
	if(carta.get_rank_carta()== "A" && valor_mano_jugador+11 < 21){
		valor_mano_jugador += 11;
	}
	else if (carta.get_rank_carta()== "A" && valor_mano_jugador+11 > 21) {
		valor_mano_jugador +=1;
	}
	else{
		valor_mano_jugador += carta.get_valor_carta();
	}
	mano.push_back(carta);
}

bool Jugador::plantarse(){
	return true;
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

void Jugador::apostar(long _apuesta) {
	apuesta_jugador = _apuesta;
	dinero_total_jugador -= apuesta_jugador;
}

//setter
long Jugador::set_dinero (const long _cantidad_depositar){
	dinero_total_jugador += _cantidad_depositar;
	return dinero_total_jugador;
}

//getter
/*
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
*/

//verificacion blackjack
bool Jugador::verificar_blackjack() {
	if (mano.size() == 2 && valor_mano_jugador == 21) {
		
		//lo comento porque probablemente no sea lo mejor, modificar todo el dinero total del jugador en esta funcion
		//dinero_total += apuesta * 1.5; // El jugador gana 1.5 veces su apuesta
		//apuesta = 0; // Se restablece la apuesta
		return true; // El jugador tiene blackjack
	}
	return false; // El jugador no tiene blackjack
}

void Jugador::reiniciar_mano() {
	mano.clear(); // Limpia el vector de cartas del jugador
	valor_mano_jugador = 0; // Reinicia el valor de la mano
    apuesta_jugador = 0; // Reinicia la apuesta del jugador
}

