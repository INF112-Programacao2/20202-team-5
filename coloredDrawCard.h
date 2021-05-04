#ifndef COLOREDDRAWCARD_H
#define COLOREDDRAWCARD_H

#include "coloredCard.h"
#include "game.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>

class ColoredDrawCard : public ColoredCard {
private:
  int _drawAmmount;
public:
  ColoredDrawCard(std::string color);
  void forceDraw(Game game);
  int get_number() override;
  ColoredDrawCard* copy() override;
  void onPlay(Game game) override;
};

#endif
