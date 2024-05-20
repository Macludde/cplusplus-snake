#include "point.h"
#include <deque>

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
    
    void draw();
private:
    void addInitialBodyPositions();
    Point head;
    Point direction;
    std::deque<Point> body;
};

#endif