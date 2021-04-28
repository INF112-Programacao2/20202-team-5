//#include <allegro5/allegro5.h>
//#include <allegro5/allegro_font.h>
//#include <stdbool.h>
#include<iostream>
#include<string>
#include "game.h"
//#include "hand.h"
#include "card.h"

//Game game();

int main()
{
  /*
    al_init();
    al_install_keyboard();

    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);
    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    ALLEGRO_DISPLAY* disp = al_create_display(960, 600);
    ALLEGRO_FONT* font = al_create_builtin_font();

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));

    bool redraw = true;
    ALLEGRO_EVENT event;

    al_start_timer(timer);
    while(1)
    {
        al_wait_for_event(queue, &event);

        if(event.type == ALLEGRO_EVENT_TIMER)
            redraw = true;
        else if((event.type == ALLEGRO_EVENT_KEY_DOWN) || (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE))
            break;

        if(redraw && al_is_event_queue_empty(queue))
        {
            al_clear_to_color(al_map_rgb(0, 0, 0));
            al_draw_text(font, al_map_rgb(255, 255, 255), 0, 0, 0, "Hello world!");
            al_flip_display();

            redraw = false;
        }
    }

    al_destroy_font(font);
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);
*/
  //Game game(2);
  std::cout << game.get_players() << ' ' << game.get_active_player() << std::endl;
  std::cout << game.get_playerList().size() << std::endl;
  std::cout << game.get_board()->get_number() << " / " << game.get_board()->get_color() << std::endl;
  for(int i=0; i <game.get_board()->get_deck()->get_cards().size();i++) {
    std::cout << game.get_board()->get_deck()->get_cards().at(i)->get_color() << " / " << game.get_board()->get_deck()->get_cards().at(i)->get_number() << std::endl;
  }
  //std::cout << game.get_board()->get_stack()->get_cards().size() << std::endl;

  std::string command = "start";

   while (command.compare("end") != 0) {
    std::getline(std::cin,command);
    if (command.compare("-showhand") == 0) {
      int playerID = 0;
      std::cout << "insert player:" << std::endl;
      std::cin >> playerID;
      for(int i = 0; i < game.get_playerList().at(playerID)->get_hand()->get_cards().size(); i++) {
        std::cout << game.get_playerList().at(playerID)->get_hand()->get_cards().at(i)->get_name() << ' ';
      }
      std::cout << std::endl;
    }
  }
  return 0;
}
