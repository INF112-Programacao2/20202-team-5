#ifndef COLOREDDRAWCARD_H
#define COLOREDDRAWCARD_H

#include "coloredCard.h"
#include "game.h"

class ColoredDrawCard : public ColoredCard {
private:
  int _drawAmmount;
public:
  ColoredDrawCard(std::string color);
  void forceDraw(Game game);
  int get_number() override;
  ColoredDrawCard* copy() override;
};

#endif
