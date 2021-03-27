#include "board.h"

class Game {
private:
  int _players;
  int _active_player;
  Board _board;
public:
  Game(_players);
  int get_players();
  void set_players(int players)
  int get_active_player();
  void set_active_player(int active_player);
  void next_player();
  int* scores()
};
