#include <SFML/Graphics.hpp>
#include <iostream>
#define MAIN_MENU_ITEMS 3
#define OPTIONS_MENU_ITEMS 3

enum class CurrentMenu { Main, Options };

class Menu
{
public:
  Menu(float, float);
  virtual ~Menu();
  void Draw(sf::RenderWindow&);
  bool Navigation(sf::Event&, sf::RenderWindow&);
private:
  int mainMenuSelected, optionsMenuSelected, width, height, selectedDifficulty = 1;
  sf::Font font;
  sf::Text mainMenu[MAIN_MENU_ITEMS];
  sf::Text optionsMenu[OPTIONS_MENU_ITEMS];
  sf::Text title, difficulty;
  CurrentMenu current = CurrentMenu::Main;
  int getDifficulty() { return selectedDifficulty; }
};
