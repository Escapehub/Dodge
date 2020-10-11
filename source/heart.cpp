#include "../header/heart.h"

Heart::Heart() {

}

Heart::Heart(sf::Texture& texture) {
  this->setScale(sf::Vector2f(0.2, 0.2));
  this->setTextureRect(State[currentState]);
  this->setTexture(texture);
}

Heart::~Heart() {

}

void Heart::setState(int s) {
  currentState = s;
  this->setTextureRect(State[currentState]);
}

int Heart::getState() {
  return currentState;
}

void Heart::Hit() {
  currentState++;
  this->setTextureRect(State[currentState]);
}
