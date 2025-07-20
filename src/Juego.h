#ifndef JUEGO_H
#define JUEGO_H
#include "Mesa.h"
#include "Mazo.h"
#include "Jugador.h"
#include "Crupier.h"
#include "Interfaz.h"
class Juego{
    public:
    Juego();
    bool recargar(Interfaz& interfaz, Jugador* jugador_ptr);
    void agregar_jugador(Interfaz& interfaz, Mesa& mesa);
    void mostrar_cartas_jugadores(Interfaz& interfaz,vector<Jugador*> jugadores, Mazo& mazo);
    void resumen_partida(Interfaz& interfaz, vector<Jugador*> jugadores,Crupier* crupier_ptr);
    void determinar_ganadores(Interfaz& interfaz, vector<Jugador*> jugadores,Crupier* crupier_ptr, Mazo& mazo);
    void eliminar_jugador(Mesa& mesa, Interfaz& interfaz);
    void apostar(Interfaz& interfaz, Jugador* jugadores);
    void jugar_turnos_jugadores(Interfaz& interfaz, vector<Jugador*> jugadores, Mazo& mazo, Crupier* crupier_ptr);
};

#endif //JUEGO_H