#ifndef JUGADOR__H
#define JUGADOR__H
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "Carta.h"
#include "Mazo.h"

class Jugador{
    private:
        string nombre;
        long dinero_total;
        long apuesta;
        int valor_mano;
        vector<Carta> mano; // Vector para almacenar las cartas del jugador
        bool estado_jugador; // true si el jugador sigue en juego, false si se ha retirado

    public:
        Jugador(const string& _nombre, int _dinero);
        //estado del jugador        
        bool iniciar_partida();
        bool terminar_partida();
       
        //acciones
        long apostar(long _apuesta);
        void pedir_carta(Mazo &mazo);
        void pedir_mano(Mazo& mazo);
        bool plantarse();
        void ver_mano();
        int contar_cartas();
       
        //seters
        long set_dinero (long _cantidad_depositar);
       
        //geters
        int get_valor_mano();

        //verificacion blackjack
        bool verificar_blackjack();

};


#endif