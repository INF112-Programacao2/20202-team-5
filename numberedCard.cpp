#include "numberedCard.h"

NumberedCard::NumberedCard(std::string color, int number) {
  this->_color = color;
  this->_number = number;
}

int NumberedCard::get_number() {
  return this->_number;
}
void NumberedCard::set_number(int number) {
  this->_number = number;
}
