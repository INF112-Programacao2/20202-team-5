#include "reversecard.h"

ReverseCard::ReverseCard(){
	this->_name="reversecard";
<<<<<<< HEAD
//	this->_spriteName = "sprites/" + color + ".bmp";
=======
	this->_spriteName = "sprites/" + color + ".bmp";
>>>>>>> f8a1f14432173170d5178e6ddf94c542add1df3e
}

ReverseCard* ReverseCard::copy(){
	ReverseCard* c = new ReverseCard();
	return c;
}

void ReverseCard::reverse_orientation(Game game){
<<<<<<< HEAD
	game.get_board()->reverse_orientation();
=======
	game.get_board().reverse_orientation();
>>>>>>> f8a1f14432173170d5178e6ddf94c542add1df3e
}

int ReverseCard::get_number(){
	return -1;
}
