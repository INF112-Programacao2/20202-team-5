#ifndef PLAYER_H
#define PLAYER_H

#include "game.h"
#include "hand.h"
class Hand;
class Game;

class Player {
private:
  int _score;
  bool _skipped;
  Hand* _hand;
  bool _uno;
  bool _unoButton;
public:
  Player(Game game);
  void set_skip(bool skip);
  int get_score();
  void set_score(int score);
  Hand* get_hand();
  Hand* newHand(Game game);
  void uno();
  void unoPressed();
  void set_uno(bool uno);
  bool get_uno();
  bool get_unoButton();
};

#endif
