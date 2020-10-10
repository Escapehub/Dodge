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
| Entity                                                            | Heart                                                                     | Menu                                                                                                   |
|-------------------------------------------------------------------|---------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------|
| Entity()<br>~Entity()<br>setSpeed(float)<br>movePlayer(Direction) | Heart()<br>Heart(sf::Texture&)<br>~Heart()<br>setState(int)<br>getState() | Menu(float, float)<br>~Menu()<br>Draw(sf::RenderWindow&)<br>moveUp()<br>moveDown()<br>GetPressedItem() |

## Media
![Heart Sprite](sprites/hearts.png)
