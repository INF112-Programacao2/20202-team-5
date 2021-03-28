#include<vector>
#include "Card.h"

class Hand {
private:
  vector<Card*> _cards;
public:
  Hand();
  void draw(int ammount);
  void play(Card card);
  bool hasPlay();
  void noPlay();
};
