#ifndef PROJ1_GAME_H
#define PROJ1_GAME_H
#pragma once
#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Paddle.h"


class Game {
public:
    // Construtor
    Game();

    void run();

private:
    void processEvents();
    void update(float dt);
    void render();

    sf::RenderWindow window;

    Paddle paddle1;
    Paddle paddle2;

    Ball ball;

    int scorePlayer1 = 0;
    int scorePlayer2 = 0;

    sf::Font font;
    sf::Text scoreText;

    void checkScore();
};



#endif //PROJ1_GAME_H
