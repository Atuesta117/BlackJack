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
#include "Controlador.h"
#include <string>


class Crupier : public Controlador
{
	private:

		// Atributos
		Mazo& mazo;
	/*
		long dinero_total_crupier;
		long apuesta_crupier;
		int valor_mano_crupier;
		vector<Carta> mano_crupier; // Vector para almacenar las cartas del crupier
	*/	
	public:
	
		// Constructor
		Crupier(const string& _nombre, long _dinero, Mazo& _mazo_crupier); 
		

		void mostrar_mano_parcial();

		string determinar_ganador(Jugador* jugador);
		void apostar(long _apuesta)override;


};


#endif // CRUPIER__H
