#include <SFML/Graphics.hpp>

enum class State {
  1 = sf::IntRect(0, 0, 237, 206),
  2 = sf::IntRect(0, 237, 237, 206),
  3 = sf::IntRect(0, 474, 237, 206),
  4 = sf::IntRect(0, 711, 237, 206),
  5 = sf::IntRect(0, 948, 237. 206)
};

class Heart : public sf::Sprite
{
public:
  Heart();
  Heart(sf::Texture&);
  virtual ~Heart();
  void setState(State);
};
