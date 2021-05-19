#include "player.h"

Player::Player(Game game) {
  this->_score = 0;
  this->_skipped = false;
  this->_uno = false;
  this->_unoButton = false;
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

void Player::uno() {
  this->_unoButton = true;
}

void Player::unoPressed() {
  this->_uno = true;
  this->_unoButton = false;
}

void Player::set_uno(bool uno) {
  this->_uno = uno;
}

bool Player::get_uno() {
  return this->_uno;
}

bool Player::get_unoButton() {
  return this->_unoButton;
}
