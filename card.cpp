#include "card.h"
#include "game.h"

std::string Card::get_name() {
  return this->_name;
}

/*
  Usa de informaçoes provenientes da classe Game para verificar se a carta pode ser jogar ou nao
*/
bool Card::isPlayable() {
  if (this->_color == "black" || this->_color.compare(game.get_board()->get_color()) == 0 || this->_number == game.get_board()->get_number()) {
    return true;
  }
  if(this->_name.compare(game.get_board()->get_stack()->get_topCard()->get_name()) == 0 && this->_name.compare("numberedCard") != 0) {
    return true;
  }
  return false;
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

std::string Card::get_color() {
  return "black";
}

int Card::get_number() {
  return -1;
}
