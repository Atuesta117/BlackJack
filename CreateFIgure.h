#ifndef CREATEFIGURE_H
#define CREATEFIGURE_H
#pragma once
#include <SFML/Graphics.hpp>

enum class Forma {
    RECTANGULO,
    CIRCULO
};

class CreateFigure {
private:
    sf::Shape* shape;

public:
    CreateFigure(int x, int y, int ancho, int alto, sf::Color color, Forma forma);
    ~CreateFigure();

    void draw(sf::RenderWindow& window);
};


#endif // CREATEFIGURE_H