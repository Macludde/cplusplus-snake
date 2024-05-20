#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.h"
#include "config.h"
#include <ctime>

int main()
{
    std::srand(std::time(nullptr));
    auto window = sf::RenderWindow{ { config.windowWidth, config.windowHeight }, "SnakeGame" };
    window.setFramerateLimit(10);
    Game game;

    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        window.clear();


        if (!game.step()) {
            std::cout << "Game over." << std::endl;
            return 0;
        }
        game.draw(window);

        window.display();
    }
}
