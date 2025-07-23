/*
	Clase: 	Carta
	Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
	Universidad del Valle

  Información CRC:

  Clase: Carta

	Responsabilidades:

	Representar una carta de un mazo (con su casta, rango y valor).

	Permitir mostrar la carta en pantalla.

	Colaboradores: Ninguno.

	Autor: Juan Jose Atuesta, Sergio Garcia Ramos, Paula Mariana Huertas, David Alejandro Garcia 
	Correo: atuesta.juan@correounivalle.edu.co - sergio.garcia.ramos@correounivalle.edu.co - murillo.paula@correounivalle.edu.co - david.grueso@correounivalle.edu.co]
	Fecha: Abril 2025
  */
#ifndef CARTA_H
#define CARTA_H
#include <iostream>
using namespace std;
#include <string>

class Carta{
	private:
		string casta;
		string rank;
		int valor;
	public:
		Carta(string casta, string rank, int valor);
		string get_casta_carta();
		string get_rank_carta();
		int get_valor_carta();

	};

#endif // CARTA_H