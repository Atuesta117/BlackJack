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


class Jugador{
	private:
		string nombre;
		long dinero_total_jugador;
		long apuesta_jugador;
		int valor_mano_jugador;
		vector<Carta> mano; // Vector para almacenar las cartas del jugador
		bool estado_jugador; // true si el jugador sigue en juego, false si se ha retirado

	public:
		Jugador(const string& _nombre, int _dinero);
		//estado del jugador        
		bool iniciar_partida();
		bool terminar_partida();
		string get_nombre(){return nombre;};
	
		//acciones
		void apostar(long _apuesta);
		void pedir_carta(Mazo &mazo);
		void pedir_mano(Mazo& mazo);
		bool plantarse();
		void mostrar_mano();
		int contar_cartas();
		//no es getter porque no devuelve un valor, sino que calcula el valor de la mano
		//int calcular_valor_mano_jugador();
	
		//getter
		long get_apuesta_jugador() { return apuesta_jugador; }
		bool get_estado_jugador() { return estado_jugador; }
		long get_dinero_jugador() { return dinero_total_jugador; }
		int get_valor_mano_jugador(){return valor_mano_jugador;}
		
		//setter
		long set_dinero (long _cantidad_depositar);
	


		//verificacion blackjack
		bool verificar_blackjack();

		//reiniciar mano
		void reiniciar_mano();
};


#endif // JUGADOR__H