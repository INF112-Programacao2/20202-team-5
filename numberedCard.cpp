#include "numberedCard.h"
#include "game.h"

NumberedCard::NumberedCard(std::string color, int number) {
  this->_color = color;
  this->_number = number;
  this->_name = "numberedCard";
  this->_spriteName = "sprites/" + color + std::to_string(number) + ".bmp";
}

int NumberedCard::get_number() {
  return this->_number;
}

void NumberedCard::set_number(int number) {
  this->_number = number;
}

NumberedCard* NumberedCard::copy() {
	NumberedCard* c = new NumberedCard(_color, _number);
	return c;
}

void NumberedCard::onPlay() {
  game.next_player();
}
