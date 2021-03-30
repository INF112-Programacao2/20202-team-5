#include<string>
#include<vector>
#include "deck.h"
//#include "stack.h"

class Board {
private:
  int _number;
  std::string _color;
  int _orientation; //0 => clockwise, 1 => counter clockwise
  Deck* _deck;
  //Stack _stack;
public:
  Board();
  int get_number();
  void set_number(int number);
  std::string get_color();
  void set_color(std::string color);
  Deck* get_deck();
  Deck* newDeck();
};
