#include <algorithm>
#include<random>
#include "deck.h"
#include "card.h"
#include "wildCard.h"
#include "plus4.h"
#include "skipCard.h"
#include "coloredDrawCard.h"
#include "reverseCard.h"

Deck::Deck(){
  this->fillDeck();
  this->shuffle();
}

std::vector<Card*> Deck::get_cards() {
  return this->_cards;
}

/*
  Método responsável por preencher o deck com todas as suas cartas
*/
void Deck::fillDeck() {
  std::string c_list[4] = {"blue", "red", "green", "yellow"};
  for (int i=0; i<4; i++) {
   this->_cards.push_back(newWildCard());
   this->_cards.push_back(newPlus4());

   for (int j=0; j<4; j++) {
     this->_cards.push_back(newSkipCard(c_list[i]));
     this->_cards.push_back(newColoredDrawCard(c_list[i]));
     this->_cards.push_back(newReverseCard(c_list[i]));
   }

    for (int j=0; j<10; j++) {
      this->_cards.push_back(newNumberedCard(c_list[i],j));
    }
  }
}

Card* Deck::get_topCard() {
  return this->_cards.back();
}

Card* Deck::newNumberedCard(std::string color, int number) {
  Card* c = new NumberedCard(color, number);
  return c;
}
/*
  Responsável por gerenciar a compra de cartas, retornando uma copia da carta que será comprada e excluindo a mesma do deck.
  Caso o deck esteja vazio também o preenche denovo.
*/
Card* Deck::drawCards(){
  Card* copy = this->get_topCard()->copy();
  this->_cards.erase(this->_cards.end() - 1);
  if(this->_cards.size() == 0) {
    fillDeck();
    shuffle();
  }
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

Card* Deck::newReverseCard(std::string color) {
  Card* c = new ReverseCard(color);
  return c;
}

std::random_device rd;

int myrandom (int i) {
  return rd()%i;
}

/*
  Metodo que embaralha o deck
*/
void Deck::shuffle() {
  std::random_shuffle (this->_cards.begin(), this->_cards.end(), myrandom);
}
