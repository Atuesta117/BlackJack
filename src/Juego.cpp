#include "Mesa.h"
#include "Mazo.h"
#include "Jugador.h"
#include "Crupier.h"
#include "Interfaz.h"
#include "Juego.h"
#include "PhoneValidator.h"
#include "ServicioRecarga.h"
using namespace std;

Juego::Juego(){}

bool Juego::recargar(Interfaz& interfaz, Jugador* jugador_ptr){
interfaz.limpiar_consola();
	interfaz.imprimir_division();
	interfaz.logo();
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
void Juego::agregar_jugador(Interfaz& interfaz, Mesa& mesa){
	interfaz.limpiar_consola();
	interfaz.imprimir_division();
	interfaz.logo();
	string nombre_jugador = interfaz.pedir_nombre();
	

	PersonaCasino* jugador = new Jugador(nombre_jugador, 0);
	Jugador* jugador_ptr = dynamic_cast<Jugador*>(jugador);
	bool comprobar_transaccion = recargar(interfaz, jugador_ptr);
	if(comprobar_transaccion){
		mesa.agregar_jugador(jugador_ptr, jugador);
		interfaz.imprimir_division();
		interfaz.esperar_enter();
	}
	else{
		interfaz.imprimir_division();
		interfaz.esperar_enter();
	}
}

void Juego::mostrar_cartas_jugadores(Interfaz& interfaz,vector<Jugador*> jugadores, Mazo& mazo){
	interfaz.limpiar_consola();
	interfaz.mensaje(2);
				interfaz.imprimir_division();
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
					interfaz.imprimir_division();
					interfaz.esperar_enter();
					interfaz.limpiar_consola();
				}
}

void Juego::resumen_partida(Interfaz& interfaz, vector<Jugador*> jugadores,Crupier* crupier_ptr){
	interfaz.limpiar_consola();
				for (size_t i = 0; i < jugadores.size()  ; i++)
				{
					interfaz.mensaje(3);
					interfaz.mostrar_mano(jugadores[i]);
					interfaz.mostrar_valor_mano(jugadores[i]);
					cout << endl;
					interfaz.limpiar_consola();
				}
				interfaz.mostrar_mano(crupier_ptr);
				interfaz.mostrar_valor_mano(crupier_ptr);
				interfaz.imprimir_division();
				cout << endl;
}

void Juego::determinar_ganadores(Interfaz& interfaz, vector<Jugador*> jugadores,Crupier* crupier_ptr, Mazo& mazo){
for(size_t i=0;i<jugadores.size();i++){
	interfaz.limpiar_consola();
	interfaz.mostrar_ganador(crupier_ptr->determinar_ganador(jugadores[i]));
	interfaz.imprimir_division();
	cout << "El dinero total del jugador " << jugadores[i]->get_nombre() << ": " << jugadores[i]->get_dinero() << endl;
	interfaz.imprimir_division();
	interfaz.esperar_enter();
	mazo.reunir_cartas(jugadores[i]->get_cartas());
	jugadores[i]->reiniciar_valores();
	interfaz.esperar_enter();
	
	}
}


void Juego::eliminar_jugador(Mesa& mesa, Interfaz& interfaz){
	interfaz.limpiar_consola();
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

void Juego::apostar(Interfaz& interfaz, Jugador* jugador){
	
	interfaz.limpiar_consola();
	interfaz.imprimir_division();
	interfaz.logo();
	interfaz.imprimir_division();	

	long apuesta_jugador1;
	interfaz.imprimir_division();
	cout << "El dinero total del jugador"<< jugador->get_nombre()<<" es: " << jugador->get_dinero() << endl;
	cout << "Ingrese la apuesta: ";
	cin >> apuesta_jugador1;

	while (apuesta_jugador1 > jugador->get_dinero()) {
		interfaz.imprimir_division();
		interfaz.mensaje_error();
		cout << "Error: La apuesta no puede ser mayor que el dinero total. Ingrese una apuesta válida: ";
		cin >> apuesta_jugador1;
	}

	jugador->apostar(apuesta_jugador1);
	jugador->iniciar_partida();
	interfaz.imprimir_division();
	interfaz.esperar_enter();
	
}

void Juego::jugar_turnos_jugadores(Interfaz& interfaz, vector<Jugador*> jugadores, Mazo& mazo, Crupier* crupier_ptr){
	for(size_t i = 0; i<jugadores.size();i++){
		interfaz.limpiar_consola();
				interfaz.interfaz_turno(jugadores[i], mazo, crupier_ptr);
				interfaz.imprimir_division();
				}
}