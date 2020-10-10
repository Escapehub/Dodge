# Dodge

## Compile

sudo g++ main.cpp source/* -lsfml-graphics -lsfml-window -lsfml-system

## To do

- [x] create player
- [ ] create enemy
- [x] player movement
- [ ] enemy movement
- [ ] collision detection
- [x] create heart

## Class Structure
| Entity                                                            |Heart                                                                     | Heart                                                                     |
|-------------------------------------------------------------------|---------------------------------------------------------------------------|
| Entity()<br>~Entity()<br>setSpeed(float)<br>movePlayer(Direction) |Heart()<br>Heart(sf::Texture&)<br>~Heart()<br>setState(int)<br>getState() |

## Media
![Heart Sprite](sprites/hearts.png)
