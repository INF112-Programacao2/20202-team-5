#include "hand.h"
#include "game.h"
#include <iostream>

Hand::Hand(Game game){
  this->_cards.clear();
}

/*
  Responsável por chamar o metodo drawCards() da classe Deck e entao adicionar a mao do jogador a carta que foi retirada do deck
*/
void Hand::draw(int ammount, Game game){
  for (int i=0; i<ammount; i++){
    this->_cards.push_back(game.get_board()->get_deck()->drawCards());
    game.get_board()->get_deck()->get_cards().back()->set_sprite(al_load_bitmap(game.get_board()->get_deck()->get_cards().back()->get_spriteName().c_str()));
  }
}

/*
  Responsável por jogar as cartas. Adiciona a carta jogada no topo da pilha e retira a mesma da mao do jogador
*/
void Hand::play(int card){
  game.get_board()->get_stack()->set_topCard(this->_cards.at(card)->copy());
  this->_cards.at(card)->onPlay();
  this->_cards.erase(this->_cards.begin() + card);
  //game.next_player();
}

/*
  Verifica se o jogador possui jogadas possíveis. Caso nao tenha , chama o metodo noPlay() que faz com que o jogador compre uma carta
  e caso seja possivel joga-la ele o faz e caso contratrio pula a vez do jogador
*/
bool Hand::hasPlay(Game game){
    for(int i = 0; i < this->_cards.size(); i++){
        if(this->_cards.at(i)->isPlayable()) {
          std::cout << "has play\n";
          return true;
        }
    }
    this->noPlay();//game);
    return false;
}

void Hand::noPlay() {//Game game) {
  std::cout << "no play\n";
  this->draw(1, game);
  if (this->_cards.back()->isPlayable()) {
    this->play(this->_cards.size() - 1);
  }
  game.next_player();
}

std::vector<Card*> Hand::get_cards() {
  return this->_cards;
}
