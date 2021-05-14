#ifndef HAND_H
#define HAND_H

#include<vector>
#include "game.h"
#include "card.h"
class Game;

class Hand {
private:
  std::vector<Card*> _cards;
public:
  Hand(Game game);
  void draw(int ammount);
  void play(int card);
  bool hasPlay(Game game);
  void noPlay();//Game game);
  std::vector<Card*> get_cards();
};

#endif
