/*
	Clase: 	Mazo
	Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
	Universidad del Valle

	Información CRC:

	Clase: Mazo
	Responsabilidades:

	Gestionar un conjunto de cartas (crear mazo, barajarlo y entregar cartas).

	Colaboradores: Carta

	Autor: Juan Jose Atuesta, Sergio Garcia Ramos, Paula Mariana Huertas, David Alejandro Garcia 
	Correo: atuesta.juan@correounivalle.edu.co - sergio.garcia.ramos@correounivalle.edu.co - murillo.paula@correounivalle.edu.co - david.grueso@correounivalle.edu.co]
	Fecha: Abril 2025
  */
#ifndef MAZO_H
#define MAZO_H
#include <iostream>
#include <vector>
using namespace std;
#include "Carta.h"
#include <string>

class Mazo{
	private:
		vector<Carta> cartas;
		
	public:
		Mazo();
		vector <Carta> get_new_mazo();
		void shuffle();
		int get_cant_cartas();
		Carta get_carta();
};


#endif // MAZO_H