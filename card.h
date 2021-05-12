#ifndef CARD_H
#define CARD_H

#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include<string>

class Game;

class Card {
protected:
  std::string _name;
  ALLEGRO_BITMAP* _sprite;
  std::string _spriteName;
  std::string _color;
  int _number;
public:
  virtual std::string get_color();
  virtual int get_number();
  std::string get_name();
  bool isPlayable();
  virtual Card* copy()=0;
  ALLEGRO_BITMAP* get_sprite();
  std::string get_spriteName();
  void set_sprite(ALLEGRO_BITMAP* sprite);
  virtual void onPlay(Game game)=0;
};

#endif
