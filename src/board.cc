#include "config.h"
#include "point.h"
#include "board.h"
#include <vector>
#include <unordered_set>
#include <random>
#include <iostream>
#include <ctime>

bool Board::isOutside(Point point) const {
    if (point.x < 0 || point.x >= width) {
        return true;
    }
    if (point.y < 0 || point.y >= height) {
        return true;
    }
    return false;
}
    
bool Board::isFree(Point point) const {
    return !isFood(point) && !isSnake(point);
}
bool Board::isFood(Point point) const {
    return food.find(point) != food.end();
}
bool Board::isSnake(Point point) const {
    return snake.isPartOfSnake(point);
}

void Board::eatFood(Point point) {
    food.erase(point);
}

void Board::addFood() {
    const Point positionOfFood = randomFreePoint();
    food.insert(positionOfFood);
}

void Board::reset() {
    food.clear();
    
    for (int i = 0; i < config.amountOfFood; ++i)
        addFood();
}

using std::rand;

Point Board::randomPoint() const {
    return Point(rand() % width, rand() % height);
}

Point Board::randomFreePoint() const {
    Point point = randomPoint();
    while (!isFree(point)) {
        point = randomPoint();
    } 
    return point;
}