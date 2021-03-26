class Game {
private:
  int _players;
  int _score[4];
  int _active_player;
public:
  Game();
  int get_players();
  void set_players(int players)
  int* get_score();
  void set_score(int score[4]);
  int get_active_player();
  void set_active_player(int active_player);
  void next_player();
};
