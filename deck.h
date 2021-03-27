#include<vector>
#include "Card.h"

class Deck {
private:
  vector<Card> _cards;
public:
  Deck();
  fillDeck();
  get_topCard();
  get_topCards(int ammount);
};
