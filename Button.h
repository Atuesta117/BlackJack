#ifndef BUTTON_H
#define BUTTON_H
#pragma once
#include <SFML/Graphics.hpp>

class Button {
private:
    sf::RectangleShape shape;
    sf::Text text;
    sf::Font font;

public:
    Button(float x, float y, float width, float height, const std::string& label);

    void draw(sf::RenderWindow& window);
    bool isClicked(const sf::RenderWindow& window, sf::Event& event);
    void setFillColor(const sf::Color& color);
    void setTextColor(const sf::Color& color);
};

#endif // BUTTON_H