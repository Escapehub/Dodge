#include <SFML/Graphics.hpp>
#include <iostream>
#define MAX_NUMBER_OF_ITEMS 3

class Menu
{
public:
  Menu(float, float);
  virtual ~Menu();
  void Draw(sf::RenderWindow&);
  void moveUp();
  void moveDown();
  int getPressedItem() { return selectedItemIndex; }
private:
  int selectedItemIndex;
  sf::Font font;
  sf::Text menu[MAX_NUMBER_OF_ITEMS];
  sf::Text title;
};
