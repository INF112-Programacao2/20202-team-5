#include<string>

class Card {
public:
  virtual std::string get_color()=0;
  virtual int get_number()=0;
  virtual bool isPlayable();
};
