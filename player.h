#ifndef PLAYER_H
#define PLAYER_H

#include "hand.h"

class Player {
private:
  int _score;
  bool _skipped;
  Hand* _hand;
public:
  Player();
  void set_skip(bool skip);
  int get_score();
  void set_score(int score);

};

#endif
