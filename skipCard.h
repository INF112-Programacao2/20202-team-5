#include <string>
#include "coloredCard.h"

class SkipCard : public ColoredCard {
public:
  SkipCard(std::string color);
  void skip();
}
