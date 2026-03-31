#include "Ball.h"

Ball::Ball(float startX, float startY) {
    shape.setSize({15.f, 15.f});
    shape.setFillColor(sf::Color::White);
    shape.setPosition({startX, startY});

    velocity = {-300.f, 300.f};
}

void Ball::update(float dt) {
    // Movimento em base da própria velocidade
    shape.move({velocity.x * dt, velocity.y * dt});

    // Colisão teto e chão
    sf::Vector2f pos = shape.getPosition();

    if (pos.y < 0.f) {
        pos.y = 0.f;
        bounceY(); // Inversão do Y
    }

    if (pos.y > 600.f - 15.f) {
        pos.y = 600.f - 15.f;
        bounceY(); // Inversão do Y
    }

    shape.setPosition(pos);
}

void Ball::render(sf::RenderWindow& window) {
    window.draw(shape);
}

sf::FloatRect Ball::getBounds() const {
    return shape.getGlobalBounds();
}

void Ball::setPosition(sf::Vector2f newPos) {
    shape.setPosition(newPos);
}

void Ball::reset() {
    shape.setPosition({392.f, 292.f});

    velocity.x = -velocity.x;
}

void Ball::bounceX() { velocity.x = -velocity.x; }
void Ball::bounceY() { velocity.y = -velocity.y; }