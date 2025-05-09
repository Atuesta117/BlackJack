#include <iostream>
#include <string>
#include "Carta.h"
#include "Mazo.h"
#include "Jugador.h"
#include "Crupier.h"
using namespace std;

int main()
{
	cout << "---------------------------------------------------" << endl;
	cout << "Bienvenido al juego de Blackjack!" << endl;
	cout << "El objetivo del juego es obtener una mano con un valor total lo más cercano posible a 21 sin pasarse." << endl;
	cout << "El jugador juega contra el crupier." << endl;
	cout << "Buena suerte! :)." << endl;
	cout << "---------------------------------------------------" << endl;

	cout << "Ingrese su nombre: ";
	string nombre_jugador;
	cin >> nombre_jugador;

	Jugador jugador(nombre_jugador, 0);
	Mazo mazo;
	Crupier crupier("Crupier", 9999999999, mazo);

	long dinero_jugador;
	cout << "Ingrese el dinero total para jugar: ";
	cin >> dinero_jugador;
	jugador.set_dinero(dinero_jugador);

	do
	{
		string opc_inicial;
		cout << "¿Qué desea hacer?" << endl;
		cout << "1. Jugar" << endl;
		cout << "2. Ingresar dinero" << endl;
		cout << "3. Salir" << endl;
		cin >> opc_inicial;

		while (opc_inicial != "1" && opc_inicial != "2" && opc_inicial != "3") {
			cout << "Opción inválida. Ingrese 1 para jugar, 2 para ingresar dinero o 3 para salir: ";
			cin >> opc_inicial;
		}

		if (opc_inicial == "1")
		{
			if (jugador.get_dinero() <= 0) {
				cout << "No tienes dinero suficiente para jugar. Por favor, ingresa dinero." << endl;
				continue;
			}

			jugador.iniciar_partida();
			mazo.shuffle();
			jugador.reiniciar_mano();
			crupier.reiniciar_mano();

			long apuesta_jugador1;
			cout << "El dinero total del jugador es: " << jugador.get_dinero() << endl;
			cout << "Ingrese la apuesta: ";
			cin >> apuesta_jugador1;

			while (apuesta_jugador1 > jugador.get_dinero()) {
				cout << "La apuesta no puede ser mayor que el dinero total. Ingrese una apuesta válida: ";
				cin >> apuesta_jugador1;
			}

			jugador.apostar(apuesta_jugador1);
			crupier.apostar(jugador);

			cout << "---------------------------------------------------" << endl;
			cout << "“En el juego de Blackjack, como en el juego de la vida, ganar es duro.\n"
					"Requiere determinación, preparación y mucha transpiración.”" << endl;
			cout << "---------------------------------------------------" << endl;

			jugador.pedir_mano(mazo);
			jugador.mostrar_mano();
			cout << "Valor de la mano: " << jugador.get_valor_mano() << endl;

			cout << endl << "Mano parcial del crupier: " << endl;
			crupier.pedir_mano(mazo);
			crupier.mostrar_mano_parcial();

			cout << endl;
			jugador.jugar_turno(mazo);

			cout << "---------------------------------------------------" << endl;
			cout << "Turno Finalizado." << endl;

			crupier.mostrar_mano();
			cout << "Valor de la mano del crupier: " << crupier.get_valor_mano() << endl;

			cout << "---------------------------------------------------" << endl;
			crupier.jugar_turno(mazo);
			cout << "---------------------------------------------------" << endl;
			cout << "El crupier se planta." << endl;
			crupier.mostrar_mano();
			cout << "Valor de la mano del crupier: " << crupier.get_valor_mano() << endl;

			cout << endl;
			jugador.mostrar_mano();
			cout << "Valor de la mano del jugador " << jugador.get_nombre() << ": " << jugador.get_valor_mano() << endl;

			cout << endl;
			crupier.determinar_ganador(jugador);
			cout << "---------------------------------------------------" << endl;
			cout << "Fin de la partida." << endl;
			cout << "El dinero total del jugador " << jugador.get_nombre() << ": " << jugador.get_dinero() << endl;
			cout << "---------------------------------------------------" << endl;
		}
		else if (opc_inicial == "2")
		{
			long dinero_ingresar;
			cout << "Ingrese el dinero a ingresar: ";
			cin >> dinero_ingresar;
			jugador.set_dinero(dinero_ingresar);
			cout << "El dinero total del jugador es: " << jugador.get_dinero() << endl;
		}
		else if (opc_inicial == "3")
		{
			cout << "Gracias por jugar! Su dinero total es: " << jugador.get_dinero() << endl;
			jugador.terminar_partida();
		}

	} while (jugador.get_esta_jugando());

	return 0;
}
