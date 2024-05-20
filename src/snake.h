#include "point.h"
#include <deque>
#include <iostream>
#include <SFML/Graphics.hpp>

#ifndef SNAKE_H
#define SNAKE_H

class Snake {
public:
    Snake(const Point headPosition): head(headPosition), body(), direction(UP) {
        addInitialBodyPositions();
    }
    
    void changeDirection(const Point direction);
    const Point nextPosition();
    void move(bool shouldGrow);

    bool isPartOfSnake(Point point);
    
    void reset(Point headPosition);
    
    void draw(sf::RenderTarget& target);
private:
    void addInitialBodyPositions();
    Point head;
    Point direction;
    std::deque<Point> body;

    void drawHead(sf::RenderTarget& target);
    void drawBodyPiece(sf::RenderTarget& target, int index);
};

#endif