#include "wildcard.h"

WildCard::WildCard(){
	this->_name = "wildcard";
}

WildCard* WildCard::copy() {
	WildCard* c = new WildCard();
	return c;
}

int WildCard::get_number() {
	return -1;
}

std::string WildCard::get_color() {
	return "black";
}
