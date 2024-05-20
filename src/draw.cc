#include "config.h"
#include "point.h"
#include "snake.h"
#include "board.h"
#include "game.h"
#include <vector>
#include <algorithm>
#include <SFML/Graphics.hpp>

void Game::draw(sf::RenderTarget& target) {
    board.draw(target);
    snake.draw(target);
}

void Board::draw(sf::RenderTarget& target) {
    auto iter = food.begin();
    while (iter != food.end()) {
        drawFood(target, *iter);
        iter++;
    }
}

void Board::drawFood(sf::RenderTarget& target, Point point) {
    sf::RectangleShape shape(sf::Vector2f(config.resolution, config.resolution));
    shape.setFillColor(sf::Color::Yellow);
    shape.setPosition(sf::Vector2f(config.resolution*point.x, config.resolution*point.y));
    target.draw(shape);
}

sf::RectangleShape styleSnake(sf::RectangleShape shape) {
    shape.setFillColor(sf::Color::White);
    shape.setOutlineColor(sf::Color::Black);
    return shape;
}

void Snake::draw(sf::RenderTarget& target) {
    drawHead(target);
    for (int i = 0; i < body.size(); ++i)
        drawBodyPiece(target, i);
}

void Snake::drawHead(sf::RenderTarget& target) {
    sf::RectangleShape shape(sf::Vector2f(config.resolution, config.resolution));
    shape.setPosition(head.x*config.resolution, head.y*config.resolution);
    target.draw(styleSnake(shape));
}

void Snake::drawBodyPiece(sf::RenderTarget& target, int i) {
    Point point = body[i];
    sf::RectangleShape shape(sf::Vector2f(config.resolution, config.resolution));
    shape.setPosition(point.x*config.resolution, point.y*config.resolution);
    target.draw(styleSnake(shape));
}