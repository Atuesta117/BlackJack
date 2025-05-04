#include <iostream>
#include <string>
#include "Carta.h"
#include "Mazo.h"
#include "Jugador.h"
#include "Crupier.h"
using namespace std;
//g++ main.cpp Carta.cpp Mazo.cpp Jugador.cpp Crupier.cpp -o p
int main()
{
	cout<<"---------------------------------------------------"<<endl;
	cout << "Bienvenido al juego de Blackjack!" << endl;
	cout << "El objetivo del juego es obtener una mano con un valor total lo más cercano posible a 21 sin pasarse." << endl;
	cout << "El jugador juega contra el crupier." << endl;
	cout << "Buena suerte! :)." << endl;
	cout<<"---------------------------------------------------"<<endl;
	cout << "Ingrese su nombre: ";
	string nombre_jugador;
	cin >> nombre_jugador;
	Jugador jugador(nombre_jugador, 0); // Crea un objeto Jugador con nombre y dinero inicial 
	 // Crea un objeto Mazo
	Mazo mazo;
	Crupier crupier(9999999999, mazo); 
	// Inicializa el mazo de cartas

	long dinero_jugador;
	cout << "Ingrese el dinero total para jugar: ";
	cin >> dinero_jugador;
	jugador.set_dinero(dinero_jugador); // Establece el dinero del jugador
	
	//con el ciclo do-while, se juega al menos una vez, y luego se pregunta si el jugador quiere jugar otra vez.
	do 
	{
		string opc_inicial;
		cout << "Que desea hacer?" << endl;
		cout << "1. Jugar" << endl;
		cout << "2. Ingresar dinero" << endl;
		cout << "2. Salir" << endl;
		cin >> opc_inicial;
		while (opc_inicial != "1" && opc_inicial != "2" && opc_inicial != "3") {
			cout << "Opción inválida. Por favor, ingrese 1 para jugar, 2 para ingresar dinero o 3 para salir: ";
			cin >> opc_inicial;
		}
		if (opc_inicial == "1")
		{
			if (jugador.get_dinero_jugador() <= 0) {
				cout << "No tienes dinero suficiente para jugar. Por favor, ingresa dinero." << endl;
				continue; // Salta a la siguiente iteración del bucle
			}
			
			jugador.iniciar_partida(); // Inicia la partida
			// Crea un nuevo mazo de cartas
			mazo.shuffle(); // Baraja el mazo de cartas
			jugador.reiniciar_mano(); // Reinicia la mano del jugador
			crupier.reiniciar_mano(); // Reinicia la mano del crupier
			long apuesta_jugador1;
			cout << "El dinero total del jugador es: " << jugador.get_dinero_jugador() << endl;
			cout << "Ingrese la apuesta: ";
			cin >> apuesta_jugador1;
			while(apuesta_jugador1 > jugador.get_dinero_jugador()){
				cout << "La apuesta no puede ser mayor que el dinero total del jugador. Ingrese una apuesta válida: ";
				cin >> apuesta_jugador1;
			}
			jugador.apostar(apuesta_jugador1); // Establece la apuesta del jugador
			crupier.apostar(apuesta_jugador1); // Establece la apuesta del crupier 
			
			cout<<"---------------------------------------------------"<<endl;
			cout << "“En el juego de Blackjack, como en el juego de la vida, ganar es duro. \nRequiere determinación, preparación y mucha transpiración.”" << endl;
			cout<<"---------------------------------------------------"<<endl;

			// El jugador pide una mano inicial de 2 cartas
			jugador.pedir_mano(mazo);
			
			
			// Mostrar mano del jugador
			jugador.mostrar_mano();
			cout<<"Valor de la mano: " << jugador.get_valor_mano_jugador()<<endl;
			cout<< endl<< "Mano parcial del crupier: " << endl;
			crupier.obtener_mano(); // El crupier obtiene una mano inicial de 2 cartas
			crupier.mostrar_mano_parcial(); //1ra carta del crupier visible, 2da oculta	
			cout<<endl;
			bool controlador = true;
			while (controlador)
			{
				string opc_jugador;
				cout<< "Acciones disponibles: " << endl;
				cout<< "1. Pedir carta" << endl;
				cout<< "2. Plantarse" << endl;
				cout<< "3. Ver mano" << endl;
				cout<< "4. Ver el valor de la mano" << endl;
				cin >> opc_jugador;
				if (opc_jugador == "1")
				{
					jugador.pedir_carta(mazo); // El jugador pide otra carta
					jugador.mostrar_mano(); // Muestra la mano del jugador
					cout << "Valor de la mano del jugador "<< jugador.get_nombre()<< ":" << jugador.get_valor_mano_jugador() << endl; // Muestra el valor de la mano del jugador
					cout << endl;
					if(jugador.get_valor_mano_jugador() >= 21){
						if(jugador.get_valor_mano_jugador() > 21) {
							cout << "¡Te has pasado de 21! Fin de tu turno." << endl;
						} else {
							cout << "¡Tienes 21! Fin de tu turno." << endl;
						}
						controlador = false; // Cambia el controlador a false para salir del bucle
					}
				}
				else if (opc_jugador == "2")
				{
					jugador.plantarse(); // El jugador se planta
					controlador = false; // Cambia el controlador a false para salir del bucle
				}
				else if (opc_jugador == "3")
				{
					jugador.mostrar_mano(); // Muestra la mano del jugador
				}
				else if (opc_jugador == "4")
				{
					cout << "Valor de la mano del jugador " << jugador.get_nombre()<< ":" << jugador.get_valor_mano_jugador() << endl; // Muestra el valor de la mano del jugador
				}
				else{
					cout<< "Opción inválida. Por favor, ingrese una opción válida."<<endl;
				



			}
		}
			// Fin del turno del jugador
			
			cout<<"---------------------------------------------------"<<endl;
			cout<<"Turno Finalizado."<<endl;
			//despues del turno de todos los jugadores (en este caso, solo 1 jugador), el crupier muestra su mano completa, y comienza su turno
			crupier.mostrar_mano_completa();
			cout << "Valor de la mano del crupier: " << crupier.get_valor_mano_crupier() << endl; // Muestra el valor de la mano del crupier
			cout<<"---------------------------------------------------"<<endl;
			//El crupier pide cartas hasta que su mano sea 17 o más
			while(crupier.get_valor_mano_crupier() < 17) // El crupier pide cartas hasta que su mano sea 17 o más
			{
				cout<<"---------------------------------------------------"<<endl;
				cout << "El crupier pide otra carta." << endl;
				crupier.obtener_carta(); // El crupier obtiene una carta del mazo
				crupier.mostrar_mano_completa();
				cout << "Valor de la mano del crupier: " << crupier.get_valor_mano_crupier() << endl; 
			}
			cout<<"---------------------------------------------------"<<endl;
			cout << "El crupier se planta." << endl;
			crupier.mostrar_mano_completa(); // Muestra la mano completa del crupier
			cout << "Valor de la mano del crupier: " << crupier.get_valor_mano_crupier() << endl; // Muestra el valor de la mano del crupier
			cout<<endl;
			jugador.mostrar_mano();
			cout << "Valor de la mano del jugador " << jugador.get_nombre()<< ":" << jugador.get_valor_mano_jugador() << endl; // Muestra el valor de la mano del jugador
			cout<< endl;
			crupier.determinar_ganador(jugador);
			cout<<"---------------------------------------------------"<<endl;
			cout << "Fin de la partida." << endl;
			cout << "El dinero total del jugador " << jugador.get_nombre()<< ":" << jugador.get_dinero_jugador() << endl;
			cout<<"---------------------------------------------------"<<endl;

		}




		else if (opc_inicial == "2")
		{
			long dinero_ingresar;
			cout << "Ingrese el dinero a ingresar: ";
			cin >> dinero_ingresar;
			jugador.set_dinero(dinero_ingresar); // Establece el dinero del jugador
			cout << "El dinero total del jugador es: " << jugador.get_dinero_jugador() << endl;
		}
		else if (opc_inicial == "3")
		{
			cout << "Gracias por jugar! Su dinero total es: " << jugador.get_dinero_jugador() << endl;
			jugador.terminar_partida(); // El jugador termina la partida
			 // Salimos del bucle si el jugador decide no jugar más
		}
		
		
	}
	
	while (jugador.get_estado_jugador() == true); // Inicia la partida}
	
	return 0;
}
