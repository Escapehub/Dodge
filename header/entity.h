#include <SFML/Graphics.hpp>

enum class Direction { Up, Down, Left, Right };

class Entity : public sf::CircleShape
{
public:
  Entity();
  virtual ~Entity();
  void setSpeed(float);
  void movePlayer(Direction);
private:
  float speed;
};
