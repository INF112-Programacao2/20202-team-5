#include "skipCard.h"

//Game game(2);

SkipCard::SkipCard(std::string color){
	_color=color;
	this->_name = "skipCard";
}

void SkipCard::skip(Game game){
	//game.get_player_list().at(game.get_next_player())->set_skip(true);
}

SkipCard* SkipCard::copy() {
	SkipCard* c = new SkipCard(_color);
	return c;
}

int SkipCard::get_number() {
	return -1;
}

std::string SkipCard::get_color() {
	return this->_color;
}
