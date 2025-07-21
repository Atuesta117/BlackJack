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
	opc_menu = interfaz.mostrar_menu_inicio();//mirar las opciones del menu de inicio para entender esta parte

	if(opc_menu == "1"){//agregar un jugador
		
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
	else if(opc_menu == "2"){ //mostrar los jugadores
		
		interfaz.mostrar_lista_jugadores(mesa);
	}
	else if (opc_menu == "3"){//eliminar un jugador
		juego.eliminar_jugador(mesa, interfaz);
	}
	else if (opc_menu == "4")//empezar partida con los jugadores registrados
	{
		
		if(mesa.get_mesa_activa()){//verifica que la mesa tiene al menos un jugador
		vector<Jugador*> jugadores = mesa.get_jugadores();
		for(size_t i = 0; i < jugadores.size(); i++){
			string opc_inicial = interfaz.mostrar_menu_juego(jugadores[i]);// opciones de menu de juego, apostar, ingresar dinero o salir 		
			while(true){
				if (opc_inicial == "1")//el jugador apuesta he inicia partida
			{
				juego.apostar(interfaz, jugadores[i]);
				break;
				
			}
			else if(opc_inicial =="2"){//el jugador recarga dinero
				bool comprobado = juego.recargar(interfaz, jugadores[i]);
				if(comprobado){
					cout<<"TRANSACCION FINALIZADA"<<endl;
				}
			}
			
			else if (opc_inicial == "3")//el jugador sale antes de iniciar la partida con el crupier
			{
				interfaz.limpiar_consola();
				interfaz.mensaje(1);
				cout << "Gracias por jugar! Su dinero total es: " << jugadores[i]->get_dinero() << endl;
				mesa.eliminar_jugador(i+1);
				interfaz.imprimir_division(); 
				break;
				
			}
			opc_inicial = interfaz.mostrar_menu_juego(jugadores[i]); 			
		}
		}
		//la idea es repetir esta interfaz a menos que el jugador de apostar o salir, una vez dijitado eso se pasa al siguiente jugador
		//para que tome sus acciones, si ya no hay mas jugadores se continua 
		if(mesa.get_mesa_activa()){// se verifica de nuevo por si todos los jugadores en el ciclo anterior decidieron salir antes de empezar la partida con el crupier
			vector<Jugador*> jugadores = mesa.get_jugadores();
			mazo.shuffle();//se baraja el mazo
			juego.mostrar_cartas_jugadores(interfaz, jugadores, mazo);//se reparte la mano y se pmuestra
			
			// el crupier toma su mano y muestra una parte
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
					interfaz.imprimir_division();
					interfaz.logo();
					interfaz.mensaje(4);
					interfaz.imprimir_division();
					interfaz.esperar_enter();
				}
				else{//en caso tal de que todos los jugadores hayan salido
					interfaz.limpiar_consola();
					interfaz.imprimir_division();
					interfaz.logo();
					interfaz.mensaje_error();
					cout<<"Error: Mesa sin jugadores"<<endl;
				}
				
			}
			else{//la mesa no tenia jugadortes
				interfaz.limpiar_consola();
				interfaz.imprimir_division();
				interfaz.logo();
				interfaz.mensaje_error();
				cout << "ERROR: MESA NO ACTIVA. Por favor, agregue al menos un jugador para iniciar una partida." << endl;
			}
			
		
	}
	else if (opc_menu == "5")//se sale del juego completamente
	{
		interfaz.limpiar_consola();
		vector<Jugador*> jugadores = mesa.get_jugadores();
		interfaz.imprimir_division();
		interfaz.logo();
		interfaz.mensaje(1);
		
			if(jugadores.size()!=0){//se muestra un resumen de el dinero final de cada jugador
				for (size_t i = 0; i < jugadores.size(); i++)
		{
			cout << "El dinero total del jugador " << jugadores[i]->get_nombre() << ": " << jugadores[i]->get_dinero() << endl;
		}
		//se eliminan todos los jugadores
		mesa.eliminar_todos_jugadores();
		
	}
	//se elimina el crupier
		delete crupier;
		break; // Salir del bucle y terminar el programa
	}
}
	

	return 0;
}
