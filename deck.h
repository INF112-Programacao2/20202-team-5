#include<vector>
#include "Card.h"

class Deck {
private:
  vector<Card> cards;
public:
  Deck();
  fillDeck();
  get_topCard();
};
