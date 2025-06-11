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
#include "Mesa.h"
using namespace std;
// g++ main.cpp Crupier.cpp Carta.cpp Mazo.cpp Jugador.cpp Controlador.cpp Interfaz.cpp PhoneValidator.cpp ServicioRecarga.cpp Mesa.cpp -o prog -lcurl
/*
Notas:
EL programa deberia para si el jugador se pasa de 21 durante su jugada.
Testear mejor el tema de las sumas

*/
int main()
{
	Mazo mazo;
	Controlador* crupier = new Crupier("Crupier", 9999999999, mazo);
	Crupier* crupier_ptr = dynamic_cast<Crupier*>(crupier);
	Mesa mesa;

	while(true){
	Interfaz interfaz;
	string opc_menu;
	opc_menu = interfaz.mostrar_menu_inicio();
	while (opc_menu != "1" && opc_menu != "2"&& opc_menu != "3" && opc_menu != "4")
	{
		cout << "Ingrese una opcion valida"<<endl;
		cin >> opc_menu;
	}
	if(opc_menu == "1"){
		
		if (mesa.mesa_llena() == false){
		string nombre_jugador = interfaz.pedir_nombre();
		cout << R"(
        ╔══════════════════════════════════════════════╗  
        ║     SERVICIO DE RECARGA DE DINERO NEQUI      ║  
        ╚══════════════════════════════════════════════╝ 
        )" << endl;
			long dinero_ingresar;
			string numero;
			cout << "Ingrese su numero de cuenta Nequi: ";
			cin >> numero;
			cout << "Ingrese la cantidad a recargar: ";
			cin >> dinero_ingresar;
			PhoneValidator validator ("4B836698810C4FF6B7C56C4431318D80");
			ServicioRecarga servicio;
			bool monto_valido = servicio.verificar_monto(dinero_ingresar);
			while (monto_valido==false) {  
				interfaz.mensaje_error();
				cout << "Error: Cantidad no válida. Ingrese un monto positivo: ";
				cin >> dinero_ingresar;
				monto_valido = servicio.verificar_monto(dinero_ingresar);
			}

			Controlador* jugador = new Jugador(nombre_jugador, 0);
     		Jugador* jugador_ptr = dynamic_cast<Jugador*>(jugador);
			servicio.realizar_transaccion(validator.esNumeroValido(numero), jugador_ptr, dinero_ingresar);
			mesa.agregar_jugador(jugador_ptr);
			cout << "Jugador agregado correctamente." << endl;
			cout << "El saldo del jugador " << jugador_ptr->get_nombre() << " es: " << jugador_ptr->get_dinero() << endl;
			interfaz.imprimir_divicion();
			interfaz.esperar_enter();
		}
		else{
			interfaz.mensaje_error();
			cout<<endl<<"ERROR: MESA LLENA";
		}
		bool prueba = mesa.get_mesa_activa();
		if (prueba == true){
			cout << "La mesa esta activa" << endl;
		}
		else{
			cout << "La mesa no esta activa" << endl;
		}
	}
	else if (opc_menu == "2"){
		vector<Jugador*> jugadores = mesa.get_jugadores();
		if(jugadores.empty()){
			interfaz.mensaje_error();
			cout<<"Error: No se han ingresado jugadores"<<endl;
		}
		else{
		int numero_jugador = interfaz.mostrar_lista_jugadores(mesa);
		interfaz.mensaje_exitoso();
		cout << "Jugador eliminado correctamente." << endl;
		cout << "EL saldo final del jugador"<< jugadores[numero_jugador-1]->get_nombre() << " es: " << jugadores[numero_jugador-1]->get_dinero()<< endl;
		mesa.eliminar_jugador(numero_jugador);
	}
	}
	else if (opc_menu == "3")
	{
		
		if(mesa.get_mesa_activa()){
		vector<Jugador*> jugadores = mesa.get_jugadores();
		for(size_t i = 0; i < jugadores.size(); i++){
			string opc_inicial = interfaz.mostrar_menu_juego(jugadores[i]); 	
			while (opc_inicial != "1" && opc_inicial != "2" && opc_inicial != "3")
			{
				interfaz.mensaje_error();
				cout << "Error: Opcion no valida."<<endl;
				cin >> opc_inicial;
			}	
			while(true){
				if (opc_inicial == "1")
			{
				interfaz.imprimir_divicion();	

				long apuesta_jugador1;
				interfaz.imprimir_divicion();
				cout << "El dinero total del jugador"<< jugadores[i]->get_nombre()<<" es: " << jugadores[i]->get_dinero() << endl;
				cout << "Ingrese la apuesta: ";
				cin >> apuesta_jugador1;

				while (apuesta_jugador1 > jugadores[i]->get_dinero()) {
					interfaz.imprimir_divicion();
					interfaz.mensaje_error();
					cout << "Error: La apuesta no puede ser mayor que el dinero total. Ingrese una apuesta válida: ";
					cin >> apuesta_jugador1;
				}

				jugadores[i]->apostar(apuesta_jugador1);
				jugadores[i]->iniciar_partida();
				interfaz.imprimir_divicion();
				interfaz.esperar_enter();
				break;
				
			}
			else if(opc_inicial =="2"){
				cout << R"(
        ╔══════════════════════════════════════════════╗  
        ║     SERVICIO DE RECARGA DE DINERO NEQUI      ║  
        ╚══════════════════════════════════════════════╝ 
        )" << endl;
			long dinero_ingresar;
			string numero;
			cout << "Ingrese su numero de cuenta Nequi: ";
			cin >> numero;
			cout << "Ingrese la cantidad a recargar: ";
			cin >> dinero_ingresar;
			PhoneValidator validator ("4B836698810C4FF6B7C56C4431318D80");
			ServicioRecarga servicio;
			bool monto_valido = servicio.verificar_monto(dinero_ingresar);
			while (monto_valido==false) {  
				interfaz.mensaje_error();
				cout << "Error: Cantidad no válida. Ingrese un monto positivo: ";
				cin >> dinero_ingresar;
				monto_valido = servicio.verificar_monto(dinero_ingresar);
			}
			servicio.realizar_transaccion(validator.esNumeroValido(numero), jugadores[i], dinero_ingresar);
			interfaz.mensaje_exitoso();
			cout << "Recarga exitosa. El saldo del jugador " << jugadores[i]->get_nombre() << " es: " <<jugadores[i]->get_dinero() << endl;
			interfaz.imprimir_divicion();
			interfaz.esperar_enter();
			}
			
			else if (opc_inicial == "3")
			{
				cout << R"(
		╔════════════════════════════╗  
		║    	SALIO DEL JUEGO      ║  
		╚════════════════════════════╝ 
		)" << endl;
				cout << "Gracias por jugar! Su dinero total es: " << jugadores[i]->get_dinero() << endl;
				mesa.eliminar_jugador(i);
				interfaz.imprimir_divicion(); 
				break;
				
			}
			opc_inicial = interfaz.mostrar_menu_juego(jugadores[i]); 	
			while (opc_inicial != "1" && opc_inicial != "2" && opc_inicial != "3")
			{
				interfaz.mensaje_error();
				cout << "Error: Opcion no valida."<<endl;
				cin >> opc_inicial;
			}
			
					
		}
		}
		
		if(mesa.get_mesa_activa()){
			vector<Jugador*> jugadores = mesa.get_jugadores();
							mazo.shuffle();
				
				
				cout << R"(
        ╔═══════════════════════════════════════════════════════════════════════════════════╗  
        ║        “En el juego de Blackjack, como en el juego de la vida, ganar es duro.     ║
        ║		Requiere determinación, preparación y mucha transpiración.”         ║
        ╚═══════════════════════════════════════════════════════════════════════════════════╝ 
        )" << endl;
				interfaz.imprimir_divicion();
				for (int i = 0; i < jugadores.size(); i++)
				{
					cout << R"(
╔═══════════════════════════════════════╗ )"<<endl;
					cout<<"		JUGADOR "<<jugadores[i]->get_nombre()<<endl;
					cout<< R"(╚════════════════════════════════════════╝ 
					)" <<endl;
					jugadores[i]->pedir_mano(mazo);
					interfaz.mostrar_mano(jugadores[i]);
					interfaz.mostrar_valor_mano(jugadores[i]);
					interfaz.imprimir_divicion();
					interfaz.esperar_enter();
				}
		
				crupier_ptr->pedir_mano(mazo);
				interfaz.mostrar_mano_parcial(crupier_ptr);

				cout << endl;
				interfaz.imprimir_divicion();
				for(int i = 0; i<jugadores.size();i++){
				interfaz.interfaz_turno(jugadores[i], mazo, crupier_ptr);
				interfaz.imprimir_divicion();
				}
				
				interfaz.interfaz_turno(crupier_ptr, jugadores, mazo);
				cout << endl;
				cout << R"(
		╔══════════════════════════════════════════════════════════════╗  
		║ 	     RESUMEN DE LA PARTIDA: JUGADORES Y CRUPIER        ║
		╚══════════════════════════════════════════════════════════════╝ 
		)" << endl;
				for (int i = 0; i < jugadores.size()  ; i++)
				{
					interfaz.mostrar_mano(jugadores[i]);
					interfaz.mostrar_valor_mano(jugadores[i]);
					cout << endl;
				}
				interfaz.mostrar_mano(crupier_ptr);
				interfaz.mostrar_valor_mano(crupier_ptr);
				interfaz.imprimir_divicion();
				cout << endl;
				for(int i=0;i<jugadores.size();i++){
					interfaz.mostrar_ganador(crupier_ptr->determinar_ganador(jugadores[i]));
					interfaz.imprimir_divicion();
					cout << "El dinero total del jugador " << jugadores[i]->get_nombre() << ": " << jugadores[i]->get_dinero() << endl;
					interfaz.imprimir_divicion();
					interfaz.esperar_enter();
					jugadores[i]->reiniciar_valores();
					
					}
					crupier_ptr->reiniciar_valores();
					cout<<"FIn de la partida"<<endl;
					interfaz.imprimir_divicion();
				}
				else{
					interfaz.mensaje_error();
					cout<<"Error: Mesa sin jugadores"<<endl;
				}
				
			}
			else{
				interfaz.mensaje_error();
				cout << "ERROR: MESA NO ACTIVA. Por favor, agregue al menos un jugador para iniciar una partida." << endl;
			}
			
		
	}
	else if (opc_menu == "4")
	{
		vector<Jugador*> jugadores = mesa.get_jugadores();
		cout << R"(
        ╔════════════════════════════╗  
        ║    	SALIO DEL JUEGO      ║  
        ╚════════════════════════════╝ 
        )" << endl;
		
			if(jugadores.size()!=0){
				for (int i = 0; i < jugadores.size(); i++)
		{
			cout << "El dinero total del jugador " << jugadores[i]->get_nombre() << ": " << jugadores[i]->get_dinero() << endl;
		}
	}
	
		
		break; // Salir del bucle y terminar el programa
	}
}
	

	return 0;
}
