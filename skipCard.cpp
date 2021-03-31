#include "skipCard.h"

//Game game(2);

SkipCard::SkipCard(std::string color){
	_color=color;
}

void SkipCard::skip(){
	game.get_player_list().at()->set_skip(1);
}
