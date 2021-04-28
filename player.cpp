#include "player.h"

Player::Player(Game game) {
  this->_score = 0;
  this->_skipped = false;
  this->_hand = newHand(game);
}

void Player::set_skip(bool skip){
	this->_skipped=skip;
}

int Player::get_score() {
  return this->_score;
}

void Player::set_score(int score) {
  this->_score = score;
}

Hand* Player::get_hand() {
  return this->_hand;
}

Hand* Player::newHand(Game game) {
  Hand* h = new Hand(game);
  return h;
}
