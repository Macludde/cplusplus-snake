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
        for (auto event = sf::Event{}; window.pollEvent(event);) {
            if (event.type == sf::Event::Closed) 
                window.close();
            else if (event.type == sf::Event::KeyPressed) {
                switch (event.key.scancode)
                {
                    case sf::Keyboard::Scancode::Up:
                    case sf::Keyboard::Scancode::W:
                        game.onKeyPress(Keypress::KEY_UP);
                        break;
                    case sf::Keyboard::Scancode::Right:
                    case sf::Keyboard::Scancode::D:
                        game.onKeyPress(Keypress::KEY_RIGHT);
                        break;
                    case sf::Keyboard::Scancode::Down:
                    case sf::Keyboard::Scancode::S:
                        game.onKeyPress(Keypress::KEY_DOWN);
                        break;
                    case sf::Keyboard::Scancode::Left:
                    case sf::Keyboard::Scancode::A:
                        game.onKeyPress(Keypress::KEY_LEFT);
                        break;
                    case sf::Keyboard::Scancode::R:
                        game.onKeyPress(Keypress::KEY_RESTART);
                        break;
                    default:
                        break;
                }
            }
        }
        window.clear();

        game.step();
        game.draw(window);

        window.display();
    }
}
