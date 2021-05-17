#include "util.h"

Player* activePlayer() {
 return game.get_playerList().at(game.get_activePlayer());
};
