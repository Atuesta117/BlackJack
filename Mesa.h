#ifndef MESA_H
#define MESA_H
#include <vector>
#include "Jugador.h"
using namespace std;
class Mesa {
    private:
        vector<Jugador*> mesa;
    public:
    Mesa();
    vector<Jugador*> get_jugadores_activos();
    Jugador* get_jugador(int index);
    bool mesa_activa();
    bool mesa_llena();
    void agregar_jugador(string nombre);
    void eliminar_jugador(int jugador);
};
#endif // MESA_H


