#include "blackCard.h"

class WildCard : public BlackCard {
public:
  WildCard();
  WildCard* copy();
  int get_number() override;
  std::string get_color() override;
};
