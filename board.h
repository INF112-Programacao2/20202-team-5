#include<string>

class Board {
private:
  int _number;
  std::string _collor;
public:
  int get_number();
  void set_number(int number);
  std::string get_collor();
  void set_collor(std::string collor);
};
