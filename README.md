![C/C++ CI](https://github.com/Escapehub/Dodge/workflows/C/C++%20CI/badge.svg)
# Dodge

Simple survival game. Move the white dot and don't get hit by the red ones.

## Compile

sudo g++ main.cpp source/* -lsfml-graphics -lsfml-window -lsfml-system

## To do

- [x] create player
- [ ] create enemy
- [x] player movement
- [ ] enemy movement
- [ ] collision detection
- [x] create heart
- [x] create multi-menu~
- [x] difficulty within options screen~

## Class Structure
| Entity                                                            | Heart                                                                              | Menu                                                                                                                    |
|-------------------------------------------------------------------|------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------|
| Entity()<br>~Entity()<br>setSpeed(float)<br>movePlayer(Direction) | Heart()<br>Heart(sf::Texture&)<br>~Heart()<br>setState(int)<br>getState()<br>Hit() | Menu(float, float)<br>~Menu()<br>Draw(sf::RenderWindow&)<br>Navigation(sf:Event&, sf::RenderWindow&)<br>getDifficulty() |

## Media
![Heart Sprite](sprites/hearts.png)
