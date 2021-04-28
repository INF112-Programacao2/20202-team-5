#include "card.h"

std::string Card::get_name() {
  return this->_name;
}

bool Card::isPlayable() {
  return true;
}
