/**
* @file Mazo.cpp
* @brief Implementación de la clase Mazo para el juego de Blackjack.
*
* @details* Este archivo implementa la clase Mazo, que representa una colección de cartas
* utilizadas en el juego de Blackjack. El mazo permite barajar las cartas y
* repartirlas a los jugadores. El crupier tiene la libertad de sacar las cartas del mazo.
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
#include "Mazo.h"
#include <vector>
#include <algorithm>
#include <random>
#include <string>

Mazo::Mazo() {
    cartas = get_new_mazo();
    
}
vector<Carta> Mazo::get_new_mazo() {
    vector<Carta> new_mazo;
    string castas[] = {"♥", "♦", "♣", "♠"};
    string ranks[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    int valores[] = {11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};

    for (string casta : castas) {
        for (int i = 0; i < 13; i++) {
            new_mazo.push_back(Carta(casta, ranks[i], valores[i]));
        }

    }       
    return new_mazo;
}
void Mazo::shuffle() {
    auto rng = std::default_random_engine(static_cast<unsigned>(time(nullptr)));
    std::shuffle(cartas.begin(), cartas.end(), rng);
}
int Mazo::get_cant_cartas() {
    return cartas.size();
}
    

Carta Mazo::get_carta() {
    Carta carta = cartas.back();
    cartas.pop_back();
    return carta;
}
void Mazo::reunir_cartas(vector<Carta> cartas_jugador){
    for(Carta carta: cartas_jugador){
        cartas.push_back(carta);
    }
    cartas_jugador.clear();
}

