#include <iostream>
#include "card.h"
#include "game.h"

class BlackCard : public Card {
protected:
	std::string _new_color=NULL;
public:
	void pickColor();
};
