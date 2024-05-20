#include "point.h"
#include "snake.h"
#include <vector>
#include <algorithm>

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
    if (point == head) {
        return true;
    }
    return std::find(body.begin(), body.end(), point) != body.end();
}