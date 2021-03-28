#include<vector>
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
//  get_topCards(int ammount);
};
