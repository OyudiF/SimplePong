//
// Created by Manutenção on 31/03/2026.
//

#ifndef PROJ1_PADDLE_H
#define PROJ1_PADDLE_H
#pragma once
#include <SFML/Graphics.hpp>


class Paddle {
public:
    // Posição inicial de X e Y
    Paddle(float startX, float startY);

    // Métodos ue roda todo frame
    void update(float dt, bool isPlayerOne);
    void render(sf::RenderWindow& window);

    // Methods para pegar a posição da raquete
    sf::FloatRect getBounds() const;

private:
    sf::RectangleShape shape;
    float speed;
};



#endif //PROJ1_PADDLE_H
