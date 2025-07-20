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
#include "PersonaCasino.h"
using namespace std;

Crupier::Crupier(const string& _nombre): PersonaCasino(_nombre) // Inicializa el mazo de cartas
{
	this-> nombre = "Crupier";
	this->valor_mano= 0;
	this->mano.clear(); // Inicializa la mano del crupier
	this->se_planta = false;
	this->esta_jugando = false; // El crupier no está jugando al inicio
	this->contador_as =0;
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

void Crupier::reiniciar_valores(){
	this->mano.clear(); // Limpia el vector de cartas del PersonaCasino
	this->valor_mano = 0; // Reinicia el valor de la mano
	this->se_planta = false; // Reinicia el estado de plantarse
	this->contador_as =	 0;
}
