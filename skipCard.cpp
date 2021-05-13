#include "skipCard.h"

//Game game(2);

SkipCard::SkipCard(std::string color){
	_color=color;
	this->_name = "skipCard";
	this->_spriteName = "sprites/" + color + "skip.bmp";
}

/*
	Chama o metodo set_skip() da classe Player , que é responsável por pular a vez do jogador seguinte ao que jogou este card
*/
void SkipCard::skip(Game game){
	game.get_playerList().at(game.get_next_player())->set_skip(true);
}

/*
	Retorna uma copia de um objeto da classe skipCard
*/
SkipCard* SkipCard::copy() {
	SkipCard* c = new SkipCard(this->_color);
	return c;
}

int SkipCard::get_number() {
	return -1;
}

std::string SkipCard::get_color() {
	return this->_color;
}

/*
  Dita o comportamento da carta quando ela é jogada, neste caso pula a vez do jogador seguinte e passa a vez para o jogador após este
*/
void SkipCard::onPlay() {
	this->skip(game);
	game.next_player();
}
