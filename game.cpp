#include "game.h"
#include "player.h"
#include "board.h"
#include<iostream>

Game::Game() {
  this->start(4);
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
  this->_active_player += _board->get_orientation();
  if (this->_active_player == this->_players) {
    this->_active_player = 0;
  } else if (_active_player == -1) {
    this->_active_player = this->_players - 1;
  }
}

int Game::get_next_player() {
  return ((this->_active_player + 1)%this->_players);
}

Player* Game::newPlayer() {
  Player* player = new Player(game);
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

void Game::start(int players) {
  if (players > 4) {
    std::cout << "Player number over limit\n";
  } else if (players < 2) {
    std::cout << "Player number under limit\n";
  } else {
    this->_players = players;
  }

  this->_active_player=0;

  for(int i = 0; i<this->_players;i++) {
    this->_playerList.push_back(this->newPlayer());
  }
  this->_board = this->newBoard();

  for (int i = 0; i < this->get_players(); i++) {
    this->get_playerList().at(i)->get_hand()->draw(7, game);
  }
}

Game game;
//int* Game::scores() {}
