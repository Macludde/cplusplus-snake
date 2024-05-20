#include "point.h"
#include "snake.h"
#include <vector>
#include <unordered_set>

#ifndef BOARD_H
#define BOARD_H

class Board {
public:
    Board(int width, int height, Snake* snake): width(width), height(height), snake(snake), food() {}
    Board(int width, int height, int resolution, Snake* snake): width(width), height(height), resolution(resolution), snake(snake), food() {}
    // Board(const Board& b): width(b.width), height(b.height), snake(b.snake), food(b.food) {}
    // Board& operator=(const Board& b) {
    //     width = b.width;
    //     height = b.height;
    //     food = b.food;
    //     return *this;
    // }

    bool isOutside(const Point point) const;
    
    bool isSnake(const Point point) const;
    bool isFood(const Point point) const;
    bool isFree(const Point point) const;

    void eatFood(const Point point);
    void addFood();

    void reset();

    void draw();
private:
    Point randomPoint() const;
    Point randomFreePoint() const;

    Snake* snake;
    
    std::unordered_set<Point> food;
    int width;
    int height;
    int resolution = 20;


    void drawFood(Point point);

};

#endif