#include "coloredCard.h"

class ColoredDrawCard : public ColoredCard {
private:
  int _drawAmmount;
public:
  ColoredDrawCard();
  void forceDraw();
};
