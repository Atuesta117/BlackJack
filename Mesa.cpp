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
vector<Jugador*> Mesa::get_jugadores_activos(size_t index) {
    vector<Jugador*> jugadores_activos;
    for (size_t i = 0; i < 5; i++)
    {
        jugadores_activos.push_back(mesa[i]);
    }
    return jugadores_activos;
    
}

bool Mesa::mesa_llena(){
    int contador = 0;
    for (size_t i = 0; i < 4; i++)
    {
        if(mesa[i]->get_esta_jugando()){
            contador++;
        }
    }
    if (contador == 5){
        return true;
    }
    else{
        return false;
    }
}

void Mesa::agregar_jugador(string nombre){
	for(size_t i=0; i < 4; i++){
	if(mesa[i]->get_esta_jugando()== false){
            mesa[i]->set_nombre(nombre);
            mesa[i]->iniciar_partida();
            break;      
    }
    

}
}

void Mesa::eliminar_jugador(int jugador){
    mesa[jugador-1]->terminar_partida(); // Termina la partida del jugador seleccionado
    mesa[jugador-1]->reiniciar_valores(); // Reinicia los valores del jugador
    mesa[jugador-1]->set_nombre(""); // Limpia el nombre del jugador    
}

