#ifndef CARD_H
#define CARD_H

//#include <allegro5/allegro5.h>
//#include <allegro5/allegro_font.h>
//#include <allegro5/allegro_image.h>
#include<string>
#include "player.h"

class Game;

class Card {
protected:
  std::string _name;
 // ALLEGRO_BITMAP* _sprite;
  std::string _spriteName;
public:
  virtual std::string get_color()=0;
  virtual int get_number()=0;
  std::string get_name();
  virtual bool isPlayable();
  virtual Card* copy()=0;
  ALLEGRO_BITMAP* get_sprite();
  std::string get_spriteName();
  void set_sprite(ALLEGRO_BITMAP* sprite);
  virtual void onPlay(Game game)=0;
};

#endif
