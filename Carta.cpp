#include <iostream>
using namespace std;
#include "Carta.h"
#include <string>

Carta::Carta(string casta, string rank, int valor){
    this->casta = casta;
    this->rank = rank;
    this->valor = valor;
}
string Carta::get_casta_carta(){
    return casta;
}
int Carta::get_valor_carta(){
    return valor;
}
string Carta::get_rank_carta(){
    return rank;
}
void Carta::display(){
    cout << "Casta: " << casta << ", rank: " << rank << ", Valor: " << valor << endl;
}