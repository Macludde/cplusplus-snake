#ifndef CONFIG_H
#define CONFIG_H

struct GameOptions {
    unsigned int width;
    unsigned int height;
    unsigned int resolution; // pixels per square side
    unsigned int windowHeight;
    unsigned int windowWidth;

    unsigned char amountOfFood = 2;

    GameOptions(int width, int height, int resolution): width(width), height(height), resolution(resolution) {
        windowWidth = resolution*width;
        windowHeight = resolution*height;
    };
};

extern GameOptions config;

#endif