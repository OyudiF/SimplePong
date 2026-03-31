#include "Game.h"
#include "Paddle.h"

// Construtor
Game::Game() : window(sf::VideoMode({800, 600}), "Pong C++"),
    paddle1(50.f, 250.f),
    paddle2(735.f, 250.f),
    ball(392.f, 292.f),
    scoreText(font)
{
    window.setFramerateLimit(60);

    if (!font.openFromFile("arial.ttf")) {
        printf("Erro: Nao foi possivel carregar a fonte arial.ttf\n");
    }

    // Placar
    scoreText.setCharacterSize(50);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setString("0 - 0");
    scoreText.setPosition({340.f, 20.f});
}

// Loop principal
void Game::run() {
    sf::Clock clock;
    while (window.isOpen()) {
        float dt = clock.restart().asSeconds();
        processEvents();
        update(dt);
        render();
    }
}

// Apenas com os inputs e janela
void Game::processEvents() {
    while (const std::optional event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window.close();
        }
    }
}

// Atualizar raquetes
void Game::update(float dt) {
    paddle1.update(dt, true);
    paddle2.update(dt, false);
    ball.update(dt);

    // Colisão bola x raquetes
    sf::FloatRect ballBounds = ball.getBounds();
    sf::FloatRect p1Bounds = paddle1.getBounds();
    sf::FloatRect p2Bounds = paddle2.getBounds();

    if (ballBounds.findIntersection(p1Bounds).has_value()) {
        ball.bounceX();

        sf::Vector2f ballPos = ballBounds.position;
        ballPos.x = p1Bounds.position.x + p1Bounds.size.x;
        ball.setPosition(ballPos);
    }
    else if (ballBounds.findIntersection(p2Bounds).has_value()) {
        ball.bounceX();

        sf::Vector2f ballPos = ballBounds.position;
        ballPos.x = p2Bounds.position.x - ballBounds.size.x;
        ball.setPosition(ballPos);
    }

    checkScore();
}

// Apenas com o desenho da tela
void Game::render() {
    window.clear(sf::Color(15, 0, 133));

    paddle1.render(window);
    paddle2.render(window);
    ball.render(window);

    window.draw(scoreText);

    window.display();
}

void Game::checkScore() {
    sf::Vector2f ballPos = ball.getBounds().position;

    if (ballPos.x < 0.f) {
        scorePlayer2++;
        ball.reset();
    }
    else if (ballPos.x > 800.f) {
        scorePlayer1++;
        ball.reset();
    }

    scoreText.setString(std::to_string(scorePlayer1) + " - " + std::to_string(scorePlayer2));
}
