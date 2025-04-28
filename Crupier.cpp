#include "Crupier.h"
#include <iostream>
using namespace std;

Crupier::Crupier(long _dinero_total_crupier, Mazo& _mazo_crupier): mazo_crupier(_mazo_crupier)  // Inicializa el mazo de cartas
{
	dinero_total_crupier = _dinero_total_crupier; //representaria el dinero total de la casa
	apuesta_crupier = 0;
	valor_mano_crupier = 0;
	mano_crupier.clear();
}


void Crupier::obtener_mano()
{
	for (int i = 0; i < 2; i++)
	{
		Carta carta = mazo_crupier.get_carta();
		mano_crupier.push_back(carta);
	}
	if(mano_crupier[0].get_rank_carta()=="A" && mano_crupier[1].get_rank_carta() != "A"){
		valor_mano_crupier += 11 + mano_crupier[1].get_valor_carta();
	}
	else if (mano_crupier[1].get_rank_carta()=="A" && mano_crupier[0].get_rank_carta() != "A"){
		valor_mano_crupier += 11+mano_crupier[0].get_valor_carta();

	}
	else if (mano_crupier[0].get_rank_carta() == "A" && mano_crupier[1].get_rank_carta() == "A" ) {
		valor_mano_crupier += 1+mano_crupier[1].get_valor_carta();
	}
	else{
		valor_mano_crupier += mano_crupier[0].get_valor_carta() + mano_crupier[1].get_valor_carta();
	}
}
	

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

void Crupier::mostrar_mano_parcial()
{
	if(mano_crupier.size() == 2)
	{
		mano_crupier[0].display();// Muestra la primera carta del crupier
		cout << endl;
		cout << "Carta oculta del crupier." << endl; // Muestra la segunda carta como oculta
	}
	else{
		cout << "El crupier no tiene cartas." << endl;
	}
	
}

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

/*
int Crupier::calcular_valor_mano() {
	
	for (size_t i = 0; i < mano_crupier.size(); i++)
	{
		valor_mano_crupier += mano_crupier[i].get_valor_carta();
		
	}

	if(valor_mano_crupier > 21){
		for (size_t i = 0; i < mano_crupier.size(); i++)
		{
			if (mano_crupier[i].get_rank_carta() == "A") {
				valor_mano_crupier -= 10; // Si el jugador tiene un As y su mano supera 21, se le resta 10 al valor total
			}
			break; // Salimos del bucle una vez que hemos ajustado el valor del As
		}
	}
	return valor_mano_crupier;
}
*/
void Crupier::determinar_ganador(Jugador &jugador)
{
	int valor_mano_jugador = jugador.get_valor_mano_jugador(); // Calcular el valor de la mano del jugador
	
	//caso 1: El crupier se pasa y el jugador no
	if (valor_mano_crupier > 21 && valor_mano_jugador<=21) 
	{
		if(jugador.verificar_blackjack()) // Verifica si el jugador tiene blackjack
		{
			cout << "El jugador tiene blackjack. El jugador gana." << endl;
			jugador.set_dinero(jugador.get_apuesta_jugador() + jugador.get_apuesta_jugador() * 1.5); //Al jugador se le devuelven su apuesta y se le da el valor de su apuesta por 1.5.
			//Este es el famoso 3 a 2, que es el pago del blackjack.
		}
		else 
		{
			cout << "El crupier se ha pasado. El jugador gana." << endl;
			jugador.set_dinero(2*jugador.get_apuesta_jugador()); // El jugador gana su apuesta (1:1)
		}
	} 
	
	//caso 2: El jugador se pasa y el crupier no
	else if (valor_mano_jugador > 21 && valor_mano_crupier <= 21) 
	{
		cout << "El jugador se ha pasado. El Crupier gana." << endl;
		set_dinero_crupier(apuesta_crupier + jugador.get_apuesta_jugador()); // El crupier gana su apuesta. La casa gana 1:1
			
	} 
	
	//caso 3: ambos se pasan de 21
	else if ((valor_mano_crupier > 21 && valor_mano_jugador > 21)) 
	{
		cout << "Ambos se han pasado de 21. Tenemos un empate." << endl;
		jugador.set_dinero(jugador.get_apuesta_jugador()); // El jugador recupera su apuesta
	}
	//caso 4: ambos tienen blackjack
	else if (valor_mano_crupier == 21 && valor_mano_jugador == 21) 
	{
		cout << "Ambos tienen blackjack. Tenemos un empate." << endl;
        jugador.set_dinero(jugador.get_apuesta_jugador()); // El jugador recupera su apuesta
	}
	// caso 5 el crupier y jugador sacan el mismo puntaje 
	else if((valor_mano_crupier == valor_mano_jugador)){
		cout<< "Ambos sacaron el mismo puntaje. Tenemos un empate." << endl;
		jugador.set_dinero(jugador.get_apuesta_jugador()); // El jugador recupera su apuesta

	} //caso 5: el crupier es mayor que el jugador y  el crupies es menor o igual que 21
	else if (valor_mano_crupier > valor_mano_jugador && valor_mano_crupier <= 21) 
	{
		cout << "El Crupier gana." << endl;
		set_dinero_crupier(apuesta_crupier+jugador.get_apuesta_jugador()); // al crupier se le devuelve su apuesta "implicita" y se le suma la apuesta del jugador.
	} 
	// caso 6: el jugador es mayor que el crupier y el jugador es menor o igual que 21
	else if(valor_mano_jugador > valor_mano_crupier && valor_mano_jugador <= 21)
	{
		if(jugador.verificar_blackjack()) // Verifica si el jugador tiene blackjack
		{
			cout << "El jugador tiene blackjack. El jugador gana." << endl;
			jugador.set_dinero(jugador.get_apuesta_jugador()+ jugador.get_apuesta_jugador()* 1.5); //EL jugador gana 1.5 veces su apuesta.
		}
		else 
		{
			cout << "El Jugador gana." << endl;
			jugador.set_dinero(jugador.get_apuesta_jugador()+jugador.get_apuesta_jugador()); // El crupier gana su apuesta (1:1)
		}
	} 	
}

//setter

long Crupier::set_dinero_crupier(const long _cantidad_depositar){
	dinero_total_crupier += _cantidad_depositar;
	return dinero_total_crupier;
}


void Crupier::reiniciar_mano()
{
	mano_crupier.clear(); // Limpia la mano del crupier
	valor_mano_crupier = 0; // Reinicia el valor de la mano del crupier
    apuesta_crupier = 0; // Reinicia la apuesta del crupier
}	

void Crupier::apostar(long _apuesta) {
	apuesta_crupier = _apuesta;
	dinero_total_crupier -= apuesta_crupier;

}