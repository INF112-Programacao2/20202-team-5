#include<vector>
#include "Card.h"

class Stack {
private:
  vector<Card*> _cards;
public:
  Stack();
  Card* get_topCard();
};
