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
	protected:
	/*
		string nombre;
		long dinero_total;
		long apuesta;
		int valor_mano;
		vector<Carta> mano; // Vector para almacenar las cartas del jugador
		bool esta_jugando; // true si el jugador sigue en juego, false si se ha retirado
		bool se_planta; // true si el jugador se planta, false si sigue pidiendo cartas
	*/
		public:
	Jugador(const string& _nombre, int _dinero);
		/*
		//estado del jugador        
		bool iniciar_partida();
		bool terminar_partida();
		string get_nombre(){return nombre;};
	
		//acciones
		void pedir_carta(Mazo &mazo);
		void pedir_mano(Mazo& mazo);
		bool plantarse();
		void mostrar_mano();
		int contar_cartas();
		//no es getter porque no devuelve un valor, sino que calcula el valor de la mano
		//int calcular_valor_mano_jugador();
	
		//getter
		long get_apuesta() { return apuesta; }
		bool get_esta_jugando() { return esta_jugando; }
		//long get_dinero() { return dinero_total_jugador; } considero que esto es mas necesario para el jugador que par el crupier
		int get_valor_mano(){return valor_mano;}
		
		//setter
		long set_dinero (long _cantidad_depositar);
	


		//verificacion blackjack
		bool verificar_blackjack();

		void reiniciar_mano();
		*/
		long get_dinero() { return dinero_total; }
		void apostar (long _apuesta) override;
		void jugar_turno(Mazo& mazo)override;
		void mostrar_mano()override;
};


#endif // JUGADOR__H