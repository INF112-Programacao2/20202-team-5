#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <stdbool.h>
#include<iostream>
#include<cmath>
#include<string>
#include <cstdlib>
#include<ctime>
#include "game.h"
#include "card.h"

ALLEGRO_BITMAP* cardBack;

void loadSprites() {
  //for (int i = 0; i < game.get_board()->get_deck()->get_cards().size(); i++) {
  //  game.get_board()->get_deck()->get_cards().at(i)->set_sprite(al_load_bitmap(game.get_board()->get_deck()->get_cards().at(i)->get_spriteName().c_str()));
  //}
  for (int j = 0; j < game.get_players(); j++) {
    for(int i = 0; i < game.get_playerList().at(j)->get_hand()->get_cards().size(); i++) {
      game.get_playerList().at(j)->get_hand()->get_cards().at(i)->set_sprite(al_load_bitmap(game.get_playerList().at(j)->get_hand()->get_cards().at(i)->get_spriteName().c_str()));
    }
  }

  game.get_board()->get_stack()->get_cards().back()->set_sprite(al_load_bitmap(game.get_board()->get_stack()->get_cards().back()->get_spriteName().c_str()));
}

int ClickedCard() {
  ALLEGRO_MOUSE_STATE state;
  al_get_mouse_state(&state);
  int PlayerSize = game.get_playerList().at(game.get_activePlayer())->get_hand()->get_cards().size();
  for (int i = 0; i < PlayerSize; i++) {
    int cardPosX = (al_get_display_width(al_get_current_display())/2) - (50 * PlayerSize) + (100 * i);
    int cardPosY = al_get_display_height(al_get_current_display()) - 182;
    if (state.x > cardPosX && state.x < cardPosX + 130 && state.y > cardPosY && state.y < cardPosY + 182) {
      return i;
    }
  }
  return -1;
}

void drawTwo(bool show) {

}

void drawFour(bool show) {
  int playerNumber = game.get_players();
  int activePlayerSize = 0;
  double playerScale = 0.5;
  int cardWidth = 130;
  int cardHeight = 182;

  if (show) {
    Player* drawPlayer = game.get_playerList().at((game.get_activePlayer()+1)%playerNumber);
    activePlayerSize = drawPlayer->get_hand()->get_cards().size();

    for (int j = 0; j < drawPlayer->get_hand()->get_cards().size(); j++) {
      al_draw_scaled_rotated_bitmap(drawPlayer->get_hand()->get_cards().at(j)->get_sprite(),
      0, 0,
      (182 * playerScale), (al_get_display_height(al_get_current_display())/2) - (25 * activePlayerSize) + (50 * j),
      playerScale, playerScale,
      M_PI/2, 0);
    }

    drawPlayer = game.get_playerList().at((game.get_activePlayer()+2)%playerNumber);
    activePlayerSize = drawPlayer->get_hand()->get_cards().size();
    for (int j = 0; j < drawPlayer->get_hand()->get_cards().size(); j++) {
      al_draw_scaled_rotated_bitmap(drawPlayer->get_hand()->get_cards().at(j)->get_sprite(),
      0, 0,
      (al_get_display_width(al_get_current_display())/2) - (25 * activePlayerSize) + (50 * j), (182 * playerScale),
      playerScale, playerScale,
      M_PI, 0);
    }

    drawPlayer = game.get_playerList().at((game.get_activePlayer()+3)%playerNumber);
    activePlayerSize = drawPlayer->get_hand()->get_cards().size();
    for (int j = 0; j < drawPlayer->get_hand()->get_cards().size(); j++) {
      al_draw_scaled_rotated_bitmap(drawPlayer->get_hand()->get_cards().at(j)->get_sprite(),
      0, 0,
      al_get_display_width(al_get_current_display()) - (182 * playerScale), (al_get_display_height(al_get_current_display())/2) - (25 * activePlayerSize) + (50 * j),
      playerScale, playerScale,
      -M_PI/2, 0);
    }
  } else {
    Player* drawPlayer = game.get_playerList().at((game.get_activePlayer()+1)%playerNumber);
    activePlayerSize = drawPlayer->get_hand()->get_cards().size();
    for (int j = 0; j < activePlayerSize; j++) {
      al_draw_scaled_rotated_bitmap(cardBack,
      0, 0,
      (182 * playerScale), (al_get_display_height(al_get_current_display())/2) - (25 * activePlayerSize) + (50 * j),
      playerScale, playerScale,
      M_PI/2, 0);
    }

    drawPlayer = game.get_playerList().at((game.get_activePlayer()+2)%playerNumber);
    activePlayerSize = drawPlayer->get_hand()->get_cards().size();
    for (int j = 0; j < activePlayerSize; j++) {
      al_draw_scaled_rotated_bitmap(cardBack,
      0, 0,
      (al_get_display_width(al_get_current_display())/2) - (25 * activePlayerSize) + (50 * j), (182 * playerScale),
      playerScale, playerScale,
      M_PI, 0);
    }

    drawPlayer = game.get_playerList().at((game.get_activePlayer()+3)%playerNumber);
    activePlayerSize = drawPlayer->get_hand()->get_cards().size();
    for (int j = 0; j < activePlayerSize; j++) {
      al_draw_scaled_rotated_bitmap(cardBack,
      0, 0,
      al_get_display_width(al_get_current_display()) - (182 * playerScale), (al_get_display_height(al_get_current_display())/2) - (25 * activePlayerSize) + (50 * j),
      playerScale, playerScale,
      -M_PI/2, 0);
    }
  }

  activePlayerSize = game.get_playerList().at(game.get_activePlayer())->get_hand()->get_cards().size();
  for (int i = 0; i < activePlayerSize; i++)  {
    if (game.get_playerList().at(game.get_activePlayer())->get_hand()->get_cards().at(i)->get_sprite() != NULL) {
      al_draw_scaled_bitmap(game.get_playerList().at(game.get_activePlayer())->get_hand()->get_cards().at(i)->get_sprite(),
        0, 0,                                // source origin
        cardWidth, cardHeight,
        (al_get_display_width(al_get_current_display())/2) - (50 * activePlayerSize) + (100 * i), al_get_display_height(al_get_current_display()) - 182,                                // target origin
        130, 182 ,                                // target dimensions
        0                                    // flags
      );
    }
  }
}

