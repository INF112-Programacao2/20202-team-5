#ifndef PLUS4_H
#define PLUS4_H

#include "blackCard.h"

class Plus4 : public BlackCard {
private:
	int _cards_to_draw;
public:
  Plus4();
  void forced_draw(Game game);
	Plus4* copy() override;
	int get_number() override;
};

#endif
