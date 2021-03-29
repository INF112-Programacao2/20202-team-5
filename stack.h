#include<vector>
#include "Card.h"

class Stack {
private:
  std::vector<Card*> _cards;
public:
  Stack();
  std::vector<Card*> get_cards();
  Card* get_topCard();
};
