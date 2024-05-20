#include "board.h"
#include "snake.h"

#ifndef GAME_H
#define GAME_H
enum Keypress {
    KEY_UP = 0,
    KEY_RIGHT = 1,
    KEY_DOWN = 2,
    KEY_LEFT = 3,
    KEY_RESTART = 10
};

struct GameOptions {
    int width;
    int height;
    int resolution = 20; // pixels per square side

    GameOptions(int width, int height): width(width), height(height) {};
    GameOptions(int width, int height, int resolution): width(width), height(height), resolution(resolution) {};
    GameOptions(const GameOptions& options): width(options.width), height(options.height), resolution(options.resolution) {};
};

class Game {
public:
    Game(GameOptions options): options(options), 
                               startingPoint(middlePoint(options.width, options.height)),
                               snake(startingPoint),
                               board(options.width, options.height, &snake)
                               {};

    void reset();
    bool step();
    void onKeyPress(Keypress key);

    void draw();
private:
    GameOptions options;
    Point startingPoint;

    Board board;
    Snake snake;
};

#endif