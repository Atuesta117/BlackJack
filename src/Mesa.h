/*
	Clase: Mesa
	Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
	Universidad del Valle

  Información CRC:

  Clase: Mesa

	Responsabilidades:

    Representar una mesa de BlackJack, con una cantidad limitada de jugadores 

	Colaboradores: Jugador, PersonaCasino

	Autor: Juan Jose Atuesta, Sergio Garcia Ramos, Paula Mariana Huertas, David Alejandro Garcia 
	Correo: atuesta.juan@correounivalle.edu.co - sergio.garcia.ramos@correounivalle.edu.co - murillo.paula@correounivalle.edu.co - david.grueso@correounivalle.edu.co]
	Fecha: Julio 2025
  */
#ifndef MESA_H
#define MESA_H
#include <vector>
#include "Jugador.h"
#include "PersonaCasino.h"
using namespace std;
class Mesa {
    private:
        vector<Jugador*> mesa;
        vector<PersonaCasino*> objetos_padre; //nos servira para cuando querramos eliminar un jugador o salir de la partida
        bool mesa_activa;
    public:
    Mesa();
    vector<Jugador*> get_jugadores();
    bool get_mesa_activa();
    bool mesa_llena();// la idea es que la mesa tenga maximo 5 jugadores
    void agregar_jugador(Jugador* jugador, PersonaCasino* PersonaCasino);
    void eliminar_jugador(int index);
    void eliminar_todos_jugadores();
    void repartir_cartas(Mazo& mazo);
};
#endif // MESA_H


