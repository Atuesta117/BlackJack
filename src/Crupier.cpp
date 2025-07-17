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
	this->contador_as =0;
}


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

string Crupier::determinar_ganador(Jugador* jugador) {
    int valor_mano_jugador = jugador->get_valor_mano();
    
    // Caso 1: El crupier se pasa y el jugador no
    if (this->valor_mano > 21 && valor_mano_jugador <= 21) {
        if (jugador->verificar_blackjack()) {
            jugador->set_dinero(jugador->get_apuesta() + jugador->get_apuesta() * 1.5);
            return "EL JUGADOR "+ jugador->get_nombre()+" BLACKJACK. EL JUGADOR GANA.";
        } else {
            jugador->set_dinero(2 * jugador->get_apuesta());
            return "EL CRUPIER SE HA PASADO. EL JUGADOR "+ jugador->get_nombre()+" GANA.";
        }
    } 
    // Caso 2: El jugador se pasa 
    else if (valor_mano_jugador > 21) {
        set_dinero(apuesta + jugador->get_apuesta());
        return "EL JUGADOR "+ jugador->get_nombre()+" SE HA PASADO. EL CRUPIER GANA.";
    } 
    // Caso 4: Ambos tienen blackjack
    else if (this->valor_mano == 21 && valor_mano_jugador == 21) {
        jugador->set_dinero(jugador->get_apuesta());
        return "EL CRUPIER Y "+ jugador->get_nombre()+" SACARON BLACKJACK. TENEMOS UN EMPATE.";
    }
    // Caso 5: Mismo puntaje
    else if (this->valor_mano == valor_mano_jugador && this->valor_mano <= 21) {
        jugador->set_dinero(jugador->get_apuesta());
        return "EL CRUPIER Y "+ jugador->get_nombre()+" TIENEN EL MISMO PUNTAJE. TENEMOS UN EMPATE.";
    } 
    // Caso 6: Crupier gana
    else if (this->valor_mano > valor_mano_jugador && this->valor_mano <= 21) {
        set_dinero(apuesta + jugador->get_apuesta());
        return "LA MANO DE "+ jugador->get_nombre()+" ES MENOR, EL CRUPIER GANA.";
    } 
    // Caso 7: Jugador gana
    else if (valor_mano_jugador > this->valor_mano && valor_mano_jugador <= 21) {
        if (jugador->verificar_blackjack()) {
            jugador->set_dinero(jugador->get_apuesta() + jugador->get_apuesta() * 1.5);
            return "EL JUGADOR "+ jugador->get_nombre()+" TIENE BLACKJACK. EL JUGADOR GANA.";
        } else {
            jugador->set_dinero(jugador->get_apuesta() + jugador->get_apuesta());
            return "EL JUGADOR "+ jugador->get_nombre()+" GANA.";
        }
    }

    // Caso no contemplado (¡nunca debería llegar aquí si la lógica es correcta!)
    return "ERROR: CASO NO PREVISTO EN determinar_ganador()";
}
void Crupier::apostar(long _apuesta) {
	this->apuesta = _apuesta;
	this->dinero_total -= apuesta; // Resta la apuesta del dinero total del crupier
}
