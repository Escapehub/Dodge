#include "../header/entity.h"

Entity::Entity() {

}

Entity::~Entity() {

}

void Entity::setSpeed(float s) {
  speed = s;
}

void Entity::movePlayer(Direction direction) {
  switch (direction) {
    case Direction::Up:
      this->move(0, -speed);
      break;
    case Direction::Down:
      this->move(0, speed);
      break;
    case Direction::Left:
      this->move(-speed, 0);
      break;
    case Direction::Right:
      this->move(speed, 0);
      break;
  }
}
