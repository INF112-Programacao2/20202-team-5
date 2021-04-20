#ifndef BLACKCARD_H
#define BLACKCARD_H

#include <iostream>
#include "card.h"
#include "game.h"
//class Game;

class BlackCard : public Card {
public:
	void pickColor(Game game);
};

#endif
