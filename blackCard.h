#include <iostream>
#include "card.h"
#include "board.h"

class BlackCard : public Card {
protected:
	std::string _new_color=NULL;
public:
	void pickColor();
};
