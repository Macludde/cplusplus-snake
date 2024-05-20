#include "config.h"
#include "point.h"
#include "snake.h"
#include "board.h"
#include "game.h"
#include <vector>
#include <algorithm>
#include <SFML/Graphics.hpp>


int padding = config.resolution*0.1;

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
    sf::RectangleShape shape(sf::Vector2f(config.resolution-padding*2, config.resolution-padding*2));
    shape.setFillColor(sf::Color::Yellow);
    shape.setPosition(sf::Vector2f(config.resolution*point.x+padding, config.resolution*point.y+padding));
    target.draw(shape);
}

sf::RectangleShape styleSnake(sf::RectangleShape shape) {
    shape.setFillColor(sf::Color::White);
    shape.setOutlineColor(sf::Color::Black);
    return shape;
}

sf::RectangleShape verticalConnectingSquare(sf::Vector2f(padding, config.resolution - padding*2));
sf::RectangleShape horizontalConnectingSquare(sf::Vector2f(config.resolution - padding*2, padding));

void drawConnectingSquare(sf::RenderTarget& target, Point pos, Point direction) {
    // direction
    // (0,1) == above
    // (0,-1) == below
    // (-1,0) == right
    // (1,0) == left
    // (0,0) == nothing
    if (direction.x != 0) {
        verticalConnectingSquare.setPosition(pos.x, pos.y);
        if (direction.x == -1)
            verticalConnectingSquare.move(config.resolution-padding, 0);
        verticalConnectingSquare.move(0, padding);
        target.draw(styleSnake(verticalConnectingSquare));
    } else if (direction.y != 0) {
        horizontalConnectingSquare.setPosition(pos.x, pos.y);
        if (direction.y == -1)
            horizontalConnectingSquare.move(0, config.resolution - padding);
        horizontalConnectingSquare.move(padding, 0);
        target.draw(styleSnake(horizontalConnectingSquare));
    }
}

void Snake::draw(sf::RenderTarget& target) {
    drawHead(target);
    for (int i = 0; i < body.size(); ++i)
        drawBodyPiece(target, i);
}

void Snake::drawHead(sf::RenderTarget& target) {
    sf::RectangleShape shape(sf::Vector2f(config.resolution-padding*2, config.resolution-padding*2));
    shape.setPosition(head.x*config.resolution+padding, head.y*config.resolution+padding);
    target.draw(styleSnake(shape));
    Point after = body[0];
    drawConnectingSquare(target, head*config.resolution, head-after);
    drawConnectingSquare(target, head*config.resolution, direction*-1);
}



void Snake::drawBodyPiece(sf::RenderTarget& target, int i) {
    Point point = body[i];

    sf::RectangleShape shape(sf::Vector2f(config.resolution - padding*2, config.resolution - padding*2));
    shape.setPosition(point.x*config.resolution + padding, point.y*config.resolution + padding);
    target.draw(styleSnake(shape));

    // Connecting squares
    Point before = i == 0 ? head : body[i-1];
    Point after = i == body.size() - 1 ? point : body[i+1];
    drawConnectingSquare(target, point*config.resolution, point-before);
    drawConnectingSquare(target, point*config.resolution, point-after);
    
}