#include "plus4.h"

//Game game(2);

Plus4::Plus4(){
	_cards_to_draw=4;
	this->_name = "plus4";
}

void Plus4::forced_draw(Game game){
	Plus4::pickColor(game);
	//game.get_playerList().at(game.get_next_player())->get_hand().draw(_cards_to_draw)

}

Plus4* Plus4::copy() {
	Plus4* c = new Plus4();
	return c;
}

int Plus4::get_number() {
	return -1;
}

std::string Plus4::get_color() {
	return "black";
}
