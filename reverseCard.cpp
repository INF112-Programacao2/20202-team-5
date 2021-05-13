#include "reverseCard.h"
#include <iostream>

ReverseCard::ReverseCard(std::string color){
	this->_name= "reverseCard";
	this->_color = color;
	this->_spriteName = "sprites/" + color + "reverse.bmp";
}

ReverseCard* ReverseCard::copy(){
	ReverseCard* c = new ReverseCard(this->_color);
	return c;
}

void ReverseCard::reverse_orientation(Game game){
	game.get_board()->reverse_orientation();
}

int ReverseCard::get_number(){
	return -1;
}

std::string ReverseCard::get_color() {
	return this->_color;
}

void ReverseCard::onPlay() {
	this->reverse_orientation(game);
	game.next_player();
}
