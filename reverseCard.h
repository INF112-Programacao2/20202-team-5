#ifndef REVERSECARD_H_
#define REVERSECARD_H_

#include "coloredCard.h"
#include "game.h"

class ReverseCard : public ColoredCard{
public:
	ReverseCard(std::string color);
	ReverseCard* copy() override;
	void reverse_orientation(Game game);
	int get_number() override;
	std::string get_color() override;
  void onPlay(Game game);
};

#endif
