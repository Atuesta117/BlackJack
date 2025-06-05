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
    Jugador* get_jugador(size_t index);
    bool mesa_activa();
    
};
#endif // MESA_H


