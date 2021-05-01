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
  this->_cards.push_back(card);
  this->_cards.back()->set_sprite(al_load_bitmap(this->_cards.back()->get_spriteName().c_str()));
}

std::string Stack::get_color() {
  return this->_cards.back()->get_color();
}

int Stack::get_number() {
  return this->_cards.back()->get_number();
}

void Stack::begin(Game game) {
  this->_cards.push_back(game.get_board()->get_deck()->drawCards());
}
