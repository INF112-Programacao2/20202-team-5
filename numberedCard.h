#include<string>

class NumberedCard : public ColoredCard{
private:
  int _number;
public:
  ColoredCard(std::string color);
  int get_number();
  void set_number(int number);
};
