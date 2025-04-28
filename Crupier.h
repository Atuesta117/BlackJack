#ifndef CRUPIER__H
#define CRUPIER__H

#include "Carta.h"
#include "Mazo.h"
#include "Jugador.h"
#include <string>


class Crupier
{
	private:
		// Atributos
		Mazo& mazo_crupier;
		long dinero_total_crupier;
		long apuesta_crupier;
		int valor_mano_crupier;
		vector<Carta> mano_crupier; // Vector para almacenar las cartas del crupier
		
	public:
	
		// Constructor
		Crupier(long _dinero_total_crupier, Mazo& _mazo_crupier); 
		
		//funciones
		void obtener_mano(); // El crupier obtiene una mano inicial de 2 cartas
		void obtener_carta(); // El crupier obtiene una carta del mazo	
		bool plantarse();
		void mostrar_mano_parcial();
		void mostrar_mano_completa();
		int contar_cartas();
		bool verificar_blackjack();
		//no seria get valor mano porque no es un getter, es un calculador. 
		// recordemos que los getters son funciones que devuelven un valor, no lo calculan.
		// ademas, los getters leen informacion, no la modifican.
		// por lo tanto, el nombre correcto de la funcion es calcular_valor_mano
		//int calcular_valor_mano();
		void determinar_ganador(Jugador& jugador);
        void apostar(long _apuesta);
		//getter
		int get_valor_mano_crupier(){return valor_mano_crupier;}
		
		//setter
		long set_dinero_crupier(long _cantidad_depositar);

		//reiniciar mano
		void reiniciar_mano();

};


#endif // CRUPIER__H
