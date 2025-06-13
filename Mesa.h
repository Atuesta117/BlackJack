#ifndef MESA_H
#define MESA_H
#include <vector>
#include "Jugador.h"
#include "Controlador.h"
using namespace std;
class Mesa {
    private:
        vector<Jugador*> mesa;
        vector<Controlador*> objetos_padre; //nos servira para cuando querramos eliminar un jugador o salir de la partida
        bool mesa_activa;
    public:
    Mesa();
    vector<Jugador*> get_jugadores();
    bool get_mesa_activa();
    bool mesa_llena();// la idea es que la mesa tenga maximo 5 jugadores
    void agregar_jugador(Jugador* jugador, Controlador* controlador);
    void eliminar_jugador(int index);
    void eliminar_todos_jugadores();
    void repartir_cartas(Mazo& mazo);
};
#endif // MESA_H


