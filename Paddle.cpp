#include "Paddle.h"
#include <SFML/Window/Keyboard.hpp>

// Construtor
Paddle::Paddle(float startX, float startY) {
    shape.setSize({15.f, 100.f});
    shape.setFillColor(sf::Color::White);
    shape.setPosition({startX, startY});
    speed = 400.f;
}

// Lógica do movimento
void Paddle::update(float dt, bool isPlayerOne) {
    sf::Vector2f pos = shape.getPosition();

    if (isPlayerOne) {
        // Player 1
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) pos.y -= speed * dt;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) pos.y += speed * dt;
    } else {
        // Player 2
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) pos.y -= speed * dt;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) pos.y += speed * dt;
    }

    // colisão com o teto e o chão
    if (pos.y < 0.f) pos.y = 0.f;
    if (pos.y > 600.f - 100.f) pos.y = 600.f - 100.f;

    shape.setPosition(pos);
}

void Paddle::render(sf::RenderWindow& window) {
    window.draw(shape);
}

sf::FloatRect Paddle::getBounds() const {
    return shape.getGlobalBounds();
}
