#include "hand.h"

Hand::Hand(Game game){
  this->_cards.clear();
  this->draw(7, game);
}

void Hand::draw(int ammount, Game game){
  for (int i=0; i<ammount; i++){
    this->_cards.push_back(game.get_board()->get_deck()->drawCards());
  }
}

void Hand::play(int card, Game game){
  game.get_board()->get_stack()->set_topCard(this->_cards.at(card)->copy());
  _cards.erase(this->_cards.begin() + card);
}

bool Hand::hasPlay(Game game){
    for(int i=0;i < _cards.size();i++){
        if((_cards.at(i)->get_color() == game.get_board()->get_stack()->get_topCard()->get_color()) || (_cards.at(i)->get_number() == game.get_board()->get_stack()->get_topCard()->get_number())) {
            return true;
        }
    }
    return false;
}

void Hand::noPlay(Game game) {
  this->draw(1, game);
  if (this->_cards.back()->get_color() == game.get_board()->get_stack()->get_topCard()->get_color() || this->_cards.back()->get_number() == game.get_board()->get_stack()->get_topCard()->get_number()) {
    this->play(this->_cards.size() - 1, game);
  }
  game.next_player();
}
