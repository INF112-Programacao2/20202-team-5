#include "deck.h"


Deck::Deck(){
  this->fillDeck();
}

std::vector<Card*> Deck::get_cards() {
  return this->_cards;
}

void Deck::fillDeck() {
  std::string c_list[4] = {"blue", "red", "green", "yellow"};
  for (int i=0; i<4; i++) {
    for (int j=0; j<10; j++) {
      this->_cards.push_back(newNumberedCard(c_list[i],j));
    }
  }
}

Card* Deck::get_topCard() {
  return this->_cards.back();
}

//get_topCards(int ammount);

Card* Deck::newNumberedCard(std::string color, int number) {
  Card* c = new NumberedCard(color, number);
  return c;
}

Card* Deck::drawCards(){
  int i = rand() % _cards.size();
  Card* copy = _cards[i];
  _cards.erase(_cards.begin() + i);
  return copy;
}