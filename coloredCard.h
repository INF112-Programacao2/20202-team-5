#ifndef COLOREDCARD_H
#define COLOREDCARD_H

#include<string>
#include "card.h"

class ColoredCard : public Card {
protected:
  std::string _color;
public:
  std::string get_color() override;
  void set_color(std::string color);
};

#endif
