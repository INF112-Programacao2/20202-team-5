#ifndef DECK_H
#define DECK_H

#include<vector>
#include <stdlib.h>
#include "numberedCard.h"

class Card;
class WildCard;
class Plus4;
class SkipCard;
class ColoredDrawCard;

class Deck {
private:
  std::vector<Card*> _cards;
  int _rand;
public:
  Deck();
  std::vector<Card*> get_cards();
  void fillDeck();
  Card* get_topCard();
  Card* newNumberedCard(std::string color, int number);
  Card* drawCards();
//  get_topCards(int ammount);
  Card* newWildCard();
  Card* newPlus4();
  Card* newSkipCard(std::string color);
  Card* newColoredDrawCard(std::string color);
<<<<<<< HEAD
  int random(int i);
=======
  int myrandom (int random);
>>>>>>> f8a1f14432173170d5178e6ddf94c542add1df3e
  void shuffle();
};

#endif
