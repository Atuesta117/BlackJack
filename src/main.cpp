#include <iostream>
#include <string>
#include "Carta.h"
#include "Mazo.h"
#include "Jugador.h"
#include "Crupier.h"
#include "PersonaCasino.h"
#include "Interfaz.h"
#include "PhoneValidator.h"
#include "ServicioRecarga.h"
#include "Mesa.h"
#include "Juego.h"
using namespace std;
// g++ main.cpp Crupier.cpp Carta.cpp Mazo.cpp Jugador.cpp PersonaCasino.cpp Interfaz.cpp PhoneValidator.cpp ServicioRecarga.cpp Mesa.cpp Juego.cpp -o prog -lcurl

 

//////////////////////////////////////////////////////////////




int main()
{
	Mazo mazo;
	PersonaCasino* crupier = new Crupier("Crupier");
	Crupier* crupier_ptr = dynamic_cast<Crupier*>(crupier);
	Mesa mesa;
	Interfaz interfaz;
	Juego juego;
	while(true){
	interfaz.limpiar_consola();
	string opc_menu;
	opc_menu = interfaz.mostrar_menu_inicio();

	if(opc_menu == "1"){
		
		if (mesa.mesa_llena() == false){
			juego.agregar_jugador(interfaz, mesa);
		}
		else{
			interfaz.limpiar_consola();
			interfaz.mensaje_error();
			cout<<endl<<"ERROR: MESA LLENA";
			interfaz.esperar_enter();
		}
	}
	else if(opc_menu == "2"){
		
		interfaz.mostrar_lista_jugadores(mesa);
	}
	else if (opc_menu == "3"){
		juego.eliminar_jugador(mesa, interfaz);
	}
	else if (opc_menu == "4")
	{
		
		if(mesa.get_mesa_activa()){
		vector<Jugador*> jugadores = mesa.get_jugadores();
		for(size_t i = 0; i < jugadores.size(); i++){
			string opc_inicial = interfaz.mostrar_menu_juego(jugadores[i]); 		
			while(true){
				if (opc_inicial == "1")
			{
				juego.apostar(interfaz, jugadores[i]);
				break;
				
			}
			else if(opc_inicial =="2"){
				bool comprobado = juego.recargar(interfaz, jugadores[i]);
				if(comprobado){
					cout<<"TRANSACCION FINALIZADA"<<endl;
				}
			}
			
			else if (opc_inicial == "3")
			{
				interfaz.limpiar_consola();
				interfaz.mensaje(1);
				cout << "Gracias por jugar! Su dinero total es: " << jugadores[i]->get_dinero() << endl;
				mesa.eliminar_jugador(i+1);
				interfaz.imprimir_divicion(); 
				break;
				
			}
			opc_inicial = interfaz.mostrar_menu_juego(jugadores[i]); 			
		}
		}
		
		if(mesa.get_mesa_activa()){
			vector<Jugador*> jugadores = mesa.get_jugadores();
			mazo.shuffle();
			juego.mostrar_cartas_jugadores(interfaz, jugadores, mazo);
			
				crupier_ptr->pedir_mano(mazo);
				interfaz.limpiar_consola();
				interfaz.mostrar_mano_parcial(crupier_ptr);

				cout << endl;
				//Jugar los turnos de los jugadores
				juego.jugar_turnos_jugadores(interfaz, jugadores, mazo, crupier_ptr);
			
				interfaz.interfaz_turno(crupier_ptr, jugadores, mazo);
				cout << endl;
				//Resumen
				juego.resumen_partida(interfaz, jugadores, crupier_ptr);
				
			//determinar ganadores
			juego.determinar_ganadores(interfaz, jugadores, crupier_ptr, mazo);
					mazo.reunir_cartas(crupier_ptr->get_cartas());
					crupier_ptr->reiniciar_valores();
					interfaz.limpiar_consola();
					interfaz.imprimir_divicion();
					interfaz.logo();
					interfaz.mensaje(4);
					interfaz.imprimir_divicion();
					interfaz.esperar_enter();
				}
				else{
					interfaz.limpiar_consola();
					interfaz.imprimir_divicion();
					interfaz.logo();
					interfaz.mensaje_error();
					cout<<"Error: Mesa sin jugadores"<<endl;
				}
				
			}
			else{
				interfaz.limpiar_consola();
				interfaz.imprimir_divicion();
				interfaz.logo();
				interfaz.mensaje_error();
				cout << "ERROR: MESA NO ACTIVA. Por favor, agregue al menos un jugador para iniciar una partida." << endl;
			}
			
		
	}
	else if (opc_menu == "5")
	{
		interfaz.limpiar_consola();
		vector<Jugador*> jugadores = mesa.get_jugadores();
		interfaz.imprimir_divicion();
		interfaz.logo();
		interfaz.mensaje(1);
		
			if(jugadores.size()!=0){
				for (size_t i = 0; i < jugadores.size(); i++)
		{
			cout << "El dinero total del jugador " << jugadores[i]->get_nombre() << ": " << jugadores[i]->get_dinero() << endl;
		}
		mesa.eliminar_todos_jugadores();
		
	}
		delete crupier;
		break; // Salir del bucle y terminar el programa
	}
}
	

	return 0;
}
