#include<string>

class ColoredCard : public Card {
private:
  std::string _color;
public:
  ColoredCard(std::string color);
  std::string get_collor();
  void set_color(std::string color);
}
