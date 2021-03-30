#include "blackCard.h"
#include "hand.h"

class Plus4 : public BlackCard {
	private:
		int _cards_to_draw;
	public:
  		Plus4();
  		void Forced_draw();
}
