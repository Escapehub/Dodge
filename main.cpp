#include "header/entity.h"
#include "header/heart.h"
#include "header/menu.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Dodge");
    // Menu
    bool isPlaying = false;
    Menu menu(window.getSize().x, window.getSize().y);
    // Player
    Entity player;
    player.setRadius(20.f);
    player.setSpeed(0.1f);
    player.setFillColor(sf::Color::White);
    player.setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));

    // Heart
    sf::Texture heartTexture;
    heartTexture.loadFromFile("sprites/hearts.png");
    Heart heart(heartTexture);

    // Enemies
    std::vector<Entity> enemies;
    sf::Clock enemyClock;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
              if (!isPlaying) {
                if (event.key.code == sf::Keyboard::Up)
                  menu.moveUp();
                else if (event.key.code == sf::Keyboard::Down)
                  menu.moveDown();
                else if (event.key.code == sf::Keyboard::Return) {
                  switch (menu.getPressedItem()) {
                    case 0:
                      isPlaying = true;
                      break;
                    case 1:
                      std::cout << "Option key pressed" << std::endl;
                      break;
                    case 2:
                      window.close();
                      break;
                  }
                }
              } else {
                if (event.key.code == sf::Keyboard::Escape)
                  isPlaying = false;
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

        if (isPlaying) {
          window.draw(player);
          window.draw(heart);
        } else {
          menu.Draw(window);
        }
        window.display();
    }

    return 0;
}
