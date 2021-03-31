#include "blackCard.h"

void BlackCard::pickColor(){
	std::cin>>_new_color;
	Board::set_color(_new_color);
}
