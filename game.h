#include<vector>
#include "board.h"
#include "player.h"

class Game {
private:
  int _players;
  std::vector<Player*> _playerList;
  int _active_player;
  Board* _board;
public:
  Game(int players);
  int get_players();
  void set_players(int players);
  int get_active_player();
  void set_active_player(int active_player);
  void next_player();
  Player* newPlayer();
  std::vector<Player*> get_playerList();
  Board* newBoard();
  Board* get_board();
  //int* scores();
};
