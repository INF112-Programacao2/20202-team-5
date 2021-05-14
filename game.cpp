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
  try {
  	if (players > 4) {
			throw Excesso_player();
	}else if (players < 2) {
			throw Excesso_player();
  	}else {
   		this->_players = players;
  	}
  }catch (Excesso_player &e){
  	std::cerr<<e.what()<<std::endl;
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
  //this->_playerList.at(this->_activePlayer)->get_hand()->hasPlay(game);
}

int Game::get_next_player() {
  return ((this->_activePlayer + 1)%this->_players);
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
  try {
  	if (players > 4) {
			throw Excesso_player();
	}else if (players < 2) {
			throw Excesso_player();
  	}else {
   		this->_players = players;
  	}
  }catch (Excesso_player &e){
  	std::cerr<<e.what()<<std::endl;
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

Game game;
//int* Game::scores() {}
