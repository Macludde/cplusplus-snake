#include "point.h"
#include "board.h"
#include <vector>
#include <unordered_set>
#include <random>
#include <SFML/Graphics.hpp>

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
    return food.find(point) != food.end();
}
bool Board::isSnake(const Point point) const {
    return snake->isPartOfSnake(point);
}

void Board::eatFood(Point point) {
    food.erase(point);
}

void Board::addFood() {
    Point positionOfFood = randomFreePoint();
    food.insert(positionOfFood);
}

void Board::reset() {
    food.clear();
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

void Board::draw() {
    auto iter = food.begin();
    while (iter != food.end()) {
        drawFood(*iter);
        iter++;
    }

}

void Board::drawFood(Point point) {
    // TODO
}
