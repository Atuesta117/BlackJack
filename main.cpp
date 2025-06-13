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

bool recargar(Interfaz& interfaz, Jugador* jugador_ptr){
	interfaz.mensaje(0);
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

	bool comprobar_transaccion = servicio.realizar_transaccion(validator.esNumeroValido(numero), jugador_ptr, dinero_ingresar);
	return comprobar_transaccion;
}
void agregar_jugador(Interfaz& interfaz, Mesa& mesa){
	string nombre_jugador = interfaz.pedir_nombre();
	

	Controlador* jugador = new Jugador(nombre_jugador, 0);
	Jugador* jugador_ptr = dynamic_cast<Jugador*>(jugador);
	bool comprobar_transaccion = recargar(interfaz, jugador_ptr);
	if(comprobar_transaccion){
		mesa.agregar_jugador(jugador_ptr, jugador);
		interfaz.imprimir_divicion();
		interfaz.esperar_enter();
	}
	else{
		interfaz.imprimir_divicion();
		interfaz.esperar_enter();
	}
}

void mostrar_cartas_jugadores(Interfaz& interfaz,vector<Jugador*> jugadores, Mazo& mazo){
	interfaz.mensaje(2);
				interfaz.imprimir_divicion();
				for (size_t i = 0; i < jugadores.size(); i++)
				{
					cout << R"(
				     ╔════════════════════════════════════════╗ )"<<endl;
					cout<<				"						  JUGADOR "<<jugadores[i]->get_nombre()<<endl;
					cout<< R"(				     ╚════════════════════════════════════════╝ 
					)" <<endl;
					jugadores[i]->pedir_mano(mazo);
					interfaz.mostrar_mano(jugadores[i]);
					interfaz.mostrar_valor_mano(jugadores[i]);
					interfaz.imprimir_divicion();
					interfaz.esperar_enter();
				}
}
void jugar_turnos_jugadores(Interfaz& interfaz, vector<Jugador*> jugadores, Mazo& mazo, Crupier* crupier_ptr){
	for(size_t i = 0; i<jugadores.size();i++){
				interfaz.interfaz_turno(jugadores[i], mazo, crupier_ptr);
				interfaz.imprimir_divicion();
				}
}
void resumen_partida(Interfaz& interfaz, vector<Jugador*> jugadores,Crupier* crupier_ptr){

	interfaz.mensaje(3);
				for (size_t i = 0; i < jugadores.size()  ; i++)
				{
					interfaz.mostrar_mano(jugadores[i]);
					interfaz.mostrar_valor_mano(jugadores[i]);
					cout << endl;
				}
				interfaz.mostrar_mano(crupier_ptr);
				interfaz.mostrar_valor_mano(crupier_ptr);
				interfaz.imprimir_divicion();
				cout << endl;
}
void determinar_ganadores(Interfaz& interfaz, vector<Jugador*> jugadores,Crupier* crupier_ptr){
for(size_t i=0;i<jugadores.size();i++){
	interfaz.mostrar_ganador(crupier_ptr->determinar_ganador(jugadores[i]));
	interfaz.imprimir_divicion();
	cout << "El dinero total del jugador " << jugadores[i]->get_nombre() << ": " << jugadores[i]->get_dinero() << endl;
	interfaz.imprimir_divicion();
	interfaz.esperar_enter();
	jugadores[i]->reiniciar_valores();
	
	}
}

void lista_jugadores(Mesa& mesa, Interfaz& interfaz){
	vector<Jugador*> jugadores = mesa.get_jugadores();
		if(jugadores.empty()){
			interfaz.mensaje_error();
			cout<<"Error: No se han ingresado jugadores"<<endl;
		}
		else{
			interfaz.mostrar_lista_jugadores(mesa);
			int numero_jugador = interfaz.elegir_jugador_eliminar(mesa);
			if(numero_jugador == 6){
				interfaz.mensaje_exitoso();
				cout <<"Volviendo al menu principal"<<endl;
				interfaz.esperar_enter();
			}
			else{
			interfaz.mensaje_exitoso();
			cout << "Jugador eliminado correctamente." << endl;
			cout << "EL saldo final del jugador"<< jugadores[numero_jugador-1]->get_nombre() << " es: " << jugadores[numero_jugador-1]->get_dinero()<< endl;
			mesa.eliminar_jugador(numero_jugador);
		}
	}
}

void apostar(Interfaz& interfaz, Jugador* jugadores){
	interfaz.imprimir_divicion();	

	long apuesta_jugador1;
	interfaz.imprimir_divicion();
	cout << "El dinero total del jugador"<< jugadores->get_nombre()<<" es: " << jugadores->get_dinero() << endl;
	cout << "Ingrese la apuesta: ";
	cin >> apuesta_jugador1;

	while (apuesta_jugador1 > jugadores->get_dinero()) {
		interfaz.imprimir_divicion();
		interfaz.mensaje_error();
		cout << "Error: La apuesta no puede ser mayor que el dinero total. Ingrese una apuesta válida: ";
		cin >> apuesta_jugador1;
	}

	jugadores->apostar(apuesta_jugador1);
	jugadores->iniciar_partida();
	interfaz.imprimir_divicion();
	interfaz.esperar_enter();
	
}

//////////////////////////////////////////////////////////////




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

	if(opc_menu == "1"){
		
		if (mesa.mesa_llena() == false){
			agregar_jugador(interfaz, mesa);
		}
		else{
			interfaz.mensaje_error();
			cout<<endl<<"ERROR: MESA LLENA";
		}
	}
	else if(opc_menu == "2"){
		
		interfaz.mostrar_lista_jugadores(mesa);
	}
	else if (opc_menu == "3"){
		lista_jugadores(mesa, interfaz);
	}
	else if (opc_menu == "4")
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
				apostar(interfaz, jugadores[i]);
				break;
				
			}
			else if(opc_inicial =="2"){
				bool comprobado = recargar(interfaz, jugadores[i]);
				if(comprobado){
					cout<<"TRANSACCION FINALIZADA"<<endl;
				}
			}
			
			else if (opc_inicial == "3")
			{
				interfaz.mensaje(1);
				cout << "Gracias por jugar! Su dinero total es: " << jugadores[i]->get_dinero() << endl;
				mesa.eliminar_jugador(i+1);
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
			mostrar_cartas_jugadores(interfaz, jugadores, mazo);
			
				crupier_ptr->pedir_mano(mazo);
				interfaz.mostrar_mano_parcial(crupier_ptr);

				cout << endl;
				//Jugar los turnos de los jugadores
				jugar_turnos_jugadores(interfaz, jugadores, mazo, crupier_ptr);
			
				interfaz.interfaz_turno(crupier_ptr, jugadores, mazo);
				cout << endl;
				//Resumen
				resumen_partida(interfaz, jugadores, crupier_ptr);
				
			//determinar ganadores
			determinar_ganadores(interfaz, jugadores, crupier_ptr);
			
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
	else if (opc_menu == "5")
	{
		vector<Jugador*> jugadores = mesa.get_jugadores();
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
