#include "point.h"
#include "board.h"
#include "game.h"
#include "snake.h"
#include <stdexcept>

void Game::reset() {
    board.reset();
    snake.reset(startingPoint);
}

bool Game::step() {
    Point head = snake.nextPosition();
    if (board.isOutside(head)) {
        return false;
    }
    if (board.isFood(head)) {
        board.eatFood(head);
        snake.move(true);
        board.addFood();
    } else {
        snake.move(false);
    }
    return true;
}

void Game::onKeyPress(Keypress key) {
    switch (key) {
        case Keypress::KEY_UP:
            snake.changeDirection(UP);
            break;
        case Keypress::KEY_LEFT:
            snake.changeDirection(LEFT);
            break;
        case Keypress::KEY_DOWN:
            snake.changeDirection(DOWN);
            break;
        case Keypress::KEY_RIGHT:
            snake.changeDirection(RIGHT);
            break;
        case Keypress::KEY_RESTART:
            Game::reset();
            break;
        default:
            throw new std::invalid_argument("Keypress is not handled");
    }
}