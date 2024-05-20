#include "point.h"
#include "board.h"
#include "game.h"
#include "snake.h"
#include <stdexcept>

void Game::reset() {
    board.reset();
    snake.reset(startingPoint);
    gameRunning = true;
}

bool Game::step() {
    if (!gameRunning)
        return false;
    snake.changeDirection(wantedDirection);
    Point head = snake.nextPosition();
    if (board.isOutside(head) || (board.isSnake(head) && !(snake.tail() == head))) {
        gameRunning = false;
        return false;
    }
    snake.move();
    if (board.isFood(head)) {
        board.eatFood(head);
        board.addFood();
        snake.grow();
    }
    return true;
}

void Game::onKeyPress(Keypress key) {
    switch (key) {
        case Keypress::KEY_UP:
            if (snake.currentDirection() == DOWN) return;
            wantedDirection = UP;
            break;
        case Keypress::KEY_LEFT:
            if (snake.currentDirection() == RIGHT) return;
            wantedDirection = LEFT;
            break;
        case Keypress::KEY_DOWN:
            if (snake.currentDirection() == UP) return;
            wantedDirection = DOWN;
            break;
        case Keypress::KEY_RIGHT:
            if (snake.currentDirection() == LEFT) return;
            wantedDirection = RIGHT;
            break;
        case Keypress::KEY_RESTART:
            Game::reset();
            break;
        default:
            throw new std::invalid_argument("Keypress is not handled");
    }
}