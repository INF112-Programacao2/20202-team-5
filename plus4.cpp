#include "plu4.h"

Plus4::Plus4(){
	_cards_to_drwa=4;
}

void Plus4::Forced_draw(){
	Hand->draw(_cards_to_draw);
}