int main() {
    al_init();
    al_install_keyboard();
    al_install_mouse();
    al_init_image_addon();

    loadSprites();

    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);
    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    ALLEGRO_DISPLAY* disp = al_create_display(1200, 900);
    ALLEGRO_FONT* font = al_create_builtin_font();
    cardBack = al_load_bitmap("sprites/cardback.bmp");

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_mouse_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));

    bool redraw = true;
    ALLEGRO_EVENT event;

    al_start_timer(timer);

    std::cout << game.get_players() << ' ' << game.get_activePlayer() << std::endl;
    std::cout << game.get_playerList().size() << std::endl;
    std::cout << game.get_board()->get_number() << " / " << game.get_board()->get_color() << std::endl;

    std::string command = "start";

    while(1)
    {
        al_wait_for_event(queue, &event);

        if(event.type == ALLEGRO_EVENT_TIMER)
            redraw = true;
        else if((event.type == ALLEGRO_EVENT_KEY_DOWN) || (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)){
           while (1) {
            std::cout << "input command: \n";
            std::getline(std::cin,command);
            if (command.compare("end") == 0) {
              break;
            }
            if (command.compare("-showhand") == 0) {
              int playerID = 0;
              std::cout << "insert player:" << std::endl;
              std::cin >> playerID;
              for(int i = 0; i < game.get_playerList().at(playerID)->get_hand()->get_cards().size(); i++) {
                std::cout << game.get_playerList().at(playerID)->get_hand()->get_cards().at(i)->get_name() << ' ';
              }
              std::cout << std::endl;
            }
            if (command.compare("-exit") == 0) {
              al_destroy_font(font);
              al_destroy_display(disp);
              al_destroy_timer(timer);
              al_destroy_event_queue(queue);
              al_destroy_bitmap(cardBack);
              return 0;
            }
            if (command.compare("-drawcards") == 0) {
              int playerID = 0;
              int cardNumber = 0;
              std::cout << "insert player:" << std::endl;
              std::cin >> playerID;
              std::cout << "insert card number:" << std::endl;
              std::cin >> cardNumber;
              game.get_playerList().at(playerID)->get_hand()->draw(cardNumber, game);
              loadSprites();
            }
            if (command.compare("-playcard") == 0) {
              int card;
              while (1) {
                std::cout << "insert card: \n";
                std::cin >> card;
                if (game.get_playerList().at(game.get_activePlayer())->get_hand()->get_cards().at(card)->isPlayable()) {
                  //game.get_playerList().at(game.get_activePlayer())->get_hand()->get_cards().at(card)->onPlay(game);
                  game.get_playerList().at(game.get_activePlayer())->get_hand()->play(card, game);
                  game.next_player();
                  loadSprites();
                  break;
                }
              }
            }
          }
          redraw = true;
        } else if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
            if (ClickedCard() != -1) {
              game.get_playerList().at(game.get_activePlayer())->get_hand()->play(ClickedCard(), game);
              game.next_player();
              loadSprites();
              redraw = true;
            }
        }

        if(redraw && al_is_event_queue_empty(queue))
        {
            al_clear_to_color(al_map_rgb(0, 0, 0));

            drawFour(false);

            al_draw_scaled_bitmap(cardBack,
              0, 0,                                // source origin
              130, 182,
              (al_get_display_width(al_get_current_display()) * 0.2), al_get_display_height(al_get_current_display()) * 0.2,                                // target origin
              130 * 0.75, 182 * 0.75,                                // target dimensions
              0                                    // flags
            );

            al_draw_scaled_bitmap(game.get_board()->get_stack()->get_cards().back()->get_sprite(),
              0, 0,                                // source origin
              130, 182,
              (al_get_display_width(al_get_current_display())/2) - 65, al_get_display_height(al_get_current_display())/2 - 91,                                // target origin
              130, 182 ,                                // target dimensions
              0                                    // flags
            );

            al_flip_display();

            redraw = false;
        }
    }
}
