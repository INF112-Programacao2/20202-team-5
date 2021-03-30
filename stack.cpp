#include "stack.h"

Stack::Stack() {
  this->_cards.clear();
}

std::vector<Card*> Stack::get_cards() {
  return this->_cards;
}

Card* Stack::get_topCard() {
  return this->_cards.back();
}
