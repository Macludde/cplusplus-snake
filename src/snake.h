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
    Point currentDirection() { return direction; };
    const Point nextPosition();
    void move();
    void grow();

    const Point tail() { return body.back(); }

    bool isPartOfSnake(Point point);
    
    void reset(Point headPosition);
    
    void draw(sf::RenderTarget& target);
private:
    void addInitialBodyPositions();
    Point head;
    Point direction;
    std::deque<Point> body;
    int foodBank = 0;

    void drawHead(sf::RenderTarget& target);
    void drawBodyPiece(sf::RenderTarget& target, int index);
};

#endif