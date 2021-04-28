#include "stack.h"
#include "card.h"
Stack::Stack() {
  this->_cards.clear();
}

std::vector<Card*> Stack::get_cards() {
  return this->_cards;
}

Card* Stack::get_topCard() {
  return this->_cards.back();
}

void Stack::set_topCard(Card* card){
  _cards.push_back(card);
}
