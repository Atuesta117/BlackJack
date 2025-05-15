#include "Interfaz.h"
using namespace std;
#include <string>
#include "Carta.h"
void Interfaz::dibujar_catra(Carta& cartas) {
    string top = "┌─────────┐";
    string bottom = "└─────────┘";
    string side = "│         │"; 
    string rank_right;
    string rank_left;
        if (cartas.get_rank_carta() == "10") {
            rank_right = "10";
            rank_left = "10";
        } else {
            rank_right = cartas.get_rank_carta() + " ";
            rank_left = " " + cartas.get_rank_carta();
        }

        string suit_line = "│    " + cartas.get_casta_carta() + "    │";
        string rank_line_left = "│ " + rank_left + "      │";
        string rank_line_right = "│      " + rank_right + " │";

        cout << top << endl;
        cout << rank_line_left << endl;
        cout << side << endl;
        cout << suit_line << endl;
        cout << side << endl;
        cout << rank_line_right << endl;
        cout << bottom << endl;
        cout << endl;
    
    
}
void Interfaz::dibujar_carta_oculta() {
    string top = "┌─────────┐";
    string bottom = "└─────────┘";
    string side = "│         │"; 
    cout<< top << endl;
    cout<< side << endl;
    cout<< side << endl;
    cout<< side << endl;
    cout<< side << endl;
    cout<< side << endl;
    cout<< bottom << endl;
    cout<< endl;
}



Interfaz::Interfaz(){}
void Interfaz::mostrar_mano(Jugador* jugador) {
    vector<Carta> cartas = jugador->get_cartas();

    for (size_t i = 0; i < cartas.size(); i++) {
       dibujar_catra(cartas[i]);
}
}

void Interfaz::mostrar_mano(Crupier* crupier) {
   
    vector<Carta> cartas = crupier->get_cartas();

    for (size_t i = 0; i < cartas.size(); i++) {
        dibujar_catra(cartas[i]);
    }
}

void Interfaz::mostrar_mano_parcial(Crupier* crupier) {
    vector<Carta> cartas = crupier->get_cartas();

    dibujar_catra(cartas[0]); // Muestra solo la primera carta del crupier
    dibujar_carta_oculta(); // Muestra la carta oculta
}

void Interfaz::mostrar_valor_mano(Jugador* jugador) {
    cout << "------------------------------------------" << endl;
    cout << "Valor de la mano del jugador " << jugador->get_nombre() << ": " << jugador->get_valor_mano() << endl;
}
void Interfaz::mostrar_valor_mano(Crupier* crupier) {
    cout << "------------------------------------------" << endl;
    cout << "Valor de la mano del crupier: " << crupier->get_valor_mano() << endl;
}

void Interfaz::mostrar_ganador(string mensaje) {
    cout << "------------------------------------------" << endl;
    cout << mensaje;
    cout << "------------------------------------------" << endl;
}
int Interfaz::mostrar_menu() {
    cout << "------------------------------------------" << endl;
    cout << "1. Jugar" << endl;
    cout << "2. Ingresar dinero" << endl;
    cout << "3. Salir" << endl;
    cout << "------------------------------------------" << endl;
    int opcion;
    cin >> opcion;
    while (opcion < 1 || opcion > 3) {
        cout << "Opción inválida. Ingrese 1 para jugar, 2 para ingresar dinero o 3 para salir: ";
        cin >> opcion;
    }
    return opcion;
}
string Interfaz::mostrar_menu_jugador() {
    cout << "------------------------------------------" << endl;
    cout << "Acciones disponibles: " << endl;
    cout << "1. Pedir carta" << endl;
    cout << "2. Plantarse" << endl;
    cout << "3. Ver mano" << endl;
    cout << "4. Ver el valor de la mano" << endl;
    cout << "------------------------------------------" << endl;
    string opcion;
    cin >> opcion;
    while (opcion != "1" && opcion != "2" && opcion != "3" && opcion != "4") {
        cout << "Opción inválida. Ingrese una opción válida: ";
        cin >> opcion;
    }
    return opcion;
}
void Interfaz::imprimir_divicion() {
    cout << "------------------------------------------" << endl;
}

void Interfaz::mostrar_turno_jugador(Jugador* jugador, Mazo& mazo) {
    if(jugador->verificar_blackjack()){
		jugador->plantarse(); // Si el jugador tiene blackjack, se planta automáticamente
		cout << "¡Tienes blackjack! Fin de tu turno." << endl;
        imprimir_divicion();
	}

	while (jugador->get_se_planta() == false)
			{
				string opcion = mostrar_menu_jugador();
				if (opcion == "1")
                {
                    jugador->pedir_carta(mazo); // El jugador pide otra carta
                    mostrar_mano(jugador); // Muestra la mano del jugador
                    mostrar_valor_mano(jugador); // Muestra el valor de la mano del jugador
                    imprimir_divicion();
                    cout << endl;
                    if(jugador->get_valor_mano() >= 21){
                        if(jugador->get_valor_mano() > 21) {
                            imprimir_divicion();
                            cout << "¡Te has pasado de 21! Fin de tu turno." << endl;
                        } else {
                            imprimir_divicion();
                            cout << "¡Tienes 21! Fin de tu turno." << endl;
                        }
                        jugador->plantarse(); // Cambia el controlador a false para salir del bucle
                    }
                }
                else if (opcion == "2")
                {
                    imprimir_divicion();
                    jugador->plantarse(); // El jugador se planta
                    cout<<"El jugador se ha plantado."<<endl;   
                    mostrar_mano(jugador); // Muestra la mano del jugador
                    imprimir_divicion();
                }
                else if (opcion == "3")
                {
                    imprimir_divicion();
                    mostrar_mano(jugador); // Muestra la mano del jugador
                    imprimir_divicion();
                }
                else if (opcion == "4")
                {
                    mostrar_valor_mano(jugador); // Muestra el valor de la mano del jugador
                }
                else{
                    imprimir_divicion();
                    cout<< "Opción inválida. Por favor, ingrese una opción válida."<<endl;
                    imprimir_divicion();
			}
		}
}
