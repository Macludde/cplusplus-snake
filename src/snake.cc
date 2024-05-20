#include "point.h"
#include "snake.h"
#include <vector>
#include <algorithm>
#include <iostream>

void Snake::changeDirection(const Point direction) {
    this->direction = direction;
}

const Point Snake::nextPosition() {
    return head + direction;
}

void Snake::move(bool shouldGrow) {
    if (!shouldGrow)
        body.pop_back();
    body.push_front(head);
    head = head + direction;
}

void Snake::reset(Point headPosition) {
    head = headPosition;
    addInitialBodyPositions();
}
void Snake::addInitialBodyPositions() {
    Point curr = head - direction;
    for (int i = 0; i < 3; ++i) {
        body.push_front(curr);
        curr = curr - direction;
    }
}

bool Snake::isPartOfSnake(Point point) {
    return false;
    std::cout << body[0] << ", " << body[1] << ", " << body[2] << std::endl;
    if (point == head) {
        return true;
    }
    return false;
    return std::find(body.begin(), body.end(), point) != body.end();
}