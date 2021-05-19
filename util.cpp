#include "util.h"

Player* activePlayer() {
 return game.get_playerList().at(game.get_activePlayer());
};

void loadSprites() {
  //for (int i = 0; i < game.get_board()->get_deck()->get_cards().size(); i++) {
  //  game.get_board()->get_deck()->get_cards().at(i)->set_sprite(al_load_bitmap(game.get_board()->get_deck()->get_cards().at(i)->get_spriteName().c_str()));
  //}
  for (int j = 0; j < game.get_playerList().size(); j++) {
    for(int i = 0; i < game.get_playerList().at(j)->get_hand()->get_cards().size(); i++) {
      game.get_playerList().at(j)->get_hand()->get_cards().at(i)->set_sprite(al_load_bitmap(game.get_playerList().at(j)->get_hand()->get_cards().at(i)->get_spriteName().c_str()));
    }
  }

  game.get_board()->get_stack()->get_cards().back()->set_sprite(al_load_bitmap(game.get_board()->get_stack()->get_cards().back()->get_spriteName().c_str()));
}
