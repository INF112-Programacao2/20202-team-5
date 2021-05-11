#include "hand.h"
#include "game.h"
#include <iostream>

Hand::Hand(Game game){
  this->_cards.clear();
}

void Hand::draw(int ammount, Game game){
  for (int i=0; i<ammount; i++){
    this->_cards.push_back(game.get_board()->get_deck()->drawCards());
    game.get_board()->get_deck()->get_cards().back()->set_sprite(al_load_bitmap(game.get_board()->get_deck()->get_cards().back()->get_spriteName().c_str()));
  }
}

void Hand::play(int card, Game game){
  game.get_board()->get_stack()->set_topCard(this->_cards.at(card)->copy());
  this->_cards.at(card)->onPlay(game);
  this->_cards.erase(this->_cards.begin() + card);
  //game.next_player();
}

bool Hand::hasPlay(Game game){
    for(int i = 0; i < this->_cards.size(); i++){
        if((this->_cards.at(i)->get_color() == game.get_board()->get_stack()->get_color()) || (this->_cards.at(i)->get_number() == game.get_board()->get_stack()->get_number())) {
          return true;
        }
    }
    //this->noPlay(game);
    return false;
}

void Hand::noPlay(Game game) {
  this->draw(1, game);
  if (this->_cards.back()->get_color() == game.get_board()->get_stack()->get_color() || this->_cards.back()->get_number() == game.get_board()->get_stack()->get_number()) {
    this->play(this->_cards.size() - 1, game);
  }
  game.next_player();
}

std::vector<Card*> Hand::get_cards() {
  return this->_cards;
}
