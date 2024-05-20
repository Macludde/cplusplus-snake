#include <SFML/Graphics.hpp>
#include "game.h"

int main()
{
    auto window = sf::RenderWindow{ { 1920u, 1080u }, "SnakeGame" };
    window.setFramerateLimit(144);
    GameOptions options(100, 100);
    Game game(options);

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
        window.display();
    }
}
