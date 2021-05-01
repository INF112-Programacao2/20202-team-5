#ifndef GAME_H
#define GAME_H

#include<vector>
#include "board.h"
#include "player.h"
//class Player;
//class Board;

class Board;
class Player;

class Game {
private:
  int _players;
  std::vector<Player*> _playerList;
  int _activePlayer;
  Board* _board;
public:
  Game();//int players);
  int get_players();
  void set_players(int players);
  int get_activePlayer();
  void set_activePlayer(int activePlayer);
  void next_player();
  int get_next_player();
  Player* newPlayer();
  std::vector<Player*> get_playerList();
  Board* newBoard();
  Board* get_board();
  void start(int players);
  //int* scores();
};

extern Game game;

#endif
