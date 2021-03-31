#include "plus4.h"

//Game game(2);

Plus4::Plus4(){
	_cards_to_draw=4;
}

void Plus4::forced_draw(){
	Plus4::pickColor();
//	game.get_playerList().at(1)->get_hand().draw(_cards_to_draw)
}
