#include "card.h"

std::string Card::get_name() {
  return this->_name;
}

bool Card::isPlayable() {
  return true;
}

ALLEGRO_BITMAP* Card::get_sprite() {
  return this->_sprite;
}

std::string Card::get_spriteName() {
  return this->_spriteName;
}

void Card::set_sprite(ALLEGRO_BITMAP* sprite) {
  this->_sprite = sprite;
}
