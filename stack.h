#ifndef STACK_H
#define STACK_H

#include<vector>
#include "card.h"

class Stack {
private:
  std::vector<Card*> _cards;
public:
  Stack();
  std::vector<Card*> get_cards();
  Card* get_topCard();
  void set_topCard(Card* card);
};

#endif
