#include <iostream>
#include "Mazo.h"
#include <vector>
#include <algorithm>
#include <random>
#include <string>

Mazo::Mazo() {
    cartas = get_new_mazo();
    
}
vector<Carta> Mazo::get_new_mazo() {
    vector<Carta> new_mazo;
    string castas[] = {"Corazones", "Diamantes", "Tréboles", "Picas"};
    string rancks[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    int valores[] = {11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};

    for (string casta : castas) {
        for (int i = 0; i < 13; i++) {
            new_mazo.push_back(Carta(casta, rancks[i], valores[i]));
        }

    }
    shuffle();
    return new_mazo;
}
void Mazo::shuffle() {
    auto rng = std::default_random_engine(static_cast<unsigned>(time(nullptr)));
    std::shuffle(cartas.begin(), cartas.end(), rng);
}
int Mazo::get_cant_cartas() {
    return cartas.size();
}

Carta Mazo::get_carta() {
    if (cartas.empty()) {
        cout << "No hay más cartas en el mazo"<<endl;
    }
    Carta carta = cartas.back();
    cartas.pop_back();
    return carta;
}

