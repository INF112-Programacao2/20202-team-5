#ifndef PLUS4_H
#define PLUS4_H

#include "blackCard.h"
#include "game.h"

class Plus4 : public BlackCard {
private:
	int _cards_to_draw;
public:
  Plus4();
  void forceDraw();
	Plus4* copy() override;
	int get_number() override;
	std::string get_color() override;
	void onPlay() override;
};

#endif
