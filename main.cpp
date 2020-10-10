#include <iostream>
#include "header/entity.h"
#include "header/heart.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Dodge");
    Entity player;
    player.setRadius(20.f);
    player.setSpeed(0.1f);
    player.setFillColor(sf::Color::White);
    player.setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));

    sf::Texture heartTexture;
    heartTexture.loadFromFile("sprites/hearts.png");
    Heart heart(heartTexture);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
            if (event.type == sf::Event::KeyPressed) {
              if (event.key.code == sf::Keyboard::F) {
                int state = heart.getState();
                std::cout << state << std::endl;
                state++;
                heart.setState(state);
              }
            }
        }

        window.clear();
        // Player movement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
          player.movePlayer(Direction::Up);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
          player.movePlayer(Direction::Right);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
          player.movePlayer(Direction::Down);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
          player.movePlayer(Direction::Left);

        window.draw(player);
        window.draw(heart);
        window.display();
    }

    return 0;
}
