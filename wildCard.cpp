#include "wildCard.h"

WildCard::WildCard(){
	this->_name = "wildcard";
	this->_spriteName = "sprites/wildcard.bmp";
	this->_color = "black";
}

WildCard* WildCard::copy() {
	WildCard* c = new WildCard();
	return c;
}

int WildCard::get_number() {
	return -1;
}

std::string WildCard::get_color() {
	return this->_color;
}

void WildCard::onPlay() {
	pickColor();
}
