#include "plus4.h"

//Game game(2);

Plus4::Plus4(){
	_cards_to_draw=4;
	this->_name = "plus4";
	this->_spriteName = "sprites/plus4.bmp";
	this->_color = "black";
}

void Plus4::forceDraw(Game game){
	game.get_playerList().at(game.get_next_player())->get_hand()->draw(this->_cards_to_draw, game);
}

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

void Plus4::onPlay(Game game) {
	this->forceDraw(game);
	this->pickColor();
}
