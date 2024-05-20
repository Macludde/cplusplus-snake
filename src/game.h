#include "config.h"
#include "board.h"
#include "snake.h"
#include <SFML/Graphics.hpp>

#ifndef GAME_H
#define GAME_H
enum Keypress {
    KEY_UP = 0,
    KEY_RIGHT = 1,
    KEY_DOWN = 2,
    KEY_LEFT = 3,
    KEY_RESTART = 10
};
class Game {
public:
    Game(): startingPoint(middlePoint(config.width, config.height)),
            snake(startingPoint),
            board(&snake),
            wantedDirection(UP) {
        reset();
    };

    void reset();
    bool step();
    void onKeyPress(Keypress key);

    void draw(sf::RenderTarget& target);
private:
    bool gameRunning = true;
    Point startingPoint;

    Board board;
    Snake snake;

    Point wantedDirection;
};

#endif