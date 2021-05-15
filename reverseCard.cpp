#include "reverseCard.h"
#include <iostream>

ReverseCard::ReverseCard(std::string color){
	this->_name= "reverseCard";
	this->_color = color;
	this->_spriteName = "sprites/" + color + "reverse.bmp";
}

/*
	Retorna uma copia de um objeto da classe ReverseCard
*/
ReverseCard* ReverseCard::copy(){
	ReverseCard* c = new ReverseCard(this->_color);
	return c;
}

/*
	Chama o metodo reverse_orientation() da classe Board que é responsável por inverter o sentido do jogo
*/
void ReverseCard::reverse_orientation(Game game){
	game.get_board()->reverse_orientation();
}

int ReverseCard::get_number(){
	return -1;
}

std::string ReverseCard::get_color() {
	return this->_color;
}

/*
  Dita o comportamento da carta quando ela é jogada, neste caso , muda o sentido em que o jogo segue
*/
void ReverseCard::onPlay() {
	this->reverse_orientation(game);
	game.next_player();
}
