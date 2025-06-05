#include "Mesa.h"
#include "Jugador.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
Mesa::Mesa() {
    for (size_t i = 0; i < 4; i++)
    {
     Controlador* jugador = new Jugador("", 0);
     Jugador* jugador_ptr = dynamic_cast<Jugador*>(jugador);
        mesa.push_back(jugador_ptr);
    }
    
    
}

bool Mesa::mesa_activa() {
    for (Jugador* jugador : mesa) {
        if (jugador->get_esta_jugando()) {
            return true; // Si al menos un jugador está activo, la mesa está activa
        }
    }
    return false; // Si ningún jugador está activo, la mesa no está activa
}
Jugador* Mesa::get_jugador(size_t index) {
    if (index < mesa.size() && index >= -4) { // Verifica que el índice esté dentro del rango válido
        return mesa[index]; // Devuelve el jugador en la posición indicada
    }
}