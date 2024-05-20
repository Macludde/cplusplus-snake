#include "config.h"
#include "point.h"
#include "snake.h"
#include <vector>
#include <unordered_set>
#include <SFML/Graphics.hpp>

#ifndef BOARD_H
#define BOARD_H

class Board {
public:
    Board(Snake* snake): snake(snake), food() {};
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

    void draw(sf::RenderTarget& target);
private:
    Point randomPoint() const;
    Point randomFreePoint() const;

    int width = config.width;
    int height = config.height;

    Snake* snake;
    
    std::unordered_set<Point> food;

    void drawFood(sf::RenderTarget& target, Point point);
};

#endif