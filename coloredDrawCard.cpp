#include "coloredDrawCard.h"

ColoredDrawCard::ColoredDrawCard(){
	_drawAmmount=2;
}

void ColoredDrawCard::forceDraw(){
	Hand->draw(_drawAmmount);
}
	
	

