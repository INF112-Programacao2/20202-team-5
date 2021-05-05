#ifndef REVERSECARD_H_
#define REVERSECARD_H_

#include "coloredCard.h"
#include <string>
#include "game.h"

class ReverseCard : public ColoredCard{
	public:
		ReverseCard();
		ReverseCard* copy() override;
		void reverse_orientation(Game game);
		int get_number() override;
};

#endif
