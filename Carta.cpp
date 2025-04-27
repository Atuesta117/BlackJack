#include <iostream>
using namespace std;
#include "Carta.h"
#include <string>

Carta::Carta(string casta, string ranck, int valor){
    this->casta = casta;
    this->ranck = ranck;
    this->valor = valor;
}
string Carta::get_casta(){
    return casta;
}
int Carta::get_valor(){
    return valor;
}
string Carta::get_ranck(){
    return ranck;
}
void Carta::display(){
    cout << "Casta: " << casta << ", Ranck: " << ranck << ", Valor: " << valor << endl;
}