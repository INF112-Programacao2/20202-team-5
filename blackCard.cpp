#include "blackCard.h"

//Game game(2);

void BlackCard::pickColor(){
	std::cin>>_new_color;
	game.get_board()->set_color(_new_color);
}
