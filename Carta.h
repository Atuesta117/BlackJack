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
		void display();
	};

#endif // CARTA_H