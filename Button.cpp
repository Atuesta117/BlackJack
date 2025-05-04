#include "Button.h"

Button::Button(float x, float y, float width, float height, const std::string& label) {
    // Cargar fuente
    font.loadFromFile("arial.ttf"); // Asegúrate de tener esta fuente

    // Configurar forma
    shape.setPosition(x, y);
    shape.setSize(sf::Vector2f(width, height));
    shape.setFillColor(sf::Color::Blue);

    // Configurar texto
    text.setFont(font);
    text.setString(label);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::White);

    // Centrar texto dentro del botón
    sf::FloatRect textBounds = text.getLocalBounds();
    text.setOrigin(textBounds.left + textBounds.width / 2.0f,
                   textBounds.top + textBounds.height / 2.0f);
    text.setPosition(x + width / 2.0f, y + height / 2.0f);
}

void Button::draw(sf::RenderWindow& window) {
    window.draw(shape);
    window.draw(text);
}

bool Button::isClicked(const sf::RenderWindow& window, sf::Event& event) {
    if (event.type == sf::Event::MouseButtonPressed &&
        event.mouseButton.button == sf::Mouse::Left) {

        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        return shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
    }
    return false;
}

void Button::setFillColor(const sf::Color& color) {
    shape.setFillColor(color);
}

void Button::setTextColor(const sf::Color& color) {
    text.setFillColor(color);
}
