#include "blackCard.h"

class Plus4 : public BlackCard {
private:
	int _cards_to_draw;
public:
  Plus4();
  void forced_draw();
	Plus4* copy();
	int get_number() override;
};
