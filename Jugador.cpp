#include <iostream>
#include <string>
#include <vector>
#include "Jugador.h"
#include "Mazo.h"
using namespace std;

Jugador::Jugador(const string& _nombre, int _dinero) {
    nombre = _nombre;
    dinero_total = _dinero;
    apuesta = 0;
    valor_mano = 0;
    estado_jugador = true; // El jugador inicia en juego
}

//Estado del jugador

bool Jugador::iniciar_partida(){
    estado_jugador = true;
    return estado_jugador;
}

bool Jugador::terminar_partida(){
    estado_jugador = false;
    return estado_jugador;
}

//acciones

void Jugador::pedir_mano(Mazo& mazo){
    for(int i = 0 ; i<2, i++;){
        Carta carta = mazo.get_carta();
        mano.push_back(carta);
    }
}

void Jugador::pedir_carta(Mazo &mazo) {
    Carta carta = mazo.get_carta();
    mano.push_back(carta);
}

bool Jugador::plantarse(){
    return true;
}

void Jugador::ver_mano(){
    for (size_t i = 0; i < mano.size(); i++)
    {
        mano[i].display();
        cout<<endl;
    }
    
}

int Jugador::contar_cartas() {
    int total = 0;
    for (size_t i = 0; i < mano.size(); i++)
    {
        total ++;
    }
    return total;
    
}

long Jugador::apostar(long _apuesta) {
    apuesta = _apuesta;
    dinero_total -= apuesta;
    return dinero_total;
}

//seters
long Jugador::set_dinero (const long _cantidad_depositar){
    dinero_total += _cantidad_depositar;
    return dinero_total;
}

//geters


//verificacion blackjack
int Jugador::get_valor_mano(){

    for (size_t i = 0; i < mano.size(); i++)
    {
        valor_mano += mano[i].get_valor();
        
    }

    if(valor_mano > 21){
        for (size_t i = 0; i < mano.size(); i++)
        {
            if (mano[i].get_ranck() == "A") {
                valor_mano -= 10; // Si el jugador tiene un As y su mano supera 21, se le resta 10 al valor total
            }
            break; // Salimos del bucle una vez que hemos ajustado el valor del As
        }
    }
    return valor_mano;
}

bool Jugador::verificar_blackjack() {
    if (mano.size() == 2 && valor_mano == 21) {
        return true; // El jugador tiene blackjack
    }
    return false; // El jugador no tiene blackjack
}

