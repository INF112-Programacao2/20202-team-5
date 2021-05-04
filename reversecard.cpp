#include "reversecard.h"

ReverseCard::ReverseCard(){
	this->_name="reversecard";
	this->_spriteName = "sprites/" + color + ".bmp";
}

ReverseCard* ReverseCard::copy(){
	ReverseCard* c = new ReverseCard();
	return c;
}

void ReverseCard::reverse_orientation(Game game){
	game.get_board().reverse_orientation();
}

int ReverseCard::get_number(){
	return -1;
}
