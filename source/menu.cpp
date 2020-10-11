#include "../header/menu.h"

Menu::Menu(float w, float h) {
  width = w;
  height = h;
  if (!font.loadFromFile("fonts/prstartk.ttf"))
    std::cout << "Failed to load font" << std::endl;

  // Main Menu
  title.setFont(font);
  title.setCharacterSize(100);
  title.setFillColor(sf::Color::White);
  title.setString("Dodge!");
  title.setPosition(sf::Vector2f(width / 3, 0));

  mainMenu[0].setFont(font);
  mainMenu[0].setCharacterSize(50);
  mainMenu[0].setFillColor(sf::Color::Red);
  mainMenu[0].setString("Play");
  mainMenu[0].setPosition(sf::Vector2f(width / 3, height / (MAIN_MENU_ITEMS + 1) * 1));

  mainMenu[1].setFont(font);
  mainMenu[1].setCharacterSize(50);
  mainMenu[1].setFillColor(sf::Color::White);
  mainMenu[1].setString("Options");
  mainMenu[1].setPosition(sf::Vector2f(width / 3, height / (MAIN_MENU_ITEMS + 1) * 2));

  mainMenu[2].setFont(font);
  mainMenu[2].setCharacterSize(50);
  mainMenu[2].setFillColor(sf::Color::White);
  mainMenu[2].setString("Exit");
  mainMenu[2].setPosition(sf::Vector2f(width / 3, height / (MAIN_MENU_ITEMS + 1) * 3));

  mainMenuSelected = 0;

  // Options Menu
  difficulty.setFont(font);
  difficulty.setCharacterSize(100);
  difficulty.setFillColor(sf::Color::White);
  difficulty.setString("Difficulty:");
  difficulty.setPosition(sf::Vector2f(width / 3, height / (OPTIONS_MENU_ITEMS + 1) * 1));

  optionsMenu[0].setFont(font);
  optionsMenu[0].setCharacterSize(50);
  optionsMenu[0].setFillColor(sf::Color::White);
  optionsMenu[0].setString("< Easy >");
  optionsMenu[0].setPosition(sf::Vector2f(width / 3, height / 2));

  optionsMenu[1].setFont(font);
  optionsMenu[1].setCharacterSize(50);
  optionsMenu[1].setFillColor(sf::Color::Red);
  optionsMenu[1].setString("< Medium >");
  optionsMenu[1].setPosition(sf::Vector2f(width / 3, height / 2));

  optionsMenu[2].setFont(font);
  optionsMenu[2].setCharacterSize(50);
  optionsMenu[2].setFillColor(sf::Color::White);
  optionsMenu[2].setString("< Hard >");
  optionsMenu[2].setPosition(sf::Vector2f(width / 3, height / 2));

  optionsMenuSelected = 1;
}

Menu::~Menu() {

}

void Menu::Draw(sf::RenderWindow& window) {
  if (current == CurrentMenu::Main) {
    window.draw(title);
    for (int i = 0; i < MAIN_MENU_ITEMS; i++) {
      window.draw(mainMenu[i]);
    }
  } else if (current == CurrentMenu::Options) {
    window.draw(difficulty);
    window.draw(optionsMenu[selectedDifficulty]);
  }

}

bool Menu::Navigation(sf::Event& event, sf::RenderWindow& window) {
  if (current == CurrentMenu::Main) {
    if (event.key.code == sf::Keyboard::Up) {
      if (mainMenuSelected - 1 >= 0) {
        mainMenu[mainMenuSelected].setFillColor(sf::Color::White);
        mainMenuSelected--;
        mainMenu[mainMenuSelected].setFillColor(sf::Color::Red);
      }
    } else if (event.key.code == sf::Keyboard::Down) {
      if (mainMenuSelected + 1 < MAIN_MENU_ITEMS) {
        mainMenu[mainMenuSelected].setFillColor(sf::Color::White);
        mainMenuSelected++;
        mainMenu[mainMenuSelected].setFillColor(sf::Color::Red);
      }
    } else if (event.key.code == sf::Keyboard::Return) {
      switch (mainMenuSelected) {
        case 0:
          return true;
          break;
        case 1:
          current = CurrentMenu::Options;
          break;
        case 2:
          window.close();
          break;
      }
    }
  } else if (current == CurrentMenu::Options) {
    if (event.key.code == sf::Keyboard::Left) {
      if (optionsMenuSelected - 1 >= 0) {
        optionsMenu[optionsMenuSelected].setFillColor(sf::Color::White);
        optionsMenuSelected--;
        optionsMenu[optionsMenuSelected].setFillColor(sf::Color::Red);
      }
    } else if (event.key.code == sf::Keyboard::Right) {
      if (optionsMenuSelected +1 < OPTIONS_MENU_ITEMS) {
        optionsMenu[optionsMenuSelected].setFillColor(sf::Color::White);
        optionsMenuSelected++;
        optionsMenu[optionsMenuSelected].setFillColor(sf::Color::Red);
      }
    } else if (event.key.code == sf::Keyboard::Escape) {
      selectedDifficulty = optionsMenuSelected;
      current = CurrentMenu::Main;
    }
  }
}
