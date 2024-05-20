#include "config.h"
#include "point.h"
#include "board.h"
#include <vector>
#include <unordered_set>
#include <random>
#include <iostream>
#include <ctime>

Board::Board(Snake* snake): snake(snake), food() {
    for (int i = 0; i < config.amountOfFood; ++i)
        addFood();
}

bool Board::isOutside(Point point) const {
    if (point.x < 0 || point.x >= width) {
        return true;
    }
    if (point.y < 0 || point.y >= height) {
        return true;
    }
    return false;
}
    
bool Board::isFree(const Point point) const {
    return !isFood(point) && !isSnake(point);
}
bool Board::isFood(const Point point) const {
    std::cout << "Checking if food" << std::endl;
    return food.find(point) != food.end();
}
bool Board::isSnake(const Point point) const {
    std::cout << "Checking if snake" << std::endl;
    snake->isPartOfSnake(point);
    std::cout << "Check of snake done" << std::endl;
    return snake->isPartOfSnake(point);
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