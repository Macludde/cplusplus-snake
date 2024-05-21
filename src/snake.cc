#include "point.h"
#include "snake.h"
#include <vector>
#include <algorithm>
#include <iostream>

void Snake::changeDirection(Point direction) {
    if (direction == this->direction) return;
    Point summed = this->direction+direction;
    if (summed.x == 0 && summed.y == 0) {
        // opposite direction
        return;
    }
    this->direction = direction;
}

Point Snake::nextPosition() const {
    return head + direction;
    // The below code enables "looping" around the edges, like a torus
    // Point newPos = head + direction;
    // return Point((newPos.x + config.width)%config.width, (newPos.y + config.height)%config.height);
}

void Snake::move() {
    if (foodBank > 0)
        --foodBank;
    else
        body.pop_back();
    body.push_front(head);
    head = nextPosition();
}

void Snake::grow() {
    ++foodBank;
}

void Snake::reset(Point headPosition) {
    direction = UP;
    body.clear();
    head = headPosition;
    addInitialBodyPositions();
}
void Snake::addInitialBodyPositions() {
    Point curr = head - direction;
    for (int i = 0; i < 3; ++i) {
        body.push_back(curr);
        curr = curr - direction;
    }
}

bool Snake::isPartOfSnake(Point point) {
    if (point == head) {
        return true;
    }
    return std::find_if(body.begin(), body.end(), [&point](Point p) {
        return p == point;
    }) != body.end();
}