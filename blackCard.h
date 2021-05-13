#ifndef BLACKCARD_H
#define BLACKCARD_H

#include <iostream>
#include "card.h"
#include "game.h"
//class Game;

class BlackCard : public Card {
protected:
	void pickColor();
};

#endif
