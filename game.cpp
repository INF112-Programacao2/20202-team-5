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
    this->get_playerList().at(i)->get_hand()->draw(7);
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
  this->next_player();
}

void Game::drawButton() {
  this->_isDrawMode = true;
}

void Game::drawButtonPressed() {
  this->_playerList.at(this->get_activePlayer())->get_hand()->draw(1);
  if (this->_playerList.at(this->_activePlayer)->get_hand()->get_cards().back()->isPlayable()) {
    playButton();
  } else {
    passButton();
  }
  this->_isDrawMode = false;
}

void Game::passButton() {
  this->_isPassMode = true;
}

void Game::playButton() {
  this->_isPlayMode = true;
}

void Game::passButtonPressed() {
  this->_isPassMode = false;
  this->next_player();
}

void Game::playButtonPressed() {
  this->_isPlayMode = false;
  this->_playerList.at(this->_activePlayer)->get_hand()->play(this->_playerList.at(this->_activePlayer)->get_hand()->get_cards().size() - 1);
  this->next_player();
}

bool Game::isDrawMode() {
  return this->_isDrawMode;
}

bool Game::isPassMode() {
  return this->_isPassMode;
}

bool Game::isPlayMode() {
  return this->_isPlayMode;
}

Game game;
