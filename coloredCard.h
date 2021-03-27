#include<string>

class ColoredCard : public Card {
private:
  std::string _color;
public:
  std::string get_collor();
  void set_color(std::string color);
};
