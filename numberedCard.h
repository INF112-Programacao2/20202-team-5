#ifndef NUMBEREDCARD_H
#define NUMBEREDCARD_H

#include<string>
#include "coloredCard.h"

class NumberedCard : public ColoredCard{
public:
  NumberedCard(std::string color, int number);
  int get_number();
  void set_number(int number);
  NumberedCard* copy() override;
  void onPlay() override;
};

#endif
