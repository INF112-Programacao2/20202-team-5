#include "game.h"
#include "player.h"
#include "board.h"
#include<iostream>

Game::Game() {
  this->_isPickingColor = false;
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

int Game::get_activePlayer() {
  return this->_activePlayer;
}

void Game::set_activePlayer(int activePlayer) {
  this->_activePlayer = activePlayer;
}

void Game::next_player() {
  this->_activePlayer += this->_board->get_orientation();
  if (this->_activePlayer == this->_players) {
    this->_activePlayer = 0;
  } else if (this->_activePlayer == -1) {
    this->_activePlayer = this->_players - 1;
  }
  std::cout << this->_players << " " << this->_activePlayer << std::endl;
  this->_playerList.at(this->_activePlayer)->get_hand()->hasPlay(game);
}

int Game::get_next_player() {
  int r = this->_activePlayer;
  r += this->_board->get_orientation();
  if (r == this->_players) {
    return 0;
  } else if (r == -1) {
    return this->_players - 1;
  }
  return r;
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

  for(int i = 0; i<this->_players;i++) {
    this->_playerList.push_back(this->newPlayer());
  }
  this->_board = this->newBoard();

  this->_activePlayer=0;

  for (int i = 0; i < this->get_players(); i++) {
    this->get_playerList().at(i)->get_hand()->draw(7, game);
  }

  this->_board->get_stack()->begin(game);

  this->_playerList.at(this->_activePlayer)->get_hand()->hasPlay(game);
}

void Game::pickColorMenu() {
  this->_isPickingColor = true;
}

bool Game::isPickingColor() {
  return this->_isPickingColor;
}

void Game::pickedColor(std::string color) {
  this->_isPickingColor = false;
  this->get_board()->get_stack()->set_color(color);
}

Game game;
