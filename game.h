#ifndef GAME_H
#define GAME_H

#include<vector>
#include "board.h"
#include "player.h"
#include "stdexcept"
#include "invalidNumberPlayer.h"

class Board;
class Player;

class Game {
private:
  int _players;
  std::vector<Player*> _playerList;
  int _activePlayer;
  Board* _board;
  bool _isPickingColor;
  bool _isMenuMode;
  bool _isDrawMode;
  bool _isPassMode;
  bool _isPlayMode;
public:
  Game();
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
  void pickColorMenu();
  bool isPickingColor();
  void pickedColor(std::string color);
  void drawButton();
  void drawButtonPressed();
  void passButton();
  void playButton();
  void passButtonPressed();
  void playButtonPressed() ;
  bool isDrawMode();
  bool isPassMode();
  bool isPlayMode();
  void end();
  bool isMenuMode();
  void set_MenuMode(bool menuMode);
  //int* scores();
};

extern Game game;

#endif
