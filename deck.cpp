#include "deck.h"
#include "card.h"
#include "wildCard.h"
#include "plus4.h"
#include "skipCard.h"
#include "coloredDrawCard.h"

Deck::Deck(){
  this->fillDeck();
}

std::vector<Card*> Deck::get_cards() {
  return this->_cards;
}

 void Deck::fillDeck() {
  std::string c_list[4] = {"blue", "red", "green", "yellow"};
  for (int i=0; i<4; i++) {
   this->_cards.push_back(newWildCard());
   this->_cards.push_back(newPlus4());

   for (int j=0; j<4; j++) {
     this->_cards.push_back(newSkipCard(c_list[i]));
     this->_cards.push_back(newColoredDrawCard(c_list[i]));
   }

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
  Card* copy = this->get_topCard()->copy();
  this->_cards.erase(this->_cards.end() - 1);
  return copy;
}

 Card* Deck::newWildCard() {
  Card* c = new WildCard();
  return c;
}

Card* Deck::newPlus4() {
  Card* c = new Plus4();
  return c;
}

Card* Deck::newSkipCard(std::string color) {
  Card* c = new SkipCard(color);
  return c;
}


Card* Deck::newColoredDrawCard(std::string color) {
  Card* c = new ColoredDrawCard(color);
  return c;
}
