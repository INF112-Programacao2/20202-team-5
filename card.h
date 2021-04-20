#ifndef CARD_H
#define CARD_H

#include<string>
//#include "game.h"

class Card {
public:
  virtual std::string get_color()=0;
  virtual int get_number()=0;
  virtual bool isPlayable();
  virtual Card* copy()=0;
};

#endif
