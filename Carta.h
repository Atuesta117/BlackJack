#ifndef CARTA_H
#define CARTA_H
#include <iostream>
using namespace std;
#include <string>

class Carta{
    private:
        string casta;
        string ranck;
        int valor;
    public:
        Carta(string casta, string ranck, int valor);
        string get_casta();
        string get_ranck();
        int get_valor();
        void display();
    };




#endif