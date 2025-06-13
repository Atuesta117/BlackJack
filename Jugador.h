/*
	Clase: 	Jugador
	Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
	Universidad del Valle

	Información CRC:
	
	Clase: Jugador

	Responsabilidades:

	Administrar los datos de un jugador (nombre, dinero, mano de cartas).

	Realizar acciones del juego: apostar, pedir cartas, plantarse, verificar blackjack, etc.

	Colaboradores: Carta, Mazo

	Autor: Juan Jose Atuesta, Sergio Garcia Ramos, Paula Mariana Huertas, David Alejandro Garcia 
	Correo: atuesta.juan@correounivalle.edu.co - sergio.garcia.ramos@correounivalle.edu.co - murillo.paula@correounivalle.edu.co - david.grueso@correounivalle.edu.co]
	Fecha: Abril 2025
  */
#ifndef JUGADOR__H
#define JUGADOR__H
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "Carta.h"
#include "Mazo.h"
#include "Controlador.h"

class Jugador : public Controlador{
	private:

		public:
	Jugador(const string& _nombre, int _dinero);
	~Jugador() override{}
		long get_dinero() { return dinero_total; }
		void apostar (long _apuesta) override;
		void set_nombre(string _nombre);
		//void jugar_turno(Mazo& mazo)override;
		//void mostrar_mano()override;
};


#endif // JUGADOR__H