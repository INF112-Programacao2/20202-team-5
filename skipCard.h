#ifndef SKIPCARD_H
#define SKIPCARD_H

#include "coloredCard.h"
#include "game.h"

class SkipCard : public ColoredCard {
public:
  SkipCard(std::string color);
  void skip(Game game);
  SkipCard* copy() override;
  int get_number() override;
  std::string get_color() override;
};

#endif
