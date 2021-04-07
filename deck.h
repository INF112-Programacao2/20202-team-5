#include<vector>
#include <stdlib.h>
#include "numberedCard.h"

class Deck {
private:
  std::vector<Card*> _cards;
public:
  Deck();
  std::vector<Card*> get_cards();
  void fillDeck();
  Card* get_topCard();
  Card* newNumberedCard(std::string color, int number);
  Card* drawCards();
//  get_topCards(int ammount);
};
