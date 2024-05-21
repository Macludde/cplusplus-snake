#include "point.h"
#include <deque>
#include <iostream>
#include <SFML/Graphics.hpp>

#ifndef SNAKE_H
#define SNAKE_H

class Snake {
public:
    Snake(Point headPosition): head(headPosition), body(), direction(UP) {
        addInitialBodyPositions();
    }
    
    void changeDirection(Point direction);
    Point currentDirection() { return direction; };
    Point nextPosition() const;
    void move();
    void grow();

    Point tail() { return body.back(); }

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