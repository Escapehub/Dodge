#include <SFML/Graphics.hpp>

class Heart : public sf::Sprite
{
public:
  Heart();
  Heart(sf::Texture&);
  virtual ~Heart();
  void setState(int);
  int getState();
private:
  int currentState = 1;
  std::map<int, sf::IntRect> State =
  {
    { 1, sf::IntRect(0, 0, 237, 206) },
    { 2, sf::IntRect(237, 0, 237, 206) },
    { 3, sf::IntRect(474, 0, 237, 206) },
    { 4, sf::IntRect(711, 0, 237, 206) },
    { 5, sf::IntRect(948, 0, 237, 206) }
  };
};
