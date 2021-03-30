#include "stack.h"

Stack::Stack() {

}

Card* Stack::get_topCard() {
  return this->_cards.back();
}
