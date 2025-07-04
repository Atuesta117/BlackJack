/*
	Clase: 	Interfaz
	Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
	Universidad del Valle

  Información CRC:

  Clase: Interfaz

	Responsabilidades:

	Mostrar menus y retornar la opcion que el jugador eligio de estos

    Mostrar mensajes ya sea de error, exito entre otros

    Mostar de forma grafia la partida de cada jugador 

    Mostrar las cartas tanto de los jugadores como del crupier

	Colaboradores: Carta, Jugador, Cruoier, Mesa, .

	Autor: Juan Jose Atuesta, Sergio Garcia Ramos, Paula Mariana Huertas, David Alejandro Garcia 
	Correo: atuesta.juan@correounivalle.edu.co - sergio.garcia.ramos@correounivalle.edu.co - murillo.paula@correounivalle.edu.co - david.grueso@correounivalle.edu.co]
	Fecha: Julio 2025
  */
#ifndef INTERFARE_H
#define INTERFARE_H
#include <iostream>
#include <string>
#include <vector>
#include "Carta.h"
#include "Jugador.h"
#include "Crupier.h"
#include "Mesa.h"
using namespace std;


class Interfaz{
    private:
        void dibujar_catra(Carta& cartas);
        void dibujar_carta_oculta();
        
        
    public:
    Interfaz();
    void mostrar_mano(Jugador* jugador);
    void mostrar_mano(Crupier* crupier);
    void mostrar_mano_parcial(Crupier* crupier);
    void mostrar_valor_mano(Jugador* jugador);
    void mostrar_valor_mano(Crupier* crupier);
    void mostrar_ganador(string mensaje);
    string mostrar_menu_inicio();
    string mostrar_menu_juego(Jugador* jugador);
    string mostrar_menu_jugador();
    string pedir_nombre();
    void interfaz_turno(Jugador* jugador, Mazo& mazo, Crupier* crupier);
    void interfaz_turno(Crupier* crupier,vector<Jugador*> jugadores_activos,  Mazo& mazo); 
    void logo(); 
    void imprimir_divicion();
    void mensaje_error();
    void mensaje_exitoso();
    void esperar_enter();
    void mostrar_servicio_recarga();
    void mostrar_lista_jugadores(Mesa& mesa);
    int elegir_jugador_eliminar(Mesa&mesa);
    void mensaje(int i);
    void limpiar_consola();
};

#endif // INTERFARE_H