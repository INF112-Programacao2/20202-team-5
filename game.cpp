#include "game.h"

Game::Game(int players) {
  if (players > 4) {

  } else if (players < 2) {

  } else {
    this->_players = players;
  }
  this->_active_player=0;
  for(int i = 0; i<this->_players;i++) {
    this->_playerList.push_back(this->newPlayer());
  }
  this->_board = this->newBoard();
}

int Game::get_players() {
  return this->_players;
}

void Game::set_players(int players) {
  if (players > 4) {

  } else if (players < 2) {

  } else {
    this->_players = players;
  }
}

int Game::get_active_player() {
  return this->_active_player;
}

void Game::set_active_player(int active_player) {
  this->_active_player = active_player;
}

void Game::next_player() {
  if (this->_active_player == this->_players - 1) {
    this->_active_player = 0;
  } else {
    this->_active_player++;
  }
}

Player* Game::newPlayer() {
  Player* player = new Player();
  return player;
}

std::vector<Player*> Game::get_playerList() {
  return this->_playerList;
}

Board* Game::get_board() {
  return this->_board;
}

Board* Game::newBoard() {
  Board* board = new Board();
  return board;
}

//int* Game::scores() {}
