using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include "Carta.h"
void mostrar_mano(vector<Carta>& cartas) {
    string top = "┌─────────┐";
    string bottom = "└─────────┘";
    string side = "│         │"; 
    string rank_right;
    string rank_left;

    for (size_t i = 0; i < cartas.size(); i++) {
        if (cartas[i].get_rank_carta() == "10") {
            rank_right = "10";
            rank_left = "10";
        } else {
            rank_right = cartas[i].get_rank_carta() + " ";
            rank_left = " " + cartas[i].get_rank_carta();
        }

        string suit_line = "│    " + cartas[i].get_casta_carta() + "    │";
        string rank_line_left = "│ " + rank_left + "      │";
        string rank_line_right = "│      " + rank_right + " │";

        cout << top << endl;
        cout << rank_line_left << endl;
        cout << side << endl;
        cout << suit_line << endl;
        cout << side << endl;
        cout << rank_line_right << endl;
        cout << bottom << endl;
        cout << endl;
    }
}

int main (){
    vector<Carta> cartas;
    cartas.push_back(Carta("♥", "A", 11));
    cartas.push_back(Carta("♦", "10", 10));
    mostrar_mano(cartas);
    string top = "┌─────────┐";
    string bottom = "└─────────┘";
    string side = "│         │"; 
    cout<< top << endl;
    cout<< side << endl;
    cout<< side << endl;
    cout<< side << endl;
    cout<< side << endl;
    cout<< side << endl;
    cout<< bottom << endl;
    cout<< endl;
}
