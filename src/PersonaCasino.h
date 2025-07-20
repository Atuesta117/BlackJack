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
#ifndef PersonaCasino_H
#define PersonaCasino_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "Carta.h"
#include "Mazo.h"


class PersonaCasino{
	private:
	protected:
		string nombre;
		long dinero_total;

		int valor_mano;
		vector<Carta> mano;
		bool esta_jugando; // true si el jugador sigue en juego, false si se ha retirado
		bool se_planta;
		int contador_as;//pasa que a veces se puede tener un as al pedir la mano, y al pedir carta sabemos que si se pasa de 21 este pasa a valer 1, la idea de este atributo es que nos ayude a saber si al pedir una carta ese as ya paso a valer 1 (restandole 10 al valor de la mano)
	 //y asi evitar vovler a retarle 10 al valor de la mano
		
	 public:
		PersonaCasino(const string& _nombre);
		virtual ~PersonaCasino() = default;

		//estado del jugador        
		void iniciar_partida();
		void terminar_partida();
		string get_nombre(){return nombre;};
	
		//acciones
		void pedir_carta(Mazo &mazo);
		void pedir_mano(Mazo& mazo);
		bool plantarse();
		//getter
		bool get_esta_jugando() { return this->esta_jugando; }
		int get_valor_mano(){return this->valor_mano;}
		vector<Carta> get_cartas() { return this->mano; } 
		bool get_se_planta() { return this->se_planta; } 

		//setter
		long set_dinero (long _cantidad_depositar);
	


		//verificacion blackjack
		bool verificar_blackjack();

		//reiniciar mano
		virtual void reiniciar_valores()=0;
	

		
};


#endif // PersonaCasino_H