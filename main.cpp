#include <iostream>
#include <string>
#include "Carta.h"
#include "Mazo.h"
#include "Jugador.h"
#include "Crupier.h"
#include "Controlador.h"
#include "Interfaz.h"
#include "PhoneValidator.h"
#include "ServicioRecarga.h"
using namespace std;
// g++ main.cpp Crupier.cpp Carta.cpp Mazo.cpp Jugador.cpp Controlador.cpp Interfaz.cpp PhoneValidator.cpp ServicioRecarga.cpp -o prog -lcurl
/*
Notas:
EL programa deberia para si el jugador se pasa de 21 durante su jugada.
Testear mejor el tema de las sumas

*/
int main()
{
	Interfaz interfaz;
	interfaz.logo();
	cout << R"(
        ╔══════════════════════════╗  
        ║     INGRESE SU NOMBRE    ║  
        ╚══════════════════════════╝ 
        )" << endl;
	
	string nombre_jugador;
	cin >> nombre_jugador;
    Mazo mazo;
	Controlador* jugador = new Jugador(nombre_jugador, 0);
	Controlador* crupier = new Crupier("Crupier", 9999999999, mazo);
	Jugador* jugador_ptr = dynamic_cast<Jugador*>(jugador);
	Crupier* crupier_ptr = dynamic_cast<Crupier*>(crupier);
	string opc_menu;
	opc_menu = interfaz.mostrar_menu_inicio();
	while (opc_menu != "1" && opc_menu != "2")
	{
		cout << "Ingrese una opcion valida"<<endl;
		cin >> opc_menu;
	}
	if (opc_menu == "1")
	{
			do
		{
			string opc_inicial = interfaz.mostrar_menu_juego(jugador_ptr);
			
			if (opc_inicial == "1")
			{
				jugador_ptr->iniciar_partida();
				mazo.shuffle();
				jugador_ptr->reiniciar_valores();
				crupier_ptr->reiniciar_valores();

				long apuesta_jugador1;
				interfaz.imprimir_divicion();
				cout << "El dinero total del jugador es: " << jugador_ptr->get_dinero() << endl;
				cout << "Ingrese la apuesta: ";
				cin >> apuesta_jugador1;

				while (apuesta_jugador1 > jugador_ptr->get_dinero()) {
					interfaz.imprimir_divicion();
					interfaz.mensaje_error();
					cout << "La apuesta no puede ser mayor que el dinero total. Ingrese una apuesta válida: ";
					cin >> apuesta_jugador1;
				}

				jugador_ptr->apostar(apuesta_jugador1);
				crupier_ptr->apostar(jugador_ptr->get_apuesta());
				cout << R"(
        ╔═══════════════════════════════════════════════════════════════════════════════════╗  
        ║        “En el juego de Blackjack, como en el juego de la vida, ganar es duro.     ║
        ║		Requiere determinación, preparación y mucha transpiración.”              ║
        ╚═══════════════════════════════════════════════════════════════════════════════════╝ 
        )" << endl;
				interfaz.imprimir_divicion();

				jugador_ptr->pedir_mano(mazo);

				interfaz.mostrar_mano(jugador_ptr);
				interfaz.mostrar_valor_mano(jugador_ptr);
				interfaz.esperar_enter();
		
				crupier_ptr->pedir_mano(mazo);
				interfaz.mostrar_mano_parcial(crupier_ptr);

				cout << endl;
				interfaz.imprimir_divicion();
				interfaz.interfaz_turno(jugador_ptr, mazo);
				interfaz.interfaz_turno(crupier_ptr, jugador_ptr, mazo);


				cout << endl;
				interfaz.mostrar_mano(jugador_ptr);
				interfaz.mostrar_valor_mano(jugador_ptr);
				cout << endl;
				interfaz.mostrar_ganador(crupier_ptr->determinar_ganador(jugador_ptr));
				interfaz.imprimir_divicion();
				cout << "Fin de la partida." << endl;
				cout << "El dinero total del jugador " << jugador_ptr->get_nombre() << ": " << jugador_ptr->get_dinero() << endl;
				interfaz.imprimir_divicion();
			}
			else if (opc_inicial == "2")
			{
				interfaz.imprimir_divicion();
				long dinero_ingresar;
				string numero;
				cout << "Ingrese su numero de cuenta Nequi: ";
				cin >> numero;
				cout << "Ingrese la cantidad a recargar: ";
				cin >> dinero_ingresar;
				PhoneValidator validator ("4B836698810C4FF6B7C56C4431318D80");
				ServicioRecarga servicio;
				while (servicio.verificar_monto(dinero_ingresar))
				{
					interfaz.mensaje_error();
					cout<< "Cantidad no valida";
					cin >> dinero_ingresar;
				}
				
				servicio.realizar_transaccion(validator.esNumeroValido("3163759188"), jugador_ptr, dinero_ingresar);
				interfaz.imprimir_divicion();
				cout << "El dinero total del jugador es: " << jugador_ptr->get_dinero() << endl;
			}
			else if (opc_inicial == "3")
			{
				cout << R"(
        ╔════════════════════════════╗  
        ║    	SALIO DEL JUEGO      ║  
        ╚════════════════════════════╝ 
        )" << endl;
				cout << "Gracias por jugar! Su dinero total es: " << jugador_ptr->get_dinero() << endl;
				jugador_ptr->terminar_partida();
			}

		} while (jugador_ptr->get_esta_jugando());
	}
	else if (opc_menu == "2")
	{
		cout << R"(
        ╔════════════════════════════╗  
        ║    	SALIO DEL JUEGO      ║  
        ╚════════════════════════════╝ 
        )" << endl;
	}
	
	

	return 0;
}
