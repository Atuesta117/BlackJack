/*
	Clase: 	Crupier
	Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
	Universidad del Valle

	Información CRC:

	Clase: Crupier
	
	Responsabilidades:

	Administrar la mano del crupier y su dinero.

	Repartir cartas, determinar el ganador, mostrar manos.

	Colaboradores: Carta, Mazo, Jugador

	Autor: Juan Jose Atuesta, Sergio Garcia Ramos, Paula Mariana Huertas, David Alejandro Garcia 
	Correo: atuesta.juan@correounivalle.edu.co - sergio.garcia.ramos@correounivalle.edu.co - murillo.paula@correounivalle.edu.co - david.grueso@correounivalle.edu.co]
	Fecha: Abril 2025
  */
#ifndef CRUPIER__H
#define CRUPIER__H

#include "Carta.h"
#include "Mazo.h"
#include "Jugador.h"
#include "PersonaCasino.h"
#include <string>


class Crupier : public PersonaCasino{
	private:

	
	public:
	
		// Constructor
		Crupier(const string& _nombre); 
		
		string determinar_ganador(Jugador* jugador);
		void reiniciar_valores()override;



};


#endif // CRUPIER__H
