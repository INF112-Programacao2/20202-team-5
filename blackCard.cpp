#include "blackCard.h"

void BlackCard::pickColor(Game game){
	std::string new_color;
	std::cout << "insert color\n";
	std::cin >> new_color;
	game.get_board()->get_stack()->set_color(new_color);
}
