#include "CreateFigure.h"
#include <SFML/Graphics.hpp>
CreateFigure::CreateFigure(int x, int y, int ancho, int alto, sf::Color color, Forma forma) {
    switch (forma) {
        case Forma::RECTANGULO: {
            auto* rect = new sf::RectangleShape(sf::Vector2f(ancho, alto));
            rect->setPosition(x, y);
            rect->setFillColor(color);
            shape = rect;
            break;
        }
        case Forma::CIRCULO: {
            float radio = std::min(ancho, alto) / 2.0f;
            auto* circle = new sf::CircleShape(radio);
            circle->setPosition(x, y);
            circle->setFillColor(color);
            shape = circle;
            break;
        }
    }
}

CreateFigure::~CreateFigure() {
    delete shape;
}

void CreateFigure::draw(sf::RenderWindow& window) {
    if (shape != nullptr)
        window.draw(*shape);
}
