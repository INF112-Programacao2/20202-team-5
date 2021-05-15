#include "wildCard.h"

WildCard::WildCard(){
	this->_name = "wildcard";
	this->_spriteName = "sprites/wildcard.bmp";
	this->_color = "black";
}

/*
	Retorna uma copia de um objeto da classe WildCard
*/
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

/*
  Dita o comportamento da carta quando ela é jogada, neste caso ,o jogador que jogou esta carta escolhe uma cor 
  que será a que continuara na pilha
*/
void WildCard::onPlay() {
	pickColor();
}
