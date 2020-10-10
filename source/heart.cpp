#include "../header/heart.h"

Heart::Heart() {

}

Heart::Heart(sf::Texture& texture) {
  this->setTexture(texture);
}

Heart::~Heart() {

}

void Heart::setState(State s) {
  this->setTextureRect(s);
}
