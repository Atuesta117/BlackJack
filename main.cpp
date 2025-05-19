#include <iostream>
#include <string>
#include "Carta.h"
#include "Mazo.h"
#include "Jugador.h"
#include "Crupier.h"
#include "Controlador.h"
#include "Interfaz.h"
using namespace std;
// g++ main.cpp Crupier.cpp Carta.cpp Mazo.cpp Jugador.cpp Controlador.cpp Interfaz.cpp -o prog 
/*
Notas:
EL programa deberia para si el jugador se pasa de 21 durante su jugada.
Testear mejor el tema de las sumas

*/
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
	Mazo mazo;
	Controlador* jugador = new Jugador(nombre_jugador, 0);
	Controlador* crupier = new Crupier("Crupier", 9999999999, mazo);
	Jugador* jugador_ptr = dynamic_cast<Jugador*>(jugador);
	Crupier* crupier_ptr = dynamic_cast<Crupier*>(crupier);
	Interfaz interfaz;

	//Jugador jugador(nombre_jugador, 0);
	
	//Crupier crupier("Crupier", 9999999999, mazo);

	long dinero_jugador;
	cout << "Ingrese el dinero total para jugar: ";
	cin >> dinero_jugador;
	jugador_ptr->set_dinero(dinero_jugador);

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
			if (jugador_ptr->get_dinero() <= 0) {
				cout << "No tienes dinero suficiente para jugar. Por favor, ingresa dinero." << endl;
				continue;
			}

			jugador_ptr->iniciar_partida();
			mazo.shuffle();
			jugador_ptr->reiniciar_valores();
			crupier_ptr->reiniciar_valores();

			long apuesta_jugador1;
			cout << "El dinero total del jugador es: " << jugador_ptr->get_dinero() << endl;
			cout << "Ingrese la apuesta: ";
			cin >> apuesta_jugador1;

			while (apuesta_jugador1 > jugador_ptr->get_dinero()) {
				cout << "La apuesta no puede ser mayor que el dinero total. Ingrese una apuesta válida: ";
				cin >> apuesta_jugador1;
			}

			jugador_ptr->apostar(apuesta_jugador1);
			crupier_ptr->apostar(jugador_ptr->get_apuesta());

			cout << "---------------------------------------------------" << endl;
			cout << "“En el juego de Blackjack, como en el juego de la vida, ganar es duro.\n"
					"Requiere determinación, preparación y mucha transpiración.”" << endl;
			cout << "---------------------------------------------------" << endl;

			jugador_ptr->pedir_mano(mazo);
			jugador_ptr->mostrar_mano();
			interfaz.mostrar_mano(jugador_ptr);
			cout << "Valor de la mano: " << jugador->get_valor_mano() << endl;

			cout << endl << "Mano parcial del crupier: " << endl;
			crupier_ptr->pedir_mano(mazo);
			crupier_ptr->mostrar_mano_parcial();
			interfaz.mostrar_mano_parcial(crupier_ptr);

			cout << endl;
			interfaz.interfaz_turno(jugador_ptr, mazo);
			/*
			cout << "---------------------------------------------------" << endl;
			cout << "Turno Finalizado." << endl;

			crupier_ptr->mostrar_mano();
			cout << "Valor de la mano del crupier: " << crupier_ptr->get_valor_mano() << endl;

			cout << "---------------------------------------------------" << endl;
			*/
			interfaz.interfaz_turno(crupier_ptr, jugador_ptr, mazo);
			//crupier_ptr->jugar_turno(mazo);
			//cout << "---------------------------------------------------" << endl;
			//cout << "El crupier se planta." << endl;
			//crupier_ptr->mostrar_mano();
			//cout << "Valor de la mano del crupier: " << crupier_ptr->get_valor_mano() << endl;

			cout << endl;
			jugador_ptr->mostrar_mano();
			interfaz.mostrar_mano(jugador_ptr);
			cout << "Valor de la mano del jugador " << jugador_ptr->get_nombre() << ": " << jugador_ptr->get_valor_mano() << endl;

			cout << endl;
			crupier_ptr->determinar_ganador(jugador_ptr);
			cout << "---------------------------------------------------" << endl;
			cout << "Fin de la partida." << endl;
			cout << "El dinero total del jugador " << jugador_ptr->get_nombre() << ": " << jugador_ptr->get_dinero() << endl;
			cout << "---------------------------------------------------" << endl;
		}
		else if (opc_inicial == "2")
		{
			long dinero_ingresar;
			cout << "Ingrese el dinero a ingresar: ";
			cin >> dinero_ingresar;
			jugador_ptr->set_dinero(dinero_ingresar);
			cout << "El dinero total del jugador es: " << jugador_ptr->get_dinero() << endl;
		}
		else if (opc_inicial == "3")
		{
			cout << "Gracias por jugar! Su dinero total es: " << jugador_ptr->get_dinero() << endl;
			jugador_ptr->terminar_partida();
		}

	} while (jugador_ptr->get_esta_jugando());

	return 0;
}
