#include "coloredDrawCard.h"

//Game game(2);

ColoredDrawCard::ColoredDrawCard(std::string color){
	this->_drawAmmount=2;
	this->_color = color;
	this->_name = "coloredDrawCard";
	this->_spriteName = "sprites/" + color + "+2.bmp";
}

/*
	Responsável por forçar a compra de cartar por um jogador , quando o anterior jogou uma carta de compra
*/
void ColoredDrawCard::forceDraw(Game game){
	game.get_playerList().at(game.get_next_player())->get_hand()->draw(this->_drawAmmount, game);
}
/*
	Retorna a copia de um objeto da classe coloredDrawCard
*/
ColoredDrawCard* ColoredDrawCard::copy() {
	ColoredDrawCard* c = new ColoredDrawCard(_color);
	return c;
}

int ColoredDrawCard::get_number() {
	return -1;
}


/*
  Dita o comportamento da carta quando ela é jogada, neste caso , força o jogador seguinte a comprar cartas e passa a vez para ele
*/
void ColoredDrawCard::onPlay() {
	this->forceDraw(game);
	game.next_player();
}
