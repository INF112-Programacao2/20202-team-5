#include "coloredDrawCard.h"

//Game game(2);

ColoredDrawCard::ColoredDrawCard(std::string color){
	_drawAmmount=2;
	_color = color;
}

void ColoredDrawCard::forceDraw(Game game){
	//game.get_playerList().at(game.get_next_player())->get_hand().draw(_drawAmmount)
}

ColoredDrawCard* ColoredDrawCard::copy() {
	ColoredDrawCard* c = new ColoredDrawCard(_color);
	return c;
}

int ColoredDrawCard::get_number() {
	return -1;
}
