/**
* @file Carta.cpp
* @brief Implementación de la clase Carta para el juego de Blackjack.
*
* @details
* Este archivo define la clase Carta, que representa una carta individual con un
* palo y un valor en un juego de Blackjack. Cada carta puede mostrar su nombre
* y valor correspondiente.
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
using namespace std;
#include "Carta.h"
#include <string>

Carta::Carta(string casta, string rank, int valor){
    this->casta = casta;
    this->rank = rank;
    this->valor = valor;
}
string Carta::get_casta_carta(){
    return casta;
}
int Carta::get_valor_carta(){
    return valor;
}
string Carta::get_rank_carta(){
    return rank;
}
void Carta::display(){
    cout << "Casta: " << casta << ", rank: " << rank << ", Valor: " << valor << endl;
}