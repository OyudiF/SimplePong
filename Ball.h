#ifndef PROJ1_BALL_H
#define PROJ1_BALL_H
#pragma once
#include <SFML/Graphics.hpp>


class Ball {
public:
    Ball(float startX, float startY);

    void update(float dt);
    void render(sf::RenderWindow& window);
    void reset();

    // Verificação de colisão
    sf::FloatRect getBounds() const;

    void setPosition(sf::Vector2f newPos);

    // Inversão de direção
    void bounceX();
    void bounceY();

private:
    sf::RectangleShape shape;
    sf::Vector2f velocity;

};



#endif //PROJ1_BALL_H
