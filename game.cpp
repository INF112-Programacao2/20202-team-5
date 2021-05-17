#include "game.h"
#include "player.h"
#include "board.h"
#include<iostream>

Game::Game() {
  this->_isPickingColor = false;
  this->_isMenuMode = true;
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


/*
  Da classe Board obtem-se a orientaçao do jogo que é usada para determinar de quem será a proxíma jogada
  A proxíma jogada é determinada sempre somando a orientaçao(1 ou -1) ao número que corresponde ao jogador da rodada atual
  exceto quando esta soma se resulta em 0 ou em um número maior que a quantidade de jogadores ,  em seguida é chamada da
  instância da classe Hand associada ao jogador atual ,  o método hasPlay() que verifica se o jogador possui jogadas possíveis e caso
  afirmativo este realizará a sua jogada , caso contrario as devidas açoes já so executadas em seguida
*/
void Game::next_player() {
  this->_activePlayer += this->_board->get_orientation();
  if (this->_activePlayer == this->_players) {
    this->_activePlayer = 0;
  } else if (this->_activePlayer == -1) {
    this->_activePlayer = this->_players - 1;
  }
  std::cout << this->_players << " " << this->_activePlayer << std::endl;
  this->_playerList.at(this->_activePlayer)->get_hand()->hasPlay();
}

/*
  Determina o proxímo jogador a jogar de maneira similar ao metodo next_player() , porém invés de verificar se o jogador possui
  jogadas possíveis , simplesmente retorna o número correspondente ao jogador seguinte
*/
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

/*
  Responsável por instanciar e realizar todas as açoes necessárias para iniciar a partida , como instanciar o objeto da classe Board
  e fazer com que todos os jogadores comprem suas maos iniciais
*/
void Game::start(int players) {
  this->_isPickingColor = false;
  this->_isMenuMode = true;
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

  this->_playerList.at(this->_activePlayer)->get_hand()->hasPlay();
}

void Game::pickColorMenu() {
  this->_isPickingColor = true;
}

bool Game::isPickingColor() {
  return this->_isPickingColor;
}
/*
  Após uma carta preta ser jogada e a cor ser selecionada , este método coloca a cor escolhida como a cor do topo da pilha e em seguida
  passa a vez para o próximo jogador.
*/
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

void Game::end() {
  this->_isMenuMode = true;
  this->_playerList.clear();
  _activePlayer = 0;
  delete(this->_board);
  this->_isPickingColor = false;
  this->_isMenuMode = false;
  this->_isDrawMode = false;
  this->_isPassMode = false;
  this->_isPlayMode = false;
}

bool Game::isMenuMode() {
  return this->_isMenuMode;
}

void Game::set_MenuMode(bool menuMode) {
  this->_isMenuMode = menuMode;
}

Game game;
