#include "player.h"

Player::Player() {
  this->_score = 0;
  this->_skipped = false;
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
