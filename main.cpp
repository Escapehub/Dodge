#include "header/entity.h"
#include "header/heart.h"
#include "header/menu.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Dodge");

    // Menu
    bool isPlaying = true;
    Menu menu(window.getSize().x, window.getSize().y);

    // Game over
    sf::Font font;
    font.loadFromFile("fonts/prstartk.ttf");
    sf::Text gameOver;
    gameOver.setFont(font);
    gameOver.setCharacterSize(100);
    gameOver.setFillColor(sf::Color::White);
    gameOver.setString("Game Over");
    gameOver.setPosition(sf::Vector2f(window.getSize().x / 4, window.getSize().y / 2));
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
            //   if (!isPlaying) {
            //     isPlaying = menu.Navigation(event, window);
            //   } else {
            //     if (event.key.code == sf::Keyboard::Escape)
            //       isPlaying = false;
            //   }
           }
        }
        // Generating enemies
        if (enemyClock.getElapsedTime().asSeconds() > 5) {
          Entity enemy;
          enemy.setRadius(10.f);
          enemy.setSpeed(0.1f);
          enemy.setFillColor(sf::Color::Red);
          enemy.setPosition(sf::Vector2f(window.getSize().x / 3, window.getSize().y / 3));
          enemies.push_back(enemy);
          enemyClock.restart();
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
        // Hit Reg
        if (!enemies.empty()) {
          for (int i = 0; i < enemies.size(); i++) {
            if (enemies[i].getGlobalBounds().intersects(player.getGlobalBounds())) {
              enemies.erase(enemies.begin() + i);
              heart.Hit();
            }
          }
        }
        if (heart.getState() < 4) {
          if (isPlaying) {
            // Drawing enemies
            for (Entity e : enemies) {
              window.draw(e);
            }
            // Moving enemies
            for (int i = 0; i < enemies.size(); i++) {
              enemies[i].movePlayer(Direction::Left);
              if (enemies[i].getPosition().x < 0)
                enemies.erase(enemies.begin() + i);
            }
            window.draw(player);
            window.draw(heart);
          } else {
            menu.Draw(window);
          }
        } else {
          window.draw(gameOver);
        }
        window.display();
    }

    return 0;
}
