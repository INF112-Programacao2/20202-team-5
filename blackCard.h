#ifndef BLACKCARD_H
#define BLACKCARD_H

#include <iostream>
#include "card.h"

class BlackCard : public Card {
public:
	void pickColor(Game game);
};

#endif
