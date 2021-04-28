#include "blackCard.h"

void BlackCard::pickColor(Game game){
	std::string new_color;
	std::cin >> new_color;
	game.get_board()->set_color(new_color);
}
