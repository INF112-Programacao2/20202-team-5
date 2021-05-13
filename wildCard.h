#ifndef WILDCARD_H
#define WILDCARD_H

#include "blackCard.h"

class WildCard : public BlackCard {
public:
  WildCard();
  WildCard* copy() override;
  int get_number() override;
  std::string get_color() override;
  void onPlay() override;
};

#endif
