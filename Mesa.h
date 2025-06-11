#ifndef MESA_H
#define MESA_H
#include <vector>
#include "Jugador.h"
using namespace std;
class Mesa {
    private:
        vector<Jugador*> mesa;
        bool mesa_activa;
    public:
    Mesa();
    vector<Jugador*> get_jugadores();
    bool get_mesa_activa();
    bool mesa_llena();// la idea es que la mesa tenga maximo 5 jugadores
    void agregar_jugador(Jugador* jugador);
    void eliminar_jugador(int index);
    void repartir_cartas(Mazo& mazo);
};
#endif // MESA_H


