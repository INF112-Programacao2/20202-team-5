#include "plus4.h"

//Game game(2);

Plus4::Plus4(){
	_cards_to_draw=4;
	this->_name = "plus4";
	this->_spriteName = "sprites/plus4.bmp";
	this->_color = "black";
}

/*
	Responsável por forçar a compra de cartar por um jogador , quando o anterior jogou uma carta +4
*/

void Plus4::forceDraw(){
	game.get_playerList().at(game.get_next_player())->get_hand()->draw(this->_cards_to_draw);
}

/*
	Retorna uma copia de um objeto da classe Plus4
*/
Plus4* Plus4::copy() {
	Plus4* c = new Plus4();
	return c;
}

int Plus4::get_number() {
	return -1;
}

std::string Plus4::get_color() {
	return this->_color;
}

/*
  Dita o comportamento da carta quando ela é jogada, neste caso , força o jogador seguinte a comprar cartas e o jogador que jogou esta 
  escolhe uma cor que será a que continuara na pilha
*/
void Plus4::onPlay() {
	this->forceDraw();
	this->pickColor();
}
