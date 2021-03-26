#include<string>

class Card {
private:
  int _number;
  std::string _collor;
public:
  Card(_number, _collor)
  int get_number();
  void set_number(int number);
  std::string get_collor();
  void set_collor(std::string collor);
  void skip();
  void skip(int player);
  void draw(int ammount);
  void draw(int player, int ammount);
  bool playable();
};
