#include<vector>
#include "Card.h"
#include "Deck.h"
#include "Stack.h"

class Hand {
private:
  std::vector<Card*> _cards;
public:
  Hand(int inittialNumberOfCards,Deck &deck);
  void draw(int ammount,Deck &deck);
  void play(Card* card,Stack &stack);
  bool hasPlay(Card* stackTopCard);
  void noPlay();
};
