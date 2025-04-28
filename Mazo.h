#ifndef MAZO_H
#define MAZO_H
#include <iostream>
#include <vector>
using namespace std;
#include "Carta.h"
#include <string>

class Mazo{
	private:
		vector<Carta> cartas;
		
	public:
		Mazo();
		vector <Carta> get_new_mazo();
		void shuffle();
		int get_cant_cartas();
		Carta get_carta();
};


#endif // MAZO_H