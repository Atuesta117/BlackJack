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
// g++ main.cpp Crupier.cpp Carta.cpp Mazo.cpp Jugador.cpp Controlador.cpp Interfaz.cpp PhoneValidator.cpp ServicioRecarga.cpp -o prog -lcurl
/*
Notas:
EL programa deberia para si el jugador se pasa de 21 durante su jugada.
Testear mejor el tema de las sumas

*/
int main()
{
	while(true){
	Interfaz interfaz;
	interfaz.logo();
	
    Mazo mazo;
	Controlador* jugador = new Jugador(nombre_jugador, 0);
	Controlador* crupier = new Crupier("Crupier", 9999999999, mazo);
	Jugador* jugador_ptr = dynamic_cast<Jugador*>(jugador);
	Crupier* crupier_ptr = dynamic_cast<Crupier*>(crupier);
	Mesa mesa;
	string opc_menu;
	opc_menu = interfaz.mostrar_menu_inicio();
	while (opc_menu != "1" && opc_menu != "2")
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
			while (servicio.verificar_monto(dinero_ingresar))
			{
				interfaz.mensaje_error();
				cout<< "Cantidad no valida";
				cin >> dinero_ingresar;
			}
		for (size_t i = 0; i < 5; i++)
		{
			if(mesa.get_jugador(i)->get_esta_jugando() == false)
		{
				servicio.realizar_transaccion(validator.esNumeroValido(numero), mesa.get_jugador(i), dinero_ingresar);
				mesa.agregar_jugador(nombre_jugador);
				interfaz.mensaje_exitoso();
				cout << "Jugador agregado correctamente." << endl;
				cout << "El saldo del jugador " << mesa.get_jugador(i)->get_nombre() << " es: " << mesa.get_jugador(i)->get_dinero() << endl;
				interfaz.imprimir_divicion();
				interfaz.esperar_enter();
				break; // Salir del bucle una vez que se ha agregado el jugador
				}		
		
		
			}
		}
		else{
			interfaz.mensaje_error();
			cout<<endl<<"ERROR: MESA LLENA";
		}
	}
	else if (opc_menu == "2"){
		string numero_jugador;;
		cout<<"Ingrese el numero de jugador a eliminar"<<endl;
		cin >> numero_jugador;
		while(numero_jugador!="1" &&numero_jugador!="2" &&numero_jugador!="3" &&numero_jugador!="4" &&numero_jugador!="5"){
			interfaz.mensaje_error();
        cout << "ERROR: Valor invalido, porfavor elija una opcion correcta";
		cin >> numero_jugador;
    }
		int numero_jugador_aux = stoi(numero_jugador); // Convertir a entero y restar 1 para el índice
		
		interfaz.mensaje_exitoso();
		cout << "Jugador eliminado correctamente." << endl;
		cout << "EL saldo final del jugador"<< mesa.get_jugador(numero_jugador_aux)->get_nombre() << " es: " << mesa.get_jugador(numero_jugador_aux)->get_dinero()<< endl;
		mesa.eliminar_jugador(numero_jugador_aux);
	}
	else if (opc_menu == "3")
	{
		vector<Jugador*> jugadores_activos = mesa.get_jugadores_activos();
		for(size_t i = 0; i < 5; i++){
			string opc_inicial = interfaz.mostrar_menu_juego(mesa.get_jugador(i)); 	
			while (opc_inicial != "1" && opc_inicial != "2" && opc_inicial != "3")
			{
				interfaz.mensaje_error();
				cout << "Error: Opcion no valida."<<endl;
				cin >> opc_inicial;
			}			
			if (opc_inicial == "1")
			{
				interfaz.imprimir_divicion();	

				long apuesta_jugador1;
				interfaz.imprimir_divicion();
				cout << "El dinero total del jugador es: " << jugadores_activos[i]->get_dinero() << endl;
				cout << "Ingrese la apuesta: ";
				cin >> apuesta_jugador1;

				while (apuesta_jugador1 > jugadores_activos[i]->get_dinero()) {
					interfaz.imprimir_divicion();
					interfaz.mensaje_error();
					cout << "Error: La apuesta no puede ser mayor que el dinero total. Ingrese una apuesta válida: ";
					cin >> apuesta_jugador1;
				}

				mesa.get_jugador(i)->apostar(apuesta_jugador1);
				jugadores_activos[i]->iniciar_partida();
				interfaz.imprimir_divicion();
				interfaz.esperar_enter();
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
			while (servicio.verificar_monto(dinero_ingresar))
			{
				interfaz.mensaje_error();
				cout<< "Cantidad no valida";
				cin >> dinero_ingresar;
			}
			servicio.realizar_transaccion(validator.esNumeroValido(numero), mesa.get_jugador(i), dinero_ingresar);
			interfaz.mensaje_exitoso();
			cout << "Recarga exitosa. El saldo del jugador " << mesa.get_jugador(i)->get_nombre() << " es: " << mesa.get_jugador(i)->get_dinero() << endl;
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
				cout << "Gracias por jugar! Su dinero total es: " << mesa.get_jugador(i)->get_dinero() << endl;
				mesa.eliminar_jugador(i);
				interfaz.imprimir_divicion(); 

			}
		}
				mazo.shuffle();
				
				crupier_ptr->apostar(jugador_ptr->get_apuesta());
				cout << R"(
        ╔═══════════════════════════════════════════════════════════════════════════════════╗  
        ║        “En el juego de Blackjack, como en el juego de la vida, ganar es duro.     ║
        ║		Requiere determinación, preparación y mucha transpiración.”         ║
        ╚═══════════════════════════════════════════════════════════════════════════════════╝ 
        )" << endl;
				interfaz.imprimir_divicion();
				for (int i = 0; i < 5; i++)
				{
					cout << R"(
					╔═══════════════════════════════════════╗ )"<<endl;
					cout<<"JUGADOR "<<jugadores_activos[i]->get_nombre()<<endl;
					cout<< R"(╚════════════════════════════════════════╝ 
					)" <<endl;
					jugadores_activos[i]->pedir_mano(mazo);
					interfaz.mostrar_mano(jugadores_activos[i]);
					interfaz.mostrar_valor_mano(jugadores_activos[i]);
					interfaz.imprimir_divicion();
					interfaz.esperar_enter();
				}
		
				crupier_ptr->pedir_mano(mazo);
				interfaz.mostrar_mano_parcial(crupier_ptr);

				cout << endl;
				interfaz.imprimir_divicion();
				for(int i = 0; i<5;i++){
				interfaz.interfaz_turno(jugadores_activos[i], mazo);
				interfaz.imprimir_divicion();
				}
				
				interfaz.interfaz_turno(crupier_ptr, mesa.get_jugadores_activos(), mazo);
				cout << endl;
				cout << R"(
		╔══════════════════════════════════════════════════════════════╗  
		║ 	     RESULTADOS DE LA PARTIDA: JUGADORES Y CRUPIER         ║
		╚══════════════════════════════════════════════════════════════╝ 
		)" << endl;
				for (size_t i = 0; i < jugadores_activos.size()  ; i++)
				{
					interfaz.mostrar_mano(jugadores_activos[i]);
					interfaz.mostrar_valor_mano(jugadores_activos[i]);
					cout << endl;
				}
				
				interfaz.mostrar_mano(jugador_ptr);
				interfaz.mostrar_valor_mano(jugador_ptr);
				cout << endl;
				interfaz.mostrar_ganador(crupier_ptr->determinar_ganador(jugador_ptr));
				interfaz.imprimir_divicion();
				cout << "Fin de la partida." << endl;
				cout << "El dinero total del jugador " << jugador_ptr->get_nombre() << ": " << jugador_ptr->get_dinero() << endl;
				interfaz.imprimir_divicion();
				interfaz.esperar_enter();
			
		
	}
	else if (opc_menu == "4")
	{
		cout << R"(
        ╔════════════════════════════╗  
        ║    	SALIO DEL JUEGO      ║  
        ╚════════════════════════════╝ 
        )" << endl;
		break; // Salir del bucle y terminar el programa
	}
}
	

	return 0;
}
