#include "skipCard.h"

//Game game(2);

SkipCard::SkipCard(std::string color){
	_color=color;
	this->_name = "skipCard";
	this->_spriteName = "sprites/" + color + "skip.bmp";
}

void SkipCard::skip(Game game){
	game.get_playerList().at(game.get_next_player())->set_skip(true);
}

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

void SkipCard::onPlay(Game game) {
	this->skip(game);
}
