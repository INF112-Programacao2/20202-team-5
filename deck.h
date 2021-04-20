#ifndef DECK_H
#define DECK_H

#include<vector>
#include <stdlib.h>
#include "numberedCard.h"
//#include "wildCard.h"
/* #include "plus4.h"
#include "skipCard.h"
#include "coloredDrawCard.h" */

class Deck {
private:
  std::vector<Card*> _cards;
public:
  Deck();
  std::vector<Card*> get_cards();
//  void fillDeck();
  Card* get_topCard();
//  Card* newNumberedCard(std::string color, int number);
  Card* drawCards();
//  get_topCards(int ammount);
/*  Card* newWildCard();
  Card* newPlus4();
  Card* newSkipCard(std::string color);
  Card* newColoredDrawCard(std::string color); */
};

#endif
