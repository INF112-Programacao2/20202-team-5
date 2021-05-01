#ifndef STACK_H
#define STACK_H

#include<vector>
#include<string>
#include "game.h"
//#include "card.h"

class Card;
class Game;

class Stack {
private:
  std::vector<Card*> _cards;
public:
  Stack();
  std::vector<Card*> get_cards();
  Card* get_topCard();
  void set_topCard(Card* card);
  std::string get_color();
  int get_number();
  void begin(Game game);
};

#endif
