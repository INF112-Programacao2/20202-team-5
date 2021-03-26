#include<vector>
#include "Card.h"

class Hand {
private:
  vector<Card> cards;
public:
  void draw(Card card);
  void play(Card card);
};
